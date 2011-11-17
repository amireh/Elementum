local BoneArmor = { IsPositive = true }
function BoneArmor:cast()
  self:logMe()

  if self.Target:hasBuff(self.Spell:getUID()) then return true end

  FxEngine:playEffect("BoneArmor", self.Target)
  self.Target:attachBuff(self.Spell)
  --~ self.Spell:setExpired(false)
  --~ self.__TurnsLeft = 120 -- bone armor is supposed to be permanent
  --~ SCT.ShowScrollingMessage(self.Spell:getName(), true, self.Target)

	return true
end

function BoneArmor:process()
end

subscribe_spell("Bone Armor", BoneArmor)
