local Tracker = {}
local EventMap = {}
local tracking = false

local function setupEvtMap()
  EventMap = {}
	tracking = false
end

Dispatcher = {}

-- registers a handler to an event
Dispatcher.subscribeToEvt = function(inUID, inHandler)

	-- init handler table for event if it doesnt exist
	if (not EventMap[inUID]) then
		EventMap[inUID] = {}
	end

	table.insert(EventMap[inUID], inHandler)

	Pixy.Log("Subscribed handler to " .. inUID .. " => " .. Pixy.Event:UIDToString(inUID))
end

-- unregisters an event handler
Dispatcher.unsubscribeFromEvt = function(inUID, inHandler)
  if not EventMap[inUID] then return false end

  remove_by_value(EventMap[inUID], inHandler)

  return true
end

-- calls handlers and returns status
-- note: this method is called directly by ScriptEngine whenever an event is dispatched
Dispatcher.processEvt = function(inEvt)
  --inEvt = tolua.cast(inEvt, "Pixy::Event")
  --tolua.cast(inEvt.UID, "Pixy::EventUID")
  --~ if (inEvt.UID == Pixy.EventUID.Connected) then Pixy.Log("There's a connected evt!") end

  --~ Pixy.Log("Handling an event " .. inEvt.UID)
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
    -- the following check is needed in the case that a new state
    -- is switched to _inside_ an event handler which will cause
    -- the event map to be erased and will segfault if we don't
    -- check for it here
		if EventMap[inEvt.UID] then
      for id,handler in ipairs(EventMap[inEvt.UID]) do
        Tracker[id] = nil
      end
    end
		tracking = false
		return true
	end

	Pixy.Log("handling evt " .. inEvt.UID .. " => " .. Pixy.Event:UIDToString(inEvt.UID))

	return false
end

Dispatcher.setup = setupEvtMap
Dispatcher.cleanup = setupEvtMap
Dispatcher.clearBindings = setupEvtMap
