#include "CUnit.h"
#include "CPuppet.h"
#include "Renderable.h"
#include "GfxEngine.h"
#include "ogre/MovableTextOverlay.h"
#include "Combat.h"
#include "FxEngine.h"

namespace Pixy
{

  CUnit::CUnit()
  : fIsMoving(false),
    mPosition(POS_READY),
    mWaypoints(0),
    mMoveDistance(0),
    mWalkSpeed(0.15f),
    mMoveSpeed(0),
    mCallback(0),
    mRenderable(0),
    mTimer(0),
    fDying(false),
    fRequiresYawFix(false)
  {

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
    if (mRenderable)
      delete mRenderable;

    if (mTimer)
      delete mTimer;

    mRenderable = 0;

    if (mLog) {
      mLog->infoStream() << " i'm destroyed!\n";
      delete mLog;
      mLog = 0;
    }

    while (!mSpells.empty()) {
      delete mSpells.back();
      mSpells.pop_back();
    }

    while (!mBuffs.empty()) {
      delete mBuffs.back();
      mBuffs.pop_back();
    }

  };

  void CUnit::copyFrom(const CUnit& src) {
    Unit::copyFrom(src);

    //this->mRenderable = new Renderable(*src.mRenderable);
    //this->mRenderable->setOwner(this);
    this->mRenderable = 0;

    mPosition = src.mPosition;
    fIsMoving = src.fIsMoving;
    mWalkSpeed = src.mWalkSpeed;
    mMoveSpeed = src.mMoveSpeed;
    mDestination = src.mDestination;
    mMoveDirection = src.mMoveDirection;
    fDying = false;
    fRequiresYawFix = src.fRequiresYawFix;

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


	CUnit::spells_t const& CUnit::getSpells(){ return mSpells; };

	void CUnit::attachSpell(CSpell* inSpell)
	{
		mSpells.push_back(inSpell);
		std::cout
      <<"CUnit: Spell " << inSpell->getName()
      << "#" << inSpell->getUID()
      << " attached to hand.\n";

    mSpells.back()->setCaster(mRenderable);
	};

	void CUnit::detachSpell(int inUID, bool remove)
	{
    CSpell* lSpell = 0;
		spells_t::iterator it;
		for(it = mSpells.begin(); it != mSpells.end(); ++it)
			if ((*it)->getUID() == inUID)
			{
        lSpell = *it;
				mSpells.erase(it);
				break;
			}

    assert(lSpell);

    std::cout
      << "CUnit: Spell " << lSpell->getName()
      << "#" << lSpell->getUID()
      << " detached from hand.\n";

    if (remove)
      delete lSpell;

    lSpell = 0;
	};

	int CUnit::nrSpells() {
		return mSpells.size();
	}

	CSpell* CUnit::getSpell(int inUID) {
		spells_t::const_iterator lSpell;
		for (lSpell = mSpells.begin(); lSpell != mSpells.end(); ++lSpell)
			if ((*lSpell)->getUID() == inUID)
				return *lSpell;

    throw invalid_uid("couldn't find a spell with uid" + stringify(inUID));
	}


  CUnit::spells_t const& CUnit::getBuffs() const {
    return mBuffs;
  }
  void CUnit::attachBuff(CSpell* inSpell)
	{
		mBuffs.push_back(inSpell);
    inSpell->setCaster(mRenderable);
		mLog->infoStream() << "buff " << inSpell->getName() << "#" << inSpell->getUID() << " attached to hand.\n";
	};

	void CUnit::detachBuff(int inUID)
	{
		CSpell* lSpell = 0;
		spells_t::iterator it;
		for(it = mBuffs.begin(); it != mBuffs.end(); ++it)
			if ((*it)->getUID() == inUID)
			{
        lSpell = *it;
				mBuffs.erase(it);
				break;
			}

    assert(lSpell);
    delete lSpell;
	};

  bool CUnit::hasBuff(int inUID) {
		spells_t::const_iterator lSpell;
		for (lSpell = mBuffs.begin(); lSpell != mBuffs.end(); ++lSpell)
			if ((*lSpell)->getUID() == inUID)
				return true;

    return false;
  }

  bool CUnit::live() {
    Unit::live();

    mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, mName + stringify(mUID));
    mLog->infoStream() << "created";

    mRenderable = new Renderable(this);

    reset();

    mTimer = new boost::asio::deadline_timer(Combat::getSingleton().getIOService());

    return true;
  };

