-- UISheet : Decks
Decks = UISheet:new("intro/decks.layout")

-- we force the loading of Decks because we will populate its windows before
-- the layout is actually attached, so it must be loaded in order to reference
-- those windows (see Decks.onPuppetSynced)
Decks:load()

local Spells = {}
local I2D = {} -- Items to Decks

local RaceSpells = nil
local isSetup = false
local CurrentDeck = nil
local Grid = {}
local DeckList = nil
local ModelGrid = nil
local DeckGrid = nil
local Tooltip = nil

 -- onDecksSynced needs this to verify whether this sheet is attached,
 -- if it isn't, then it won't populate the deck list until attachment
local attached = false
local last_puppet_race = nil
local spells_populated = false

RaceSpells = CEWindowMgr:getWindow("Decks/RaceSpells")
Tooltip = CEWindowMgr:getWindow("Decks/Text/Tooltip")
DeckList = CEGUI.toCombobox(CEWindowMgr:getWindow("Decks/Combobox/Decks"))
ModelGrid = CEGUI.toGridLayoutContainer(CEWindowMgr:getWindow("Decks/Containers/Spells"))
DeckGrid = CEGUI.toGridLayoutContainer(CEWindowMgr:getWindow("Decks/Containers/Deck"))

ModelGrid:setGridDimensions(4,16)
DeckGrid:setGridDimensions(8,2)

function Decks:attach()
  UISheet.attach(self)
  attached = true

  Decks.populateDecks()

	if isSetup then return true end

  Decks.createDeckGrid()

  isSetup = true
end

function Decks:detach()
  UISheet.detach(Decks)
  attached = false
end

Decks.backToChat = function()
  Decks:detach()
  Chat:attach()
end

local Deck = {}
Decks.createDeckGrid = function()
  -- if it's already created, just return
  if CEWindowMgr:isWindowPresent("Deck/Slot0") then return true end

  local dim = CEGUI.UVector2:new(CEGUI.UDim(0.125,0),	CEGUI.UDim(0.5,0))

  local nr_slots = 16
  local idx = 0
  while idx < nr_slots do
    local slot = CEWindowMgr:createWindow("Vanilla/Static", "Deck/Slot" .. idx)
    slot:setSize(dim)
    local dragger = CEWindowMgr:createWindow("DragContainer", slot:getName() .. "Drag")
    slot:addChildWindow(dragger)
    dragger:setSize(CEGUI.UVector2(CEGUI.UDim(1,0), CEGUI.UDim(1,0)))
    dragger:subscribeEvent("MouseClick", "Decks.removeSpellFromDeck")

    DeckGrid:addChildWindow(slot)
    idx = idx + 1
  end
end

local function spell_image_name(spell)
  -- create the spell image window
  spell:setImageSet("Spells_" .. raceToString(spell:getRace()))
  -- sanitize spell name to match image set name
  local sane_name = string.gsub(spell:getName(), "%s", "_")
  spell:setImageName(sane_name)

  return "set:" .. spell:getImageSet() .. " image:" .. spell:getImageName() .. "_Normal"
end

Decks.populateDecks = function()
  assert(Puppet and PuppetDecks)

  DeckList:clearAllSelections()
  DeckList:resetList()
  DeckList:setText("")

  for k,v in ipairs(PuppetDecks) do
    print("\tDeck: " .. k .. " => " .. v:getName())
  end
  for deck in list_iter(PuppetDecks) do
    item = CEGUI.createListboxTextItem(deck:getName())
    DeckList:addItem(item)

    I2D[item] = deck
  end

end

