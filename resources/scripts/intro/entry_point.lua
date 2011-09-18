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

if not Intro then Intro = {} end
if not Lobby then Lobby = {} end

require("intro/main_menu")
require("intro/profiles")
require("combat/effects")
require("intro/bindings")
require("lobby/lobby")
require("lobby/chat")
require("lobby/input")
require("lobby/decks")
--~ require("lobby/bindings")

Intro.bind()
--~ MainMenu.attach()
