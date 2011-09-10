local Tracker = {}
local WantUpdates = {}

function list_iter(t)
  local i = 0
  local n = table.getn(t)
  return function ()
    i = i + 1
    if i <= n then return t[i] end
  end
end

function doUpdateMe(inCallback)
	table.insert(WantUpdates, inCallback)
end

function removeByValue(inTable, inValue)
	local i = 1
	for val in list_iter(inTable) do
	  if val == inValue then
	    table.remove(inTable, i)
			break
	  end
	  i = i+1
	end
end

function dontUpdateMe(inCallback)

	local i = 1
	for method in list_iter(WantUpdates) do
	  if method == inCallback then
	    table.remove(WantUpdates, i)
			break
	  end
	  i = i+1
	end
end

function setupEvtMap()
  EventMap = {}
	tracking = false
end

-- registers a handler to an event
function subscribeToEvt(inUID, inHandler)

	-- init handler table for event if it doesnt exist
	if (not EventMap[inUID]) then
		EventMap[inUID] = {}
	end

	table.insert(EventMap[inUID], inHandler)

	Pixy.Log("Subscribed handler to " .. inUID)
end
bind = subscribeToEvt -- an alias

function clearBindings()
  EventMap = {}
end

-- calls handlers and returns status
function processEvt(inEvt)
  --inEvt = tolua.cast(inEvt, "Pixy::Event")
  --tolua.cast(inEvt.UID, "Pixy::EventUID")
  if (inEvt.UID == Pixy.EventUID.Connected) then Pixy.Log("There's a connected evt!") end

  --Pixy.Log("Handling an event " .. inEvt.UID)
	done = true

	if (not EventMap[inEvt.UID]) then return true end

	-- register handlers
	if (not tracking) then

		local nrHandlers = 0
		for id,handler in ipairs(EventMap[inEvt.UID]) do
			table.insert(Tracker, id, false)
			nrHandlers = nrHandlers+1
		end

		-- there are no handlers for this evt, we're done
		if (nrHandlers == 0) then
			Pixy.Log("Oops! Found no handlers for event " .. inEvt.UID)
			return true
		end

		tracking = true
	end

	-- calls each handler interested in this event
	-- and stores the result of their return
	-- will not call handles that have returned true
	-- moreover, should any handler return a false it
	-- means that we still have work to do, so the global
	-- 'done' will be set to false
	for id,status in ipairs(Tracker) do
		-- call handler if it's not done
		if (not status) then
			Tracker[id] = EventMap[inEvt.UID][id](inEvt)
			if (not Tracker[id]) then done = false end
		end

	end

	-- we're done, empty the tracker and return true
	if (done) then
		for id,handler in ipairs(EventMap[inEvt.UID]) do
			Tracker[id] = nil
		end
		tracking = false
		return true
	end

	Pixy.Log("handling evt " .. inEvt.UID)

	return false
end

function update()
	for callback in list_iter(WantUpdates) do
		callback()
	end
end

setupEvtMap()
