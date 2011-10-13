Combat.bind = function()
  --bind(Pixy.EventUID.Connected, Combat.login)
  --bind(Pixy.EventUID.Login, Combat.on_login)
  --bind("AssignPuppets", Combat.assignPuppets)
  --bind("CreatePuppet", Combat.createPuppet)
  --bind("GameStarted", Combat.gameStarted)
  bind(Pixy.EventUID.Disconnected, UI.onDisconnected)
  bind(Pixy.EventUID.PlayerDroppedOut, UI.onPlayerDroppedOut)

  bind(Pixy.EventUID.EntitySelected, Gfx.onEntitySelected)
  bind(Pixy.EventUID.EntityDeselected, Gfx.onEntityDeselected)

  bind(Pixy.EventUID.UnitAttacked, UI.onEntityAttacked)
  bind(Pixy.EventUID.EntityDying, Units.onEntityDying)

  bind(Pixy.EventUID.StartTurn, UI.onStartTurn)
  bind(Pixy.EventUID.TurnStarted, UI.onTurnStarted)
  bind(Pixy.EventUID.StartBlockPhase, UI.onStartBlockPhase)
  bind(Pixy.EventUID.Block, UI.onBlock)
  bind(Pixy.EventUID.CancelBlock, UI.onCancelBlock)

  bind(Pixy.EventUID.InvalidAction, UI.onInvalidAction)
  --~ bind(Pixy.EventUID.Lifetap, Pixy.FX.Combat.onLifetap)
  bind(Pixy.EventUID.Lifetap, UI.onLifetap)
  bind(Pixy.EventUID.Trample, UI.onTrample)
  bind(Pixy.EventUID.FirstStrike, UI.onFirstStrike)

  bind(Pixy.EventUID.EntityStatChanged, UI.onStatChange)
  bind(Pixy.EventUID.UnitMechanicChanged, UI.onMechanicChanged)

  -- updating the player's hand --
  bind(Pixy.EventUID.StartTurn, Hand.Update)
  --bind(Pixy.EventUID.TurnStarted, UI.onTurnStarted)
  bind(Pixy.EventUID.TurnStarted, Hand.Update)
  bind(Pixy.EventUID.UpdatePuppet, Hand.Update)
  bind(Pixy.EventUID.EntitySelected, Hand.Update)
  bind(Pixy.EventUID.EntityDeselected, Hand.Update)
  bind(Pixy.EventUID.StartBlockPhase, Hand.Update)

  bind(Pixy.EventUID.IncomingMessage, UI.Chat.onIncomingMessage)

  Input.KeyRelease.bind(OIS.KC_X, Gfx.ToggleRTTCompositor)
  Input.KeyRelease.bind(OIS.KC_Z, UI.Toggle)
  Input.KeyRelease.bindToAll(Debug.playSpellEffect)
  Input.KeyRelease.bind(OIS.KC_Q, function() return GameMgr:requestShutdown() end)

end
