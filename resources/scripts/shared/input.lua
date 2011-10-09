Keybindings = {}
MasterBindings = {}

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

Input.clearBindings = function()
  Keybindings = {}
  MasterBindings = {}
end

Input.isAltDown = function()
  return Input.Keyboard:isModifierDown(OIS.Keyboard.Alt)
end

Input.KeyRelease = {}

Input.KeyRelease.bind = function(key, handler)
  if not Keybindings[key] then Keybindings[key] = {} end
  table.insert(Keybindings[key], handler)
end
Input.KeyRelease.unbind = function(key, handler)
  remove_by_value(Keybindings[key], handler)
end

Input.KeyRelease.bindToAll = function(handler)
  table.insert(MasterBindings, handler)
end

Input.KeyRelease.unbindFromAll = function(handler)
  remove_by_value(MasterBindings, handler)
end

Input.onKeyReleased = function(e)
  print("got key hit")
  if Keybindings[e.key] then
    for handler in list_iter(Keybindings[e.key]) do
      handler(e)
    end
  end

  for handler in list_iter(MasterBindings) do handler(e) end
end
