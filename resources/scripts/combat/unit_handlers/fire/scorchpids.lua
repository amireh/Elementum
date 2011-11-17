Scorchpids = {
  Create = nil,
  RegisterAnimations = nil,
  Mesh = "scorpid-model.mesh",
  MaterialPrefix = "Elementum/Scorchpid"
}

Scorchpids.Create = function(unit, model_name)
  unit:setMesh(Scorchpids.Mesh)
  unit:setMaterial(Scorchpids.MaterialPrefix .. "/" .. model_name)

  rnd = unit
  rnd:setScale(3)

  GfxEngine:attachToScene(rnd)

  Scorchpids.RegisterAnimations(rnd)

  rnd:animateIdle()

  return true
end

Scorchpids.RegisterAnimations = function(renderable)
  renderable:registerAnimationState(Pixy.Animable.ANIM_IDLE,   "Idle_1")
  renderable:registerAnimationState(Pixy.Animable.ANIM_IDLE,   "Idle_2")
  renderable:registerAnimationState(Pixy.Animable.ANIM_WALK,    "Walk")
  renderable:registerAnimationState(Pixy.Animable.ANIM_RUN,     "Walk")
  renderable:registerAnimationState(Pixy.Animable.ANIM_DIE,  "Death_1", false)
  renderable:registerAnimationState(Pixy.Animable.ANIM_DIE,  "Death_2", false)
  renderable:registerAnimationState(Pixy.Animable.ANIM_DIE,  "Death_3", false)
  renderable:registerAnimationState(Pixy.Animable.ANIM_ATTACK, "Attack_1", false)
  renderable:registerAnimationState(Pixy.Animable.ANIM_ATTACK, "Attack_2", false)
  renderable:registerAnimationState(Pixy.Animable.ANIM_ATTACK, "Attack_3", false)
  renderable:registerAnimationState(Pixy.Animable.ANIM_HIT,    "Hit_1", false)
  renderable:registerAnimationState(Pixy.Animable.ANIM_HIT,    "Hit_2", false)

  -- undefined
  --~ rnd:registerAnimationState(Pixy.Animable.ANIM_LIVE,   "Idle_1")
  --~ rnd:registerAnimationState(Pixy.Animable.ANIM_REST,    "")
  --~ rnd:registerAnimationState(Pixy.Animable.ANIM_GETUP,   "", false)
end

subscribe_unit("Scorchpid Drone", function(inUnit) Scorchpids.Create(inUnit, "Drone") end)
subscribe_unit("Scorchpid Ashcrawler", function(inUnit) Scorchpids.Create(inUnit, "Ashcrawler") end)
subscribe_unit("Scorchpid Lavawalker", function(inUnit) Scorchpids.Create(inUnit, "Lavawalker") end)
subscribe_unit("Scorchpid Magmaburster", function(inUnit) Scorchpids.Create(inUnit, "Magmaburster") end)
