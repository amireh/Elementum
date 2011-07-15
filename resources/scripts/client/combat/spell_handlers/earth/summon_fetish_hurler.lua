local process = function(inCaster, inTarget, inSpell)
	Pixy.Log("I'm summoning a Fetish: Hurler!")

	return true
end

subscribe_spell("Summon: Fetish Hurler", process)
