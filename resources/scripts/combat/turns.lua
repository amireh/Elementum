--[[
	combat: turns.lua

	logic related to game turns is handled here
]]

TurnNumber = 0
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
    local lEvt = Pixy.Event(Pixy.EventUID.EndTurn)
    NetMgr:send(lEvt)
  end
end

Combat.onMatchFinished = function(wuid)
  UI.onMatchFinished(wuid)
end

Combat.onHandleNewTurn = function()
  if Active == EnemyPuppet then UI.ClearSpellLog(Active) end

  TurnNumber = TurnNumber + 1
end
