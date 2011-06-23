#include "CPuppet.h"
#include "CDeck.h"

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

	  mDeck = new CDeck(this);
	  mDeck->generate();

    return true;
  };

  void CPuppet::die() {
    if (mDeck)
      delete mDeck;

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

  Renderable& CPuppet::getRenderable() {
    return *mRenderable;

  }

  CDeck* CPuppet::getDeck() {
    mLog->infoStream() << "returning deck;";
    assert(mDeck != 0);
    CSpell* lSpell = mDeck->getSpell("Summon: Fetish Zij");
    if (!lSpell) {
      mLog->errorStream() << "didn't find the spell";
    } else {
      mLog->infoStream() << "Spell name " << lSpell->getName();
    }
    return mDeck;
  }

} // end of namespace
