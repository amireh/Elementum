local attached = Pixy.UI.Attached

-- UI Sheets --
-- UI.Sheet provides necessary and convenience functions for attaching
-- and detaching CEGUI layout windows

UISheet = {}

--[[
  @brief
    constructs a new UI.Sheet object
  @arg
    path_to_layout: relative path to layout file with extension
  @return
    newly created UI.Sheet object pointing to the given layout
]]
function UISheet:new(path_to_layout, o)
  local o = o or {}
  o.Path = path_to_layout
  o.Window = nil
  --~ o.Callbacks = {}

  setmetatable(o, {__index = self})
  self.__index = self

  Pixy.Log("UISheet: '" .. o.Path .. "' created")

  return o
end

function UISheet:load()
	if not self:isLoaded() then
		-- load layout
    self.Window = CEGUI.toGUISheet(CEWindowMgr:loadWindowLayout(self.Path))
    -- track this sheet in the master sheet table
    table.insert(attached, self)
	end
end

function UISheet:isLoaded()
  return self.Window
end

function UISheet:attach()
	Pixy.Log("UISheet: '" .. self.Path .. "' attached")

  if not self:isLoaded() then self:load() end

	-- attach layout
  local layout = self.Window
	layout:setAlwaysOnTop(true)
	layout:show()
	CESystem:setGUISheet(layout)

  -- register this UISheet as the currently attached one
  Pixy.UI.CurrentSheet = self

	return self
end

function UISheet:isAttached()
  return
    (self.Window and
    self.Window == CESystem:getGUISheet()) or
    (Pixy.UI.CurrentSheet and
    Pixy.UI.CurrentSheet.Path == self.Path)
end

function UISheet:detach()
  local layout = self.Window

  if not layout then return true end

  --~ if UISheet.isDialogShown() then
    UISheet.hideDialog()
  --~ end

  -- unregister this UISheet from being the current one if it is
  if self:isAttached() then
    CESystem:setGUISheet(nil)
    Pixy.UI.CurrentSheet = nil
  end

  layout:setAlwaysOnTop(false)
  layout:hide()

  Pixy.Log("UISheet: '" .. self.Path .. "' detached")

  return self
end

-- detaches the sheet, destroys its windows, and removes it from the UISheet master table
function UISheet:destroy()
  if self:isAttached() then self:detach() end

  -- detach the dialog if it's attached to any window
  local layout = Pixy.UI.Dialog.Window:getParent()
  if layout then
    layout:removeChildWindow(Pixy.UI.Dialog.Window)
  end

  if self.Window then
    CEWindowMgr:destroyWindow(self.Window)
    self.Window = nil
  end
  remove_by_value(attached, self)

  Pixy.Log("UISheet: '" .. self.Path .. "' destroyed")
  self = nil

  return nil
end

-- this is called when the Dialog is attached to this sheet
-- and its Ok button is pressed, and a callback is registered
function UISheet.onDialogOk()
  local dialog = Pixy.UI.Dialog
  -- call the registered handler
  --~ self.Callbacks.DialogOk()
  -- remove the subscription
  --~ dialog.OkButton:removeEvent("Clicked")

  --~ self.Callbacks.DialogOk = nil
  --~ self:hideDialog()
  UISheet.hideDialog()

  dialog.OkCallback()
  dialog.OkCallback = nil

  return true
end

-- displays a dialog box showing a message and optionally taking a callback
-- that will be called when the dialog is closed
function UISheet.showDialog(text, callback)
  local dialog = Pixy.UI.Dialog
  local self = Pixy.UI.CurrentSheet
  local layout = self.Window

  if dialog.Window:getParent() and dialog.Window:getParent() ~= layout then
    UISheet.hideDialog(nil)
  end

  layout:addChildWindow(dialog.Window)
  dialog.Window:show()
  if text then
    local lbl = dialog.Label
    lbl:setText(text)
    -- resize the dialog to reflect the new text size
    local lbl_height = tonumber(lbl:getProperty("VertExtent"))
    local btn_height = tonumber(dialog.OkButton:getHeight().offset)-- * AR.Height
    dialog.Window:setHeight(CEGUI.UDim(0, lbl_height + btn_height + 20))
    --~ dialog.Window:setPosition(
      --~ CEGUI.UVector2(
        --~ lbl:getPosition().x,
        --~ CEGUI.UDim(0.05, dialog.Window:getHeight().offset)))
  end

  dialog.OkButton:removeEvent("Clicked")

  if callback then
    -- call the registered handler when the Ok button is pressed
    --~ self.Callbacks.DialogOk = callback
    dialog.OkCallback = callback
    dialog.OkButton:subscribeEvent("Clicked", self.onDialogOk)
  else
    -- hide the dialog when the Ok button is pressed
    --~ self.Callbacks.DialogOk = nil
    dialog.OkCallback = nil
    dialog.OkButton:subscribeEvent("Clicked", UISheet.hideDialog)
  end

  return self
end

function UISheet.isDialogShown()
  return Pixy.UI.Dialog.Window and Pixy.UI.Dialog.Window:isVisible() and Pixy.UI.Dialog.Window:getParent()
end

function UISheet.hideDialog(e)
  if not UISheet.isDialogShown() then return true end

  local dialog = Pixy.UI.Dialog
  local layout = dialog.Window:getParent()
  print(dialog.Window:getName())
  layout:removeChildWindow(dialog.Window)
  dialog.Window:hide()

  return true
end
