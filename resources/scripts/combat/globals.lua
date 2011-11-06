Selected = nil
SelectedIsFriendly = nil

BBSet = nil
BB = nil
BBNode = nil
Scene = nil
RTT = {
  Player = {
    Camera = nil,
    Texture = nil
  },
  Enemy = {
    Camera = nil,
    Texture = nil
  }
}

Defaults = {

  CameraYawPitchDist = Ogre.Vector3(180, 30, 140),

  MTO = {
    Colour = Ogre.ColourValue(1,1,1),
    Font = "DejaVuSans",
    Size = 16,
    Material = "RedTransparent"
  },

  Fog = {
    Enabled = true,
    Colour = Ogre.ColourValue(0,0,0,1),
    Distance = 0.0015
  },

  PlayerPosition = Ogre.Vector3(0,0,-35),
  EnemyPosition = Ogre.Vector3(0,0,35),
  PuppetScale = Ogre.Vector3(5,5,5),
  UnitScale = Ogre.Vector3(1,1,1),

  UnitMarginX = 15, -- the distance between every unit on the X axis
  UnitMarginZ = 10, -- the distance between the frontier and rear of the unit packs on the Z axis
  PuppetMarginZ = 35, -- how far puppets are from each other
  PackSpacing = 20, -- how far every unit pack is from the other on the X axis

  UnitWalkSpeed = 0.10,
  UnitRotSpeed = 60,
  AnimFadeSpeed = 30
}
