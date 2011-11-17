%module Pixy
%{
%}

%include "std_string.i"

%include "Pixy.i"
//%include "EventUID.i"

// GameStates
%include "GameState.i"
%include "Combat.i"
%include "Intro.i"

// Entities
%include "Animable.i"
%include "Mobile.i"
%include "Caster.i"
%include "Renderable.i"
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

%luacode {
  print "Elementum SWIG module loaded ok"
}
