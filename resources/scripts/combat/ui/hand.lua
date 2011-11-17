Hand = {}
local MyHand = {}
--local Win2Anims = {}

MaxSpellsInHand = 4
--Win2Spells = {}


HandItem = {}
function HandItem:New(in_spell)
  local o = {
    Spell = in_spell,
    Window = nil,
    isMarked = false,
    isFaded = false,
    toBeDestroyed = false,
    __isDisabled = false,
    Anims = {}
  }
  setmetatable(o, {__index = self})
  self.__index = self
  o:Draw():Bind()

  return o
end

HandItem.cleanup = function()
  for item in list_iter(MyHand) do
    if item.isFaded then
    item:__DoDestroy()
    end
  end

  Pixy.dontUpdateMe(HandItem.cleanup)
end

function HandItem:Destroy()
  self.toBeDestroyed = true
  self.Window:subscribeEvent("AlphaChanged", "HandItem.DestroyAfterFade")

  self:Unmark()

  -- move all the spells to the right of this window to the left
  do
    -- find the index of this window
    local found = false
    local idx = 0
    while not found do
      local _win = self.Window:getParent():getChildAtIdx(idx)
      if _win == self.Window then
        found = true
        break
      end
      idx = idx + 1
    end
    assert(found)
    -- if it's not the last button, move the right ones
    idx = idx + 1
    while idx < self.Window:getParent():getChildCount() do
      local _win = self.Window:getParent():getChildAtIdx(idx)
      local _item = HandItem.FindByWindow(_win)
      if not _item.toBeDestroyed then
        _item:Animate("MoveToLeftInHand")
      end
      idx = idx + 1
    end
  end

  return self:Animate("DropSpell")
end

HandItem.DestroyAfterFade = function(e)
  local win = CEGUI.toWindowEventArgs(e).window
  if (win and tonumber(win:getProperty("Alpha")) <= 0) then
    --~ return HandItem.FindByWindow(win):__DoDestroy()
    HandItem.FindByWindow(win).isFaded = true
    Pixy.doUpdateMe(HandItem.cleanup)
  end
  return true
end

function HandItem:__DoDestroy()
  self:Unbind()

  -- destroy all animation instances
  for anim in list_iter(self.Anims) do
    anim:stop()
    anim:setTargetWindow(nil)
    CEGUI.AnimationManager:getSingleton():destroyAnimationInstance(anim)
  end

  CEWindowMgr:destroyWindow(self.Window)
  self.Window = nil
  self.Spell = nil
  self.isMarked = nil
  self.isFaded = nil
  self.toBeDestroyed = nil
  self.Anims = {}

  remove_by_value(MyHand, self)
  return nil
end

function HandItem:Draw()
  self.Window = UI.Helpers.DrawSpellButton(self.Spell, UI.Hand, UI.Config.Dim.HandButton, "Hand", true --[[is active]])
  self.Window:setProperty("Alpha", "0")

  UI.Hand:layout()
  --~ table.insert(self.Anims, UI.Animate(self.Window, "DrawSpell"))
  self:Animate("DrawSpell")

  return self
end

function HandItem:Bind()
	self.Window:subscribeEvent("Clicked", "HandItem.onClicked")
  self.Window:subscribeEvent("MouseEnter", "UI.ShowTooltip")
  self.Window:subscribeEvent("MouseLeave", "UI.HideTooltip")

  return self
end

function HandItem:Unbind(weak)
	self.Window:removeEvent("Clicked")
  self.Window:removeEvent("MouseEnter")
  self.Window:removeEvent("MouseLeave")

  -- HandItem:__Disable() calls a "weak" unbinding that removes the top 3 events above
  -- but not the destruction event ("AlphaChanged") because it might be rebound again
  if not weak then
    self.Window:removeEvent("AlphaChanged")
  end

  return self
end

function HandItem:Animate(anim_name)
  -- let's check if we already have an instance of this animation
  local __anim = find_by_cond(self.Anims, function(anim) return anim:getDefinition():getName() == anim_name end)
  if __anim then
    return __anim:start()
  end
  -- the instance doesn't exist, let's create one
  table.insert(self.Anims, UI.Animate(self.Window, anim_name))

  return self
end

function HandItem:StopAnimating(anim_name, reset)
  if not self:isAnimating(anim_name) then return true end

  local __anim = find_by_cond(self.Anims, function(anim) return anim:getDefinition():getName() == anim_name end)
  if __anim then
    if reset then __anim:setPosition(0); __anim:step(0) end
    return __anim:stop()
  end

  return nil
end

function HandItem:isAnimating(anim_name)
  for anim in list_iter(self.Anims) do
    if anim:getDefinition():getName() == anim_name then
      return anim:isRunning()
    end
  end

  return false
end

function HandItem:Mark()
  self.isMarked = true
  return self:Animate("SpellBlink")
