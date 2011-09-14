Skeletons = {
  Create = nil,
  RegisterAnimations = nil,
  MaterialPrefix = "Elementum/Skeleton"
}

Skeletons.CreatePeasant = function(unit)
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

  Skeletons.Create(unit, "skeleton_peasant01.mesh", "Footsoldier", 5)
  local rnd = unit:getRenderable()
  --~ rnd:getSceneNode():setScale(20)
  local scythe = rnd:attachExtension("scythe.mesh", "Bip01 R Hand")
  scythe:setMaterialName("sk_mat#07")

  return true
end

Skeletons.Create = function(unit, mesh, model_name, scale)
  unit:setMesh(mesh)
  unit:setMaterial(Skeletons.MaterialPrefix .. "/" .. model_name)

  rnd = unit:getRenderable()
  rnd:setScale(scale)

  GfxEngine:attachToScene(rnd)

  Skeletons.RegisterAnimations(rnd)

  rnd:animateIdle()

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

subscribe_unit("Skeleton Footsoldier",
  function(inUnit)
    return Skeletons.CreatePeasant(inUnit)
  end)

subscribe_unit("Skeleton Mage",
  function(inUnit)
    return Skeletons.Create(inUnit, "skeleton.mesh", "Mage", 9)
  end)
subscribe_unit("Skeleton Acolyte",
  function(inUnit)
    return Skeletons.Create(inUnit, "skeleton_pirate.mesh", "Acolyte", 7.5)
  end)
subscribe_unit("Skeleton Warrior",
  function(inUnit)
    return Skeletons.Create(inUnit, "SkeletonWarrior.mesh", "Warrior", 9)
  end)
