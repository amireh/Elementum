/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#include "CPuppet.h"
//~ #include "Renderable.h"
#include "CDeck.h"
#include "CUnit.h"
#include "CSpell.h"
#include "PixyUtility.h"
#include "ogre/MovableTextOverlay.h"
#include "Event.hpp"
#include "EventManager.h"
#include "Combat.h"

namespace Pixy
{

  CPuppet::CPuppet()
  : //mRenderable(0),
    mEnemy(0) {

    /*mSceneObject = 0;
    mSceneNode = 0;
    mEntity = this;
    */
    mLog = 0;
  };

  bool CPuppet::live() {
    Puppet::live();
    CEntity::live();

    mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, mName);
    mLog->infoStream() << "created";

    //~ mRenderable = new Renderable(this);
    updateTextOverlay();

    mEnemy = 0;
    Combat::puppets_t lPuppets = Combat::getSingleton().getPuppets();
    for (Combat::puppets_t::const_iterator itr = lPuppets.begin();
      itr != lPuppets.end();
      ++itr)
    {
      if ((*itr)->getUID() != mOwner->getUID()) {
        mEnemy = *itr;
        break;
      }
    }

    return true;
  };

  void CPuppet::die() {
    Puppet::die();

    //~ mRenderable->hide();

    mLog->infoStream() << "dead";
  };

  CPuppet::~CPuppet() {
    /*mRenderable
    mSceneObject = 0;
    mSceneNode = 0;
    mEntity = 0;*/
    //~ if (mRenderable)
      //~ delete mRenderable;

    while (!mSpells.empty()) {
      delete mSpells.back();
      mSpells.pop_back();
    }

    while (!mBuffs.empty()) {
      delete mBuffs.back();
      mBuffs.pop_back();
    }

    while (!mUnits.empty()) {
      delete mUnits.back();
      mUnits.pop_back();
    }

    //~ mRenderable = 0;

    if (mLog) {
      mLog->infoStream() << "destroyed";
      delete mLog;
      mLog = 0;
    }
  };

  /*CDeck* CPuppet::getDeck() {
    mLog->infoStream() << "returning deck;";
    assert(mDeck != 0);
    CSpell* lSpell = mDeck->getSpell("Summon: Fetish Zij");
    if (!lSpell) {
      mLog->errorStream() << "didn't find the spell";
    } else {
      mLog->infoStream() << "Spell name " << lSpell->getName();
    }
    return mDeck;
  }*/


	/* ------------------------
	 * UNITS
	 * ------------------------ */
  /*void CPuppet::attachUnit(CUnit* inUnit) {
    mUnits.push_back(inUnit);
    inUnit->_setOwner(this);
    inUnit->_setEnemy(mEnemy);

    mLog->infoStream()
      << mUID << " attached a cunit to my control: "
      << inUnit->getName() << "#" << inUnit->getUID();

    assert(inUnit->getOwner());
  }
  void CPuppet::detachUnit(int inUID, bool remove) {
    CUnit* lUnit = 0;
		units_t::iterator it;
		for(it = mUnits.begin(); it != mUnits.end(); ++it)
			if ((*it)->getUID() == inUID)
			{
        lUnit = *it;
				mUnits.erase(it);
				break;
			}

    assert(lUnit);
    if (remove)
      delete lUnit;
    else
      mLog->infoStream() << "softly removed a unit from my control " << inUID;
  }*/
  CUnit* CPuppet::getUnit(const int inUID) {
    units_t::iterator lUnit = mUnits.begin();
		for (lUnit; lUnit != mUnits.end(); ++lUnit)
			if ((*lUnit)->getUID() == inUID)
				return dynamic_cast<CUnit*>(*lUnit);

    throw invalid_uid("couldn't find a unit with uid" + stringify(inUID));
  }

  /*CPuppet::units_t const& CPuppet::getUnits() const { return mUnits; }*/

  void CPuppet::deserialize(const Event& evt) {
    Puppet::deserialize(evt);

    updateTextOverlay();
  }

  void CPuppet::updateTextOverlay() {
    if (getText())
      getText()->setCaption(stringify(mHP));
  }

  void CPuppet::onVictory() {

		//mRenderable->setBaseAnimation(Renderable::ANIM_DANCE, true);
		//mRenderable->setTopAnimation(Renderable::ANIM_NONE);
		//// disable hand animation because the dance controls hands
		//mRenderable->mAnims[Renderable::ANIM_HANDS_RELAXED]->setEnabled(false);
  }

  void CPuppet::setHP(int inHP) {
    //int lastHP = getHP();
    Puppet::setHP(inHP);
    /*int incHP = getHP() - lastHP;

    Event e(EventUID::EntityStatChanged);
    e.setProperty("Stat", "HP");
    e.setProperty("Value", incHP);
    e.Any = (void*)this->mRenderable;
    EventManager::getSingleton().hook(e);
    updateTextOverlay();*/
  }
} // end of namespace
