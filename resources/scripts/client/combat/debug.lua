--[[
	combat: debug.lua

	this script defines methods that bypass the normal flow, hence debug, ie:
	login, logout, and forcing the creation of a solo instance
]]

MyPuppetName = "Sugar"

Pixy.Combat.login = function()
  Pixy.Log("Sending login event")
	local lEvt = Pixy.Event:new()
  lEvt.UID = Pixy.EventUID.Login
	lEvt:setProperty("Username", "Sugarfly")
	lEvt:setProperty("Password", "tuonela")
	NetMgr:send(lEvt)

  return true
end

Pixy.Combat.on_login = function(inEvt)
  Pixy.Log("Login result received: " .. inEvt.Feedback)
	if (inEvt.Feedback == Pixy.EventFeedback.Error) then
    Pixy.Log("Login failed, trying with a different account")
    local lEvt = Pixy.Event:new()
    lEvt.UID = Pixy.EventUID.Login
    lEvt:setProperty("Username", "Kandie")
    lEvt:setProperty("Password", "tuonela")
    NetMgr:send(lEvt)

    MyPuppetName = "Kandie"
	else
    -- queue up
    local evt = Pixy.Event:new()
    evt.UID = Pixy.EventUID.JoinQueue
    evt:setProperty("Puppet", MyPuppetName)
    NetMgr:send(evt)

  end

  return true
end

Pixy.Combat.logOut = function()
	--local lEvt = EvtMgr:createEvt("Logout")
	--EvtMgr:hook(lEvt)
	--lEvt = nil
end
