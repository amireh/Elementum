local Handlers = {}

Pixy.Combat.CreateUnit = function(inUnit)

	local handler = Handlers[inUnit:getName()]
	if not handler then
    Pixy.Log("ERROR! Unit " .. inUnit:getName() .. " has no handler! aborting")
    return false
  else
    local result = handler(inUnit)
    if result then
      FxEngine:playEffect("Elementum/Fx/Summon", inUnit:getRenderable())
    end
    return result
  end

  return true
end

function subscribe_unit(inUnitName, inMethod)
	Pixy.Log("subscribing to " .. inUnitName)
	Handlers[inUnitName] = inMethod
end

require("d_lister")
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
