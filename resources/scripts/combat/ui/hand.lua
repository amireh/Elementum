local MyHand = {}
if not Hand then Hand = {} end



MaxSpellsInHand = 4
Win2Spells = {}

-- draws a CEGUI::ImageButton element representing the given spell
-- and attaches it to the Puppet's hand
Hand.DrawSpell = function(inSpell)

  local lButton = UI.Helpers.DrawSpellButton(inSpell, UI.Hand, UI.Config.Dim.HandButton, "Hand", true --[[is active]])

  -- finally, subscribe the button to its event handlers
  --lButton["Window"]:subscribeEvent("Shown", "UI.DrawSpell")
  lButton["Window"]:setProperty("Alpha", "0")
	lButton["Window"]:subscribeEvent("Clicked", "Spells.reqCastSpell")
  lButton["Window"]:subscribeEvent("MouseEnter", "UI.ShowTooltip")
  lButton["Window"]:subscribeEvent("MouseLeave", "UI.HideTooltip")
  --lButton["Window"]:subscribeEvent("Clicked", "UI.castSpellAnimation")

  UI.Hand:layout()
  UI.Animate(lButton["Window"], "DrawSpell")

  table.insert(MyHand, inSpell)
  Win2Spells[inSpell] = lButton["Window"]
  Hand.CheckForDiscards(0)

  return true
end

local Win2Anims = {}
Hand.DropSpell = function(inSpell)
  local win = CEWindowMgr:getWindow(UI.Helpers.GenerateSpellName(inSpell, "Hand"))

  -- move all the spells to the right of this window to the left
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
      if not UI.isAnimating(_win, "MoveToLeftInHand") and not UI.isAnimating(_win, "DropSpell") then
        UI.Animate(_win, "MoveToLeftInHand")
      end
      idx = idx + 1
    end
  end

  win:removeEvent("Clicked")
  win:removeEvent("MouseEnter")
  win:removeEvent("MouseLeave")

  remove_by_value(MyHand, inSpell)
  Win2Spells[inSpell] = nil
  --~ UI.Hand:removeChildWindow(win)
  --~ UI.Hand:destroyWindow(win)
  --~ CEWindowMgr:destroyWindow(win)

  if win:isUserStringDefined("Marked") and win:getUserString("Marked") == "True" then
    win:setUserString("Marked", "False")
    --Win2Anims[win]:stop()
    --CEGUI.AnimationManager:getSingleton():destroyAnimationInstance(Win2Anims[win])
  end

  UI.ClearAnimations(win)

  UI.HideTooltip(nil)
  win:subscribeEvent("AlphaChanged", "UI.Helpers.DestroyAfterFade")
  UI.Animate(win, "DropSpell")

  win:setUserString("Destroyed", "True")

  --~ UI.Hand:layout()

  print("Spell discarded")

  -- we pass a -1 pad because the button is not yet removed from the container,
  -- it will be when it fades out but the method should consider it removed
  -- all the same
  Hand.CheckForDiscards(-1)

  return true
end
Hand.CheckForDiscards = function(pad)
  print("Checking for spells to be discarded")
  local idx = 0
  -- now unmark the rest of the buttons, if any
  --~ print("\tUnmarking:")
  while idx < UI.Hand:getChildCount() do
    local win = UI.Hand:getChildAtIdx(idx)
    if win:isUserStringDefined("Marked") and win:getUserString("Marked") == "True" then
      --~ print("\tfound one! unmarking...")
      -- do unmark
      win:setUserString("Marked", "False")
      --~ win:setProperty("Alpha", "1.0")
      -- revert the button to its original state
      Win2Anims[win]:setPosition(Win2Anims[win]:getDefinition():getDuration())
      Win2Anims[win]:step(0)
      -- destroy the animation instance
      UI.RemoveAnimation(win, Win2Anims[win])
      Win2Anims[win] = nil
      --~ Win2Anims[win]:stop()
      --~ CEGUI.AnimationManager:getSingleton():destroyAnimationInstance(Win2Anims[win])
    end
    idx = idx + 1
  end

  if not pad then pad = 0 end
  -- if there is an overflow in the hand, mark the buttons that will be discarded
  local nr_spells = UI.Hand:getChildCount() + pad
  idx = 0
  --~ print("\tMarking:")
  if nr_spells > MaxSpellsInHand then
    local delta = nr_spells - MaxSpellsInHand
    while idx < delta do
      local win = UI.Hand:getChildAtIdx(idx)
      -- do mark unless this window is being destroyed
      if not win:isUserStringDefined("Destroyed") then
        --~ print("\tfound one! marking...")
        win:setUserString("Marked", "True")
        assert(not Win2Anims[win])
        --~ win:setProperty("Alpha", "0.5")
        Win2Anims[win] = UI.Animate(win, "MarkForRemoval")
      else
        delte = delta + 1
      end
      idx = idx + 1
    end
  end

  --~ print("Done checking for spells to be discarded")
end

local prereqs_met = function(spell)
  if ((spell:requiresTarget() or spell:requiresEnemyTarget()) and Selected == nil) then
    Pixy.Log("-=-= spell requires a target, none is selected")
    return false
  end
  if (spell:requiresEnemyTarget()
    and
    Selected:getEntity():getOwner():getUID() == SelfPuppet:getUID())
  then
    return false
  end


  local caster = spell:getCaster():getEntity()

  if (caster:getRank() == Pixy.PUPPET) then
    if (caster:getWP() < spell:getCostWP()) then
      --~ Pixy.Log("-=-= caster doesn't have enough WP")
      return false
    end
    if (caster:getChannels() < spell:getCostChannels()+1) then
      --~ Pixy.Log("-=-= caster doesn't have enough channels")
      return false
    end
  end

  if (caster:getHP() < spell:getCostHP()) then
    --~ Pixy.Log("-=-= caster doesn't have enough HP")
    return false
  end

  if (inBlockPhase and spell:getPhase() == Pixy.CASTING) then
    --~ Pixy.Log("-=-= spell isn't castable in this phase")
    return false
  end

  if SpellValidators[spell:getName()] then
    return SpellValidators[spell:getName()](spell)
  else
    return true
  end
end

Hand.Update = function(e)

  for spell in list_iter(MyHand) do
    if prereqs_met(spell) then
      Win2Spells[spell]:enable()
    else
      Win2Spells[spell]:disable()
      --~ Pixy.Log("-=-=-= disabling spell due to not meeting requirements")
    end
  end

  --~ Pixy.Log("== Hand has " .. table.getn(MyHand) .. " spells")

  return true
end

Hand.UpdateTooltips = function()
  local exporter = Pixy.CSpellListExporter()
  exporter:export(SelfPuppet:getHand(), "Pixy::CSpell", "Temp")
  for spell in list_iter(Temp) do
    spell:updateTooltip();
    Win2Spells[spell]:setUserString("Tooltip", spell:getTooltip())
  end
end
