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
#include "FxEngine.h"
#include "ScriptEngine.h"
#include "CResourceManager.h"
#include "Renderable.h"

namespace Pixy
{

  Combat::Combat()
  : mIOService(),
    mStrand(mIOService),
    mWork(mIOService),
    mWorker(0),
    fSetup(false) {

  }
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

    mWorker = new boost::thread(boost::bind(&boost::asio::io_service::run, &mIOService));

    mId = STATE_COMBAT;

		mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, "Combat");

		mLog->infoStream() << "---- Entering ----";
    mLog->infoStream() << "My Listener UID: " << mUID;

		//mPuppets.clear();
		//mUpdateQueue.clear();

		mEvtMgr = EventManager::getSingletonPtr();
		mNetMgr = NetworkManager::getSingletonPtr();
		if (!mNetMgr->connect()) {
      mLog->errorStream() << "Could not connect to server, aborting";
      return GameManager::getSingleton().requestShutdown();
		}

		fUpdateGfx = false;
		mGfxEngine = GfxEngine::getSingletonPtr();
		mGfxEngine->setup();

    mFxEngine = FxEngine::getSingletonPtr();
    mFxEngine->setup();

		mUIEngine = UIEngine::getSingletonPtr();
		mUIEngine->setup();

		mScriptEngine = ScriptEngine::getSingletonPtr();
		mScriptEngine->setup();

		// start the interface chain
		mScriptEngine->runScript("combat/entry_point.lua");
    mScriptEngine->passToLua("PrepareScene", 0);

		mLog->infoStream() << "i'm up!";
    mPuppet = 0;

    // sync the game data when we're connected
    bind(EventUID::Connected, boost::bind(&Combat::onConnected, this, _1));
    bind(EventUID::Login, boost::bind(&Combat::onLogin, this, _1));
    bind(EventUID::SyncGameData, boost::bind(&Combat::onSyncGameData, this, _1));
    bind(EventUID::JoinQueue, boost::bind(&Combat::onJoinQueue, this, _1));
    bind(EventUID::SyncPuppetData, boost::bind(&Combat::onSyncPuppetData, this, _1));
    bind(EventUID::StartTurn, boost::bind(&Combat::onStartTurn, this, _1));
    bind(EventUID::TurnStarted, boost::bind(&Combat::onTurnStarted, this, _1));
    bind(EventUID::DrawSpells, boost::bind(&Combat::onDrawSpells, this, _1));
    bind(EventUID::CastSpell, boost::bind(&Combat::onCastSpell, this, _1));
    bind(EventUID::CreateUnit, boost::bind(&Combat::onCreateUnit, this, _1));
    bind(EventUID::UpdatePuppet, boost::bind(&Combat::onUpdatePuppet, this, _1));
    bind(EventUID::UpdateUnit, boost::bind(&Combat::onUpdateUnit, this, _1));
    bind(EventUID::EntityDied, boost::bind(&Combat::onEntityDied, this, _1));
    bind(EventUID::StartBlockPhase, boost::bind(&Combat::onStartBlockPhase, this, _1));
    bind(EventUID::Charge, boost::bind(&Combat::onCharge, this, _1));
    bind(EventUID::CancelCharge, boost::bind(&Combat::onCancelCharge, this, _1));
    bind(EventUID::Block, boost::bind(&Combat::onBlock, this, _1));
    bind(EventUID::CancelBlock, boost::bind(&Combat::onCancelBlock, this, _1));
    bind(EventUID::EndBlockPhase, boost::bind(&Combat::onEndBlockPhase, this, _1));

    inBlockPhase = false;
    fSetup = true;
	}

  bool Combat::onConnected(const Event& evt) {
    mNetMgr->send(Event(EventUID::SyncGameData));

    return true;
  }

  bool Combat::onLogin(const Event& evt) {
    Event _evt(EventUID::JoinQueue);
    _evt.setProperty("Puppet", "Sugar");
    mNetMgr->send(_evt);

    return true;
  }
	void Combat::exit( void ) {
    if (fSetup)
      mScriptEngine->passToLua("cleanup", 0);

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

    mIOService.stop();
    mWorker->join();
    delete mWorker;
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
      break;
      case OIS::KC_A:
        if (mActivePuppet == mPuppet) {
          CPuppet::units_t::const_iterator unit_itr;
          for (unit_itr = mPuppet->getUnits().begin();
               unit_itr != mPuppet->getUnits().end();
               ++unit_itr) {
            CUnit* unit = *unit_itr;
            if (unit->getAP() > 0 && !unit->isResting() && !unit->isMoving() && !unit->getPosition() == POS_CHARGING) {
              Event req(EventUID::Charge);
              req.setProperty("UID", unit->getUID());
              mNetMgr->send(req);
            }
          }
        }
      break;
		}

	}

	bool Combat::mouseMoved( const OIS::MouseEvent &e )	{
		mUIEngine->mouseMoved(e);
		mGfxEngine->mouseMoved(e);

    return true;
	}

	bool Combat::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    if (!mPuppet) // game hasn't started
      return false;

		//~ if (mUIEngine->mousePressed(e, id))
      //~ return true;
    mUIEngine->mousePressed(e, id);
		mGfxEngine->mousePressed(e, id);

    return true;
	}

	bool Combat::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    if (!mPuppet) // game hasn't started
      return false;

		//~ if (mUIEngine->mouseReleased(e, id))
      //~ return true;

    mUIEngine->mouseReleased(e, id);
		mGfxEngine->mouseReleased(e, id);

    return true;
	}

	void Combat::pause( void ) {
	}

	void Combat::resume( void ) {
	}

  boost::asio::io_service& Combat::getIOService() {
    return mIOService;
  }
  boost::asio::strand& Combat::getStrand() {
    return mStrand;
  }

	/* +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ *
	 *	Main Routines
	 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */

	void Combat::update( unsigned long lTimeElapsed ) {

		mEvtMgr->update();
    mNetMgr->update();

    processEvents();

		mGfxEngine->update(lTimeElapsed);
    mFxEngine->update(lTimeElapsed);
		mScriptEngine->update(lTimeElapsed);
		mUIEngine->update(lTimeElapsed);

    if (!mDeathlist.empty()) {
      deathlist_t::iterator unit;
      for (unit = mDeathlist.begin();
           unit != mDeathlist.end();
           ++unit)
        static_cast<CPuppet*>((Entity*)(*unit)->getOwner())->detachUnit((*unit)->getUID());

      mDeathlist.clear();
    }

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
    else
      mScriptEngine->passToLua("assignEnemyPuppet", 1, "Pixy::CPuppet", (void*)inPuppet);
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

    throw invalid_uid("in Combat::getPuppet() : " + stringify(inUID));
  }

  CUnit* Combat::getUnit(int inUID) {
    puppets_t::const_iterator puppet;
    for (puppet = mPuppets.begin();
         puppet != mPuppets.end();
         ++puppet)
    {
      CPuppet::units_t::const_iterator unit;
      for (unit = (*puppet)->getUnits().begin();
           unit != (*puppet)->getUnits().end();
           ++unit)
        if ((*unit)->getUID() == inUID)
          return *unit;
    }

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

    for (list<CPuppet*>::iterator puppet = lPuppets.begin();
         puppet != lPuppets.end();
         ++puppet)
      this->registerPuppet(*puppet);

    // set up the scene
    mGfxEngine->setupCombat();
    mScriptEngine->passToLua("SetupScene", 0);

    // render all the puppets
    for (puppets_t::iterator puppet_itr = mPuppets.begin();
         puppet_itr != mPuppets.end();
         ++puppet_itr) {
      CPuppet* puppet = *puppet_itr;
      if (puppet->getName() == mPuppetName) // is this the puppet we're playing with?
        mPuppet = puppet;

      puppet->live();
      mScriptEngine->passToLua("CreatePuppet", 1, "Pixy::CPuppet", (void*)puppet);
      //~ mGfxEngine->attachToScene(puppet->getRenderable());
    }

    mScriptEngine->passToLua("GameStarted", 0);

    mNetMgr->send(Event(EventUID::Ready));
    //mEvtMgr->hook(mEvtMgr->createEvt("Ready")); __DISABLED__
    return true;
  }

  void Combat::handleNewTurn() {

    mScriptEngine->passToLua("assignActivePuppet", 1, "Pixy::CPuppet", (void*)mActivePuppet);
    mScriptEngine->passToLua("onHandleNewTurn", 0);

    // remove all expired puppet buffs
    {
      std::vector<CSpell*> expired;
      for (CPuppet::spells_t::const_iterator buff = mActivePuppet->getBuffs().begin();
           buff != mActivePuppet->getBuffs().end();
           ++buff)
        if ((*buff)->hasExpired())
          expired.push_back(*buff);

      for (std::vector<CSpell*>::iterator expired_spell = expired.begin();
           expired_spell != expired.end();
           ++expired_spell)
        mActivePuppet->detachBuff((*expired_spell)->getUID());
    }
    // apply active buffs
    for (CPuppet::spells_t::const_iterator buff = mActivePuppet->getBuffs().begin();
         buff != mActivePuppet->getBuffs().end();
         ++buff)
    {
      mScriptEngine->passToLua(
        "CastSpell", 3,
        "Pixy::Renderable", (*buff)->getCaster(),
        "Pixy::Renderable", (*buff)->getTarget(),
        "Pixy::CSpell", *buff);
    }

    for (CPuppet::units_t::const_iterator unit_itr = mActivePuppet->getUnits().begin();
         unit_itr != mActivePuppet->getUnits().end();
         ++unit_itr)
    {
      CUnit* unit = *unit_itr;
      unit->reset();
      unit->getUp();

      // remove all expired puppet buffs
      {
        std::vector<CSpell*> expired;
        for (CUnit::spells_t::const_iterator buff = unit->getBuffs().begin();
             buff != unit->getBuffs().end();
             ++buff)
          if ((*buff)->hasExpired())
            expired.push_back(*buff);

        for (std::vector<CSpell*>::iterator expired_spell = expired.begin();
             expired_spell != expired.end();
             ++expired_spell)
          unit->detachBuff((*expired_spell)->getUID());
      }
      // apply active buffs
      for (CUnit::spells_t::const_iterator buff = unit->getBuffs().begin();
           buff != unit->getBuffs().end();
           ++buff)
      {
        mScriptEngine->passToLua(
        "CastSpell", 3,
        "Pixy::Renderable", (*buff)->getCaster(),
        "Pixy::Renderable", (*buff)->getTarget(),
        "Pixy::CSpell", *buff);
      }
    }

  }

  bool Combat::onStartTurn(const Event& inEvt) {

    mActivePuppet = mPuppet;
    if (mPuppet == mPuppets.front())
      mWaitingPuppet = mPuppets.back();
    else
      mWaitingPuppet = mPuppets.front();

    // send the event back, acknowledging the order
    mNetMgr->send(inEvt);

    handleNewTurn();

    return true;
  }

  bool Combat::onTurnStarted(const Event& inEvt) {
    assert(inEvt.hasProperty("Puppet")); // _DEBUG_

    mWaitingPuppet = mActivePuppet;
    mActivePuppet = getPuppet(convertTo<int>(inEvt.getProperty("Puppet")));

    assert(mActivePuppet); // _DEBUG_

    handleNewTurn();

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

    return true;
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

  bool Combat::onCastSpell(const Event& inEvt) {
    if (inEvt.Feedback == EventFeedback::InvalidRequest) {
      // the UID was invalid
      std::cout << "my request to cast a spell was rejected!\n";
      return true;
    }

    // it's ok, let's find the spell, the caster, and the target
    CSpell* lSpell = 0;
    CPuppet* lCaster = 0;

    for (puppets_t::iterator puppet = mPuppets.begin();
         puppet != mPuppets.end();
         ++puppet)
      try {
        lSpell = (*puppet)->getSpell(convertTo<int>(inEvt.getProperty("Spell")));
        lCaster = static_cast<CPuppet*>(lSpell->getCaster()->getEntity());
        break;
      } catch (...) { lSpell = 0; }

    assert(lSpell && lCaster);
    Entity* _lTarget = 0;
    Renderable* lTarget = 0;
    if (inEvt.hasProperty("T")) {
      try {
        // is the target a puppet?
        _lTarget = getPuppet(convertTo<int>(inEvt.getProperty("T")));
        mLog->debugStream() << "target: " << _lTarget->getUID() << "#" << _lTarget->getName();
      } catch (invalid_uid& e) {
        try {
          // a unit?
          _lTarget = getUnit(convertTo<int>(inEvt.getProperty("T")));
        } catch (invalid_uid& e) {
          // invalid UID
          mLog->errorStream() << "couldn't find spell target with id " << inEvt.getProperty("T");
          return true;
        }
      }

      lTarget =
        (_lTarget->getRank() == PUPPET)
          ? getPuppet(_lTarget->getUID())->getRenderable()
          : getUnit(_lTarget->getUID())->getRenderable();

      lSpell->setTarget(lTarget);
    } else
      lSpell->setTarget(lCaster->getRenderable());

    mScriptEngine->passToLua(
      "CastSpell", 3,
      "Pixy::Renderable", lCaster->getRenderable(),
      "Pixy::Renderable", lTarget,
      "Pixy::CSpell", lSpell);
    // ...
    std::cout << "casted a spell! " << lSpell->getName() << "#" << lSpell->getUID() << "\n";
    // remove it from the UI
    if (lCaster == mPuppet)
      mScriptEngine->passToLua("DropSpell", 1, "Pixy::CSpell", (void*)lSpell);
    //mUIEngine->dropSpell(_spell);
    // remove it from the puppet's hand if it's not a buff
    lCaster->detachSpell(lSpell->getUID(), lSpell->getDuration() == 0);

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

    _unit->live();
    //~ mGfxEngine->attachToScene(_unit->getRenderable());

    mScriptEngine->passToLua("CreateUnit", 1, "Pixy::CUnit", (void*)_unit);

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
    mScriptEngine->passToLua("UpdatePuppet", 1, "Pixy::CPuppet", (void*)_puppet);

    return true;
  }

  bool Combat::onUpdateUnit(const Event& evt) {
    assert(evt.hasProperty("UID"));

    CUnit* _unit = getUnit(convertTo<int>(evt.getProperty("UID")));
    assert(_unit);

    std::cout << "Updating unit named: " << _unit->getName() << "#" << _unit->getUID() << "\n";

    _unit->updateFromEvent(evt);
    if (_unit->isDead())
      markForDeath(_unit);

    return true;
  }

  bool Combat::onEntityDied(const Event& evt) {
    markForDeath(static_cast<CUnit*>(evt.Any));
    return true;
  }
  bool Combat::onStartBlockPhase(const Event& evt) {
    if (mActivePuppet != mPuppet)
      inBlockPhase = true;

    // get up all the opponent units with summoning sickness
    for (CPuppet::units_t::const_iterator unit = mWaitingPuppet->getUnits().begin();
         unit != mWaitingPuppet->getUnits().end();
         ++unit)
      if ((*unit)->hasSummoningSickness())
        ((CUnit*)(*unit))->getUp();

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
    attacker->setAttackOrder(mAttackers.size());

    attacker->updateTextOverlay();

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

    std::cout << evt.getProperty("UID") << " is no longer charging\n";
    mAttackers.remove(attacker);

    // recalculate attack orders and display them
    attacker->setAttackOrder(0);
    attacker->updateTextOverlay();

    int i=0;
    for (attackers_t::iterator unit = mAttackers.begin();
         unit != mAttackers.end();
         ++unit) {
      (*unit)->setAttackOrder(++i);
      (*unit)->updateTextOverlay();
    }

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
    blocker->setBlockTarget(attacker);

    blocker->updateTextOverlay();

    return true;
  }

  bool Combat::onCancelBlock(const Event& evt) {
    CUnit *blocker, *attacker = 0;

    assert(evt.hasProperty("B") && evt.hasProperty("A"));
    try {
      blocker = mWaitingPuppet->getUnit(convertTo<int>(evt.getProperty("B")));
      attacker = mActivePuppet->getUnit(convertTo<int>(evt.getProperty("A")));
    } catch (invalid_uid& e) {
      mLog->errorStream() << "invalid charge event parameters : " << e.what();
      return true;
    }

    assert(blocker && attacker);

    /*
     * 1) remove blocker from blockers list
     * 2) if no blockers r left, remove the entry, otherwise
     *    recalculate attack orders
     */
    blockers_t::iterator entry = mBlockers.find(attacker);

    assert(entry != mBlockers.end());

    entry->second.remove(blocker);

    if (entry->second.empty()) {
      mBlockers.erase(entry);
    } else {
      int i=0;
      for (std::list<CUnit*>::iterator blocker = entry->second.begin();
           blocker != entry->second.end();
           ++blocker) {
        (*blocker)->setAttackOrder(++i);
        (*blocker)->updateTextOverlay();
      }
    }

    // reset the blocker
    blocker->setAttackOrder(0);
    blocker->setBlockTarget(0);
    blocker->updateTextOverlay();

    return true;
  }

  bool Combat::onEndBlockPhase(const Event& evt) {
    if (mActivePuppet != mPuppet)
      inBlockPhase = false;

    doBattle();

    return true;
  }

  void Combat::doBattle() {

    // first call
    if (mChargers.empty()) {
      // simulate the battle
      mLog->infoStream() << "simulating battle with : "
      << mAttackers.size() << " attacking units and "
      << mBlockers.size() << " units being blocked";

      // assign attack orders and display them
      int i=0;
      for (attackers_t::iterator unit = mAttackers.begin();
           unit != mAttackers.end();
           ++unit) {
        (*unit)->setAttackOrder(++i);
        (*unit)->updateTextOverlay();
      }

      for (blockers_t::iterator unit_pair = mBlockers.begin();
           unit_pair != mBlockers.end();
           ++unit_pair) {
        int i = 0;
        for (attackers_t::iterator unit = unit_pair->second.begin();
             unit != unit_pair->second.end();
             ++unit) {
          (*unit)->setAttackOrder(++i);
          (*unit)->updateTextOverlay();
        }
      }
    }
    // move them back
    if (mAttackers.empty()) {

      // move the blockers first
      for (blockers_t::iterator unit_pair = mBlockers.begin();
           unit_pair != mBlockers.end();
           ++unit_pair)
        for (attackers_t::iterator unit = unit_pair->second.begin();
             unit != unit_pair->second.end();
             ++unit) {
          if (!(*unit)->isDead()) {
            (*unit)->move(POS_READY, boost::bind(&Combat::onMoveBack, this, *unit));
          } else {
            //static_cast<CPuppet*>((Entity*)unit->getOwner())->detachUnit(unit->getUID());
            mDeathlist.push_back(*unit);
          }
        }

      for (attackers_t::iterator unit = mChargers.begin();
           unit != mChargers.end();
           ++unit) {
        if (!(*unit)->isDead())
          (*unit)->move(POS_READY, boost::bind(&Combat::onMoveBackAndRest, this, *unit));
        else {
          //static_cast<CPuppet*>((Entity*)unit->getOwner())->detachUnit(unit->getUID());
          mDeathlist.push_back(*unit);
        }
      }

      mChargers.clear();
      mBlockers.clear();
      mAttackers.clear();

      // tell the server we're done simulating the battle
      mNetMgr->send(Event(EventUID::BattleOver));

      mLog->infoStream() << "battle is over";
      return;
    }



    // go through every attacking unit:
    CUnit* unit = mAttackers.front();
    //for (auto unit : mAttackers) {
      // if it's being blocked, go through every blocker
      // else, let it attack the puppet
      if (mBlockers.find(unit) == mBlockers.end()) {
        unit->moveAndAttack(mWaitingPuppet);
        //~ break;
      } else {
        unit->moveAndAttack(mBlockers.find(unit)->second);
      }
    //}

  }

  void Combat::onMoveBack(CUnit* inUnit) {
    inUnit->setAttackOrder(0);
    inUnit->reset();
  }
  void Combat::onMoveBackAndRest(CUnit* inUnit) {
    onMoveBack(inUnit);
    inUnit->rest();
  }

  void Combat::unitAttacked(CUnit* inUnit) {
    mAttackers.remove(inUnit);
    mChargers.push_back(inUnit);
    mLog->infoStream() << "a unit is done, " << mAttackers.size() << " left";
  }

  void Combat::markForDeath(CUnit* inUnit) {
    // add the unit to the deathlist only if it's not there
    for (deathlist_t::iterator unit = mDeathlist.begin();
         unit != mDeathlist.end();
         ++unit)
      if ((*unit)->getUID() == inUnit->getUID())
        return;

    mDeathlist.push_back(inUnit);
  }
} // end of namespace
