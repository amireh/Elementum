/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_Lobby_H
#define H_Lobby_H

#include "GameState.h"
#include "EventListener.h"
#include <boost/asio.hpp>
#include <boost/thread.hpp>

namespace Pixy
{

  class Engine;
  class GfxEngine;
  class FxEngine;
  class UIEngine;
  class ScriptEngine;
  class EventManager;
  class NetworkManager;
  /*! \class Lobby
   *  \brief
   *  Chat lobby & match finding state.
   */
	class Lobby : public GameState, public EventListener {
	public:
		virtual ~Lobby( void );

		void enter( void );
		void exit( void );

		void pause( void );
		void resume( void );
		void update( unsigned long lTimeElapsed );

		void keyPressed( const OIS::KeyEvent &e );
		void keyReleased( const OIS::KeyEvent &e );

		bool mouseMoved( const OIS::MouseEvent &e );
		bool mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id );
		bool mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id );

		static Lobby* getSingletonPtr( void );

	private:
		Lobby( void );
		Lobby( const Lobby& );
		Lobby & operator = ( const Lobby& );

		// Pixy
		GfxEngine		    *mGfxEngine;
		UIEngine		    *mUIEngine;
    FxEngine        *mFxEngine;
		ScriptEngine	  *mScriptEngine;
		EventManager	  *mEvtMgr;
		NetworkManager  *mNetMgr;

		static Lobby    *mLobby;

    boost::asio::strand mStrand;


	};
} // end of namespace
#endif

