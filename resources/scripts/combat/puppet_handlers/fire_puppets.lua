local create_puppet = function(puppet)
  puppet:setMesh("DarkKnight.mesh")
  puppet:setMaterial("Elementum/DarkKnight/Fire")

  rnd = puppet:getRenderable()
  rnd:setScale(5)
  GfxEngine:attachToScene(rnd)
  --rnd:attachExtension("SkeletonPeasantAxe.mesh", "Bone01")

  rnd:registerAnimationState(Pixy.Renderable.ANIM_IDLE1, "Idle_1")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_IDLE2, "Idle_2")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_WALK, "Walk")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_RUN, "Run")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_DEATH1, "Death_1")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_DEATH2, "Death_2")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_ATTACK1, "Attack_1")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_ATTACK2, "Attack_2")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_HIT1, "Hit_1", false)
  rnd:registerAnimationState(Pixy.Renderable.ANIM_HIT2, "Hit_2", false)

  -- undefined
  rnd:registerAnimationState(Pixy.Renderable.ANIM_REST, "Idle_1")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_GETUP, "Idle_1")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_LIVE1, "Idle_1")
  rnd:registerAnimationState(Pixy.Renderable.ANIM_LIVE2, "Idle_1")

  rnd:animateIdle()
end

subscribe_puppet(Pixy.FIRE, create_puppet)