  void CUnit::die() {
    if (fDying)
      return;

    fDying = true;

    //~ boost::function<void()> death_func = boost::bind(&Unit::die, this);

    mLog->infoStream() << "dying [playing animation now]";

    //~ float length_sec = mRenderable->animateDie();

    //~ mTimer->expires_from_now(boost::posix_time::milliseconds(length_sec * 1000));
    //~ mTimer->async_wait([&, death_func](boost::system::error_code e) -> void {
      Unit::die();

      FxEngine::getSingleton().onEntityDying(this->mRenderable);

      //~ Event evt(EventUID::EntityDied);
      //~ evt.Any = (void*)this;
      //~ EventManager::getSingleton().hook(evt);

      mRenderable->hide();
      mLog->infoStream() << "dead [inside the async timer]";
    //~ });
  };



  Renderable* CUnit::getRenderable() {
    return mRenderable;

  }

  bool CUnit::nextLocation(int inDestination)
  {
    Ogre::SceneNode* mNode = mRenderable->getSceneNode();

    mDestination = mWaypoints->at(inDestination);  // get walkpoint to our required destination
    //~ std::cout
      //~ << "\tMoving to : "
      //~ << mDestination.x << "," << mDestination.y << "," << mDestination.z
      //~ << " from "
      //~ << mNode->getPosition().x << "," << mNode->getPosition().y << "," << mNode->getPosition().z
      //~ << "\n";

    mMoveDirection = mDestination - mNode->getPosition();
    mMoveDistance = mMoveDirection.normalise();

    Vector3 src = mNode->getOrientation() * Vector3::UNIT_Z;
    if ((1.0f + src.dotProduct(mMoveDirection)) < 0.0001f)
    {
        mNode->yaw(Ogre::Degree(180));
    } else
    {
        Ogre::Quaternion quat = src.getRotationTo(mMoveDirection);
        mNode->rotate(quat);
    } // else

    mNode = 0;
    return true;
  } // nextLocation()

  void CUnit::move(UNIT_POS inDestination, boost::function<void(CUnit*)> callback) {
    mCallback = callback;

    std::cout << "Unit " << mUID << " moving to position: " << inDestination << "\n";
    mPDestination = inDestination;
    GfxEngine::getSingletonPtr()->updateMe(this);

    // start running if not already moving and the player wants to move
    mRenderable->animateRun();
    //~ mRenderable->setBaseAnimation(Renderable::ANIM_RUN_BASE, true);
    //if (mRenderable->mTopAnimID == Renderable::ANIM_IDLE_TOP) {
      // when charging, run with swords sheathed
      if (inDestination == POS_READY) {
        //mRenderable->setTopAnimation(Renderable::ANIM_RUN_TOP, true);

      } else {
        // draw swords and continue running
        /*if (!mRenderable->mSwordsDrawn) {
          // take swords out (or put them back, since it's the same animation but reversed)
          mRenderable->setTopAnimation(Renderable::ANIM_DRAW_SWORDS, true);
          mRenderable->mTimer = 0;
        }*/
      }
    //}

  }

