-- UISheet : Profiles

--require("pixy")
require("helpers")
Profiles = {}
Profiles.New = {}

local isSetup = nil
local mProfiles = {}
local Name, Stats = nil
local Listbox = nil
local RaceText = nil

local Buttons = {
  JoinLobby = nil,
  Back = nil
}

Races = {
  Earth =
"With dirt, stone, and bone, the followers of the call of Nature have risen." ..
" Bound to the ground for millenias, Earthens have mastered matters of" ..
" Life and Death.\
 \
Preserving life, or reanimating it, the followers" ..
" of the Earth dominion are" ..
" bound to surpass their foes."
, Fire =
"Fire shizzle, fingers burned etc.",
  Water =
"In calamity there's also peace, at least that's what the Water guys believe.\
 \
Water is definitely every gay gentleman's choice.",
  Air = "Unavailable."
}
require("intro/profiles/new_info")

Selected = nil

local UID = 100
Profiles.CreateKnight = function(material, scale, pos)
    UID = UID+1

    local unit = Pixy.CUnit()
    unit:setRank(Pixy.PUPPET)
    unit:setName("Knight_" .. material)
    unit:setUID(UID)
    unit:live()
    unit:setMesh("DarkKnight.mesh")
    unit:setMaterial("Elementum/DarkKnight/" .. material)

    rnd = unit:getRenderable()

    local node = SceneMgr:createSceneNode("knight_node_" .. material)
    SceneMgr:getRootSceneNode():addChild(node)
    local ent = SceneMgr:createEntity("Knight_" .. material, unit:getMesh());
    ent:setMaterialName(unit:getMaterial())
    ent:setCastShadows(true)
    ent:setQueryFlags(Pixy.GfxEngine.ENTITY_MASK)
    node:attachObject(ent)
    node:setScale(scale)
    node:setPosition(pos)
    node:lookAt(Ogre.Vector3(0,0,-100),Ogre.Node.TS_WORLD)
    rnd:attachSceneObject(ent)
    rnd:attachSceneNode(node)
    rnd:setup(SceneMgr)

    GfxEngine:attachToScene(rnd)
    local sword = nil
    if (material ~= "Water" and material ~= "Air") then
      --~ sword = rnd:attachExtension("DarkKnightSword.mesh", "Bone01")
      --~ sword:setMaterialName("Elementum/DarkKnight/" .. material .. "/Sword")
      rnd:registerAnimationState(Pixy.Renderable.ANIM_IDLE, "Idle_1")
    end
    if (material == "Water") then
      rnd:registerAnimationState(Pixy.Renderable.ANIM_IDLE, "Idle_2")

    end
    if (material == "Air") then
      rnd:registerAnimationState(Pixy.Renderable.ANIM_IDLE, "Idle_1")
    end


    --~ rnd:registerAnimationState(Pixy.Renderable.ANIM_DIE, "Death_1", false)
    --~ rnd:registerAnimationState(Pixy.Renderable.ANIM_DIE, "Death_2", false)
    rnd:animateIdle()

    table.insert(Units, unit)

  return unit
end

Profiles.onEntitySelected = function(e)
  rnd = tolua.cast(e.Any, "Pixy::Renderable")
  Selected = rnd

  Profiles.updateRaceText()
  FxEngine:highlight(rnd)
end

Profiles.onEntityDeselected = function(e)
  FxEngine:dehighlight()
end

