#include "Intro.h"
#include "GameManager.h"
#include "EventManager.h"
#include "NetworkManager.h"
#include "UIEngine.h"
#include "GfxEngine.h"
#include "ScriptEngine.h"
#include "CPuppet.h"
#include "CDeck.h"
#include "CSpell.h"
#include "Combat.h"
#include "FxEngine.h"

using namespace Ogre;
namespace Pixy
{

	Intro* Intro::mIntro = 0;

	Intro::Intro()
  : //mIOService(),
    mStrand(GameManager::getSingleton().getIOService()),
    //~ mWork(GameManager::getSingleton().getIOService()),
    //~ mWorker(0),
    fSetup(false) {
    mLog = 0;
    mId = STATE_INTRO;
	}

	Intro::~Intro() {
    if (mLog) {
		  delete mLog;
		  mLog = 0;
		}
	}

	void Intro::enter( void ) {

		if (!mLog)
		  mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, "Intro");

    //~ mWorker = new boost::thread(boost::bind(&boost::asio::io_service::run, &GameManager::getSingleton().getIOService()));

		mLog->infoStream() << "---- Entering ----";

		mEvtMgr = EventManager::getSingletonPtr();
		mNetMgr = NetworkManager::getSingletonPtr();
		if (!mNetMgr->connect()) {
      mLog->errorStream() << "Could not connect to server, aborting";
      return GameManager::getSingleton().requestShutdown();
		}

		// init engines
		mGfxEngine = GfxEngine::getSingletonPtr();
		mGfxEngine->setup();

    mFxEngine = FxEngine::getSingletonPtr();
    mFxEngine->setup();

		mUIEngine = UIEngine::getSingletonPtr();
		mUIEngine->setup();

		mScriptEngine = ScriptEngine::getSingletonPtr();
		mScriptEngine->setup();

		// start the interface chain
		mScriptEngine->runScript("intro/entry_point.lua");

		/*
		mLog->infoStream() << "creating puppet and a deck";
		Puppet* lPuppet = new Puppet();
		Deck* lDeck = new Deck(*lPuppet);
		lDeck->generate();
		*/
		/*
		for (int i=0; i<50; ++i) {

			UIEvent_Register* _evt = mEvtMgr->createEvt<UIEvent_Register>();
			_evt->setType(EVT_REQ);
			_evt->setUsername("vxvxvx");
			_evt->setPassword("fubarxxzz");

			mEvtMgr->hook(_evt);
		}
		*/


		//mLog->debugStream() << "evt id " << _evt->getId();

		//mLog->infoStream() << "Initialized successfully.";
    fSetup = true;
	}


	void Intro::exit( void ) {

    //~ if (fSetup)
      //~ mScriptEngine->passToLua("cleanup", 0);

		//mNetMgr->disconnect();

		/*delete mScriptEngine;
		delete mUIEngine;
		delete mGfxEngine;
		delete mEvtMgr;*/

		mLog->infoStream() << "---- Exited ----";

		delete mLog;
		mLog = 0;

    //~ mIOService.stop();
    //~ mWorker->join();
    //~ delete mWorker;

	}

	void Intro::update( unsigned long lTimeElapsed ) {

		mEvtMgr->update();
		mNetMgr->update();

		processEvents();

		mGfxEngine->update(lTimeElapsed);
		mUIEngine->update(lTimeElapsed);
		mScriptEngine->update(lTimeElapsed);
    mFxEngine->update(lTimeElapsed);

	}

	void Intro::keyPressed( const OIS::KeyEvent &e )
	{
    mUIEngine->keyPressed(e);
	}

	void Intro::keyReleased( const OIS::KeyEvent &e ) {
    mUIEngine->keyReleased(e);
		switch (e.key) {
			case OIS::KC_ESCAPE:
				this->requestShutdown();
				break;
			case OIS::KC_SPACE:
				//fireLoginEvt();
				GameManager::getSingleton().changeState(Combat::getSingletonPtr());
				break;
		}

	}

	bool Intro::mouseMoved( const OIS::MouseEvent &e )
	{
		// Update CEGUI with the mouse motion
    mUIEngine->mouseMoved(e);
    mGfxEngine->mouseMoved(e);
    return true;
	}

	bool Intro::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    mUIEngine->mousePressed(e, id);
    mGfxEngine->mousePressed(e, id);
    return true;
	}

	bool Intro::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    mUIEngine->mouseReleased(e, id);
    mGfxEngine->mouseReleased(e, id);
    return true;
	}

	void Intro::pause( void ) {
	}

	void Intro::resume( void ) {
	}

	Intro* Intro::getSingletonPtr( void ) {
		if( !mIntro )
		    mIntro = new Intro();

		return mIntro;
	}

	Intro& Intro::getSingleton( void ) {
		return *getSingletonPtr();
	}

} // end of namespace
