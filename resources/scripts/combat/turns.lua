--[[
	combat: turns.lua

	logic related to game turns is handled here
]]

-- type: incoming event handler
-- job: requests spells from the instance, and registers
-- the currently active / waiting puppets
Combat.startTurn = function(inEvt)
	--local lEvt = EvtMgr:createEvt("StartTurnAck")
	--EvtMgr:hook(lEvt)
	--lEvt = nil

	--Active = Puppet
	--Waiting = EnemyPuppet


end

-- type: incoming event handler
-- job: swaps the active/waiting puppets
Combat.endTurn = function()
	--Active = EnemyPuppet
	--Waiting = Puppet
end

-- type: event transmitter
-- job: hooks an event requesting the turn to end for the current player
Combat.reqEndTurn = function()
  if Active:getUID() == SelfPuppet:getUID() then
    local lEvt = Pixy.Event:new()
    lEvt.UID = Pixy.EventUID.EndTurn
    NetMgr:send(lEvt)

    local instance = CEGUI.AnimationManager:getSingleton():instantiateAnimation("ClickEndTurn")
    instance:setTargetWindow(CEWindowMgr:getWindow("Elementum/Combat/Buttons/EndTurn"))
    if (not instance:isRunning()) then instance:start() end
  end
end

Combat.onMatchFinished = function(wuid)
  Pixy.UI.Combat.onMatchFinished(wuid)
end

Combat.onHandleNewTurn = function()
  Pixy.UI.Combat.ClearSpellLog()
end
