--[[
	combat: ui.lua

	cegui event handlers and UI bootstrapping goes here
]]

local MyHand = {}
local inBlockPhase = false

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
      CEGUI.UDim(0.15,0),-- cfg.SpellButton["Width"]),
      CEGUI.UDim(1,0)-- cfg.SpellButton["Height"])
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

local Hand = nil
Pixy.UI.Combat.registerGlobals = function()
  Pixy.UI.Combat.Containers["Error"] = CEWindowMgr:getWindow("Elementum/Combat/Containers/Error")
  Pixy.UI.Combat.Containers["Tooltip"] = CEWindowMgr:getWindow("Elementum/Combat/Containers/Tooltip")
  Pixy.UI.Combat.Containers["Message"] = CEWindowMgr:getWindow("Elementum/Combat/Containers/Message")

  assert(Pixy.UI.Combat.Containers["Error"])

  Pixy.UI.Combat.Labels["Turns"] = CEWindowMgr:getWindow("Elementum/Combat/Effects/Turns/Text")
  Pixy.UI.Combat.Labels["Tooltip"] = CEWindowMgr:getWindow("Elementum/Combat/Text/Tooltip")
  Pixy.UI.Combat.Labels["Error"] = CEWindowMgr:getWindow("Elementum/Combat/Text/Error")
  Pixy.UI.Combat.Labels["PlayerWP"] = CEWindowMgr:getWindow("Combat/Text/Player/Willpower")
  Pixy.UI.Combat.Labels["PlayerHP"] = CEWindowMgr:getWindow("Combat/Text/Player/Health")
  Pixy.UI.Combat.Labels["PlayerC"] = CEWindowMgr:getWindow("Combat/Text/Player/Channels")
  Pixy.UI.Combat.Labels["EnemyWP"] = CEWindowMgr:getWindow("Combat/Text/Enemy/Willpower")
  Pixy.UI.Combat.Labels["EnemyHP"] = CEWindowMgr:getWindow("Combat/Text/Enemy/Health")
  Pixy.UI.Combat.Labels["EnemyC"] = CEWindowMgr:getWindow("Combat/Text/Enemy/Channels")
  Hand = CEWindowMgr:getWindow("Combat/Hand")

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
	--~ lButton["Dimensions"] =
		--~ CEGUI.UVector2:new(
			--~ CEGUI.UDim(0.147,0),-- cfg.SpellButton["Width"]),
			--~ CEGUI.UDim(0.67,0)-- cfg.SpellButton["Height"])
		--~ )

	-- generate the button's name
	lButton["Name"] = "SpellButton_" .. inSpell:getUID()

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
  lButton["Window"]:setProperty("MousePassThroughEnabled", "False")
  lButton["Window"]:setProperty("AlwaysOnTop", "True")

	-- attach our spell object to the button...
	lButton["Window"]:setUserString("Spell", inSpell:getUID())

	-- create tooltip
  --lButton["Window"]:setTooltipText(inSpell:getTooltip())
	-- ...

	-- attach the window to our layout
	Hand:addChildWindow(lButton["Window"])

  --local item = lButton["Window"]
	--CEGUI.toItemEntry(list_item)
  --local list = CEWindowMgr:getWindow("Elementum/Combat/SpellPanel/Player/Hand")
  --CEGUI.toListbox(list)
  --list:addItem(list_item)
	lButton["Window"]:setSize(cfg.SpellButton["Dimensions"])
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
	lButton["Window"]:subscribeEvent("Clicked", "Combat.reqCastSpell")
  lButton["Window"]:subscribeEvent("MouseEnter", "Pixy.UI.Combat.ShowTooltip")
  lButton["Window"]:subscribeEvent("MouseLeave", "Pixy.UI.Combat.HideTooltip")
  lButton["Window"]:subscribeEvent("AlphaChanged", "Pixy.UI.Combat.RemoveSpell")
  --lButton["Window"]:subscribeEvent("Clicked", "Pixy.UI.Combat.castSpellAnimation")

  lButton["Window"]:moveToFront()
	lButton["Window"]:show()

  local instance = CEGUI.AnimationManager:getSingleton():instantiateAnimation("DrawSpell")
  instance:setTargetWindow(inSpell:getButton())
  if (not instance:isRunning()) then instance:start() end

  table.insert(MyHand, inSpell)
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

  removeByValue(MyHand, inSpell)
  --[[local idx = 0
  for spell in list_iter(MyHand) do
    if spell:getButton() == win then
      Pixy.Log("----- REMOVING SPELL " .. spell:getName() .. " FROM HAND -----")
      table.remove(MyHand, idx)
      break
    end
    idx = idx+1
  end]]

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

