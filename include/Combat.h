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
#include <boost/asio.hpp>
#include <boost/thread.hpp>

namespace Pixy
{
    /*! \class Combat
     *  \brief
     *  PEWPEW
     */

  class CSpell;
  class GfxEngine;
  class FxEngine;
  class UIEngine;
  class ScriptEngine;
  class EventManager;
  class NetworkManager;
  class CPuppet;
  class Engine;
  class CUnit;
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

		bool mouseMoved( const OIS::MouseEvent &e );
		bool mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id );
		bool mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id );

		static Combat* getSingletonPtr( void );
		static Combat& getSingleton();

		void registerPuppet(CPuppet* inPuppet);

		void updateMe(Engine* inEngine);
		void updateGfx();

    puppets_t const& getPuppets();
    void assignPuppet(CPuppet* inPuppet);
    CPuppet* getPuppet();
    CPuppet* getPuppet(int inUID);
    CPuppet* getActivePuppet();

    CUnit* getUnit(int inUID);

    void doBattle();

    void unitAttacked(CUnit*);

    void markForDeath(CUnit*);

    boost::asio::io_service& getIOService();
    boost::asio::strand& getStrand();

  protected:
    friend class UIEngine;
    void castSpell(CSpell*);

	private:

		Combat( void );
		Combat( const Combat& ) = delete;
		Combat& operator=( const Combat& ) = delete;

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
    bool onUpdateUnit(const Event&);

    bool onStartBlockPhase(const Event&);
    bool onCharge(const Event&);
    bool onCancelCharge(const Event&);
    bool onBlock(const Event&);
    bool onCancelBlock(const Event&);
    bool onEndBlockPhase(const Event&);

		GfxEngine			*mGfxEngine;
    FxEngine      *mFxEngine;
		UIEngine			*mUIEngine;
		ScriptEngine		*mScriptEngine;
		EventManager		*mEvtMgr;
		NetworkManager		*mNetMgr;

		static Combat		*mCombat;

		puppets_t		mPuppets;
    CPuppet* mPuppet, *mActivePuppet, *mWaitingPuppet;
    std::string mPuppetName;

    typedef std::list<CUnit*> attackers_t;
    attackers_t mAttackers;
    attackers_t mChargers;

    // key is the attacker, value is the list of blockers in order
    typedef std::map<CUnit*, std::list<CUnit*> > blockers_t;
    blockers_t mBlockers;


    typedef std::vector<CUnit*> death_list_t;
    death_list_t mDeathlist;

    bool inBlockPhase;


		std::vector<Engine*>		mUpdateQueue;
		std::vector<Engine*>::const_iterator mUpdater;

		bool fUpdateGfx;

    boost::asio::io_service mIOService;
    boost::asio::strand mStrand;
    boost::asio::io_service::work mWork;
    boost::thread* mWorker;

	};
} // end of namespace
#endif
