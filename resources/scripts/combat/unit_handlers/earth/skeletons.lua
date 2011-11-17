Skeletons = {
  Create = nil,
  RegisterAnimations = nil,
  MaterialPrefix = "Elementum/Skeleton"
}

Skeletons.Create = function(unit, mesh, model_name, scale)
  unit:setMesh(mesh)
  unit:setMaterial(Skeletons.MaterialPrefix .. "/" .. model_name)

  GfxEngine:attachToScene(unit)
  unit:getSceneNode():setScale(Ogre.Vector3(scale, scale, scale))

  Skeletons.RegisterAnimations(unit)

  unit:animateIdle()
  unit:animateGetUp()
  unit:animateAttack()

  return true
end

Skeletons.CreateSoldier = function(unit)
  --~ GfxEngine:loadScene("SkeletonPeasant.scene")
  --~ local SceneMgr = GfxEngine:getSceneMgr()
--~
  --~ rnd = unit
  --~ rnd:attachSceneNode(SceneMgr:getSceneNode("skeleton_peasant01"))
  --~ rnd:attachSceneObject(tolua.cast(rnd:getSceneNode():getAttachedObject("skeleton_peasant01"), "Ogre::Entity"))
  --~ rnd:getSceneNode():setScale(Ogre.Vector3(10))
--~
  --~ GfxEngine:attachToScene(rnd)
--~
  --~ Skeletons.RegisterAnimations(rnd)
--~
  --~ rnd:animateIdle()

  if false then
  Skeletons.Create(unit, "skeleton_peasant01.mesh", "Soldier", 11)
  --~ rnd:getSceneNode():setScale(20)
  local scythe = unit:attachExtension("scythe.mesh", "Bip01 R Hand")
  scythe:setMaterialName("sk_mat#07")
  end

  do
    unit:setMesh("mech2.mesh")
    unit:setMaterial("Elementum/Mech1")

    GfxEngine:attachToScene(unit)
    unit:getSceneNode():setScale(Ogre.Vector3(3,3,3))

    local gun1 = unit:attachExtension("gun1.mesh", "Bip01 R Finger0")
    gun1:setMaterialName("Elementum/Mech/Gun1")

    local gun2 = unit:attachExtension("gun2.mesh", "Bip01 L Finger0")
    gun2:setMaterialName("Elementum/Mech/Gun1")

    unit:registerAnimationState(Pixy.Animable.ANIM_IDLE,   "idle2")
    unit:animateIdle()
  end

  return true
end

local grant_lifetap = function(unit)
  if unit:getOwner():getRace() == Pixy.Race.Earth
    and unit:getOwner():hasUnitWithName("Skeleton Warlord")
    and not unit:hasLifetap() then
    unit:setHasLifetap(true)
  end
end

Skeletons.CreateWarlord = function(inUnit)
  Skeletons.Create(inUnit, "SkeletonWarrior.mesh", "Warlord", 9)

  -- Warlord grants Lifetap to all ally skeletons
  local exporter = Pixy.UnitListExporter()
  exporter:export(inUnit:getOwner():getUnits(), "Pixy::Unit", "Temp")
  for unit in list_iter(Temp) do
    print("Lua: granting Lifetap to " .. unit:getName())
    unit:setHasLifetap(true)
  end
  Temp = nil

  subscribe_generic_unit_handler("Alive", grant_lifetap)

  return true
end

Skeletons.RegisterAnimations = function(renderable)
  renderable:registerAnimationState(Pixy.Animable.ANIM_IDLE,   "Idle_1")
  renderable:registerAnimationState(Pixy.Animable.ANIM_IDLE,   "Idle_2")
  renderable:registerAnimationState(Pixy.Animable.ANIM_IDLE,   "Idle_3")
  renderable:registerAnimationState(Pixy.Animable.ANIM_WALK,    "Walk_1")
  renderable:registerAnimationState(Pixy.Animable.ANIM_WALK,    "Walk_2")
  renderable:registerAnimationState(Pixy.Animable.ANIM_RUN,     "Run_1")
  renderable:registerAnimationState(Pixy.Animable.ANIM_RUN,     "Run_2")
  renderable:registerAnimationState(Pixy.Animable.ANIM_DIE,     "Death_1", false)
  renderable:registerAnimationState(Pixy.Animable.ANIM_DIE,     "Death_2", false)
  renderable:registerAnimationState(Pixy.Animable.ANIM_ATTACK,  "Attack_1", false)
  renderable:registerAnimationState(Pixy.Animable.ANIM_ATTACK,  "Attack_2", false)
  renderable:registerAnimationState(Pixy.Animable.ANIM_ATTACK,  "Attack_3", false)
  renderable:registerAnimationState(Pixy.Animable.ANIM_REST,    "Rest")
  renderable:registerAnimationState(Pixy.Animable.ANIM_GETUP,   "Jump", false)

  -- undefined
  --~ rnd:registerAnimationState(Pixy.Animable.ANIM_LIVE,   "Idle_1")
  --~ renderable:registerAnimationState(Pixy.Animable.ANIM_HIT,    "Hit_1", false)
  --~ renderable:registerAnimationState(Pixy.Animable.ANIM_HIT,    "Hit_2", false)
end

subscribe_unit("Skeleton Soldier",
  function(inUnit)
    return Skeletons.CreateSoldier(inUnit)
  end)

subscribe_unit("Skeleton Ravager",
  function(inUnit)
    return Skeletons.Create(inUnit, "skeleton.mesh", "Ravager", 18)
  end)
subscribe_unit("Skeleton Acolyte",
  function(inUnit)
    return Skeletons.Create(inUnit, "skeleton_pirate.mesh", "Acolyte", 7.5)
  end)
subscribe_unit("Skeleton Warlord",
  function(inUnit)
    return Skeletons.CreateWarlord(inUnit)
  end)
