--[[
	combat: turns.lua

	logic related to game turns is handled here
]]

Turns = {}
TurnNumber = 0

-- type: event transmitter
-- job: hooks an event requesting the turn to end for the current player
Turns.reqEndTurn = function()
  local e = nil
  if Active:getUID() == SelfPuppet:getUID() then
    e = Pixy.Event(Pixy.EventUID.EndTurn)
  else
    e = Pixy.Event(Pixy.EventUID.EndBlockPhase)
  end
  UI.onReqEndTurn()
  NetMgr:send(e)
end

Turns.onNewTurn = function()
  if Active == EnemyPuppet then UI.ClearSpellLog(Active) end

  TurnNumber = TurnNumber + 1
end

Turns.cleanup = function()
  TurnNumber = 0
end
