/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#include "EntityManager.h"
#include "PixyUtility.h"

using std::vector;
using std::string;
namespace Pixy {

	EntityManager::EntityManager() {
		mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, "EntityMgr");
	}

	EntityManager::~EntityManager() {
    mLog->infoStream() << "shutting down";

    this->clear();

		if (mLog) {
			delete mLog;
			mLog = NULL;
		}
	}

  Spell* EntityManager::createSpell(char inRace)
  {
    spell_t* lSpell = new spell_t();
    lSpell->_setRace(inRace);
    mSpells[inRace].push_back(lSpell);
    return lSpell;
  }

  Unit* EntityManager::createUnit(char inRace)
  {
    unit_t *lUnit = new unit_t();
    lUnit->_setRace(inRace);
    mUnits[inRace].push_back(lUnit);
    return lUnit;
  }

  Puppet* EntityManager::createPuppet(int inUID, std::string inName, char inRace)
  {
    puppet_t *lPuppet = new puppet_t();
    lPuppet->_setUID(inUID);
    lPuppet->_setName(inName);
    lPuppet->_setRace(inRace);
    mPuppets.push_back(lPuppet);
    return lPuppet;
  }

  Deck* EntityManager::createDeck(BasePuppet const* inPuppet)
  {
    deck_t *lDeck = new deck_t(static_cast<const Puppet*>(inPuppet));
    mDecks.push_back(lDeck);
    return lDeck;
  }

  Talent* EntityManager::createTalent(char inRace)
  {
    talent_t *lTalent = new talent_t();
    lTalent->_setRace(inRace);
    mTalents[inRace].push_back(lTalent);
    return lTalent;
  }

  EntityManager::spell_t* const EntityManager::getSpell(std::string const& inName) {
    spell_t* lSpell = 0;
    for (int i; i < 4; ++i) {
      lSpell = getSpell(inName, i);
      if (lSpell)
        return lSpell;
    }

    throw UnidentifiedResource("couldnt find a spell named " + inName );
    return 0;
  }

  EntityManager::spell_t* const EntityManager::getSpell(std::string const& inName, char inRace) {
    spells_t::const_iterator itr;
    spells_t* lSpells = &mSpells[inRace];

    for (itr = (*lSpells).begin(); itr != (*lSpells).end(); ++itr)
      if ((*itr)->getName() == inName)
        return new spell_t((**itr));

    return 0;
  }

  EntityManager::unit_t* const  EntityManager::getUnit(std::string const& inName) {
    unit_t* lUnit = 0;
    for (int i; i < 4; ++i) {
      lUnit = getUnit(inName, i);
      if (lUnit)
        return lUnit;
    }

    throw UnidentifiedResource("couldnt find a unit named " + inName );
    return 0;
  }

  EntityManager::unit_t* const  EntityManager::getUnit(std::string const& inName, char inRace) {
    units_t::const_iterator itr;
    units_t* lUnits = &mUnits[inRace];

    for (itr = (*lUnits).begin(); itr != (*lUnits).end(); ++itr)
      if ((*itr)->getName() == inName)
        return new unit_t((**itr));

    return 0;
  }


  const EntityManager::talent_t* const EntityManager::getTalent(std::string const& inName) {
    talents_t::const_iterator itr;
    for (int i=0; i < 4; ++i)
    {
      for (itr = mTalents[i].begin(); itr != mTalents[i].end(); ++itr)
        if ((*itr)->getName() == inName)
          return (*itr);
    }

    throw UnidentifiedResource("couldnt find a talent named " + inName );
    return 0;
  }

  const EntityManager::talent_t* const EntityManager::getTalent(std::string const& inName, char inRace) {
    talents_t::const_iterator itr;
    for (itr = mTalents[inRace].begin(); itr != mTalents[inRace].end(); ++itr)
        if ((*itr)->getName() == inName)
          return (*itr);

    throw UnidentifiedResource("couldnt find a talent named " + inName );
    return 0;
  }


  EntityManager::spell_t const* const EntityManager::getModelSpell(std::string const& inName) {
    spells_t::const_iterator itr;

    for (int i; i < 4; ++i)
      for (itr = mSpells[i].begin(); itr != mSpells[i].end(); ++itr)
        if ((*itr)->getName() == inName)
          return (*itr);

    std::cerr << "couldnt find a spell named " << inName << "\n";
    return 0;
  }

  EntityManager::unit_t const* const EntityManager::getModelUnit(std::string const& inName) {
    units_t::const_iterator itr;

    for (int i; i < 4; ++i)
      for (itr = mUnits[i].begin(); itr != mUnits[i].end(); ++itr)
        if ((*itr)->getName() == inName)
          return (*itr);

    std::cerr << "couldnt find a unit named " << inName << "\n";
    return 0;
  }

  EntityManager::spells_t const& EntityManager::_getSpells(char inRace)
  {
    assert(inRace >= 0 && inRace < 4);
    return mSpells[inRace];
  }
  EntityManager::units_t const& EntityManager::_getUnits(char inRace)
  {
    assert(inRace >= 0 && inRace < 4);
    return mUnits[inRace];
  }
  EntityManager::talents_t const& EntityManager::_getTalents(char inRace)
  {
    assert(inRace >= 0 && inRace < 4);
    return mTalents[inRace];
  }
  EntityManager::puppets_t& EntityManager::_getPuppets() {
    return mPuppets;
  }

  void EntityManager::clear()
  {
    while (!mPuppets.empty())
    {
      delete mPuppets.back();
      mPuppets.pop_back();
    }

    for (int i; i < 4; ++i) {
      while (!mSpells[i].empty()) {
        // delete only the spells that aren't minion abilities
        //~ if (mSpells[i].back()->getCaster() == 0)
          delete mSpells[i].back();

        mSpells[i].pop_back();
      }

      while (!mUnits[i].empty()) {
        delete mUnits[i].back();
        mUnits[i].pop_back();
      }

      while (!mTalents[i].empty()) {
        delete mTalents[i].back();
        mTalents[i].pop_back();
      }
    }


  }

  EntityManager::puppet_t*
  EntityManager::getPuppet(std::string const& inName) {
    return getPuppetInList(inName, mPuppets);
  }

  EntityManager::puppet_t*
  EntityManager::getPuppetInList(std::string const& inName, puppets_t const& inPuppets) {
    puppets_t::const_iterator itr;
    for (itr = inPuppets.begin(); itr != inPuppets.end(); ++itr)
      if ((*itr)->getName() == inName)
        return (*itr);

    return 0;
  }

}
