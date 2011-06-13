--[[
	combat: debug.lua
	
	this script defines methods that bypass the normal flow, hence debug, ie:
	login, logout, and forcing the creation of a solo instance
]]

Pixy.Combat.logIn = function()
	local lEvt = EvtMgr:createEvt("Login")
	lEvt:setProperty("Username", "asd")
	lEvt:setProperty("Password", "asd")
	EvtMgr:hook(lEvt)
	lEvt = nil
end

Pixy.Combat.logOut = function()
	local lEvt = EvtMgr:createEvt("Logout")
	EvtMgr:hook(lEvt)
	lEvt = nil
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
