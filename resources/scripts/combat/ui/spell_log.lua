UI.LogSpellCast = function(inSpell)

  local self_cast = inSpell:getCaster():getEntity():getOwner():getUID() == SelfPuppet:getUID()

  -- only log enemy casts
  if self_cast then return true end

  -- figure out which panel to log onto
  local target = ""
  if (self_cast) then target = "Player" else target = "Enemy" end
  Pixy.Log("Spell's log target : " .. target)

  local lButton = UI.__DrawSpellButton(inSpell, UI.Containers.SpellLog[target], UI.Config.Dim.LogButton, "Log")

  --[[
  local name = inSpell:getUID() .. "_log"
  local win = CEWindowMgr:createWindow("TaharezLook/ImageButton", name)
  UI.Containers.SpellLog[target]:addChildWindow(win)

  -- sanitize spell name to match image set name
  local image_set = "Spells_" .. raceToString(inSpell:getRace())
  local image_name = string.gsub(inSpell:getName(), "%s", "_")

	local image = "set:" .. image_set .. " image:" .. image_name
	win:setProperty("NormalImage",   image .. "_Normal")
	win:setProperty("HoverImage",    image .. "_Hover")
	win:setProperty("PushedImage",   image .. "_Pushed")
	win:setProperty("DisabledImage", image .. "_Disabled")
  --win:setUserString("Tooltip", inSpell:getTooltip())
	win:setSize(UI.Config.Dim.LogButton)
  UIEngine:setMargin(win,
    CEGUI.UBox(
      CEGUI.UDim(0,5),
      CEGUI.UDim(0,5),
      CEGUI.UDim(0,0),
      CEGUI.UDim(0,5)))

  win:moveToFront()
  win:show()

  win:subscribeEvent("MouseEnter", "UI.ShowLogTooltip")
  win:subscribeEvent("MouseLeave", "UI.HideLogTooltip")
  --]]

  lButton["Window"]:subscribeEvent("MouseEnter", "UI.ShowTooltip")
  lButton["Window"]:subscribeEvent("MouseLeave", "UI.HideTooltip")

  Pixy.Log("Logged Spell cast ! " .. inSpell:getName() .. inSpell:getUID())
end

UI.ClearSpellLog = function(target)

  local name = ""
  if target:getUID() == SelfPuppet:getUID() then name = "Player" else name = "Enemy" end

  Pixy.Log("Clearing spell log")
  while UI.Containers.SpellLog[name]:getChildCount() > 0 do
    local win = UI.Containers.SpellLog[name]:getChildAtIdx(0)
    Pixy.Log("removing spell log button named: " .. win:getName())
    CEWindowMgr:destroyWindow(win)
  end

end
