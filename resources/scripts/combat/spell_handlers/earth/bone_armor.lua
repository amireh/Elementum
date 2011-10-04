local process = function(inCaster, inTarget, inSpell)
  local unit = nil
  if not inSpell:getTarget() then unit = inTarget:getEntity() else
    unit = inSpell:getTarget():getEntity()
  end

  if unit:hasBuff(inSpell:getUID()) then return true end

	Pixy.Log("I'm shielding with Bone Armor!")

  FxEngine:playEffect("BoneArmor", inTarget)
  unit:attachBuff(inSpell)
  inSpell:setExpired(false)
  SCT.ShowScrollingMessage(inSpell:getName(), true, inTarget)

	return true
end

subscribe_spell("Bone Armor", process)
