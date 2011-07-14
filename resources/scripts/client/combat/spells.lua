--[[
	combat: spells.lua

	spell routines go here; drawing and casting a spell
	once a spell is cast it gets propagated to its registered handler
]]


-- type: incoming event handler
-- job: parses the spell attributes from the given event,
-- and attaches it to the puppet's hand, and finally calls the UI script
-- to draw it
Pixy.Combat.DrawSpell = function(Spell)
  Pixy.Log("Drawing spell button: " .. Spell:getName())
  Pixy.UI.Combat.drawSpell(Spell)
--[[
  local uid = inEvt:getProperty("Spell")
  tolua.cast(uid, "int")

	lSpell = Puppet:getSpell(inEvt:getProperty("Spell"))
	if (lSpell == nil) then
		Pixy.Log("Error! Deck didn't give me a proper spell object named " .. inEvt:getProperty("Spell"))
	end

	--~ lSpell:setId(inEvt:getObjectId())
	--~ Pixy.Log(inEvt:getOwner() .. " is drawing a spell named " .. lSpell:getName() .. "@" .. lSpell:getId())



	--~ Active:attachSpell(lSpell)]]
	return true
end

Pixy.Combat.DropSpell = function(Spell)
  Pixy.Log("Discarding spell button: " .. Spell:getName())
  Pixy.UI.Combat.dropSpell(Spell)
end

-- type: CEGUI event handler
-- job: sends a request to the instance with the spell id
-- awaiting EVT_OK feedback to actually cast it
Pixy.Combat.reqCastSpell = function(inUIEvt)
	local lWindow = CEGUI.toWindowEventArgs(inUIEvt).window
	lWindow:setText("handled from Lua");

	local lSpell = Active:getSpell(lWindow:getUserString("Spell"))
  assert(lSpell)

	--tolua.cast(lSpell, "Pixy::Spell")
	Pixy.Log( "request to cast a spell named " .. lSpell:getName() .. "@" .. lSpell:getUID() )
  local evt = Pixy.Event:new()
  evt.UID = Pixy.EventUID.CastSpell
  evt:setProperty("Spell", lSpell:getUID())
  NetMgr:send(evt)
end

-- type: incoming event handler
-- job: locates the spell given in the event and calls its registered handler
Pixy.Combat.castSpell = function(inEvt)
	if (inEvt:getFeedback() == Pixy.EVT_OK) then
		Pixy.Log( "casting a spell" )
	else
		Pixy.Log( "request to cast spell was rejected" )
	end

end
