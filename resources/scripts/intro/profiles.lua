-- UISheet : Profiles

require("pixy")

Profiles = {}
Profiles.New = {}

local isSetup = nil
local mProfiles = {}
local Name, Stats = nil

local Listbox = nil

require("intro/profiles/new_info")

-- ************************
-- ** Profiles Listing
-- ************************
Profiles.attach = function()
	Layout = Pixy.UI.attach("intro/profiles.layout")
	
	if isSetup then return true end
	
	CEImagesetMgr:create( "Profiles-Avatars.imageset" );
	CEWindowMgr:getWindow("Elementum/Scenes/Intro/Profiles/Container/Avatar"):setProperty("Image", "set:Profiles-Avatars image:Kandy");

	Pixy.Log("subscribing to load profile")

	Listbox = CEWindowMgr:getWindow("Elementum/Scenes/Intro/Profiles/List")
	CEGUI.toItemListbox(Listbox)
	Name = CEWindowMgr:getWindow("Elementum/Scenes/Intro/Profiles/Container/Name")
	Stats = CEWindowMgr:getWindow("Elementum/Scenes/Intro/Profiles/Container/Stats")
	
	Pixy.Log("hooking evt load profile")
	
	
	local mEvt = EvtMgr:createEvt("LoadAllProfiles")
	mEvt:setType(Pixy.EVT_REQ)

	EvtMgr:hook(mEvt)
	mEvt = nil
	
	Pixy.UI.waiting("Loading Profiles", Layout)
	
	isSetup = true
end

Profiles.detach = function()
end

Profiles.back = function()

	local mEvt = EvtMgr:createEvt("Logout")
	EvtMgr:hook(mEvt)
	mEvt = nil
	
	Profiles.detach()
	Login.attach()	
end

Profiles.play = function()
  
	Pixy.Log("player wants to play!")

  -- DEBUG --
  --[[local mEvt = EvtMgr:createEvt("ForceInstance")
  mEvt:setProperty("Profile", Listbox:getLastSelectedItem():getText())
  EvtMgr:hook(mEvt)]]
  
	local mEvt = EvtMgr:createEvt("JoinQueue")
	Pixy.Log(Listbox:getLastSelectedItem():getText())
	mEvt:setProperty("Profile", Listbox:getLastSelectedItem():getText())
	EvtMgr:hook(mEvt)
	
	-- wait for feedback
	Pixy.UI.waiting("Looking for an opponent", Layout)
	CEWindowMgr:getWindow("Elementum/Scenes/Intro/Profiles/Buttons/Play"):disable()
	
end

Profiles.next = function()

end

Profiles.prev = function()

end

Profiles.create = function()
	if (not mPuppet) then
		mPuppet = Pixy.Puppet:new()
	end
	Profiles.New.Info.attach()
end

Profiles.saveProfile = function(inPuppet)
	-- this is called once the user is done creating
	-- a profile, we create an event, set the profile
	-- data, and fire it
	local mEvt = EvtMgr:createEvt("CreateProfile")

	mEvt:setProperty("Name", inPuppet:getName())
	mEvt:setProperty("Race", inPuppet:getRace())
	mEvt:setProperty("Intelligence", inPuppet:getIntelligence())
	mEvt:setProperty("Vitality", inPuppet:getVitality())
	mEvt:setProperty("Alignment", inPuppet:getAlignment())
	
	EvtMgr:hook(mEvt)
	mEvt = nil
end

Profiles.show = function(inItem)
	-- displays the chosen profile that is loaded
	--if (inEvt:getFeedback() == Pixy.EVT_ERROR) then return true end
	
	-- retrieve profile using the item's value
	inItem = CEGUI.toWindowEventArgs(inItem).window
	local profile = nil --mProfiles[tonumber(inItem:getUserData())]
	for _id,_profile in ipairs(mProfiles) do
		if (_profile.Name == inItem:getText()) then 
			profile = _profile
			break 
		end
	end
	
	if (not profile) then return false end
	--tolua.cast(inEvt, "Pixy::UIEvent_Profile")
	--Pixy.Log("Got profile! " .. inEvt:getProfileName())
	
	
	local stats, race, align = ""
	if (profile.Race == Pixy.EARTH) then race = "Earth"
	elseif (profile.Race == Pixy.AIR) then race = "Air"
	elseif (profile.Race == Pixy.FIRE) then race = "Fire"
	else race = "Water" end
	
	if (profile.Alignment == Pixy.H_NEUTRAL) then align = "Neutral"
	elseif (profile.Alignment == Pixy.H_GOOD) then align = "Good"
	else align = "Evil" end
	
	stats = 	"Race: " .. race .. "\n"
						.. "Alignment: " .. align .. "\n"
						.. "Intelligence: " .. tostring(profile.Intelligence) .. "\n"
						.. "Vitality: " .. tostring(profile.Vitality) .. "\n"	
	
	Name:setText(profile.Name)
	Stats:setText(stats)
	
	return true
end

Profiles.add = function(inEvt)

	if (inEvt:propertyExists("Incoming")) then
		return true
	end
	
	-- adds a loaded profile to our container
	inEvt:dump()
	
	
	local profile = {}
	profile.Name = inEvt:getProperty("Name")
	profile.Race = inEvt:getProperty("Race")
	profile.Intelligence = inEvt:getProperty("Intelligence")
	profile.Vitality = inEvt:getProperty("Vitality")
	profile.Alignment = inEvt:getProperty("Alignment")
	
--	if (not mProfiles[profile.Name]) then mProfiles[profile.Name] = {} end
	local name = profile.Name
	Pixy.Log("Adding profile '" .. name .. "' to container")
	
	table.insert(mProfiles, profile)
	
	-- add item to our profile list
	local item = CEWindowMgr:createWindow("TaharezLook/ListboxItem", "Elementum/Scenes/Intro/Profiles/List/" .. profile.Name)
	CEGUI.toItemEntry(item)
	item:subscribeEvent("SelectionChanged", "Profiles.show")
	item:setText(profile.Name)
	Listbox:addItem(item)
	-- remove progress box
	Pixy.UI.doneWaiting()
	
	return true
end

Profiles.matchFound = function()
	Pixy.Log("!!!! GAME FOUND !!!!")
	Pixy.UI.doneWaiting()
	GameMgr:changeState(Combat)
	--require("combat/entry_point")
	--CEWindowMgr:getWindow("Elementum/Scenes/Intro/Profiles/Container/Buttons/Play"):enable()
	return true
end

subscribeToEvt("LoadProfile", Profiles.show)
subscribeToEvt("LoadAllProfiles", Profiles.add)
subscribeToEvt("MatchFound", Profiles.matchFound)
