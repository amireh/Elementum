--[[
	combat: spells.lua

	spell routines go here; drawing and casting a spell
	once a spell is cast it gets propagated to its registered handler
]]

local Handlers = {}

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
  if (lSpell:requiresTarget()) then
    local target = GfxEngine:getSelected()
    if (not target) then
      Pixy.UI.Combat.ShowError("You need to select a target")
      evt:delete()
      return false
    end
    evt:setProperty("T", target:getEntity():getUID())
  end
  NetMgr:send(evt)
end

-- type: incoming event handler
-- job: locates the spell given in the event and calls its registered handler
Pixy.Combat.CastSpell = function(inCaster, inTarget, inSpell)
	local spellHandler = Handlers[inSpell:getName()]
  if not inSpell:getCaster() then
    Pixy.Log("Spell has no assigned caster!! returning")
    return false
  end

	if not spellHandler then return false else
    local caster_is_self = false
    if (inSpell:getCaster():getEntity():getOwner():getUID() == SelfPuppet:getUID()) then
      caster_is_self = true
    end
    Pixy.UI.Combat.LogSpellCast(inSpell,caster_is_self)
    return spellHandler(inCaster, inTarget, inSpell)
  end
end

function subscribe_spell(inSpellName, inMethod)
	Pixy.Log("subscribing to " .. inSpellName)
	Handlers[inSpellName] = inMethod
end

require("d_lister")
path_to_handlers = "../resources/scripts/client/combat/spell_handlers"
races = {"earth", "air", "fire", "water"}
package.path = package.path .. ";" .. path_to_handlers .. "/?.lua"
for race in list_iter(races) do
  for filename in dirtree(path_to_handlers .. "/" .. race) do
    stripped_name = string.gsub(filename, path_to_handlers .. "/", "")
    stripped_name = string.gsub(stripped_name, ".lua", "")

    require(stripped_name)
  end
end
