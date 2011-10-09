local Handlers = { Generic = { Alive = {}, Dead = {} } }

local SummoningEffects = {
  Earth = "EarthSummoning",
  Fire = "FireSummoning"
}
Units = {}

Units.cleanup = function()
  --~ SpellValidators = {}
  --~ Handlers = { Generic = { Alive = {}, Dead = {} } }
end

Units.onCreateUnit = function(inUnit)

	local handler = Handlers[inUnit:getName()]
	if not handler then
    Pixy.Log("ERROR! Unit " .. inUnit:getName() .. " has no handler! aborting")
    return false
  else
    local result = handler(inUnit)
    if result then
      FxEngine:playEffect(SummoningEffects[raceToString(inUnit:getRace())], inUnit:getRenderable(), true)

      -- now call the Generic handlers (Renderable is created)
      for generic_handler in list_iter(Handlers.Generic.Alive) do
        generic_handler(inUnit)
      end
    end
    return result
  end

  return true
end

Units.onEntityDying = function(e)
  local rnd = tolua.cast(e.Any, "Pixy::Renderable")
  FxEngine:playEffect(SummoningEffects[raceToString(rnd:getEntity():getRace())], rnd:getSceneNode():getPosition(), true)
end

function subscribe_unit(inUnitName, inMethod)
	Pixy.Log("subscribing to " .. inUnitName)
	Handlers[inUnitName] = inMethod
end

function subscribe_generic_unit_handler(inState, inMethod)
  if not Handlers.Generic[inState] then
    Handlers.Generic[inState] = {}
  end

  table.insert(Handlers.Generic[inState], inMethod)
end

function unsubscribe_generic_unit_handler(inState, inMethod)
  remove_by_value(Handlers.Generic[inState], inMethod)
end

path_to_handlers = ScriptPrefix .. "/combat/unit_handlers"
races = {"earth", "air", "fire", "water"}
package.path = path_to_handlers .. "/?.lua;" .. package.path
for race in list_iter(races) do
  for filename in dirtree(path_to_handlers .. "/" .. race) do
    stripped_name = string.gsub(filename, path_to_handlers .. "/", "")
    stripped_name = string.gsub(stripped_name, ".lua", "")

    require(stripped_name)
  end
end
