local BoneHarvest = {}
function BoneHarvest:cast()
	Pixy.Log("I'm casting Bone Harvest!")
  FxEngine:playEffect("BoneHarvest", self.CasterRnd)

  local exporter = Pixy.CUnitListExporter()
  exporter:export(self.Caster:getUnits(), "Pixy::CUnit", "__TempUnits")

  local nr_skeletons = 0
  for unit in list_iter(__TempUnits) do
    if unit:getName():find("Skeleton") then
      nr_skeletons = nr_skeletons + 1
    end
  end
  __TempUnits = nil
  SCT.ShowScrollingMessage("+" .. nr_skeletons .. " health (Bone Harvest)", true, self.CasterRnd)

  return true
end

SpellValidators["Bone Harvest"] = function(spell)
  local exporter = Pixy.CUnitListExporter()
  exporter:export(spell:getCaster():getEntity():getUnits(), "Pixy::CUnit", "_tmp")

  local nr_skeletons = 0
  for unit in list_iter(_tmp) do
    if unit:getName():find("Skeleton") then
      nr_skeletons = nr_skeletons + 1
    end
  end
  _tmp = nil

  if nr_skeletons <= 0 then
    UI.setValidationMsg("This spell requires you to have at least one Skeleton under your control.")
    return false
  end

  return true
end

subscribe_spell("Bone Harvest", BoneHarvest)
