--[[
	combat: ui.lua

	cegui event handlers and UI handlers go here
]]
if not UI then UI = {} end

UI = {

  Config = {
    Layout = "combat/ui.layout",
    Dim = {
      HandButton = CEGUI.UVector2(CEGUI.UDim(0.125,0),CEGUI.UDim(1,0)),
      BuffButton = CEGUI.UVector2(CEGUI.UDim(0.25,0),CEGUI.UDim(0.1,0)),
      LogButton = CEGUI.UVector2(CEGUI.UDim(0.05,0),CEGUI.UDim(1,0))
    }
  },
  Animes = {
    ShowTooltip = nil,
    HideTooltip = nil
  },

  Root = nil,
  Hand = nil,
  Buffs = { Player = nil, Enemy = nil },

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
      Enemy = nil
    },
    Player = {
      Selected = nil
    },
    Enemy = {
      Selected = nil
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

UI.cleanup = function()
  local idx = 0
  while idx < UI.Hand:getChildCount() do
    local win = UI.Hand:getChildAtIdx(idx)
    UI.ClearAnimations(win)
    idx = idx + 1
  end
  --~ CEGUI.AnimationManager:getSingleton():destroyAnimation(UI.Animes.ShowTooltip:getDefinition():getName())
  --~ CEGUI.AnimationManager:getSingleton():destroyAnimation(UI.Animes.HideTooltip:getDefinition():getName())
end

UI.registerGlobals = function()

  UI.Root = CEWindowMgr:getWindow("Combat")
  UI.Hand = CEGUI.toLayoutContainer(CEWindowMgr:getWindow("Combat/Hand"))
  --~ UI.Buffs = CEWindowMgr:getWindow("Combat/Buffs")
  --~ UI.Buffs.Player = CEGUI.toLayoutContainer(CEWindowMgr:getWindow("Combat/Buffs/Player"))
  --~ UI.Buffs.Enemy = CEGUI.toLayoutContainer(CEWindowMgr:getWindow("Combat/Buffs/Enemy"))
  UI.Buffs.Player = CEWindowMgr:getWindow("Combat/Buffs/Player")
  UI.Buffs.Enemy = CEWindowMgr:getWindow("Combat/Buffs/Enemy")

  UI.Containers["Error"] = CEWindowMgr:getWindow("Combat/Containers/Error")
  --~ UI.Containers["Tooltip"] = CEWindowMgr:getWindow("Combat/Containers/Tooltip")
  UI.Containers["Message"] = CEWindowMgr:getWindow("Combat/Containers/Message")
  UI.Containers["Buffs"] = CEWindowMgr:getWindow("Combat/Containers/Buffs")
  UI.Containers.SpellLog["Enemy"] = CEWindowMgr:getWindow("Combat/Containers/SpellLog/Enemy")
  UI.Containers.Player["Selected"] = CEGUI.toLayoutContainer(CEWindowMgr:getWindow("Combat/Containers/Selected/Player"))
  UI.Containers.Enemy["Selected"] = CEGUI.toLayoutContainer(CEWindowMgr:getWindow("Combat/Containers/Selected/Enemy"))

  UI.Labels["Turns"] = CEWindowMgr:getWindow("Combat/Effects/Turns/Text")
  UI.Labels["Tooltip"] = CEWindowMgr:getWindow("Combat/Text/Tooltip")
  UI.Labels["Error"] = CEWindowMgr:getWindow("Combat/Text/Error")
  UI.Labels.Player["WP"] = CEWindowMgr:getWindow("Combat/Text/Player/Willpower")
  UI.Labels.Player["HP"] = CEWindowMgr:getWindow("Combat/Text/Player/Health")
  UI.Labels.Player["C"] = CEWindowMgr:getWindow("Combat/Text/Player/Channels")
  UI.Labels.Player["Selected"] = CEWindowMgr:getWindow("Combat/Labels/Player/Selected")
  UI.Labels.Enemy["WP"] = CEWindowMgr:getWindow("Combat/Text/Enemy/Willpower")
  UI.Labels.Enemy["HP"] = CEWindowMgr:getWindow("Combat/Text/Enemy/Health")
  UI.Labels.Enemy["C"] = CEWindowMgr:getWindow("Combat/Text/Enemy/Channels")
  UI.Labels.Enemy["Selected"] = CEWindowMgr:getWindow("Combat/Labels/Enemy/Selected")

  UI.Buttons["EndTurn"] = CEWindowMgr:getWindow("Combat/Buttons/EndTurn")
  UI.Buttons["Attack"] = CEWindowMgr:getWindow("Combat/Buttons/Attack")
  UI.Buttons["Menu"] = CEWindowMgr:getWindow("Combat/Buttons/Menu")

  UIEngine:connectAnimation(UI.Containers["Message"], "Fade")
  UIEngine:connectAnimation(UI.Containers["Error"], "LongFadeOut")

  --~ UI.Animes.ShowTooltip = CEGUI.AnimationManager:getSingleton():instantiateAnimation("ShowTooltip")
  --~ UI.Animes.HideTooltip = CEGUI.AnimationManager:getSingleton():instantiateAnimation("HideTooltip")
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

  return true;
end

UI.onMechanicChanged = function(e)
  Pixy.Log("Unit Mechanic has changed")
  local unit = tolua.cast(e.Any, "Pixy::CUnit")
  local rnd = unit:getRenderable()

  local has_it = e:getProperty("HasIt") == "Yes"
  local _mod = ""
  if has_it then _mod = "+" else _mod = "-" end
  SCT.ShowScrollingMessage(_mod .. " " .. e:getProperty("M"), has_it, rnd)

  return true;
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

UI.Animations = {}
UI.Animate = function(win, anim)
  local instance = CEGUI.AnimationManager:getSingleton():instantiateAnimation(anim)
  instance:setTargetWindow(win)
  --if (not instance:isRunning()) then
  instance:start()
  if not UI.Animations[win] then UI.Animations[win] = { } end
  table.insert(UI.Animations[win], instance)
  return instance
  --end
end
UI.RemoveAnimation = function(win, in_anim)
  assert(UI.Animations[win])

  local idx = 1
  for anim in list_iter(UI.Animations[win]) do
    if anim == in_anim then
      table.remove(UI.Animations[win], idx)
    end
    idx = idx + 1
  end

  in_anim:stop()
  in_anim:setTargetWindow(nil)
  CEGUI.AnimationManager:getSingleton():destroyAnimationInstance(in_anim)

end
UI.ClearAnimations = function(win)
  assert(UI.Animations[win])
  local count = 0
  for anim in list_iter(UI.Animations[win]) do
    anim:stop()
    anim:setTargetWindow(nil)
    CEGUI.AnimationManager:getSingleton():destroyAnimationInstance(anim)
    count = count + 1
  end
  print("\t--destroyed " .. count .. " animation instances for window: " .. win:getName())
  UI.Animations[win] = {}
end
UI.isAnimating = function(anim)
  local instance = CEGUI.AnimationManager:getSingleton():instantiateAnimation(anim)
  return instance:isRunning()
end
UI.StopAnimating = function(anim)
  local instance = CEGUI.AnimationManager:getSingleton():instantiateAnimation(anim)
  instance:stop()
end

UI.Highlight = function(entity, is_friendly)
  local lbl = nil
  if is_friendly then
    lbl = UI.Labels.Player["Selected"]
  else
    lbl = UI.Labels.Enemy["Selected"]
  end
  lbl:setText(entity:getName())
  height = tonumber(lbl:getProperty("VertExtent"))
  lbl:setHeight(CEGUI.UDim(0, height + 20))
end

UI.onSelectPlayer = function(e)
  -- if we don't have any selection or the selection isn't a friendly target,
  -- override it
  if not Selected or not SelectedIsFriendly then
    Combat.Highlight(SelfPuppet:getRenderable())
  end
end

UI.onSelectEnemy = function(e)
  -- if we don't have any selection or the selection isn't a friendly target,
  -- override it
  if not Selected or SelectedIsFriendly then
    Combat.Highlight(EnemyPuppet:getRenderable())
  end
  print("I'm selected!")
end

UI.Toggle = function()
  if UI.Root:isVisible() then
    UI.Root:hide()
    CEGUI.MouseCursor:getSingleton():hide()
    RTT.Player.Texture:disable()
    RTT.Player.Texture:hide()
    RTT.Enemy.Texture:disable()
    RTT.Enemy.Texture:hide()
  else
    UI.Root:show()
    CEGUI.MouseCursor:getSingleton():show()
    RTT.Player.Texture:enable()
    RTT.Player.Texture:show()
    RTT.Enemy.Texture:enable()
    RTT.Enemy.Texture:show()
  end
end

UI.onDisconnected = function(e)
  Pixy.UI.waiting("The connection to the server has been lost.", UI.Root, function()
    GameMgr:changeState(IntroState)
  end)

  return true
end
-- configure
UI.configure()

require("combat/ui/helpers")
require("combat/ui/tooltips")
require("combat/ui/sct")
require("combat/ui/hand")
require("combat/ui/spell_log")
