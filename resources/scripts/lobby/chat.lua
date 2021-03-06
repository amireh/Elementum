-- UISheet : Chat

MinMessageLength = 2
MaxMessageLength = 255
MaxMessages = 50

Chat = { Errors = { General = {} } }

local SelectedRnd = nil
Lobby.DeckList = nil

Chat = {
  History = {},
  WhisperHistory = {},
  Contexts = {
    Typing = nil,
    Whispering = nil
  },
  Context = nil,
  InputBox = nil,

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
      InvalidArgs = "Invalid command arguments. Type /help for a list of valid commands.",
      PermanentRoom = "You can not leave this room."
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
Chat = UISheet:new("lobby/chat.layout", Chat)

require "lobby/chat/chat_commands"
require "lobby/chat/chat_history"
require "lobby/chat/chat_whispers"

__RoomNames__ = {}

Rooms = {}
CurrentRoom = nil
CurrentWhisperTarget = nil

local isSetup = false
function Chat:attach()
  UISheet.attach(self)
  --MsgBox = CEGUI.toListbox(CEWindowMgr:getWindow("Elementum/Chat/Text/Messages"))
  InputBox = CEGUI.toEditbox(CEWindowMgr:getWindow("Elementum/Chat/Editbox/Message"))
  RoomBox = CEGUI.toListbox(CEWindowMgr:getWindow("Elementum/Chat/Listboxes/Clients"))
  Lobby.DeckList = CEGUI.toCombobox(CEWindowMgr:getWindow("Elementum/Chat/Comboboxes/Decks"))
  RoomLabel = CEWindowMgr:getWindow("Elementum/Chat/Labels/ClientsNr")
  Tabs = CEGUI.toTabControl(CEWindowMgr:getWindow("Elementum/Containers/Rooms"))
  Chat.InputBox = InputBox -- export it so chat_history.lua can see this

  Input.KeyRelease.bindToAll(Chat.onKeyReleased)
  Input.KeyRelease.bind(OIS.KC_ESCAPE, Chat.backToListing)

  if not isSetup then
    Chat.History = Cyclable:new()
    Chat.WhisperHistory = Cyclable:new()
    isSetup = true
  end

  InputBox:activate()
end

Chat.backToListing = function()
  local e = Pixy.Event(Pixy.EventUID.LeaveLobby)
  NetMgr:send(e)

  Decks.cleanup()
  Chat.cleanup()
  Profiles.attach()
end

function Chat:detach()
  UISheet.detach(self)

  Input.KeyRelease.unbind(OIS.KC_ESCAPE, Chat.backToListing)
  Input.KeyRelease.unbindFromAll(Chat.onKeyReleased)

	--~ CEWindowMgr:destroyWindow(Chat.Layout)
	--~ Chat.Layout:hide()
  --~ FxEngine:dehighlight()

end

Chat.cleanup = function()
  if not isSetup then return true end

  Fx.dehighlight()
  Chat:detach()

  -- destroy rooms
  for room in list_iter(__RoomNames__) do
    Chat.unregisterRoom(room)
  end
  Tabs:removeTab(Rooms["General"].Window:getName())
  CEWindowMgr:destroyWindow(Rooms["General"].Window)

  __RoomNames__ = {}
  Rooms = {}
  CurrentRoom = nil
  --~ Chat.History = {}
  Chat.History:destroy()
  Chat.WhisperHistory:destroy()
  Chat.Context = nil

  isSetup = false
  return true
end

Chat.showMessage = function(room, txt, sender, msg)
  if not msg then
  msg =
    "[colour='FF00FF00']" ..
    sender ..
    "[colour='FFFFFFFF']" ..
    ": " .. txt
  end

  local MsgBox = Rooms[room].MsgBox

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

  -- whispers are shown in all rooms
  print("Showing whisper in " .. table.getn(Rooms) .. " rooms")
  for room in list_iter(__RoomNames__) do
    Chat.showMessage(room, nil, nil, msg)
  end
end

Chat.addClientToRoom = function(name)
  local item = CEGUI.createListboxTextItem(name)
  item:setTextParsingEnabled(true)
  item:setSelectionBrushImage("TaharezLook", "MultiListSelectionBrush")

  RoomBox:addItem(item)
end

Chat.populateRoom = function(clients)
  print("Removing all clients from list")
  while RoomBox:getItemCount() > 0 do
    RoomBox:removeItem(RoomBox:getListboxItemFromIndex(0))
  end

  print("Populating room clients")
  for client in list_iter(clients) do
    print(client)
    Chat.addClientToRoom(client)
  end

end

Chat.registerRoom = function(name, clients)

  local win = CEWindowMgr:loadWindowLayout("lobby/room.layout", "Elementum/Rooms/" .. name)
  win:setText(name)
  win:setUserString("Room", name) -- onTabChanged() uses this string to identify the room

  Rooms[name] = {
    Name = name,
    Window = win,
    Clients = split(clients, ";")
  }

  table.insert(__RoomNames__, name)

  Tabs:addTab(win)
  Chat.switchToRoom(name)

  --Chat.addClientToRoom(SelectedPuppetName)
  Pixy.Log("Contacts in room " .. CurrentRoom.Name .. ": " .. clients)

end

Chat.unregisterRoom = function(room)
  assert(Rooms[room])

  print("Unregistering room " .. room)

  -- attempt to switch to tab-1
  local next_idx = table.getn(__RoomNames__)
  for room_name in rlist_iter(__RoomNames__) do
    if room_name == room then next_idx = next_idx - 1; break end

    next_idx = next_idx - 1
  end

  if next_idx < 1 then return false end
  --assert(next_idx >= 1)

  Chat.switchToRoom(__RoomNames__[next_idx])

  Tabs:removeTab(Rooms[room].Window:getName())
  CEWindowMgr:destroyWindow(Rooms[room].Window)
  Rooms[room] = nil
  remove_by_value(__RoomNames__, room)

end

-- we either joined this room or not, if we did
-- we get the list of clients in this current room
Chat.onJoinRoom = function(e)

  if e.Feedback == Pixy.EventFeedback.Ok then
    assert(e:hasProperty("R") and e:hasProperty("C"))
    Chat.registerRoom(e:getProperty("R"), e:getProperty("C"))
  else
    Chat.showMessage(CurrentRoom.Name, "Unable to join room.", "Server")
  end

  return true
end

Chat.onLeaveRoom = function(e)
  if e.Feedback == Pixy.EventFeedback.Ok then
    assert(e:hasProperty("R"))
    Chat.unregisterRoom(e:getProperty("R"))
  end

  return true
end

-- a new client has joined this room
Chat.onJoinedRoom = function(e)
  assert(e:hasProperty("R") and e:hasProperty("S"))

  local room = e:getProperty("R")
  local client = e:getProperty("S")

  -- add this client to the room's list
  table.insert(Rooms[room].Clients, client)

  -- display a notification in the room's message box
  Chat.showMessage(room, "has joined the room.", client)

  -- if it's our current room, add the client to the box, and adjust the clients nr label
  if CurrentRoom.Name == room then
    Chat.addClientToRoom(client)
    Chat.refreshCurrentRoom()
  end

  return true
end

Chat.refreshCurrentRoom = function()
  RoomLabel:setText("There are " .. table.getn(CurrentRoom.Clients) .. " players in this room.")
end

-- an existing client has left this room
Chat.onLeftRoom = function(e)
  assert(e:hasProperty("R") and e:hasProperty("S"))
  local room = e:getProperty("R")
  local client = e:getProperty("S")

  Chat.showMessage(room, "has left the room.", client)
  remove_by_value(Rooms[room].Clients, client)

  if CurrentRoom.Name == room then
    Chat.refreshCurrentRoom()

    -- remove the client from the clients list
    local item = RoomBox:findItemWithText(client)

    -- NOTE: why does it break here???
    --if not item then return true end

    RoomBox:removeItem(item)
  end

  return true
end

Chat.switchToRoom = function(room)
  print("Switching to room "  .. room)
  CurrentRoom = Rooms[room]

  local msg_box = CurrentRoom.Window:getChildAtIdx(0)--("Messages")
  assert(msg_box)

  CurrentRoom.MsgBox = CEGUI.toListbox(msg_box)
  CurrentRoom.MsgBox:rename(CurrentRoom.Window:getName() .. "/" .. "Messages")

  Tabs:setSelectedTab(CurrentRoom.Window:getName())
  Chat.populateRoom(CurrentRoom.Clients)

  Chat.refreshCurrentRoom()

  --Tabs:makeTabVisible(win:getName())
end

Chat.onTabChanged = function(args)
  local args = CEGUI.toWindowEventArgs(args)
  print("Tab changed: " .. args.window:getName())
  local win = Tabs:getTabContentsAtIndex(Tabs:getSelectedTabIndex())

  -- extract room name from window
  Chat.switchToRoom(win:getUserString("Room"))

  return true
end

Chat.onIncomingMessage = function(e)
  if e.Feedback == Pixy.EventFeedback.Ok then
    assert(e:hasProperty("R") and e:hasProperty("M") and e:hasProperty("S"))
    Chat.showMessage(e:getProperty("R"), e:getProperty("M"), e:getProperty("S"))
  end
  return true
end

Chat.onIncomingWhisper = function(e)
  print("A whisper is incoming!")

  --if e.Feedback == Pixy.EventFeedback.Ok then
    assert(e:hasProperty("M") and e:hasProperty("S"))
    Chat.showWhisper(e:getProperty("M"), e:getProperty("S"))

    -- track the target if this is the first whisper we receive from them
    Chat.trackWhisperTarget(e:getProperty("S"))
    -- set them as the most recent whisper target
    CurrentWhisperTarget = e:getProperty("S")
  --end
  return true
end

Chat.onSendWhisper = function(e)
  if e:hasProperty("E") and e:getProperty("E") == "UnknownTarget" then
    return Chat.notifySendFailed("Whisper", "UnknownTarget")
  end
end

Chat.send = function(e)
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
  e:setProperty("R", CurrentRoom.Name)

  -- save the message for history browsing
  Chat.saveMessage(msg)

  return Chat.doSend(e)
end

Chat.Handlers.Command = function(msg)
  local cmd = (string.match(msg:sub(1), "%a+")):lower()
  if not Chat.Commands[cmd] then return false, "UnknownCommand" end

  Chat.saveMessage(msg)
  InputBox:setText("")

  return Chat.Commands[cmd](msg:sub(3 + cmd:len()))
end

Chat.notifySendFailed = function(msg_type, _error)
  print("Error: " .. msg_type .. " # " .. _error)
  assert(Chat.Errors[msg_type][_error] ~= nil)

  local msg =
    "[colour='ffff0000']" .. Chat.Errors[msg_type][_error] .. "[colour='FFFFFFFF']"
  Chat.showMessage(CurrentRoom.Name, txt, nil, msg)

  return true
end

Chat.doSend = function(msg_event)

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
  local history = Chat.WhisperHistory
  if history:find(target) then
    history:remove(target)
  end
  history:add(target)
  history:reset(true)
end

-- search for the cursor whisper target in the history
-- and get the previous one
-- if there is no cursor, simply fetch the first in history
Chat.prevWhisperTarget = function()
  local history = Chat.WhisperHistory

  if history:isEmpty() then return true end

  InputBox:setText("/w " .. history:prev() .. " ")
  InputBox:setCaratIndex(InputBox:getText():len()+1)

  return true
end


Chat.onPuppetDecksSynced = function(e)
  Intro.PuppetDecks = __PuppetDecksTemp
  __PuppetDecksTemp = nil

  Lobby.DeckList:clearAllSelections()
  Lobby.DeckList:resetList()

  for deck in list_iter(Intro.PuppetDecks) do
    item = CEGUI.createListboxTextItem(deck:getName())
    Lobby.DeckList:addItem(item)
  end

  if Lobby.DeckList:getItemCount() > 0 then
    Lobby.DeckList:setItemSelectState(0, true)
  end

  Decks.onDecksSynced(Intro.PuppetDecks)

  return true
end

Chat.onPuppetSynced = function(e)
  Intro.Puppet = __PuppetTemp
  __PuppetTemp = nil

  CEWindowMgr:getWindow("Elementum/Chat/Labels/Portrait"):setText(Intro.Puppet:getName())
  SelectedRnd = Profiles.Knights[raceToString(Intro.Puppet:getRace())]
  Fx.highlight(SelectedRnd)

  Decks.onPuppetSynced(Intro.Puppet)

  return true
end
