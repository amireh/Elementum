/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

// Caster.cpp
#include "Caster.h"
#include "Spell.h"
#include "Entity.h"
#include "PixyUtility.h"

namespace Pixy
{

	Caster::~Caster()
	{
    while (!mSpells.empty()) {
      delete mSpells.back();
      mSpells.pop_back();
    }
    while (!mBuffs.empty()) {
      delete mBuffs.back();
      mBuffs.pop_back();
    }
	}

  Caster::Caster()//(BaseEntity* inOwner) : mOwner(inOwner)
  {
	}

  Caster::Caster(const Caster& src)
  {
    copyFrom(src);
  }

  Caster& Caster::operator=(const Caster& rhs)
  {
    // check for self-assignment
    if (this == &rhs)
      return (*this);

    copyFrom(rhs);

    return (*this);
  }

  void Caster::copyFrom(const Caster& src)
  {

    // deep copy the target's spells
    if (!src.mSpells.empty())
      for (spells_t::const_iterator _spell = src.mSpells.begin(); _spell != src.mSpells.end(); ++_spell)
        attachSpell( new spell_t(*(*_spell)) );

    // ... and the target's buffs
    if (!src.mBuffs.empty())
      for (spells_t::const_iterator _buff = src.mBuffs.begin(); _buff != src.mBuffs.end(); ++_buff)
        attachSpell( new spell_t(*(*_buff)) );

  }

	Caster::spells_t const& Caster::getSpells() {
    return mSpells;
  }
	Caster::spells_t const& Caster::getBuffs() {
    return mBuffs;
  }

	void Caster::attachSpell(spell_t* inSpell)
	{
		mSpells.push_back(inSpell);
		//std::cout
    //  <<"Caster: Spell " << inSpell->getName()
    //  << "#" << inSpell->getUID()
    //  << " attached to hand.\n";

    //~ mSpells.back()->setCaster(this);
    //std::cout << "\tSpell " << inSpell->getName() << "#" << inSpell->getUID()
    //  << " is now owned by " << mOwner->getName() << "#" << mOwner->getUID() << "\n";
	}

	void Caster::attachBuff(spell_t* inSpell)
	{
		mBuffs.push_back(inSpell);
		//std::cout
    //  <<"Caster: Spell " << inSpell->getName()
    //  << "#" << inSpell->getUID()
    //  << " attached to hand.\n";

    //~ mBuffs.back()->setTarget(this);
	}

	void Caster::detachSpell(int inUID, bool remove)
	{
    spell_t* lSpell = 0;
		spells_t::iterator it;
		for(it = mSpells.begin(); it != mSpells.end(); ++it)
			if ((*it)->getUID() == inUID)
			{
        lSpell = *it;
				mSpells.erase(it);
				break;
			}

    assert(lSpell);

    //std::cout
    //  << "Caster: Spell " << lSpell->getName()
    //  << "#" << lSpell->getUID()
    //  << " detached from hand.\n";

    if (remove)
      delete lSpell;
    lSpell = 0;
	}

	void Caster::detachBuff(int inUID, bool remove)
	{
    spell_t* lSpell = 0;
		spells_t::iterator it;
		for(it = mBuffs.begin(); it != mBuffs.end(); ++it)
			if ((*it)->getUID() == inUID)
			{
        lSpell = *it;
				mBuffs.erase(it);
				break;
			}

    assert(lSpell);

    //std::cout
    //  << "Caster: Spell " << lSpell->getName()
    //  << "#" << lSpell->getUID()
    //  << " detached from hand.\n";

    if (remove)
      delete lSpell;
    lSpell = 0;
	}

	int Caster::nrSpells() {
		return mSpells.size();
	}
	int Caster::nrBuffs() {
		return mBuffs.size();
	}

	Caster::spell_t* Caster::getSpell(int inUID) {
		spells_t::const_iterator lSpell;
		for (lSpell = mSpells.begin(); lSpell != mSpells.end(); ++lSpell)
			if ((*lSpell)->getUID() == inUID)
				return *lSpell;

    throw invalid_uid("couldn't find a spell with uid" + stringify(inUID));
	}

	Caster::spell_t* Caster::getBuff(int inUID) {
		spells_t::const_iterator lSpell;
		for (lSpell = mBuffs.begin(); lSpell != mBuffs.end(); ++lSpell)
			if ((*lSpell)->getUID() == inUID)
				return *lSpell;

    throw invalid_uid("couldn't find a buff with uid" + stringify(inUID));
	}

  bool Caster::hasBuff(int inUID) {
		spells_t::iterator lSpell = mBuffs.begin();
		for (lSpell; lSpell != mBuffs.end(); ++lSpell)
			if ((*lSpell)->getUID() == inUID)
				return true;

    return false;
  }

  bool Caster::hasBuffWithName(std::string const& inName)
  {
		spells_t::const_iterator lSpell;
		for (lSpell = mBuffs.begin(); lSpell != mBuffs.end(); ++lSpell)
			if ((*lSpell)->getName() == inName)
				return true;

    //std::cout << "**** I don't have the requested buff!" << inUID << "\n";
    return false;
  }
} // end of namespace
