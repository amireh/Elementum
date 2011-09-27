local process = function(inCaster, inTarget, inSpell)
	Pixy.Log("I'm summoning a Fetish: Herdkeeper!")
	return true
end

subscribe_spell("Summon: Fetish Herdkeeper", process)
