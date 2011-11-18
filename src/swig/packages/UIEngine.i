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
  #include "UIEngine.h"
%}

namespace CEGUI {
  %nodefaultctor Window;
  %nodefaultdtor Window;
  class Window {
  };

  %nodefaultctor UBox;
  %nodefaultdtor UBox;
  class UBox {

  };
}

namespace Pixy {

  %nodefaultctor UIEngine;

  class Spell;
	class UIEngine {

	public:
		static UIEngine* getSingletonPtr();

    void setMargin(CEGUI::Window*, CEGUI::UBox&);
    void refreshSize();
    void connectAnimation(CEGUI::Window*, std::string inAnim);
    void refreshTooltipSize(CEGUI::Window* inWindow, Spell* inSpell);
    void reportLuaError(std::string const& inMsg);

	};
}
