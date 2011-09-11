Lobby = {}

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

    Pixy.UI.waiting("Looking for opponents", Layout)
  else
    CEWindowMgr:getWindow("Elementum/Chat/Buttons/JoinQueue"):enable()
    Pixy.UI.attachOverlay("ProgressBox"):setText("Unable to join the queue.")
  end

end

Lobby.onLeaveQueue = function(e)
end
