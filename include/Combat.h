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
#include "EventListener.h"
#include "Archiver.h"
#include "EventManager.h"

namespace Pixy
{
    /*! \class Combat
     *  \brief
     *  PEWPEW
     */

  class CSpell;
  class GfxEngine;
  class UIEngine;
  class ScriptEngine;
  class EventManager;
  class NetworkManager;
  class CPuppet;
  class Engine;
	class Combat : public GameState, public EventListener {
	public:
    typedef std::list<CPuppet*> puppets_t;

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

		void registerPuppet(CPuppet* inPuppet);

		void updateMe(Engine* inEngine);
		void updateGfx();

    puppets_t const& getPuppets();
    void assignPuppet(CPuppet* inPuppet);
    CPuppet* getPuppet();
    CPuppet* getPuppet(int inUID);

    //~ void pktDrawSpells(RakNet::Packet* inPkt);

  protected:
    friend class UIEngine;
    void castSpell(CSpell*);

	private:

		Combat( void ) { }
		Combat( const Combat& ) { }
		Combat & operator = ( const Combat& );

    bool onSyncGameData(const Event&);
    bool onJoinQueue(const Event& inEvt);
    bool onMatchFound(const Event& inEvt);
    bool onSyncPuppetData(const Event& inEvt);
    bool onStartTurn(const Event& inEvt);
    bool onTurnStarted(const Event& inEvt);
    bool onDrawSpells(const Event&);
    bool onCastSpell(const Event&);
    bool onCreateUnit(const Event&);
    bool onUpdatePuppet(const Event&);

		GfxEngine			*mGfxEngine;
		UIEngine			*mUIEngine;
		ScriptEngine		*mScriptEngine;
		EventManager		*mEvtMgr;
		NetworkManager		*mNetMgr;

		static Combat		*mCombat;

		puppets_t		mPuppets;
    CPuppet* mPuppet, *mActivePuppet;
    std::string mPuppetName;


		vector<Engine*>		mUpdateQueue;
		vector<Engine*>::const_iterator mUpdater;

		bool fUpdateGfx;

	};
} // end of namespace
#endif
