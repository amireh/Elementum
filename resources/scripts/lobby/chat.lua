-- UISheet : Chat

require("helpers")

MinMessageLength = 2
MaxMessageLength = 255
MaxMessages = 50

if not Chat then
  Chat = { Errors = { General = {} } }
end

Chat = {
  History = {},
  WhisperHistory = {},
  Contexts = {
    Typing = nil,
    Whispering = nil
  },
  Context = nil,

  Handlers = {
    Message = nil, -- a message sent to the room
    Whisper = nil, -- a "tell" sent to one client
    Command = nil -- a special command
  },

  Errors = {
    General = {
      TooShort = "Message must be at least " .. MinMessageLength .. " characters long.",
      TooLong = "Message can't be longer than " .. MaxMessageLength .. " characters."
    },
    Whisper = {
      InvalidTarget = "Invalid whisper target.",
      TooShort = nil,
      UnknownTarget = "Unknown whisper target, probably offline."
    },
    Message = {
    },
    Command = {
      UnknownCommand = "Unknown command. Type /help for a list of available commands.",
      InvalidArgs = "Invalid command arguments. Type /help for a list of valid commands."
    }
  },
  Commands = {
    ping = nil,
    join = nil,
    leave = nil,
    help = nil
  }
}

Chat.Errors.Whisper.TooShort = Chat.Errors.General.TooShort

require("lobby/chat_commands")

Rooms = {}
CurrentRoom = nil
NrClients = 0
CurrentWhisperTarget = nil
CurrentChatMessage = nil

local isSetup = false
Chat.attach = function()
	Layout = Pixy.UI.attach("lobby/chat.layout")
  MsgBox = CEGUI.toListbox(CEWindowMgr:getWindow("Elementum/Chat/Text/Messages"))
  InputBox = CEGUI.toEditbox(CEWindowMgr:getWindow("Elementum/Chat/Editbox/Message"))
  RoomBox = CEGUI.toListbox(CEWindowMgr:getWindow("Elementum/Chat/Listboxes/Clients"), "CEGUI::Listbox")
  RoomLabel = CEWindowMgr:getWindow("Elementum/Chat/Labels/ClientsNr")
  Tabs = CEGUI.toTabControl(CEWindowMgr:getWindow("Elementum/Containers/Rooms"))
  --~ local evt = Pixy.Event(Pixy.EventUID.JoinLobby)
  --~ evt:setProperty("Puppet", SelectedPuppetName)
  --~ NetMgr:send(evt)

  --~ Pixy.Log("Joining the Lobby with " .. Intro:getPuppetName())
  --~ Pixy.Log("Joining the Lobby with " .. SelectedPuppetName)

  GfxEngine:getCameraMan():setStyle(OgreBites.CS_ORBIT)
  GfxEngine:trackNode(nil)

  InputBox:activate()

  isSetup = true
end

Chat.detach = function()
	--CEWindowMgr:destroyWindow(Layout)
end

Chat.cleanup = function()
  if not isSetup then return true end

  return true
end

Chat.showMessage = function(txt, sender, msg)
  if not msg then
  msg =
    "[colour='FF00FF00']" ..
    sender ..
    "[colour='FFFFFFFF']" ..
    ": " .. txt
  end

  while MsgBox:getItemCount() > MaxMessages do
    MsgBox:removeItem(MsgBox:getListboxItemFromIndex(0))
  end

  local item = CEGUI.createFormattedListboxTextItem(msg, CEGUI.HTF_WORDWRAP_LEFT_ALIGNED)
  MsgBox:addItem(item)
  MsgBox:ensureItemIsVisible(item)

end

Chat.showWhisper = function(txt, sender)
  local msg =
    "[colour='ff00ffff']" ..
    sender ..
    ": " .. txt .. "\n" ..
    "[colour='FFFFFFFF']"
  Chat.showMessage(txt, sender, msg)
end

