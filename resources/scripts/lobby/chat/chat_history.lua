local max_messages = 50

Chat.saveMessage = function(msg)
  local history = Chat.History

  -- history shouldn't be bigger than MaxMessages
  local overflow = history:count() - max_messages
  while overflow > 0 do
    history:remove()
    overflow = overflow - 1
  end

  history:add(msg)
end

Chat.prevChatMessage = function()
  local history = Chat.History
  local input_box = Chat.InputBox

  input_box:setText(history:prev())
  input_box:setCaratIndex(history:get():len()+1)

  return true
end

Chat.nextChatMessage = function()
  local history = Chat.History
  local input_box = Chat.InputBox

  input_box:setText(history:next())
  input_box:setCaratIndex(history:get():len()+1)

  return true
end
