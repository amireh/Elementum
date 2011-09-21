--package.path = "./?.lua;../resources/scripts/?.lua;../Plugins/?.lua;"
--package.cpath = "../Plugins/?.so;" .. package.cpath

ScriptPrefix = ""
ModulePrefix = ""

function resolvePaths()
  ScriptPrefix = Pixy.ScriptEngine:getSingletonPtr():getScriptPathPrefix()
  package.path = ScriptPrefix .. "/?.lua;" .. package.path
  ModulePrefix = Pixy.ScriptEngine:getSingletonPtr():getModulePathPrefix()
  package.cpath = ModulePrefix .. "/?.so;" .. package.path

  print("Scripts path: " .. ScriptPrefix .. "\nModule path: " .. ModulePrefix)
end

resolvePaths()

require("pixy")

Pixy.registerGlobals()
clearBindings()

require("combat/combat")
require("combat/bootstrap")
--require("combat/debug")
require("combat/ui")
require("combat/turns")
require("combat/spells")
require("combat/gfx")
require("combat/effects")
require("combat/bindings")

arbitraryFunc = arbitraryFuncCombat

-- and attach UI layout!
Pixy.UI.attach(Pixy.UI.Combat.Config.LayoutPath)
Pixy.UI.Combat.registerGlobals()

Combat.bind()
Combat.PrepareScene()
--~ Pixy.Effects.Configure()
