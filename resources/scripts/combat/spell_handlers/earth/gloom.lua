local turns_left = 0
local effect = nil
local _cost = 2

local increase_cost = function(puppet, spell)
  if spell:getName():find("Summon") then return true end
  spell:setCostWP(spell:getCostWP() + _cost)
  Pixy.Log("increasing cost of spell "
    .. spell:getName() .. "#" .. spell:getUID()
    .. " for caster " .. spell:getCaster():getEntity():getName()
    .. ", now WP=" .. spell:getCostWP())

  return true
end

local revert_cost = function(puppet, spell)
  if spell:getName():find("Summon") then return true end
  spell:setCostWP(spell:getCostWP() - _cost)
  Pixy.Log("restoring cost of spell "
    .. spell:getName() .. "#" .. spell:getUID()
    .. " for caster " .. spell:getCaster():getEntity():getName()
    .. ", now WP=" .. spell:getCostWP())

  return true
end

local apply_buff = function(inCaster, inTarget, inSpell)
  local target = inTarget:getEntity()
  local caster = inCaster:getEntity()

  Pixy.Log("Applying " .. inSpell:getName() .. " on " .. target:getName() .. "#" .. target:getUID() .. " by " .. caster:getName() .. "!")

  -- attach the buff to the puppet
  target:attachBuff(inSpell)
  turns_left = inSpell:getDuration()
  inSpell:setExpired(false)

  SCT.ShowScrollingMessage(inSpell:getName() .. " (" .. turns_left .. " turns)", false, inTarget)
  effect = FxEngine:playEffect("Gloom", inSpell:getTarget())

  -- if it's our puppet that is the target, then we need to update all the tooltips
  -- to reflect the new cost
  if target:getUID() == SelfPuppet:getUID() then
    local exporter = Pixy.CSpellListExporter()
    exporter:export(target:getHand(), "Pixy::CSpell", "Temp")
    for spell in list_iter(Temp) do
      increase_cost(nil, spell)
    end
    Temp = nil
    Hand.UpdateTooltips()
  end

  return true
end

local process_buff = function(inCaster, inTarget, inSpell)
  local target = inTarget:getEntity()

  turns_left = turns_left - 1
  -- remove spell when the duration expires
  if (turns_left == 0) then
    inSpell:setExpired(true)
    effect:stop()

    -- revert tooltip changes
    if target:getUID() == SelfPuppet:getUID() then
      local exporter = Pixy.CSpellListExporter()
      exporter:export(target:getHand(), "Pixy::CSpell", "Temp")
      for spell in list_iter(Temp) do
        revert_cost(nil, spell)
      end
      Temp = nil
      Hand.UpdateTooltips()
    end
  end

  return true
end

local process = function(inCaster, inTarget, inSpell)

  inTarget = CombatState:getEnemy(inCaster:getEntity():getUID()):getRenderable()

  if (inTarget:getEntity():hasBuff(inSpell:getUID())) then
    return process_buff(inCaster, inTarget, inSpell)
  else
    return apply_buff(inCaster, inTarget, inSpell)
  end

end

subscribe_spell("Gloom", process)
