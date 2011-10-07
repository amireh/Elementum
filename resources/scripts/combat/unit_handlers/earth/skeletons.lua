Skeletons = {
  Create = nil,
  RegisterAnimations = nil,
  MaterialPrefix = "Elementum/Skeleton"
}

Skeletons.Create = function(unit, mesh, model_name, scale)
  unit:setMesh(mesh)
  unit:setMaterial(Skeletons.MaterialPrefix .. "/" .. model_name)

  rnd = unit:getRenderable()
  rnd:setScale(scale)

  GfxEngine:attachToScene(rnd)

  Skeletons.RegisterAnimations(rnd)

  rnd:animateIdle()
  rnd:animateGetUp()
  rnd:animateAttack()

  return true
end

Skeletons.CreateSoldier = function(unit)
  --~ GfxEngine:loadScene("SkeletonPeasant.scene")
  --~ local SceneMgr = GfxEngine:getSceneMgr()
--~
  --~ rnd = unit:getRenderable()
  --~ rnd:attachSceneNode(SceneMgr:getSceneNode("skeleton_peasant01"))
  --~ rnd:attachSceneObject(tolua.cast(rnd:getSceneNode():getAttachedObject("skeleton_peasant01"), "Ogre::Entity"))
  --~ rnd:getSceneNode():setScale(Ogre.Vector3(10))
--~
  --~ GfxEngine:attachToScene(rnd)
--~
  --~ Skeletons.RegisterAnimations(rnd)
--~
  --~ rnd:animateIdle()

  Skeletons.Create(unit, "skeleton_peasant01.mesh", "Soldier", 11)
  local rnd = unit:getRenderable()
  --~ rnd:getSceneNode():setScale(20)
  local scythe = rnd:attachExtension("scythe.mesh", "Bip01 R Hand")
  scythe:setMaterialName("sk_mat#07")

  return true
end

local grant_lifetap = function(unit)
  if not unit:hasLifetap() then unit:setHasLifetap(true) end
end

Skeletons.CreateWarlord = function(inUnit)
  Skeletons.Create(inUnit, "SkeletonWarrior.mesh", "Warlord", 9)

  -- Warlord grants Lifetap to all ally skeletons
  local exporter = Pixy.CUnitListExporter()
  exporter:export(inUnit:getOwner():getUnits(), "Pixy::CUnit", "Temp")
  for unit in list_iter(Temp) do
    print("Lua: granting Lifetap to " .. unit:getName())
    unit:setHasLifetap(true)
  end
  Temp = nil

  subscribe_generic_unit_handler("Alive", grant_lifetap)

  return true
end

Skeletons.RegisterAnimations = function(renderable)
  renderable:registerAnimationState(Pixy.Renderable.ANIM_IDLE,   "Idle_1")
  renderable:registerAnimationState(Pixy.Renderable.ANIM_IDLE,   "Idle_2")
  renderable:registerAnimationState(Pixy.Renderable.ANIM_IDLE,   "Idle_3")
  renderable:registerAnimationState(Pixy.Renderable.ANIM_WALK,    "Walk_1")
  renderable:registerAnimationState(Pixy.Renderable.ANIM_WALK,    "Walk_2")
  renderable:registerAnimationState(Pixy.Renderable.ANIM_RUN,     "Run_1")
  renderable:registerAnimationState(Pixy.Renderable.ANIM_RUN,     "Run_2")
  renderable:registerAnimationState(Pixy.Renderable.ANIM_DIE,     "Death_1", false)
  renderable:registerAnimationState(Pixy.Renderable.ANIM_DIE,     "Death_2", false)
  renderable:registerAnimationState(Pixy.Renderable.ANIM_ATTACK,  "Attack_1", false)
  renderable:registerAnimationState(Pixy.Renderable.ANIM_ATTACK,  "Attack_2", false)
  renderable:registerAnimationState(Pixy.Renderable.ANIM_ATTACK,  "Attack_3", false)
  renderable:registerAnimationState(Pixy.Renderable.ANIM_REST,    "Rest")
  renderable:registerAnimationState(Pixy.Renderable.ANIM_GETUP,   "Jump", false)

  -- undefined
  --~ rnd:registerAnimationState(Pixy.Renderable.ANIM_LIVE,   "Idle_1")
  --~ renderable:registerAnimationState(Pixy.Renderable.ANIM_HIT,    "Hit_1", false)
  --~ renderable:registerAnimationState(Pixy.Renderable.ANIM_HIT,    "Hit_2", false)
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
