--[[
	combat: ui.lua

	cegui event handlers and UI bootstrapping goes here
]]
Pixy.UI.Combat = {}
local cfg = nil

Pixy.UI.Combat.configure = function()
	-- register the globals
	Pixy.UI.Combat.Config = {}

	cfg = Pixy.UI.Combat.Config

	-- path to our layout sheet
	cfg.LayoutPath = "combat/ui.layout"

	-- spell button config
	cfg.SpellButton = {}
	cfg.SpellButton["Height"] = 48
	cfg.SpellButton["Width"] = 48

	-- create our imagesets used for spell buttons
	CEImagesetMgr:create( "Spells-Earth.imageset" )
end

-- effectively reloads the UI components and sheets
-- NOTE: this destroys all currently drawn spell buttons too!
Pixy.UI.Combat.reload = function()
	CEWindowMgr:destroyWindow(CEWindowMgr:getWindow("Elementum/Scenes/Combat"))

	local lLayout = CEWindowMgr:loadWindowLayout(Pixy.UI.Combat.Config.LayoutPath)
	lLayout:setAlwaysOnTop(true)
	CESystem:setGUISheet(lLayout)

	-- TODO repopulate puppet hand after reloading ui
end

-- draws a CEGUI::ImageButton element representing the given spell
-- and attaches it to the Puppet's hand
Pixy.UI.Combat.drawSpell = function(inSpell)

	local lButton = {}

	-- calculate position
	lButton["Position"] =
		CEGUI.UVector2:new(
			CEGUI.UDim(0, cfg.SpellButton["Width"] * SelfPuppet:nrSpellsInHand() - 2),
			CEGUI.UDim(0, 0)
		)

	-- assign dimensions
	lButton["Dimensions"] =
		CEGUI.UVector2:new(
			CEGUI.UDim(0, cfg.SpellButton["Width"]),
			CEGUI.UDim(0, cfg.SpellButton["Height"])
		)

	-- generate the button's name
	lButton["Name"] = "Elementum/Scenes/Combat/SpellPanel/Player/" .. inSpell:getUID()

	Pixy.Log("creating a window named " .. lButton["Name"])

	-- create the actual button element
	lButton["Window"] = CEWindowMgr:createWindow("TaharezLook/ImageButton", lButton["Name"])

	-- attach the button to the Pixy::Spell object
	inSpell:setButton(lButton["Window"])
  inSpell:setImageSet("Spells-" .. raceToString(inSpell:getRace()))
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

	-- attach our spell object to the button...
	lButton["Window"]:setUserString("Spell", inSpell:getUID())

	-- create tooltip
	-- ...

	-- attach the window to our layout
	CEWindowMgr:getWindow("Elementum/Scenes/Combat/SpellPanel/Player"):addChildWindow(lButton["Window"])
	lButton["Window"]:setSize(lButton["Dimensions"])
	lButton["Window"]:setPosition(lButton["Position"])
	lButton["Window"]:moveToFront()
	lButton["Window"]:show()

	-- finally, subscribe the button to its event handlers
	lButton["Window"]:subscribeEvent("Clicked", "Pixy.Combat.reqCastSpell")

end

-- configure
Pixy.UI.Combat.configure()
