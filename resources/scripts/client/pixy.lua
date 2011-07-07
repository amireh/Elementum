require("processor")
setupEvtMap()

local attached = {} -- tracks all attached layouts
Pixy.UI = {}

PBox, PBox_Label, regularizer, loadingText = nil, nil, 0, ""
Pixy.registerGlobals = function()

  if (Pixy.Launched) then return true end

	Pixy.Log( "*************************************************")
	Pixy.Log( "* Launching Pixy Lua module!                    *")

	-- registers CEGUI singletons as globals for use by the UI sheets

	CELogger = CEGUI.Logger:getSingleton()
	CELogger:logEvent( ">>> Pixy LUA scripts engaging" )
	--CELogger:setLoggingLevel( CEGUI.Informative )

	-- get a local reference to the singletons we use (not required)
	CESystem    = CEGUI.System:getSingleton()
	CEWindowMgr = CEGUI.WindowManager:getSingleton()
	CEFontMgr   = CEGUI.FontManager:getSingleton()
	CESchemeMgr = CEGUI.SchemeManager:getSingleton()
	CEImagesetMgr = CEGUI.ImagesetManager:getSingleton()

	-- load schemes
	CESchemeMgr:create( "TaharezLook.scheme" )
	CESchemeMgr:create( "WindowsLook.scheme" )
	CESchemeMgr:create( "VanillaSkin.scheme" )

	-- load a default font
	CESystem:setDefaultFont( "DejaVuSans-10" )
	-- set default mouse cursor
	CESystem:setDefaultMouseCursor( "WindowsLook","MouseArrow" )

	EvtMgr = Pixy.EventManager:getSingletonPtr()
	GameMgr = Pixy.GameManager:getSingleton()
  NetMgr = Pixy.NetworkManager:getSingleton()
	--if (state == "Intro") then
		--Intro = Pixy.Intro:getSingletonPtr()
	--elseif (state == "Combat") then
		Puppet, EnemyPuppet, Active, Waiting = nil
		Combat = Pixy.Combat:getSingletonPtr()
		--PuppetFactory = Pixy.CPuppetFactory:getSingletonPtr()
		--UnitFactory = Pixy.CUnitFactory:getSingletonPtr()
		GfxEngine = Pixy.GfxEngine:getSingletonPtr()
		Pixy.Combat = {}
	--end
	--Pixy.Log("* State: " .. state)

  Puppets = {}
  SelfPuppet = nil
  Active = nil

	-- progress box , used for loading
	PBox = Pixy.UI.attachOverlay("ProgressBox")
	PBox_Label = PBox:getChild("Elementum/Overlays/ProgressBox/Label")
	regularizer = 0
	PBox:hide()

	Pixy.Log( "* Launched successfully!                        *")
	Pixy.Log( "*************************************************")

  Pixy.Log("Test: EventUID::Connected => " .. Pixy.EventUID.Connected)

	Pixy.Launched = true

end

Pixy.UI.attach = function(inWindow)
	Pixy.Log("attaching window '" .. inWindow .. "'")
	-- remove current layout if exists
	if (not attached[inWindow]) then
		Pixy.Log("window is not loaded, loading...")
		-- load layout
		attached[inWindow] = CEWindowMgr:loadWindowLayout(inWindow)
 		--CEWindowMgr:destroyWindow(attached[inWindow])
	end

	-- attach layout
	attached[inWindow]:setAlwaysOnTop(true)
	CESystem:setGUISheet(attached[inWindow])
	return attached[inWindow]
end

Pixy.UI.attachOverlay = function(inWindow)
	local _window
	if (inWindow == "ProgressBox") then
		-- check if window present then retrieve its handle
		-- otherwise, create it
		_window = (CEWindowMgr:isWindowPresent("Elementum/Overlays/ProgressBox"))
							and CEWindowMgr:getWindow("Elementum/Overlays/ProgressBox")
							or	CEWindowMgr:loadWindowLayout("overlays/progress_box.layout")
		return _window
	end
end

Pixy.UI.showLoadingBox = function()
	regularizer = regularizer + 1
	if (not (regularizer % 90 == 0)) then return true else regularizer = 0 end
	local text = PBox_Label:getText()

	-- "Loading Profiles"
	if (string.len(string.sub(text, 16)) > 10) then
		text = loadingText
	else
		text = text .. "."
	end

	PBox_Label:setText(text)
end

Pixy.UI.waiting = function(inText, inLayout)

	loadingText = inText
	inLayout:addChildWindow(PBox)
	PBox_Label:setText(loadingText)
	PBox:show()

	doUpdateMe(Pixy.UI.showLoadingBox)
end

Pixy.UI.doneWaiting = function(keep_box)
	if (not keep_box or keep_box == false) then PBox:hide() end
	dontUpdateMe(Pixy.UI.showLoadingBox)
end


function arbitraryFunc(name, argc, ...)
  Pixy.Combat[name](unpack(arg))
end
