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

using namespace Ogre;
namespace Pixy
{

	Intro* Intro::mIntro = 0;

	Intro::Intro() {
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

		mLog->infoStream() << "---- Entering ----";

		mEvtMgr = EventManager::getSingletonPtr();
		mNetMgr = NetworkManager::getSingletonPtr();
		mNetMgr->connect();

		// init engines
		mGfxEngine = GfxEngine::getSingletonPtr();
		mGfxEngine->setup();

		mUIEngine = UIEngine::getSingletonPtr();
		mUIEngine->setup();

		mScriptEngine = ScriptEngine::getSingletonPtr();
		mScriptEngine->setup();

		// start the interface chain
		mScriptEngine->runScript("intro/main_menu.lua");

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

	}


	void Intro::exit( void ) {

		//mNetMgr->disconnect();

		/*delete mScriptEngine;
		delete mUIEngine;
		delete mGfxEngine;
		delete mEvtMgr;*/

		mLog->infoStream() << "---- Exiting ----";



	}

	void Intro::update( unsigned long lTimeElapsed ) {

		mEvtMgr->update();
		mNetMgr->update();

		mGfxEngine->update(lTimeElapsed);
		mUIEngine->update(lTimeElapsed);
		mScriptEngine->update(lTimeElapsed);

		processEvents();
	}

	void Intro::keyPressed( const OIS::KeyEvent &e )
	{


	}

	void Intro::keyReleased( const OIS::KeyEvent &e ) {

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
    return true;
	}

	bool Intro::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    mUIEngine->mousePressed(e, id);
    return true;
	}

	bool Intro::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    mUIEngine->mouseReleased(e, id);
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
