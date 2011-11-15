#include "Mobile.h"
#include "GfxEngine.h"
#include "Unit.h"
#include "Renderable.h"

namespace Pixy {

  float Mobile::mDefaultWalkSpeed = 0.15f;
  Ogre::Real Mobile::mRotFactor = 1.0f / 30.0f;

  Mobile::Mobile()
  : mRenderable(0),
    fRotating(false),
    mMoveDirection(Ogre::Vector3::ZERO)
  {
  }

  Mobile::~Mobile()
  {
    if (mRaySceneQuery) {
      GfxEngine::getSingletonPtr()->getSceneMgr()->destroyQuery(mRaySceneQuery);
      mRaySceneQuery = 0;
    }

    mRenderable = 0;
  }

  void Mobile::copyFrom(const Mobile& src)
  {
    fIsMoving = src.fIsMoving;
    mWalkSpeed = src.mWalkSpeed;
    mMoveSpeed = src.mMoveSpeed;
    mDestination = src.mDestination;
    mMoveDirection = src.mMoveDirection;
  }

  void Mobile::setup(Renderable* inRnd)
  {
    //mSceneMgr = GfxEngine::getSingletonPtr()->getSceneMgr();
    //mSceneNode = inNode;
    //mSceneObject = inEntity;
    mRenderable = inRnd;
    mRaySceneQuery = GfxEngine::getSingletonPtr()->getSceneMgr()->createRayQuery(Ogre::Ray());
    mRaySceneQuery->setSortByDistance(true);
  }

  void Mobile::move(int inWaypoint)
  {
    mDestinationWP = inWaypoint;
    GfxEngine::getSingletonPtr()->updateMe(this);
  }

  void Mobile::step(unsigned long dt) {
    // keep moving
    if (!doMove(dt)) {

      // we arrived
      GfxEngine::getSingletonPtr()->stopUpdatingMe(this);

      // if we came back from an attack and still waiting at the charging spot
      // turn around 180 degrees to face the enemy
      /*if ((mPosition != POS_READY && mDestinationWP == POS_CHARGING))
      {
        //~ mRenderable->getSceneNode()->yaw(Ogre::Degree(180));
        //~ mRenderable->trackEnemyPuppet();
        rotateToEnemy();
      } else if (mDestinationWP == POS_READY)
      {
        rotateTo(mWaypoints->at(POS_CHARGING));
      }*/

      // is there a callback?
      if (mCallback)
        mCallback(this);

      //mCallback = 0;
    }

    /*if (fRotating) {
      mSceneNode->yaw(Ogre::Degree(0.1 * (dt/1000)));

      Vector3 src = mSceneNode->getOrientation() * Vector3::UNIT_Z;
      if ((1.0f + src.dotProduct(mRotDirection)) < 0.0001f)
        fRotating = false;
    }*/

    if(fRotating)                                // Process timed rotation
    {
      mRotProgress += mRotFactor;
      if(mRotProgress>1)
      {
        fRotating = false;
      }
      else
      {
        Quaternion delta = Quaternion::Slerp(mRotProgress, mOrientSrc, mOrientDest, true);
        mRenderable->getSceneNode()->setOrientation(delta);
      }
    }  // if mRotating
  }


