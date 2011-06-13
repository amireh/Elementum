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
	
	Combat* Combat::mCombat;
	GAME_STATE Combat::getId() const { return STATE_COMBAT; }
	
	void Combat::enter( void ) {
		
		mLog = new log4cpp::FixedContextCategory(CLIENT_LOG_CATEGORY, "Combat");
		
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
		
	}
	
	
	void Combat::exit( void ) {
		
		vector<Puppet*>::iterator lPuppet;
		
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
	
	void Combat::updateMe(Engine* inEngine) {
		mUpdateQueue.push_back(inEngine);
	}
	void Combat::updateGfx() {
		fUpdateGfx = true;
	}
	
	void Combat::update( unsigned long lTimeElapsed ) {
		
		mEvtMgr->update();		
		mNetMgr->update();
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
	
	void Combat::keyPressed( const OIS::KeyEvent &e )
	{
		
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
	
	void Combat::mouseMoved( const OIS::MouseEvent &e )
	{
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
	
	Combat* Combat::getSingletonPtr( void ) {
		if( !mCombat )
		    mCombat = new Combat();
		
		return mCombat;
	}
	
	Combat& Combat::getSingleton( void ) {
		return *getSingletonPtr();
	}
	
	void Combat::registerPuppet(Puppet* inPuppet) {
		mPuppets.push_back(inPuppet);
	}
} // end of namespace
