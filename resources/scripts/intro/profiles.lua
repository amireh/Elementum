-- UISheet : Profiles

if not Profiles then Profiles = {} end

require("intro/profiles/new_profile")
require("intro/profiles/listing")

Profiles.Knights = { Earth = nil, Air = nil, Water = nil, Fire = nil }
Profiles.CurrentScreen = nil

local UID = 100
Profiles.CreateKnight = function(name, material, scale, pos)
  UID = UID+1

  local unit = Pixy.Unit:new()
  unit:setRank(Pixy.PUPPET)
  unit:setName(name)
  unit:setUID(UID)
  unit:live()
  unit:setMesh("DarkKnight.mesh")
  unit:setMaterial("Elementum/DarkKnight/" .. material)

  rnd = unit

  local node = SceneMgr:createSceneNode("knight_node_" .. material)
  SceneMgr:getRootSceneNode():addChild(node)
  local ent = SceneMgr:createEntity("Knight_" .. material, unit:getMesh());
  ent:setMaterialName(unit:getMaterial())
  ent:setCastShadows(true)
  ent:setQueryFlags(Pixy.GfxEngine.ENTITY_MASK)
  node:attachObject(ent)
  node:setScale(scale)
  node:setPosition(pos)
  --~ node:lookAt(Ogre.Vector3(0,0,-100),Ogre.Node.TS_WORLD)
  rnd:attachSceneObject(ent)
  rnd:attachSceneNode(node)
  rnd:setup(SceneMgr)

  GfxEngine:attachToScene(rnd)
  local sword = nil
  if (material ~= "Water" and material ~= "Air") then
    sword = rnd:attachExtension("DarkKnightSword.mesh", "Bone01")
    sword:setMaterialName("Elementum/DarkKnight/" .. material .. "/Sword")
    rnd:registerAnimationState(Pixy.Animable.ANIM_IDLE, "Idle_1")
  end
  if (material == "Water") then
    rnd:registerAnimationState(Pixy.Animable.ANIM_IDLE, "Idle_2")

  end
  if (material == "Air") then
    rnd:registerAnimationState(Pixy.Animable.ANIM_IDLE, "Idle_1")
  end

  --~ rnd:registerAnimationState(Pixy.Animable.ANIM_DIE, "Death_1", false)
  --~ rnd:registerAnimationState(Pixy.Animable.ANIM_DIE, "Death_2", false)
  rnd:animateIdle()

  --~ table.insert(Units, unit)
  unit:setIsDead(false)

  return unit
end

Profiles.HideKnights = function()
  Profiles.Knights.Earth:hide()
  Profiles.Knights.Air:hide()
  Profiles.Knights.Fire:hide()
  Profiles.Knights.Water:hide()
end

Profiles.ShowKnights = function()
  Profiles.Knights.Earth:show()
  Profiles.Knights.Air:show()
  Profiles.Knights.Fire:show()
  Profiles.Knights.Water:show()
end

Profiles.CalcScale = function(sf)
  local ar_orig = 1600 / 900
  local scale = Ogre.Vector3(sf)

  -- find the aspect ratio and calculate the scale based on that
  local vw = GfxEngine:getViewport():getActualWidth()
  local vh = GfxEngine:getViewport():getActualHeight()
  local ar = vw / vh
  if ar < ar_orig then
    sf = sf / ar
    scale = Ogre.Vector3(sf)
  end

  return scale, ar
end

