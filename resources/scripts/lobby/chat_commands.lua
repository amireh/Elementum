local formatCmdMsg = function(msg)
  return
    "[colour='ff00ff00']"
    .. msg ..
    "[colour='FFFFFFFF']"
end

Chat.Commands.ping = function(args)
  print("Command args: " .. args)
  Chat.showMessage(CurrentRoom.Name, nil, nil, formatCmdMsg("Pong: 0ms."))
  return true
end

Chat.Commands.help = function(args)
  print("Command args: " .. args)
  Chat.showMessage(CurrentRoom.Name, "Available commands:", "Server")
  if args == "" then
    -- list all commands
    Chat.showMessage(CurrentRoom.Name, nil, nil, formatCmdMsg("  /ping - tests server latency"))
    Chat.showMessage(CurrentRoom.Name, nil, nil, formatCmdMsg("  /join ROOM - join a lobby room"))
    Chat.showMessage(CurrentRoom.Name, nil, nil, formatCmdMsg("  /leave \\[ROOM] - leave either the party or lobby room"))
    Chat.showMessage(CurrentRoom.Name, nil, nil, formatCmdMsg("  /w PLAYER MSG - send tell"))
    Chat.showMessage(CurrentRoom.Name, nil, nil, formatCmdMsg("  /invite PLAYER - invite target player to your party"))
    Chat.showMessage(CurrentRoom.Name, nil, nil, formatCmdMsg("  /kick PLAYER - remove target player from your party"))
  end

  return true
end

Chat.Commands.join = function(args)
  if args == "" then
    return false, "InvalidArgs"
  end

  local room = capitalize((string.match(args, "%a+")):lower())

  local e = Pixy.Event(Pixy.EventUID.JoinRoom)
  e:setProperty("R", room)
  NetMgr:send(e)

  return true
end

Chat.Commands.leave = function(args)
  local room = nil
  if args == "" then
    room = CurrentRoom.Name
  else
    room = capitalize((string.match(args, "%a+")):lower())
    -- verify that we're connected to this room
    local found = false
    for room_name in list_iter(__RoomNames__) do
      if room_name == room then found = true; break end
    end
    if not found then return false, "InvalidArgs" end
  end

  if room == "General" then return false, "PermanentRoom" end

  local e = Pixy.Event(Pixy.EventUID.LeaveRoom)
  e:setProperty("R", room)
  NetMgr:send(e)

  e.Feedback = Pixy.EventFeedback.Ok
  EvtMgr:hook(e)

  return true
end
