Fx = {}
local isSetup = false
local highlight_effect = nil
Fx.setup = function()
  if isSetup then return true end

  Pixy.Log("Registering spell effects")
  FxEngine:loadEffect("Elementum/Fx/Highlight")
  FxEngine:loadEffect("Elementum/Fx/Explosion")
  FxEngine:loadEffect("Elementum/Fx/ExplosionDirt")
  --FxEngine:loadEffect("Elementum/Fx/Seal")
  highlight_effect = FxEngine:loadEffect("Elementum/Fx/Aurora")
  FxEngine:loadEffect("Elementum/Fx/Summon")
  FxEngine:loadEffect("Elementum/Fx/Desummon")
  FxEngine:loadEffect("Elementum/Fx/MindControl")
  FxEngine:loadEffect("Elementum/Fx/Nourish")
  FxEngine:loadEffect("Elementum/Fx/Fatigue")

  FxEngine:loadEffect("Elementum/Fx/Comet")
  FxEngine:loadEffect("Elementum/Fx/CometExplosion")

  FxEngine:loadEffect("Elementum/Fx/BloodStrike2")
  FxEngine:loadEffect("Elementum/Fx/BloodStrike3")
  FxEngine:loadEffect("Elementum/Fx/BloodSplat")
  FxEngine:loadEffect("Elementum/Fx/BloodSpray")

  FxEngine:loadEffect("BoneHarvest")
  FxEngine:loadEffect("BoneArmor")
  FxEngine:loadEffect("LocustSwarm")
  FxEngine:loadEffect("Aftermath")
  FxEngine:loadEffect("Anger")
  FxEngine:loadEffect("BloodForBlood")
  FxEngine:loadEffect("BurnOut")
  FxEngine:loadEffect("KissOfDeath")
  FxEngine:loadEffect("CrownOfDestruction")
  FxEngine:loadEffect("DestructivePassion")
  FxEngine:loadEffect("FireSummoning")
  FxEngine:loadEffect("FlameShield")
  FxEngine:loadEffect("Immolation")
  FxEngine:loadEffect("Insanity")
  FxEngine:loadEffect("RagingFury")
  FxEngine:loadEffect("SmokeScreen")
  FxEngine:loadEffect("SuddenCraven")
  FxEngine:loadEffect("Redirect")
  FxEngine:loadEffect("Negate")
  FxEngine:loadEffect("Gloom")
  FxEngine:loadEffect("GladeBlessing")
  FxEngine:loadEffect("EarthSummoning")

  --FxEngine:registerHighlightEffect("Elementum/Fx/Aurora")

  isSetup = true
  return true
end

Fx.cleanup = function()
  FxEngine:unloadAllEffects()
  isSetup = false
end

Fx.highlight = function(rnd)
  highlight_effect:stop()
  FxEngine:playEffect(highlight_effect, rnd)
end

Fx.dehighlight = function()
  highlight_effect:stop()
end
