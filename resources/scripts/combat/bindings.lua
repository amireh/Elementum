Combat.bind = function()
  --bind(Pixy.EventUID.Connected, Combat.login)
  --bind(Pixy.EventUID.Login, Combat.on_login)
  --bind("AssignPuppets", Combat.assignPuppets)
  --bind("CreatePuppet", Combat.createPuppet)
  --bind("GameStarted", Combat.gameStarted)
  bind(Pixy.EventUID.EntitySelected, Combat.onEntitySelected)
  bind(Pixy.EventUID.EntityDeselected, Combat.onEntityDeselected)
  bind(Pixy.EventUID.UnitAttacked, UI.onEntityAttacked)
  bind(Pixy.EventUID.EntityDying, Units.onEntityDying)

  bind(Pixy.EventUID.StartTurn, UI.onStartTurn)
  bind(Pixy.EventUID.TurnStarted, UI.onTurnStarted)
  bind(Pixy.EventUID.StartBlockPhase, UI.onStartBlockPhase)

  bind(Pixy.EventUID.InvalidAction, UI.onInvalidAction)
  --~ bind(Pixy.EventUID.Lifetap, Pixy.FX.Combat.onLifetap)
  bind(Pixy.EventUID.Lifetap, UI.onLifetap)
  bind(Pixy.EventUID.Trample, UI.onTrample)
  bind(Pixy.EventUID.FirstStrike, UI.onFirstStrike)

  bind(Pixy.EventUID.EntityStatChanged, UI.onStatChange)
  bind(Pixy.EventUID.UnitMechanicChanged, UI.onMechanicChanged)


  -- updating the player's hand --
  bind(Pixy.EventUID.StartTurn, Hand.Update)
  bind(Pixy.EventUID.TurnStarted, Hand.Update)
  bind(Pixy.EventUID.UpdatePuppet, Hand.Update)
  bind(Pixy.EventUID.EntitySelected, Hand.Update)
  bind(Pixy.EventUID.EntityDeselected, Hand.Update)
  bind(Pixy.EventUID.StartBlockPhase, Hand.Update)

  Input.bindToKeyReleased(OIS.KC_X, Combat.ToggleRTTCompositor)
  Input.bindToKeyReleased(OIS.KC_Z, UI.Toggle)

  cleanup = Combat.cleanup
end
