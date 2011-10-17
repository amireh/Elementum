/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#include "CUnit.h"
#include "CPuppet.h"
//~ #include "Renderable.h"
#include "GfxEngine.h"
#include "PixyUtility.h"
#include "ogre/MovableTextOverlay.h"
#include "Combat.h"
#include "FxEngine.h"
#include "GameManager.h"

namespace Pixy
{

  float CUnit::mDefaultWalkSpeed = 0.15f;

  CUnit::CUnit()
  : fIsMoving(false),
    mAttackOrder(0),
    mBlockTarget(0),
    mAttackTarget(0),
    mPosition(CUnit::Position::Casting),
    mWaypoints(0),
    mMoveDistance(0),
    mWalkSpeed(mDefaultWalkSpeed),
    mMoveSpeed(0),
    mCallback(0),
    mTimer(0),
    fDying(false),
    mDestination(Vector3::ZERO),
    mEnemy(0),
    mRaySceneQuery(0)
  {
    mLog = 0;
  };


  CUnit::CUnit(const CUnit& src)
  {
    copyFrom(src);
  };

  CUnit& CUnit::operator=(const CUnit& rhs)
  {
      // check for self-assignment
      if (this == &rhs)
          return (*this);

      copyFrom(rhs);
      return (*this);
  };

  CUnit::~CUnit() {

    //~
    mAttackTarget = 0;
    mBlockTarget = 0;

    if (mTimer)
      delete mTimer;

    while (!mSpells.empty()) {
      delete mSpells.back();
      mSpells.pop_back();
    }

    while (!mBuffs.empty()) {
      delete mBuffs.back();
      mBuffs.pop_back();
    }

    if (mRaySceneQuery) {
      mSceneMgr->destroyQuery(mRaySceneQuery);
      mRaySceneQuery = 0;
    }

    if (mLog)
    {
      delete mLog;
      mLog = 0;
    }

    //std::cout << "CUnit: " << mName << "#" << mUID << " destroyed\n";
  };

  void CUnit::copyFrom(const CUnit& src) {
    Unit::copyFrom(src);

    //this->mRenderable = new Renderable(*src.mRenderable);
    //this->setOwner(this);
    //this->mRenderable = 0;

    mPosition = src.mPosition;
    fIsMoving = src.fIsMoving;
    mWalkSpeed = src.mWalkSpeed;
    mMoveSpeed = src.mMoveSpeed;
    mDestination = src.mDestination;
    mMoveDirection = src.mMoveDirection;
    fDying = false;
    mAttackOrder = src.mAttackOrder;
    mBlockTarget = src.mBlockTarget;
    mAttackTarget = src.mAttackTarget;
    mDescription = src.mDescription;

    // Pixy::Entity::copyFrom() copies Spell* objects and we need
    // CSpell* here, so we clear the copied ones, and create new ones
    while (!mSpells.empty()) {
      delete mSpells.back();
      mSpells.pop_back();
    }

    if (!src.mSpells.empty()) {
      spells_t::const_iterator spell;
      for (spell = src.mSpells.begin();
           spell != src.mSpells.end();
           ++spell)
        attachSpell( new CSpell(*(*spell)) );
    }

    mTimer = 0;
  }

  void  CUnit::setWalkSpeed(const float inSpeed) {
    mWalkSpeed = inSpeed;
  }
  float CUnit::getWalkSpeed() const {
    return mWalkSpeed;
  }

  void CUnit::setDefaultWalkSpeed(const float inSpeed) {
    mDefaultWalkSpeed = inSpeed;
  }
  float CUnit::getDefaultWalkSpeed() {
    return mDefaultWalkSpeed;
  }

  bool CUnit::live() {
    Unit::live();

    mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, mName + stringify(mUID));
    mLog->infoStream() << "created";

    //~ mRenderable = new Renderable(this);
    mSceneMgr = GfxEngine::getSingletonPtr()->getSceneMgr();
    mRaySceneQuery = mSceneMgr->createRayQuery(Ogre::Ray());
    mRaySceneQuery->setSortByDistance(true);