  bool CUnit::doMove(unsigned long mTimeElapsed)
  {
      Ogre::SceneNode* mNode = mRenderable->getSceneNode();

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
              mMoveDirection = Vector3::ZERO;

              if (mPDestination == POS_READY) {
                mNode->yaw(Ogre::Degree(180));
              }
              //Vector3 mLookDirection = (inIdOwner == ID_HOST) ? mHeroPos[ID_CLIENT] : mHeroPos[];

              //mNode->lookAt(mMoveDirection[this->getOwner()], Ogre::Node::TS_WORLD);
              //this->setMoving(false);
          } else {
              mNode->translate(mMoveDirection * mMoveSpeed);
          }
          fIsMoving = true;
      } else // if
        fIsMoving = false;

      return fIsMoving;
  };


  void CUnit::update(unsigned long lTimeElapsed) {
    // keep moving
    if (!doMove(lTimeElapsed)) {

      // we arrived
      GfxEngine::getSingletonPtr()->stopUpdatingMe(this);

      // if we came back from an attack and still waiting at the charging spot
      // turn around 180 degrees to face the enemy
      if (mPosition != POS_READY && mPDestination == POS_CHARGING) {
        mRenderable->getSceneNode()->yaw(Ogre::Degree(180));
      }

      // ------------- a gentleman's hack ---------------
      if (fRequiresYawFix) {
        if (mPosition == POS_READY && mPDestination == POS_CHARGING) {
          mRenderable->getSceneNode()->yaw(Ogre::Degree(180));
        }
      } // yaw hack

			// stop running if already moving and the player doesn't want to move
      mRenderable->animateIdle();
			/*mRenderable->setBaseAnimation(Renderable::ANIM_IDLE_BASE);
			if (mRenderable->mTopAnimID == Renderable::ANIM_RUN_TOP)
        mRenderable->setTopAnimation(Renderable::ANIM_IDLE_TOP);*/


      // if we came back from an attack or a block, unsheathe our swords
      /*if (mPDestination == POS_READY && mRenderable->mSwordsDrawn) {
        mRenderable->setTopAnimation(Renderable::ANIM_DRAW_SWORDS, true);
        mRenderable->mTimer = 0;
      }*/

      std::cout << "Unit " << mUID << " arrived at destination: " << mPosition << "\n";
      mPosition = mPDestination;

      //~ this->mRenderable->resetOrientation();

      // is there a callback?
      if (mCallback)
        mCallback(this);

      //mCallback = 0;
    }
  }

  void CUnit::reset() {
    Unit::reset();

    if (mRenderable && mRenderable->getText())
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
    /*
     * unit is attacking, show attack order. format:
     * [AID] AP/HP
     */
    else if (mAttackOrder != 0) {
      cap += "[" + stringify(mAttackOrder) + "] ";
    }
    // show stats (AP/HP)
    cap += stringify(mAP) + "/" + stringify(mHP);
    mRenderable->getText()->setCaption(cap);
  }

  bool CUnit::attack(Pixy::CPuppet* inTarget, boost::function<void()> callback) {
    /*Renderable::AnimID anim = (rand() % 2 == 0)
      ? Renderable::ANIM_SLICE_VERTICAL
      : Renderable::ANIM_SLICE_HORIZONTAL;
    float length_sec = mRenderable->mAnims[anim]->getLength();*/
    float length_sec = mRenderable->animateAttack();

    std::cout << "Animation is " << length_sec << " seconds long\n";

    //mRenderable->setTopAnimation(anim, true);
    //mRenderable->mTimer = 0;

    //boost::function<bool(Puppet*)> attack_func = boost::bind(&Unit::attack, this, _1);

    mTimer->expires_from_now(boost::posix_time::milliseconds(length_sec * 1000));
    mTimer->async_wait( boost::bind(&CUnit::attackAfterAnimation, this, callback, inTarget) );
    /*mTimer->async_wait([&, callback, attack_func, inTarget](boost::system::error_code e) -> void {

    });*/
  }
  
  void 
  CUnit::attackAfterAnimation(boost::function<void()> callback, CPuppet* inTarget) {
    Unit::attack(inTarget);
    
    inTarget->getRenderable()->animateHit();
    
    Event evt(EventUID::EntityAttacked);
    evt.Any = (void*)inTarget->getRenderable();
    EventManager::getSingleton().hook(evt);
    
    this->updateTextOverlay();
    callback();    
  }

  bool CUnit::attack(Pixy::CUnit* inTarget, boost::function<void()> callback, bool block) {
    /*Renderable::AnimID anim = (rand() % 2 == 0)
      ? Renderable::ANIM_SLICE_VERTICAL
      : Renderable::ANIM_SLICE_HORIZONTAL;
    float length_sec = mRenderable->mAnims[anim]->getLength();

    mRenderable->setTopAnimation(anim, true);
    mRenderable->mTimer = 0;*/

    float length_sec = mRenderable->animateAttack();

    // wrap the base class function using boost function because we can't call it
    // inside the lambda
    //boost::function<bool(Unit*, bool)> attack_func = boost::bind(&Unit::attack, this, _1, _2);

    // @note
    // we're using a timer so we give the animation time to finish
    // TODO: use actual animation length
    mTimer->expires_from_now(boost::posix_time::milliseconds(length_sec * 1000));
    mTimer->async_wait(boost::bind(&CUnit::attackAfterAnimation, this, callback, inTarget, block));
    /*[&, inTarget, callback, block, attack_func](boost::system::error_code e) -> void {

      
    });*/
  }
  
  void CUnit::attackAfterAnimation(boost::function<void()> callback, CUnit* inTarget, bool block) {
    
    // actually attack the target (see Unit::attack())
    // @note
    // the reason we pass block=false here is that we're running a special
    // version of the attack function (this one) that deals with rendering
    Unit::attack(inTarget, false);
    
    inTarget->getRenderable()->animateHit();
    
    // inform other components so they can render particles or w/e
    Event evt(EventUID::EntityAttacked);
    evt.Any = (void*)inTarget->getRenderable();
    EventManager::getSingleton().hook(evt);
    
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

    if (inTarget->isDead()) {
      Combat::getSingleton().unitAttacked(this);
      Combat::getSingleton().doBattle();

      return;
    }

    this->mRenderable->trackEnemyPuppet();
    this->move(POS_ATTACK, boost::bind(&CUnit::attackAfterMoving, this, inTarget) );
  }
  
  void CUnit::attackAfterMoving(CPuppet* inTarget) {
    this->mAttackTarget = inTarget;
    this->attack(inTarget, boost::bind(&CUnit::cleanupAfterAttacking, this, inTarget) );  
  }
  
  void CUnit::cleanupAfterAttacking(CPuppet* inTarget) {
    // update the stat HUDs
    inTarget->updateTextOverlay();
    
    this->mAttackTarget = 0;
    
    std::cout << "I attacked puppet, going back now\n";
    
    this->move(POS_CHARGING, boost::bind(&CUnit::cleanupAfterMovingBack, this, inTarget) ); // on move back to charging position    
  }
  
  void CUnit::cleanupAfterMovingBack(CPuppet* inTarget) {
    std::cout << "I'm back to charging position now, asking Combat to continue battle\n";
    Combat::getSingleton().unitAttacked(this);
    Combat::getSingleton().doBattle();    
  }

  void CUnit::moveAndAttack(std::list<CUnit*> inBlockers) {
#if 0
    // move to offense position
    //fDoneBlocking = false;

    mBlockers = inBlockers;

    this->reset();
    this->move(POS_OFFENCE, boost::bind(&CUnit::doAttack, this, boost::ref(mBlockers)));
#endif
  }

  void CUnit::doAttack(std::list<CUnit*>& inBlockers) {

    updateTextOverlay();
#if 0
    /*
     * for every blocker X in blockers do:
     *  - move(X,POS_DEFENSE)
     *  - attack(this,X)
     *  - if X is not dead, move(X,POS_CHARGING)
     *  - if this is dead, mark for removal and abort
     * if trample && currentAP > 0
     *  - move(this,POS_ATTACK)
     *  - attack(this,puppet)
     * move(this,POS_CHARGING)
     * mark as done
     */

    // we're dead, tell Combat we're done and to process the next unit
    if (isDead()) {

      Combat::getSingleton().unitAttacked(this);
      Combat::getSingleton().doBattle();

      return;
    }

    // we're done with blockers
    if (inBlockers.empty()) {
      // if this is a trampling unit, and we still got AP left,
      // proceed to hitting the puppet
      if (fIsTrampling && mAP > 0) {
        move(POS_ATTACK, [&](CUnit*) -> void {
          this->attack(static_cast<CPuppet*>((Entity*)inBlockers.front()->getOwner()),
          [&]() -> void {
            // now move back
            move(POS_CHARGING, [&](CUnit*) -> void {
              // and mark us as done
              Combat::getSingleton().unitAttacked(this);
              Combat::getSingleton().doBattle();
            });
          });
        });
      } else { // no trample, just move back and mark as done
        move(POS_CHARGING);
        this->mRenderable->trackEnemyPuppet();

        Combat::getSingleton().unitAttacked(this);
        Combat::getSingleton().doBattle();


        return;
      }
    }

    // get the next blocker, move it to the defense position, and attack it
    auto blocker = inBlockers.front();

    // there's a special case where the attacker has 0 AP left, and the blocker
    // has 0 base AP, then there's no point moving it to defense pos, we should
    // just skip it
    if (mAP <= 0 && blocker->getAP() == 0) {
      inBlockers.pop_front();

      return this->doAttack(inBlockers);
    }

    if (blocker->isDying()) {
      inBlockers.pop_front();

      return this->doAttack(inBlockers);
    }

    blocker->getRenderable()->trackEnemyUnit(this);
    this->getRenderable()->trackEnemyUnit(blocker);

    blocker->move(POS_DEFENCE, [&, blocker](CUnit*) -> void {

      /*
       * basically,
       *  1) if we ran out of AP, then only the blocker hits us
       * otherwise,
       *  2) we hit the blocker, if they're not dead, they hit us back
       */

      if (mAP <= 0) {
        if (blocker->getBaseAP() > 0) { // can the blocker attack?
          blocker->attack(this, [&, blocker]() -> void {
            blocker->move(POS_CHARGING);

            inBlockers.pop_front();

            return this->doAttack(inBlockers);
          }, false);
        }
      } else {
        this->attack(blocker, [&, blocker]() -> void {
          // if the blocker didn't die, it means we ran out of AP and/or dead,
          // but anyway we're done with this guy
          if (!blocker->isDead()) {
            blocker->move(POS_CHARGING);
          }

          inBlockers.pop_front();

          // repeat until we're done
          return this->doAttack(inBlockers);
        }, true);

      }
    });
#endif
  }

  void CUnit::onVictory() {

		//mRenderable->setBaseAnimation(Renderable::ANIM_DANCE, true);
		//mRenderable->setTopAnimation(Renderable::ANIM_NONE);
		//// disable hand animation because the dance controls hands
		//mRenderable->mAnims[Renderable::ANIM_HANDS_RELAXED]->setEnabled(false);

    GfxEngine::getSingletonPtr()->stopUpdatingMe(this);
  }

  void CUnit::rest() {
    if (isResting())
      return;

    Unit::rest();
    updateTextOverlay();
    mRenderable->animateRest();
  }

  void CUnit::getUp() {
    if (!isResting())
      return;

    Unit::getUp();

    //mRenderable->setBaseAnimation(Renderable::ANIM_JUMP_START, true);
    //mRenderable->setTopAnimation(Renderable::ANIM_NONE);
    //mRenderable->mTimer = 0;
    float length_sec = mRenderable->animateGetUp();

    /*mTimer->expires_from_now(boost::posix_time::milliseconds(length_sec * 1000));
    mTimer->async_wait([&](boost::system::error_code e) -> void { this->mRenderable->animateIdle(); } );*/


    updateTextOverlay();
  }

  void CUnit::updateFromEvent(const Event& evt) {
    Unit::updateFromEvent(evt);

    updateTextOverlay();
  }

  bool CUnit::isDying() const { return fDying; };
} // end of namespace
