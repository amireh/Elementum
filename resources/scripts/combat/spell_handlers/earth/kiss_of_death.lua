local __Damage = 2
local __Lifetap = 3

local KissOfDeath = {}
function KissOfDeath:bootstrap()
  self.Target = CombatState:getEnemy(self.Caster:getUID())
  self.TargetRnd = self.Target:getRenderable()
end

function KissOfDeath:cast()
  self:logMe()

  SCT.ShowScrollingMessage("+" .. __Lifetap .. " health (Kiss of Death)", true, self.CasterRnd)
  SCT.ShowScrollingMessage("-" .. __Damage .. " health (Kiss of Death)", false, self.TargetRnd)

  FxEngine:playEffect("KissOfDeath", self.CasterRnd)

	return true
end

subscribe_spell("Kiss of Death", KissOfDeath)