-- ************************
-- ** Profiles Listing
-- ************************
local isSetup = false
Profiles.attach = function()

  Pixy.Log("Attaching Profiles[]")

  if not isSetup then

    do
      -- create the Knights
      local scale = Ogre.Vector3(1,1,1)
      local pos = Ogre.Vector3(0,0,0)

      Profiles.Knights.Earth = Profiles.CreateKnight("EarthKnight", "Earth", scale, pos)
      Profiles.Knights.Earth:setRace(Pixy.EARTH)

      Profiles.Knights.Water = Profiles.CreateKnight("WaterKnight", "Water", scale, pos)
      Profiles.Knights.Water:setRace(Pixy.WATER)

      Profiles.Knights.Air = Profiles.CreateKnight("AirKnight", "Air", scale, pos)
      Profiles.Knights.Air:setRace(Pixy.AIR)

      Profiles.Knights.Fire = Profiles.CreateKnight("FireKnight", "Fire", scale, pos)
      Profiles.Knights.Fire:setRace(Pixy.FIRE)
    end

    Profiles.HideKnights()
    isSetup = true
  end

  -- if there are any existing chars, go to the character selection screen
  -- otherwise go to the new character screen
  if #Intro.Puppets > 0 then
    Profiles.Listing:attach()
  else
    Profiles.NewProfile:attach()
  end

end

Profiles.detach = function()
  --~ CEWindowMgr:destroyWindow(Profiles.Layout)
  --Profiles.Layout:hide()
  Pixy.Log("Detaching Profiles[]")

  if Profiles.CurrentScreen == "New" then
    Profiles.NewProfile:detach()
  else
    Profiles.Listing:detach()
  end
  --~ Pixy.UI.detach(Profiles.Layout)
end

Profiles.cleanup = function()
  if not isSetup then return true end

  Profiles.NewProfile:detach()
  Profiles.Listing:detach()

  nodes = {
    Profiles.Knights.Earth:getSceneNode():getName(),
    Profiles.Knights.Air:getSceneNode():getName(),
    Profiles.Knights.Fire:getSceneNode():getName(),
    Profiles.Knights.Water:getSceneNode():getName(),
  }

  Profiles.Knights.Earth:delete()
  Profiles.Knights.Air:delete()
  Profiles.Knights.Fire:delete()
  Profiles.Knights.Water:delete()

  -- we must destroy the Knights' scene nodes because GfxEngine does not do that
  for node in list_iter(nodes) do SceneMgr:destroySceneNode(node) end
  nodes = {}

  isSetup = false
end

Profiles.Back = function()

  NetMgr:disconnect()
	--[[
  local mEvt = Pixy.Event(Pixy.EventUID.Logout)
	NetMgr:send(mEvt)
	mEvt = nil
  ]]

	Profiles.detach()
	MainMenu:attach()
end


Profiles.onPuppetListSynced = function(e)
  Intro.Puppets = __PuppetsTemp
  __PuppetsTemp = nil

  print("Puppets are synced!")

  for k,v in ipairs(Intro.Puppets) do
    print("\t" .. k .. " => " .. v:getName())
  end

  MainMenu:detach()
  Profiles.attach()

  return true
end

Profiles.onCreatePuppet = function(e)
  Profiles.detach()
  Profiles.NewProfile:attach()
end


Profiles.JoinLobby = function()

	--~ local evt = Pixy.Event(Pixy.EventUID.JoinQueue)
  --~ evt:setProperty("Puppet", "Kandie")
	--~ NetMgr:send(evt)

	-- wait for feedback
	--Pixy.UI.waiting("Looking for an opponent", Layout)
	--~ Buttons.JoinLobby:disable()
  --~ FxEngine:dehighlight()

  local evt = Pixy.Event(Pixy.EventUID.JoinLobby)
  evt:setProperty("Puppet", Selected:getName())
  NetMgr:send(evt)

  --~ Pixy.Log("Joining the Lobby with " .. IntroState:getPuppetName())
  Pixy.Log("Joining the Lobby with " .. Selected:getName())

  --~ MainMenu.cleanup()
  Profiles.detach()
  --~ require("lobby/entry_point")
  --~ clearBindings()
  --~ Lobby.bind()
  Chat:attach()
  --~ GameMgr:changeState(LobbyState)

  return true
end

Profiles.JoinLobbyWithLastPuppet = function()
  assert(Intro.Puppet)
  Selected = Intro.Puppet
  Profiles.JoinLobby()
end

Profiles.onJoinLobby = function(e)
  if e.Feedback ~= Pixy.EventFeedback.Ok then
    UISheet.showDialog("Unable to connect to lobby. Please try again later.")
    return true
  end

  return true
end
