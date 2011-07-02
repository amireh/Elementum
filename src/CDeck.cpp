#include "CDeck.h"
//#include "CombatManager.h"
#include "CPuppet.h"
//#include "UIEngine.h"
#include "CSpell.h"

namespace Pixy
{

  int CDeck::idCounter = 0;
  CDeck::CDeck(CPuppet* inPuppet) : Deck(inPuppet) {
    /*if (mLog)
      delete mLog;

    mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, "CDeck");
    */
    nrRandom = 0;
    idCounter = 0;
    mPuppet = inPuppet;
    mLog->infoStream() << "CDeck built, not yet generated";

    /*try {
      mParser = new SpellParser();
    } catch (std::exception& e) {
      mLog->errorStream() << "couldn't build parser!";
    }*/

    //std::cout << "CDeck: built for puppet named " << mPuppet->getName() << "\n";
  };

  CDeck::~CDeck()
  {
    mLog->infoStream() << "clearing spell pool..";
/*
    while (!mSpells.empty())
    {
        delete mSpells.back();
        mSpells.pop_back();
    }
 */
    //mSpells.clear();
    idCounter = 0;
    nrRandom = 0;

    mPuppet = 0;
    //mCombatMgr = NULL;
    //delete mParser;
    //mParser = 0;

    //mLog->infoStream() << "cleared successfully!";

    /*if (mLog)
      delete mLog;

    mLog = 0;*/
  };

  void CDeck::generate()
  {
  }

  CSpell* CDeck::getSpell(std::string inName) {
    vector<Spell const*>::iterator lSpell = mSpells.begin();
    for (lSpell; lSpell != mSpells.end(); ++lSpell) {
      if ((*lSpell)->getName() == inName)
        return new CSpell(*(*lSpell));
    }
    return NULL;
  }
}
