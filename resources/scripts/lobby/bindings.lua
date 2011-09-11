bind(Pixy.EventUID.Connected, Chat.onConnected) -- debug
bind(Pixy.EventUID.Login, Chat.onLogin) -- debug
bind(Pixy.EventUID.JoinLobby, Chat.onJoinLobby)
bind(Pixy.EventUID.JoinRoom, Chat.onJoinRoom)
bind(Pixy.EventUID.JoinedRoom, Chat.onJoinedRoom)
bind(Pixy.EventUID.LeftRoom, Chat.onLeftRoom)
bind(Pixy.EventUID.IncomingMessage, Chat.onIncomingMessage)
bind(Pixy.EventUID.IncomingWhisper, Chat.onIncomingWhisper)