end
function HandItem:Unmark()
  if not self.isMarked then return true end

  self.isMarked = false
  return self:StopAnimating("SpellBlink", true)
end

function HandItem:__Enable()
  self.Window:enable()
  self.__isDisabled = false
  return self
end
function HandItem:__Disable()
  self.Window:disable()
  self.__isDisabled = true
  return self
end

HandItem.FindBySpell = function(spell)
  return HandItem.FindBySpellUID(spell:getUID())
  --return find_by_condition(MyHand, function(item) return item.Spell:getUID() == spell:getUID() end)
end
HandItem.FindBySpellUID = function(uid)
  return find_by_condition(MyHand, function(item) return item.Spell:getUID() == uid end)
end

HandItem.FindByWindow = function(win)
  return find_by_condition(MyHand, function(item) return item.Window:getName() == win:getName() end)
end

-- when a spell button is pressed, we send a CastSpell request event, but in the meantime, the button must be disabled
-- so the client doesn't send duplicate requests on multi clicks
-- note: if the request was rejected, the HandItem must be enabled again
HandItem.onClicked = function(e)
  local win = CEGUI.toWindowEventArgs(e).window
  assert(win)
  local item = HandItem.FindByWindow(win)
  assert(item)
  if item.__isDisabled then return true end

  item:__Disable()

  Spells.reqCastSpell(item.Spell)
  return true
end

function HandItem:Validate()
  UI.setValidationMsg("")

  if Active:getUID() ~= SelfPuppet:getUID() then return false end

  --~ Pixy.Log("validating self.Spell requirements")
  --~ Pixy.Log("\tcurrent self.Spell: " .. self.Spell:getName() .. "#" .. self.Spell:getUID())
  -- validate that Selected exists and is a friendly target if the self.Spell requires a friendly target
  if self.Spell:requiresTarget() and not self.Spell:requiresEnemyTarget()
  and (not Selected or (Selected and Selected:getOwner():getUID() ~= SelfPuppet:getUID()))
  then
    UI.setValidationMsg("This spell requires a friendly target.")
    return false
  end

  -- validate that Selected exists and is an enemy target if the self.Spell requires an enemy target
  if self.Spell:requiresEnemyTarget()
  and (not Selected or (Selected and Selected:getOwner():getUID() == SelfPuppet:getUID()))
  then
    UI.setValidationMsg("This spell requires an enemy target.")
    return false
  end

  --~ local caster = self.Spell:getCaster()
  local caster = SelfPuppet

  --~ if (caster:getRank() == Pixy.PUPPET) then
    if (caster:getWP() < self.Spell:getCostWP()) then
      --~ Pixy.Log("-=-= caster doesn't have enough WP")
      UI.setValidationMsg("You do not have enough Willpower to cast this spell.")
      return false
    end

    if (caster:getChannels() < self.Spell:getCostChannels()+1) then
      --~ Pixy.Log("-=-= caster doesn't have enough channels")
      UI.setValidationMsg("You do not have enough Channels to cast this spell.")
      return false
    end
  --~ end

  if (caster:getHP() < self.Spell:getCostHP()) then
    --~ Pixy.Log("-=-= caster doesn't have enough HP")
    UI.setValidationMsg("You do not have enough Health to cast this spell.")
    return false
  end

  if (inBlockPhase and self.Spell:getPhase() == Pixy.Spell.Phase.Casting) then
    --~ Pixy.Log("-=-= self.Spell isn't castable in this phase")
    UI.setValidationMsg("This spell can not be used in blocking phase.")
    return false
  end

  if SpellValidators[self.Spell:getName()] then
    return SpellValidators[self.Spell:getName()](self.Spell)
  else
    return true
  end
end

-- here is where we re-enable the HandItem after a spell reject, note this is called from Spells.onCastSpellRejected()
Hand.onCastSpellRejected = function(uid)
  local item = HandItem.FindBySpellUID(uid)
  if item then
    item:__Enable()
    return true
  end

  Pixy.Log("ERROR! Can't find HandItem for a rejected spell request of UID: " .. uid)
  return true
end

Hand.cleanup = function()
  --~ Win2Spells = {}
  --for item in list_iter(MyHand) do
  --  item:__DoDestroy()
  --end
  while #MyHand > 0 do MyHand[1]:__DoDestroy() end
  MyHand = {}
  --~ Win2Anims = {}
end

