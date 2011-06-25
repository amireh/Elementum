
-- type: incoming event handler
-- job: stores the names of the player's puppet and his opponent
-- and tells the graphics engine about them
Pixy.Combat.addPuppet = function(inPuppet)
  table.insert(Puppets, inPuppet)
  Pixy.Log("Registering a new Puppet to the instance, named: " .. inPuppet:getName())
end

Pixy.Combat.assignSelfPuppet = function(inPuppet)
  SelfPuppet = inPuppet
  Pixy.Log("I'm playing with a puppet named " .. SelfPuppet:getName())
end
Pixy.Combat.assignActivePuppet = function(puppet)
  Active = puppet
  Pixy.Log("Current turn is for puppet: " .. Active:getName())
end

-- type: incoming event handler
-- job: parses the puppet from the event, calls the factory for an instance
-- then generates the deck.. and tells the GfxEngine to render it
--[[
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
]]
