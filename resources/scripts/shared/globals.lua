-- CEGUI globals
CELogger = nil
CESystem = nil
CEWindowMgr = nil
CEFontMgr = nil
CESchemeMgr = nil
CEImagesetMgr = nil
CEAnimMgr = nil

-- Elementum globals
  if not Pixy then Pixy = {} end

  -- When the game data is synced from the server, the following tables will
  -- be populated the models of Spell and Unit objects which can be used
  -- throughout the game's lifetime
  Pixy.Models = {
    Spells = {},
    Units = {}
  }

  -- Managers
  EvtMgr = nil
  GameMgr = nil
  NetMgr = nil
  InputMgr = nil

  -- GameStates
  IntroState = nil
  LobbyState = nil
  CombatState = nil

  -- Engines
  GfxEngine = nil
  FxEngine = nil
  UIEngine = nil
  ScriptEngine = nil

  -- Objects
  Selected = nil -- this is the puppet that's either being chosen for creation or joining with
  -- Puppet is used in Intro when a puppet is selected to join the lobby with,
  -- and is passed on to the Combat state
  Puppet = nil
  -- the puppet our client's player is playing with
  SelfPuppet = nil
  -- the enemy puppet, not ours; mainly used to test whether we should render or update something
  EnemyPuppet = nil
  Active = nil -- the puppet with the active turn
  Waiting = nil -- the puppet who's waiting for their turn

  update = nil
  cleanup = nil

-- Ogre globals
SceneMgr = nil
CompositorMgr = nil
Viewport = nil
Window = nil
Camera = nil
CameraMan = nil
AR = { Width = 0, Height = 0 }

local registered = false
Pixy.registerGlobals = function()

  if registered then return true end

	Pixy.Log( "*************************************************")
	Pixy.Log( "* Launching Pixy Lua module!                    *")

	-- registers CEGUI singletons as globals for use by the UI sheets

	CELogger = CEGUI.Logger:getSingleton()
	CELogger:logEvent( ">>> Pixy LUA scripts engaging" )
	--CELogger:setLoggingLevel( CEGUI.Informative )

	-- get a local reference to the singletons we use (not required)
	CESystem    = CEGUI.System:getSingleton()
	CEWindowMgr = CEGUI.WindowManager:getSingleton()
	CEFontMgr   = CEGUI.FontManager:getSingleton()
	CESchemeMgr = CEGUI.SchemeManager:getSingleton()
	CEImagesetMgr = CEGUI.ImagesetManager:getSingleton()
  CEAnimMgr = CEGUI.AnimationManager:getSingleton()

	GameMgr = Pixy.GameManager:getSingleton()
	EvtMgr = Pixy.EventManager:getSingletonPtr()
  NetMgr = Pixy.NetworkManager:getSingleton()
  InputMgr = Pixy.InputManager:getSingletonPtr()

  IntroState = Pixy.Intro:getSingletonPtr()
  LobbyState = Pixy.Lobby:getSingletonPtr()
  CombatState = Pixy.Combat:getSingletonPtr()

  GfxEngine = Pixy.GfxEngine:getSingletonPtr()
  FxEngine = Pixy.FxEngine:getSingleton()
  UIEngine = Pixy.UIEngine:getSingletonPtr()
  ScriptEngine = Pixy.ScriptEngine:getSingletonPtr()

  SceneMgr = GfxEngine:getSceneMgr()
  CompositorMgr = Ogre.CompositorManager:getSingletonPtr()
  Viewport = GfxEngine:getViewport()
  Window = GfxEngine:getWindow()
  Camera = GfxEngine:getCamera()
  CameraMan = GfxEngine:getCameraMan()
  AR = { Width = Viewport:getActualWidth(), Height = Viewport:getActualHeight() }

	Pixy.Log( "* Launched successfully!                        *")
	Pixy.Log( "*************************************************")

	registered = true
end
