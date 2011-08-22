--[[
	combat: ui.lua

	cegui event handlers and UI bootstrapping goes here
]]
if (Pixy.UI.Combat == nil) then
  Pixy.UI.Combat = { Buttons = {}, LogButtons = {}, Labels = {}, Config = {}, Containers = {}}

end

Pixy.UI.Combat.configure = function()
	-- register the globals
	cfg = Pixy.UI.Combat.Config

  -- path to our layout sheet
  cfg.LayoutPath = "combat/ui.layout"

	-- spell button config
	cfg.SpellButton = {}
	cfg.SpellButton["Height"] = 96
	cfg.SpellButton["Width"] = 96
  cfg.SpellButton["Dimensions"] =
    CEGUI.UVector2:new(
      CEGUI.UDim(0.127,0),-- cfg.SpellButton["Width"]),
      CEGUI.UDim(0.6,0)-- cfg.SpellButton["Height"])
    )
  cfg.SpellButton["LogDimensions"] =
    CEGUI.UVector2:new(
      CEGUI.UDim(0.0735,0),-- cfg.SpellButton["Width"]),
      CEGUI.UDim(0.335,0)-- cfg.SpellButton["Height"])
    )

	-- create our imagesets used for spell buttons
	CEImagesetMgr:create( "spells_earth.imageset" )
	CEImagesetMgr:create( "spells_fire.imageset" )
  CEImagesetMgr:create( "huds.imageset" )

end

Pixy.UI.Combat.registerGlobals = function()
  Pixy.UI.Combat.Containers["Error"] = CEWindowMgr:getWindow("Elementum/Combat/Containers/Error")
  Pixy.UI.Combat.Containers["Tooltip"] = CEWindowMgr:getWindow("Elementum/Combat/Containers/Tooltip")
  Pixy.UI.Combat.Containers["Message"] = CEWindowMgr:getWindow("Elementum/Combat/Containers/Message")

  assert(Pixy.UI.Combat.Containers["Error"])

  Pixy.UI.Combat.Labels["Turns"] = CEWindowMgr:getWindow("Elementum/Combat/Effects/Turns/Text")
  Pixy.UI.Combat.Labels["Tooltip"] = CEWindowMgr:getWindow("Elementum/Combat/Text/Tooltip")
  Pixy.UI.Combat.Labels["Error"] = CEWindowMgr:getWindow("Elementum/Combat/Text/Error")
  Pixy.UI.Combat.Labels["PlayerWP"] = CEWindowMgr:getWindow("Elementum/Combat/Text/PlayerWP")
  Pixy.UI.Combat.Labels["EnemyWP"] = CEWindowMgr:getWindow("Elementum/Combat/Text/EnemyWP")

  UIEngine:connectAnimation(CEWindowMgr:getWindow("Elementum/Combat/Containers/Victory"), "Testing")
  UIEngine:connectAnimation(CEWindowMgr:getWindow("Elementum/Combat/Containers/Message"), "Fade")
  UIEngine:connectAnimation(CEWindowMgr:getWindow("Elementum/Combat/Containers/Error"), "LongFadeOut")

end

-- effectively reloads the UI components and sheets
-- NOTE: this destroys all currently drawn spell buttons too!
Pixy.UI.Combat.reload = function()
	CEWindowMgr:destroyWindow(CEWindowMgr:getWindow("Elementum/Combat"))

	local lLayout = CEWindowMgr:loadWindowLayout(Pixy.UI.Combat.Config.LayoutPath)
	lLayout:setAlwaysOnTop(true)
	CESystem:setGUISheet(lLayout)

	-- TODO repopulate puppet hand after reloading ui
end

firstButton = true

function foobar()
  Pixy.Log("Animation has stopped")
end

