UI.Helpers = { }

local fadeCallback = nil
UI.Helpers.AssignFadeCallback = function(handler)
  fadeCallback = handler
end

UI.Helpers.DestroyAfterFade = function(e)
  local win = CEGUI.toWindowEventArgs(e).window
  if (win and tonumber(win:getProperty("Alpha")) <= 0) then
    UI.ClearAnimations(win)

    CEWindowMgr:destroyWindow(win)

    if fadeCallback then
      print("window faded out, calling the handler");
      fadeCallback() end
    fadeCallback = nil
  end
end

UI.Helpers.GenerateSpellName = function(inSpell, inSuffix)
  return "SpellButton_" .. inSpell:getUID() .. "_" .. inSuffix
end

UI.Helpers.DrawSpellButton = function(inSpell, inContainer, inDim, inSuffix, isActive)
  local lButton = {}

	-- generate the button's name
	lButton["Name"] = UI.Helpers.GenerateSpellName(inSpell, inSuffix)

	Pixy.Log("creating a window named " .. lButton["Name"])

	-- create the actual button element
  --local list_item = CEWindowMgr:createWindow("TaharezLook/ListboxItem", lButton["Name"] .. "/ListItem")
	lButton["Window"] = CEWindowMgr:createWindow("Combat/ImageButton", lButton["Name"])
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

  return lButton["Window"]
end
