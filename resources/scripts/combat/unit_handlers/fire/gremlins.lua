Gremlins = {
  Create = nil,
  RegisterAnimations = nil,
  MaterialPrefix = "Elementum/Gremlin"
}

Gremlins.Create = function(unit, mesh, material, scale)
  unit:setMesh(mesh)
  unit:setMaterial(Gremlins.MaterialPrefix .. "/" .. material)

  rnd = unit:getRenderable()
  if not scale then scale = 20 end
  rnd:setScale(scale)

  GfxEngine:attachToScene(rnd)

  Gremlins.RegisterAnimations(rnd)

  rnd:animateRest()
  rnd:animateAttack()
  rnd:animateAttack()
  --~ rnd:getSceneNode():pitch(Ogre.Degree(-90))
  --~ rnd:getSceneNode():yaw(Ogre.Degree(180))
  --~ rnd:getSceneNode():setOrientation(Ogre.Quaternion:new(0,180,0,0))

  return true
end

Gremlins.RegisterAnimations = function(renderable)
  --rnd:getSceneNode():yaw(Ogre.Degree:new(180))

  rnd:registerAnimationState(Pixy.Renderable.ANIM_IDLE,   "Idle_1")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_IDLE,   "Idle_2")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_IDLE,   "Idle_3")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_WALK,   "Walk_1")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_RUN,    "Run_1")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_RUN,    "Run_2")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_DIE,    "Death_1", false)
  rnd:registerAnimationState(Pixy.Renderable.ANIM_DIE,    "Death_2", false)
  rnd:registerAnimationState(Pixy.Renderable.ANIM_ATTACK, "Attack_1", false)
  rnd:registerAnimationState(Pixy.Renderable.ANIM_ATTACK, "Attack_2", false)
  rnd:registerAnimationState(Pixy.Renderable.ANIM_ATTACK, "Attack_3", false)
  rnd:registerAnimationState(Pixy.Renderable.ANIM_REST,   "Idle_Sitting")
  --~ rnd:registerAnimationState(Pixy.Renderable.ANIM_REST,    "Idle_Sleeping")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_GETUP,   "Jump", false)
  rnd:registerAnimationState(Pixy.Renderable.ANIM_GETUP,   "Jumping_Happy", false)

  -- undefined
  --~ rnd:registerAnimationState(Pixy.Renderable.ANIM_LIVE,   "Idle_1")
  --~ rnd:registerAnimationState(Pixy.Renderable.ANIM_HIT,    "Scared", false)
end

subscribe_unit("Mechanical Gremlin",
  function(inUnit)
    return Gremlins.Create(inUnit, "Gremlin1.mesh", "Mechanical")
  end)

subscribe_unit("Gremlin Brawler",
  function(inUnit)
    return Gremlins.Create(inUnit, "Gremlin2.mesh", "Engineer", 35)
  end)
subscribe_unit("Gremlin Engineer",
  function(inUnit)
    return Gremlins.Create(inUnit, "Gremlin1.mesh", "Brawler", 25)
  end)
subscribe_unit("Master Gremlin",
  function(inUnit)
    return Gremlins.Create(inUnit, "Gremlin3.mesh", "Master", 25)
  end)
