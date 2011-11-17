/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#include "Unit.h"
#include "Puppet.h"
#include "PixyUtility.h"
#include "GameManager.h"
#include "GfxEngine.h"
#include "Combat.h"

namespace Pixy
{
  Unit::Unit()
  : mTimer(0),
    mEnemy(0),
    mAttackTarget(0),
    mBlockTarget(0),
    mAttackOrder(0),
    mLog(0),
    fDying(false)
  {
    setRank(Rank::Unit);
  };


  Unit::~Unit()
  {
    mBlockers.clear();
    mEnemy = 0;
    mBlockTarget = 0;
    mAttackTarget = 0;

    if (mTimer)
      delete mTimer;
    mTimer = 0;

    if (mLog)
    {
      delete mLog;
      mLog = 0;
    }
  };

  Unit::Unit(const Unit& src)
  {
    Unit::copyFrom(src);
  }

  Unit& Unit::operator=(const Unit& rhs)
  {
    // check for self-assignment
    if (this == &rhs)
      return (*this);

    Unit::copyFrom(rhs);
    return (*this);
  }

  void Unit::copyFrom(const Unit& src)
  {
    Entity::copyFrom(src);
    BaseUnit::copyFrom(src);
    Mobile::copyFrom(src);

    fDying = false;
    mBlockTarget = 0;
    mAttackTarget = 0;
    mAttackOrder = 0;

    mTimer = 0;
  }

  bool Unit::attack(Puppet *inTarget)
  {
    return true;
  }

  bool Unit::attack(Unit* inTarget, bool doBlock)
  {
    return true;
  }

  void Unit::serialize(Event& inEvt) {
    Entity::serialize(inEvt);
    BaseUnit::serialize(inEvt);
  }
  void Unit::deserialize(const Event& evt) {
    BaseUnit::deserialize(evt);
    Entity::deserialize(evt);

    updateTextOverlay();
  }

  Entity* Unit::toEntity() const {
    return static_cast<Entity*>((Unit*)this);
  }

  void Unit::setup(Ogre::SceneManager* inSceneMgr)
  {
    Entity::setup(inSceneMgr);
    Mobile::setup(this);
  }

  bool Unit::live() {
    Entity::live();

    mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, mName + stringify(mUID));
    mLog->infoStream() << "created";

    Mobile::setup(this);

    reset();

    mTimer = new boost::asio::deadline_timer(GameManager::getSingleton().getIOService());

