-- UISheet : MainMenu

MainMenu = {}
local Gremlin = nil

local Form = {}
require "lfs"
MainMenu.CreateGremlin = function()

  local unit = Pixy.CUnit:new()
  --~ unit:setRank(Pixy.PUPPET)
  unit:setName("IntroGremlin")
  unit:live()
  unit:setMesh("Gremlin1.mesh")
  unit:setMaterial("Elementum/Gremlin/Intro")

  rnd = unit:getRenderable()

  local node = SceneMgr:createSceneNode("gremlin_node")
  SceneMgr:getRootSceneNode():addChild(node)
  local ent = SceneMgr:createEntity("Gremlin", unit:getMesh());
  ent:setMaterialName(unit:getMaterial())
  ent:setCastShadows(true)
  node:attachObject(ent)
  node:setScale(Ogre.Vector3(20))
  node:setPosition(Ogre.Vector3(0,0,0))
  rnd:attachSceneObject(ent)
  rnd:attachSceneNode(node)

  --~ GfxEngine:loadScene("DarkMansion.scene")
  --~ rnd:attachSceneNode(SceneMgr:getSceneNode("troll"))
  --~ rnd:attachSceneObject(tolua.cast(rnd:getSceneNode():getAttachedObject("troll"), "Ogre::Entity"))

  rnd:setup(SceneMgr)


  GfxEngine:attachToScene(rnd)
--~
  GfxEngine:getCameraMan():setStyle(OgreBites.CS_ORBIT)
  --~ GfxEngine:getCameraMan():setTarget(gremlin:getRenderable():getSceneNode())
  GfxEngine:trackNode(node)
  GfxEngine:setYawPitchDist(Ogre.Vector3(0, 20, 40))

  rnd:registerAnimationState(Pixy.Renderable.ANIM_IDLE,   "Idle_1")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_IDLE,   "Idle_2")
  --~ rnd:registerAnimationState(Pixy.Renderable.ANIM_IDLE,   "Idle_3")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_DIE,  "Death_1", false)
  rnd:registerAnimationState(Pixy.Renderable.ANIM_DIE,  "Death_2", false)
--~
  rnd:animateIdle()

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
  Camera = GfxEngine:getCamera()

  Camera:setAspectRatio(Viewport:getActualWidth() / Viewport:getActualHeight())
  Camera:setNearClipDistance( 10 )
  Camera:setFarClipDistance( 10000 )

  SceneMgr:setAmbientLight(Ogre.ColourValue(100,100,100))

  fadeColour = Ogre.ColourValue(0, 0, 0)
  --~ SceneMgr:setFog(Ogre.FOG_EXP2, fadeColour, 0.0075)
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
  ent:setCastShadows(true)
  ent:setRenderQueueGroup( Ogre.RENDER_QUEUE_BACKGROUND );
  SceneMgr:getRootSceneNode():attachObject(ent)

  -- Lights
  local pos = Ogre.Vector3(0,100,30)
  local dcol = Ogre.ColourValue(155,155,155)
  local scol = Ogre.ColourValue(155,155,155)
  local light = nil

  light = SceneMgr:createLight()
  light:setType(Ogre.Light.LT_POINT)
  light:setPosition(pos)
  light:setDiffuseColour(dcol)
  light:setSpecularColour(scol)

  pos = Ogre.Vector3(pos.x, 0, 80)
  dcol = Ogre.ColourValue(155,155,155)
  scol = Ogre.ColourValue(155,155,155)
  light = SceneMgr:createLight()
  light:setType(Ogre.Light.LT_POINT)
  light:setPosition(pos)
  light:setDiffuseColour(dcol)
  light:setSpecularColour(scol)

  Gremlin = MainMenu.CreateGremlin()

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
  if Gremlin then Gremlin:delete() end
  Gremlin = nil
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
