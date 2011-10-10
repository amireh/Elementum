Chat.onKeyReleased = function(e)

  -- ## typing context ## --
  if Chat.Context == Chat.Contexts.Typing then
    -- cycle through msg history using Up and Down arrows
    if e.key == OIS.KC_UP then
      return Chat.prevChatMessage()
    elseif e.key == OIS.KC_DOWN then
      return Chat.nextChatMessage()
    elseif e.key == OIS.KC_RETURN then
      return Chat.send()

    -- Alt+R switches into Whisper mode
    --[[elseif e.key == OIS.KC_R and Input.isAltDown() then
      return Chat.switchContext(Chat.Contexts.Whispering)
    end]]

    elseif e.key == OIS.KC_TAB then
      --~ Chat.switchContext(Chat.Contexts.Whispering)
      return Chat.prevWhisperTarget()
    end

  -- ## whispering context ## --
  --elseif Chat.Context == Chat.Contexts.Whispering then
    -- cycle through the whisper history using TAB


  -- ## no context ## --
  else -- no context, the chat box isn't activated
    if e.key == OIS.KC_TAB then
      Chat.switchContext(Chat.Contexts.Typing)
    end
  end

end
