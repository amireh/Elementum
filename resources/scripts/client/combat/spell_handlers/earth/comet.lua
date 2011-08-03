local process = function(inCaster, inTarget, inSpell)
	Pixy.Log("I'm throwing a Comet!")
  FxEngine:playEffect("Elementum/Fx/Explosion", inTarget:getSceneNode():getPosition())
  FxEngine:playEffect("Elementum/Fx/ExplosionDirt", inTarget:getSceneNode():getPosition())
	return true
end

subscribe_spell("Comet", process)
