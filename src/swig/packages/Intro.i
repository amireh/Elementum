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
  #include "Intro.h"
  #include <list>
%}

namespace Pixy {

  %nodefaultctor Intro;
  %nodefaultdtor Intro;

  class Puppet;
	class Intro{
	public:

    typedef std::list<Puppet*> puppets_t;

		static Intro* getSingletonPtr( void );
		static Intro& getSingleton();

    std::string const& getPuppetName() const;
    void setPuppetName(std::string);

    puppets_t const& getPuppets();
    Puppet* getPuppet();

	};
} // end of namespace
