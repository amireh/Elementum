Intro = {
  Puppets = {}
}

Intro.onEnter = function()
  -- Selected points to the puppet that is chosen to join the lobby with.
  -- On switching to Combat state, Intro::setPuppetName() is called with
  -- this puppet's name so that Combat can tell which puppet is self's
  Selected = nil

  Pixy.Log("Entering Intro state")

  Fx.setup()
  Intro.bind()
  MainMenu:attach()
end

Intro.onExit = function()
  Pixy.Log("Cleaning up in Intro state")

  MainMenu.cleanup()
  Profiles.cleanup()
  Chat.cleanup()
  Decks.cleanup()
  Fx.cleanup()

  --~ CEWindowMgr:destroyAllWindows()
  --~ FxEngine:unloadAllEffects()
  --~ SceneMgr:clearScene()

  return true
end

Intro.shutdown = function(e)
  Intro.onExit()
  --~ MainMenu.cleanup()
  --~ Profiles.cleanup()
  --~ Chat.cleanup()
  --~ Decks.cleanup()

  Pixy.cleanup()

  return true
end

Intro.onGameDataSynced = function(e)
  Pixy.Log("Game data synced, parsing it in lua")
  local ret = ScriptEngine:_passGameData()

  Pixy.Models.Spells = __SpellsTemp
  __SpellsTemp = nil

  --~ local race = 0
  --~ while race ~= 4 do
    --~ for k,v in ipairs(Pixy.Models.Spells[race]) do
      --~ print(k .. " => " .. v:getName())
    --~ end
    --~ race = race + 1
  --~ end

  return true
end
