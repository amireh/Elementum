local MyHand = {}
if not Hand then Hand = {} end
if not Buffs then Buffs = {} end

local gen_spell_name = function(inSpell, inSuffix)
  return "SpellButton_" .. inSpell:getUID() .. "_" .. inSuffix
end

UI.__DrawSpellButton = function(inSpell, inContainer, inDim, inSuffix, isActive)
  local lButton = {}
  --~ local margin = 5

  --~ if (firstButton) then margin = 0; firstButton = false end

	-- calculate position
	--~ lButton["Position"] =
		--~ CEGUI.UVector2:new(
			--~ --CEGUI.UDim(0, cfg.SpellButton["Width"] * (SelfPuppet:nrSpellsInHand() - 2) + (margin*SelfPuppet:nrSpellsInHand())),
      --~ CEGUI.UDim(UI.Config.Dim.HandButton.x.scale * (SelfPuppet:nrSpellsInHand() - 2),0),
			--~ CEGUI.UDim(0, 0)
		--~ )

	-- generate the button's name
	lButton["Name"] = gen_spell_name(inSpell, inSuffix)

	Pixy.Log("creating a window named " .. lButton["Name"])

	-- create the actual button element
  --local list_item = CEWindowMgr:createWindow("TaharezLook/ListboxItem", lButton["Name"] .. "/ListItem")
	lButton["Window"] = CEWindowMgr:createWindow("TaharezLook/ImageButton", lButton["Name"])
  --list_item:addChildWindow(lButton["Window"])

	-- attach the button to the Pixy::CSpell object
	inSpell:setButton(lButton["Window"])
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
  lButton["Window"]:subscribeEvent("AlphaChanged", "UI.Helpers.DestroyAfterFade")
  --lButton["Window"]:subscribeEvent("Clicked", "UI.castSpellAnimation")

  UI.Animate(lButton["Window"], "DrawSpell")

  table.insert(MyHand, inSpell)

  return true
end

Hand.DropSpell = function(inSpell)
  local win = CEWindowMgr:getWindow(gen_spell_name(inSpell, "Hand"))

  UI.HideTooltip(nil)
  --~ UI.Animate(inSpell:getButton(), "DropSpell")
  UI.Animate(win, "DropSpell")

  win:removeEvent("Clicked")
  win:removeEvent("MouseEnter")
  win:removeEvent("MouseLeave")

  removeByValue(MyHand, inSpell)

  return true
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
      spell:getButton():enable()
    else
      spell:getButton():disable()
      --~ Pixy.Log("-=-=-= disabling spell due to not meeting requirements")
    end
  end

  --~ Pixy.Log("== Hand has " .. table.getn(MyHand) .. " spells")

  return true
end

Buffs.DrawSpell = function(spell)
  local lButton = UI.__DrawSpellButton(spell, UI.Buffs, UI.Config.Dim.HandButton, "Buff")
  lButton["Window"]:subscribeEvent("MouseEnter", "UI.ShowTooltip")
  lButton["Window"]:subscribeEvent("MouseLeave", "UI.HideTooltip")

  --table.insert(MyBuffs, spell)

  return true
end

Buffs.Show = function(rnd)
  Buffs.Hide()

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
  -- draw the spell buttons
  for buff in list_iter(buffs) do
    print("\t\tdrawing buff " .. buff:getName())
    Buffs.DrawSpell(buff)
  end

  if table.getn(buffs) > 0 then
    UI.Containers["Buffs"]:show()
  end

  return true
end

Buffs.Hide = function(rnd)
  while UI.Buffs:getChildCount() > 0 do
    CEWindowMgr:destroyWindow(UI.Buffs:getChildAtIdx(0))
  end
  UI.Containers["Buffs"]:hide()

  return true
end
