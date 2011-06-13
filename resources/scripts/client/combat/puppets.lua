local nrPlayers = 1 -- DEBUG
local nrProfilesLoaded = 0

Puppets = {}

-- type: incoming event handler
-- job: stores the names of the player's puppet and his opponent
-- and tells the graphics engine about them
Pixy.Combat.assignPuppets = function(inEvt)
	Me = inEvt:getProperty("Puppet")
	Enemy = inEvt:getProperty("EnemyPuppet")

	Pixy.Log("I'm playing " .. Me .. " against " .. Enemy) -- DEBUG

	GfxEngine:setupCombat(Me, "Foobar")
	return true
end

-- type: incoming event handler
-- job: parses the puppet from the event, calls the factory for an instance
-- then generates the deck.. and tells the GfxEngine to render it
Pixy.Combat.createPuppet = function(inEvt)
	tolua.cast(inEvt, "Pixy::EntityEvent")

	local lPuppet =
	PuppetFactory:createEntity(
			inEvt:getObjectId(),
			inEvt:getProperty("Name"),
			inEvt:getOwner(),
			raceFromString(inEvt:getProperty("Race"))
	)

  lPuppet:live()
	lPuppet:setMesh("sinbad.mesh")
  --lRenderable = lPuppet:getRenderable()
	--lPuppet:getDeck():generate()

	-- DEBUG
	Pixy.Log("puppet " .. lPuppet:getName() .. "#" .. lPuppet:getObjectId() .. " owned by " .. lPuppet:getOwner() .. " is up")
	lPuppet:printInfo()

	-- track puppet
	if (lPuppet:getOwner() == Me) then
		Puppet = lPuppet
	else
		EnemyPuppet = lPuppet
	end

	-- render the puppet
	GfxEngine:attachToScene(lPuppet:getRenderable())

	-- track how many puppets to go before we're ready
	nrProfilesLoaded = nrProfilesLoaded+1

	if (nrProfilesLoaded == nrPlayers) then
		-- tell the server i'm ready to play
		local lEvt = EvtMgr:createEvt("Ready")
		EvtMgr:hook(lEvt)
		lEvt = nil
	end

	Puppets[lPuppet:getName()] = lPuppet
	Pixy.Log("Registered puppet " .. lPuppet:getName())
	return true
end