    return true;
  };

  void Unit::die() {
    if (fDying)
      return;

    assert(!fIsDead);

    fDying = true;

    //~ boost::function<void()> death_func = boost::bind(&Unit::die, this);

    mLog->infoStream() << "dying [playing animation now]";

    float length_sec = animateDie();

    Event evt(EventUID::EntityDying);
    evt.Any = (void*)this;
    EventManager::getSingleton().hook(evt);

    mTimer->expires_from_now(boost::posix_time::milliseconds(length_sec * 1000));
    mTimer->async_wait(boost::bind(&Unit::dieAfterAnimating, this));

  };

  void Unit::dieAfterAnimating() {

    //~ FxEngine::getSingleton().onEntityDying(this->mRenderable);

    //Event evt(EventUID::EntityDied);
    //evt.Any = (void*)this->mRenderable;
    //EventManager::getSingleton().hook(evt);
    Combat::getSingleton().markForDeath(this);

    //~ mRenderable->hide();
    GfxEngine::getSingletonPtr()->stopUpdatingMe(this);

    mLog->infoStream() << "dead [inside the async timer]";
    mLog->infoStream() << " i'm destroyed!\n";
    delete mLog;
    mLog = 0;

    Entity::die();
  }


  void Unit::move(int inDestination, boost::function<void(Mobile*)> callback) {
    Mobile::hookOnDoneMoving(callback);

    //std::cout << "Unit " << mUID << " moving to position: " << inDestination << " from " << mPosition << "\n";
    //mPDestination = inDestination;
    //GfxEngine::getSingletonPtr()->updateMe(this);
    //~ mDestination = Ogre::Vector3::ZERO;

    /*if (inDestination < mPosition) {
      //~ mRenderable->trackEnemyUnit(this);
      //~ mRenderable->getSceneNode()->setAutoTracking(false);
      //~ Ogre::Vector3 pos = mWaypoints->front();
      //~ pos.z *= 2;
      //~ mRenderable->getSceneNode()->lookAt(pos, Ogre::Node::TS_WORLD);
      //~ std::cout << "Unit: I'm MOVING BACK, ROTATING\n";
      //~ mRenderable->getSceneNode()->yaw(Ogre::Degree(180));
    }
    //~ else
      //~ mRenderable->trackEnemyPuppet();
    // start running if not already moving and the player wants to move
    */
    animateRun();
    Mobile::move(inDestination);
  }

  void Unit::reset() {
    BaseUnit::reset();

    if (!isDead() && getText())
      updateTextOverlay();
  }

  void Unit::updateTextOverlay() {
    if (!mText)
      return;

    std::string cap = "";
    if (hasSummoningSickness()) {
      cap += "[S] ";
    }
    else if (isResting()) {
      cap += "[zZz] ";
    }
    /*
     * if the unit is blocking a target, we show the attacker's ID and our
     * attack order since an attacker can have multiple blockers. format:
     * [AID -> BID] AP/HP
     */
    else if (mBlockTarget) {
      std::ostringstream s;
      s << "[" << mBlockTarget->getAttackOrder() << "->" << mAttackOrder << "] ";
      cap += s.str();
    }

    if (hasFirstStrike()) {
      cap += "[FS] ";
    }
    if (hasLifetap()) {
      cap += "[L] ";
    }
    if (isRestless()) {
      cap += "[R] ";
    }
    if (isTrampling()) {
      cap += "[T] ";
    }
    if (isUnblockable()) {
      cap += "[U] ";
    }
    if (isFlying()) {
      cap += "[F] ";
    }
    /*
     * unit is attacking, show attack order. format:
     * [AID] AP/HP
     */
    else if (mAttackOrder != 0) {
      cap += "[" + stringify(mAttackOrder) + "] ";
    }
    // show stats (AP/HP)
    cap += stringify(mAP) + "/" + stringify(mHP);
    getText()->setCaption(cap);
  }

  bool Unit::attack(Pixy::Puppet* inTarget, boost::function<void()> callback) {

    float length_sec = animateAttack();

    //std::cout << "Animation is " << length_sec << " seconds long\n";

    mTimer->expires_from_now(boost::posix_time::milliseconds(length_sec * 1000));
    mTimer->async_wait( boost::bind(&Unit::attackAfterAnimation, this, callback, inTarget) );

    return true;
  }

  void
  Unit::attackAfterAnimation(boost::function<void()> callback, Puppet* inTarget) {
    int dmg = getAP();

    inTarget->animateHit();

    // tell interested parties that the target has been attacked (for SCT etc)
    {
      Event evt(EventUID::UnitAttacked);
      evt.setProperty("Damage", dmg);
      evt.Any = (void*)inTarget;
      EventManager::getSingleton().hook(evt);
    }

    // trigger a lifetap event if the unit has leeched any HP
    if (hasLifetap() && dmg > 0) {
      Event evt(EventUID::Lifetap);
      evt.setProperty("Damage", dmg);
      evt.Any = (void*)static_cast<Puppet*>(this->mOwner);
      EventManager::getSingleton().hook(evt);
    }

    // update HUDs
    static_cast<Puppet*>((Puppet*)mOwner)->updateTextOverlay();
    this->updateTextOverlay();
    callback();
  }

  bool Unit::attack(Pixy::Unit* inTarget, boost::function<void()> callback, bool block) {

    if (block && inTarget->hasFirstStrike() && !this->hasFirstStrike())
      return inTarget->attack(this, callback, block);


    float length_sec = animateAttack();

    // @note
    // we're using a timer so we give the animation time to finish
    mTimer->expires_from_now(boost::posix_time::milliseconds(length_sec * 1000));
    mTimer->async_wait(boost::bind(&Unit::attackAfterAnimation, this, callback, inTarget, block));

    return true;
  }

  void Unit::attackAfterAnimation(boost::function<void()> callback, Unit* inTarget, bool block) {

    // actually attack the target (see Unit::attack())
    // @note
    // the reason we pass block=false here is that we're running a special
    // version of the attack function (this one) that deals with rendering
    int dmg = getAP();

    inTarget->animateHit();

    // inform other components so they can render particles or w/e
    {
      Event evt(EventUID::UnitAttacked);
      evt.setProperty("Damage", dmg);
      evt.Any = (void*)inTarget;
      EventManager::getSingleton().hook(evt);
    }

    // if the target is required to block us, is not dead, and has AP, make it hit us back
    if (block && !inTarget->isDead() && !inTarget->isDying() && inTarget->getAP() > 0) {
      inTarget->attack(this, boost::bind(&Unit::updateOverlayAfterAttack, this, callback));
    } else {
      updateTextOverlay();
      callback();
    }
  }

  void Unit::updateOverlayAfterAttack(boost::function<void()> callback) {
    updateTextOverlay();
    callback();
  }

  void Unit::moveAndAttack(Puppet* inTarget) {
    this->reset();

    // puppet is dead, nothing to do!
    if (inTarget->isDead()) {
      Combat::getSingleton().unitAttacked(this);
      Combat::getSingleton().doBattle();

      return;
    }

    //this->mRenderable->trackEnemyPuppet();
    this->move(Position::Attacking,
      boost::bind(static_cast<void (Unit::*)(Puppet*)>(&Unit::attackAfterMoving), this, inTarget) );
  }

  void Unit::attackAfterMoving(Puppet* inTarget) {
    this->mAttackTarget = inTarget;
    this->attack(inTarget, boost::bind(&Unit::cleanupAfterAttacking, this, inTarget) );
  }

  void Unit::cleanupAfterAttacking(Puppet* inTarget) {
    // update the target stat HUD
    inTarget->updateTextOverlay();

    this->mAttackTarget = 0;

    //std::cout << "I attacked puppet, going back now\n";

    // move back and tell Combat that we're done to fetch the next attacker
    this->move(Position::Charging, boost::bind(&Unit::cleanupAfterMovingBack, this, inTarget) );
  }

  void Unit::cleanupAfterMovingBack(Puppet* inTarget) {
    //std::cout << "I'm back to charging position now, asking Combat to continue battle\n";
    Combat::getSingleton().unitAttacked(this);
    Combat::getSingleton().doBattle();
  }

  void Unit::moveAndAttack(std::list<Unit*> inBlockers) {

    // move to offense position
    //fDoneBlocking = false;

    mBlockers = inBlockers;

    this->reset();
    this->move(Position::Attacking, boost::bind(&Unit::doAttack, this));
  }

  void Unit::doAttack() {

    updateTextOverlay();

    /*
     * for every blocker X in blockers do:
     *  - move(X,Position::Blocking)
     *  - attack(this,X)
     *  - if X is not dead, move(X,Position::Charging)
     *  - if this is dead, mark for removal and abort
     * if trample && currentAP > 0
     *  - move(this,Position::Trampling)
     *  - attack(this,puppet)
     * move(this,Position::Charging)
     * mark as done
     */

    // we're dead, tell Combat we're done and to process the next unit
    if (isDead()) {

      Combat::getSingleton().unitAttacked(this);
      Combat::getSingleton().doBattle();

      return;
    }

    // we're done with blockers
    if (mBlockers.empty()) {


      // if this is a trampling unit, and we still got AP left,
      // proceed to hitting the puppet
      if (fIsTrampling && mAP > 0) {
        assert(mEnemy);
        return (void)move(Position::Trampling, boost::bind(static_cast<void (Unit::*)(Puppet*)>(&Unit::moveAndAttack), this, mEnemy));
      } else { // no trample, just move back and mark as done
        move(Position::Charging);
        //this->mRenderable->trackEnemyPuppet();

        Combat::getSingleton().unitAttacked(this);
        Combat::getSingleton().doBattle();

        return;
      }
    }

    // get the next blocker, move it to the defense position, and attack it
    Unit* blocker = mBlockers.front();

    // there's a special case where the attacker has 0 AP left, and the blocker
    // has 0 base AP, then there's no point moving it to defense pos, we should
    // just skip it
    if (mAP <= 0 && blocker->getAP() <= 0) {
      mBlockers.pop_front();

      return this->doAttack();
    }

    /*if (blocker->isDying()) {
      mBlockers.pop_front();

      return this->doAttack();
    }*/

    // make the two units face each other
    blocker->trackEnemyUnit(this);
    this->trackEnemyUnit(blocker);

    // move the blocker to its defence node and do the attacking
    blocker->move(Position::Blocking,
      boost::bind(static_cast<void (Unit::*)(Unit*)>(&Unit::attackAfterMoving), this, blocker));
  }

  void Unit::attackAfterMoving(Unit* blocker) {
    /*
     * basically,
     *  1) if we ran out of AP, then only the blocker hits us
     * otherwise,
     *  2) we hit the blocker, if they're not dead, they hit us back
     */

    if (mAP <= 0) {
      if (blocker->getBaseAP() > 0) { // can the blocker attack?
        // make it attack us and move it back
        blocker->attack(
          this,
          boost::bind(&Unit::moveBackAfterBlocking, this, blocker),
          false /* don't ask us to retaliate */);
      }
    } else {
      // attack the unit, tell it to retaliate and move it back if it's still alive
      this->attack(
        blocker,
        boost::bind(&Unit::moveBackAfterBlocking, this, blocker),
        true /* ask it to retaliate */);
    }
  }
  void Unit::moveBackAfterBlocking(Unit* blocker) {
    if (!(blocker->isDead() || blocker->isDying())) {
      blocker->move(Position::Charging);
      blocker->updateTextOverlay();
    }

    mBlockers.pop_front();

    // keep repeating until all blockers are handled or we're dead
    return this->doAttack();
  }


  void Unit::rest() {
    if (isResting())
      return;

    BaseUnit::rest();
    updateTextOverlay();
    animateRest();
  }

  void Unit::getUp() {
    if (!isResting())
      return;

    BaseUnit::getUp();

    animateGetUp();
    animateIdle();
    updateTextOverlay();
  }


  bool Unit::isDying() const { return fDying; };

  void Unit::setHP(int inHP) {
    if (isDead())
      return Entity::setHP(inHP);

    int lastHP = getHP();
    Entity::setHP(inHP);
    int incHP = getHP() - lastHP;

    Event e(EventUID::EntityStatChanged);
    e.setProperty("Stat", "HP");
    e.setProperty("Value", incHP);
    e.Any = (void*)this;
    EventManager::getSingleton().hook(e);
    updateTextOverlay();
  }

  void Unit::setAP(int inAP)
  {
    if (isDead())
      return BaseUnit::setAP(inAP);

    int lastAP = getAP();
    BaseUnit::setAP(inAP);
    int incAP = getAP() - lastAP;

    Event e(EventUID::EntityStatChanged);
    e.setProperty("Stat", "AP");
    e.setProperty("Value", incAP);
    e.Any = (void*)this;
    EventManager::getSingleton().hook(e);
    updateTextOverlay();
  }

  void Unit::_setEnemy(Puppet* inPuppet) {
    mEnemy = inPuppet;
  }

  int Unit::getAttackOrder() const
  {
    return mAttackOrder;
  }
  void Unit::setAttackOrder(int inOrder)
  {
    mAttackOrder = inOrder;
  }

  Unit* Unit::getBlockTarget() const
  {
    return mBlockTarget;
  }
  void Unit::setBlockTarget(Unit* const inTarget)
  {
    mBlockTarget = inTarget;
  }
  Entity* Unit::getAttackTarget() const
  {
    return mAttackTarget;
  }
  void Unit::setAttackTarget(Entity* const inTarget)
  {
    mAttackTarget = inTarget;
  }

  Puppet* Unit::getOwner() const
  {
    return static_cast<Puppet*>(mOwner);
  }

  void Unit::transmitMechanicChange(std::string mechanic, bool has_it)
  {
    if (isDead()) return;

    Event e(EventUID::UnitMechanicChanged);
    e.setProperty("M", mechanic);
    e.setProperty("HasIt", has_it ? "Yes" : "No");
    e.Any = (void*)this;

    EventManager::getSingleton().hook(e);
  }

} // end of Pixy namespace