local ShowBigMessage = function(txt)
  CEWindowMgr:getWindow("Elementum/Combat/Containers/Message"):hide()
  CEWindowMgr:getWindow("Elementum/Combat/Text/Message"):setText(txt)
  CEWindowMgr:getWindow("Elementum/Combat/Containers/Message"):show()
end

Pixy.UI.Combat.onStartTurn = function()
  ShowBigMessage("Attacking Phase")

  inBlockPhase = false
  Pixy.UI.Combat.Labels["Turns"]:setText("Your turn")

  Hand:enable()
  --for button in list_iter(Pixy.UI.Combat.Buttons) do
  --  button:enable()
  --end

end

Pixy.UI.Combat.onTurnStarted = function()
  ShowBigMessage("Waiting")
  inBlockPhase = true
  Pixy.UI.Combat.Labels["Turns"]:setText("Enemy's turn")

  Hand:disable()
  --for button in list_iter(Pixy.UI.Combat.Buttons) do
  --  button:disable()
  --end
end

Pixy.UI.Combat.onStartBlockPhase = function()
  ShowBigMessage("Blocking Phase")
  Pixy.UI.Combat.Labels["Turns"]:setText("Blocking Phase")
end

Pixy.UI.Combat.onMatchFinished = function(wuid)
  local suid = tonumber(SelfPuppet:getUID())
  Pixy.Log("Winner's UID : " .. wuid .. " mine: " .. suid)
  UIEngine:connectAnimation(CEWindowMgr:getWindow("Elementum/Combat/Containers/Message"), "LongFade")
  if (wuid == suid) then
    ShowBigMessage("Victory")
    Pixy.UI.Combat.Labels["Turns"]:setText("")
  else
    ShowBigMessage("Loss")
    Pixy.UI.Combat.Labels["Turns"]:setText("")
  end
end

Pixy.UI.Combat.ShowTooltip = function(e)
	local win = CEGUI.toWindowEventArgs(e).window
  assert(win)
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
    Pixy.UI.Combat.Labels["PlayerC"]:setText(puppet:getChannels())
    Pixy.UI.Combat.Labels["PlayerHP"]:setText(puppet:getHP())
  else
    Pixy.UI.Combat.Labels["EnemyWP"]:setText(puppet:getWP())
    Pixy.UI.Combat.Labels["EnemyC"]:setText(puppet:getChannels())
    Pixy.UI.Combat.Labels["EnemyHP"]:setText(puppet:getHP())
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

local InvalidActions = {
  Block = {
    BlockerResting = "Selected unit is resting!",
    AttackerUnblockable = "Target is unblockable.",
    InvalidTarget = "You can not block that target."
  },
  Charge = {
    AttackerRestless = "Target is restless!",
    AttackerHasNoAP = "Target has no attack power!"
  }
}
Pixy.UI.Combat.onInvalidAction = function(e)
  Pixy.UI.Combat.ShowError(InvalidActions[e:getProperty("Action")][e:getProperty("Reason")])
end


-- configure
Pixy.UI.Combat.configure()

local last_scrolling_text_idx = 0
ShowScrollingMessage = function(txt, good, rnd)
  local pos = nil
  if rnd == nil then
    pos = { x = "0.5", y = "0.5" }
  else
    pos = GfxEngine:getScreenCoords(rnd:getSceneObject())
  end

  last_scrolling_text_idx = last_scrolling_text_idx + 1
  local win = CEWindowMgr:createWindow("TaharezLook/StaticText", "Elementum/Combat/Temp/ScrollingText" .. last_scrolling_text_idx)
  CEWindowMgr:getWindow("Elementum/Combat"):addChildWindow(win)
  win:setProperty("UnifiedXPosition", "{" .. pos.x .. ",0}")
  win:setProperty("UnifiedYPosition", "{" .. pos.y .. ",0}")
  win:setProperty("UnifiedHeight", "{0,50}")
  win:setProperty("Font", "Scrolling_Text")
  if good then
    win:setProperty("TextColours", "tl:FF6bcf00 tr:FF6bcf00 bl:FF6bcf00 br:FF6bcf00")
  else
    win:setProperty("TextColours", "tl:FFFF0000 tr:FF8f0000 bl:FF8f0000 br:FF8f1e00")
  end
  --~ win:setProperty("UnifiedWidth", "{1,0}")
  --~ win:setProperty("HorzFormatting", "WordWrapLeftAligned")
  --~ win:setProperty("VertFormatting", "TopAligned")
  --~ win:setProperty("VerticalAlignment", "Centre")

  --~ win:setProperty("HorizontalAlignment", "Centre")
  win:setProperty("Text", txt)

  local anim = "ScrollUpLeft"
  if (last_scrolling_text_idx % 2 == 0) then anim = "ScrollUpLeft" else anim = "ScrollUpRight" end
  local instance = CEGUI.AnimationManager:getSingleton():instantiateAnimation(anim)
  instance:setTargetWindow(win)
  if (not instance:isRunning()) then instance:start() end

  win:subscribeEvent("AlphaChanged", "Pixy.UI.Combat.RemoveSpell")
