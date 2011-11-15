/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_Unit_H
#define H_Unit_H

#include "Entity.h"
#include "BaseUnit.h"
#include "Mobile.h"
#include <boost/function.hpp>
#include <boost/asio.hpp>

namespace Pixy
{
  /*! \class Unit "Unit.h" "include/Unit.h"
  *
  *  \brief
  *  Represents Unit GameObjects, their actions and attributes.
  *
  */
  struct Event;
  class Puppet;
  class Unit : public Entity, public BaseUnit, public Mobile
  {
    public:

    enum Position {
      Ready,
      Charging,
      Attacking,
      Blocking,
      Trampling
    };


    Unit();
    Unit(const Unit& src);
    Unit& operator=(const Unit& rhs);
    virtual ~Unit();

    virtual bool live();
    virtual void die();

    virtual bool attack(Puppet* inTarget);
    virtual bool attack(Unit* inTarget, bool doBlock = false);

    virtual void serialize(Event& inEvt);
    virtual void deserialize(const Event& inEvt);

    virtual Entity* toEntity() const;

    void move(int inDestination, boost::function<void(Mobile*)> callback=0);
    void moveAndAttack(Puppet* inTarget);
    void moveAndAttack(std::list<Unit*> inBlockers);

    Puppet* getEnemy() const {
      assert(mEnemy);
      return mEnemy;
    };

    int getAttackOrder() const;
    void setAttackOrder(int);

    Unit* getBlockTarget() const;
    void setBlockTarget(Unit* const);
    Entity* getAttackTarget() const;
    void setAttackTarget(Entity* const);

    // called by Puppet::attachUnit()
    void _setEnemy(Puppet* inPuppet);

    virtual void setAP(int inU);
    virtual void setHP(int inU);
    //virtual void setBaseHP(int inU);
    //virtual void setBaseAP(int inU);

    virtual bool attack(Pixy::Puppet* inTarget, boost::function<void()> callback);
    virtual bool attack(Pixy::Unit* inTarget, boost::function<void()> callback, bool block=false);

    //~ virtual bool attack(Pixy::Puppet* inTarget);
    //~ virtual bool attack(Pixy::Unit* inTarget, bool block=false);

    virtual void updateTextOverlay();
    virtual void reset();
    virtual void rest();
    virtual void getUp();

    bool isDying() const;

    virtual void setup(Ogre::SceneManager*);

    protected:

    void copyFrom(const Unit& src);
    void dieAfterAnimating();

    void attackAfterMoving(Puppet* inTarget);
    void attackAfterMoving(Unit* inBlocker);
    void cleanupAfterAttacking(Puppet* inTarget);
    void cleanupAfterMovingBack(Puppet* inTarget);

    // recursively goes through all the blockers and attacks them
    void doAttack();

    void attackAfterAnimation(boost::function<void()> callback, Puppet*);
    void attackAfterAnimation(boost::function<void()> callback, Unit*, bool doBlock);
    void updateOverlayAfterAttack(boost::function<void()> callback);

    void moveBackAfterBlocking(Unit* blocker);

    typedef std::list<Unit*> blockers_t;
    blockers_t mBlockers;
    boost::asio::deadline_timer* mTimer;
    bool fDying;
    Puppet* mEnemy;
    int mAttackOrder;
    Unit *mBlockTarget;
    Entity* mAttackTarget;

    log4cpp::Category	*mLog;
  }; // end of class Unit
} // end of Pixy namespace

#endif // P_Unit_H