-- draws a CEGUI::ImageButton element representing the given spell
-- and attaches it to the Puppet's hand
Hand.DrawSpell = function(inSpell)

  --[[
  local lButton = UI.Helpers.DrawSpellButton(inSpell, UI.Hand, UI.Config.Dim.HandItem, "Hand", true)

  -- finally, subscribe the button to its event handlers
  --lButton["Window"]:subscribeEvent("Shown", "UI.DrawSpell")
  lButton["Window"]:setProperty("Alpha", "0")
	lButton["Window"]:subscribeEvent("Clicked", "Spells.reqCastSpell")
  lButton["Window"]:subscribeEvent("MouseEnter", "UI.ShowTooltip")
  lButton["Window"]:subscribeEvent("MouseLeave", "UI.HideTooltip")
  --lButton["Window"]:subscribeEvent("Clicked", "UI.castSpellAnimation")

  UI.Hand:layout()
  UI.Animate(lButton["Window"], "DrawSpell")
  ]]

  local button = HandItem:New(inSpell)
  table.insert(MyHand, button)

  --~ Win2Spells[inSpell] = lButton["Window"]
  Hand.CheckForDiscards(0)

  return true
end


Hand.DropSpell = function(inSpell)
  --~ local win = CEWindowMgr:getWindow(UI.Helpers.GenerateSpellName(inSpell, "Hand"))

  -- move all the spells to the right of this window to the left
  --[[
  do
    -- find the index of this window
    local found = false
    local idx = 0
    while not found do
      local _win = UI.Hand:getChildAtIdx(idx)
      if _win == win then
        found = true
        break
      end
      idx = idx + 1
    end
    assert(found)
    -- if it's not the last button, move the right ones
    idx = idx + 1
    while idx < UI.Hand:getChildCount() do
      local _win = UI.Hand:getChildAtIdx(idx)
      -- if the button is already animating (being dropped or moved to the left by another spell)
      -- then animating it again will crash the client, because in the latter case, the pointer
      -- is invalidated _before_ the next animation is over
      if not UI.isAnimating(_win, "MoveToLeftInHand") and not UI.isAnimating(_win, "DropSpell") then
        UI.Animate(_win, "MoveToLeftInHand")
      end
      idx = idx + 1
    end
  end
  ]]

  --[[
  win:removeEvent("Clicked")
  win:removeEvent("MouseEnter")
  win:removeEvent("MouseLeave")
  ]]
  local item = HandItem.FindBySpell(inSpell)
  assert(item)
  item:Destroy()
  Hand.CheckForDiscards(0)
  --~ remove_by_value(MyHand, item)
  --~ remove_by_value(MyHand, inSpell)
  --~ Win2Spells[inSpell] = nil

  --[[
  if win:isUserStringDefined("Marked") and win:getUserString("Marked") == "True" then
    win:setUserString("Marked", "False")
    --Win2Anims[win]:stop()
    --CEGUI.AnimationManager:getSingleton():destroyAnimationInstance(Win2Anims[win])
  end

  UI.ClearAnimations(win)

  UI.HideTooltip(nil)
  win:subscribeEvent("AlphaChanged", "UI.Helpers.DestroyAfterFade")
  UI.Helpers.AssignFadeCallback( Hand.CheckForDiscards )
  UI.Animate(win, "DropSpell")

  win:setUserString("Destroyed", "True")

  --~ UI.Hand:layout()

  print("Spell discarded")

  -- we pass a -1 pad because the button is not yet removed from the container,
  -- it will be when it fades out but the method should consider it removed
  -- all the same
  --~ Hand.CheckForDiscards(0)
  ]]

  return true
end
Hand.CheckForDiscards = function(pad)
  print("Checking for spells to be discarded")

  -- unmark currently blinking buttons and calculate the number of active
  -- buttons in hand (active here means they're not marked for destruction)
  local nr_active_spells = 0
  for item in list_iter(MyHand) do
    if item.isMarked then item:Unmark() end
    if not item.toBeDestroyed then nr_active_spells = nr_active_spells + 1 end
  end

  local overflow = nr_active_spells - MaxSpellsInHand
  if overflow <= 0 then return true end

  local marked_ctr = 0
  for item in list_iter(MyHand) do
    if not item.toBeDestroyed then
      item:Mark()
      marked_ctr = marked_ctr + 1
      if marked_ctr == overflow then break end
    end
  end

  return true
end

Hand.__DoUpdate = function()
  for item in list_iter(MyHand) do
    if not item.toBeDestroyed then
      if item:Validate() then
        item.Window:enable()
      else
        item.Window:disable()
        --~ Pixy.Log("-=-=-= disabling spell due to not meeting requirements")
      end
    end
  end
  Pixy.dontUpdateMe(Hand.__DoUpdate)
end

Hand.Update = function(e)
  Pixy.doUpdateMe(Hand.__DoUpdate)
  return true
end

Hand.UpdateTooltips = function()
  local exporter = Pixy.SpellListExporter()
  exporter:export(SelfPuppet:getSpells(), "Pixy::Spell", "Temp")
  for spell in list_iter(Temp) do
    spell:updateTooltip();
    HandItem.FindBySpell(spell).Window:setUserString("Tooltip", spell:getTooltip())
    --~ Win2Spells[spell]:setUserString("Tooltip", spell:getTooltip())
  end
end