end

Combat.onKeyReleased = function()
  --ShowScrollingMessage("foobar")
  if (Selected) then
    local pos = GfxEngine:getScreenCoords(Selected:getSceneObject())
    Pixy.Log(pos.x)
    ShowScrollingMessage("foobar this is a very long scrolling combat message", true, Selected)
  end
end

Pixy.UI.Combat.onStatChange = function(e)
  rnd = tolua.cast(e.Any, "Pixy::Renderable")
  if (e:getProperty("Stat") == "HP") then
    local amount = tonumber(e:getProperty("Value"))
    if amount > 0 then _mod = "+" else _mod = "" end
    ShowScrollingMessage(_mod .. amount .. " health", amount > 0, rnd)
  end
end

Pixy.UI.Combat.onEntityAttacked = function(e)
  rnd = tolua.cast(e.Any, "Pixy::Renderable")
  local damage = tonumber(e:getProperty("Damage"))
  if damage > 0 then
    ShowScrollingMessage("-" .. damage .. " health", false --[[ negative scrolling message ]], rnd)
  end
end

Pixy.UI.Combat.onLifetap = function(e)
  rnd = tolua.cast(e.Any, "Pixy::Renderable")
  local damage = tonumber(e:getProperty("Damage"))
  if damage > 0 then
    ShowScrollingMessage("+" .. damage .. " health (LIFETAP)", true --[[ good scrolling message ]], rnd)
  end
end

Pixy.UI.Combat.onFirstStrike = function(e)
  ShowBigMessage("FIRST STRIKE!")
end

Pixy.UI.Combat.onTrample = function(e)
  ShowBigMessage("TRAMPLE!")
end


local function prereqs_met(spell)
  if ((spell:requiresTarget() or spell:requiresEnemyTarget()) and Selected == nil) then
    Pixy.Log("-=-= spell requires a target, none is selected")
    return false
  end
  if (spell:requiresEnemyTarget()
    and
    Selected:getEntity():getOwner():getUID() == SelfPuppet:getUID())
  then
    return false
  end


  local caster = spell:getCaster():getEntity()

  if (caster:getRank() == Pixy.PUPPET) then
    if (caster:getWP() < spell:getCostWP()) then
      --~ Pixy.Log("-=-= caster doesn't have enough WP")
      return false
    end
    if (caster:getChannels() < spell:getCostChannels()) then
      --~ Pixy.Log("-=-= caster doesn't have enough channels")
      return false
    end
  end

  if (caster:getHP() < spell:getCostHP()) then
    --~ Pixy.Log("-=-= caster doesn't have enough HP")
    return false
  end

  if (inBlockPhase and spell:getPhase() == Pixy.CASTING) then
    --~ Pixy.Log("-=-= spell isn't castable in this phase")
    return false
  end

  if (SpellValidators[spell:getName()] ~= nil) then
    return SpellValidators[spell:getName()]()
  else
    return true
  end
end

Pixy.UI.Combat.updateHand = function(e)
  --if next(Hand) == nil then return true end
  local idx = 0
  for spell in list_iter(MyHand) do
    if prereqs_met(spell) then
      spell:getButton():enable()
    else
      spell:getButton():disable()
      Pixy.Log("-=-=-= disabling spell due to not meeting requirements")
    end
    idx = idx + 1
  end

  Pixy.Log("== Hand has " .. idx .. " spells")

  return true
end

Pixy.UI.Combat.onUpdatePuppet = function(e)
  --Pixy.Log("***************** UPDATING PUPPET *******************")
  Pixy.UI.Combat.updateHand(e)
end
