local DeathExchange = {}
function DeathExchange:cast()
	Pixy.Log("I'm casting Death Exchange!")
  FxEngine:playEffect("BloodForBlood", self.CasterRnd)

  self.Target:die()
  SCT.ShowScrollingMessage("+2 channels (Death Exchange)", true, self.CasterRnd)
  Gfx.Dehighlight()

	return true
end

subscribe_spell("Death Exchange", DeathExchange)
