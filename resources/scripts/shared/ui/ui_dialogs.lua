-- UI Dialogs --
-- UIDialog provides necessary and convenience functions for attaching
-- and detaching CEGUI dialogs

UIDialog = {}

local __UID = 0
local __Path = "overlays/dialog.layout"
local Win2Dialogs = {} -- maps CEGUI::Windows to UIDialog objects, see events below

function UIDialog:new(in_text, keep_alive, keep_hidden)
  if not in_text then return error("can not create an empty dialog!") end

  local o = {
    Window = nil,
    Label = nil,
    KeepAlive = keep_alive or false,
    Buttons = {
      Ok = nil,
      Cancel = nil
    },
    Callbacks = {
      Ok = {},
      Cancel = {}
    }
  }

  setmetatable(o, {__index = self})
  self.__index = self

  o:__load()
  o.Label:setText(in_text)

  Pixy.Log("UIDialog: '" .. o.Window:getName() .. "' created")

  if not keep_hidden then o:show() end

  return o
end

-- load the layout and rename it to prevent name clashes,
-- UIDialogs are always loaded on construction
function UIDialog:__load()
  local prefix = "UIDialog_Auto_" .. __UID


  self.Window = CEWindowMgr:loadWindowLayout(__Path, prefix)
  self.Label = self.Window:getChild(prefix .. "Dialog_Label")
  self.Buttons.Ok = self.Window:getChild(prefix .. "Dialog_OkButton")
  self.Buttons.Cancel = self.Window:getChild(prefix .. "Dialog_CancelButton")

  Win2Dialogs[self.Window:getName()] =  self

  self.Buttons.Ok:subscribeEvent("Clicked", UIDialog.onDialogOk)
  self.Buttons.Cancel:subscribeEvent("Clicked", UIDialog.onDialogCancel)

  -- @note
  -- the name of the window is not used anywhere nor is significant for us,
  -- but it has to be unique for CEGUI to load it multiple times!
  --~ self.Window:setName("UIDialog" .. __UID)
  __UID = __UID + 1
end

function UIDialog:show()
	-- attach layout
  local parent = Pixy.UI.CurrentSheet.Window
  local layout = self.Window

  if not parent then return error("attempting to load a dialog when no UISheet is attached!") end

  parent:addChildWindow(layout)
	layout:setAlwaysOnTop(true)
	layout:show()

  self:__resize()

	Pixy.Log("UIDialog: '" .. self.Window:getName() .. "' is now visible")

	return self
end

function UIDialog:isVisible()
  return self.Window and self.Window:isVisible() and self.Window:getParent()
end

function UIDialog:hide()
  local layout = self.Window

  Pixy.Log("UIDialog: '" .. self.Window:getName() .. "' is being hidden")

  layout:setAlwaysOnTop(false)
  layout:hide()
  layout:getParent():removeChildWindow(layout)

  return self
end

function UIDialog:__resize()

  local lbl_height = tonumber(self.Label:getProperty("VertExtent"))
  local btn_height = tonumber(self.Buttons.Ok:getHeight().offset)-- * AR.Height
  self.Window:setHeight(CEGUI.UDim(0, lbl_height + btn_height + 20))
  self.Window:setWidth(CEGUI.UDim(0, self.Label:getProperty("HorzExtent") ))


end

-- detaches the sheet, destroys its windows, and removes it from the UIDialog master table
function UIDialog:destroy()
  if self:isVisible() then self:hide() end

  Pixy.Log("UIDialog: '" .. self.Window:getName() .. "' destroyed")

  Win2Dialogs[self.Window:getName()] = nil
  CEWindowMgr:destroyWindow(self.Window)
  self.Window = nil
  self.Callbacks = {}

  self = nil

  return nil
end

function UIDialog:bind(action, handler)
  table.insert(self.Callbacks[action], handler)
end

function UIDialog:unbind(action, handler)
  assert(self.Callbacks[action])
  remove_by_value(self.Callbacks[action], handler)
end


-- this is called when the Dialog is attached to this sheet
-- and its Ok button is pressed, and a callback is registered
UIDialog.onDialogOk = function(e)
  local win = CEGUI.toWindowEventArgs(e).window
  local dlg = Win2Dialogs[win:getParent():getName()]

  assert(dlg)
  for callback in list_iter(dlg.Callbacks.Ok) do
    callback(dlg)
  end

  if not dlg.KeepAlive then
    dlg:destroy()
  end

  return true
end
UIDialog.onDialogCancel = function(e)
  local win = CEGUI.toWindowEventArgs(e).window
  local dlg = Win2Dialogs[win:getParent():getName()]

  assert(dlg)
  for callback in list_iter(dlg.Callbacks.Cancel) do
    callback(dlg)
  end

  if not dlg.KeepAlive then
    dlg:destroy()
  end

  return true
end

-- aliases for the action handlers
UIDialog.onDialogYes = UIDialog.onDialogOk
UIDialog.onDialogNo = UIDialog.onDialogCancel

YesNoDialog = {}
function YesNoDialog:new(in_text, keep_hidden)
  local o = UIDialog:new(in_text, keep_hidden)

  o.Buttons.Ok:show()
  o.Buttons.Ok:setText("Yes")
  o.Buttons.Cancel:show()
  o.Buttons.Cancel:setText("No")

  -- position the Yes button next to the No one
  o.Buttons.Ok:setXPosition(CEGUI.UDim(0.695, 0))
  o.Buttons.Ok:setWidth(CEGUI.UDim(0.2, 0))
  o.Buttons.Cancel:setXPosition(CEGUI.UDim(0.9, 0))
  o.Buttons.Cancel:setWidth(CEGUI.UDim(0.1, 0))

  return o
end

OkDialog = {}
function OkDialog:new(in_text, keep_hidden)
  local o = UIDialog:new(in_text, keep_hidden)

  o.Buttons.Ok:show()
  o.Buttons.Ok:setText("Ok")
  o.Buttons.Cancel:hide()

  -- position the one button in the middle
  o.Buttons.Ok:setProperty("HorizontalAlignment", "Centre")

  return o
end
