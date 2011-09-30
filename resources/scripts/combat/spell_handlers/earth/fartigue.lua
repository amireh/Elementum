local turns_left = 0
local apply_buff = function(inCaster, inTarget, inSpell)
  local target = inTarget:getEntity()
  local caster = inCaster:getEntity()

  Pixy.Log("Applying Fartigue on " .. target:getName() .. "#" .. target:getUID() .. " by " .. caster:getName() .. "!")

  -- attach the buff to the puppet
  target:attachBuff(inSpell)
  inSpell:setCaster(inCaster)
  inSpell:setTarget(inTarget)
  turns_left = inSpell:getDuration()
  inSpell:setExpired(false)

  SCT.ShowScrollingMessage(inSpell:getName() .. " (" .. turns_left .. " turns)", false, inTarget)
  FxEngine:playEffect("Elementum/Fx/Fatigue", inSpell:getTarget())

  return true
end

local process_buff = function(inCaster, inTarget, inSpell)
  local target = inTarget:getEntity()
  local caster = inCaster:getEntity()
  if (target:getRank() == Pixy.PUPPET) then
    target = tolua.cast(target, "Pixy::CPuppet")
  else
    target = tolua.cast(target, "Pixy::CUnit")
  end

  Pixy.Log("Processing Fartigue on " .. target:getName() .. "#" .. target:getUID() .. "!")

  target:setHP(target:getHP() - 2)
  SCT.ShowScrollingMessage("-2 health (" .. inSpell:getName() .. ")", false, inTarget)
  if (not target:isDead()) then
    target:updateTextOverlay()
    FxEngine:playEffect("Elementum/Fx/Fatigue", inTarget)
  end

  turns_left = turns_left - 1
  -- remove spell when the duration expires
  if (turns_left == 0) then
    inSpell:setExpired(true)
  end

  return true
end

local process = function(inCaster, inTarget, inSpell)

  if (inTarget:getEntity():hasBuff(inSpell:getUID())) then
    return process_buff(inCaster, inTarget, inSpell)
  else
    return apply_buff(inCaster, inTarget, inSpell)
  end

end

subscribe_spell("Fartigue", process)
