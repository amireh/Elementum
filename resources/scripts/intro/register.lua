require("pixy")

Register = {}

Register.attach = function()
	Layout = Pixy.UI.attach("intro/register.layout")
	Register.Username = CEWindowMgr:getWindow("Elementum/Scenes/Intro/Register/TextFields/Username")
	Register.Password = CEWindowMgr:getWindow("Elementum/Scenes/Intro/Register/TextFields/Password")
	
	subscribeToEvt("Register", Register.update)
end

Register.detach = function()
	--CEWindowMgr:destroyWindow(Layout)
	Register.Username, Register.Password = nil, nil
end

Register.back = function(inEvt)
	Register.detach()
	--CESystem:executeScriptFile("intro/Login.lua")
	Login.attach()	
end

Register.update = function(inEvt)

	local result = "Failed."
	if (inEvt:getFeedback() == Pixy.EVT_OK) then
		result = "Successful!"
	end
	PBox_Label:setText(result)
	
	Pixy.Log("handler returning true..")
	
	Pixy.UI.doneWaiting(true)
	return true
end

Register.submit = function()

	Pixy.UI.waiting("Registering", Layout)
	
	-- hook registration event
	local mEvt = EvtMgr:createEvt("Register")
	mEvt:setProperty("Username", Register.Username:getText())
	mEvt:setProperty("Password", Register.Password:getText())

	EvtMgr:hook(mEvt)
	
	return true
end
