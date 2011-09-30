local turns_left = 0
local apply_buff = function(inCaster, inSpell)
  Pixy.Log("Applying Nourish on " .. inCaster:getName() .. "#" .. inCaster:getUID() .. "!")

  -- attach the buff to the puppet
  inCaster:attachBuff(inSpell)
  turns_left = inSpell:getDuration()
  inSpell:setExpired(false)
  SCT.ShowScrollingMessage(inSpell:getName() .. " (" .. turns_left .. " turns)", true, inCaster:getRenderable())

  FxEngine:playEffect("Elementum/Fx/Nourish", inCaster:getRenderable())

  return true
end

local process_buff = function(inCaster, inSpell)
  Pixy.Log("Processing Nourish on " .. inCaster:getName() .. "#" .. inCaster:getUID() .. "!")
  inCaster:setHP(inCaster:getHP() + 3)
  inCaster:updateTextOverlay()
  FxEngine:playEffect("Elementum/Fx/Nourish", inCaster:getRenderable())
  SCT.ShowScrollingMessage("+3 health (Nourish)", true, inCaster:getRenderable())

  turns_left = turns_left - 1
  -- remove spell when the duration expires
  if (turns_left == 0) then
    inSpell:setExpired(true)
  end

  return true
end

local process = function(inCaster, inTarget, inSpell)
  local caster = inCaster:getEntity()
  tolua.cast(caster, "Pixy::CPuppet")

  if (caster:hasBuff(inSpell:getUID())) then
    return process_buff(caster, inSpell)
  else
    return apply_buff(caster, inSpell)
  end

end

subscribe_spell("Nourish", process)
