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
  #include "Combat.h"
  #include <list>
%}

namespace Pixy
{
  %nodefaultctor Combat;

  class Puppet;
  class Unit;
	class Combat : public GameState {
	public:
    typedef std::list<Puppet*> puppets_t;

		static Combat* getSingletonPtr( void );
		static Combat& getSingleton();

    puppets_t const& getPuppets();
    Puppet* getPuppet();
    Puppet* getEnemy(int inUID);
    Puppet* getPuppet(int inUID);
    Puppet* getActivePuppet();
    Unit* getUnit(int inUID);

    void __setIsDebugging(bool setting);
    bool __isDebugging() const;
	};
} // end of namespace
