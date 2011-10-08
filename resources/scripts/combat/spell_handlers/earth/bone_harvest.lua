local process = function(inCaster, inTarget, inSpell)
	Pixy.Log("I'm casting Bone Harvest!")
  FxEngine:playEffect("BoneHarvest", inCaster)

  local exporter = Pixy.CUnitListExporter()
  exporter:export(inCaster:getEntity():getUnits(), "Pixy::CUnit", "Temp")

  local nr_skeletons = 0
  for unit in list_iter(Temp) do
    if unit:getName():find("Skeleton") then
      nr_skeletons = nr_skeletons + 1
    end
  end
  SCT.ShowScrollingMessage("+" .. nr_skeletons .. " health (Bone Harvest)", true, inCaster)


	return true
end

subscribe_spell("Bone Harvest", process)
