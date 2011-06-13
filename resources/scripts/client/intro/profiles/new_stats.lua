-- ************************
-- ** New - Stats
-- ************************
Profiles.New.Stats = {}

local Intelligence, Vitality, Alignment, PtsLeft, LabelPtsLeft, PtsFactor, Next = nil

PtsLeft = 10
PtsFactor = 2

Profiles.New.Stats.attach = function()
	Layout = Pixy.UI.attach("intro/profiles/new_stats.layout")

	local _prefix = "Elementum/Scenes/Intro/Profiles/New/Stats"
	Intelligence = CEWindowMgr:getWindow(_prefix .. "/TextFields/Intelligence")
	Vitality = CEWindowMgr:getWindow(_prefix .. "/TextFields/Vitality")
	LabelPtsLeft = CEWindowMgr:getWindow(_prefix .. "/Labels/PointsLeft")
	Alignment = CEWindowMgr:getWindow(_prefix .. "/RadioButtons/Neutral")
	
	Next = CEWindowMgr:getWindow(_prefix .. "/Buttons/Next")
	Next:setEnabled(false)

	doUpdateMe(Profiles.New.Stats.update)
end

Profiles.updatePtsLeft = function()
	LabelPtsLeft:setText(tostring(PtsLeft))
end

Profiles.New.Stats.detach = function()
	dontUpdateMe(Profiles.New.Stats.update)
end

Profiles.New.Stats.update = function()
	if PtsLeft == 0 then Next:setEnabled(true) end
end

Profiles.New.Stats.incVitality = function()

	if (PtsLeft < PtsFactor) then return end
	Vitality:setText(tonumber(Vitality:getText()) + PtsFactor)

	PtsLeft = PtsLeft - PtsFactor
	Profiles.updatePtsLeft()
end

Profiles.New.Stats.decVitality = function()
	
	Vitality:setText(tonumber(Vitality:getText()) - PtsFactor)
	PtsLeft = PtsLeft + PtsFactor
	Profiles.updatePtsLeft()
	
end

Profiles.New.Stats.incIntelligence = function()
	if (PtsLeft < PtsFactor) then return end
	Intelligence:setText(tonumber(Intelligence:getText()) + PtsFactor)
	PtsLeft = PtsLeft - PtsFactor
	Profiles.updatePtsLeft()
end

Profiles.New.Stats.decIntelligence = function()
	Intelligence:setText(tonumber(Intelligence:getText()) - PtsFactor)
	PtsLeft = PtsLeft + PtsFactor
	Profiles.updatePtsLeft()

end

Profiles.New.Stats.back = function()
	Profiles.New.Stats.detach()
	Profiles.New.Info.attach()
end

Profiles.New.Stats.next = function()
	-- save alignment, vitality, and intelligence
	
	local _alignment
	tolua.cast(_alignment, "Pixy.PUPPET_ALIGNMENT")
	
	Alignment = CEGUI.toRadioButton(Alignment)
	Alignment = Alignment:getSelectedButtonInGroup():getText()
	
	if (Alignment == "Neutral") then _alignment = Pixy.H_NEUTRAL
	elseif (Alignment == "Good") then _alignment = Pixy.H_GOOD
	else _alignment = Pixy.H_EVIL end
	
	mPuppet:setIntelligence(tonumber(Intelligence:getText()))
	mPuppet:setVitality(tonumber(Vitality:getText()))
	mPuppet:setAlignment(_alignment)
	Profiles.New.Stats.detach()
	Profiles.saveProfile(mPuppet)
	Profiles.attach()
end