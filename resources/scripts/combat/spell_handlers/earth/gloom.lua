local __Cost = 2 -- this is the cost of WP that is increased by this spell
local increase_cost = function(spell)

  -- don't increase the cost of summoning spells
  if spell:getName():find("Summon") then return true end

  spell:setCostWP(spell:getCostWP() + __Cost)
  Pixy.Log("increasing cost of spell "
    .. spell:getName() .. "#" .. spell:getUID()
    .. " for caster " .. spell:getCaster():getEntity():getName()
    .. ", now WP=" .. spell:getCostWP())

  return true
end

local revert_cost = function(spell)
  if spell:getName():find("Summon") then return true end
  spell:setCostWP(spell:getCostWP() - __Cost)

  Pixy.Log("restoring cost of spell "
    .. spell:getName() .. "#" .. spell:getUID()
    .. " for caster " .. spell:getCaster():getEntity():getName()
    .. ", now WP=" .. spell:getCostWP())

  return true
end

local Gloom = { IsPositive = false }
function Gloom:bootstrap()

  -- gloom is applied on the Puppet's enemy Puppet
  assert(self.Caster)
  self.Target = CombatState:getEnemy(self.Caster:getUID())
  self.TargetRnd = self.Target:getRenderable()

  -- the particle system has to be turned off when the buff expires
  self.__Effect = nil
  self.__IsSelfCast = self.Target:getUID() == SelfPuppet:getUID()

  return self
end

function Gloom:cast()
  self:logMe()

  -- attach the buff to the puppet
  self.Target:attachBuff(self.Spell)

  SCT.ShowScrollingMessage(self.Spell:getName() .. " (" .. self.__TurnsLeft .. " turns)", false, self.TargetRnd)
  self.__Effect = FxEngine:playEffect("Gloom", self.TargetRnd)

  -- if it's our puppet that is the target, then we need to update all the tooltips
  -- to reflect the new cost
  if self.__IsSelfCast then
    local exporter = Pixy.CSpellListExporter()
    exporter:export(self.Target:getHand(), "Pixy::CSpell", "__TempSpells")
    for spell in list_iter(__TempSpells) do
      increase_cost(spell)
    end
    __TempSpells = nil
    Hand.UpdateTooltips()
  end

  return true
end

function Gloom:process()
  self:__tick()
  return true
end

function Gloom:cleanup()
  self.__Effect:stop()

  -- revert tooltip changes
  if self.__IsSelfCast then
    local exporter = Pixy.CSpellListExporter()
    exporter:export(self.Target:getHand(), "Pixy::CSpell", "__TempSpells")
    for spell in list_iter(__TempSpells) do
      revert_cost(spell)
    end
    __TempSpells = nil
    Hand.UpdateTooltips()
  end
end

subscribe_spell("Gloom", Gloom)
