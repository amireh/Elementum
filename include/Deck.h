/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_Deck_H
#define H_Deck_H

#include "Pixy.h"
#include "BaseDeck.h"
#include "Spell.h"
#include <vector>
#include <cassert>

namespace Pixy
{

  class Caster;
  /**
   * @class Deck
   * @brief
   * Decks contain a spell pool from which Puppets will be drawing spells into
   * their hand. The deck is responsible for deciding which spell the Puppet
   * receives at every start of turn.
   */
  class Deck : public BaseDeck {
	public:
    typedef Spell spell_t;
    typedef Caster caster_t;
    typedef std::vector<spell_t const*> spells_t;

		Deck(caster_t const*);
		virtual ~Deck();

    /**
     * @brief
     * Returns the spell pool this Deck contains.
     **/
    virtual spells_t const& getSpells() const;

    /**
     * @brief
     * Adds the given spell to the spell pool this Deck contains.
     *
     * Ownership of the passed spell object is transferred to this Deck object,
     * and when it's destroyed, it will destroy all Spell objects in the pool
     * unless _clear() was called manually in which case you must be responsible
     * for destroying the spell objects else there'll be leaks.
     **/
    virtual void _assignSpell(spell_t *const inSpell);

    /**
     * @brief
     * Clears the pool of spells referenced by this deck.
     *
     * This method does NOT destroy the spell objects.
     **/
    virtual void _clear();


	protected:
		//log4cpp::Category* mLog;
		spells_t mSpells;
		caster_t const* mCaster;
	};
}

#endif // H_Deck_H