-- draws a CEGUI::ImageButton element representing the given spell
-- and attaches it to the Puppet's hand
Pixy.UI.Combat.drawSpell = function(inSpell)

	local lButton = {}

  local margin = 5
    if (firstButton) then margin = 0; firstButton = false end

	-- calculate position
	lButton["Position"] =
		CEGUI.UVector2:new(
			--CEGUI.UDim(0, cfg.SpellButton["Width"] * (SelfPuppet:nrSpellsInHand() - 2) + (margin*SelfPuppet:nrSpellsInHand())),
      CEGUI.UDim(0, cfg.SpellButton["Width"] * (SelfPuppet:nrSpellsInHand() - 2)),
			CEGUI.UDim(0, 0)
		)

	-- assign dimensions
	lButton["Dimensions"] =
		CEGUI.UVector2:new(
			CEGUI.UDim(0.147,0),-- cfg.SpellButton["Width"]),
			CEGUI.UDim(0.67,0)-- cfg.SpellButton["Height"])
		)

	-- generate the button's name
	lButton["Name"] = "Elementum/Combat/SpellPanel/Player/" .. inSpell:getUID()

	Pixy.Log("creating a window named " .. lButton["Name"])

	-- create the actual button element
  --local list_item = CEWindowMgr:createWindow("TaharezLook/ListboxItem", lButton["Name"] .. "/ListItem")
	lButton["Window"] = CEWindowMgr:createWindow("TaharezLook/ImageButton", lButton["Name"])
  --list_item:addChildWindow(lButton["Window"])

	-- attach the button to the Pixy::Spell object
	inSpell:setButton(lButton["Window"])
  inSpell:setImageSet("Spells_" .. raceToString(inSpell:getRace()))
  -- sanitize spell name to match image set name
  local sane_name = string.gsub(inSpell:getName(), "%s", "_")
  inSpell:setImageName(sane_name)

  -- get spell properties
  --local lAspect = aspectToString(inSpell:getAspect())
  --local lRace = raceToString(inSpell:getRace())
  --local lSpellData = Pixy.Spells[lRace][lAspect][inSpell:getName()]
  --local lSpellData = Pixy.Spells.Earth.Matter["Summon: Fetish Zij"]
	-- draw the image button
	lButton["Image"] = "set:" .. inSpell:getImageSet() .. " image:" .. inSpell:getImageName()
	lButton["Window"]:setProperty("NormalImage", lButton["Image"] .. "_Normal")
	lButton["Window"]:setProperty("HoverImage", lButton["Image"] .. "_Hover")
	lButton["Window"]:setProperty("PushedImage", lButton["Image"] .. "_Pushed")
	lButton["Window"]:setProperty("DisabledImage", lButton["Image"] .. "_Disabled")
  lButton["Window"]:setProperty("Alpha", "0.0")

	-- attach our spell object to the button...
	lButton["Window"]:setUserString("Spell", inSpell:getUID())

	-- create tooltip
  --lButton["Window"]:setTooltipText(inSpell:getTooltip())
	-- ...

	-- attach the window to our layout
	CEWindowMgr:getWindow("Elementum/Combat/SpellPanel/Player/Hand"):addChildWindow(lButton["Window"])

  --local item = lButton["Window"]
	--CEGUI.toItemEntry(list_item)
  --local list = CEWindowMgr:getWindow("Elementum/Combat/SpellPanel/Player/Hand")
  --CEGUI.toListbox(list)
  --list:addItem(list_item)
	lButton["Window"]:setSize(lButton["Dimensions"])
  UIEngine:setMargin(lButton["Window"],
    CEGUI.UBox(
      CEGUI.UDim(0,0),
      CEGUI.UDim(0,0),
      CEGUI.UDim(0,0),
      CEGUI.UDim(0,5)))
  --list_item:setSize(lButton["Dimensions"])
	--lButton["Window"]:setPosition(lButton["Position"])

  -- finally, subscribe the button to its event handlers
  --lButton["Window"]:subscribeEvent("Shown", "Pixy.UI.Combat.DrawSpell")
	lButton["Window"]:subscribeEvent("Clicked", "Pixy.Combat.reqCastSpell")
  lButton["Window"]:subscribeEvent("MouseEnter", "Pixy.UI.Combat.ShowTooltip")
  lButton["Window"]:subscribeEvent("MouseLeave", "Pixy.UI.Combat.HideTooltip")
  lButton["Window"]:subscribeEvent("AlphaChanged", "Pixy.UI.Combat.RemoveSpell")
  --lButton["Window"]:subscribeEvent("Clicked", "Pixy.UI.Combat.castSpellAnimation")

  lButton["Window"]:moveToFront()
	lButton["Window"]:show()

  local instance = CEGUI.AnimationManager:getSingleton():instantiateAnimation("DrawSpell")
  instance:setTargetWindow(inSpell:getButton())
  if (not instance:isRunning()) then instance:start() end

  --table.insert(Pixy.UI.Combat.Buttons, inSpell:getButton())
