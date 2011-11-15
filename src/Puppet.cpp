/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#include "Puppet.h"
#include "Unit.h"
#include "PixyUtility.h"

namespace Pixy
{

  Puppet::Puppet()
  {
    setRank(Rank::Puppet);
    _setOwner(this);
  }

  Puppet::~Puppet()
  {
    while (!mUnits.empty())
    {
      this->detachUnit(mUnits.front()->getUID(), true);
    }

    while (!mDecks.empty())
    {
      this->detachDeck(mDecks.front()->getName());
    }

    mDeck = 0;

    _setOwner(0);
  };



  // ----- Decks -----
  void Puppet::attachDeck(BaseDeck* inDeck) {
    if (!mDeck)
      _setDeck(inDeck);

    mDecks.push_back(static_cast<Deck*>(inDeck));
  }
  void Puppet::detachDeck(std::string const& inName)
  {
    for (Puppet::decks_t::iterator _deck = mDecks.begin(); _deck != mDecks.end(); ++_deck)
    {
      if ((*_deck)->getName() == inName)
      {
        delete (*_deck);
        mDecks.erase(_deck);
        break;
      }
    }
  }

  Puppet::decks_t const& Puppet::getDecks() const {
    return mDecks;
  }

  void Puppet::_setDeck(BaseDeck* inDeck) {
		mDeck = static_cast<Deck*>(inDeck);
	}
	Puppet::deck_t* Puppet::getDeck() {
		return mDeck;
	}
  bool Puppet::hasDeck(std::string const& inName) const {
    decks_t::const_iterator itr;
    for (itr = mDecks.begin(); itr != mDecks.end(); ++itr)
      if ((*itr)->getName() == inName)
        return true;

    return false;
  }
  int Puppet::nrDecks() const {
    return mDecks.size();
  }

  /* ------------------------
	 * UNITS
	 * ------------------------ */
  void Puppet::attachUnit(unit_t* inUnit) {
    mUnits.push_back(inUnit);
    inUnit->_setOwner(this);

    //std::cout
    //  << mUID << " attached a unit to my control: "
    //  << inUnit->getName() << "#" << inUnit->getUID() << "\n";
  }
  void Puppet::detachUnit(int inUID, bool remove) {
    unit_t* lUnit = 0;
		units_t::iterator it;
		for(it = mUnits.begin(); it != mUnits.end(); ++it)
			if ((*it)->getUID() == inUID)
			{
        lUnit = *it;
				mUnits.erase(it);
				break;
			}

    if (remove)
      delete lUnit;
  }
  Puppet::unit_t* Puppet::getUnit(int inUID) {
    units_t::iterator lUnit;
		for (lUnit = mUnits.begin(); lUnit != mUnits.end(); ++lUnit)
			if ((*lUnit)->getUID() == inUID)
				return *lUnit;

    throw invalid_uid("couldn't find a unit with uid" + stringify(inUID));
  }
  Puppet::units_t& Puppet::getUnits() {
    return mUnits;
  }

  Entity* Puppet::toEntity() const {
    return static_cast<Entity*>((Puppet*)this);
  }

  bool Puppet::hasUnitWithName(std::string const& inName) const
  {
		units_t::const_iterator lUnit;
		for (lUnit = mUnits.begin(); lUnit != mUnits.end(); ++lUnit)
			if ((*lUnit)->getName() == inName)
				return true;

    //std::cout << "**** I don't have the requested buff!" << inUID << "\n";
    return false;
  }


  void Puppet::updateTextOverlay() {
    std::string cap = "";
    cap += stringify(mHP);
    getText()->setCaption(cap);
  }
} // end of Pixy namespace
