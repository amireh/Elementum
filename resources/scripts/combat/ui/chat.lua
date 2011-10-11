local InputBox = nil
local MsgBox = nil
local Container = nil
local isTyping = false

UI.Chat = {}
UI.Chat.setup = function()
  Container = UI.Containers.Chat
  MsgBox = UI.Containers.Messages
  InputBox = UI.ChatInput

  MsgBoxAnimator = Animatable:new(MsgBox)
  MsgBoxAnimator:registerAnime("ShowChatBox")
  MsgBoxAnimator:registerAnime("HideChatBox")

  InputBox:hide()
  isTyping = false

  Input.KeyRelease.bind(OIS.KC_RETURN, UI.Chat.onReturn)
  --~ Input.KeyRelease.bind(OIS.KC_TAB, UI.Chat.onReturn)
  Input.KeyRelease.bind(OIS.KC_ESCAPE, UI.Chat.hideInput)
end

UI.Chat.cleanup = function()
  Input.KeyRelease.unbind(OIS.KC_RETURN, UI.Chat.onReturn)
  --~ Input.KeyRelease.unbind(OIS.KC_TAB, UI.Chat.onReturn)
  Input.KeyRelease.unbind(OIS.KC_TAB, UI.Chat.hideInput)

  isTyping = false

  MsgBoxAnimator:destroy()
  Container:hide()
end

UI.Chat.onReturn = function()
  if isTyping then
    -- send the shizzle
    if InputBox:getText():len() > 0 then
      local e = Pixy.Event(Pixy.EventUID.SendMessage)
      e:setProperty("M", InputBox:getText())
      NetMgr:send(e)
    end
    UI.Chat.hideInput()
  else
    UI.Chat.showInput()
  end

  --~ isTyping = not isTyping
  return true
end

UI.Chat.hideInput = function()
  InputBox:setText("")
  InputBox:hide()

  UI.Chat.hideMsgBox()

  --~ GfxEngine:enableMouseCaptureOverUIElement("Chat")

  isTyping = false
end
UI.Chat.showInput = function()
  InputBox:show()
  InputBox:moveToFront()
  InputBox:activate()

  UI.Chat.showMsgBox()

  --~ GfxEngine:disableMouseCaptureOverUIElement("Chat")

  isTyping = true
end
UI.Chat.hideMsgBox = function()
  if tonumber(MsgBox:getProperty("Alpha")) > 0 then
    --~ MsgBoxAnimator:stopAnime("ShowChatBox")
    --~ MsgBoxAnimator:startAnime("HideChatBox")
    MsgBoxAnimator:startAnime("ShowChatBox")
  end
end

UI.Chat.showMsgBox = function()
  if tonumber(MsgBox:getProperty("Alpha")) < 1.0 then
    --~ MsgBoxAnimator:stopAnime("HideChatBox")
    MsgBoxAnimator:startAnime("ShowChatBox")
  end
end


UI.Chat.onIncomingMessage = function(e)
  local txt = e:getProperty("M")
  local sender = e:getProperty("S")
  local MaxMessages = 20
  local msg = nil

  if not msg then
  msg =
    "[colour='FF00FF00']\\[" ..
    sender ..
    "][colour='FFFFFFFF']" ..
    ": " .. txt
  end

  while MsgBox:getItemCount() > MaxMessages do
    MsgBox:removeItem(MsgBox:getListboxItemFromIndex(0))
  end

  local item = CEGUI.createFormattedListboxTextItem(msg, CEGUI.HTF_WORDWRAP_LEFT_ALIGNED)
  MsgBox:addItem(item)
  MsgBox:ensureItemIsVisible(item)

  UI.Chat.showMsgBox()

  --~ UI.Animate(MsgBox, "ShowChatBox")

  return true
end
