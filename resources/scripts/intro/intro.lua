-- Selected points to the puppet that is chosen to join the lobby with.
-- On switching to Combat state, Intro::setPuppetName() is called with
-- this puppet's name so that Combat can tell which puppet is self's
Selected = nil

if not Intro.Puppets then Intro.Puppets = {} end

Intro.oneTimeRun = function()
  Intro.bind()
  MainMenu.attach()
end

Intro.cleanup = function(e)
  Pixy.Log("Cleaning up in Intro state")

  MainMenu.cleanup()
  Profiles.cleanup()
  Chat.cleanup()
  Decks.cleanup()

  --~ CEWindowMgr:destroyAllWindows()
  FxEngine:unloadAllEffects()
  SceneMgr:clearScene()
  
  return true
end

Intro.shutdown = function(e)
  --Intro.cleanup()
  MainMenu.cleanup()
  Profiles.cleanup()
  Chat.cleanup()
  Decks.cleanup()  
  Pixy.cleanup()

  return true
end
