local process = function(inCaster, inTarget, inSpell)
	Pixy.Log("A unit is being mind controlled by " .. inCaster:getEntity():getName() .. "!")

  inTarget:getEntity():getOwner():detachUnit(inTarget:getEntity():getUID(), false)
  local cunit = inTarget:getEntity()
  --local cpuppet = inCaster:getEntity()
  tolua.cast(cunit, "Pixy::CUnit")
  --tolua.cast(cpuppet, "Pixy::CPuppet")

  inCaster:getEntity():attachUnit(cunit)
  GfxEngine:changeOwnership(cunit)
  FxEngine:playEffect("Elementum/Fx/MindControl", inTarget)
	return true
end

subscribe_spell("Chains of Command", process)
