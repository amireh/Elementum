/*
 *  Combat.cpp
 *  Elementum
 *
 *  Created by Ahmad Amireh on 4/4/10.
 *  Copyright 2010 JU. All rights reserved.
 *
 */

#include "Combat.h"
#include "GameManager.h"
//#include "Intro.h"
#include "CPuppet.h"
#include "CUnit.h"
#include "CSpell.h"
#include "EventManager.h"
#include "NetworkManager.h"
#include "UIEngine.h"
#include "GfxEngine.h"
#include "ScriptEngine.h"
#include "CResourceManager.h"

namespace Pixy
{

	Combat* Combat::mCombat = 0;

	Combat* Combat::getSingletonPtr( void ) {
		if( !mCombat )
		    mCombat = new Combat();

		return mCombat;
	}

	Combat& Combat::getSingleton( void ) {
		return *getSingletonPtr();
	}

	/* +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ *
	 *	Bootstrap
	 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */

	void Combat::enter( void ) {

    mId = STATE_COMBAT;

		mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, "Combat");

		mLog->infoStream() << "---- Entering ----";

		//mPuppets.clear();
		//mUpdateQueue.clear();

		mEvtMgr = EventManager::getSingletonPtr();
		mNetMgr = NetworkManager::getSingletonPtr();
		mNetMgr->connect();

		fUpdateGfx = false;
		mGfxEngine = GfxEngine::getSingletonPtr();
		mGfxEngine->setup();

		mUIEngine = UIEngine::getSingletonPtr();
		mUIEngine->setup();


		mScriptEngine = ScriptEngine::getSingletonPtr();
		mScriptEngine->setup();

		// start the interface chain
		mScriptEngine->runScript("combat/entry_point.lua");

		mLog->infoStream() << "i'm up!";
    mPuppet = 0;

    // sync the game data when we're connected
    bind(EventUID::Connected, [&](const Event& evt) -> bool {
      mNetMgr->send(Event(EventUID::SyncGameData));
      return true;
    });

    bind(EventUID::Login, [&](const Event& evt) -> bool {
      Event _evt(EventUID::JoinQueue);
      _evt.setProperty("Puppet", "Sugar");
      mNetMgr->send(_evt);
      return true;
    });

    bind(EventUID::SyncGameData, boost::bind(&Combat::onSyncGameData, this, _1));
    bind(EventUID::JoinQueue, boost::bind(&Combat::onJoinQueue, this, _1));
    bind(EventUID::SyncPuppetData, boost::bind(&Combat::onSyncPuppetData, this, _1));
    bind(EventUID::StartTurn, boost::bind(&Combat::onStartTurn, this, _1));
    bind(EventUID::TurnStarted, boost::bind(&Combat::onTurnStarted, this, _1));
    bind(EventUID::DrawSpells, boost::bind(&Combat::onDrawSpells, this, _1));
    bind(EventUID::CastSpell, boost::bind(&Combat::onCastSpell, this, _1));
    bind(EventUID::CreateUnit, boost::bind(&Combat::onCreateUnit, this, _1));
    bind(EventUID::UpdatePuppet, boost::bind(&Combat::onUpdatePuppet, this, _1));

    bind(EventUID::StartBlockPhase, boost::bind(&Combat::onStartBlockPhase, this, _1));
    bind(EventUID::Charge, boost::bind(&Combat::onCharge, this, _1));
    bind(EventUID::CancelCharge, boost::bind(&Combat::onCancelCharge, this, _1));
    bind(EventUID::Block, boost::bind(&Combat::onBlock, this, _1));
    bind(EventUID::CancelBlock, boost::bind(&Combat::onCancelBlock, this, _1));
    bind(EventUID::EndBlockPhase, boost::bind(&Combat::onEndBlockPhase, this, _1));

    //bindToName("JoinQueue", this, &Combat::evtJoinQueue);
    //bindToName("MatchFound", this, &Combat::evtMatchFound);
    //bindToName("CreatePuppets", this, &Combat::evtCreatePuppets);
    //bindToName("StartTurn", this, &Combat::evtStartTurn);
    //bindToName("TurnStarted", this, &Combat::evtTurnStarted);

