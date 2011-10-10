Pixy.UI = {
  Attached = {}, -- a list of attached UISheets
  CurrentSheet = nil, -- points to the currently attached UISheet
  Dialog = {
    Window = nil,
    Label = nil,
    OkButton = nil,
    OkCallback = nil
  },
  Defaults = {
    Font = "DejaVuSans-10",
    MouseCursor = {
      ImageSet = "WindowsLook",
      Image = "MouseArrow"
    }
  }
}

Pixy.UI.setup = function()
  if isSetup then return true end

	-- load schemes
	CESchemeMgr:create( "TaharezLook.scheme" )
	CESchemeMgr:create( "WindowsLook.scheme" )
	CESchemeMgr:create( "VanillaSkin.scheme" )
	CESchemeMgr:create( "CombatSkin.scheme" )

	-- create our imagesets used for spell buttons
	CEImagesetMgr:create( "spells_earth.imageset" )
	CEImagesetMgr:create( "spells_fire.imageset" )
  CEImagesetMgr:create( "huds.imageset" )

	-- load a default font
  local defaults = Pixy.UI.Defaults
	CESystem:setDefaultFont( defaults.Font )
	-- set default mouse cursor
	CESystem:setDefaultMouseCursor( defaults.MouseCursor.ImageSet, defaults.MouseCursor.Image )

	-- set up the dialog
	Pixy.UI.Dialog.Window = CEWindowMgr:loadWindowLayout("overlays/dialog.layout")
	--~ Pixy.UI.Dialog.Label = Pixy.UI.Dialog.Window:getChild("Elementum/Overlays/Dialog/Label")
	Pixy.UI.Dialog.Label = Pixy.UI.Dialog.Window:getChild("Dialog_Label")
	Pixy.UI.Dialog.OkButton = Pixy.UI.Dialog.Window:getChild("Dialog_OkButton")
	Pixy.UI.Dialog.CancelButton = Pixy.UI.Dialog.Window:getChild("Dialog_CancelButton")
  Pixy.UI.Dialog.CancelButton:hide()
  Pixy.UI.Dialog.OkButton:setProperty("HorizontalAlignment", "Centre")
	Pixy.UI.Dialog.Window:hide()

  require "shared/ui/ui_sheet"
  require "shared/ui/ui_dialogs"

  isSetup = true
  return true
end

Pixy.UI.cleanup = function()
  if not isSetup then return true end

  Pixy.Log("Cleaning up all registered UI Sheets. Total = " .. #Pixy.UI.Attached)

  -- destroy all UISheets
  while #Pixy.UI.Attached > 0 do
    Pixy.UI.Attached[1]:destroy()
  end
  for sheet in list_iter(Pixy.UI.Attached) do
    sheet:destroy()
  end

  assert(#Pixy.UI.Attached == 0)

  CEWindowMgr:destroyWindow(Pixy.UI.Dialog.Window)
  Pixy.UI.Dialog = {}

  isSetup = false
  return true
end
