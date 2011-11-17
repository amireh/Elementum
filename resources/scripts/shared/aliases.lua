-- this is called externally by ScriptEngine and it references the global table
-- so we have to map it here
processEvt = Dispatcher.processEvt

-- aliases for registering events
bind = Dispatcher.subscribeToEvt
bindEvt = Dispatcher.subscribeToEvt

-- aliases for unregistering events
unbind = Dispatcher.unsubscribeFromEvt
unbindEvt = Dispatcher.unsubscribeFromEvt

-- update() is called by ScriptEngine::update() every frame
-- Whenever a state script overrides the "update" global var,
-- it should call Pixy.update() at some point in its body
update = Pixy.update