Chat.addClientToRoom = function(name)
  local item = CEGUI.createListboxTextItem(name)
  item:setTextParsingEnabled(true)
  item:setSelectionBrushImage("TaharezLook", "MultiListSelectionBrush")

  RoomBox:addItem(item)
  NrClients = NrClients+1
  RoomLabel:setText("There are " .. NrClients .. " players in this room.")
end

Chat.populateRoom = function(clients)
  print("Populating room clients")
  list = split(clients, ";")
  for client in list_iter(list) do
    print(client)
    Chat.addClientToRoom(client)
  end
end

Chat.onConnected = function(e)
  local mEvt = Pixy.Event(Pixy.EventUID.Login)
  mEvt:setProperty("Username", "Kandie")
  mEvt:setProperty("Password", "tuonela")
  NetMgr:send(mEvt)

  return true
end

Chat.onLogin = function(e)
  SelectedPuppetName = "Kandie"

  local evt = Pixy.Event(Pixy.EventUID.JoinLobby)
  evt:setProperty("Puppet", SelectedPuppetName)
  NetMgr:send(evt)

  return true
end

Chat.onJoinLobby = function(e)
  if e.Feedback ~= Pixy.EventFeedback.Ok then
    local box = Pixy.UI.attachOverlay("ProgressBox")
    box:setText("Unable to connect to lobby. Please try again later.")
  end
  return true
end

-- we either joined this room or not, if we did
-- we get the list of clients in this current room
Chat.onJoinRoom = function(e)

  local win = CEWindowMgr:loadWindowLayout("lobby/party.layout", "Elementum/Rooms/" .. e:getProperty("R"))
  win:setText(e:getProperty("R"))
  Tabs:addTab(win)
  Chat.switchToRoom(e:getProperty("R"))

  if e.Feedback == Pixy.EventFeedback.Ok then
    assert(e:hasProperty("R") and e:hasProperty("C"))

    table.insert(Rooms, e:getProperty("R"))

    -- set the first room as our default one
    if not CurrentRoom then CurrentRoom = e:getProperty("R") end

    Chat.populateRoom(e:getProperty("C"))
    Chat.addClientToRoom(SelectedPuppetName)
    Pixy.Log("Contacts in room " .. CurrentRoom .. ": " .. e:getProperty("C"))
  else
    Chat.showMessage("Unable to join room.", "Server")
  end
  return true
end

-- a new client has joined this room
Chat.onJoinedRoom = function(e)
  assert(e:hasProperty("R") and e:hasProperty("S"))
  Chat.showMessage("has joined the room.", e:getProperty("S"))

  Chat.addClientToRoom(e:getProperty("S"))

  return true
end

-- an existing client has left this room
Chat.onLeftRoom = function(e)
  assert(e:hasProperty("R") and e:hasProperty("S"))

  Chat.showMessage("has left the room.", e:getProperty("S"))

  NrClients = NrClients-1
  RoomLabel:setText("There are " .. NrClients .. " players in this room.")

  -- remove the client from the clients list
  local item = RoomBox:findItemWithText(e:getProperty("S"))

  -- NOTE: why does it break here???
  if not item then return true end

  RoomBox:removeItem(item)

  return true
end

Chat.switchToRoom = function(room)
  local win = CEWindowMgr:getWindow("Elementum/Rooms/" .. room)
  assert(win)
  local msg_box = win:getChildAtIdx(0)--("Messages")
  assert(msg_box)
  MsgBox = CEGUI.toListbox(msg_box)
  MsgBox:rename(win:getName() .. "/" .. "Messages")
end

Chat.onIncomingMessage = function(e)
  if e.Feedback == Pixy.EventFeedback.Ok then
    assert(e:hasProperty("M") and e:hasProperty("S"))
    Chat.showMessage(e:getProperty("M"), e:getProperty("S"))
  end
  return true
end

Chat.onIncomingWhisper = function(e)
  if e.Feedback == Pixy.EventFeedback.Ok then
    assert(e:hasProperty("M") and e:hasProperty("S"))
    Chat.showWhisper(e:getProperty("M"), e:getProperty("S"))

    -- track the target if this is the first whisper we receive from them
    Chat.trackWhisperTarget(e:getProperty("S"))
    -- set them as the most recent whisper target
    CurrentWhisperTarget = e:getProperty("S")
  end
  return true
