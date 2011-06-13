/*
 *  Lobby.h
 *  Elementum
 *
 *  Created by Ahmad Amireh on 2/15/10.
 *  Copyright 2010 JU. All rights reserved.
 *
 */

#ifndef H_Lobby_H
#define H_Lobby_H

#include "GameState.h"
#include "UIEngine.h"
#include "GfxEngine.h"
#include <map>

namespace Pixy
{
	
    /*! \class Lobby
     *  \brief
     *  Chat lobby & match finding state.
     */
	class Lobby : public GameState {
	public:
		~Lobby( void ){ };
		
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
		
		static Lobby* getSingletonPtr( void );
		
		GAME_STATE getId() const;
	private:
		Lobby( void ) { }
		Lobby( const Lobby& ) { }
		Lobby & operator = ( const Lobby& );
		
		// Pixy
		GfxEngine			 *mGfxEngine;
		UIEngine			 *mUIEngine;
		CEGUI::System		 *mUISystem;
		// OIS
		OIS::Keyboard        *mInputDevice;

		static Lobby    *mLobby;
		
		
	};
} // end of namespace
#endif

