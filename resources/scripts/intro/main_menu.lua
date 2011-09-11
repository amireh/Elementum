-- UISheet : MainMenu

MainMenu = {}
Units = {}

local Form = {}

MainMenu.CreateGremlin = function()

  unit = Pixy.CUnit()
  --~ unit:setRank(Pixy.PUPPET)
  unit:live()
  unit:setMesh("Gremlin1.mesh")
  unit:setMaterial("Elementum/Gremlin/Intro")

  rnd = unit:getRenderable()

  local node = SceneMgr:createSceneNode("gremlin_node")
  SceneMgr:getRootSceneNode():addChild(node)
  local ent = SceneMgr:createEntity("Gremlin", "Gremlin1.mesh");
  ent:setMaterialName("Elementum/Gremlin/Psycho")
  ent:setCastShadows(true)
  node:attachObject(ent)
  node:setScale(Ogre.Vector3:new(20))
  node:setPosition(Ogre.Vector3:new(0,0,0))
  rnd:attachSceneObject(ent)
  rnd:attachSceneNode(node)
  rnd:setup(SceneMgr)

  GfxEngine:attachToScene(rnd)

  GfxEngine:getCameraMan():setStyle(OgreBites.CS_ORBIT)
  --~ GfxEngine:getCameraMan():setTarget(gremlin:getRenderable():getSceneNode())
  GfxEngine:trackNode(node)
  GfxEngine:setYawPitchDist(Ogre.Vector3:new(0, 20, 40))

  rnd:registerAnimationState(Pixy.Renderable.ANIM_IDLE,   "Idle_1")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_IDLE,   "Idle_2")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_IDLE,   "Idle_3")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_DIE,  "Death_1", false)
  rnd:registerAnimationState(Pixy.Renderable.ANIM_DIE,  "Death_2", false)

  rnd:animateIdle()

  table.insert(Units, unit)

  return unit
end

local isSetup = false
MainMenu.attach = function()
	MainMenu.Layout = Pixy.UI.attach("intro/login.layout")
  Form.Username = CEWindowMgr:getWindow("Elementum/Scenes/Intro/Login/TextFields/Username")
	Form.Password = CEWindowMgr:getWindow("Elementum/Scenes/Intro/Login/TextFields/Password")
  Form.Username:activate()

	if isSetup then return true end

  SceneMgr = GfxEngine:getSceneMgr()
  Viewport = GfxEngine:getViewport()
  Camera = GfxEngine:getCamera()

  Camera:setAspectRatio(Viewport:getActualWidth() / Viewport:getActualHeight())
  Camera:setNearClipDistance( 10 )
  Camera:setFarClipDistance( 10000 )

  SceneMgr:setAmbientLight(Ogre.ColourValue(100,100,100))

  fadeColour = Ogre.ColourValue:new(0, 0, 0)
  SceneMgr:setFog(Ogre.FOG_EXP2, fadeColour, 0.0075)
  --~ SceneMgr:setShadowTechnique(Ogre.SHADOWTYPE_STENCIL_MODULATIVE)

  -- Movable Text Overlay attributes
  --~ GfxEngine.mMTOFontColor = Ogre.ColourValue:new(1,1,1)
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

  Pos = { Me = Ogre.Vector3:new(0,100,30) }
  local pos = Ogre.Vector3:new(Pos.Me.x, Pos.Me.y, Pos.Me.z)
  dcol = Ogre.ColourValue:new(155,0,0)
  scol = Ogre.ColourValue:new(155,0,0)
  light = SceneMgr:createLight()
  light:setType(Ogre.Light.LT_POINT)
  light:setPosition(pos)
  light:setDiffuseColour(dcol)
  light:setSpecularColour(scol)

  pos = Ogre.Vector3:new(Pos.Me.x, 0, 80)
  dcol = Ogre.ColourValue:new(155,0,0)
  scol = Ogre.ColourValue:new(155,0,0)
  light = SceneMgr:createLight()
  light:setType(Ogre.Light.LT_POINT)
  light:setPosition(pos)
  light:setDiffuseColour(dcol)
  light:setSpecularColour(scol)

  gremlin = MainMenu.CreateGremlin()

  isSetup = true
end

MainMenu.detach = function()
  Pixy.UI.doneWaiting(false)
	--~ CEWindowMgr:destroyWindow(MainMenu.Layout)
  --~ MainMenu.Layout:hide()
  Pixy.UI.detach(MainMenu.Layout)
  Form = {}
end

MainMenu.Quit = function(e)
	MainMenu.detach()
  IntroState:requestShutdown()
end


MainMenu.reqLogin = function(inEvt)

	-- nop, send the event now then
	Pixy.Log("firing Login event")

	Pixy.UI.waiting("Connecting...", MainMenu.Layout)
  connected = NetMgr:connect()
  if (connected) then
    Pixy.UI.doneWaiting(false)
    Pixy.UI.waiting("Authenticating", MainMenu.Layout)

    -- hook login event
    local mEvt = Pixy.Event(Pixy.EventUID.Login)
    mEvt:setProperty("Username", Form.Username:getText())
    mEvt:setProperty("Password", Form.Password:getText())
    NetMgr:send(mEvt)
    mEvt = nil
  else
    PBox_Label:setText("Unable to connect to server.")
    Pixy.UI.doneWaiting(true)
  end

	return true
end

MainMenu.onLogin = function(inEvt)
	Pixy.UI.doneWaiting(true)

	if (inEvt.Feedback == Pixy.EventFeedback.Ok) then
		Pixy.Log("login successful")

		MainMenu.detach()
		Profiles.attach()
		return true
	end

	Pixy.Log("login failed")
	PBox_Label:setText("Failed")

	return true
end

MainMenu.cleanup = function()
  if not isSetup then return true end

  Pixy.Log("Cleaning up in Intro state")
  FxEngine:dehighlight()
  for unit in list_iter(Units) do
    --~ unit:die()
    unit:delete()
  end
  Units = {}
  FxEngine:unloadAllEffects()
  SceneMgr:clearScene()

  return true
end

MainMenu.onEntityDied = function(e)
  unit = tolua.cast(e.Any, "Pixy::CUnit")
  unit:getRenderable():hide()
  FxEngine:playEffect("Elementum/Fx/Desummon", unit:getRenderable():getSceneNode():getPosition())

  return true
end

MainMenu.attach()
