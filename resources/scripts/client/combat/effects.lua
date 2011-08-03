Pixy.Effects = {}
Pixy.Effects.Configure = function()
  Pixy.Log("Registering spell effects")
  FxEngine:loadEffect("Elementum/Fx/Highlight")
  FxEngine:loadEffect("Elementum/Fx/Explosion")
  FxEngine:loadEffect("Elementum/Fx/ExplosionDirt")
  --FxEngine:loadEffect("Elementum/Fx/Seal")
  FxEngine:loadEffect("Elementum/Fx/Aurora")
  FxEngine:loadEffect("Elementum/Fx/Summon")
  FxEngine:loadEffect("Elementum/Fx/MindControl")
  FxEngine:loadEffect("Elementum/Fx/Nourish")
  FxEngine:loadEffect("Elementum/Fx/Fatigue")

  FxEngine:loadEffect("Elementum/Fx/Comet")
  FxEngine:loadEffect("Elementum/Fx/CometExplosion")


  FxEngine:loadEffect("Elementum/Fx/BloodStrike2")
  FxEngine:loadEffect("Elementum/Fx/BloodStrike3")
  FxEngine:loadEffect("Elementum/Fx/BloodSplat")
  FxEngine:loadEffect("Elementum/Fx/BloodSpray")

  FxEngine:registerHighlightEffect("Elementum/Fx/Aurora")
end

Pixy.Effects.Configure()
