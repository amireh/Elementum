local process = function(inCaster, inTarget, inSpell)
	Pixy.Log("I'm throwing a Comet!")
  FxEngine:playEffect("Explosion/mp_explosion_04", inTarget:getSceneNode():getPosition())
  FxEngine:playEffect("Explosion/mp_dirt_01", inTarget:getSceneNode():getPosition())
	return true
end

subscribe_spell("Comet", process)
