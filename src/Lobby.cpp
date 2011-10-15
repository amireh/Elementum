/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#include "Lobby.h"
#include "GameManager.h"
#include "EventManager.h"
#include "NetworkManager.h"
#include "UIEngine.h"
#include "GfxEngine.h"
#include "ScriptEngine.h"
#include "Combat.h"
#include "FxEngine.h"
#include "Intro.h"

namespace Pixy
{
	Lobby* Lobby::mLobby = 0;

  Lobby::Lobby()
  : mStrand(GameManager::getSingleton().getIOService())
  {
    mLog = 0;
    mId = STATE_LOBBY;
  }

  Lobby::~Lobby()
  {
    if (mLog) {
		  delete mLog;
		  mLog = 0;
		}
  }

	void Lobby::enter( void ) {
		if (!mLog)
		  mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, "Lobby");

    mLog->infoStream() << "---- Entering ----";

		mEvtMgr = EventManager::getSingletonPtr();
		mNetMgr = NetworkManager::getSingletonPtr();
		//~ if (!mNetMgr->isConnected()) {
      //~ mLog->errorStream() << "Could not connect to server, aborting";
      //~ return GameManager::getSingleton().requestShutdown();
		//~ }
		//~ if (!mNetMgr->connect()) {
      //~ mLog->errorStream() << "Could not connect to server, aborting";
      //~ return GameManager::getSingleton().requestShutdown();
		//~ }

		// init engines
		mGfxEngine = GfxEngine::getSingletonPtr();
		mGfxEngine->setup();

    mFxEngine = FxEngine::getSingletonPtr();
    mFxEngine->setup();

		mUIEngine = UIEngine::getSingletonPtr();
		mUIEngine->setup();

		mScriptEngine = ScriptEngine::getSingletonPtr();
		mScriptEngine->setup();

    //~ mScriptEngine->runScript("lobby/entry_point.lua");

    //~ mLog->infoStream() << "Joined the lobby with puppet " << Intro::getSingleton().getPuppetName();
	}

	void Lobby::exit( void ) {
    //~ mScriptEngine->cleanup();
    //~ mUIEngine->cleanup();

    mLog->infoStream() << "---- Exiting ----";
    delete mLog;
		mLog = 0;
	}

	void Lobby::keyPressed( const OIS::KeyEvent &e )
	{
    mUIEngine->keyPressed(e);
    mScriptEngine->keyPressed(e);
	}

	void Lobby::keyReleased( const OIS::KeyEvent &e ) {
    mUIEngine->keyReleased(e);
    mScriptEngine->keyReleased(e);
		switch (e.key) {
			case OIS::KC_ESCAPE:
				this->requestShutdown();
				break;
      case OIS::KC_SPACE:
				GameManager::getSingleton().changeState(Intro::getSingletonPtr());
				break;
		}

	}

	bool Lobby::mouseMoved( const OIS::MouseEvent &e )
	{
		// Update CEGUI with the mouse motion
    mUIEngine->mouseMoved(e);
    mGfxEngine->mouseMoved(e);
    return true;
	}

	bool Lobby::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    mUIEngine->mousePressed(e, id);
    mGfxEngine->mousePressed(e, id);
    return true;
	}

	bool Lobby::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    mUIEngine->mouseReleased(e, id);
    mGfxEngine->mouseReleased(e, id);
    return true;
	}

	void Lobby::pause( void ) {
	}

	void Lobby::resume( void ) {
	}

	void Lobby::update( unsigned long lTimeElapsed ) {
		mEvtMgr->update();

		processEvents();

		mGfxEngine->update(lTimeElapsed);
		mUIEngine->update(lTimeElapsed);
		mScriptEngine->update(lTimeElapsed);
    mFxEngine->update(lTimeElapsed);
	}

	Lobby* Lobby::getSingletonPtr( void ) {
		if( !mLobby ) {
		    mLobby = new Lobby();
		}

		return mLobby;
	}


} // end of namespace
