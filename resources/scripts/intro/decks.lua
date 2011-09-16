-- UISheet : Decks

Decks = {}
Spells = {}

local isSetup = false
Decks.attach = function()
	Decks.Layout = Pixy.UI.attach("intro/decks.layout")

	if isSetup then return true end

  isSetup = true
end

Decks.detach = function()
  Pixy.UI.detach(Decks.Layout)
end
