/*
 *  Combat.cpp
 *  Elementum
 *
 *  Created by Ahmad Amireh on 4/4/10.
 *  Copyright 2010 JU. All rights reserved.
 *
 */

#include "Combat.h"
#include "Intro.h"

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

		// grab CEGUI handle
		mUISystem = &CEGUI::System::getSingleton();

		mScriptEngine = ScriptEngine::getSingletonPtr();
		mScriptEngine->setup();

		// start the interface chain
		mScriptEngine->runScript("combat/entry_point.lua");

		mLog->infoStream() << "i'm up!";
    mPuppet = 0;

    bindToName("JoinQueue", this, &Combat::evtJoinQueue);
    bindToName("MatchFound", this, &Combat::evtMatchFound);
    bindToName("CreatePuppets", this, &Combat::evtCreatePuppets);
    bindToName("StartTurn", this, &Combat::evtStartTurn);
    bindToName("TurnStarted", this, &Combat::evtTurnStarted);

    /*CSpell* boo = new CSpell();
    boo->setName("HEHE");
    mScriptEngine->passToLua("Pixy.Foobar", 2, "Pixy::CSpell", (void*)boo);
    delete boo;*/
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
			  GameManager::getSingleton().changeState(Intro::getSingletonPtr());
				break;
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

  Combat::puppets_t const& Combat::getPuppets() {
    return mPuppets;
  }

  CPuppet* Combat::getPuppet(int inUID) {
    puppets_t::const_iterator itr;
    for (itr = mPuppets.begin(); itr != mPuppets.end(); ++itr)
      if ((*itr)->getObjectId() == inUID)
        return *itr;

    return 0;
  }

	/* +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ *
	 *	Event Handlers
	 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */

  bool Combat::evtJoinQueue(Event* inEvt) {
    // store the name of the puppet the player joined the queue with
    if (inEvt->getFeedback() == EVT_OK) {
      mPuppetName = inEvt->getProperty("PuppetName");
      mLog->infoStream() << "joined queue with puppet " << mPuppetName;
    }
    return true;
  }
  bool Combat::evtMatchFound(Event* inEvt) {

    return true;
  }

  bool Combat::evtCreatePuppets(Event* inEvt) {

    // find the puppet we're playing with
    puppets_t::const_iterator itr;
    for (itr = mPuppets.begin(); itr != mPuppets.end(); ++itr)
      if ((*itr)->getName() == mPuppetName) {
        assignPuppet(*itr);
        break;
      }

    // set up the scene
    mGfxEngine->setupCombat();

    // render all the puppets
    for (itr = mPuppets.begin(); itr != mPuppets.end(); ++itr) {
      if ((*itr)->getName() == mPuppetName) // is this the puppet we're playing with?
        mPuppet = (*itr);

      (*itr)->live();
      mGfxEngine->attachToScene((*itr)->getRenderable());
    }

    mEvtMgr->hook(mEvtMgr->createEvt("Ready"));
    return true;
  }

  bool Combat::evtStartTurn(Event* inEvt) {
    // acknowledge the order
    mEvtMgr->hook(mEvtMgr->createEvt("StartTurn"));

    mActivePuppet = mPuppet;
    mScriptEngine->passToLua("assignActivePuppet", 1, "Pixy::CPuppet", (void*)mActivePuppet);

    return true;
  }

  bool Combat::evtTurnStarted(Event* inEvt) {
    assert(inEvt->hasProperty("Puppet")); // _DEBUG_

    mActivePuppet = getPuppet(convertTo<int>(inEvt->getProperty("Puppet")));
    mScriptEngine->passToLua("assignActivePuppet", 1, "Pixy::CPuppet", (void*)mActivePuppet);

    assert(mActivePuppet); // _DEBUG_

    mLog->infoStream() << mActivePuppet->getName() << "'s turn has started, not mine";

    return true;
  }

  void Combat::pktDrawSpells(RakNet::Packet* inPkt) {
    using RakNet::BitStream;
    using RakNet::RakString;
    using std::vector;
    using std::string;

    mLog->infoStream() << "parsing drawn spells";

    CResourceManager& mResMgr = GameManager::getSingleton().getResMgr();

    BitStream lStream(inPkt->data, inPkt->length, false);
    lStream.IgnoreBytes(1); // skip the packet identifier

    RakString lData;
    lStream.Read(lData);

    // parse the spells and add them to our hand
    {
      string tmp(lData.C_String());
      vector<string> elements = Utility::split(tmp, ';');

      int lPuppetUID = convertTo<int>(elements[0].erase(0,1).c_str()); // strip out the leading $
      Puppet* lPuppet = getPuppet(lPuppetUID);
      assert(lPuppet); // _DEBUG_

      int nrSpells = convertTo<int>(elements[1].c_str());
      assert((elements.size()-2)/2 == nrSpells);

      int spellsParsed = 0;
      int index = 1;
      while (++spellsParsed <= nrSpells) {
        CSpell* lSpell = mResMgr.getSpell(elements[++index]);
        lSpell->setUID(convertTo<int>(elements[++index]));
        lSpell->setCaster(lPuppet);
        lPuppet->attachSpell(lSpell);

        /*Event* lEvt = mEvtMgr->createEvt("DrawSpell", true);
        lEvt->setProperty("Spell", stringify(lSpell->getUID()));
        mEvtMgr->hook(lEvt);*/

        if (lPuppet == mPuppet)
          mScriptEngine->passToLua("DrawSpell", 1, "Pixy::CSpell", (void*)lSpell);

        lSpell = 0;
      }
    }
  }
} // end of namespace
