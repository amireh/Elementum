local StygianDisease = { IsPositive = false }
local __Dmg = 1

function StygianDisease:cast()
  -- attach the buff to the puppet
  self.Target:attachBuff(inSpell)
  FxEngine:playEffect("Elementum/Fx/Fatigue", self.TargetRnd)
end

function StygianDisease:process()
  self.Target:setHP(self.Target:getHP() - _dmg)

  FxEngine:playEffect("Elementum/Fx/Fatigue", self.TargetRnd)
  SCT.ShowScrollingMessage("-1 health (Stygian Disease)", false, self.TargetRnd)

end

subscribe_spell("Stygian Disease", StygianDisease)
