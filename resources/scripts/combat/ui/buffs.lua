if not Buffs then Buffs = {} end

Buffs.DrawSpell = function(spell,wnd, idx)
  local btn = UI.Helpers.DrawSpellButton(spell, wnd, UI.Config.Dim.BuffButton, "Buff")["Window"]
  btn:subscribeEvent("MouseEnter", "UI.ShowTooltip")
  btn:subscribeEvent("MouseLeave", "UI.HideTooltip")
  -- position the button
  local col = idx % 4
  local row = math.floor(idx / 4) + 1
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
