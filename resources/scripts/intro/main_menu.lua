-- UISheet : MainMenu

MainMenu = {}
local Gremlin = nil

local Form = {}
require "lfs"
local idx = 0
MainMenu.CreateGremlin = function(mesh, material)

  local unit = Pixy.CUnit:new()
  --~ unit:setRank(Pixy.PUPPET)
  unit:setName("IntroGremlin" .. idx)
  unit:live()
  unit:setMesh(mesh)
  unit:setMaterial("Elementum/Gremlin/" .. material)

  rnd = unit:getRenderable()

  local node = SceneMgr:createSceneNode("gremlin_node" .. idx)
  SceneMgr:getRootSceneNode():addChild(node)
  --~ node:showBoundingBox(true)
  local ent = SceneMgr:createEntity("Gremlin" .. idx, unit:getMesh())
  ent:setMaterialName(unit:getMaterial())
  ent:setCastShadows(true)
  node:attachObject(ent)
  node:setScale(Ogre.Vector3(20))
  node:setPosition(Ogre.Vector3(0,0,0))

  local _size = ent:getWorldBoundingBox(true):getSize()
  print("\tGremlin " .. mesh .. " Size: " .. _size.x .. "," .. _size.y .. "," .. _size.z)

  rnd:attachSceneObject(ent)
  rnd:attachSceneNode(node)

  --~ GfxEngine:loadScene("DarkMansion.scene")
  --~ rnd:attachSceneNode(SceneMgr:getSceneNode("troll"))
  --~ rnd:attachSceneObject(tolua.cast(rnd:getSceneNode():getAttachedObject("troll"), "Ogre::Entity"))

  rnd:setup(SceneMgr)


  GfxEngine:attachToScene(rnd)

  if material ~= "Master" then
    rnd:registerAnimationState(Pixy.Renderable.ANIM_IDLE,   "Idle_1")
    rnd:registerAnimationState(Pixy.Renderable.ANIM_IDLE,   "Idle_2")
  else
    -- the master gremlin yawns, the others dont
    rnd:registerAnimationState(Pixy.Renderable.ANIM_IDLE,   "Idle_3")
  end
  rnd:registerAnimationState(Pixy.Renderable.ANIM_WALK,   "Walk_1")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_RUN,    "Run_1")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_RUN,    "Run_2")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_DIE,    "Death_1", false)
  rnd:registerAnimationState(Pixy.Renderable.ANIM_DIE,    "Death_2", false)
  rnd:registerAnimationState(Pixy.Renderable.ANIM_ATTACK, "Attack_1", false)
  rnd:registerAnimationState(Pixy.Renderable.ANIM_ATTACK, "Attack_2", false)
  rnd:registerAnimationState(Pixy.Renderable.ANIM_ATTACK, "Attack_3", false)
  rnd:registerAnimationState(Pixy.Renderable.ANIM_REST,   "Idle_Sitting")
  --~ rnd:registerAnimationState(Pixy.Renderable.ANIM_REST,    "Idle_Sleeping")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_GETUP,   "Jump", false)
  rnd:registerAnimationState(Pixy.Renderable.ANIM_GETUP,   "Jumping_Happy", false)

  rnd:animateIdle()

  idx = idx + 1

  return unit
end