end


Pixy.UI.Combat.dropSpell = function(inSpell)
  Pixy.UI.Combat.HideTooltip(nil)
  --removeByValue(Pixy.UI.Combat.Buttons, inSpell:getButton())
  local instance = CEGUI.AnimationManager:getSingleton():instantiateAnimation("DropSpell")
  instance:setTargetWindow(inSpell:getButton())
  if (not instance:isRunning()) then instance:start() end

  inSpell:getButton():removeEvent("Clicked")
  inSpell:getButton():removeEvent("MouseEnter")
  inSpell:getButton():removeEvent("MouseLeave")
  --CEWindowMgr:destroyWindow(inSpell:getButton())
  --for button in list_iter(Pixy.UI.Combat.Buttons) do
  --  local pos = CEGUI.UVector2:new(
  --  	CEGUI.UDim(0, button:getPosition().x.offset - cfg.SpellButton["Width"]),
	--		button:getPosition().y)
  --
  --  button:setPosition(pos)
  --end
end

Pixy.UI.Combat.RemoveSpell = function(e)
  local win = CEGUI.toWindowEventArgs(e).window
  if (win and tonumber(win:getProperty("Alpha")) == 0) then
    --~ win:removeEvent("AlphaChanged")
    CEWindowMgr:destroyWindow(win)
  end
end

Pixy.UI.Combat.onStartTurn = function()
  CEWindowMgr:getWindow("Elementum/Combat/Containers/Message"):hide()
  CEWindowMgr:getWindow("Elementum/Combat/Text/Message"):setText("Attacking Phase")
  CEWindowMgr:getWindow("Elementum/Combat/Containers/Message"):show()

  Pixy.UI.Combat.Labels["Turns"]:setText("Your turn")

  CEWindowMgr:getWindow("Elementum/Combat/SpellPanel/Player/Hand"):enable()
  --for button in list_iter(Pixy.UI.Combat.Buttons) do
  --  button:enable()
  --end

end

Pixy.UI.Combat.onTurnStarted = function()
  CEWindowMgr:getWindow("Elementum/Combat/Containers/Message"):hide()
  CEWindowMgr:getWindow("Elementum/Combat/Text/Message"):setText("Waiting")
  CEWindowMgr:getWindow("Elementum/Combat/Containers/Message"):show()

  Pixy.UI.Combat.Labels["Turns"]:setText("Enemy's turn")

  CEWindowMgr:getWindow("Elementum/Combat/SpellPanel/Player/Hand"):disable()
  --for button in list_iter(Pixy.UI.Combat.Buttons) do
  --  button:disable()
  --end
end

Pixy.UI.Combat.onStartBlockPhase = function()
  CEWindowMgr:getWindow("Elementum/Combat/Containers/Message"):hide()
  CEWindowMgr:getWindow("Elementum/Combat/Text/Message"):setText("Blocking Phase")
  CEWindowMgr:getWindow("Elementum/Combat/Containers/Message"):show()

  Pixy.UI.Combat.Labels["Turns"]:setText("Blocking Phase")
end

Pixy.UI.Combat.onMatchFinished = function(wuid)
  local suid = tonumber(SelfPuppet:getUID())
  Pixy.Log("Winner's UID : " .. wuid .. " mine: " .. suid)
  UIEngine:connectAnimation(CEWindowMgr:getWindow("Elementum/Combat/Containers/Message"), "LongFade")
  if (wuid == suid) then
    CEWindowMgr:getWindow("Elementum/Combat/Containers/Message"):hide()
    CEWindowMgr:getWindow("Elementum/Combat/Text/Message"):setText("Victory")
    CEWindowMgr:getWindow("Elementum/Combat/Containers/Message"):show()

    Pixy.UI.Combat.Labels["Turns"]:setText("")
  else
    CEWindowMgr:getWindow("Elementum/Combat/Containers/Message"):hide()
    CEWindowMgr:getWindow("Elementum/Combat/Text/Message"):setText("Loss")
    CEWindowMgr:getWindow("Elementum/Combat/Containers/Message"):show()

    Pixy.UI.Combat.Labels["Turns"]:setText("")
  end
end

