local process = function(inCaster, inTarget, inSpell)
  FxEngine:playEffect("SuddenCraven", inCaster)
	return true
end

subscribe_spell("Sudden Craven", process)
