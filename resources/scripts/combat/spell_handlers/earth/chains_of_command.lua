local process = function(inCaster, inTarget, inSpell)
	Pixy.Log("A unit is being mind controlled by " .. inCaster:getName() .. "!")

  inTarget:getOwner():detachUnit(inTarget:getUID(), false)
  local cunit = inTarget
  --local cpuppet = inCaster
  tolua.cast(cunit, "Pixy::Unit")
  --tolua.cast(cpuppet, "Pixy::Puppet")

  inCaster:attachUnit(cunit)
  Combat.onEntityDeselected()
  GfxEngine:changeOwnership(cunit)
  FxEngine:playEffect("Elementum/Fx/MindControl", inTarget)

	return true
end

local validate = function()
  if Selected == nil then return false end

  if Selected:getRank() == Pixy.PUPPET then return false end

  return true
end

subscribe_spell("Chains of Command", process)
subscribe_spell_prereq("Chains of Command", validate)
