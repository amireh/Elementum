/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_CUnit_H
#define H_CUnit_H

#include "Unit.h"
#include "CEntity.h"
#include "Logger.h"
#include <Ogre.h>
#include <list>
#include <vector>
#include <boost/function.hpp>
#include <boost/asio.hpp>

using std::list;
using std::vector;


using Ogre::Real;
using Ogre::Vector3;
namespace Pixy
{
  class GfxEngine;
  //~ class Renderable;
  class CPuppet;
	class CUnit : public Unit//, public CEntity, public Logger
	{
	public:

    struct Position
    {
     enum {
       Casting, // the Unit is passive/in casting position (the starting one)
       Charging, // the Unit is charging
       Blocking, // the Unit is blocking an attacker
       Clearing, // the Unit is attacking a blocker
       Attacking // the Unit is attacking the puppet
     };
    };

    CUnit();
    CUnit(const CUnit& src);
    CUnit& operator=(const CUnit& rhs);
    virtual ~CUnit();

    //~ virtual Renderable* getRenderable();

    virtual bool live();
    virtual void die();

    void move(char inDestination, boost::function<void(CUnit*)> callback=0);
    void moveAndAttack(CPuppet* inTarget);
    void moveAndAttack(std::list<CUnit*> inBlockers);

    CPuppet* getEnemy() const;

    void setAttackOrder(int inOrder);
    int getAttackOrder() const;

    // called by CPuppet::attachUnit()
    void _setEnemy(CPuppet* inPuppet);

    void update(unsigned long);

    bool isMoving() const;

    char getPosition() const;
    void setPosition(char inPos);

    void setWaypoints(std::vector<Ogre::Vector3>* inWp);

    CUnit* getBlockTarget() const;
    void setBlockTarget(CUnit* inTarget);

    CEntity* getAttackTarget() const;
    void setAttackTarget(CEntity* inTarget);

    virtual void setIsTrampling(bool inF);
    virtual void setIsUnblockable(bool inF);
    virtual void setIsRestless(bool inF);
    virtual void setHasFirstStrike(bool inF);
    virtual void setHasLifetap(bool inF);

    virtual void setAP(int inU);
    virtual void setHP(int inU);
    virtual void setBaseHP(int inU);
    virtual void setBaseAP(int inU);

    virtual bool attack(Pixy::CPuppet* inTarget, boost::function<void()> callback);
    virtual bool attack(Pixy::CUnit* inTarget, boost::function<void()> callback, bool block=false);

    //~ virtual bool attack(Pixy::CPuppet* inTarget);
    //~ virtual bool attack(Pixy::CUnit* inTarget, bool block=false);

    void updateTextOverlay();

    virtual void reset();

    void onVictory();

    virtual void rest();
    virtual void getUp();

    virtual void deserialize(const Event& evt);

    bool isDying() const;

    void setWalkSpeed(const float inSpeed);
    float getWalkSpeed() const;

    static void setDefaultWalkSpeed(const float inSpeed);
    static float getDefaultWalkSpeed();
    void setDescription(std::string inTxt);
    std::string const& getDescription() const;


	protected:
    friend class GfxEngine;

    //~ Renderable* mRenderable;
    virtual void copyFrom(const CUnit& src);

    //~ virtual void _onMechanicChange(std::string mechanic, bool has_it);

    bool setMoving(bool inMoving) {
      fIsMoving = inMoving;
    }

    bool doMove(unsigned long);

    void dieAfterAnimating();

    void attackAfterMoving(CPuppet* inTarget);
    void attackAfterMoving(CUnit* inBlocker);
    void cleanupAfterAttacking(CPuppet* inTarget);
    void cleanupAfterMovingBack(CPuppet* inTarget);

    // recursively goes through all the blockers and attacks them
    void doAttack();

    void attackAfterAnimation(boost::function<void()> callback, CPuppet*);
    void attackAfterAnimation(boost::function<void()> callback, CUnit*, bool doBlock);
    void updateOverlayAfterAttack(boost::function<void()> callback);

    void moveBackAfterBlocking(CUnit* blocker);

    /*!
     * \brief Informs whether the SceneNode has
     * reached its destination and updates the distance left, and the direction
     * the Node should be facing.
     * \note used by moveUnit()
     * @return true the Unit still has not reached its destination
     * @return false the Unit should not move further
     */
    bool nextLocation(int inDestination);

    bool fIsMoving;
    char  mPosition, mPDestination;
    std::vector<Vector3>* mWaypoints;

    //! used by moveUnit() and nextLocation() for tracking the Node's destination
    Vector3 mDestination;
    //! used by moveUnit() and nextLocation() for tracking and updating Node's direction while moving
    Vector3 mMoveDirection;
    //! used by nextLocation() for calculating how much distance left to travel
    Real mMoveDistance;
    //! fixed speed to be used later by mMoveSpeed
    Real mWalkSpeed;
    //! regulates the movement speed by (mWalkSpeed * mTimeElapsed) keeping it consistent
    Real mMoveSpeed;

    static float mDefaultWalkSpeed;

    //~ bool fDoneBlocking;

    typedef std::list<CUnit*> blockers_t;
    blockers_t mBlockers;

    boost::function<void(CUnit*)> mCallback;

    boost::asio::deadline_timer* mTimer;

    bool fDying;

    int mAttackOrder;
    CUnit* mBlockTarget;
    CEntity* mAttackTarget;
    std::string mDescription;

    CPuppet* mEnemy;

    Ogre::RaySceneQuery *mRaySceneQuery;
    Ogre::SceneManager      *mSceneMgr;
	};
} // end of namespace
#endif
