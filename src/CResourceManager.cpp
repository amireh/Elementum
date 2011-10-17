/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#include "CResourceManager.h"

namespace Pixy {

	CResourceManager::CResourceManager() {
	}

	CResourceManager::~CResourceManager() {
	}


  CResourceManager::spell_t* const CResourceManager::getSpell(std::string const& inName, char inRace) {
    spells_t::const_iterator itr;
    spells_t* lSpells = &mSpells[inRace];

    for (itr = (*lSpells).begin(); itr != (*lSpells).end(); ++itr)
      if ((*itr)->getName() == inName)
        return new CSpell((**itr));

    return 0;
  }


  CResourceManager::unit_t* const  CResourceManager::getUnit(std::string const& inName, char inRace) {
    units_t::const_iterator itr;
    units_t* lUnits = &mUnits[inRace];

    for (itr = (*lUnits).begin(); itr != (*lUnits).end(); ++itr)
      if ((*itr)->getName() == inName)
        return new CUnit(**itr);

    return 0;
  }

}
