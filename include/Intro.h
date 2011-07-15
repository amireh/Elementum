/* -----------------------------------------------
 *  Filename: Intro.h
 *  Date Created: ??/2009
 *
 *  Original Author:
 *      IMPORTANT : GET AUTHOR NAME FROM OGRE WIKI
 *
 *  Last Update:
 *      Date:   20/4/2009
 *      By:     Ahmad Amireh
 * ----------------------------------------------- */
#if 0
#ifndef H_Intro_H
#define H_Intro_H

#include "GameState.h"
#include "EventListener.h"
#include <map>
#include <list>

namespace Pixy
{

  class Engine;
  class GfxEngine;
  class UIEngine;
  class ScriptEngine;
  class EventManager;
  class NetworkManager;
  class CPuppet;
  /*!
   * @class Intro
   * @brief
   * Main Menu state, handles non-Combat game tasks.
   */
	class Intro : public GameState, public EventListener {
	public:

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

		static Intro* getSingletonPtr( void );
		static Intro& getSingleton();

	protected:
		void fireLoginEvt();
	private:
		Intro( void );
		~Intro();
		Intro( const Intro& ) { }
		Intro & operator = ( const Intro& );

		GfxEngine		*mGfxEngine;
		UIEngine		*mUIEngine;
		ScriptEngine	*mScriptEngine;
		EventManager	*mEvtMgr;
		NetworkManager  *mNetMgr;
		//Player			*mPlayer;

		static Intro    *mIntro;

	};
} // end of namespace
#endif
#endif
