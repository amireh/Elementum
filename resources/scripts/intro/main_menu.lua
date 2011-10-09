-- UISheet : MainMenu

MainMenu = UISheet:new("intro/login.layout")

local Gremlin = nil
local Form = {}

local idx = 0
local createGremlin = function(mesh, material)

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
function MainMenu:attach()
  UISheet.attach(self)

  Form.Username = CEWindowMgr:getWindow("Elementum/Scenes/Intro/Login/TextFields/Username")
	Form.Password = CEWindowMgr:getWindow("Elementum/Scenes/Intro/Login/TextFields/Password")
  Form.Username:activate()

  --~ bind(Pixy.EventUID.EntityDied, MainMenu.onEntityDied)
	if isSetup then return true end

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

  do
    Gremlin = createGremlin("Gremlin2.mesh", "Engineer")

    Gremlin2 = createGremlin("Gremlin1.mesh", "Brawler")
    Gremlin2:getRenderable():getSceneNode():setPosition(Ogre.Vector3(10, 0, 0))
    Gremlin2:getRenderable():getSceneNode():setScale(Ogre.Vector3(15))
    Gremlin2:getRenderable():getSceneNode():yaw(Ogre.Degree(-75))
    Gremlin2:getRenderable():animateRest()

    Gremlin3 = createGremlin("Gremlin3.mesh", "Master")
    Gremlin3:getRenderable():getSceneNode():setPosition(Ogre.Vector3(-10, 0, 0))
    Gremlin3:getRenderable():getSceneNode():setScale(Ogre.Vector3(10))
    Gremlin3:getRenderable():getSceneNode():yaw(Ogre.Degree(75))

    GfxEngine:getCameraMan():setStyle(OgreBites.CS_ORBIT)
    GfxEngine:getCameraMan():setTarget(Gremlin:getRenderable():getSceneNode())
    GfxEngine:setYawPitchDist(Ogre.Vector3(0, 20, 40))
  end

  isSetup = true
end

function MainMenu:detach()
  --~ unbind(Pixy.EventUID.EntityDied, MainMenu.onEntityDied)
  UISheet.detach(self)
  --~ Pixy.UI.doneWaiting(false)
	--~ CEWindowMgr:destroyWindow(MainMenu.Layout)
  --~ MainMenu.Layout:hide()

  --~ if Gremlin then Gremlin:die() end
  if Gremlin then Gremlin:getRenderable():hide() end
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
  if SceneMgr:hasEntity("Floor") then
    SceneMgr:destroyEntity("Floor")
  end

  SceneMgr:destroyAllLights()

  Gremlin = nil
  Gremlin2 = nil
  Gremlin3 = nil

  MainMenu:detach()
  isSetup = false
end


MainMenu.reqLogin = function(inEvt)
  local self = MainMenu

	-- nop, send the event now then
	Pixy.Log("firing Login event")

	UISheet.showDialog("Connecting...")
  NetMgr:disconnect()
  NetMgr:connect()

	return true
end

MainMenu.onConnected = function(e)
  local self = MainMenu

  if e.Feedback == Pixy.EventFeedback.Error then
    UISheet.showDialog("Unable to connect to server.")
    return true
  end

  UISheet.showDialog("Authenticating...")

  -- hook login event
  local mEvt = Pixy.Event(Pixy.EventUID.Login)
  mEvt:setProperty("Username", Form.Username:getText())
  mEvt:setProperty("Password", Form.Password:getText())
  NetMgr:send(mEvt)

  Pixy.Log("Awaiting authentication reply...")
  return true
end

MainMenu.onLogin = function(e)

	if e.Feedback == Pixy.EventFeedback.Ok then
    local req = Pixy.Event(Pixy.EventUID.SyncPuppets)
    NetMgr:send(req)

    UISheet.showDialog("Retrieving character list...")

		return true
	end

  UISheet.showDialog("Login failed.")

	return true
end


MainMenu.onEntityDied = function(e)
  local entity = tolua.cast(e.Any, "Pixy::CUnit")
  local rnd = entity:getRenderable()
  rnd:hide()
  --~ FxEngine:playEffect("Elementum/Fx/Desummon", rnd:getSceneNode():getPosition())

  return true
end

MainMenu.showGremlins = function()
  if Gremlin and not Gremlin:isDead() then
    Gremlin:getRenderable():show()
  end
  if Gremlin2 then Gremlin2:getRenderable():show() end
  if Gremlin3 then Gremlin3:getRenderable():show() end
end
MainMenu.hideGremlins = function()
  if Gremlin and not Gremlin:isDead() then
    Gremlin:getRenderable():hide()
  end
  if Gremlin2 then Gremlin2:getRenderable():hide() end
  if Gremlin3 then Gremlin3:getRenderable():hide() end
end

