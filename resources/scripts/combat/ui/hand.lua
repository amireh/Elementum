local MyHand = {}
if not Hand then Hand = {} end
if not Buffs then Buffs = {} end

local gen_spell_name = function(inSpell, inSuffix)
  return "SpellButton_" .. inSpell:getUID() .. "_" .. inSuffix
end

MaxSpellsInHand = 4
Win2Spells = {}
UI.__DrawSpellButton = function(inSpell, inContainer, inDim, inSuffix, isActive)
  local lButton = {}

	-- generate the button's name
	lButton["Name"] = gen_spell_name(inSpell, inSuffix)

	Pixy.Log("creating a window named " .. lButton["Name"])

	-- create the actual button element
  --local list_item = CEWindowMgr:createWindow("TaharezLook/ListboxItem", lButton["Name"] .. "/ListItem")
	lButton["Window"] = CEWindowMgr:createWindow("TaharezLook/ImageButton", lButton["Name"])
  --list_item:addChildWindow(lButton["Window"])

	-- attach the button to the Pixy::CSpell object
	--~ inSpell:setButton(lButton["Window"])
  inSpell:setImageSet("Spells_" .. raceToString(inSpell:getRace()))
  -- sanitize spell name to match image set name
  local sane_name = string.gsub(inSpell:getName(), "%s", "_")
  inSpell:setImageName(sane_name)

	-- draw the image button
	lButton["Image"] = "set:" .. inSpell:getImageSet() .. " image:" .. inSpell:getImageName()
	lButton["Window"]:setProperty("NormalImage", lButton["Image"] .. "_Normal")
  if isActive then
	lButton["Window"]:setProperty("HoverImage", lButton["Image"] .. "_Hover")
	lButton["Window"]:setProperty("PushedImage", lButton["Image"] .. "_Pushed")
  else
  lButton["Window"]:setProperty("HoverImage", lButton["Image"] .. "_Normal")
	lButton["Window"]:setProperty("PushedImage", lButton["Image"] .. "_Normal")
  end
	lButton["Window"]:setProperty("DisabledImage", lButton["Image"] .. "_Disabled")
  lButton["Window"]:setProperty("MousePassThroughEnabled", "False")
  lButton["Window"]:setProperty("ClippedByParent", "False")
  lButton["Window"]:setProperty("AlwaysOnTop", "True")

	-- attach our spell object to the button
	lButton["Window"]:setUserString("UID", inSpell:getUID())
	lButton["Window"]:setUserString("Model", inSpell:getName())
	lButton["Window"]:setUserString("Tooltip", inSpell:getTooltip())

	-- create tooltip
  --lButton["Window"]:setTooltipText(inSpell:getTooltip())
	-- ...

	-- attach the window to our layout
	inContainer:addChildWindow(lButton["Window"])

	lButton["Window"]:setSize(inDim)

  UIEngine:setMargin(lButton["Window"],
    CEGUI.UBox(
      CEGUI.UDim(0,0),
      CEGUI.UDim(0,0),
      CEGUI.UDim(0,0),
      CEGUI.UDim(0,5)))

  lButton["Window"]:moveToFront()
	lButton["Window"]:show()

  return lButton
end

-- draws a CEGUI::ImageButton element representing the given spell
-- and attaches it to the Puppet's hand
Hand.DrawSpell = function(inSpell)

  local lButton = UI.__DrawSpellButton(inSpell, UI.Hand, UI.Config.Dim.HandButton, "Hand", true --[[is active]])

  -- finally, subscribe the button to its event handlers
  --lButton["Window"]:subscribeEvent("Shown", "UI.DrawSpell")
  lButton["Window"]:setProperty("Alpha", "0")
	lButton["Window"]:subscribeEvent("Clicked", "Combat.reqCastSpell")
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
  local win = CEWindowMgr:getWindow(gen_spell_name(inSpell, "Hand"))

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
      UI.Animate(_win, "MoveToLeftInHand")
      idx = idx + 1
    end
  end

  win:removeEvent("Clicked")
  win:removeEvent("MouseEnter")
  win:removeEvent("MouseLeave")

  removeByValue(MyHand, inSpell)
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

  if (SpellValidators[spell:getName()] ~= nil) then
    return SpellValidators[spell:getName()]()
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

Buffs.DrawSpell = function(spell,wnd, idx)
  local btn = UI.__DrawSpellButton(spell, wnd, UI.Config.Dim.BuffButton, "Buff")["Window"]
  btn:subscribeEvent("MouseEnter", "UI.ShowTooltip")
  btn:subscribeEvent("MouseLeave", "UI.HideTooltip")
  -- position the button
  local col = idx % 3
  local row = math.floor(idx / 3) + 1
  local dim = UI.Config.Dim.BuffButton
  local margin = { x= 5, y= 5 }
  btn:setPosition(CEGUI.UVector2(
    CEGUI.UDim(col * dim.x.scale, margin.x * col),
    CEGUI.UDim(1 - (row * dim.y.scale), margin.y * row * -1)))
  local pos = btn:getPosition()
  print("Buff position @ " .. pos.x.scale .. "," .. pos.y.scale .. " => " .. row .. "x" .. col)
  --table.insert(MyBuffs, spell)

  return true
end

Buffs.Show = function(rnd, is_friendly)
  --Buffs.Hide()

  print("Showing buffs for " .. rnd:getEntity():getName() .. rnd:getEntity():getUID())
  local entity = rnd:getEntity()
  if entity:getRank() == Pixy.PUPPET then
    entity = tolua.cast(entity, "Pixy::CPuppet")
  else
    entity = tolua.cast(entity, "Pixy::CUnit")
  end
  local exporter = Pixy.CSpellListExporter()
  exporter:export(entity:getBuffs(), "Pixy::CSpell", "Temp")
  local buffs = Temp
  Temp = nil

  print("\tFound " .. table.getn(buffs) .. " buffs on unit " .. rnd:getEntity():getName())

  -- clear the current buff panel
  local selector = ""; if is_friendly then selector = "Player" else selector = "Enemy" end
  local wnd = UI.Buffs[selector]
  local container = UI.Containers[selector].Selected

  Buffs.Hide(wnd)

  -- draw the spell buttons
  local idx = 0
  for buff in list_iter(buffs) do
    print("\t\tdrawing buff " .. buff:getName())
    Buffs.DrawSpell(buff, wnd, idx)
    idx = idx + 1
  end

  --~ wnd:layout()
  container:layout()

  --if table.getn(buffs) > 0 then
  --  UI.Containers["Buffs"]:show()
  --end

  return true
end

Buffs.Hide = function(wnd)
  while wnd:getChildCount() > 0 do
    CEWindowMgr:destroyWindow(wnd:getChildAtIdx(0))
  end
  --~ wnd:layout()
  --UI.Containers["Buffs"]:hide()

  return true
end
