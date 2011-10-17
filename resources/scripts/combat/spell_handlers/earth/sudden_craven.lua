local SuddenCraven = {}
function SuddenCraven:cast()
  FxEngine:playEffect("SuddenCraven", self.CasterRnd)
end

subscribe_spell("Sudden Craven", SuddenCraven)
