#include "CDeck.h"
//#include "CombatManager.h"
#include "CPuppet.h"
//#include "UIEngine.h"
#include "CSpell.h"
#include "SpellParser.h"

namespace Pixy
{

  int CDeck::idCounter = 0;
  CDeck::CDeck(CPuppet* inPuppet) : Deck(inPuppet) {
    /*if (mLog)
      delete mLog;

    mLog = new log4cpp::FixedContextCategory(CLIENT_LOG_CATEGORY, "CDeck");
    */
    nrRandom = 0;
    idCounter = 0;
    mPuppet = inPuppet;
    mLog->infoStream() << "CDeck built, not yet generated";

    try {
      mParser = new SpellParser();
    } catch (std::exception& e) {
      mLog->errorStream() << "couldn't build parser!";
    }

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
    delete mParser;
    mParser = 0;

    mLog->infoStream() << "cleared successfully!";

    if (mLog)
      delete mLog;

    mLog = 0;
  };

  void CDeck::generate()
  {
    mLog->infoStream() << "generating";
    std::ostringstream _path;
    switch (mPuppet->getRace()) {
      case EARTH:
        _path << PROJECT_ROOT << PROJECT_RESOURCES << "/data/spells/earth/matter.xml";
        mParser->parseSpells( _path.str() , &mSpells);
      //mParser->printAttributes(mSpells);
      /*
        mSpells.push_back ( new s_Summon_Earth_Elemental );
        mSpells.push_back ( new s_Summon_Crustling );
        mSpells.push_back ( new s_Summon_StoneGolem );
        mSpells.push_back ( new s_Summon_Treant );
        // init earth spells
      */
        break;
      case AIR:
        //mSpells.push_back ( new s_Summon_Kraken );
        break;
      case WATER:
        break;
      case FIRE:
        //_path = "../data/spells/fire.xml";
        //mParser->parseSpells( _path , &mSpells);
        /*
      mSpells.push_back ( new s_Summon_Fire_Elemental );
        mSpells.push_back ( new s_Fireball );
        mSpells.push_back ( new s_Summon_Imp );
        mSpells.push_back ( new s_Summon_Hound );
        mSpells.push_back ( new s_Summon_Balrog );
      */
        break;
      default:
        break;
    }

  }

  /*CSpell* CDeck::drawSpell()
  {
    std::cout << mSpells.size();

    assert(mSpells.size() != 0);

    if (nrRandom == mSpells.size())
        nrRandom = 0;

    CSpell* mSpell = NULL;
    try
    {
      //mSpell = new Spell(*(mSpells.at(nrRandom)));
      mSpell = new Spell(*(mSpells.front()));
    }
    catch (std::bad_alloc& e)
    {
        mLog->infoStream() << e.what();
        return NULL;
    }
    catch (std::out_of_range& e)
    {
        mLog->infoStream() << e.what();
        return NULL;
    }
    //mSpell->setId(idCounter++);
    //mSpell->setCaster(mPuppet);

    //CombatInterface::getSingletonPtr()->drawSpellButton(mSpell);
    nrRandom++;

  mLog->infoStream() << "Spell drawn, sending it now";

      return mSpell;
  }*/

  CSpell* CDeck::getSpell(std::string inName) {
    vector<Spell*>::iterator lSpell = mSpells.begin();
    for (lSpell; lSpell != mSpells.end(); ++lSpell) {
      if ((*lSpell)->getName() == inName)
        return new CSpell(*(*lSpell));
    }
    return NULL;
  }
}
