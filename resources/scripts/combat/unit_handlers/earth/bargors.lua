Bargors = {
  Create = nil,
  RegisterAnimations = nil,
  Mesh = "Troll.mesh",
  MaterialPrefix = "Elementum/Bargor"
}

Bargors.Create = function(unit, model_name)
  unit:setMesh(Bargors.Mesh)
  unit:setMaterial(Bargors.MaterialPrefix .. "/" .. model_name)

  rnd = unit:getRenderable()
  rnd:setScale(3.5)

  GfxEngine:attachToScene(rnd)

  Bargors.RegisterAnimations(rnd)

  rnd:animateIdle()

  return true
end

Bargors.RegisterAnimations = function(renderable)
  renderable:registerAnimationState(Pixy.Renderable.ANIM_IDLE,   "Idle")
  renderable:registerAnimationState(Pixy.Renderable.ANIM_WALK,    "Walk")
  renderable:registerAnimationState(Pixy.Renderable.ANIM_RUN,     "Run")
  renderable:registerAnimationState(Pixy.Renderable.ANIM_DIE,  "Death_1", false)
  renderable:registerAnimationState(Pixy.Renderable.ANIM_DIE,  "Death_2", false)
  renderable:registerAnimationState(Pixy.Renderable.ANIM_ATTACK, "Attack_1", false)
  renderable:registerAnimationState(Pixy.Renderable.ANIM_ATTACK, "Attack_2", false)

  -- undefined
  --~ rnd:registerAnimationState(Pixy.Renderable.ANIM_LIVE,   "Idle_1")
  --~ rnd:registerAnimationState(Pixy.Renderable.ANIM_REST,    "")
  --~ rnd:registerAnimationState(Pixy.Renderable.ANIM_GETUP,   "", false)
  --~ renderable:registerAnimationState(Pixy.Renderable.ANIM_HIT,    "Hit_1", false)
end

subscribe_unit("Bargor Stomper", function(inUnit) Bargors.Create(inUnit, "Stomper") end)
subscribe_unit("Bargor Pulverizer", function(inUnit) Bargors.Create(inUnit, "Pulverizer") end)
subscribe_unit("Bargor Chieftain", function(inUnit) Bargors.Create(inUnit, "Chieftain") end)
subscribe_unit("Bargor Maimer", function(inUnit) Bargors.Create(inUnit, "Maimer") end)