local Spells = {}
Decks.populateRaceSpells = function(race)
  local dim =
  CEGUI.UVector2:new(CEGUI.UDim(0.22,0),	CEGUI.UDim(0.20,0))

  for idx, spell in ipairs(Pixy.Models.Spells[race]) do
    -- check if this slot has been created before
    local created = CEWindowMgr:isWindowPresent("Decks/RaceSpells/Slot" .. idx)
    local slot = nil
    local dragger = nil
    local button = nil

    if not created then
      print("\tcreating slot for race spell" .. idx .. " => " .. spell:getName())
      -- create the container window
      slot = CEWindowMgr:createWindow("DefaultWindow", "Decks/RaceSpells/Slot" .. idx)
      slot:setSize(dim)

      -- create the draggable window
      dragger = CEWindowMgr:createWindow("DragContainer", slot:getName() .. "Drag")
      slot:addChildWindow(dragger)
      dragger:setSize(CEGUI.UVector2(CEGUI.UDim(0.95,0), CEGUI.UDim(0.95,0)))
      dragger:subscribeEvent("MouseClick", "Decks.addSpellToDeck")
      dragger:subscribeEvent("MouseEnter", "Decks.showTooltip")
      dragger:subscribeEvent("MouseLeave", "Decks.hideTooltip")
      dragger:setUserString("Spell", spell:getName())
      dragger:setUserString("Race", raceToString(race))

      button = CEWindowMgr:createWindow("Combat/ImageButton", dragger:getName() .. "Image")
      dragger:addChildWindow(button)
      button:setSize(CEGUI.UVector2(CEGUI.UDim(1,0), CEGUI.UDim(1,0)))
      button:setProperty("NormalImage", spell_image_name(spell))
      button:setProperty("MousePassThroughEnabled", "True")

      ModelGrid:addChildWindow(slot)
    else
      slot = CEWindowMgr:getWindow("Decks/RaceSpells/Slot" .. idx)
      dragger = slot:getChild(slot:getName() .. "Drag")
      dragger:setUserString("Spell", spell:getName())
      dragger:setUserString("Race", raceToString(race))
      button = dragger:getChild(dragger:getName() .. "Image")
      button:setProperty("NormalImage", spell_image_name(spell))
    end

    Spells[dragger:getName()] = spell
  end

  spells_populated = true
  last_puppet_race = race
end

Decks.addSpellToDeck = function(args)
  local args = CEGUI.toWindowEventArgs(args)
  local dragger = args.window
  local spell = Spells[dragger:getName()]

  Decks.doAddSpellToDeck(spell)
end

Decks.doAddSpellToDeck = function(spell)

  assert(spell)

  -- find an empty slot in the deck
  local idx = 0
  local target = nil
  local prefix = "Deck/Slot"
  while idx < 16 do
    local win = DeckGrid:getChild(prefix .. idx):getChild(prefix .. idx .. "Drag")
    if win:getChildCount() == 0 then
      target = win
      break
    end
    idx = idx + 1
  end

  if not target then print("ERROR! Couldn't find an empty slot in the grid"); return true end

  local button = CEWindowMgr:createWindow("Combat/ImageButton", target:getParent():getName() .. "Spell")
  button:setSize(CEGUI.UVector2(CEGUI.UDim(1,0), CEGUI.UDim(1,0)))
  button:setProperty("NormalImage", spell_image_name(spell))
  button:setProperty("MousePassThroughEnabled", "True")

  target:subscribeEvent("MouseEnter", "Decks.showTooltip")
  target:subscribeEvent("MouseLeave", "Decks.hideTooltip")
  target:setUserString("Spell", spell:getName())
  target:setUserString("Race", raceToString(spell:getRace()))

  target:addChildWindow(button)

  Deck[target:getName()] = spell
  table.insert(Grid, spell)
  return true
end



Decks.removeSpellFromDeck = function(args)
  local args = CEGUI.toWindowEventArgs(args)
  local dragger = args.window
  local spell = Deck[dragger:getName()]

  if not spell then print("no spell at this slot!"); return true end

  assert(spell and dragger)
  -- get the spell button and remove/destroy it
  local button = dragger:getChild(dragger:getParent():getName() .. "Spell")
  dragger:removeChildWindow(button)
  CEWindowMgr:destroyWindow(button)
  Deck[dragger:getName()] = nil

  remove_by_value(Grid, spell)

  print("player removed " .. spell:getName() .. " from slot " .. dragger:getName())
  return true
end

