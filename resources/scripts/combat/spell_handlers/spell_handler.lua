-- when a Spell has its duration set to this "magic" number, it means its permanent
local __Magic = 120

SpellHandler = {}
function SpellHandler:new(inSpell, inCaster, inTarget, inDefinition)
  assert(inDefinition)

  local o = inDefinition
  o.Spell = inSpell
  o.Caster = inCaster
  if o.Spell:requiresTarget() then
    o.Target = inTarget
  else
    o.Target = o.Caster
  end
  o.__TurnsLeft = o.Spell:getDuration()
  o.Spell:setExpired(false)

  setmetatable(o, {__index = self})
  self.__index = self

  return o
end

function SpellHandler:bootstrap()
  return true
end

function SpellHandler:destroy()
  self:cleanup()

  local uid = self.Spell:getUID()
  self.Spell:setExpired(true)

  self.Spell = nil
  self.Caster = nil
  self.Target = nil

  self = nil

  Spells.__destroyInstance(uid)

  return nil
end

function SpellHandler:cast()
  Pixy.Log("ERROR! Generic SpellHandler cast behaviour called.")

  return true
end

function SpellHandler:process()
  Pixy.Log("ERROR! Generic SpellHandler process behaviour called.")

  return true
end

function SpellHandler:cleanup()
  return true
end

function SpellHandler:isDone()
  return self.Spell:getDuration() == 0 or self.__TurnsLeft == 0
end


function SpellHandler:logMe()
  local msg = ""
  msg = "Casting " .. self.Spell:getName() .. "#" .. self.Spell:getUID()
  msg = msg .. " by " .. self.Caster:getName() .. "#" .. self.Caster:getUID()
  if self.Target then
    msg = msg .. " on " .. self.Target:getName() .. "#" .. self.Target:getUID()
  end

  Pixy.Log("\t" .. msg)
end

function SpellHandler:__tick()
  self.__TurnsLeft = self.__TurnsLeft - 1
end

function SpellHandler:isBuff()
  local dur = self.Spell:getDuration()
  return dur > 0 or dur == __Magic
end

function SpellHandler:isPermanent()
  return self.Spell:getDuration() == __Magic
end

function SpellHandler:logSCT()
  if self:isBuff() then
    local msg = self.Spell:getName()
    if self:isPermanent() then
      msg = msg .. " (permanent)"
    else
      msg = msg .. " (" .. self.__TurnsLeft .. " turns)"
    end
    SCT.ShowScrollingMessage(msg, self.IsPositive, self.Target)
  else
    error("attempting to SCT log a non-buff spell!")
  end
end
