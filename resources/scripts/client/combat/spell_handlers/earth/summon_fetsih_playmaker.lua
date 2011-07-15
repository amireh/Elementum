local process = function(inCaster, inTarget, inSpell)
	Pixy.Log("I'm summoning a Fetish: Playmaker!")

	return true
end

subscribe_spell("Summon: Fetish Playmaker", process)
