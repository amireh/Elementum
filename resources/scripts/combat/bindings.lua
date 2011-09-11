Combat.bind = function()
  --bind(Pixy.EventUID.Connected, Combat.login)
  --bind(Pixy.EventUID.Login, Combat.on_login)
  --bind("AssignPuppets", Combat.assignPuppets)
  --bind("CreatePuppet", Combat.createPuppet)
  --bind("GameStarted", Combat.gameStarted)
  bind(Pixy.EventUID.EntitySelected, Combat.onEntitySelected)
  bind(Pixy.EventUID.EntityDeselected, Combat.onEntityDeselected)
  bind(Pixy.EventUID.EntityAttacked, Pixy.UI.Combat.onEntityAttacked)

  bind(Pixy.EventUID.StartTurn, Pixy.UI.Combat.onStartTurn)
  bind(Pixy.EventUID.TurnStarted, Pixy.UI.Combat.onTurnStarted)
  bind(Pixy.EventUID.StartBlockPhase, Pixy.UI.Combat.onStartBlockPhase)

  bind(Pixy.EventUID.InvalidAction, Pixy.UI.Combat.onInvalidAction)
  bind(Pixy.EventUID.Lifetap, Pixy.FX.Combat.onLifetap)
  bind(Pixy.EventUID.Lifetap, Pixy.UI.Combat.onLifetap)
  bind(Pixy.EventUID.Trample, Pixy.UI.Combat.onTrample)
  bind(Pixy.EventUID.FirstStrike, Pixy.UI.Combat.onFirstStrike)

  bind(Pixy.EventUID.EntityStatChanged, Pixy.UI.Combat.onStatChange)


  -- updating the player's hand --
  bind(Pixy.EventUID.StartTurn, Pixy.UI.Combat.updateHand)
  bind(Pixy.EventUID.TurnStarted, Pixy.UI.Combat.updateHand)
  bind(Pixy.EventUID.UpdatePuppet, Pixy.UI.Combat.updateHand)
  bind(Pixy.EventUID.EntitySelected, Pixy.UI.Combat.updateHand)
  bind(Pixy.EventUID.EntityDeselected, Pixy.UI.Combat.updateHand)
  bind(Pixy.EventUID.StartBlockPhase, Pixy.UI.Combat.updateHand)
end