  bool Mobile::nextLocation(int inDestination)
  {

    Ogre::SceneNode *mSceneNode = mRenderable->getSceneNode();

    if (mDestination == Vector3::ZERO) {

      mDestination = mWaypoints->at(inDestination);  // get walkpoint to our required destination
      //std::cout
      //  << "\tMoving to : "
      //  << mDestination.x << "," << mDestination.y << "," << mDestination.z
      //  << " from "
      //  << mNode->getPosition().x << "," << mNode->getPosition().y << "," << mNode->getPosition().z
      //  << "\n";

      #if 0 // __DISABLED__
      if (inDestination == Unit::State::Attacking) {
        assert(mEnemy);

        Ogre::Real radius = mEnemy->getSceneObject()->getBoundingBox().getSize().z;
        Ogre::Real scale = mEnemy->getSceneNode()->getScale().z;
        int mod = (mDestination.z > mSceneNode->getPosition().z) ? -1 : 1;
        mDestination.z =
          mEnemy->getSceneNode()->getPosition().z +
          (radius * /*scale*/2 * mod);
        //calculatePositionOffset();
        //std::cout << "\tPosition for attacking node: " << mDestination.z <<"\n";
      } else if (inDestination == Unit::State::Blocking) {
        Ogre::Vector3 bbox = mBlockers.front()->getSceneObject()->getBoundingBox().getSize();
        Ogre::Real radius = mBlockers.front()->getSceneObject()->getBoundingBox().getSize().z;
        int mod = (mDestination.z >= mSceneNode->getPosition().z) ? -1 : 1;
        mDestination.z +=
          //mBlockers.front()->getRenderable()->getSceneNode()->getPosition().z +
          ((radius * mBlockers.front()->getSceneNode()->getScale().z) /2 * mod);

        //std::cout << "My blocker's bbox: "
        //  << bbox.x << ","
        //  << bbox.y << ","
        //  << bbox.z << "\n";
      }
      #endif
    }

    mMoveDirection = mDestination - mSceneNode->getPosition();
    mMoveDistance = mMoveDirection.normalise();

    Vector3 src = mSceneNode->getOrientation() * Vector3::UNIT_Z;
    if ((1.0f + src.dotProduct(mMoveDirection)) < 0.0001f)
    {
      //std::cout << " ***** YAWING 180 ****** \n";
        mSceneNode->yaw(Ogre::Degree(180));
    } else
    {
        Ogre::Quaternion quat = src.getRotationTo(mMoveDirection);
        mSceneNode->rotate(quat);
    } // else

    return true;
  } // nextLocation()

  /*void Mobile::calculatePositionOffset(Vector3& inDestination) {
    // ------------------------------
    Ogre::Ray entityRay(mRenderable->getSceneNode()->getPosition(), mMoveDirection);
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
          << mEnemy->getRenderable()->getSceneObject()->getBoundingBox().getSize().x <<","
          << mEnemy->getRenderable()->getSceneObject()->getBoundingBox().getSize().y <<","
          << mEnemy->getRenderable()->getSceneObject()->getBoundingBox().getSize().z << "\n";

          if (itr->distance <= mEnemy->getRenderable()->getSceneObject()->getBoundingBox().getSize().z/4.0f)
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

  bool Mobile::doMove(unsigned long mTimeElapsed)
  {
    Ogre::SceneNode *mSceneNode = mRenderable->getSceneNode();

    nextLocation(mDestinationWP);

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
        mSceneNode->setPosition(mDestination);
        //~ mMoveDirection = Vector3::ZERO;

      } else {
        mSceneNode->translate(mMoveDirection * mMoveSpeed);
      }
      fIsMoving = true;
    } else { // if
      fIsMoving = false;
      mDestination = Vector3::ZERO;
    }

    return fIsMoving;
  };
  bool Mobile::isMoving() const {
    return fIsMoving;
  }

  void Mobile::setWaypoints(std::vector<Vector3>* inWp) {
    mWaypoints = inWp;
  }


  void  Mobile::setWalkSpeed(const float inSpeed) {
    mWalkSpeed = inSpeed;
  }
  float Mobile::getWalkSpeed() const {
    return mWalkSpeed;
  }

  void Mobile::setDefaultWalkSpeed(const float inSpeed) {
    mDefaultWalkSpeed = inSpeed;
  }
  float Mobile::getDefaultWalkSpeed() {
    return mDefaultWalkSpeed;
  }

  void Mobile::setRotationFactor(float inFactor) {
    mRotFactor = 1.0f / inFactor;
  }

  void Mobile::rotateToEnemy() {
    /*CPuppet* mEnemy = 0;
    Combat::puppets_t lPuppets = Combat::getSingleton().getPuppets();
    for (Combat::puppets_t::const_iterator itr = lPuppets.begin();
      itr != lPuppets.end();
      ++itr)
    {
      if ((*itr)->getUID() != mOwner->getOwner()->getUID()) {
        mEnemy = *itr;
        break;
      }
    }

    assert(mEnemy);
    rotateTo(mEnemy->getEntity()->getSceneNode()->getPosition());*/
  }

  void Mobile::rotateTo(const Ogre::Vector3& inDest) {
    Ogre::SceneNode *mSceneNode = mRenderable->getSceneNode();

    mOrientSrc = mSceneNode->getOrientation();
    Vector3 src = mSceneNode->getOrientation( ) * Vector3::UNIT_Z;
    // We want dest orientation, not a relative rotation (quat)
    mOrientDest = (src.getRotationTo(inDest - mSceneNode->getPosition())) * mOrientSrc;
    mRotProgress = 0;
    fRotating = true;
  }
}
