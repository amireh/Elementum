Intro.bind = function()
  --bind(Pixy.EventUID.ChangingState, Intro.cleanup)
  bind(Pixy.EventUID.ShuttingDown, Intro.shutdown)

  bind(Pixy.EventUID.GameDataSynced, Pixy.onGameDataSynced);

  bind(Pixy.EventUID.Login, MainMenu.onLogin)
  bind(Pixy.EventUID.Connected, MainMenu.onConnected)
  bind(Pixy.EventUID.EntityDied, MainMenu.onEntityDied)

  bind(Pixy.EventUID.PuppetListSynced, Profiles.onPuppetListSynced);
  bind(Pixy.EventUID.JoinLobby, Profiles.onJoinLobby)

  bind(Pixy.EventUID.JoinRoom, Chat.onJoinRoom)
  bind(Pixy.EventUID.LeaveRoom, Chat.onLeaveRoom)
  bind(Pixy.EventUID.JoinedRoom, Chat.onJoinedRoom)
  bind(Pixy.EventUID.LeftRoom, Chat.onLeftRoom)
  bind(Pixy.EventUID.IncomingMessage, Chat.onIncomingMessage)
  bind(Pixy.EventUID.IncomingWhisper, Chat.onIncomingWhisper)
  bind(Pixy.EventUID.SendWhisper, Chat.onSendWhisper)

  bind(Pixy.EventUID.JoinQueue, Lobby.onJoinQueue)
  bind(Pixy.EventUID.MatchFound, Lobby.onMatchFound)
  --bind(Pixy.EventUID.LeaveQueue, Lobby.onLeaveQueue)

  bind(Pixy.EventUID.UpdateDeck, Decks.onUpdateDeck)
  bind(Pixy.EventUID.PuppetSynced, Decks.onPuppetSynced)
  bind(Pixy.EventUID.PuppetDecksSynced, Decks.onDecksSynced)
  bind(Pixy.EventUID.RemoveDeck, Decks.onRemoveDeck)

  bind(Pixy.EventUID.PuppetSynced, Chat.onPuppetSynced)
  bind(Pixy.EventUID.PuppetDecksSynced, Chat.onPuppetDecksSynced)

  cleanup = Intro.cleanup
  arbitraryFunc = arbitraryFuncIntro
end
--Pixy.Log("I'm BEING CALLED")
