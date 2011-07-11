#include "CUnit.h"
#include "CPuppet.h"
#include "Renderable.h"
#include "GfxEngine.h"
#include "ogre/MovableTextOverlay.h"
#include "Combat.h"

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
    mRenderable(0)
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

    mRenderable = 0;

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
  }

  bool CUnit::live() {
    Unit::live();

    mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, "CUnit " + mName);
    mLog->infoStream() << "created";

    mRenderable = new Renderable(this);

    reset();

    return true;
  };

  void CUnit::die() {
    Unit::die();

    mLog->infoStream() << "dead";
  };



  Renderable* CUnit::getRenderable() {
    return mRenderable;

  }

  bool CUnit::nextLocation(int inDestination)
  {
    Ogre::SceneNode* mNode = mRenderable->getSceneNode();
    //~ int idNode = parseIdNodeFromName(mNode->getName());
//~
    //~ std::deque<Vector3>* mWalklist;
    //~ mWalklist = (inUnit->getOwner() == ID_HOST) ? &hWalklist[idNode] : &cWalklist[idNode];
//~
    //~ if ((*mWalklist).empty())
        //~ return false;


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
      mPosition = mPDestination;

      std::cout << "Unit " << mUID << " arrived at destination: " << mPosition << "\n";

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
    if (mAttackOrder != 0) {
      cap += "[" + stringify(mAttackOrder) + "] ";
    }
    cap += stringify(mCurrentAP) + "/" + stringify(mCurrentHP);
    mRenderable->getText()->setCaption(cap);
  }

  bool CUnit::attack(Pixy::CPuppet* inTarget) {
    Unit::attack(inTarget);

    updateTextOverlay();
  }

  bool CUnit::attack(Pixy::CUnit* inTarget, bool block) {
    Unit::attack(inTarget, block);

    updateTextOverlay();
  }

  void CUnit::moveAndAttack(CPuppet* inTarget) {
    this->reset();

    mAttackTarget = inTarget;
    this->move(POS_ATTACK, [&](CUnit* me) -> void {
      this->attack(static_cast<CPuppet*>(this->mAttackTarget));

      // __DEBUG__
      static_cast<CPuppet*>(mAttackTarget)->updateTextOverlay();
      this->updateTextOverlay();

      this->mAttackTarget = 0;

      std::cout << "I attacked puppet, going back now\n";

      this->move(POS_CHARGING, [&](CUnit*) -> void {
        std::cout << "I'm back to charging position now, asking Combat to continue battle\n";
        Combat::getSingleton().unitAttacked(this);
        Combat::getSingleton().doBattle();
      });
    });
  }

  void CUnit::moveAndAttack(std::list<CUnit*> inBlockers) {
    // move to offense position
    fDoneBlocking = false;

    mBlockers = inBlockers;

    this->reset();
    this->move(POS_OFFENCE, boost::bind(&CUnit::doAttack, this, boost::ref(mBlockers)));
  }

  void CUnit::doAttack(std::list<CUnit*>& inBlockers) {

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

    if (isDead() || fDoneBlocking) {
      Combat::getSingleton().unitAttacked(this);
      Combat::getSingleton().doBattle();

      return;
    }

    // we're done with blockers
    if (inBlockers.empty()) {
      // if this is a trampling unit, and we still got AP left,
      // proceed to hitting the puppet
      if (fIsTrampling && mCurrentAP > 0) {
        move(POS_ATTACK, [&](CUnit*) -> void {
          this->attack(static_cast<CPuppet*>((Entity*)inBlockers.front()->getOwner()));

          // now move back
          move(POS_CHARGING, [&](CUnit*) -> void {
            // and mark us as done
            Combat::getSingleton().unitAttacked(this);
            Combat::getSingleton().doBattle();
          });
        });
      } else { // no trample, just move back and mark as done
        move(POS_CHARGING);

        Combat::getSingleton().unitAttacked(this);
        Combat::getSingleton().doBattle();

        return;
      }
    }

    // get the next blocker, move it to the defense position, and attack it
    auto blocker = inBlockers.front();
    inBlockers.pop_front();
    blocker->move(POS_DEFENCE, [&, blocker, &inBlockers](CUnit*) -> void {
      this->attack(blocker, true);

      // if the blocker didn't die, it means we ran out of AP and/or dead,
      // but anyway we're done
      if (!blocker->isDead()) {
        blocker->move(POS_CHARGING);
        this->fDoneBlocking = true;
      }

      return this->doAttack(inBlockers);
    });
  }
} // end of namespace
