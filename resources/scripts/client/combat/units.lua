Pixy.Combat.CreateUnit = function(inUnit)
  FxEngine:playEffect("Elementum/Fx/Summon", inUnit:getRenderable())
  return true
end
