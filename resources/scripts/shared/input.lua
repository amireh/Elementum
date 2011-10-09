Input = {
  Keyboard = nil,
  Mouse = nil,
  onKeyReleased = function(e) end,
  onKeyPressed = function(e) end,
  onMousePressed = function(e, id) end,
  onMouseReleased = function(e, id) end
}

Input.setup = function()
  Keyboard = InputMgr:getKeyboard()
  --~ Mouse = InputMgr:getMouse()
end

Input.cleanup = function()
  Keyboard = nil
  Mouse = nil
end

Input.isAltDown = function()
  return Input.Keyboard:isModifierDown(OIS.Keyboard.Alt)
end
