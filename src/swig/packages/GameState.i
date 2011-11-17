/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

%module Pixy
%{
  #include "GameState.h"
%}

namespace Pixy {

  %nodefaultctor GameState;

  class GameState {

    enum State {
      Intro,
      Combat
    };

    void changeState( Pixy::GameState *state );
    void requestShutdown( void );
    bool isCurrentState();
  };
}
