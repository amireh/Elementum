-- resolve script paths
do
  ScriptPrefix = Pixy.ScriptEngine:getSingletonPtr():getScriptPathPrefix()
  package.path = ScriptPrefix .. "/?.lua;" .. package.path
  ModulePrefix = Pixy.ScriptEngine:getSingletonPtr():getModulePathPrefix()
  package.cpath = ModulePrefix .. "/?.so;" .. package.cpath

  print("Scripts path: " .. ScriptPrefix .. "\nModule path: " .. ModulePrefix)
end

require("pixy")

-- clear all event bindings
Dispatcher.setup()

if not Intro then Intro = {} end
if not Lobby then Lobby = {} end

require("intro/intro")
require("intro/main_menu")
require("intro/profiles")
require("lobby/lobby")
require("lobby/chat")
require("lobby/input")
require("lobby/decks")
require("intro/bindings")
