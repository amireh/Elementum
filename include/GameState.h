/* -----------------------------------------------
 *  Filename: GameState.h
 *  Date Created: ??/2009
 *
 *  Original Author:
 *      IMPORTANT : GET AUTHOR NAME FROM OGRE WIKI
 *
 *  Last Update:
 *      Date:   20/4/2009
 *      By:     Ahmad Amireh
 * ----------------------------------------------- */

#ifndef H_GameState_H
#define H_GameState_H

#include "Pixy.h"
#include "InputListener.h"

namespace Pixy
{
    /*! \class GameState
     *  \brief
     *  Defines general behaviour of game states such as the Main Menu, and Combat.
     */
	class GameState : public InputListener {

	public:
		~GameState(){ };

		virtual void enter( void )  = 0;
		virtual void exit( void )   = 0;

		virtual void pause( void )  = 0;
		virtual void resume( void ) = 0;
		virtual void update( unsigned long lTimeElapsed ) = 0;

		virtual void keyPressed( const OIS::KeyEvent &e ) = 0;
		virtual void keyReleased( const OIS::KeyEvent &e ) = 0;

		virtual bool mouseMoved( const OIS::MouseEvent &e ) = 0;
		virtual bool mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id )  = 0;
		virtual bool mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) = 0;

		//virtual CEGUI::MouseButton convertButton(OIS::MouseButtonID buttonID);

		void changeState( GameState *state );
		void pushState( GameState *state );
		void popState( void );
		void requestShutdown( void );

		virtual GAME_STATE getId() const;

    bool isCurrentState();
	protected:
		GameState(){ };
		log4cpp::Category* mLog;

    GAME_STATE mId;
	private:

		GameState(const GameState&) { }
		GameState& operator=(const GameState&);
    };
} // end of namespace
#endif
