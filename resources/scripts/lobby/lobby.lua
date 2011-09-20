Lobby.doJoinQueue = function(args)
  args = CEGUI.toWindowEventArgs(args)
  local button = args.window
  button:disable()

  local e = Pixy.Event(Pixy.EventUID.JoinQueue)
  NetMgr:send(e)

end

Lobby.doLeaveQueue = function(args)
  args = CEGUI.toWindowEventArgs(args)
  local button = args.window
  button:disable()
  button:hide()

  local e = Pixy.Event(Pixy.EventUID.LeaveQueue)
  NetMgr:send(e)

  --CEWindowMgr:getWindow("Elementum/Chat/Buttons/LeaveQueue"):hide()
  CEWindowMgr:getWindow("Elementum/Chat/Labels/Queue"):setText("Status: not in queue.")

  local button = CEWindowMgr:getWindow("Elementum/Chat/Buttons/JoinQueue")
  button:enable()
  button:show()

  Pixy.UI.doneWaiting(false)
end

Lobby.onJoinQueue = function(e)
  if e.Feedback == Pixy.EventFeedback.Ok then
    CEWindowMgr:getWindow("Elementum/Chat/Buttons/JoinQueue"):hide()
    CEWindowMgr:getWindow("Elementum/Chat/Labels/Queue"):setText("Status: in queue.")

    local button = CEWindowMgr:getWindow("Elementum/Chat/Buttons/LeaveQueue")
    button:enable()
    button:show()

    IntroState:setPuppetName(Selected:getName())

    Pixy.UI.waiting("Looking for opponents", Chat.Layout)
  else
    CEWindowMgr:getWindow("Elementum/Chat/Buttons/JoinQueue"):enable()
    Pixy.UI.attachOverlay("ProgressBox"):setText("Unable to join the queue.")
  end

end

Lobby.onMatchFound = function(e)
  clearBindings()
  Chat.detach()
  Intro.cleanup()
  Lobby.cleanup()
  GameMgr:changeState(CombatState)
end

Lobby.doLogout = function(e)
  NetMgr:disconnect()
  --GameMgr:changeState(IntroState)
  Chat.detach()
  Decks.cleanup()

  --~ clearBindings()
  --~ Intro.bind()

  --require("intro/entry_point")
  MainMenu.attach()
end

Lobby.showDecks = function()
  Decks.attach()
end

Lobby.cleanup = function()

end
