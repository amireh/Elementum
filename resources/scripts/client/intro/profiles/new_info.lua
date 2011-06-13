require("intro/profiles/new_stats")

-- ************************
-- ** New - Info
-- ************************
Profiles.New.Info = {}

local isSetup = nil

local Name, Race, Next = nil

Profiles.New.Info.attach = function()
	Layout = Pixy.UI.attach("intro/profiles/new_info.layout")
	doUpdateMe(Profiles.New.Info.update)
	
	if isSetup then return true end
	
	CEImagesetMgr:create("Elements.imageset")
	local _prefix = "Elementum/Scenes/Intro/Profiles/New/Info"
	Name = CEWindowMgr:getWindow(_prefix .. "/TextFields/Name")
	Race = CEWindowMgr:getWindow(_prefix .. "/TextFields/Race")
	Next = CEWindowMgr:getWindow(_prefix .. "/Buttons/Next")
	Next:setEnabled(false)
	
	isSetup = true
end

Profiles.New.Info.detach = function()
	dontUpdateMe(Profiles.New.update)
end

Profiles.New.Info.back = function()
	-- discard puppet info, reset it
	Profiles.New.Info.detach()
	Profiles.attach()
end

Profiles.New.Info.setRace = function(e)
	-- get window and find out which race it was
	local button = CEGUI.toWindowEventArgs(e).window
	local _race = nil
	
	_start, _end = string.find(button:getName(), "Buttons/", 1, true)
	-- strip the slash and get the button name
	_race = string.sub(button:getName(), _end+1)
	Race:setText(_race)
end

Profiles.New.Info.next = function()

	-- save profile name and race

	int_race = 0
	if (Race:getText() == "Earth") then int_race = Pixy.EARTH
	elseif (Race:getText() == "Air") then int_race = Pixy.AIR
	elseif (Race:getText() == "Fire") then int_race = Pixy.FIRE
	elseif (Race:getText() == "Water") then int_race = Pixy.WATER
	else -- we have an error

	end
	-- validate
	-- ...

	mPuppet:setName(Name:getText())
	mPuppet:setRace(int_race)
	
	-- jump to Stats sheet
	Profiles.New.Info.detach()
	Profiles.New.Stats.attach()
end

Profiles.New.Info.update = function()
	-- enable next button when race and name are entered
	if ((string.len(Name:getText()) > 2) 
			and
			(string.len(Race:getText()) > 0)) 
		then
			Next:setEnabled(true)
		end
end

