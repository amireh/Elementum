local turns_left = 0
local effect = nil
local _ap = 1
local caster = nil

local increase_ap = function(unit)
  if unit:getOwner():getUID() == caster:getUID() then
    unit:setBaseAP(unit:getBaseAP() + _ap)
    SCT.ShowScrollingMessage("+" .. _ap .. " AP (Shadow dance)", true, unit:getRenderable())
  end

  return true
end

local revert_ap = function(unit)
  if unit:getOwner():getUID() == caster:getUID() then
    unit:setBaseAP(unit:getBaseAP() - _ap)
    SCT.ShowScrollingMessage("-" .. _ap .. " AP (Shadow dance)", false, unit:getRenderable())
  end

  return true
end

local apply_buff = function(inCaster, inTarget, inSpell)
  local target = inTarget:getEntity()
  caster = inCaster:getEntity()

  Pixy.Log("Applying " .. inSpell:getName() .. " on " .. caster:getName() .. "#" .. caster:getUID() .. " by " .. caster:getName() .. "!")

  -- attach the buff to the puppet
  caster:attachBuff(inSpell)
  turns_left = inSpell:getDuration()
  inSpell:setExpired(false)

  SCT.ShowScrollingMessage(inSpell:getName() .. " (" .. turns_left .. " turns)", true, inCaster)
  effect = FxEngine:playEffect("Gloom", inCaster)

  -- update the AP of all the units
  local exporter = Pixy.CUnitListExporter()
  exporter:export(caster:getUnits(), "Pixy::CUnit", "Temp")
  for unit in list_iter(Temp) do
    increase_ap(unit)
  end
  Temp = nil

  -- update the AP of all units to be created
  subscribe_generic_unit_handler("Alive", increase_ap)

  return true
end

local process_buff = function(inCaster, inTarget, inSpell)

  turns_left = turns_left - 1
  -- remove spell when the duration expires
  if (turns_left == 0) then
    inSpell:setExpired(true)
    effect:stop()

    -- revert the AP of all the units
    local exporter = Pixy.CUnitListExporter()
    exporter:export(caster:getUnits(), "Pixy::CUnit", "Temp")
    for unit in list_iter(Temp) do
      revert_ap(unit)
    end
    Temp = nil

    SCT.ShowScrollingMessage("-" .. inSpell:getName(), false, inCaster)

    unsubscribe_generic_unit_handler("Alive", increase_ap)
  end

  return true
end

local process = function(inCaster, inTarget, inSpell)
  inTarget = inCaster
  if (inCaster:getEntity():hasBuff(inSpell:getUID())) then
    return process_buff(inCaster, inTarget, inSpell)
  else
    return apply_buff(inCaster, inTarget, inSpell)
  end

end

subscribe_spell("Shadow Dance", process)
