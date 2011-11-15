/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#include "Deck.h"
#include "Spell.h"

namespace Pixy
{

  Deck::Deck(caster_t const* inCaster)
  {
		//~ mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, "Deck");
    mCaster = inCaster;
    //~ mLog->infoStream() << "built, not yet generated";
  }

  Deck::~Deck()
  {
    while (!mSpells.empty()) {
      delete mSpells.back();
      mSpells.pop_back();
    }
    //mSpells.clear(); // we don't own the spell_t objects, don't delete them
    mCaster = 0;

    //~ mLog->infoStream() << "cleared successfully!";
		//~ delete mLog;
  }

  Deck::spells_t const& Deck::getSpells() const {
    return mSpells;
  }

  void Deck::_assignSpell(BaseSpell *const inSpell)
  {
    assert(inSpell != 0);
    mSpells.push_back(static_cast<Spell*>(inSpell));

    //std::cout << "\t" << mName << " - attached spell " << inSpell->getName() << "\n";
  }

  void Deck::_clear()
  {
    mSpells.clear();
  }

}