Pixy.UI.Combat.ShowTooltip = function(e)
	local win = CEGUI.toWindowEventArgs(e).window
	local spell = SelfPuppet:getSpell(win:getUserString("Spell"))
  assert(spell)

  Pixy.UI.Combat.Containers["Tooltip"]:show()
  local label = Pixy.UI.Combat.Labels["Tooltip"]
  label:setText(spell:getTooltip())
  --UIEngine:refreshTooltipSize(win, spell)

  --~ label:setSize(
    --~ CEGUI.UVector2:new(
      --~ CEGUI.UDim(0, label:getHorizontalTextExtent()),
      --~ CEGUI.UDim(0, label:getVerticalTextExtent())))
end
Pixy.UI.Combat.HideTooltip = function(e)
  Pixy.UI.Combat.Labels["Tooltip"]:setText("")
  Pixy.UI.Combat.Containers["Tooltip"]:hide()
end

Pixy.UI.Combat.ShowError = function(txt)
  Pixy.UI.Combat.Containers["Error"]:hide()
  Pixy.UI.Combat.Labels["Error"]:setText(txt)
  Pixy.UI.Combat.Containers["Error"]:show()
end

Pixy.UI.Combat.UpdatePuppet = function(puppet)
  if (puppet == SelfPuppet) then
    Pixy.UI.Combat.Labels["PlayerWP"]:setText(puppet:getWP())
  else
    Pixy.UI.Combat.Labels["EnemyWP"]:setText(puppet:getWP())
  end
end

Pixy.UI.Combat.LogSpellCast = function(inSpell,caster_is_self)
  local target = ""
  if (caster_is_self) then target = "Player" else target = "Enemy" end
  Pixy.Log("Spell's log target : " .. target)
  local name = "Elementum/Combat/SpellLog/" .. target .. "/" .. inSpell:getUID() .. "_log"
  local win = CEWindowMgr:createWindow("TaharezLook/ImageButton", name)
  CEWindowMgr:getWindow("Elementum/Combat/Containers/SpellLog/" .. target):addChildWindow(win)

  -- sanitize spell name to match image set name
  local image_set = "Spells_" .. raceToString(inSpell:getRace())
  local image_name = string.gsub(inSpell:getName(), "%s", "_")

	local image = "set:" .. image_set .. " image:" .. image_name
	win:setProperty("NormalImage",   image .. "_Normal")
	win:setProperty("HoverImage",    image .. "_Hover")
	win:setProperty("PushedImage",   image .. "_Pushed")
	win:setProperty("DisabledImage", image .. "_Disabled")
  win:setUserString("Tooltip", inSpell:getTooltip())
	win:setSize(Pixy.UI.Combat.Config.SpellButton["LogDimensions"])
  UIEngine:setMargin(win,
    CEGUI.UBox(
      CEGUI.UDim(0,5),
      CEGUI.UDim(0,5),
      CEGUI.UDim(0,0),
      CEGUI.UDim(0,5)))

  win:moveToFront()
  win:show()

  win:subscribeEvent("MouseEnter", "Pixy.UI.Combat.ShowLogTooltip")
  win:subscribeEvent("MouseLeave", "Pixy.UI.Combat.HideLogTooltip")

  table.insert(Pixy.UI.Combat.LogButtons, win:getName())

  Pixy.Log("Logged Spell cast ! " .. inSpell:getName() .. inSpell:getUID())
end

Pixy.UI.Combat.ClearSpellLog = function()
  if next(Pixy.UI.Combat.LogButtons) == nil then
     return
  end
  Pixy.Log("Clearing spell log")
  for win in list_iter(Pixy.UI.Combat.LogButtons) do
    Pixy.Log("removing spell log button named: " .. win)
    CEWindowMgr:destroyWindow(win)
  end
  Pixy.Log("Cleared")
end

Pixy.UI.Combat.ShowLogTooltip = function(e)
  local win = CEGUI.toWindowEventArgs(e).window
  local tt = win:getUserString("Tooltip")

  Pixy.UI.Combat.Containers["Tooltip"]:show()
  local label = Pixy.UI.Combat.Labels["Tooltip"]
  label:setText(tt)
end
Pixy.UI.Combat.HideLogTooltip = function(e)
  Pixy.UI.Combat.Containers["Tooltip"]:hide()
  local label = Pixy.UI.Combat.Labels["Tooltip"]
  label:setText("")
end

-- configure
Pixy.UI.Combat.configure()
