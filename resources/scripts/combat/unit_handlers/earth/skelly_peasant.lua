local process = function(inUnit)
  inUnit:setMesh("Gremlin1.mesh")
  inUnit:setMaterial("Elementum/Gremlin/Molten")
  inUnit.fRequiresYawFix = true

  rnd = inUnit:getRenderable()
  rnd:setScale(20)

  GfxEngine:attachToScene(rnd)
  --~ rnd:attachExtension("SkeletonWarriorShield.mesh", "Bip01 L Hand")
  --rnd:attachExtension("scythe.mesh", "Bip01 R Hand")

  --rnd:getSceneNode():yaw(Ogre.Degree:new(180))

  rnd:registerAnimationState(Pixy.Renderable.ANIM_IDLE1,   "Idle_1")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_IDLE2,   "Idle_2")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_WALK,    "Walk_1")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_RUN,     "Run_1")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_DEATH1,  "Death_1")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_DEATH2,  "Death_2")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_ATTACK1, "Attack_1")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_ATTACK2, "Attack_2")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_HIT1,    "Scared", false)
  rnd:registerAnimationState(Pixy.Renderable.ANIM_HIT2,    "Scared", false)
  rnd:registerAnimationState(Pixy.Renderable.ANIM_REST,    "Idle_Sitting")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_GETUP,   "Jump")

  -- undefined
  rnd:registerAnimationState(Pixy.Renderable.ANIM_LIVE1,   "Idle_1")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_LIVE2,   "Idle_1")

  rnd:animateRest()
  --~ rnd:getSceneNode():pitch(Ogre.Degree(-90))
  rnd:getSceneNode():yaw(Ogre.Degree(180))
  --~ rnd:getSceneNode():setOrientation(Ogre.Quaternion:new(0,180,0,0))

	return true
end

subscribe_unit("Skelly Peasant", process)
