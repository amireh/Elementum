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

  -- Camera
  Camera:setAspectRatio(Viewport:getActualWidth() / Viewport:getActualHeight())
  Camera:setNearClipDistance( 10 )
  Camera:setFarClipDistance( 10000 )

  GfxEngine:getCameraMan():setTarget(nil)
  GfxEngine:getCameraMan():setStyle(OgreBites.CS_ORBIT)
  GfxEngine:setYawPitchDist( Ogre.Vector3(180, 30, 140) )

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


  --~ GfxEngine.mCameraYawPitchDist = Ogre.Vector3(180, 30, 140)
  --~ GfxEngine:getCameraMan():setStyle(OgreBites.CS_FREELOOK)
  --~ GfxEngine:getCameraMan():setTarget(nil)
  --~ GfxEngine:getCameraMan():setStyle(OgreBites.CS_ORBIT)
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
  --~ Ogre.MeshManager:getSingleton():createPlane(
    --~ "floor", Ogre.ResourceGroupManager.DEFAULT_RESOURCE_GROUP_NAME,
			--~ Ogre.Plane:new(Ogre.Vector3.UNIT_Y, 0), 512, 512, 10, 10, true, 1, 10, 10, Ogre.Vector3.UNIT_Z);
  --~ ent = SceneMgr:createEntity("Floor", "floor");
  --~ ent:setMaterialName("Elementum/Terrain/Floor");
  --~ ent:setCastShadows(true)
  --~ ent:setRenderQueueGroup( Ogre.RENDER_QUEUE_BACKGROUND );
  --~ SceneMgr:getRootSceneNode():attachObject(ent)
  --~ GfxEngine:loadDotScene("Elementum.scene", "General")
  --~ Scene = GfxEngine:loadScene("DarkMansion.scene")
  Scene = GfxEngine:loadScene("MoltenChasm.scene")
  -- loop through all the scene's Entities and set their RenderQueueGroup to background
  do
    local root_node = SceneMgr:getSceneNode("molten_chasm")
    local nr_nodes = root_node:numChildren()
    local idx = 0
    print("Scene has " .. nr_nodes .. " child nodes")
    while idx < nr_nodes do
      -- get this node's entities
      local node = root_node:getChildAt(idx)
      node = tolua.cast(node, "Ogre::SceneNode")
      local nr_entities = node:numAttachedObjects()
      local _idx = 0
      --print("\tNode " .. node:getName() .. " has " .. nr_entities .. " attached objects")
      while _idx < nr_entities do
        node:getAttachedObjectAt(_idx):setRenderQueueGroup(Ogre.RENDER_QUEUE_BACKGROUND)
        _idx = _idx + 1
      end
      idx = idx + 1
    end
  end
  --~ GfxEngine:getSceneMgr():getEntity("arena_02"):setCastShadows(false)
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
  SceneMgr:setAmbientLight(Ogre.ColourValue(0.1,0.1,0.1))
  --~ SceneMgr:setShadowTechnique(Ogre.SHADOWTYPE_STENCIL_ADDITIVE)
  --~ SceneMgr:setShadowColour(Ogre.ColourValue(255, 0, 0))

  fadeColour = Ogre.ColourValue(0, 0, 0, 0.5)
  SceneMgr:setFog(Ogre.FOG_EXP2, fadeColour, 0.0025)

  _mod = 0.5
  dcol = Ogre.ColourValue(_mod,_mod,_mod)
  scol = Ogre.ColourValue(_mod,_mod,_mod)

  local pos = Ogre.Vector3(Pos.Me.x, Pos.Me.y, Pos.Me.z)
  pos.y = pos.y + 50

  --[[dcol = Ogre.ColourValue:new(1.0,1.0,1.0)
  scol = Ogre.ColourValue:new(1.0,1.0,1.0)
  light = SceneMgr:createLight()
  light:setType(Ogre.Light.LT_POINT)
  light:setPosition(pos)
  light:setDiffuseColour(dcol)
  light:setSpecularColour(scol)
  --~ light:setPowerScale(1000)
  light:setCastShadows(true)]]

  -- Middle Spotlight - between the two heroes
  pos = Ogre.Vector3(0,10,0)
  dcol = Ogre.ColourValue(0.9,0.7,0)
  scol = Ogre.ColourValue(0.9,0.7,0)
  light = SceneMgr:createLight()
  light:setType(Ogre.Light.LT_SPOTLIGHT)
  light:setPosition(pos)
  light:setDiffuseColour(dcol)
  light:setSpecularColour(scol)
  light:setDirection(Ogre.Vector3(0,-1,0))
  light:setPowerScale(10000)
  light:setSpotlightRange(Ogre.Radian(1), Ogre.Radian(30), 0.5)
  light:setCastShadows(true)

  -- Players Lights
  do
    -- Player's army light
    dcol = Ogre.ColourValue(0.8,0.8,0.8)
    scol = Ogre.ColourValue(0,0,0)
    pos = Ogre.Vector3(0, 10, Pos.Me.z - 30)
    light = SceneMgr:createLight()
    light:setType(Ogre.Light.LT_POINT)
    light:setPosition(pos)
    light:setDiffuseColour(dcol)
    light:setSpecularColour(scol)
    light:setCastShadows(true)

    -- Enemy's army light
    pos = Ogre.Vector3(0, 10, Pos.Enemy.z + 30)
    light = SceneMgr:createLight()
    light:setType(Ogre.Light.LT_POINT)
    light:setPosition(pos)
    light:setDiffuseColour(dcol)
    light:setSpecularColour(scol)
    --~ light:setPowerScale(1000)
    light:setCastShadows(true)
  end

  -- Side lights
  do
    -- Player's army light
    dcol = Ogre.ColourValue(0.8,0.3,0)
    scol = Ogre.ColourValue(0,0,0)
    pos = Ogre.Vector3(30, 10, 0)
    light = SceneMgr:createLight()
    light:setType(Ogre.Light.LT_POINT)
    light:setPosition(pos)
    light:setDiffuseColour(dcol)
    light:setSpecularColour(scol)
    light:setCastShadows(true)

    -- Enemy's army light
    pos = Ogre.Vector3(-30, 10, 0)
    light = SceneMgr:createLight()
    light:setType(Ogre.Light.LT_POINT)
    light:setPosition(pos)
    light:setDiffuseColour(dcol)
    light:setSpecularColour(scol)
    --~ light:setPowerScale(1000)
    light:setCastShadows(true)
  end

  --~ dcol = Ogre.ColourValue:new(1.0,0.5,0.5)
  --~ scol = Ogre.ColourValue:new(1.0,0.5,0.5)
  --~ light = SceneMgr:createLight()
  --~ light:setType(Ogre.Light.LT_DIRECTIONAL)
  --~ light:setDirection(Ogre.Vector3:new(0,-1,0))
  --~ light:setDiffuseColour(dcol)
  --~ light:setSpecularColour(scol)
  --~ light:setCastShadows(true)
