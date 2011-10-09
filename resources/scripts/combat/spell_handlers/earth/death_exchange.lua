local process = function(inCaster, inTarget, inSpell)
	Pixy.Log("I'm casting Death Exchange!")
  FxEngine:playEffect("BloodForBlood", inCaster)

  inSpell:getTarget():getEntity():die()
  SCT.ShowScrollingMessage("+2 channels (Death Exchange)", true, inCaster)
  Gfx.Dehighlight()

	return true
end

subscribe_spell("Death Exchange", process)
