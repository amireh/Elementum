UI.LogSpellCast = function(inSpell)

  local self_cast = inSpell:getCaster():getEntity():getOwner():getUID() == SelfPuppet:getUID()

  -- only log enemy casts
  if self_cast then return true end

  -- figure out which panel to log onto
  local target = ""
  if (self_cast) then target = "Player" else target = "Enemy" end
  Pixy.Log("Spell's log target : " .. target)

  local lButton = UI.Helpers.DrawSpellButton(inSpell, UI.Containers.SpellLog[target], UI.Config.Dim.LogButton, "Log")

  --~ lButton["Window"]:setProperty("Alpha", "0.5")
  lButton:subscribeEvent("MouseEnter", "UI.ShowTooltip")
  lButton:subscribeEvent("MouseLeave", "UI.HideTooltip")

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