    reset();

    mTimer = new boost::asio::deadline_timer(GameManager::getSingleton().getIOService());

    return true;
  };

  void CUnit::die() {
    if (fDying)
      return;

    assert(!fIsDead);

    fDying = true;

    //~ boost::function<void()> death_func = boost::bind(&Unit::die, this);

    mLog->infoStream() << "dying [playing animation now]";

    Unit::die();
    float length_sec = animateDie();

    Event evt(EventUID::EntityDying);
    evt.Any = (void*)this;
    EventManager::getSingleton().hook(evt);

    mTimer->expires_from_now(boost::posix_time::milliseconds(length_sec * 1000));
    mTimer->async_wait(boost::bind(&CUnit::dieAfterAnimating, this));
  };

  void CUnit::dieAfterAnimating() {

    //~ FxEngine::getSingleton().onEntityDying(this->mRenderable);

    //Event evt(EventUID::EntityDied);
    //evt.Any = (void*)this->mRenderable;
    //EventManager::getSingleton().hook(evt);
    Combat::getSingleton().markForDeath(this);

    //~ hide();
    GfxEngine::getSingletonPtr()->stopUpdatingMe(this);
    mSceneMgr->destroyQuery(mRaySceneQuery);
    mRaySceneQuery = 0;
    mSceneMgr = 0;

    mLog->infoStream() << "dead [inside the async timer]";
    mLog->infoStream() << " i'm destroyed!\n";
    delete mLog;
    mLog = 0;

  }

  bool CUnit::nextLocation(int inDestination)
  {
    Ogre::SceneNode* mNode = getSceneNode();

    if (mDestination == Vector3::ZERO) {

      mDestination = mWaypoints->at(inDestination);  // get walkpoint to our required destination
      //std::cout
      //  << "\tMoving to : "
      //  << mDestination.x << "," << mDestination.y << "," << mDestination.z
      //  << " from "
      //  << mNode->getPosition().x << "," << mNode->getPosition().y << "," << mNode->getPosition().z
      //  << "\n";

      if (inDestination == CUnit::Position::Attacking) {
        assert(mEnemy);

        Ogre::Real radius = mEnemy->getSceneObject()->getBoundingBox().getSize().z;
        Ogre::Real scale = mEnemy->getSceneNode()->getScale().z;
        int mod = (mDestination.z > mNode->getPosition().z) ? -1 : 1;
        mDestination.z =
          mEnemy->getSceneNode()->getPosition().z +
          (radius * /*scale*/2 * mod);
        //calculatePositionOffset();
        //std::cout << "\tPosition for attacking node: " << mDestination.z <<"\n";
      } else if (inDestination == CUnit::Position::Clearing) {
        Ogre::Vector3 bbox = mBlockers.front()->getSceneObject()->getBoundingBox().getSize();
        Ogre::Real radius = mBlockers.front()->getSceneObject()->getBoundingBox().getSize().z;
        int mod = (mDestination.z >= mNode->getPosition().z) ? -1 : 1;
        mDestination.z +=
          //mBlockers.front()->getSceneNode()->getPosition().z +
          ((radius * mBlockers.front()->getSceneNode()->getScale().z) /2 * mod);

        //std::cout << "My blocker's bbox: "
        //  << bbox.x << ","
        //  << bbox.y << ","
        //  << bbox.z << "\n";
      }
    }

    mMoveDirection = mDestination - mNode->getPosition();
    mMoveDistance = mMoveDirection.normalise();

    Vector3 src = mNode->getOrientation() * Vector3::UNIT_Z;
    if ((1.0f + src.dotProduct(mMoveDirection)) < 0.0001f)
    {
      //std::cout << " ***** YAWING 180 ****** \n";
        mNode->yaw(Ogre::Degree(180));
    } else
    {
        Ogre::Quaternion quat = src.getRotationTo(mMoveDirection);
        mNode->rotate(quat);
    } // else

    mNode = 0;
    return true;
  } // nextLocation()

  /*void CUnit::calculatePositionOffset(Vector3& inDestination) {
    // ------------------------------
    Ogre::Ray entityRay(getSceneNode()->getPosition(), mMoveDirection);
    mRaySceneQuery->setRay(entityRay);

    // Execute query
    Ogre::RaySceneQueryResult &result = mRaySceneQuery->execute();
    Ogre::RaySceneQueryResult::iterator itr;
    for (itr = result.begin(); itr != result.end(); itr++)
    {
      if (itr->worldFragment) {
        //Ogre::Real depth = itr->worldFragment->singleIntersection.z;
        std::cout << "-- Intersection @ "
          << itr->worldFragment->singleIntersection.x << ","
          << itr->worldFragment->singleIntersection.y << ","
          << itr->worldFragment->singleIntersection.z << "\n";
      } else if (itr->movable &&
        (itr->movable->getName().find(mEnemy->getName()) != std::string::npos)) {
        std::cout << "-- Distance to collision: "
          << itr->distance << ", enemy size is:"
          << mEnemy->getSceneObject()->getBoundingBox().getSize().x <<","
          << mEnemy->getSceneObject()->getBoundingBox().getSize().y <<","
          << mEnemy->getSceneObject()->getBoundingBox().getSize().z << "\n";

          if (itr->distance <= mEnemy->getSceneObject()->getBoundingBox().getSize().z/4.0f)
          {
            mMoveDistance = 0.0f;
            mMoveDirection = Vector3::ZERO;
            fIsMoving = false;
            return false;
          }

      }
    }
    // ------------------------------
  }*/

  void CUnit::move(char inDestination, boost::function<void(CUnit*)> callback) {
    mCallback = callback;

    //std::cout << "Unit " << mUID << " moving to position: " << inDestination << " from " << mPosition << "\n";
    mPDestination = inDestination;
    GfxEngine::getSingletonPtr()->updateMe(this);
    mDestination = Ogre::Vector3::ZERO;

    if (inDestination < mPosition) {
      //~ trackEnemyUnit(this);
      //~ getSceneNode()->setAutoTracking(false);
      //~ Ogre::Vector3 pos = mWaypoints->front();
      //~ pos.z *= 2;
      //~ getSceneNode()->lookAt(pos, Ogre::Node::TS_WORLD);
      //~ std::cout << "Unit: I'm MOVING BACK, ROTATING\n";
      //~ getSceneNode()->yaw(Ogre::Degree(180));
    }
    //~ else
      //~ trackEnemyPuppet();
    // start running if not already moving and the player wants to move
    animateRun();

  }

  bool CUnit::doMove(unsigned long mTimeElapsed)
  {
    Ogre::SceneNode* mNode = getSceneNode();

    nextLocation(mPDestination);

    if (mMoveDirection != Vector3::ZERO)
    {
      mMoveSpeed = mWalkSpeed * mTimeElapsed;
      mMoveDistance -= mMoveSpeed;

      //~ std::cout
        //~ << "\tActually moving, distance left: "
        //~ << mMoveDistance << " at speed "
        //~ << mMoveSpeed << " te: " << mTimeElapsed << " ws: " << mWalkSpeed << "\n";

      // if we're there or the Unit has passed the destination
      // correct its position and stop moving
      if (mMoveDistance <= 0.0f)
      {
        mNode->setPosition(mDestination);
        //~ mMoveDirection = Vector3::ZERO;

      } else {
        mNode->translate(mMoveDirection * mMoveSpeed);
      }
      fIsMoving = true;
    } else { // if
      fIsMoving = false;
      mDestination = Vector3::ZERO;
    }

    return fIsMoving;
  };


  void CUnit::update(unsigned long lTimeElapsed) {
    // keep moving
    if (!doMove(lTimeElapsed)) {

      // we arrived
      GfxEngine::getSingletonPtr()->stopUpdatingMe(this);

      // if we came back from an attack and still waiting at the charging spot
      // turn around 180 degrees to face the enemy
      if ((mPosition != CUnit::Position::Casting && mPDestination == CUnit::Position::Charging))
      {
        //~ getSceneNode()->yaw(Ogre::Degree(180));
        //~ trackEnemyPuppet();
        rotateToEnemy();
      } else if (mPDestination == CUnit::Position::Casting)
      {
        rotateTo(mWaypoints->at(CUnit::Position::Charging));
      }



      // ------------- a gentleman's hack ---------------
      //~ if (fRequiresYawFix) {
        //~ if (mPosition == CUnit::Position::Casting && mPDestination == CUnit::Position::Charging) {
          //~ getSceneNode()->yaw(Ogre::Degree(180));
        //~ }
      //~ } // yaw hack

			// stop running if already moving and the player doesn't want to move
      animateIdle();

      mPosition = mPDestination;
      //std::cout << "Unit " << mUID << " arrived at destination: " << mPosition << "\n";

      //~ this->resetOrientation();

      // is there a callback?
      if (mCallback)
        mCallback(this);

      //mCallback = 0;
    }
  }

  void CUnit::reset() {
    Unit::reset();
    mBlockTarget = 0;
    mAttackTarget = 0;

    if (getText())
      updateTextOverlay();
  }

  void CUnit::updateTextOverlay() {
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

  bool CUnit::attack(Pixy::CPuppet* inTarget, boost::function<void()> callback) {

    float length_sec = animateAttack();

    //std::cout << "Animation is " << length_sec << " seconds long\n";

    mTimer->expires_from_now(boost::posix_time::milliseconds(length_sec * 1000));
    mTimer->async_wait( boost::bind(&CUnit::attackAfterAnimation, this, callback, inTarget) );

    return true;
  }

  void
  CUnit::attackAfterAnimation(boost::function<void()> callback, CPuppet* inTarget) {
    int dmg = getAP();
    Unit::attack(inTarget);
    dmg -= getAP();

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
      evt.Any = (void*)getOwner();
      EventManager::getSingleton().hook(evt);
    }

    // update HUDs
    this->updateTextOverlay();
    callback();
  }

  bool CUnit::attack(Pixy::CUnit* inTarget, boost::function<void()> callback, bool block) {

    if (block && inTarget->hasFirstStrike() && !this->hasFirstStrike())
      return inTarget->attack(this, callback, block);


    float length_sec = animateAttack();

    // @note
    // we're using a timer so we give the animation time to finish
    mTimer->expires_from_now(boost::posix_time::milliseconds(length_sec * 1000));
    mTimer->async_wait(boost::bind(&CUnit::attackAfterAnimation, this, callback, inTarget, block));

    return true;
  }

  void CUnit::attackAfterAnimation(boost::function<void()> callback, CUnit* inTarget, bool block) {

    // actually attack the target (see Unit::attack())
    // @note
    // the reason we pass block=false here is that we're running a special
    // version of the attack function (this one) that deals with rendering
    int dmg = getAP();
    Unit::attack(inTarget, false);
    dmg -= getAP();

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
      inTarget->attack(this, boost::bind(&CUnit::updateOverlayAfterAttack, this, callback));
    } else {
      updateTextOverlay();
      callback();
    }
  }

  void CUnit::updateOverlayAfterAttack(boost::function<void()> callback) {
    updateTextOverlay();
    callback();
  }

  void CUnit::moveAndAttack(CPuppet* inTarget) {
    this->reset();

    // puppet is dead, nothing to do!
    if (inTarget->isDead()) {
      Combat::getSingleton().unitAttacked(this);
      Combat::getSingleton().doBattle();

      return;
    }

    //this->trackEnemyPuppet();
    this->move(CUnit::Position::Attacking,
      boost::bind(static_cast<void (CUnit::*)(CPuppet*)>(&CUnit::attackAfterMoving), this, inTarget) );
  }

  void CUnit::attackAfterMoving(CPuppet* inTarget) {
    this->mAttackTarget = inTarget;
    this->attack(inTarget, boost::bind(&CUnit::cleanupAfterAttacking, this, inTarget) );
  }

  void CUnit::cleanupAfterAttacking(CPuppet* inTarget) {
    // update the target stat HUD
    inTarget->updateTextOverlay();

    this->mAttackTarget = 0;

    //std::cout << "I attacked puppet, going back now\n";

    // move back and tell Combat that we're done to fetch the next attacker
    this->move(CUnit::Position::Charging, boost::bind(&CUnit::cleanupAfterMovingBack, this, inTarget) );
  }

  void CUnit::cleanupAfterMovingBack(CPuppet* inTarget) {
    //std::cout << "I'm back to charging position now, asking Combat to continue battle\n";
    Combat::getSingleton().unitAttacked(this);
    Combat::getSingleton().doBattle();
  }

  void CUnit::moveAndAttack(std::list<CUnit*> inBlockers) {

    // move to offense position
    //fDoneBlocking = false;

    mBlockers = inBlockers;

    this->reset();
    this->move(CUnit::Position::Clearing, boost::bind(&CUnit::doAttack, this));
  }

  void CUnit::doAttack() {

    updateTextOverlay();

    /*
     * for every blocker X in blockers do:
     *  - move(X,POS_DEFENSE)
     *  - attack(this,X)
     *  - if X is not dead, move(X,CUnit::Position::Charging)
     *  - if this is dead, mark for removal and abort
     * if trample && currentAP > 0
     *  - move(this,CUnit::Position::Attacking)
     *  - attack(this,puppet)
     * move(this,CUnit::Position::Charging)
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

        return move(CUnit::Position::Attacking, boost::bind(static_cast<void (CUnit::*)(CPuppet*)>(&CUnit::moveAndAttack), this, mEnemy));
#if 0
        move(CUnit::Position::Attacking, [&](CUnit*) -> void {
          this->attack(static_cast<CPuppet*>((Entity*)inBlockers.front()->getOwner()),
          [&]() -> void {
            // now move back
            move(CUnit::Position::Charging, [&](CUnit*) -> void {
              // and mark us as done
              Combat::getSingleton().unitAttacked(this);
              Combat::getSingleton().doBattle();
            });
          });
        });
#endif
      } else { // no trample, just move back and mark as done
        move(CUnit::Position::Charging);
        //this->trackEnemyPuppet();

        Combat::getSingleton().unitAttacked(this);
        Combat::getSingleton().doBattle();

        return;
      }
    }

    // get the next blocker, move it to the defense position, and attack it
    CUnit* blocker = mBlockers.front();

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
    blocker->move(CUnit::Position::Blocking,
      boost::bind(static_cast<void (CUnit::*)(CUnit*)>(&CUnit::attackAfterMoving), this, blocker));
  }

  void CUnit::attackAfterMoving(CUnit* blocker) {
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
          boost::bind(&CUnit::moveBackAfterBlocking, this, blocker),
          false /* don't ask us to retaliate */);
      }
    } else {
      // attack the unit, tell it to retaliate and move it back if it's still alive
      this->attack(
        blocker,
        boost::bind(&CUnit::moveBackAfterBlocking, this, blocker),
        true /* ask it to retaliate */);
    }
  }
  void CUnit::moveBackAfterBlocking(CUnit* blocker) {
    if (!(blocker->isDead() || blocker->isDying())) {
      blocker->move(CUnit::Position::Charging);
      blocker->updateTextOverlay();
    }

    mBlockers.pop_front();

    // keep repeating until all blockers are handled or we're dead
    return this->doAttack();
  }

  void CUnit::onVictory() {

		//setBaseAnimation(Renderable::ANIM_DANCE, true);
		//setTopAnimation(Renderable::ANIM_NONE);
		//// disable hand animation because the dance controls hands
		//mAnims[Renderable::ANIM_HANDS_RELAXED]->setEnabled(false);

    GfxEngine::getSingletonPtr()->stopUpdatingMe(this);
  }

  void CUnit::rest() {
    if (isResting())
      return;

    Unit::rest();
    updateTextOverlay();
    animateRest();
  }

  void CUnit::getUp() {
    if (!isResting())
      return;

    Unit::getUp();

    float length_sec = animateGetUp();
    animateIdle();
    updateTextOverlay();

    /*mTimer->expires_from_now(boost::posix_time::milliseconds(length_sec * 1000));
    mTimer->async_wait([&](boost::system::error_code e) -> void { this->animateIdle(); } );*/

  }

  void CUnit::deserialize(const Event& evt) {
    Unit::deserialize(evt);

    updateTextOverlay();
  }

  bool CUnit::isDying() const { return fDying; };

  void CUnit::setIsTrampling(bool inF) {
    Unit::setIsTrampling(inF);
  }
  void CUnit::setIsUnblockable(bool inF) {
    Unit::setIsUnblockable(inF);
  }
  void CUnit::setIsRestless(bool inF) {
    Unit::setIsRestless(inF);
  }
  void CUnit::setHasFirstStrike(bool inF) {
    Unit::setHasFirstStrike(inF);
  }
  void CUnit::setHasLifetap(bool inF) {
    Unit::setHasLifetap(inF);
  }
  void CUnit::setBaseHP(int inU) {
    Unit::setBaseHP(inU);
  }
  void CUnit::setBaseAP(int inU) {
    Unit::setBaseAP(inU);
  }

  void CUnit::setHP(int inHP) {
    if (isDead())
      return Unit::setHP(inHP);

    int lastHP = getHP();
    Unit::setHP(inHP);
    int incHP = getHP() - lastHP;

    Event e(EventUID::EntityStatChanged);
    e.setProperty("Stat", "HP");
    e.setProperty("Value", incHP);
    e.Any = (void*)this;
    EventManager::getSingleton().hook(e);
    updateTextOverlay();
  }

  void CUnit::setAP(int inAP)
  {
    if (isDead())
      return Unit::setAP(inAP);

    int lastAP = getAP();
    Unit::setAP(inAP);
    int incAP = getAP() - lastAP;

    Event e(EventUID::EntityStatChanged);
    e.setProperty("Stat", "AP");
    e.setProperty("Value", incAP);
    e.Any = (void*)this;
    EventManager::getSingleton().hook(e);
    updateTextOverlay();
  }

  void CUnit::_setEnemy(CPuppet* inPuppet) {
    mEnemy = inPuppet;
  }

  void CUnit::setAttackOrder(int inOrder) {
    mAttackOrder = inOrder;
  }

  int CUnit::getAttackOrder() const {
    return mAttackOrder;
  }


  CUnit* CUnit::getBlockTarget() const {
    return mBlockTarget;
  }
  void CUnit::setBlockTarget(CUnit* inTarget) {
    mBlockTarget = inTarget;
  }

  CEntity* CUnit::getAttackTarget() const {
    return mAttackTarget;
  }
  void CUnit::setAttackTarget(CEntity* inTarget) {
    mAttackTarget = inTarget;
  }


  void CUnit::setDescription(std::string inTxt) {
    mDescription = inTxt;
  }

  std::string const& CUnit::getDescription() const {
    return mDescription;
  }

  CPuppet* CUnit::getEnemy() const {
    assert(mEnemy);
    return mEnemy;
  };

  bool CUnit::isMoving() const {
    return fIsMoving;
  }

  char CUnit::getPosition() const {
    return mPosition;
  }
  void CUnit::setPosition(char inPos) {
    mPosition = inPos;
  }

  void CUnit::setWaypoints(std::vector<Ogre::Vector3>* inWp) {
    mWaypoints = inWp;
  }
} // end of namespace
