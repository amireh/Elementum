Profiles.NewProfile = UISheet:new("intro/profiles/new_profile.layout")

local isSetup = false
local mProfiles = {}
local Name, Stats = nil
local Listbox = nil
local RaceText = nil
local Namebox = nil
local SelectedRndRnd = nil -- this is used to keep track of the highlighted Knight's renderable object
local Buttons = {
  CreatePuppet = nil,
  Back = nil
}

local Races = {
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

local updateRaceText = function()
  if (SelectedRnd == nil) then return false end
  local race = SelectedRnd:getRace()

  -- display the race description
  RaceText:setText(Races[raceToString(race)])

  -- if it's earth or fire, enable the play button
  if (race == Pixy.EARTH or race == Pixy.FIRE) then
    Buttons.CreatePuppet:enable()
  else
    Buttons.CreatePuppet:disable()
  end
end

local onEntitySelected = function(e)
  rnd = tolua.cast(e.Any, "Pixy::Renderable")
  SelectedRnd = rnd

  updateRaceText()
  Fx.highlight(rnd)

  return true
end

local onCreatePuppet = function(e)
  if e.Feedback == Pixy.EventFeedback.Ok then
    UISheet.hideDialog()
    Profiles.detach()
    Profiles.Listing:attach()
  else
    UISheet.showDialog("Unable to create character.")
  end

  return true
end

function Profiles.NewProfile:attach()
  UISheet.attach(self)
  --~ Profiles.Layout = Pixy.UI.attach("intro/profiles.layout")
  RaceText = CEWindowMgr:getWindow("Intro/NewPuppet/Text/RaceDescription")
  Buttons.CreatePuppet = CEWindowMgr:getWindow("Intro/NewPuppet/Buttons/CreatePuppet")
  Buttons.Back = CEWindowMgr:getWindow("Intro/NewPuppet/Buttons/BackToListing")
  Namebox = CEGUI.toEditbox(CEWindowMgr:getWindow("Intro/NewPuppet/Editboxes/Name"))

  Profiles.CurrentScreen = "New"
  Pixy.Log("Attaching Profiles[NewProfile]")

  bind(Pixy.EventUID.EntitySelected, onEntitySelected)
  bind(Pixy.EventUID.CreatePuppet, onCreatePuppet)

  local scale, ar = Profiles.CalcScale(4)

  -- prepare the scene
  -- hide the gremlins
  MainMenu.hideGremlins()
  do
    -- set the scale of all knights
    Profiles.Knights.Earth:getSceneNode():setScale(scale)
    Profiles.Knights.Air:getSceneNode():setScale(scale)
    Profiles.Knights.Fire:getSceneNode():setScale(scale)
    Profiles.Knights.Water:getSceneNode():setScale(scale)
  end

  do
    -- set the position of all knights
    local pos =
    Profiles.Knights.Earth:getSceneNode():setPosition(Ogre.Vector3(-14 * ar,0,3 * ar))
    Profiles.Knights.Water:getSceneNode():setPosition(Ogre.Vector3(-8 * ar,0,-20))
    Profiles.Knights.Air:getSceneNode():setPosition(Ogre.Vector3(0,0,-20))
    Profiles.Knights.Fire:getSceneNode():setPosition(Ogre.Vector3(4 * ar,0,3 * ar))
  end

  do
    -- rotate the ones on the edges to give them a look of standing in a semi-circle
    Profiles.Knights.Fire:getSceneNode():lookAt(Ogre.Vector3(9 * ar, 0, -10), Ogre.Node.TS_WORLD)
    Profiles.Knights.Earth:getSceneNode():lookAt(Ogre.Vector3(-26 * ar, 0, -10), Ogre.Node.TS_WORLD)
    Profiles.Knights.Air:getSceneNode():lookAt(Ogre.Vector3(0, 0, -100), Ogre.Node.TS_WORLD)
    Profiles.Knights.Water:getSceneNode():lookAt(Ogre.Vector3(0, 0, -100), Ogre.Node.TS_WORLD)
  end

  do
    -- set up the camera
    --~ GfxEngine:trackNode(fire_knight:getSceneNode())
    --~ GfxEngine:trackNode(nil)
    --~ GfxEngine:setYawPitchDist(Ogre.Vector3(-30, 0, 0))
    GfxEngine:getCameraMan():setStyle(OgreBites.CS_FREELOOK)
    GfxEngine:getCamera():setPosition(Ogre.Vector3(-6 * ar, 3 * ar, 29 * ar))
    --~ GfxEngine:getCamera():yaw(Ogre.Radian(-30))
    GfxEngine:getCamera():lookAt(Ogre.Vector3(-4 * ar ,6 * ar ,-58 * ar))
  end

  Profiles.ShowKnights()

  Input.KeyRelease.bind(OIS.KC_ESCAPE, Profiles.NewProfile.Back)

	if isSetup then return true end
end

function Profiles.NewProfile:detach()
  UISheet.detach(self)

  Input.KeyRelease.bind(OIS.KC_ESCAPE, Profiles.NewProfile.Back)

  unbind(Pixy.EventUID.EntitySelected, onEntitySelected)
  unbind(Pixy.EventUID.CreatePuppet, onCreatePuppet)

  Pixy.Log("Detaching Profiles[NewProfile]")

  MainMenu.showGremlins()

  Buttons = {}
  RaceText = nil
end

Profiles.NewProfile.Back = function()
  Profiles.detach()
  Profiles.Listing:attach()
end

local valid = function(name)
  if name:len() <= 3 then return false end

  return true
end
Profiles.NewProfile.CreatePuppet = function()
  if not SelectedRnd then return false end

  local name = capitalize(string.lower(Namebox:getText()))
  if not valid(name) then return false end

  local e = Pixy.Event(Pixy.EventUID.CreatePuppet)
  e:setProperty("Name", name)
  e:setProperty("Race", raceToString(SelectedRnd:getRace()))
  NetMgr:send(e)

  UISheet.showDialog("Creating character...")
end

