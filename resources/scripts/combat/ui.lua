--[[
	combat: ui.lua

	cegui event handlers and UI handlers go here
]]
if not UI then UI = {} end

UI = {

  Config = {
    Layout = "combat/ui.layout",
    Dim = {
      HandButton = CEGUI.UVector2:new(CEGUI.UDim(0.15,0),CEGUI.UDim(1,0)),
      LogButton = CEGUI.UVector2:new(CEGUI.UDim(0.06,0),CEGUI.UDim(1,0))
    }
  },

  Root = nil,
  Hand = nil,
  Buffs = nil,

  Labels = {
    Message = nil,
    Error = nil,
    Tooltip = nil,
    Turns = nil,
    Player = {
      WP = nil,
      HP = nil,
      C = nil
    },
    Enemy = {
      WP = nil,
      HP = nil,
      C = nil
    }
  },
  Containers = {
    Message = nil,
    Error = nil,
    Tooltip = nil,
    Buffs = nil,
    SpellLog = {
      Player = nil,
      Enemy = nil
    }
  },

  Buttons = {
    EndTurn = nil,
    Attack = nil,
    --Pass = nil,
    Menu = nil
  },

}

-- maps CEGUI Windows to CSpell objects
local inBlockPhase = false

UI.configure = function()

	-- create our imagesets used for spell buttons
	CEImagesetMgr:create( "spells_earth.imageset" )
	CEImagesetMgr:create( "spells_fire.imageset" )
  CEImagesetMgr:create( "huds.imageset" )

end


UI.registerGlobals = function()

  UI.Root = CEWindowMgr:getWindow("Combat")
  UI.Hand = CEWindowMgr:getWindow("Combat/Hand")
  UI.Buffs = CEWindowMgr:getWindow("Combat/Buffs")

  UI.Containers["Error"] = CEWindowMgr:getWindow("Combat/Containers/Error")
  UI.Containers["Tooltip"] = CEWindowMgr:getWindow("Combat/Containers/Tooltip")
  UI.Containers["Message"] = CEWindowMgr:getWindow("Combat/Containers/Message")
  UI.Containers["Buffs"] = CEWindowMgr:getWindow("Combat/Containers/Buffs")
  UI.Containers.SpellLog["Player"] = CEWindowMgr:getWindow("Combat/Containers/SpellLog/Player")
  UI.Containers.SpellLog["Enemy"] = CEWindowMgr:getWindow("Combat/Containers/SpellLog/Enemy")

  UI.Labels["Turns"] = CEWindowMgr:getWindow("Combat/Effects/Turns/Text")
  UI.Labels["Tooltip"] = CEWindowMgr:getWindow("Combat/Text/Tooltip")
  UI.Labels["Error"] = CEWindowMgr:getWindow("Combat/Text/Error")
  UI.Labels.Player["WP"] = CEWindowMgr:getWindow("Combat/Text/Player/Willpower")
  UI.Labels.Player["HP"] = CEWindowMgr:getWindow("Combat/Text/Player/Health")
  UI.Labels.Player["C"] = CEWindowMgr:getWindow("Combat/Text/Player/Channels")
  UI.Labels.Enemy["WP"] = CEWindowMgr:getWindow("Combat/Text/Enemy/Willpower")
  UI.Labels.Enemy["HP"] = CEWindowMgr:getWindow("Combat/Text/Enemy/Health")
  UI.Labels.Enemy["C"] = CEWindowMgr:getWindow("Combat/Text/Enemy/Channels")

  UI.Buttons["EndTurn"] = CEWindowMgr:getWindow("Combat/Buttons/EndTurn")
  UI.Buttons["Attack"] = CEWindowMgr:getWindow("Combat/Buttons/Attack")
  UI.Buttons["Menu"] = CEWindowMgr:getWindow("Combat/Buttons/Menu")



  UIEngine:connectAnimation(UI.Containers["Message"], "Fade")
  UIEngine:connectAnimation(UI.Containers["Error"], "LongFadeOut")

end

-- effectively reloads the UI components and sheets
-- NOTE: this destroys all currently drawn spell buttons too!
UI.reload = function()
	CEWindowMgr:destroyWindow(CEWindowMgr:getWindow("Combat"))

	local lLayout = CEWindowMgr:loadWindowLayout(UI.Config.LayoutPath)
	lLayout:setAlwaysOnTop(true)
	CESystem:setGUISheet(lLayout)

	-- TODO repopulate puppet hand after reloading ui
