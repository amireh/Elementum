local __Damage = 2
local __Lifetap = 3

local KissOfDeath = {}
function KissOfDeath:bootstrap()
  self.Target = CombatState:getEnemy(self.Caster:getUID())
  self.Target = self.Target
end

function KissOfDeath:cast()
  self:logMe()

  SCT.ShowScrollingMessage("+" .. __Lifetap .. " health (Kiss of Death)", true, self.Caster)
  SCT.ShowScrollingMessage("-" .. __Damage .. " health (Kiss of Death)", false, self.Target)

  FxEngine:playEffect("KissOfDeath", self.Caster)

	return true
end

subscribe_spell("Kiss of Death", KissOfDeath)
