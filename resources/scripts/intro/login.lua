-- Login.lua
require("pixy")
require("intro/register")
require("intro/profiles")
Login = {}


Login.attach = function()

	Layout = Pixy.UI.attach("intro/login.layout")
	
	Login.Username = CEWindowMgr:getWindow("Elementum/Scenes/Intro/Login/TextFields/Username")
	Login.Password = CEWindowMgr:getWindow("Elementum/Scenes/Intro/Login/TextFields/Password")
	
	subscribeToEvt("Login", Login.doAuthenticate)
	
	

	-- DEBUG
	--[[
	Pixy.Log("Creating a new kind of event")
	local mEvt = EvtMgr:createEvt(Pixy.EVT_MSG)
	mEvt:setProperty("SomeProperty", "SomeValue")
	mEvt:setProperty("SomeProperty", "SomeValue")
	EvtMgr:hook(mEvt)
	
	
	Pixy.Log("Hooking Spell Event")
	local mEvt = EvtMgr:createEvt(Pixy.EVT_SPELL_CAST)
	tolua.cast(mEvt, "Pixy::SpellEvent")
	mEvt:setProperty("SpellName", "Summoning")
	mEvt:dump()
	EvtMgr:hook(mEvt)
	
	mEvt = EvtMgr:createEvt(Pixy.EVT_SPELL_CAST)
	tolua.cast(mEvt, "Pixy::SpellEvent")
	mEvt:setProperty("SpellName", "Regenerating")

	EvtMgr:hook(mEvt)
	
	mEvt = nil
	]]
end

Login.detach = function()
	--CEWindowMgr:destroyWindow(Layout)
	Login.Username = nil
	Login.Password = nil
end


Login.back = function()
	--CESystem:executeScriptFile("MainMenu.lua")
	Login.detach()
	MainMenu.attach()
	--Pixy.UI.attach("intro/MainMenu.layout")
end

Login.register = function()
	Login.detach()
	--CESystem:executeScriptFile("intro/Register.lua")
	Register.attach()
end


Login.authenticate = function(inEvt)

	-- nop, send the event now then
	Pixy.Log("firing Login event")
	
	Pixy.UI.waiting("Authenticating", Layout)
	
	-- hook login event
	--[[
	local mEvt = EvtMgr:createEvt(Pixy.EVT_UI_LOGIN)
	tolua.cast(mEvt, "Pixy::UIEvent_Login")
	mEvt:setUsername(Login.Username:getText())
	mEvt:setPassword(Login.Password:getText())
	
	EvtMgr:hook(mEvt)
	]]
	local mEvt = EvtMgr:createEvt("Login")
	mEvt:setProperty("Username", Login.Username:getText())
	mEvt:setProperty("Password", Login.Password:getText())
	EvtMgr:hook(mEvt)
	mEvt = nil
	
	return true
end

Login.doAuthenticate = function(inEvt)
	Pixy.UI.doneWaiting(true)

	if (inEvt:getFeedback() == Pixy.EVT_OK) then
		Pixy.Log("login successful")
		
		Login.detach()
		Profiles.attach()
		return true
	end

	Pixy.Log("login failed")
	PBox_Label:setText("Failed")

	return true
end