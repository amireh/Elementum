local __Dmg = 1
local ShadowDance = { IsPositive = true }

local increase_ap = function(unit, override)
  print("\tgranting the AP by shadow dance on " .. unit:getName())
  if override or unit:getOwner():hasBuffWithName("Shadow Dance") then
    unit:setBaseAP(unit:getBaseAP() + __Dmg)
    SCT.ShowScrollingMessage("+" .. __Dmg .. " AP (Shadow dance)", true, unit:getRenderable())
  end

  return true
end

local revert_ap = function(unit, caster)
  print("\treverting the AP granted by shadow dance on " .. unit:getName())
  if override or unit:getOwner():hasBuffWithName("Shadow Dance") then
    unit:setBaseAP(unit:getBaseAP() - __Dmg)
    SCT.ShowScrollingMessage("-" .. __Dmg .. " AP (Shadow dance)", false, unit:getRenderable())
  end

  return true
end

function ShadowDance:bootstrap()
  self.__Effect = nil
end

function ShadowDance:cast()
  self:logMe()

  -- attach the buff to the puppet
  self.Caster:attachBuff(self.Spell)
  self.__Effect = FxEngine:playEffect("Gloom", self.CasterRnd)

  -- update the AP of all the units
  local exporter = Pixy.CUnitListExporter()
  exporter:export(self.Caster:getUnits(), "Pixy::CUnit", "__TempUnits")
  for unit in list_iter(__TempUnits) do
    increase_ap(unit, true --[[override checks for performance]])
  end
  __TempUnits = nil

  -- update the AP of all units to be created
  subscribe_generic_unit_handler("Alive", increase_ap)
end

function ShadowDance:process()
  -- Shadow Dance lasts only for a turn, so we revert the changes in cleanup()
  self:__tick()
end

function ShadowDance:cleanup()
  self.__Effect:stop()

  -- revert the AP of all the units
  local exporter = Pixy.CUnitListExporter()
  exporter:export(self.Caster:getUnits(), "Pixy::CUnit", "__TempUnits")
  for unit in list_iter(__TempUnits) do
    revert_ap(unit, true --[[override checks for performance]])
  end
  __TempUnits = nil

  SCT.ShowScrollingMessage("-" .. self.Spell:getName(), false, self.CasterRnd)

  unsubscribe_generic_unit_handler("Alive", increase_ap)
end

subscribe_spell("Shadow Dance", ShadowDance)