end

Chat.Send = function(e)
  local msg = InputBox:getText()
  local len = msg:len()
  local e = nil

  if len == 0 then return true end

  if len > MaxMessageLength then
    return Chat.notifySendFailed("General", "TooLong")
  elseif len < MinMessageLength then
    return Chat.notifySendFailed("General", "TooShort")
  end

  local msg_type = Chat.parseMessageType(msg)
  if msg_type then
    local _result, _error = Chat.Handlers[msg_type](msg)

    -- if an error occured, we notify the client
    if not _result then
      return Chat.notifySendFailed(msg_type, _error)
    else
      return true
    end
  end

  -- really shouldn't be here
  assert(false)
end

Chat.parseMessageType = function(msg)
  -- a message is either a message, a whisper, or a command
  -- whispers format: "/w TARGET MSG"
  -- commands format: "/COMMAND"

  -- a) is it a whisper?
  if (msg:sub(0,3) == "/w ") then return "Whisper" end

  -- b) is it a command?
  if (msg:sub(0,1) == "/") then return "Command" end

  return "Message"
end

Chat.Handlers.Whisper = function(msg)
  print("this is a whisper! ")

  -- validate the whisper
  local target = capitalize(string.match(msg:sub(3), "%a+"))
  if not target then return false, "InvalidTarget" end

  msg = msg:sub(5 + target:len()) --[["/w TARGET MSG"]]

  if msg:len() < MinMessageLength then return false, "TooShort" end


  -- TODO: check if target is online
  -- if not Chat.isOnline(target) then return false, "UnknownTarget" end

  e = Pixy.Event(Pixy.EventUID.SendWhisper)
  e:setProperty("M", msg)
  e:setProperty("T", target)

  -- send the tell to ourself as well
  Chat.showWhisper(msg, "\\[To: " .. target .. "\]")

  -- track history
  Chat.trackWhisperTarget(target)

  -- switch back to typing context
  --~ Chat.switchContext(Chat.Contexts.Typing)
  return Chat.doSend(e)
end

Chat.Handlers.Message = function(msg)
  e = Pixy.Event(Pixy.EventUID.SendMessage)
  e:setProperty("M", msg)

  -- save the message for history browsing
  Chat.saveMessage(msg)

  return Chat.doSend(e)
end

Chat.Handlers.Command = function(msg)
  local cmd = (string.match(msg:sub(1), "%a+")):lower()
  if not Chat.Commands[cmd] then return false, "UnknownCommand" end

  Chat.saveMessage(msg)

  return Chat.Commands[cmd](msg:sub(3 + cmd:len()))
end

Chat.notifySendFailed = function(msg_type, _error)
  print("Error: " .. msg_type .. " # " .. _error)
  assert(Chat.Errors[msg_type][_error] ~= nil)

  local msg =
    "[colour='ffff0000']" .. Chat.Errors[msg_type][_error] .. "[colour='FFFFFFFF']"
  Chat.showMessage(txt, nil, msg)

  return true
end

Chat.doSend = function(msg_event)
  msg_event:setProperty("R", CurrentRoom)
  msg_event:setProperty("S", SelectedPuppetName)

  NetMgr:send(msg_event)
  InputBox:setText("")

  return true
end

Chat.onCaptureGained = function(e)
  print("Gained capture!")
  Chat.Context = Chat.Contexts.Typing
end

Chat.onCaptureLost = function(e)
  print("Lost capture!")
  Chat.Context = nil
end

Chat.switchContext = function(ctxt)
  Chat.Context = ctxt
  Chat.Context()
end

Chat.Contexts.Typing = function()
  CurrentWhisperTarget = nil
  InputBox:activate()
end

Chat.onTextChanged = function(e)
  if InputBox:getText() == "" then
    CurrentChatMessage = nil
    CurrentWhisperTarget = nil
  end
