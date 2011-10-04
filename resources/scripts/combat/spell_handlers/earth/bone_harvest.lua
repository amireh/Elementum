local process = function(inCaster, inTarget, inSpell)
	Pixy.Log("I'm casting Bone Harvest!")
  FxEngine:playEffect("BoneHarvest", inCaster)

	return true
end

subscribe_spell("Bone Harvest", process)
