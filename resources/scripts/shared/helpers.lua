--[[
	combat: helpers.lua

	defines some global helpers used by the rest of the scripts
]]

function list_iter(t)
  local i = 0
  local n = table.getn(t)
  return function ()
    i = i + 1
    if i <= n then return t[i] else return nil end
  end
end

function rlist_iter(t)
  local n = table.getn(t)
  local i = n+1
  return function ()
    i = i - 1
    if i > 0 then return t[i] else return nil end
  end
end

-- Code by David Kastrup
require "lfs"

function dirtree(dir)
  assert(dir and dir ~= "", "directory parameter is missing or empty")
  if string.sub(dir, -1) == "/" then
    dir=string.sub(dir, 1, -2)
  end

  local function yieldtree(dir)
    for entry in lfs.dir(dir) do
      if entry ~= "." and entry ~= ".." then
        entry=dir.."/"..entry
	local attr=lfs.attributes(entry)
	coroutine.yield(entry,attr)
	if attr.mode == "directory" then
	  yieldtree(entry)
	end
      end
    end
  end

  return coroutine.wrap(function() yieldtree(dir) end)
end

-- converts Pixy.RACE to a string
function raceToString(inRace)
	if (inRace == Pixy.EARTH) then return 'Earth'
	elseif (inRace == Pixy.AIR) then return 'Air'
	elseif (inRace == Pixy.FIRE) then return 'Fire'
	elseif (inRace == Pixy.WATER) then return 'Water'
	end
end

-- converts a string to Pixy.RACE
function raceFromString(inRace)
	if (inRace == 'Earth') then return Pixy.EARTH
	elseif (inRace == 'Air') then return Pixy.AIR
	elseif (inRace == 'Fire') then return Pixy.FIRE
	elseif (inRace == 'Water') then return Pixy.WATER
	end
end

function split(str, pat)
   local t = {}  -- NOTE: use {n = 0} in Lua-5.0
   local fpat = "(.-)" .. pat
   local last_end = 1
   local s, e, cap = str:find(fpat, 1)
   while s do
      if s ~= 1 or cap ~= "" then
	 table.insert(t,cap)
      end
      last_end = e+1
      s, e, cap = str:find(fpat, last_end)
   end
   if last_end <= #str then
      cap = str:sub(last_end)
      table.insert(t, cap)
   end
   return t
end

function all_words(str)
  local t = {}
  local b = 0
  local e = 0
  b,e = str:find("%w+", e+1)
  while b do
    table.insert(t, str:sub(b,e))
    b,e = str:find("%w+", e+1)
  end
  return t
end

function capitalize(str)
  if not str then return nil end
  return (str:gsub("^%l", string.upper))
end

function find_by_cond(in_table, functor)
  for item in list_iter(in_table) do
    if functor(item) then return item end
  end

  return nil
end
find_by_condition = find_by_cond

function find_by_value(in_table, in_val)
  return find_by_cond(in_table, function(item) if item == in_val then return true end end)
end

function remove_by_value(inTable, inValue)
	local i = 1
	for val in list_iter(inTable) do
	  if val == inValue then
	    table.remove(inTable, i)
			break
	  end
	  i = i+1
	end
end
