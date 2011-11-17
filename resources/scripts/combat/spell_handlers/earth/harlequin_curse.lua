local HarlequinCurse = {}
function HarlequinCurse:cast()
  self:logMe()

  SCT.ShowScrollingMessage("dead (Harlequin Curse)", false, self.Target)
  self.Target:die()
  if Selected == self.Target then
    Gfx.Dehighlight()
  end

  FxEngine:playEffect("KissOfDeath", self.Caster)

	return true
end

subscribe_spell("Harlequin Curse", HarlequinCurse)
