%module Pixy
%{
%}

%include "std_string.i"

%include "Pixy.i"

// GameStates
%include "GameState.i"
%include "Combat.i"
%include "Intro.i"

// Entities
%include "Animable.i"
%include "Mobile.i"
%include "Renderable.i"
%include "Caster.i"
%include "Deck.i"
%include "Entity.i"
%include "Puppet.i"
%include "Spell.i"
%include "Unit.i"

// Managers
%include "GameManager.i"
%include "InputManager.i"
%include "NetworkManager.i"

// Engines
%include "GfxEngine.i"
%include "FxEngine.i"
%include "UIEngine.i"
%include "ScriptEngine.i"

// Misc
%include "OgreRTT.i"
%include "LuaExporter.i"

%luacode {
  print "--"
  print "Elementum SWIG module loaded ok"
  print "dumping Pixy table"
  for k in pairs(Pixy) do print("# " .. k) end
  print "--"
}
