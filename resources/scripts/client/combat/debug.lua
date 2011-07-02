--[[
	combat: debug.lua

	this script defines methods that bypass the normal flow, hence debug, ie:
	login, logout, and forcing the creation of a solo instance
]]

MyPuppetName = "Kandie"

Pixy.Combat.login = function()
  Pixy.Log("Sending login event")
	local lEvt = Pixy.Event:new()
  lEvt.UID = Pixy.EventUID.Login
	lEvt:setProperty("Username", "Kandie")
	lEvt:setProperty("Password", "tuonela")
	NetMgr:send(lEvt)

  return true
end

Pixy.Combat.loginResult = function(inEvt)
  Pixy.Log("Login result received: " .. inEvt:getFeedback())
	if (inEvt:getFeedback() == Pixy.EVT_ERROR) then
    Pixy.Log("Login failed, trying with a different account")
    local lEvt = EvtMgr:createEvt("Login")
    lEvt:_setMsgId(Pixy.ID_LOGIN_EVENT)
    lEvt:setProperty("Username", "Sugarfly")
    lEvt:setProperty("Password", "tuonela")
    EvtMgr:hook(lEvt)
    lEvt = nil

    MyPuppetName = "Sugar"
	else
    -- queue up
    local lEvt = EvtMgr:createEvt("JoinQueue")
    lEvt:setProperty("PuppetName", MyPuppetName)
    EvtMgr:hook(lEvt)
    lEvt = nil
  end

  return true
end

Pixy.Combat.logOut = function()
	--local lEvt = EvtMgr:createEvt("Logout")
	--EvtMgr:hook(lEvt)
	--lEvt = nil
end

Pixy.Combat.forceInstance = function(inEvt)

	if (not inEvt:getFeedback() == Pixy.EVT_OK) then
		return true
	end

	local lEvt = EvtMgr:createEvt("ForceInstance")
	lEvt:setProperty("Profile", "Kandie")
	EvtMgr:hook(lEvt)
	lEvt = nil

end