local isSetup = false
MainMenu.attach = function()
  Pixy.Effects.Configure()

	MainMenu.Layout = Pixy.UI.attach("intro/login.layout")
  Form.Username = CEWindowMgr:getWindow("Elementum/Scenes/Intro/Login/TextFields/Username")
	Form.Password = CEWindowMgr:getWindow("Elementum/Scenes/Intro/Login/TextFields/Password")
  Form.Username:activate()

  --~ MainMenu.Layout:hide()
  --~ bind(Pixy.EventUID.EntityDied, MainMenu.onEntityDied)
	if isSetup then return true end

  SceneMgr = GfxEngine:getSceneMgr()
  Viewport = GfxEngine:getViewport()
  Window = GfxEngine:getWindow()
  Camera = GfxEngine:getCamera()

  Camera:setAspectRatio(Viewport:getActualWidth() / Viewport:getActualHeight())
  Camera:setNearClipDistance( 10 )
  Camera:setFarClipDistance( 10000 )

  SceneMgr:setAmbientLight(Ogre.ColourValue(0,0,0))

  fadeColour = Ogre.ColourValue(0,0,0)
  SceneMgr:setFog(Ogre.FOG_EXP2, fadeColour, 0.015)
  --~ SceneMgr:setShadowTechnique(Ogre.SHADOWTYPE_STENCIL_MODULATIVE)

  -- Movable Text Overlay attributes
  --~ GfxEngine.mMTOFontColor = Ogre.ColourValue(1,1,1)
  --~ GfxEngine.mMTOFontName = "DejaVuSans"
  --~ GfxEngine.mMTOFontSize = 16
  --~ GfxEngine.mMTOMaterialName = "RedTransparent"
  --~ GfxEngine:setupMovableTextOverlays()

  -- Sky
  --SceneMgr:setSkyDome(true, "Elementum/Sky", 1, 1,1000,true);
  --SceneMgr:setSkyBox(true, "Elementum/Sky", 5000, true);
  --~ GfxEngine:createSphere("MySkyDome", 180, 64, 64)
  --~ sphereEntity = SceneMgr:createEntity("MySkyDomeEntity", "MySkyDome")
  --~ sphereNode = SceneMgr:getRootSceneNode():createChildSceneNode()
  --~ sphereEntity:setMaterialName("Elementum/Sky")
  --~ sphereEntity:setRenderQueueGroup( Ogre.RENDER_QUEUE_BACKGROUND );
  --~ sphereNode:attachObject(sphereEntity)

  -- Terrain
  Ogre.MeshManager:getSingleton():createPlane(
    "floor", Ogre.ResourceGroupManager.DEFAULT_RESOURCE_GROUP_NAME,
			Ogre.Plane:new(Ogre.Vector3.UNIT_Y, 0), 512, 512, 10, 10, true, 1, 10, 10, Ogre.Vector3.UNIT_Z);
  ent = SceneMgr:createEntity("Floor", "floor");
  ent:setMaterialName("Elementum/Terrain/Floor");
  --~ ent:setCastShadows(true)
  ent:setRenderQueueGroup( Ogre.RENDER_QUEUE_BACKGROUND );
  SceneMgr:getRootSceneNode():attachObject(ent)

  -- Lights
  local pos = Ogre.Vector3(0,100,30)
  local dcol = Ogre.ColourValue(0.9,0.9,0.9)
  local scol = Ogre.ColourValue(0.9,0.9,0.9)
  local light = nil

  light = SceneMgr:createLight()
  light:setType(Ogre.Light.LT_POINT)
  light:setPosition(pos)
  light:setDiffuseColour(dcol)
  light:setSpecularColour(scol)

  pos = Ogre.Vector3(pos.x, 15, 10)
  dcol = Ogre.ColourValue(0.8,0.8,0.8)
  scol = Ogre.ColourValue(0.8,0.8,0.8)
  light = SceneMgr:createLight()
  light:setType(Ogre.Light.LT_POINT)
  light:setPosition(pos)
  light:setDiffuseColour(dcol)
  light:setSpecularColour(scol)

  Gremlin = MainMenu.CreateGremlin("Gremlin2.mesh", "Engineer")

  Gremlin2 = MainMenu.CreateGremlin("Gremlin1.mesh", "Brawler")
  Gremlin2:getRenderable():getSceneNode():setPosition(Ogre.Vector3(10, 0, 0))
  Gremlin2:getRenderable():getSceneNode():setScale(Ogre.Vector3(15))
  Gremlin2:getRenderable():getSceneNode():yaw(Ogre.Degree(-75))
  Gremlin2:getRenderable():animateRest()

  Gremlin3 = MainMenu.CreateGremlin("Gremlin3.mesh", "Master")
  Gremlin3:getRenderable():getSceneNode():setPosition(Ogre.Vector3(-10, 0, 0))
  Gremlin3:getRenderable():getSceneNode():setScale(Ogre.Vector3(10))
  Gremlin3:getRenderable():getSceneNode():yaw(Ogre.Degree(75))

  GfxEngine:getCameraMan():setStyle(OgreBites.CS_ORBIT)
  GfxEngine:getCameraMan():setTarget(Gremlin:getRenderable():getSceneNode())
  GfxEngine:setYawPitchDist(Ogre.Vector3(0, 20, 40))

  isSetup = true
end

MainMenu.detach = function()
  --~ unbind(Pixy.EventUID.EntityDied, MainMenu.onEntityDied)

  --~ Pixy.UI.doneWaiting(false)
	--~ CEWindowMgr:destroyWindow(MainMenu.Layout)
  --~ MainMenu.Layout:hide()
  Pixy.UI.detach(MainMenu.Layout)
  Form = {}

  Gremlin:die()
end

MainMenu.Quit = function(e)
  --Intro.cleanup()
  IntroState:requestShutdown()
end

MainMenu.cleanup = function()
  if not isSetup then return false end
  GfxEngine:getCameraMan():setTarget(nil)
  GfxEngine:getCameraMan():setStyle(OgreBites.CS_FREELOOK)
  if Gremlin then
    Gremlin:delete()
    Gremlin2:delete()
    Gremlin3:delete()
  end
  if RTT then
    --~ RTT:delete()
    --~ SceneMgr:destroyCamera(testCamera)
    RTT = nil
    testCamera = nil
  end
  Gremlin = nil
  Gremlin2 = nil
  Gremlin3 = nil
  isSetup = false
end


MainMenu.reqLogin = function(inEvt)

	-- nop, send the event now then
	Pixy.Log("firing Login event")

	Pixy.UI.waiting("Connecting...", MainMenu.Layout)
  NetMgr:disconnect()
  NetMgr:connect()

	return true
end

MainMenu.onConnected = function(e)
  if e.Feedback == Pixy.EventFeedback.Error then
    PBox_Label:setText("Unable to connect to server.")
    Pixy.UI.doneWaiting(true)
    return true
  end

  Pixy.UI.doneWaiting(false)
  Pixy.UI.waiting("Authenticating", MainMenu.Layout)

  -- hook login event
  local mEvt = Pixy.Event(Pixy.EventUID.Login)
  mEvt:setProperty("Username", Form.Username:getText())
  mEvt:setProperty("Password", Form.Password:getText())
  NetMgr:send(mEvt)

  Pixy.Log("Awaiting authentication reply...")
  return true
end

MainMenu.onLogin = function(inEvt)
	Pixy.UI.doneWaiting(true)

	if (inEvt.Feedback == Pixy.EventFeedback.Ok) then
		Pixy.Log("login successful")

    local req = Pixy.Event(Pixy.EventUID.SyncPuppets)
    NetMgr:send(req)

		return true
	end

	Pixy.Log("login failed")
	PBox_Label:setText("Login failed.")

	return true
end


MainMenu.onEntityDied = function(e)
  local entity = tolua.cast(e.Any, "Pixy::CUnit")
  local rnd = entity:getRenderable()
  rnd:hide()
  FxEngine:playEffect("Elementum/Fx/Desummon", rnd:getSceneNode():getPosition())

  return true
end
