local __DPT = 1 -- damage caused per turn

local LocustSwarm = {}
function LocustSwarm:cast()
  self:logMe()
  -- attach the buff to the puppet
  self.Target:attachBuff(self.Spell)
  --~ self.Target = tolua.cast(self.Target, "Pixy::Unit")
  --~ SCT.ShowScrollingMessage(self.Spell:getName() .. " (" .. self.__TurnsLeft .. " turns)", false, self.Target)
  FxEngine:playEffect("LocustSwarm", self.Target)
end

function LocustSwarm:process()
  SCT.ShowScrollingMessage("-1 health (" .. self.Spell:getName() .. ")", false, self.Target)
  self.Target:setBaseHP(self.Target:getBaseHP() - __DPT)
  --if (not target:isDead()) then
  --  target:updateTextOverlay()

    -- we play over the target's position because the target might have died
    FxEngine:playEffect("LocustSwarm", self.Target:getSceneNode():getPosition())
  --end

  self:__tick()
end

SpellValidators["Locust Swarm"] = function(spell)
  return not Selected:isPuppet()
end

subscribe_spell("Locust Swarm", LocustSwarm)
