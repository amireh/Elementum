--[[
	combat: helpers.lua

	defines some global helpers used by the rest of the scripts
]]

-- retrieves the puppet mentioned in the incoming event
function getPuppet(inEvt)
	if (Puppet:getName() == inEvt:getOwner()) then
		return Puppet
	else
		return EnemyPuppet
	end
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

function aspectToString(inAsp)
  if (inAsp == Pixy.MIND) then return 'Mind'
  else return 'Matter'
  end
end

-- reloads the lua module, effectively resetting the state
--~ Combat.reloadScripts = function()
	--~ require("pixy")
--~ end

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

function capitalize(str)
  if not str then return nil end
  return (str:gsub("^%l", string.upper))
end
