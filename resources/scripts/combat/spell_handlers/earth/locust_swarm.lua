local __DPT = 1 -- damage caused per turn

local LocustSwarm = {}
function LocustSwarm:cast()
  self:logMe()
  -- attach the buff to the puppet
  self.Target:attachBuff(self.Spell)
  --~ SCT.ShowScrollingMessage(self.Spell:getName() .. " (" .. self.__TurnsLeft .. " turns)", false, self.TargetRnd)
  FxEngine:playEffect("LocustSwarm", self.TargetRnd)
end

function LocustSwarm:process()
  self.Target:setBaseHP(self.Target:getBaseHP() - __DPT)
  SCT.ShowScrollingMessage("-1 health (" .. self.Spell:getName() .. ")", false, self.TargetRnd)
  --if (not target:isDead()) then
  --  target:updateTextOverlay()

    -- we play over the target's position because the target might have died
    FxEngine:playEffect("LocustSwarm", self.TargetRnd:getSceneNode():getPosition())
  --end

  self:__tick()
end

SpellValidators["Locust Swarm"] = function(spell)
  return Selected:getEntity():getRank() ~= Pixy.PUPPET
end

subscribe_spell("Locust Swarm", LocustSwarm)
