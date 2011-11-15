local PSS = 6 -- Puppet selection billboard scale
local OriginalDim = { Width = 1, Height = 1 }
local PuppetDim = {
  Width = OriginalDim.Width * PSS,
  Height = OriginalDim.Height * PSS
}
local rotateBillboard = function(dt)
  BBNode:yaw(Ogre.Degree(0.1 * dt))
end
local doNothing = function(dt) end
local updater = doNothing

local Pos = { Me = nil, Enemy = nil }

if not Gfx then Gfx = {} end

Gfx.PrepareScene = function()
  Pixy.Log("Preparing the Combat scene")

  Selected = nil
  SelectedIsFriendly = nil

  -- Camera
  Camera:setAspectRatio(Viewport:getActualWidth() / Viewport:getActualHeight())
  Camera:setNearClipDistance( 10 )
  Camera:setFarClipDistance( 10000 )

  CameraMan:setTarget(nil)
  CameraMan:setStyle(OgreBites.CS_ORBIT)
  GfxEngine:setYawPitchDist( Defaults.CameraYawPitchDist )

  -- Movable Text Overlay attributes
  GfxEngine.mMTOFontColor = Defaults.MTO.Colour
  GfxEngine.mMTOFontName = Defaults.MTO.Font
  GfxEngine.mMTOFontSize = Defaults.MTO.Size
  GfxEngine.mMTOMaterialName = Defaults.MTO.Material
  GfxEngine:setupMovableTextOverlays()

  -- Hero nodes stuff
  GfxEngine.mPuppetPos[0] = Ogre.Vector3(0,0, -Defaults.PuppetMarginZ)
  GfxEngine.mPuppetPos[1] = Ogre.Vector3(0,0, Defaults.PuppetMarginZ)
  GfxEngine.mPuppetScale = Defaults.PuppetScale
  GfxEngine.mUnitScale = Defaults.UnitScale
  Pos.Me = GfxEngine.mPuppetPos[0]
  Pos.Enemy = GfxEngine.mPuppetPos[1]

  GfxEngine.mUnitMargin.x = Defaults.UnitMarginX
  GfxEngine.mUnitMargin.z = Defaults.UnitMarginZ
  --GfxEngine.mPuppetMargin.x = 10 -- how far units are from the puppet on the X axis
  GfxEngine.mPuppetMargin.z = Defaults.PuppetMarginZ
  GfxEngine.mPackSpacing = Defaults.PackSpacing

  Pixy.Mobile:setDefaultWalkSpeed(Defaults.UnitWalkSpeed)
  Pixy.Mobile:setRotationFactor(Defaults.UnitRotSpeed)
  Pixy.Animable:setAnimFadeSpeed(Defaults.AnimFadeSpeed)

  -- Viewport
  Viewport:setBackgroundColour(Ogre.ColourValue(0,0,0))

  -- Sky
  --SceneMgr:setSkyDome(true, "Elementum/Sky", 1, 1,1000,true);
  --SceneMgr:setSkyBox(true, "Elementum/Sky", 5000, true);
  --~ GfxEngine:createSphere("MySkyDome", 500, 64, 64)
  --~ sphereEntity = SceneMgr:createEntity("MySkyDomeEntity", "MySkyDome")
  --~ sphereNode = SceneMgr:getRootSceneNode():createChildSceneNode()
  --~ sphereEntity:setMaterialName("Elementum/Sky")
  --~ sphereEntity:setRenderQueueGroup( Ogre.RENDER_QUEUE_BACKGROUND );
  --~ sphereNode:attachObject(sphereEntity)

  --~ GfxEngine:loadDotScene("Elementum.scene", "General")
  --~ Scene = GfxEngine:loadScene("DarkMansion.scene")

  -- TODO: fix OgreMaxScene's unloading module because as it is now, the scene
  -- can not be recreated after destruction!!
  if not Scene then
    Scene = GfxEngine:loadScene("MoltenChasm.scene")
    SceneRoot = SceneMgr:getSceneNode("Scene")
    -- loop through all the scene's Entities and set their RenderQueueGroup to background
    do
      local root_node = SceneRoot
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
  else
    SceneMgr:getRootSceneNode():addChild(SceneRoot)
    --~ SceneRoot:setVisible(true)
  end

  -- Selection billboard
  do
    BBNode = SceneMgr:createSceneNode("EntitySelectionNode")
    BBSet = SceneMgr:createBillboardSet("EntitySelection")
    BBSet:setMaterialName("Elementum/Billboards/EntitySelection")
    BBSet:setDefaultDimensions(1,1)
    BBSet:setBillboardOrigin(Ogre.BBO_CENTER)
    BBSet:setBillboardType(Ogre.BBT_PERPENDICULAR_COMMON)
    BBSet:setBillboardRotationType(Ogre.BBR_VERTEX)
    BBSet:setCommonDirection(Ogre.Vector3(0,1,0))
    BBSet:setCommonUpVector(Ogre.Vector3(0,0,1))
    BBSet:setRenderQueueGroup(Ogre.RENDER_QUEUE_WORLD_GEOMETRY_1)
    BBSet:setAutoextend(false)
    BB = BBSet:createBillboard(Ogre.Vector3(0,0,0))
    BB:setTexcoordRect(0,0,1,1)
    BBNode:attachObject(BBSet)
  end

  -- RTTs
  do
    -- create the RTT cameras
    RTT.Player.Camera = SceneMgr:createCamera("RTT.Player.Camera")
    RTT.Player.Camera:setNearClipDistance( 1 )
    RTT.Player.Camera:setFarClipDistance( 100 )

    RTT.Enemy.Camera = SceneMgr:createCamera("RTT.Enemy.Camera")
    RTT.Enemy.Camera:setNearClipDistance( 1 )
    RTT.Enemy.Camera:setFarClipDistance( 100 )

    -- create the RTT texture (Player's)
    RTT.Player.Texture = Pixy.OgreRTT:new()
    RTT.Player.Texture:setup(SceneMgr, GfxEngine:getWindow(), RTT.Player.Camera)
    RTT.Player.Texture:setCorners(-0.985, -0.40, -0.73, -0.785)
    RTT.Player.Texture:enable()

    -- create the RTT texture (Enemy's)
    RTT.Enemy.Texture = Pixy.OgreRTT:new()
    RTT.Enemy.Texture:setup(SceneMgr, GfxEngine:getWindow(), RTT.Enemy.Camera)
    RTT.Enemy.Texture:setCorners(0.73, -0.40, 0.985, -0.785)
    RTT.Enemy.Texture:enable()
  end

  -- Lights
  Gfx.SetupLights()
end

Gfx.SetupLights = function()
  SceneMgr:setAmbientLight(Ogre.ColourValue(0.1,0.1,0.1))
  --~ SceneMgr:setShadowTechnique(Ogre.SHADOWTYPE_STENCIL_ADDITIVE)
  --~ SceneMgr:setShadowColour(Ogre.ColourValue(255, 0, 0))

  if Defaults.Fog.Enabled then
    SceneMgr:setFog(Ogre.FOG_EXP2, Defaults.Fog.Colour, Defaults.Fog.Distance)
  end

  _mod = 0.5
  dcol = Ogre.ColourValue(_mod,_mod,_mod)
  scol = Ogre.ColourValue(_mod,_mod,_mod)

  local pos = Ogre.Vector3(Pos.Me.x, Pos.Me.y, Pos.Me.z)
  pos.y = pos.y + 50

  --[[dcol = Ogre.ColourValue(1.0,1.0,1.0)
  scol = Ogre.ColourValue(1.0,1.0,1.0)
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
    light:setVisibilityFlags(Pixy.GfxEngine.ENTITY_MASK)

    -- Enemy's army light
    pos = Ogre.Vector3(0, 10, Pos.Enemy.z + 30)
    light = SceneMgr:createLight()
    light:setType(Ogre.Light.LT_POINT)
    light:setPosition(pos)
    light:setDiffuseColour(dcol)
    light:setSpecularColour(scol)
    --~ light:setPowerScale(1000)
    light:setCastShadows(true)
    light:setVisibilityFlags(Pixy.GfxEngine.ENTITY_MASK)
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
    light:setVisibilityFlags(Pixy.GfxEngine.ENTITY_MASK)

    -- Enemy's army light
    pos = Ogre.Vector3(-30, 10, 0)
    light = SceneMgr:createLight()
    light:setType(Ogre.Light.LT_POINT)
    light:setPosition(pos)
    light:setDiffuseColour(dcol)
    light:setSpecularColour(scol)
    --~ light:setPowerScale(1000)
    light:setCastShadows(true)
    light:setVisibilityFlags(Pixy.GfxEngine.ENTITY_MASK)
  end

  --~ dcol = Ogre.ColourValue(1.0,0.5,0.5)
  --~ scol = Ogre.ColourValue(1.0,0.5,0.5)
  --~ light = SceneMgr:createLight()
  --~ light:setType(Ogre.Light.LT_DIRECTIONAL)
  --~ light:setDirection(Ogre.Vector3(0,-1,0))
  --~ light:setDiffuseColour(dcol)
  --~ light:setSpecularColour(scol)
  --~ light:setCastShadows(true)
--~
  --~ dcol = Ogre.ColourValue(0,0,1)
  --~ scol = Ogre.ColourValue(0,0,1)
  --~ light = SceneMgr:createLight()
  --~ light:setType(Ogre.Light.LT_DIRECTIONAL)
  --~ light:setDirection(Ogre.Vector3(0,-1,1))
  --~ light:setDiffuseColour(dcol)
  --~ light:setSpecularColour(scol)
  --~ light:setCastShadows(true)

  --~ dcol = Ogre.ColourValue(0.9,0,0)
  --~ scol = Ogre.ColourValue(0.9,0,0)
  --~ light = SceneMgr:createLight()
  --~ light:setType(Ogre.Light.LT_DIRECTIONAL)
  --~ light:setDirection(Ogre.Vector3(0,-1,0))
  --~ light:setDiffuseColour(dcol)
  --~ light:setSpecularColour(scol)

end

Gfx.cleanup = function()
  Gfx.Dehighlight()
  Selected = nil

  do
    if BBNode:getParentSceneNode() then BBNode:getParentSceneNode():removeChild(BBNode) end
    BBSet:removeBillboard(BB)
    SceneMgr:destroyBillboardSet(BBSet)
    SceneMgr:destroySceneNode(BBNode)
    BB = nil
    BBSet = nil
    BBNode = nil
  end

  -- just hide the Scene's root node
  SceneMgr:getRootSceneNode():removeChild(SceneRoot)
  --~ SceneRoot:setVisible(false)
  --~ GfxEngine:unloadScene(Scene)
  --~ Scene = nil

  --~ assert(not SceneMgr:hasSceneNode("Scene"))
  --~ SceneMgr:destroySceneNode("Scene")

  do
    --~ GfxEngine:detachRTT(RTT.Player.Texture)
    --~ GfxEngine:detachRTT(RTT.Enemy.Texture)
    RTT.Player.Texture:delete()
    RTT.Enemy.Texture:delete()
    SceneMgr:destroyCamera(RTT.Player.Camera)
    SceneMgr:destroyCamera(RTT.Enemy.Camera)

    RTT.Player.Texture = nil
    RTT.Enemy.Texture = nil
    RTT.Player.Camera = nil
    RTT.Enemy.Camera = nil

  end

  SceneMgr:destroyAllLights()
  --~ SceneMgr:destroyAllEntities()
  --~ SceneMgr:destroySceneNode(SceneMgr:getRootSceneNode())
  --~ SceneMgr:clearScene()
end

-- RTT Portraits
Gfx.ShowPortrait = function(target, is_friendly)

  -- Puppet sizes are much bigger than units, so we position the camera accordingly on Y/Z axes
  local is_puppet = target == SelfPuppet or target == EnemyPuppet
  local zpad, ypad = nil
  if is_puppet then
    ypad = function(pos, size) return pos.y + size.y * 0.75 end
    zpad = function(pos, size, sign) return pos.z + 10 * sign end
  else
    ypad = function(pos, size) return pos.y + size.y * 0.5 end
    zpad = function(pos, size, sign) return pos.z + ( (size.z + 5) * sign ) end
  end

  -- we will use both the node's position and the entity's AABB to calculate
  -- the camera's position
  local pos = target:getSceneNode():getPosition()
  local size = target:getSceneObject():getWorldBoundingBox(true):getSize()
  -- DEBUG
  do
    --print("\tSelected Size: " .. size.x .. "," .. size.y .. "," .. size.z)
    --print("\tSelected Position: " .. pos.x .. "," .. pos.y .. "," .. pos.z)
  end

  -- should we position the camera in the negative or positive Z?
  local _sign = 1; if pos.z > 0 then _sign = -1 end

  -- finally, do position the camera
  local selector = nil; if is_friendly then selector = "Player" else selector = "Enemy" end
  RTT[selector].Camera:setPosition(Ogre.Vector3(pos.x, ypad(pos,size), zpad(pos,size,_sign)))
  RTT[selector].Camera:lookAt(pos.x, ypad(pos,size), pos.z  + _sign)
end

Gfx.ShowSelection = function(rnd, is_friendly)
  Gfx.HideSelection()

  print("Selecting entity " .. rnd:getName())

  --~ entity:getSceneNode():attachObject(BBNode)
  rnd:getSceneNode():addChild(BBNode)
  if rnd:isPuppet() then
    BBSet:setDefaultDimensions(PuppetDim.Width, PuppetDim.Height)
  else
    BBSet:setDefaultDimensions(
      OriginalDim.Width,
      OriginalDim.Height)
    --~ BBNode:setScale(entity:getSceneNode():getScale())
  end
  --~ BBNode:setPosition(entity:getSceneNode():getPosition())
  --~ BBNode:setScale(entity:getSceneNode():getScale())

  if is_friendly then
    BBSet:setMaterialName("Elementum/Billboards/EntitySelection")
  else
    BBSet:setMaterialName("Elementum/Billboards/EnemyEntitySelection")
  end

  Pixy.doUpdateMe(rotateBillboard)
end

Gfx.HideSelection = function(rnd)
  if BBNode:getParentSceneNode() then
    BBNode:getParentSceneNode():removeChild(BBNode)
  end
  Pixy.dontUpdateMe(rotateBillboard) -- stop rotating the billboard
end

Gfx.Highlight = function(rnd)
  Selected = rnd

  -- is the entity owned by the player or the enemy?
  SelectedIsFriendly = Selected:getOwner():getUID() == SelfPuppet:getUID()

  Gfx.ShowSelection(Selected, SelectedIsFriendly)
  Gfx.ShowPortrait(Selected, SelectedIsFriendly)
  UI.Highlight(Selected, SelectedIsFriendly)
  Buffs.Show(Selected, SelectedIsFriendly)

  return true
end

Gfx.Dehighlight = function()
  Pixy.dontUpdateMe(rotateBillboard) -- stop rotating the billboard

  --~ Pixy.Log("Deselecting entity")
  if not Selected then return true end
  --if (Selected) then
    Gfx.HideSelection(Selected)
    Gfx.ShowPortrait(Selected:getOwner(), SelectedIsFriendly)
    UI.Highlight(Selected:getOwner(), SelectedIsFriendly)
    if SelectedIsFriendly then
      Buffs.Show(SelfPuppet, true)
    else
      Buffs.Show(EnemyPuppet, false)
    end

  --end

  Selected = nil
  SelectedIsFriendly = nil

  return true
end

Gfx.onEntitySelected = function(inEvt)
  local rnd = inEvt.Any
  rnd = tolua.cast(rnd, "Pixy::Entity")

  return Gfx.Highlight(rnd)
end

Gfx.onEntityDeselected = function()
  return Gfx.Dehighlight()
end

local RTTCompositorEffect = "ASCII"
local RTTCompositorEnabled = false
local RTTCompositorRegistered = false
Gfx.ToggleRTTCompositor = function()
  if not RTTCompositorRegistered then
    CompositorMgr:addCompositor(RTT.Player.Camera:getViewport(), RTTCompositorEffect)
    CompositorMgr:addCompositor(RTT.Enemy.Camera:getViewport(), RTTCompositorEffect)
  end

  RTTCompositorEnabled = not RTTCompositorEnabled
  CompositorMgr:setCompositorEnabled(RTT.Player.Camera:getViewport(), RTTCompositorEffect, RTTCompositorEnabled)
  CompositorMgr:setCompositorEnabled(RTT.Enemy.Camera:getViewport(), RTTCompositorEffect, RTTCompositorEnabled)
end
