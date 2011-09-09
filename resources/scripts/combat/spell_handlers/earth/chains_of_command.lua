local process = function(inCaster, inTarget, inSpell)
	Pixy.Log("A unit is being mind controlled by " .. inCaster:getEntity():getName() .. "!")

  inTarget:getEntity():getOwner():detachUnit(inTarget:getEntity():getUID(), false)
  local cunit = inTarget:getEntity()
  --local cpuppet = inCaster:getEntity()
  tolua.cast(cunit, "Pixy::CUnit")
  --tolua.cast(cpuppet, "Pixy::CPuppet")

  inCaster:getEntity():attachUnit(cunit)
  Pixy.Combat.onEntityDeselected()
  GfxEngine:changeOwnership(cunit)
  FxEngine:playEffect("Elementum/Fx/MindControl", inTarget)

	return true
end

local validate = function()
  if Selected == nil then return false end

  if Selected:getEntity():getRank() == Pixy.PUPPET then return false end

  return true
end

subscribe_spell("Chains of Command", process)
subscribe_spell_prereq("Chains of Command", validate)
