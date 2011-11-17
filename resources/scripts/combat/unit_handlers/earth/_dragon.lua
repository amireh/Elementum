--[[
  inUnit:setMesh("Dragon.mesh")
  inUnit:setMaterial("Elementum/Dragon/Bronze")

  rnd = inUnit
  rnd:setScale(0.4)

  GfxEngine:attachToScene(rnd)

  rnd:registerAnimationState(Pixy.Animable.ANIM_IDLE1,   "Idle")
  rnd:registerAnimationState(Pixy.Animable.ANIM_IDLE2,   "Idle")
  rnd:registerAnimationState(Pixy.Animable.ANIM_WALK,    "Walk_1")
  rnd:registerAnimationState(Pixy.Animable.ANIM_RUN,     "Fly_Start")
  rnd:registerAnimationState(Pixy.Animable.ANIM_DEATH1,  "Death_Air_1")
  rnd:registerAnimationState(Pixy.Animable.ANIM_DEATH2,  "Death_Air_2")
  rnd:registerAnimationState(Pixy.Animable.ANIM_ATTACK1, "Attack_1")
  rnd:registerAnimationState(Pixy.Animable.ANIM_ATTACK2, "Attack_2")
  rnd:registerAnimationState(Pixy.Animable.ANIM_HIT1,    "GetHit")
  rnd:registerAnimationState(Pixy.Animable.ANIM_HIT2,    "GetHit")
  rnd:registerAnimationState(Pixy.Animable.ANIM_REST,    "Sleep")
  rnd:registerAnimationState(Pixy.Animable.ANIM_GETUP,   "WakeUp")

  -- undefined
  rnd:registerAnimationState(Pixy.Animable.ANIM_LIVE1,   "WakeUp")
  rnd:registerAnimationState(Pixy.Animable.ANIM_LIVE2,   "WakeUp")

  rnd:animateRest()
]]
