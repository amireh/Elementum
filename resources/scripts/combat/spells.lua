--[[
	combat: spells.lua

	spell routines go here; drawing and casting a spell
	once a spell is cast it gets propagated to its registered handler
]]

--~ local Handlers = {}
local Definitions = {}
local HandlerInstances = {}
SpellValidators = {}
Spells = {}
ValidationMsg = ""

Spells.cleanup = function()
  --~ SpellValidators = {}
  --~ Handlers = {}
end

-- type: incoming event handler
-- job: parses the spell attributes from the given event,
-- and attaches it to the puppet's hand, and finally calls the UI script
-- to draw it
Spells.onDrawSpell = function(Spell)
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

Spells.onDropSpell = function(Spell)
  Pixy.Log("Discarding spell button: " .. Spell:getName())
  Hand.DropSpell(Spell)
end

-- type: CEGUI event handler
-- job: sends a request to the instance with the spell id
-- awaiting EVT_OK feedback to actually cast it
Spells.reqCastSpell = function(lSpell)
	--[[local lWindow = CEGUI.toWindowEventArgs(inUIEvt).window
	lWindow:setText("handled from Lua");

	local lSpell = Active:getSpell(lWindow:getUserString("UID"))
  assert(lSpell)]]

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
    evt:setProperty("T", target:getUID())
  end
  NetMgr:send(evt)

  return true
end

-- this is called by every buff handler when the spell effect is over
Spells.__destroyInstance = function(inUID)
  local handler = HandlerInstances[inUID]
  --~ handler:destroy()

  HandlerInstances[inUID] = nil
  return true
end

Spells.onProcessBuff = function(inCaster, inTarget, inSpell)
  local instance = HandlerInstances[inSpell:getUID()]
  if not instance then
    return error("Could not find the spell handler instance for " .. inSpell:getName() .. "#" .. inSpell:getUID())
  end

  instance:process()

  if instance:isDone() then instance:destroy() end
end

Spells.onCastSpell = function(inCaster, inTarget, inSpell)
  -- 1. if there is no registered handler for this spell, error out
  local definition = Definitions[inSpell:getName()]
  if not definition then
    return Pixy.Log("Could not find a spell definition for " .. inSpell:getName())
  end

  -- 2. create a new instance of the SpellHandler for this type of spell
  local instance = SpellHandler:new(inSpell, inCaster, inTarget, definition)
  instance:bootstrap()

  -- 3. track it
  assert(not HandlerInstances[inSpell:getUID()])
  HandlerInstances[inSpell:getUID()] = instance

  -- 4. show the spell in the spell log
  UI.LogSpellCast(inSpell)

  -- 5. call it
  instance:cast()

  -- 6. create an SCT entry if it's a (de)buff
  if instance:isBuff() then instance:logSCT() end

  -- 7. if it's not a buff, destroy it
  if instance:isDone() then instance:destroy() end

  return true
end

-- type: incoming event handler
-- job: locates the spell given in the event and calls its registered handler
--[[
Spells.onCastSpell = function(inCaster, inTarget, inSpell)
	local spellHandler = Handlers[inSpell:getName()]
  if not inSpell:getCaster() then
    Pixy.Log("Spell has no assigned caster!! returning")
    assert(false)
    return false
  end

  local _msg = inCaster:getName() .. "#" .. inCaster:getUID()
  if inTarget and inTarget ~= inCaster then
    _msg = _msg .. " against " .. inTarget:getName() .. "#" .. inTarget:getUID()
  end
  Pixy.Log("Casting spell " .. inSpell:getName() .. " by " .. _msg)

  UI.LogSpellCast(inSpell)
  local result = false
	if not spellHandler then return false else
    result = spellHandler(inCaster, inTarget, inSpell)
  end

  -- check whether to show buffs or not:
  -- 1) if the spell has a target and that target is already selected
  -- 2) no entity is selected, and the buff affects a puppet
  do
    local show_buffs = false
    local target_rnd = nil
    if Selected and inTarget and inTarget == Selected then
      show_buffs = true
      target_rnd = Selected
    elseif not Selected and inCaster:getRank() == Pixy.PUPPET then
      show_buffs = true
      target_rnd = inCaster
    end
    if show_buffs then
      local target_is_friendly = target_rnd:getOwner():getUID() == SelfPuppet:getUID()
      Buffs.Show(target_rnd, target_is_friendly)
    end
  end
  return result
end]]

-- this is called by Combat when the CastSpell request is rejected
Spells.onCastSpellRejected = function(e)
  assert(e:hasProperty("Spell"))
  Pixy.Log("Spell cast was rejected, re-enabling button for " .. e:getProperty("Spell"))
  Hand.onCastSpellRejected(tonumber(e:getProperty("Spell")))
  return true
end

function subscribe_spell(inSpellName, inDef)
	Pixy.Log("\t subscribing a Spell handler for " .. inSpellName)
	Definitions[inSpellName] = inDef
end

function subscribe_spell_prereq(inSpellName, inMethod)
  SpellValidators[inSpellName] = inMethod
end

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

require "combat/spell_handlers/spell_handler"
