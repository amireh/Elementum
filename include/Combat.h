/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_Combat_H
#define H_Combat_H

#include "GameState.h"
#include "EventListener.h"
#include "Archiver.h"
#include "EventManager.h"
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <list>

namespace Pixy
{
    /*! \class Combat
     *  \brief
     *  PEWPEW
     */

  class Spell;
  class GfxEngine;
  class FxEngine;
  class UIEngine;
  class ScriptEngine;
  class EventManager;
  class NetworkManager;
  class EntityManager;
  class Puppet;
  class Engine;
  class Unit;
	class Combat : public GameState, public EventListener {
	public:
    typedef std::list<Puppet*> puppets_t;

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

		void registerPuppet(Puppet* inPuppet);

    void assignPuppet(Puppet* inPuppet);

    puppets_t const& getPuppets();
    Puppet* getPuppet();
    Puppet* getEnemy(int inUID);
    Puppet* getPuppet(int inUID);
    Puppet* getActivePuppet();

    Unit* getUnit(int inUID);

    void doBattle();

    void unitAttacked(Unit*);

    void markForDeath(Unit*);

    //~ boost::asio::io_service& getIOService();
    boost::asio::strand& getStrand();

    void __setIsDebugging(bool setting);
    bool __isDebugging() const;

  protected:

	private:

    bool fSetup;

		Combat( void );
		Combat( const Combat& );
		Combat& operator=( const Combat& );

    void handleNewTurn();

    bool onConnected(const Event&);
    bool onGameDataSynced(const Event&);
    bool onLogin(const Event& inEvt);
    bool onSyncPuppets(const Event& inEvt); // __DEBUG__
    //~ bool onSyncGameData(const Event&);
    //~ bool onJoinQueue(const Event& inEvt);
    bool onJoinLobby(const Event& inEvt);
    bool onChangingState(const Event& inEvt);
    bool onMatchFound(const Event& inEvt);
    bool onSyncMatchPuppets(const Event& inEvt);
    bool onStartTurn(const Event& inEvt);
    bool onTurnStarted(const Event& inEvt);
    bool onDrawSpells(const Event&);
    bool onCastSpell(const Event&);
    bool onCreateUnit(const Event&);
    bool onUpdatePuppet(const Event&);
    bool onUpdateUnit(const Event&);

    /*
     * Pushes the UID of the given unit into mRDeathlist. See below.
     */
    bool onRemoveUnit(const Event&);

    /*
     * Client-specific event:
     */
    bool onEntityDied(const Event&);


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
    EntityManager *mEntityMgr;

		static Combat		*mCombat;

		puppets_t		mPuppets;
    Puppet* mPuppet, *mActivePuppet, *mWaitingPuppet;
    std::string mPuppetName;

    typedef std::list<Unit*> attackers_t;
    attackers_t mAttackers;
    attackers_t mChargers;

    // key is the attacker, value is the list of blockers in order
    typedef std::map<Unit*, attackers_t > blockers_t;
    blockers_t mBlockers;

    /* mDeathlist contains a list of units to be immediately removed from play,
     * as in their objects destroyed. Note that this does not particularly
     * happen when the Unit _displays_ that it dies.
     *
     * See Unit::die() for more info.
     */
    typedef std::vector<Unit*> deathlist_t;
    deathlist_t mDeathlist;

    /* "Remote" deathlist is a list populated by commands sent from the
     * server, namely EventUID::RemoveUnit events. We queue them in a separate
     * queue other than Deathlist because the client stages a unit's death
     * before actually removing it; the unit might display death animation & fx
     * at a time much earlier than the actual removal.
     *
     * mRDeathlist is used to verify the consistency between client unit deaths
     * and the server's. on Update(), units in mDeathlist are checked against
     * those UIDs in mRDeathlist, if they don't match, something is seriously
     * wrong.
     */
    typedef std::list<int> rdeathlist_t;
    rdeathlist_t mRDeathlist;

    bool inBlockPhase;

    bool fIsDebugging;

    //~ boost::asio::io_service& mIOService;
    boost::asio::strand mStrand;
    //~ boost::asio::io_service::work mWork;
    //~ boost::thread* mWorker;

    void onMoveBack(Unit* inUnit);
    void onMoveBackAndRest(Unit* inUnit);

	};
} // end of namespace
#endif