end

UI.ShowBigMessage = function(txt)
  CEWindowMgr:getWindow("Combat/Containers/Message"):hide()
  CEWindowMgr:getWindow("Combat/Text/Message"):setText(txt)
  CEWindowMgr:getWindow("Combat/Containers/Message"):show()
end

UI.onStartTurn = function()
  UI.ShowBigMessage("Attacking Phase")

  inBlockPhase = false
  UI.Labels["Turns"]:setText("Your turn")

  UI.Hand:enable()
  --for button in list_iter(UI.Buttons) do
  --  button:enable()
  --end

end

UI.onTurnStarted = function()
  UI.ShowBigMessage("Waiting")
  inBlockPhase = true
  UI.Labels["Turns"]:setText("Enemy's turn")

  UI.Hand:disable()
  --for button in list_iter(UI.Buttons) do
  --  button:disable()
  --end
end

UI.onStartBlockPhase = function()
  UI.ShowBigMessage("Blocking Phase")
  UI.Labels["Turns"]:setText("Blocking Phase")
end

UI.onMatchFinished = function(wuid)
  local suid = tonumber(SelfPuppet:getUID())
  Pixy.Log("Winner's UID : " .. wuid .. " mine: " .. suid)
  UIEngine:connectAnimation(CEWindowMgr:getWindow("Combat/Containers/Message"), "LongFade")
  if (wuid == suid) then
    UI.ShowBigMessage("Victory")
    UI.Labels["Turns"]:setText("")
  else
    UI.ShowBigMessage("Loss")
    UI.Labels["Turns"]:setText("")
  end
end

UI.ShowError = function(txt)
  UI.Containers["Error"]:hide()
  UI.Labels["Error"]:setText(txt)
  UI.Containers["Error"]:show()
end

UI.UpdatePuppet = function(puppet)
  if (puppet == SelfPuppet) then
    UI.Labels.Player["WP"]:setText(puppet:getWP())
    UI.Labels.Player["C"]:setText(puppet:getChannels())
    UI.Labels.Player["HP"]:setText(puppet:getHP())
  else
    UI.Labels.Enemy["WP"]:setText(puppet:getWP())
    UI.Labels.Enemy["C"]:setText(puppet:getChannels())
    UI.Labels.Enemy["HP"]:setText(puppet:getHP())
  end
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
UI.onInvalidAction = function(e)
  UI.ShowError(InvalidActions[e:getProperty("Action")][e:getProperty("Reason")])
end

UI.onStatChange = function(e)
  rnd = tolua.cast(e.Any, "Pixy::Renderable")
  if (e:getProperty("Stat") == "HP") then
    local amount = tonumber(e:getProperty("Value"))
    if amount > 0 then _mod = "+" else _mod = "" end
    SCT.ShowScrollingMessage(_mod .. amount .. " health", amount > 0, rnd)
  end
end

UI.onEntityAttacked = function(e)
  rnd = tolua.cast(e.Any, "Pixy::Renderable")
  local damage = tonumber(e:getProperty("Damage"))
  if damage > 0 then
    SCT.ShowScrollingMessage("-" .. damage .. " health", false --[[ negative scrolling message ]], rnd)
  end
end

UI.onLifetap = function(e)
  rnd = tolua.cast(e.Any, "Pixy::Renderable")
  local damage = tonumber(e:getProperty("Damage"))
  if damage > 0 then
    SCT.ShowScrollingMessage("+" .. damage .. " health (LIFETAP)", true --[[ good scrolling message ]], rnd)
  end
end

UI.onFirstStrike = function(e)
  UI.ShowBigMessage("FIRST STRIKE!")
end

UI.onTrample = function(e)
  UI.ShowBigMessage("TRAMPLE!")
end

UI.onUpdatePuppet = function(e)
  --Pixy.Log("***************** UPDATING PUPPET *******************")
  UI.updateHand(e)
end

UI.Animate = function(win, anim)
  local instance = CEGUI.AnimationManager:getSingleton():instantiateAnimation(anim)
  instance:setTargetWindow(win)
  --if (not instance:isRunning()) then
  instance:start()
  --end
end

-- configure
UI.configure()

require("combat/ui/helpers")
require("combat/ui/tooltips")
require("combat/ui/sct")
require("combat/ui/hand")
require("combat/ui/spell_log")
