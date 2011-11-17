local __HPT = 3
local Nourish = { IsPositive = true }
function Nourish:cast()
  self:logMe()

  -- attach the buff to the puppet
  inCaster:attachBuff(inSpell)

  FxEngine:playEffect("GladeBlessing", self.Caster)
end

function Nourish:process()
  self.Caster:setHP(self.Caster:getHP() + __HPT)
  FxEngine:playEffect("GladeBlessing", self.Caster)
  SCT.ShowScrollingMessage("+" .. __HPT .. " health (Nourish)", true, self.Caster)

  self:__tick()
end

subscribe_spell("Nourish", Nourish)
