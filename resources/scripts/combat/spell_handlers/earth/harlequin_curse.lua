local HarlequinCurse = {}
function HarlequinCurse:cast()
  self:logMe()

  SCT.ShowScrollingMessage("dead (Harlequin Curse)", false, self.TargetRnd)
  self.Target:die()
  if Selected == self.TargetRnd then
    Gfx.Dehighlight()
  end

  FxEngine:playEffect("KissOfDeath", self.CasterRnd)

	return true
end

subscribe_spell("Harlequin Curse", HarlequinCurse)
