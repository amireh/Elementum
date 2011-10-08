local turns_left = 0
local _dmg = 1
local apply_buff = function(inCaster, inTarget, inSpell)
  Pixy.Log("Applying Stygian Disease on " .. inTarget:getEntity():getName() .. "#" .. inTarget:getEntity():getUID() .. "!")

  -- attach the buff to the puppet
  inTarget:getEntity():attachBuff(inSpell)
  turns_left = inSpell:getDuration()
  inSpell:setExpired(false)

  SCT.ShowScrollingMessage(inSpell:getName(), false, inTarget)

  local puppet = inSpell:getTarget():getEntity():getOwner()
  FxEngine:playEffect("Elementum/Fx/Fatigue", puppet:getRenderable())

  return true
end

local process_buff = function(inCaster, inTarget, inSpell)
  local puppet = inSpell:getTarget():getEntity():getOwner()
  puppet:setHP(puppet:getHP() - _dmg)
  puppet:updateTextOverlay()

  FxEngine:playEffect("Elementum/Fx/Fatigue", puppet:getRenderable())
  SCT.ShowScrollingMessage("-1 health (Stygian Disease)", false, puppet:getRenderable())

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

subscribe_spell("Stygian Disease", process)
