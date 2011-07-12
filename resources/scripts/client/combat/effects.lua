Pixy.Effects = {}
Pixy.Effects.Configure = function()
  Pixy.Log("Registering spell effects")
  FxEngine:loadEffect("Elementum/Fx/Highlight")
  FxEngine:loadEffect("Elementum/Fx/BlackHole")
  --FxEngine:loadEffect("Elementum/Fx/Seal")
  FxEngine:loadEffect("Elementum/Fx/Aurora")
  FxEngine:registerHighlightEffect("Elementum/Fx/Aurora")
end

Pixy.Effects.Configure()
