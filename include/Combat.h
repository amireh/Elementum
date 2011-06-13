/*
 *  Combat.h
 *  Elementum
 *
 *  Created by Ahmad Amireh on 4/4/10.
 *  Copyright 2010 JU. All rights reserved.
 *
 */

#ifndef H_Combat_H
#define H_Combat_H

#include "GameState.h"
#include "EventManager.h"
#include "NetworkManager.h"
#include "UIEngine.h"
#include "GfxEngine.h"
#include "ScriptEngine.h"
#include "Puppet.h"

namespace Pixy
{
    /*! \class Combat
     *  \brief
     *  PEWPEW
     */
	
	
	class Combat : public GameState {
	public:
		~Combat( void ){ };
		
		void enter( void );
		void exit( void );
		
		void pause( void );
		void resume( void );
		void update( unsigned long lTimeElapsed );
		
		void keyPressed( const OIS::KeyEvent &e );
		void keyReleased( const OIS::KeyEvent &e );
		
		void mouseMoved( const OIS::MouseEvent &e );
		void mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id );
		void mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id );
		
		static Combat* getSingletonPtr( void );
		static Combat& getSingleton();
		
		virtual GAME_STATE getId() const;
		
		void registerPuppet(Puppet* inPuppet);
		
		void updateMe(Engine* inEngine);
		void updateGfx();
	private:
		
		Combat( void ) { }
		Combat( const Combat& ) { }
		Combat & operator = ( const Combat& );
		
		GfxEngine			*mGfxEngine;
		UIEngine			*mUIEngine;
		CEGUI::System		*mUISystem;
		ScriptEngine		*mScriptEngine;
		EventManager		*mEvtMgr;
		NetworkManager		*mNetMgr;
		
		static Combat		*mCombat;
		
		vector<Puppet*>		mPuppets;
		vector<Engine*>		mUpdateQueue;
		vector<Engine*>::const_iterator mUpdater;
		
		bool fUpdateGfx;
		
	};
} // end of namespace
#endif
