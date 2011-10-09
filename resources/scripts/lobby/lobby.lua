Lobby.doJoinQueue = function(args)
  args = CEGUI.toWindowEventArgs(args)
  local button = args.window
  button:disable()

  local e = Pixy.Event(Pixy.EventUID.JoinQueue)
  e:setProperty("D", Lobby.DeckList:getSelectedItem():getText())
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

  UISheet.hideDialog()
end

Lobby.onJoinQueue = function(e)
  if e.Feedback == Pixy.EventFeedback.Ok then
    CEWindowMgr:getWindow("Elementum/Chat/Buttons/JoinQueue"):hide()
    CEWindowMgr:getWindow("Elementum/Chat/Labels/Queue"):setText("Status: in queue.")

    local button = CEWindowMgr:getWindow("Elementum/Chat/Buttons/LeaveQueue")
    button:enable()
    button:show()

    IntroState:setPuppetName(Selected:getName())

    UISheet.showDialog("Looking for opponents")
  else
    CEWindowMgr:getWindow("Elementum/Chat/Buttons/JoinQueue"):enable()
    UISheet.showDialog("Unable to join the queue.")
  end

end

Lobby.onMatchFound = function(e)
  --clearBindings()
  Chat:detach()
  --Intro.cleanup()
  --~ GameMgr:changeState(CombatState)

  return true
end

Lobby.doLogout = function(e)
  NetMgr:disconnect()
  --GameMgr:changeState(IntroState)
  Chat:detach()
  Chat.cleanup()
  Decks.cleanup()

  --~ clearBindings()
  --~ Intro.bind()

  --require("intro/entry_point")
  MainMenu:attach()
end

Lobby.showDecks = function()
  Decks:attach()
end

