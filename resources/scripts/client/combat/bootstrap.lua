require("combat/helpers")
require("combat/puppets") -- puppet handling
require("combat/units") -- unit handling
require("spells/bootstrap_spells") -- unit definitions
require("units/bootstrap_units") -- unit definitions
Pixy.Combat.gameStarted = function()
	Pixy.Log("Game has started! Pwning time")
	return true
end
