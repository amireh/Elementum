--[[
	combat: turns.lua

	logic related to game turns is handled here
]]

-- type: incoming event handler
-- job: requests spells from the instance, and registers
-- the currently active / waiting puppets
Pixy.Combat.startTurn = function(inEvt)
	--local lEvt = EvtMgr:createEvt("StartTurnAck")
	--EvtMgr:hook(lEvt)
	--lEvt = nil

	--Active = Puppet
	--Waiting = EnemyPuppet
end

-- type: incoming event handler
-- job: swaps the active/waiting puppets
Pixy.Combat.endTurn = function()
	--Active = EnemyPuppet
	--Waiting = Puppet
end

-- type: event transmitter
-- job: hooks an event requesting the turn to end for the current player
Pixy.Combat.reqEndTurn = function()
  if Active:getUID() == SelfPuppet:getUID() then
    local lEvt = Pixy.Event:new()
    lEvt.UID = Pixy.EventUID.EndTurn
    NetMgr:send(lEvt)
  end
end

