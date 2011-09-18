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

#ifndef H_Intro_H
#define H_Intro_H

#include "GameState.h"
#include "EventListener.h"
#include "CPuppet.h"
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <map>
#include <list>

namespace Pixy
{

  class Engine;
  class GfxEngine;
  class FxEngine;
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

    typedef std::list<CPuppet*> puppets_t;

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

    std::string const& getPuppetName() const;
    void setPuppetName(std::string);

    puppets_t const& getPuppets();
    CPuppet* getPuppet();

	protected:
		void fireLoginEvt();
    bool onSyncPuppets(const Event&);
    bool onSyncPuppetData(const Event&);
    bool onJoinLobby(const Event&);

    //~ boost::asio::io_service mIOService;
    boost::asio::strand mStrand;
    puppets_t mPuppets;
    //~ boost::asio::io_service::work mWork;
    //~ boost::thread* mWorker;

	private:
		Intro( void );
		~Intro();
		Intro( const Intro& );
		Intro & operator = ( const Intro& );

		GfxEngine		*mGfxEngine;
		UIEngine		*mUIEngine;
    FxEngine      *mFxEngine;
		ScriptEngine	*mScriptEngine;
		EventManager	*mEvtMgr;
		NetworkManager  *mNetMgr;

    std::string mPuppetName;
    CPuppet *mPuppet;

    bool fSetup;

		static Intro    *mIntro;


	};
} // end of namespace
#endif