-- ************************
-- ** Profiles Listing
-- ************************
Profiles.attach = function()
	Layout = Pixy.UI.attach("intro/profiles.layout")
  RaceText = CEWindowMgr:getWindow("Elementum/Intro/Text/RaceDescription")
  Buttons.JoinLobby = CEWindowMgr:getWindow("Elementum/Intro/Buttons/JoinLobby")
  Buttons.Back = CEWindowMgr:getWindow("Elementum/Intro/Buttons/BackToLogin")

	if isSetup then return true end

  unit = next(Units)
  Units[unit]:die()

  local ar_orig = 1600 / 900
  local sf = 4
  local scale = Ogre.Vector3(sf)
  -- find the aspect ratio and calculate the scale based on that
  local vw = GfxEngine:getViewport():getActualWidth()
  local vh = GfxEngine:getViewport():getActualHeight()
  local ar = vw / vh
  if ar < ar_orig then
    sf = sf / ar
    scale = Ogre.Vector3(sf)
  end

  earth_knight = Profiles.CreateKnight("Earth", scale, Ogre.Vector3:new(-14 * ar,0,3 * ar))
  earth_knight:setRace(Pixy.EARTH)
  water_knight = Profiles.CreateKnight("Water", scale, Ogre.Vector3:new(-8 * ar,0,0))
  water_knight:setRace(Pixy.WATER)
  air_knight = Profiles.CreateKnight("Air", scale, Ogre.Vector3:new(0,0,0))
  air_knight:setRace(Pixy.AIR)
  fire_knight = Profiles.CreateKnight("Fire", scale, Ogre.Vector3:new(6 * ar,0,3 * ar))
  fire_knight:setRace(Pixy.FIRE)

  fire_knight:getRenderable():getSceneNode():yaw(Ogre.Degree(-26 * ar))
  earth_knight:getRenderable():getSceneNode():yaw(Ogre.Degree(26 * ar))
  air_knight:getRenderable():getSceneNode():yaw(Ogre.Degree(-6 * ar))

  --~ GfxEngine:trackNode(fire_knight:getRenderable():getSceneNode())
  --~ GfxEngine:trackNode(nil)
  --~ GfxEngine:setYawPitchDist(Ogre.Vector3:new(-30, 0, 0))
  GfxEngine:getCameraMan():setStyle(OgreBites.CS_FREELOOK)
  GfxEngine:getCamera():setPosition(Ogre.Vector3(-6 * ar, 3 * ar, 29 * ar))
  --~ GfxEngine:getCamera():yaw(Ogre.Radian(-30))
  GfxEngine:getCamera():lookAt(Ogre.Vector3(-4 * ar ,6 * ar ,-58 * ar))

	isSetup = true
end

Profiles.detach = function()
end

Profiles.Back = function()

  NetMgr:disconnect()
	--[[
  local mEvt = Pixy.Event(Pixy.EventUID.Logout)
	NetMgr:send(mEvt)
	mEvt = nil
  ]]

	Profiles.detach()
	MainMenu.attach()
end

Profiles.JoinLobby = function()

	--~ local evt = Pixy.Event(Pixy.EventUID.JoinQueue)
  --~ evt:setProperty("Puppet", "Kandie")
	--~ NetMgr:send(evt)

	-- wait for feedback
	--Pixy.UI.waiting("Looking for an opponent", Layout)
	Buttons.JoinLobby:disable()

  FxEngine:dehighlight()

  for unit in list_iter(Units) do
    --~ unit:die()
    --~ GfxEngine:detachFromScene(unit:getRenderable())
  end

  MainMenu.cleanup()
  GameMgr:changeState(Pixy.Lobby:getSingletonPtr())

  --~ GameMgr:changeState(Lobby)
  --~ ScriptEngine:callMeAfter(1, "doJoinLobby")
end

Pixy.Combat.doJoinLobby = function()
  for unit in list_iter(Units) do
    --~ unit:die()
    --~ unit:delete()
  end
end

Profiles.updateRaceText = function()
  if (Selected == nil) then return false end
  local race = Selected:getEntity():getRace()

  -- display the race description
  RaceText:setText(Races[raceToString(race)])

  -- if it's earth or fire, enable the play button
  if (race == Pixy.EARTH or race == Pixy.FIRE) then
    Buttons.JoinLobby:enable()
  else
    Buttons.JoinLobby:disable()
  end
end