Decks.showTooltip = function(args)
  local args = CEGUI.toWindowEventArgs(args)
  local dragger = args.window
  for spell in list_iter(Pixy.Models.Spells[raceFromString(dragger:getUserString("Race"))]) do
    if spell:getName() == dragger:getUserString("Spell") then
      Tooltip:setText(spell:getTooltip())
      return true
    end
  end

end

Decks.hideTooltip = function(args)
  Tooltip:setText("")
end

Decks.clearGrid = function()
  local idx = 0
  while idx < 16 do
    CEWindowMgr:destroyWindow("Deck/Slot" .. idx .. "Spell")
    idx = idx + 1
  end
  Grid = {}
end

Decks.onListSelectionChanged = function(args)
  local item = DeckList:getSelectedItem()

  assert(I2D[item])

  if CurrentDeck then
    Decks.clearGrid()
  end

  local deck = I2D[item]
  print("Populating deck " .. deck:getName() .. " which has ")
  -- populate deck grid with the spells in this deck
  local idx = 0
  while idx < 16 do
    local spell = find_by_cond(Pixy.Models.Spells[Puppet:getRace()], function(in_spell)
      if in_spell:getName() == deck:getSpell(idx):getName() then return true end
    end)

    Decks.doAddSpellToDeck(spell)
    idx = idx + 1
  end

  CurrentDeck = deck
  return true
end

local function valid(name)
  if name:len() > 20 or name:len() < 3 then return false end
  -- starts with a letter, can contain spaces, letters, or numbers
  return name:find("^%a+%w*[%s*%w*]*$") ~= nil
end

Decks.onSaveDeck = function(args)
  print("Saving deck:")
  for idx,spell in ipairs(Grid) do
    print("\t" .. idx .. " => " .. spell:getName())
  end

  if table.getn(Grid) < 16 then
    print("deck not full!");
    Pixy.UI.notifyError("Deck has to be full.")
    return false
  end

  local deck_name = DeckList:getText()
  if not valid(deck_name) then
    print("invalid deck name!");
    Pixy.UI.notifyError("Deck names need to start with a letter, can contain alphanumeric characters and spaces, \
    and have to be 3 to 20 characters long.")
    return false
  end

  local e = Pixy.Event(Pixy.EventUID.UpdateDeck)
  e.Options = Pixy.Event.NoFormat
  local tmp = deck_name .. ","
  for idx,spell in ipairs(Grid) do
    tmp = tmp .. spell:getName()
    if idx ~= 16 then tmp = tmp .. "," end
  end
  e:setProperty("Data", tmp)
  NetMgr:send(e)

  UISheet.showDialog("Updating deck...")

  return true
end

Decks.onUpdateDeck = function(e)

  if e.Feedback == Pixy.EventFeedback.Error then
    UISheet.showDialog("An error occured while updating the deck.")
  else
    UISheet.showDialog("Deck is updated.")
  end

  return true
end

Decks.onPuppetSynced = function(e)

  print("Populating race spells in deck menu for puppet " .. Puppet:getName() .. " race : " .. Puppet:getRace())
  --~ if not last_puppet_race or last_puppet_race ~= Puppet:getRace() then
    Decks.populateRaceSpells( Puppet:getRace() )
    last_puppet_race = Puppet:getRace()
    spells_populated = false
  --~ end
  return true
end

Decks.onDecksSynced = function(e)
  if not attached then return true end

  print("Got decks")
  I2D = {}
  Decks.populateDecks()
  Decks.clearGrid()

  return true
end

Decks.cleanup = function()
  Decks:detach()
  isSetup = false
end

Decks.RemoveDeck = function()
  if not CurrentDeck then return true end

  local e = Pixy.Event(Pixy.EventUID.RemoveDeck)
  e:setProperty("Name", CurrentDeck:getName())
  NetMgr:send(e)

  UISheet.showDialog("Deleting deck...")
  return true
end

Decks.onRemoveDeck = function(e)

  if e.Feedback == Pixy.EventFeedback.Error then
    UISheet.showDialog("An error occured while deleting the deck.")
  else
    UISheet.showDialog("Deck is deleted.")
    Decks.clearGrid()
  end
end
