local damage = 2
local lifetap = 3
local process = function(inCaster, inTarget, inSpell)
  local caster = inCaster:getEntity()
  local target = CombatState:getEnemy(caster:getUID())
  inTarget = target:getRenderable()

	Pixy.Log("Casting Kiss of Death on "
    .. target:getName() .. "#" .. target:getUID()
    .. " by " .. caster:getUID() .. "!")

  SCT.ShowScrollingMessage("+" .. lifetap .. " health (Kiss of Death)", true, inCaster)
  SCT.ShowScrollingMessage("-" .. damage .. " health (Kiss of Death)", false, inTarget)

  FxEngine:playEffect("KissOfDeath", inCaster)

	return true
end

subscribe_spell("Kiss of Death", process)
