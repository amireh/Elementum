-- resolve script paths
do
  ScriptPrefix = Pixy.ScriptEngine_getSingletonPtr():getScriptPathPrefix()
  package.path = ScriptPrefix .. "/?.lua;" .. package.path
  ModulePrefix = Pixy.ScriptEngine_getSingletonPtr():getModulePathPrefix()
  package.cpath = ModulePrefix .. "/?.so;" .. package.path

  print("Scripts path: " .. ScriptPrefix .. "\nModule path: " .. ModulePrefix)
end

require("pixy")

if not Combat then Combat = {} end

require("combat/globals")
require("combat/combat")
require("combat/ui")
require("combat/turns")
require("combat/gfx")
require("combat/input")
require("combat/puppets")
require("combat/units")
require("combat/spells")
require("combat/bindings")
