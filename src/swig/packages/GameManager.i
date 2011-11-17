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
  #include "GameManager.h"
%}

namespace Pixy {

  %nodefaultctor GameManager;

  class GameManager
  {
    public:
    static GameManager& getSingleton();
    static GameManager* getSingletonPtr();

    void changeState(Pixy::GameState *inState);
    void requestShutdown();

  };

}
