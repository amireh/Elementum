local create_earth_puppet = function(puppet)
  puppet:setMesh("DarkKnight.mesh")
  puppet:setMaterial("Elementum/DarkKnight/Earth")

  Pixy.Log("Assigned puppet mesh: " .. puppet:getMesh())

  rnd = puppet
  GfxEngine:attachToScene(rnd)
  rnd:getSceneNode():setScale(Ogre.Vector3(5,5,5))
  rnd:getSceneObject():setCastShadows(true)
  --rnd:attachExtension("SkeletonPeasantAxe.mesh", "Bone01")
  local sword = rnd:attachExtension("DarkKnightSword.mesh", "Bone01")
  sword:setMaterialName("Elementum/DarkKnight/Earth/Sword")
  sword:setCastShadows(true)

  rnd:registerAnimationState(Pixy.Animable.ANIM_IDLE, "Idle_1")
  rnd:registerAnimationState(Pixy.Animable.ANIM_IDLE, "Idle_2")
  rnd:registerAnimationState(Pixy.Animable.ANIM_DIE, "Death_1", false)
  rnd:registerAnimationState(Pixy.Animable.ANIM_DIE, "Death_2", false)
  rnd:registerAnimationState(Pixy.Animable.ANIM_HIT, "Hit_1", false)
  rnd:registerAnimationState(Pixy.Animable.ANIM_HIT, "Hit_2", false)
  rnd:registerAnimationState(Pixy.Animable.ANIM_HIT, "Hit_3", false)

  -- undefined
  --~ rnd:registerAnimationState(Pixy.Animable.ANIM_REST, "Idle_1")
  --~ rnd:registerAnimationState(Pixy.Animable.ANIM_GETUP, "Idle_1")
  --~ rnd:registerAnimationState(Pixy.Animable.ANIM_LIVE, "Idle_1")
  --~ rnd:registerAnimationState(Pixy.Animable.ANIM_LIVE, "Idle_1")
  --~ rnd:registerAnimationState(Pixy.Animable.ANIM_ATTACK, "Attack_1")
  --~ rnd:registerAnimationState(Pixy.Animable.ANIM_ATTACK, "Attack_2")
  --~ rnd:registerAnimationState(Pixy.Animable.ANIM_WALK, "Walk")
  --~ rnd:registerAnimationState(Pixy.Animable.ANIM_RUN, "Run")

  rnd:animateIdle()
end

subscribe_puppet(Pixy.Race.Earth, create_earth_puppet)
