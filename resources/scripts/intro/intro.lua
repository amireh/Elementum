if not Intro then Intro = {} end
Intro.switchToLobby = function()
  clearBindings()
  require("lobby/entry_point")
  Lobby.bind()
  Chat.attach()
end

Intro.oneTimeRun = function()
  Intro.bind()
  MainMenu.attach()
end
