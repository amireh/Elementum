local SuddenCraven = {}
function SuddenCraven:cast()
  FxEngine:playEffect("SuddenCraven", self.Caster)
end

subscribe_spell("Sudden Craven", SuddenCraven)
