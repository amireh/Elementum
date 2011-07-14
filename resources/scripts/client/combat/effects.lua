Pixy.Effects = {}
Pixy.Effects.Configure = function()
  Pixy.Log("Registering spell effects")
  FxEngine:loadEffect("Elementum/Fx/Highlight")
  FxEngine:loadEffect("Elementum/Fx/BlackHole")
  --FxEngine:loadEffect("Elementum/Fx/Seal")
  FxEngine:loadEffect("Elementum/Fx/Aurora")

  FxEngine:loadEffect("Elementum/Fx/BloodStrike2")
  FxEngine:loadEffect("Elementum/Fx/BloodStrike3")
  FxEngine:loadEffect("Elementum/Fx/BloodSplat")
  FxEngine:loadEffect("Elementum/Fx/BloodSpray")

  FxEngine:registerHighlightEffect("Elementum/Fx/Aurora")
end

Pixy.Effects.Configure()
