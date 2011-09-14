require("helpers")
require("combat/puppets") -- puppet handling
require("combat/units") -- unit handling
--~ require("spells/bootstrap_spells") -- unit definitions
--~ require("units/bootstrap_units") -- unit definitions

local SceneMgr = nil
local Viewport = nil
local Camera = nil

local Pos = { Me = Ogre.Vector3:new(0,0,0), Enemy = Ogre.Vector3:new(0,0,0) }

BBSet = nil
BB = nil
BBNode = nil
Scene = nil

Combat.PrepareScene = function()
  Pixy.Log("COMBAT SCENE IS PREPARED")

  SceneMgr = GfxEngine:getSceneMgr()
  Viewport = GfxEngine:getViewport()
  Camera = GfxEngine:getCamera()

  -- Movable Text Overlay attributes
  GfxEngine.mMTOFontColor = Ogre.ColourValue:new(1,1,1)
  GfxEngine.mMTOFontName = "DejaVuSans"
  GfxEngine.mMTOFontSize = 16
  GfxEngine.mMTOMaterialName = "RedTransparent"
  GfxEngine:setupMovableTextOverlays()

  -- Hero nodes stuff
  GfxEngine.mPuppetPos[0] = Ogre.Vector3:new(0,0,-35)
  GfxEngine.mPuppetPos[1] = Ogre.Vector3:new(0,0,35)
  GfxEngine.mPuppetScale = Ogre.Vector3:new(5,5,5)
  GfxEngine.mUnitScale = Ogre.Vector3:new(1,1,1)
  Pos.Me = GfxEngine.mPuppetPos[0]
  Pos.Enemy = GfxEngine.mPuppetPos[1]

  GfxEngine.mUnitMargin.x = 15 -- the distance between every unit on the X axis
  GfxEngine.mUnitMargin.z = 10 -- the distance between the frontier and rear of the unit packs on the Z axis
  --GfxEngine.mPuppetMargin.x = 10 -- how far units are from the puppet on the X axis
  GfxEngine.mPuppetMargin.z = 35 -- how far puppets are from each other
  GfxEngine.mPackSpacing = 20 -- how far every unit pack is from the other on the X axis

  -- Viewport
  Viewport:setBackgroundColour(Ogre.ColourValue:new(0,0,0))

  -- Camera
  Camera:setAspectRatio(Viewport:getActualWidth() / Viewport:getActualHeight())
  Camera:setNearClipDistance( 10 )
  Camera:setFarClipDistance( 10000 )
  GfxEngine.mCameraYawPitchDist = Ogre.Vector3:new(180, 30, 140)
  GfxEngine:getCameraMan():setStyle(OgreBites.CS_FREELOOK)
  -- Sky
  --SceneMgr:setSkyDome(true, "Elementum/Sky", 1, 1,1000,true);
  --SceneMgr:setSkyBox(true, "Elementum/Sky", 5000, true);
  --~ GfxEngine:createSphere("MySkyDome", 500, 64, 64)
  --~ sphereEntity = SceneMgr:createEntity("MySkyDomeEntity", "MySkyDome")
  --~ sphereNode = SceneMgr:getRootSceneNode():createChildSceneNode()
  --~ sphereEntity:setMaterialName("Elementum/Sky")
  --~ sphereEntity:setRenderQueueGroup( Ogre.RENDER_QUEUE_BACKGROUND );
  --~ sphereNode:attachObject(sphereEntity)

  -- Terrain
  --Ogre.MeshManager:getSingleton():createPlane(
  --  "floor", Ogre.ResourceGroupManager.DEFAULT_RESOURCE_GROUP_NAME,
	--		Ogre.Plane:new(Ogre.Vector3.UNIT_Y, 0), 512, 512, 10, 10, true, 1, 10, 10, Ogre.Vector3.UNIT_Z);
  --ent = SceneMgr:createEntity("Floor", "floor");
  --ent:setMaterialName("Elementum/Terrain/Floor");
  --ent:setCastShadows(true)
  --ent:setRenderQueueGroup( Ogre.RENDER_QUEUE_BACKGROUND );
  --SceneMgr:getRootSceneNode():attachObject(ent)
  --~ GfxEngine:loadDotScene("Elementum.scene", "General")
  --~ Scene = GfxEngine:loadScene("DarkMansion.scene")
  Scene = GfxEngine:loadScene("MoltenChasm.scene")
  GfxEngine:getSceneMgr():getEntity("arena_02"):setRenderQueueGroup(Ogre.RENDER_QUEUE_BACKGROUND)
  GfxEngine:getSceneMgr():getEntity("arena_02"):setCastShadows(false)
  --local mask = tolua.cast(Pixy.GfxEngine.TERRAIN_MASK, "Ogre::uint32")
  --GfxEngine:getSceneMgr():getEntity("arena_02"):setQueryFlags(Pixy.GfxEngine.TERRAIN_MASK)
  --Pixy.Log("Arena node is at " .. pos.x .. "," .. pos.y .. "," .. pos.z)

  BBNode = SceneMgr:createSceneNode("EntitySelectionNode")
  BBSet = SceneMgr:createBillboardSet("EntitySelection")
  BBSet:setMaterialName("Elementum/Billboards/EntitySelection")
  BBSet:setDefaultDimensions(1,1)
  BBSet:setBillboardOrigin(Ogre.BBO_CENTER)
  BBSet:setBillboardType(Ogre.BBT_PERPENDICULAR_COMMON)
  BBSet:setBillboardRotationType(Ogre.BBR_VERTEX)
  BBSet:setCommonDirection(Ogre.Vector3:new(0,1,0))
  BBSet:setCommonUpVector(Ogre.Vector3:new(0,0,1))
  BBSet:setRenderQueueGroup(Ogre.RENDER_QUEUE_WORLD_GEOMETRY_1)
  BBSet:setAutoextend(false)
  BB = BBSet:createBillboard(Ogre.Vector3:new(0,0,0))
  BB:setTexcoordRect(0,0,1,1)
  BBNode:attachObject(BBSet)

  Pixy.CUnit:setDefaultWalkSpeed(0.10)
  Pixy.Renderable:setRotationFactor(60.0)
  Pixy.Renderable:setAnimFadeSpeed(30.0)

  -- Lights
  Combat.SetupLights()
