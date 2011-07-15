local process = function(inCaster, inTarget, inSpell)
	Pixy.Log("I'm summoning a Fetish: Zij!")

	return true
end

subscribe_spell("Summon: Fetish Zij", process)
