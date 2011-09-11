Lobby.bind = function()
  --~ bind(Pixy.EventUID.Connected, Chat.onConnected) -- debug
  --~ bind(Pixy.EventUID.Login, Chat.onLogin) -- debug
  bind(Pixy.EventUID.JoinLobby, Chat.onJoinLobby)
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
end
