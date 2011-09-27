#include "CPuppet.h"
#include "Renderable.h"
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
  : mRenderable(0), mEnemy(0) {

    /*mSceneObject = 0;
    mSceneNode = 0;
    mEntity = this;
    */
    mLog = 0;
  };

  bool CPuppet::live() {
    mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, mName);
    mLog->infoStream() << "created";

    mRenderable = new Renderable(this);
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

    mRenderable->hide();

    mLog->infoStream() << "dead";
  };

  CPuppet::~CPuppet() {
    /*mRenderable
    mSceneObject = 0;
    mSceneNode = 0;
    mEntity = 0;*/
    if (mRenderable)
      delete mRenderable;

    while (!mSpells.empty()) {
      delete mSpells.back();
      mSpells.pop_back();
    }

    while (!mBuffs.empty()) {
      delete mBuffs.back();
      mBuffs.pop_back();
    }

    mRenderable = 0;

    if (mLog) {
      mLog->infoStream() << "destroyed";
      delete mLog;
      mLog = 0;
    }
  };

  Renderable* CPuppet::getRenderable() {
    return mRenderable;

  }

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

	std::list<CSpell*> const& CPuppet::getHand(){ return mHand; };

	int CPuppet::nrSpellsInHand() {
		return mHand.size();
	}

  CSpell* CPuppet::getSpell(int inUID) {
    hand_t::const_iterator lSpell;
    for (lSpell = mHand.begin(); lSpell != mHand.end(); ++lSpell)
      if ((*lSpell)->getUID() == inUID)
        return *lSpell;

    assert(false);
    throw invalid_uid("couldn't find a spell with uid" + stringify(inUID));
    return 0;
  }
	void CPuppet::attachSpell(CSpell* inSpell)
	{
		mHand.push_back(inSpell);
    inSpell->setCaster(mRenderable);
		//std::cout<<"Hero: Spell " << inSpell->getName() << "#" << inSpell->getUID() << " attached to hand.\n";
	};

	void CPuppet::detachSpell(int inUID, bool remove)
	{
		CSpell* lSpell = 0;
		hand_t::iterator it;
		for(it = mHand.begin(); it != mHand.end(); ++it)
			if ((*it)->getUID() == inUID)
			{
        lSpell = *it;
				mHand.erase(it);
				break;
			}

    assert(lSpell);
    if (remove)
      delete lSpell;

    lSpell = 0;
	};

  CPuppet::spells_t const& CPuppet::getBuffs() const {
    return mBuffs;
  }
  void CPuppet::attachBuff(CSpell* inSpell)
	{
		mBuffs.push_back(inSpell);
    inSpell->setCaster(mRenderable);
		mLog->infoStream() << "buff " << inSpell->getName() << "#" << inSpell->getUID() << " attached to hand.\n";
	};

	void CPuppet::detachBuff(int inUID)
	{
		CSpell* lSpell = 0;
		spells_t::iterator it;
		for(it = mBuffs.begin(); it != mBuffs.end(); ++it)
			if ((*it)->getUID() == inUID)
			{
        lSpell = *it;
				mBuffs.erase(it);
				break;
			}

    assert(lSpell);
    delete lSpell;
	};

  bool CPuppet::hasBuff(int inUID) {
		spells_t::iterator lSpell = mBuffs.begin();
		for (lSpell; lSpell != mBuffs.end(); ++lSpell)
			if ((*lSpell)->getUID() == inUID)
				return true;

    return false;
  }

	/* ------------------------
	 * UNITS
	 * ------------------------ */
  void CPuppet::attachUnit(CUnit* inUnit) {
    mUnits.push_back(inUnit);
    inUnit->setOwner(this);
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
  }
  CUnit* CPuppet::getUnit(const int inUID) {
    units_t::iterator lUnit = mUnits.begin();
		for (lUnit; lUnit != mUnits.end(); ++lUnit)
			if ((*lUnit)->getUID() == inUID)
				return *lUnit;

    throw invalid_uid("couldn't find a unit with uid" + stringify(inUID));
  }

  CPuppet::units_t const& CPuppet::getUnits() const { return mUnits; }

  void CPuppet::updateFromEvent(const Event& evt) {
    Puppet::updateFromEvent(evt);

    updateTextOverlay();
  }

  void CPuppet::updateTextOverlay() {
    if (mRenderable && mRenderable->getText())
      mRenderable->getText()->setCaption(stringify(mHP));
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
