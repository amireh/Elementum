local StygianDisease = { IsPositive = false }
local __Dmg = 1

function StygianDisease:cast()
  -- attach the buff to the puppet
  self.Target:attachBuff(self.Spell)
  FxEngine:playEffect("Elementum/Fx/Fatigue", self.Target)
end

function StygianDisease:process()
  self.Target:getOwner():setHP(self.Target:getOwner():getHP() - __Dmg)

  FxEngine:playEffect("Elementum/Fx/Fatigue", self.Target)
  SCT.ShowScrollingMessage("-1 health (Stygian Disease)", false, self.Target)

end

subscribe_spell("Stygian Disease", StygianDisease)
