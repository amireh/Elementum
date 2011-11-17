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
  #include "Deck.h"
  #include "BaseDeck.h"
%}

%import(module="Pixy") "BaseDeck.i"

namespace Pixy
{

  class Caster;
  class Deck : public BaseDeck {
	public:
    typedef Spell spell_t;
    typedef Caster caster_t;
    typedef std::vector<spell_t const*> spells_t;

		Deck(caster_t const*);
		virtual ~Deck();

    virtual spells_t const& getSpells() const;

	};
}
