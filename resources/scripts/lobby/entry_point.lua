ScriptPrefix = ""
ModulePrefix = ""

function resolvePaths()
  ScriptPrefix = Pixy.ScriptEngine:getSingletonPtr():getScriptPathPrefix()
  package.path = ScriptPrefix .. "/?.lua;" .. package.path
  ModulePrefix = Pixy.ScriptEngine:getSingletonPtr():getModulePathPrefix()
  package.cpath = ModulePrefix .. "/?.so;" .. package.cpath

  print("Scripts path: " .. ScriptPrefix .. "\nModule path: " .. ModulePrefix)
end

resolvePaths()

require("pixy")

Pixy.registerGlobals()
clearBindings()

if not Lobby then Lobby = {} end

require("lobby/lobby")
require("lobby/chat")
require("lobby/bindings")
require("lobby/input")

Lobby.bind()