--~
  --~ dcol = Ogre.ColourValue:new(0,0,1)
  --~ scol = Ogre.ColourValue:new(0,0,1)
  --~ light = SceneMgr:createLight()
  --~ light:setType(Ogre.Light.LT_DIRECTIONAL)
  --~ light:setDirection(Ogre.Vector3:new(0,-1,1))
  --~ light:setDiffuseColour(dcol)
  --~ light:setSpecularColour(scol)
  --~ light:setCastShadows(true)

  --~ dcol = Ogre.ColourValue:new(0.9,0,0)
  --~ scol = Ogre.ColourValue:new(0.9,0,0)
  --~ light = SceneMgr:createLight()
  --~ light:setType(Ogre.Light.LT_DIRECTIONAL)
  --~ light:setDirection(Ogre.Vector3:new(0,-1,0))
  --~ light:setDiffuseColour(dcol)
  --~ light:setSpecularColour(scol)

  Pixy.Effects.Configure()
end

Combat.GameStarted = function()
	Pixy.Log("Game has started! Pwning time")

  GfxEngine:getCameraMan():setTarget(SelfPuppet:getRenderable():getSceneNode())
  GfxEngine:setYawPitchDist( Ogre.Vector3(180, 30, 140) )

  --~ GfxEngine:enableCompositorEffect("HDR")

	return true
end
