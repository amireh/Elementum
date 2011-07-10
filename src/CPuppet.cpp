#include "CPuppet.h"
#include "Renderable.h"
#include "CDeck.h"
#include "CUnit.h"
#include "CSpell.h"
#include "PixyUtility.h"
#include "ogre/MovableTextOverlay.h"

namespace Pixy
{

  CPuppet::CPuppet() {
    mRenderable = new Renderable(this);
    /*mSceneObject = 0;
    mSceneNode = 0;
    mEntity = this;
    */
  };

  bool CPuppet::live() {
    mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, "CPuppet");
    mLog->infoStream() << "created";

    mRenderable->getText()->setCaption(stringify(mHP));
	  //mDeck = new CDeck(this);
	  //mDeck->generate();

    return true;
  };

  void CPuppet::die() {
    //if (mDeck)
    //  delete mDeck;

    mLog->infoStream() << "dead";
  };

  CPuppet::~CPuppet() {
    /*mRenderable
    mSceneObject = 0;
    mSceneNode = 0;
    mEntity = 0;*/
    if (mRenderable)
      delete mRenderable;

    mRenderable = 0;
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

    throw invalid_uid("couldn't find a spell with uid" + stringify(inUID));
    return 0;
  }
	void CPuppet::attachSpell(CSpell* inSpell)
	{
		mHand.push_back(inSpell);
    inSpell->setCaster(this);
		std::cout<<"Hero: Spell " << inSpell->getName() << "#" << inSpell->getUID() << " attached to hand.\n";
	};

	void CPuppet::detachSpell(int inUID)
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
    delete lSpell;
	};

	/* ------------------------
	 * UNITS
	 * ------------------------ */
  void CPuppet::attachUnit(CUnit* inUnit) {
    mUnits.push_back(inUnit);
    inUnit->setOwner(this);

    std::cout
      << mUID << " attached a cunit to my control: "
      << inUnit->getName() << "#" << inUnit->getUID() << "\n";

    assert(inUnit->getOwner());
  }
  void CPuppet::detachUnit(int inUID) {
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
    delete lUnit;
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
    mRenderable->getText()->setCaption(stringify(mHP));
  }
} // end of namespace