    /*CSpell* boo = new CSpell();
    boo->setName("HEHE");
    mScriptEngine->passToLua("Pixy.Foobar", 2, "Pixy::CSpell", (void*)boo);
    delete boo;*/

    inBlockPhase = false;
	}

	void Combat::exit( void ) {

		puppets_t::iterator lPuppet;
		for (lPuppet = mPuppets.begin(); lPuppet != mPuppets.end(); ++lPuppet) {
			delete (*lPuppet);
		}
		mPuppets.clear();

		mUpdateQueue.clear();

		/*delete mScriptEngine;
		delete mUIEngine;
		delete mGfxEngine;
		delete mEvtMgr;*/

		mLog->infoStream() << "---- Exited ----";

		delete mLog;
		mLog = 0;

	}

	/* +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ *
	 *	Misc
	 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */

	void Combat::updateMe(Engine* inEngine) {
		mUpdateQueue.push_back(inEngine);
	}
	void Combat::updateGfx() {
		fUpdateGfx = true;
	}

	void Combat::keyPressed( const OIS::KeyEvent &e )	{

		/*mUISystem->injectKeyDown(e.key);
		mUISystem->injectChar(e.text);

		mGfxEngine->getCameraMan()->injectKeyDown(e);
		*/
		mUIEngine->keyPressed(e);
		mGfxEngine->keyPressed(e);
	}

	void Combat::keyReleased( const OIS::KeyEvent &e ) {

	  mUIEngine->keyReleased(e);
		mGfxEngine->keyReleased(e);

		/*
		mUISystem->injectKeyUp(e.key);

		mGfxEngine->getCameraMan()->injectKeyUp(e);
		*/
		switch (e.key) {
			case OIS::KC_ESCAPE:
				this->requestShutdown();
				break;
			case OIS::KC_SPACE:
			  //GameManager::getSingleton().changeState(Intro::getSingletonPtr());
				break;
      case OIS::KC_RETURN:
      //~ case OIS::KC_E:
        if (mActivePuppet == mPuppet)
          mNetMgr->send(Event(EventUID::EndTurn));
        //~ else
          //~ mNetMgr->send(Event(EventUID::EndBlockPhase));
      break;
      case OIS::KC_F:
        if (inBlockPhase)
          mNetMgr->send(Event(EventUID::EndBlockPhase));
		}

	}

	void Combat::mouseMoved( const OIS::MouseEvent &e )	{
		mUIEngine->mouseMoved(e);
		mGfxEngine->mouseMoved(e);
	}

	void Combat::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
		mUIEngine->mousePressed(e, id);
		mGfxEngine->mousePressed(e, id);
	}

	void Combat::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
		mUIEngine->mouseReleased(e, id);
		mGfxEngine->mouseReleased(e, id);
	}

	void Combat::pause( void ) {
	}

	void Combat::resume( void ) {
	}

	/* +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ *
	 *	Main Routines
	 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */

	void Combat::update( unsigned long lTimeElapsed ) {

		mEvtMgr->update();
    mNetMgr->update();

    processEvents();

    if (!mDeathlist.empty()) {
      for (auto unit : mDeathlist)
        static_cast<CPuppet*>((Entity*)unit->getOwner())->detachUnit(unit->getUID());

      mDeathlist.clear();
    }

		mGfxEngine->update(lTimeElapsed);
		mScriptEngine->update(lTimeElapsed);
		mUIEngine->update(lTimeElapsed);

		/*for (mUpdater = mUpdateQueue.begin();
			 mUpdater != mUpdateQueue.end();
			 ++mUpdater) {
			(*mUpdater)->update(lTimeElapsed);
		}

		if (fUpdateGfx)
			mGfxEngine->update(lTimeElapsed);*/
		/*
		mUIEngine->update(lTimeElapsed);
		mGfxEngine->update(lTimeElapsed);
		mScriptEngine->update(lTimeElapsed);
		 */
	}

	void Combat::registerPuppet(CPuppet* inPuppet) {
		mPuppets.push_back(inPuppet);
    mScriptEngine->passToLua("addPuppet", 1, "Pixy::CPuppet", (void*)inPuppet);
    if (inPuppet->getName() == mPuppetName)
      assignPuppet(inPuppet);
	}

  void Combat::assignPuppet(CPuppet* inPuppet) {
    assert(inPuppet);
    mLog->infoStream() << "I'm playing with a puppet named " << inPuppet->getName();
    mPuppet = inPuppet;
    mScriptEngine->passToLua("assignSelfPuppet", 1, "Pixy::CPuppet", (void*)mPuppet);
  }

	/* +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ *
	 *	Helpers
	 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */

  CPuppet* Combat::getPuppet() {
    return mPuppet;
  }
  CPuppet* Combat::getActivePuppet() {
    return mActivePuppet;
  }

  Combat::puppets_t const& Combat::getPuppets() {
    return mPuppets;
  }

  CPuppet* Combat::getPuppet(int inUID) {
    puppets_t::const_iterator itr;
    for (itr = mPuppets.begin(); itr != mPuppets.end(); ++itr)
      if ((*itr)->getUID() == inUID)
        return *itr;

    return 0;
  }

  CUnit* Combat::getUnit(int inUID) {
    for (auto puppet : mPuppets)
      for (auto unit : puppet->getUnits())
        if (unit->getUID() == inUID)
          return unit;

    throw invalid_uid("in Combat::getUnit() : " + stringify(inUID));
  }

	/* +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ *
	 *	Event Handlers
	 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */

  bool Combat::onSyncGameData(const Event& evt) {
    using std::string;
    using std::vector;

    mLog->infoStream() << "received game data, populating Resource Manager...";

    std::string senc = evt.getProperty("Data");

    vector<unsigned char> encoded(senc.begin(), senc.end());
    vector<unsigned char> raw;

    if (Archiver::decodeLzma(raw, encoded, evt.Rawsize) != 1) {
      std::cerr << "decoding failed!! \n";
    }

    string raw2str(raw.begin(), raw.end());

    std::istringstream datastream(raw2str);

    GameManager::getSingleton().getResMgr().populate(datastream);

    Event _evt(EventUID::Login);
    _evt.setProperty("Username", "Sugarfly");
    _evt.setProperty("Password", "tuonela");
    mNetMgr->send(_evt);

    return true;
  }

  bool Combat::onJoinQueue(const Event& inEvt) {
    // store the name of the puppet the player joined the queue with
    if (inEvt.Feedback == EventFeedback::Ok) {
      mPuppetName = inEvt.getProperty("Puppet");
      mLog->infoStream() << "joined queue with puppet " << mPuppetName;
    }
    return true;
  }
  bool Combat::onMatchFound(const Event& inEvt) {

    return true;
  }

  bool Combat::onSyncPuppetData(const Event& inEvt) {

    using std::string;
    using std::vector;

    //string senc(inEvt.getProperty("Data"));
    /*vector<unsigned char> encoded(senc.begin(), senc.end());
    vector<unsigned char> raw;

    if (Archiver::decodeLzma(raw, encoded, inEvt.Rawsize) != 1) {
      std::cerr << "decoding failed!! \n";
    }

    string raw2str(raw.begin(), raw.end());

    std::cout << "Uncompressed puppet data: " << raw2str << "\n";*/

    std::istringstream datastream(inEvt.getProperty("Data"));
    list<CPuppet*> lPuppets = GameManager::getSingleton().getResMgr().puppetsFromStream(datastream);
    datastream.clear();

    for (auto puppet : lPuppets)
      this->registerPuppet(puppet);

    // set up the scene
    mGfxEngine->setupCombat();

    // render all the puppets
    for (auto puppet : mPuppets) {
      if (puppet->getName() == mPuppetName) // is this the puppet we're playing with?
        mPuppet = puppet;

      mGfxEngine->attachToScene(puppet->getRenderable());
      puppet->live();
    }

    mNetMgr->send(Event(EventUID::Ready));
    //mEvtMgr->hook(mEvtMgr->createEvt("Ready")); __DISABLED__
    return true;
  }

  bool Combat::onStartTurn(const Event& inEvt) {
    // acknowledge the order
    //mEvtMgr->hook(mEvtMgr->createEvt("StartTurn")); __DISABLED__

    mActivePuppet = mPuppet;
    if (mPuppet == mPuppets.front())
      mWaitingPuppet = mPuppets.back();
    else
      mWaitingPuppet = mPuppets.front();

    mScriptEngine->passToLua("assignActivePuppet", 1, "Pixy::CPuppet", (void*)mActivePuppet);

    //mUIEngine->onTurnStarted(mPuppet);
    // send the event back, effectively acknowledging the order
    mNetMgr->send(inEvt);

    return true;
  }

  bool Combat::onTurnStarted(const Event& inEvt) {
    assert(inEvt.hasProperty("Puppet")); // _DEBUG_

    mWaitingPuppet = mActivePuppet;
    mActivePuppet = getPuppet(convertTo<int>(inEvt.getProperty("Puppet")));
    //mUIEngine->onTurnStarted(mActivePuppet);
    mScriptEngine->passToLua("assignActivePuppet", 1, "Pixy::CPuppet", (void*)mActivePuppet);

    assert(mActivePuppet); // _DEBUG_

    mLog->infoStream() << mActivePuppet->getName() << "'s turn has started, not mine";

    return true;
  }


  bool Combat::onDrawSpells(const Event& inEvt) {
    using std::vector;
    using std::string;
    using std::istringstream;

    mLog->infoStream() << "parsing drawn spells";

    CResourceManager& mResMgr = GameManager::getSingleton().getResMgr();

    //BitStream lStream(inPkt->data, inPkt->length, false);
    //lStream.IgnoreBytes(1); // skip the packet identifier

    //RakString tmp;
    //lStream.Read(tmp);

    istringstream lData(inEvt.getProperty("Data"));
    string lLine;

    // parse the drawn spells and add them to our hand
    {
      // how many spells to create
      getline(lData, lLine);
      int nrDrawSpells = atoi(Utility::split(lLine, ';').back().c_str());

      // the next line contains the actual string UIDs/names and the owner uid
      getline(lData, lLine);
      vector<string> elements = Utility::split(lLine, ';');

      int lPuppetUID = convertTo<int>(elements[0].erase(0,1).c_str()); // strip out the leading $
      CPuppet* lPuppet = getPuppet(lPuppetUID);
      assert(lPuppet); // _DEBUG_

      //int nrSpells = convertTo<int>(elements[1].c_str());
      assert((elements.size()-1)/2 == nrDrawSpells);

      int spellsParsed = 0;
      int index = 0;
      while (++spellsParsed <= nrDrawSpells) {
        CSpell* lSpell = mResMgr.getSpell(elements[++index]);
        lSpell->setUID(convertTo<int>(elements[++index]));
        lSpell->setCaster(lPuppet);
        lPuppet->attachSpell(lSpell);

        mLog->debugStream() << "attaching spell with UID: " << lSpell->getUID() << " to puppet " << lPuppet->getUID();

        if (lPuppet == mPuppet) {
          //mUIEngine->drawSpell(lSpell);
          mScriptEngine->passToLua("DrawSpell", 1, "Pixy::CSpell", (void*)lSpell);

          mUIEngine->refreshSize();
        }

        lSpell = 0;
      }

      lPuppet = 0;
    }

    // parse the spells to be discarded
    {
      getline(lData, lLine);
      int nrDropSpells = atoi(Utility::split(lLine, ';').back().c_str());

      if (nrDropSpells > 0) {

        mLog->debugStream() << "dropping " << nrDropSpells << " spells";

        // the next line contains the actual string UIDs/names and the owner uid
        getline(lData, lLine);
        vector<string> elements = Utility::split(lLine, ';');

        int lPuppetUID = convertTo<int>(elements[0].erase(0,1).c_str()); // strip out the leading $
        CPuppet* lPuppet = getPuppet(lPuppetUID);
        assert(lPuppet); // _DEBUG_

        //int nrSpells = convertTo<int>(elements[1].c_str());
        assert((elements.size()-1) == nrDropSpells);

        int spellsParsed = 0;
        int index = 0;
        while (++spellsParsed <= nrDropSpells) {
          CSpell* lSpell = lPuppet->getSpell(convertTo<int>(elements[++index]));
          mLog->debugStream() << "removing spell with UID " << elements[index] << " from puppet " << lPuppet->getUID();;
          assert(lSpell); // _DEBUG_

          if (lPuppet == mPuppet)
            //mUIEngine->dropSpell(lSpell);
            mScriptEngine->passToLua("DropSpell", 1, "Pixy::CSpell", (void*)lSpell);

          lPuppet->detachSpell(lSpell->getUID());
          lSpell = 0;
        }

        lPuppet = 0;
      }
    }
  }

  void Combat::castSpell(CSpell* inSpell) {
    if (mActivePuppet != mPuppet) {
      mLog->errorStream() << "attempting to cast spell while it's not my turn";
      return;
    }

    Event evt(EventUID::CastSpell);
    evt.setProperty("Spell", inSpell->getUID());
    mNetMgr->send(evt);
  }

  bool Combat::onCastSpell(const Event& evt) {
    if (evt.Feedback == EventFeedback::InvalidRequest) {
      // the UID was invalid
      std::cout << "my request to cast a spell was rejected!\n";
      return true;
    }

    // it's ok, let's find the spell
    CSpell* _spell = 0;
    CPuppet* _puppet = 0;
    for (auto puppet : mPuppets)
      try {
        _spell = puppet->getSpell(convertTo<int>(evt.getProperty("Spell")));
        _puppet = puppet;
        break;
      } catch (...) { _spell = 0; }
    assert(_spell && _puppet);
    // ...
    std::cout << "casted a spell! " << _spell->getName() << "#" << _spell->getUID() << "\n";
    // remove it from the UI
    if (_puppet == mPuppet)
      mScriptEngine->passToLua("DropSpell", 1, "Pixy::CSpell", (void*)_spell);
    //mUIEngine->dropSpell(_spell);
    // remove it from the puppet's hand
    _puppet->detachSpell(_spell->getUID());


    return true;
  }

  bool Combat::onCreateUnit(const Event& evt) {
    assert(evt.hasProperty("Name") && evt.hasProperty("OUID") && evt.hasProperty("UID"));

    CPuppet* _owner = getPuppet(convertTo<int>(evt.getProperty("OUID")));
    assert(_owner);

    std::cout << "CreateUnit name: " << evt.getProperty("Name") << "\n";
    CResourceManager& rmgr_ = GameManager::getSingleton().getResMgr();
    CUnit* _unit = rmgr_.getUnit(evt.getProperty("Name"), _owner->getRace());
    assert(_unit);

    _unit->fromEvent(evt);
    _owner->attachUnit(_unit);

    std::cout << "new units UID=" << _unit->getUID() << "\n";
    assert(_unit->getOwner());

    mGfxEngine->attachToScene(_unit->getRenderable());
    _unit->live();

    _unit = 0;
    _owner = 0;

    return true;
  }

  bool Combat::onUpdatePuppet(const Event& evt) {
    assert(evt.hasProperty("UID"));

    CPuppet* _puppet = getPuppet(convertTo<int>(evt.getProperty("UID")));
    assert(_puppet);

    std::cout << "Updating puppet named: " << _puppet->getName() << "\n";

    _puppet->updateFromEvent(evt);

    return true;
  }

  bool Combat::onStartBlockPhase(const Event& evt) {
    if (mActivePuppet != mPuppet)
      inBlockPhase = true;

    return true;
  }

  bool Combat::onCharge(const Event& evt) {
    CUnit *attacker = 0;

    assert(evt.hasProperty("UID"));
    try {
      attacker = mActivePuppet->getUnit(convertTo<int>(evt.getProperty("UID")));
    } catch (invalid_uid& e) {
      std::cout  << "invalid charge event parameters : " << e.what();
    }

    // move the unit
    std::cout << evt.getProperty("UID") << " is charging for an attack\n";

    mAttackers.push_back(attacker);

    return true;
  }

  bool Combat::onCancelCharge(const Event& evt) {
    CUnit *attacker = 0;

    assert(evt.hasProperty("UID"));
    try {
      attacker = mActivePuppet->getUnit(convertTo<int>(evt.getProperty("UID")));
    } catch (invalid_uid& e) {
      mLog->errorStream() << "invalid charge event parameters : " << e.what();
      return true;
    }

    // move the unit
    std::cout << evt.getProperty("UID") << " is no longer charging\n";

    mAttackers.remove(attacker);

    return true;
  }

  bool Combat::onBlock(const Event& evt) {
    CUnit *attacker, *blocker = 0;

    assert(evt.hasProperty("B") && evt.hasProperty("A"));
    try {
      attacker = mActivePuppet->getUnit(convertTo<int>(evt.getProperty("A")));
      blocker = mWaitingPuppet->getUnit(convertTo<int>(evt.getProperty("B")));
    } catch (invalid_uid& e) {
      std::cout  << "invalid block event parameters : " << e.what();
    }

    // does the attacker have any other units blocking?
    blockers_t::iterator blockers = mBlockers.find(attacker);
    if (blockers == mBlockers.end()) {
      // this is the first blocker
      blockers = mBlockers.insert( std::make_pair(attacker, std::list<CUnit*>()) ).first;
    }
    blockers->second.push_back(blocker);
    blocker->setAttackOrder(blockers->second.size());

    return true;
  }

  bool Combat::onCancelBlock(const Event& evt) {
    CUnit *blocker = 0;

    assert(evt.hasProperty("UID"));
    try {
      blocker = mActivePuppet->getUnit(convertTo<int>(evt.getProperty("UID")));
    } catch (invalid_uid& e) {
      mLog->errorStream() << "invalid charge event parameters : " << e.what();
      return true;
    }

    // move the unit

    return true;
  }

  bool Combat::onEndBlockPhase(const Event& evt) {
    if (mActivePuppet != mPuppet)
      inBlockPhase = false;

    doBattle();

    return true;
  }

  void Combat::doBattle() {

    // move them back
    if (mAttackers.empty()) {

      // move the blockers first
      for (auto pair : mBlockers)
        for (auto unit : pair.second) {
          if (!unit->isDead())
            unit->move(POS_READY, [&](CUnit* inUnit) -> void { inUnit->reset(); });
          else {
            //static_cast<CPuppet*>((Entity*)unit->getOwner())->detachUnit(unit->getUID());
            mDeathlist.push_back(unit);
          }
        }

      for (auto unit : mChargers) {
        if (!unit->isDead())
          unit->move(POS_READY, [&](CUnit* inUnit) -> void { inUnit->reset(); });
        else {
          //static_cast<CPuppet*>((Entity*)unit->getOwner())->detachUnit(unit->getUID());
          mDeathlist.push_back(unit);
        }
      }



      mChargers.clear();
      mBlockers.clear();
      mAttackers.clear();

      if (mActivePuppet == mPuppet)
        mNetMgr->send(Event(EventUID::EndTurn));

      mLog->infoStream() << "battle is over";
      return;
    }

    // simulate the battle
    mLog->infoStream() << "simulating battle with : "
      << mAttackers.size() << " attacking units and "
      << mBlockers.size() << " units being blocked";

    // go through every attacking unit:
    for (auto unit : mAttackers) {

      // if it's being blocked, go through every blocker
      // else, let it attack the puppet
      if (mBlockers.find(unit) == mBlockers.end()) {
        unit->moveAndAttack(mWaitingPuppet);
        break;
      } else {
        unit->moveAndAttack(mBlockers.find(unit)->second);
      }
    }

  }

  void Combat::unitAttacked(CUnit* inUnit) {
    mAttackers.remove(inUnit);
    mChargers.push_back(inUnit);
    mLog->infoStream() << "a unit is done, " << mAttackers.size() << " left";
  }

} // end of namespace