end

Chat.saveMessage = function(msg)
  -- history shouldn't be bigger than MaxMessages
  local overflow = table.getn(Chat.History) - MaxMessages
  if overflow > 0 then
    for item in list_iter(Chat.History) do
      print("removing message history overflow of " .. overflow .. " messages")
      table.remove(Chat.History, item)
      overflow = overflow+1
      if overflow == 0 then break end
    end
  end

  table.insert(Chat.History, msg)
end

Chat.Contexts.Whispering = function()
  -- there's no current whisper target set, see if there's any whisper history
  if not CurrentWhisperTarget then
    if not Chat.prevWhisperTarget() then
      -- there's no whisper history, switch back to typing context
      return Chat.switchContext(Chat.Contexts.Typing)
    end
  end

  -- type the last whisper target's name :)
  InputBox:setText("/w " .. CurrentWhisperTarget .. " ")

  return true
end

Chat.trackWhisperTarget = function(target)
  local tracked = false
  for favorite in list_iter(Chat.WhisperHistory) do
    if favorite == target then
      --tracked = true
      removeByValue(Chat.WhisperHistory, target)
      CurrentWhisperTarget = target
      --table.remove(Chat.WhisperHistory, target)
      break
    end
  end
  if not tracked then table.insert(Chat.WhisperHistory, target) end
end

-- search for the cursor whisper target in the history
-- and get the previous one
-- if there is no cursor, simply fetch the first in history
Chat.prevWhisperTarget = function()
  local found = false

  -- is there any history at all?
  if table.getn(Chat.WhisperHistory) == 0 then return false end

  -- special case: CurrentWhisperTarget is the last in the list, so we rewind
  if CurrentWhisperTarget == Chat.WhisperHistory[1] then
    CurrentWhisperTarget = Chat.WhisperHistory[table.getn(Chat.WhisperHistory)]
    --~ for dummy in rlist_iter(Chat.WhisperHistory) do
      --~ CurrentWhisperTarget = dummy
      --~ break
    --~ end
    found = true
  else
    -- normal case, get the next one if any
    for client in rlist_iter(Chat.WhisperHistory) do
      if not CurrentWhisperTarget or found then
        CurrentWhisperTarget = client
        found = true
        break
      end

      if client == CurrentWhisperTarget then found = true end
    end
  end

  if found then
    InputBox:setText("/w " .. CurrentWhisperTarget .. " ")
    InputBox:setCaratIndex(MaxMessageLength+1)
  end

  return found
end

Chat.prevChatMessage = function()
  if not CurrentChatMessage and table.getn(Chat.History) > 0 then
    for dummy in rlist_iter(Chat.History) do
      CurrentChatMessage = dummy
      break
    end
    InputBox:setText(CurrentChatMessage)
    InputBox:setCaratIndex(MaxMessageLength+1)
    return true
  end

  local found = false
  for msg in rlist_iter(Chat.History) do
    if not CurrentChatMessage or found then
      CurrentChatMessage = msg
      found = true
      break
    end

    if msg == CurrentChatMessage then found = true end
  end

  if found then
    InputBox:setText(CurrentChatMessage)
    InputBox:setCaratIndex(MaxMessageLength+1)
  end

  return found
end

Chat.nextChatMessage = function()
  if not CurrentChatMessage and table.getn(Chat.History) > 0 then
    for dummy in list_iter(Chat.History) do
      CurrentChatMessage = dummy
      break
    end
    InputBox:setText(CurrentChatMessage)
    InputBox:setCaratIndex(MaxMessageLength+1)
    return true
  end

  local found = false
  for msg in list_iter(Chat.History) do
    if not CurrentChatMessage or found then
      CurrentChatMessage = msg
      found = true
      break
    end

    if msg == CurrentChatMessage then found = true end
  end

  if found then
    InputBox:setText(CurrentChatMessage)
    InputBox:setCaratIndex(MaxMessageLength+1)
  end

  return found
end

Chat.attach()
