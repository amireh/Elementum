local process = function(inCaster, inTarget, inSpell)
  local caster = inCaster:getEntity()
  local target = inTarget:getEntity()

	Pixy.Log("Casting Harlequin Curse on "
    .. target:getName() .. "#" .. target:getUID()
    .. " by " .. caster:getUID() .. "!")

  SCT.ShowScrollingMessage("dead (Harlequin Curse)", false, inTarget)
  target:die()
  if Selected == inTarget then
    Gfx.Dehighlight()
  end

  FxEngine:playEffect("KissOfDeath", inCaster)

	return true
end

subscribe_spell("Harlequin Curse", process)