end

Combat.SetupScene = function()
end

Combat.cleanup = function()
  GfxEngine:unloadScene(Scene)
end

Combat.SetupLights = function()
  SceneMgr:setAmbientLight(Ogre.ColourValue(150, 150,150))

  fadeColour = Ogre.ColourValue:new(0, 0, 0)
  --SceneMgr:setFog(Ogre.FOG_EXP2, fadeColour, 0.0035)

  _mod = 0.5
  dcol = Ogre.ColourValue:new(_mod,_mod,_mod)
  scol = Ogre.ColourValue:new(_mod,_mod,_mod)

  local pos = Ogre.Vector3:new(Pos.Me.x, Pos.Me.y, Pos.Me.z)
  pos.y = pos.y + 50
--~
  dcol = Ogre.ColourValue:new(100,100,100)
  scol = Ogre.ColourValue:new(100,100,100)
  light = SceneMgr:createLight()
  light:setType(Ogre.Light.LT_POINT)
  light:setPosition(pos)
  light:setDiffuseColour(dcol)
  light:setSpecularColour(scol)
  light:setPowerScale(1000)

  --~ SceneMgr:setShadowTechnique(Ogre.SHADOWTYPE_STENCIL_ADDITIVE)

  --~ dcol = Ogre.ColourValue:new(0.5,0.5,0.5)
  --~ scol = Ogre.ColourValue:new(0.5,0.5,0.5)
  --~ light = SceneMgr:createLight()
  --~ light:setType(Ogre.Light.LT_DIRECTIONAL)
  --~ light:setDirection(Ogre.Vector3:new(0,-1,-1))
  --~ light:setDiffuseColour(dcol)
  --~ light:setSpecularColour(scol)

  --~ dcol = Ogre.ColourValue:new(0.9,0,0)
  --~ scol = Ogre.ColourValue:new(0.9,0,0)
  --~ light = SceneMgr:createLight()
  --~ light:setType(Ogre.Light.LT_DIRECTIONAL)
  --~ light:setDirection(Ogre.Vector3:new(0,-1,0))
  --~ light:setDiffuseColour(dcol)
  --~ light:setSpecularColour(scol)

end

Combat.GameStarted = function()
	Pixy.Log("Game has started! Pwning time")

  --~ GfxEngine:enableCompositorEffect("Bloom")

	return true
end
