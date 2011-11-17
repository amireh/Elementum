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
  #include "InputManager.h"
%}

namespace Pixy {

  %nodefaultctor InputManager;

	struct Event;
	class InputManager {

	public:
		static InputManager* getSingletonPtr();

    OIS::Mouse*    getMouse( void );
    OIS::Keyboard* getKeyboard( void );
	};
}
