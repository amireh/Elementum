--[[
	combat: spells.lua

	spell routines go here; drawing and casting a spell
	once a spell is cast it gets propagated to its registered handler
]]

local Handlers = {}
SpellValidators = {}

-- type: incoming event handler
-- job: parses the spell attributes from the given event,
-- and attaches it to the puppet's hand, and finally calls the UI script
-- to draw it
Combat.DrawSpell = function(Spell)
  Pixy.Log("Drawing spell button: " .. Spell:getName())
  Hand.DrawSpell(Spell)
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

Combat.DropSpell = function(Spell)
  Pixy.Log("Discarding spell button: " .. Spell:getName())
  Hand.DropSpell(Spell)
end

-- type: CEGUI event handler
-- job: sends a request to the instance with the spell id
-- awaiting EVT_OK feedback to actually cast it
Combat.reqCastSpell = function(inUIEvt)
	local lWindow = CEGUI.toWindowEventArgs(inUIEvt).window
	lWindow:setText("handled from Lua");

	local lSpell = Active:getSpell(lWindow:getUserString("UID"))
  assert(lSpell)

	--tolua.cast(lSpell, "Pixy::Spell")
	Pixy.Log( "request to cast a spell named " .. lSpell:getName() .. "@" .. lSpell:getUID() )
  local evt = Pixy.Event(Pixy.EventUID.CastSpell)
  evt:setProperty("Spell", lSpell:getUID())
  if (lSpell:requiresTarget()) then
    local target = GfxEngine:getSelected()
    if (not target) then
      UI.ShowError("You need to select a target")
      return true
    end
    evt:setProperty("T", target:getEntity():getUID())
  end
  NetMgr:send(evt)

  return true
end

-- type: incoming event handler
-- job: locates the spell given in the event and calls its registered handler
Combat.CastSpell = function(inCaster, inTarget, inSpell)
	local spellHandler = Handlers[inSpell:getName()]
  if not inSpell:getCaster() then
    Pixy.Log("Spell has no assigned caster!! returning")
    assert(false)
    return false
  end

  local _msg = inCaster:getEntity():getName() .. "#" .. inCaster:getEntity():getUID()
  if inTarget and inTarget ~= inCaster then
    _msg = _msg .. " against " .. inTarget:getEntity():getName() .. "#" .. inTarget:getEntity():getUID()
  end
  Pixy.Log("Casting spell " .. inSpell:getName() .. " by " .. _msg)

  UI.LogSpellCast(inSpell)
  local result = false
	if not spellHandler then return false else
    result = spellHandler(inCaster, inTarget, inSpell)
  end

  if inTarget and inTarget == Selected then Buffs.Show(inTarget, SelectedIsFriendly) end
  return result
end

function subscribe_spell(inSpellName, inMethod)
	Pixy.Log("subscribing to " .. inSpellName)
	Handlers[inSpellName] = inMethod
end

function subscribe_spell_prereq(inSpellName, inMethod)
  SpellValidators[inSpellName] = inMethod
end

require("d_lister")
path_to_handlers = ScriptPrefix .. "/combat/spell_handlers"
races = {"earth", "air", "fire", "water"}
package.path = path_to_handlers .. "/?.lua;" .. package.path
for race in list_iter(races) do
  for filename in dirtree(path_to_handlers .. "/" .. race) do
    stripped_name = string.gsub(filename, path_to_handlers .. "/", "")
    stripped_name = string.gsub(stripped_name, ".lua", "")

    require(stripped_name)
  end
end
