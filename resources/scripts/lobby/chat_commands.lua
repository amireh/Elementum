local formatCmdMsg = function(msg)
  return
    "[colour='ff00ff00']"
    .. msg ..
    "[colour='FFFFFFFF']"
end

Chat.Commands.ping = function(args)
  print("Command args: " .. args)
  Chat.showMessage(nil, nil, formatCmdMsg("Pong: 0ms."))
  return true
end

Chat.Commands.help = function(args)
  print("Command args: " .. args)
  Chat.showMessage("Available commands:", "Server")
  if args == "" then
    -- list all commands
    Chat.showMessage(nil, nil, formatCmdMsg("  /ping - tests server latency"))
    Chat.showMessage(nil, nil, formatCmdMsg("  /join ROOM - join a lobby room"))
    Chat.showMessage(nil, nil, formatCmdMsg("  /leave \\[ROOM] - leave either the party or lobby room"))
    Chat.showMessage(nil, nil, formatCmdMsg("  /w PLAYER MSG - send tell"))
    Chat.showMessage(nil, nil, formatCmdMsg("  /invite PLAYER - invite target player to your party"))
    Chat.showMessage(nil, nil, formatCmdMsg("  /kick PLAYER - remove target player from your party"))
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
