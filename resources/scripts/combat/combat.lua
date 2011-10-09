if not Combat.Puppets then Combat.Puppets = {} end

Combat.onEnter = function()
  Pixy.Log("Entering Combat state")

  Gfx.PrepareScene()
  UI:attach()

  Combat.bind()
  Fx.setup()
end

Combat.onExit = function()
  Pixy.Log("Exiting Combat state")

  --~ UI:detach()
  Turns.cleanup()
  Spells.cleanup()
  UI.cleanup()
  Gfx.cleanup()
  Puppets.cleanup()

  --~ CEWindowMgr:destroyAllWindows()

  --Keybindings = {}

  --FxEngine:unloadAllEffects()
  Fx.cleanup()
  --~ SceneMgr:clearScene()

end

Combat.onShutdown = function()
  Pixy.Log("Combat: preparing for obtrusive shutdown")
end

Combat.onGameStarted = function()
	Pixy.Log("Game has started! Pwning time")

  GfxEngine:getCameraMan():setTarget(SelfPuppet:getRenderable():getSceneNode())
  GfxEngine:setYawPitchDist( Ogre.Vector3(180, 30, 140) )

  Gfx.ShowPortrait(SelfPuppet:getRenderable(), true)
  UI.Highlight(SelfPuppet, true)
  Gfx.ShowPortrait(EnemyPuppet:getRenderable(), false)
  UI.Highlight(EnemyPuppet, false)

  --~ GfxEngine:enableCompositorEffect("HDR")

	return true
end
