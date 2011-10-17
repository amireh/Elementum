/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

// CEntity.cpp
#include <cstring>
#include "CEntity.h"
#include "PixyUtility.h"
#include "ogre/MovableTextOverlay.h"
#include "GfxEngine.h"
#include "Combat.h"
#include "CPuppet.h"
#include "CUnit.h"

namespace Pixy
{

  float CEntity::mAnimFadeSpeed = 7.5f;
  Ogre::Real CEntity::mRotFactor = 1.0f / 30.0f;

	CEntity::CEntity()
	{
    mSceneNode = 0;
    mSceneObject = 0;
    mText = 0;
    mSceneMgr = 0;
    //mCurrentAnimID = ANIM_NONE;
    //mLoopAnimID = ANIM_NONE;
    mCurrentAnim = 0;
    mLoopAnim = 0;
    mScale = Ogre::Vector3(1,1,1);
    fRotating = false;
	}

  CEntity::~CEntity() {

    for (anim_map_t::iterator itr = mAnims.begin();
      itr != mAnims.end();
      ++itr)
    {
      for (anims_t::iterator anim = itr->second.begin();
        anim != itr->second.end();
        ++anim)
        delete *anim;

      itr->second.clear();
    }

    for (extensions_t::iterator ext = mExtensions.begin(); ext != mExtensions.end(); ++ext)
    {
      mSceneMgr->destroyEntity((*ext)->getName());
    }
    mExtensions.clear();

    if (mText)
      delete mText;

    if (mSceneNode) {
      mSceneNode->setVisible(true);
      GfxEngine::getSingletonPtr()->detachFromScene(this);
    }

		mSceneNode = 0;
    mSceneObject = 0;

    mText = 0;
	}

  CEntity::CEntity(const CEntity& src)
  {
    copyFrom(src);
  }

  CEntity& CEntity::operator=(const CEntity& rhs)
  {
    // check for self-assignment
    if (this == &rhs)
      return (*this);

    copyFrom(rhs);
    return (*this);
  }
  void CEntity::copyFrom(const CEntity& src) {
		mSceneNode = src.mSceneNode;
    mScale = src.mScale;
		mSceneObject = src.mSceneObject;
    mText = src.mText;
    mSceneMgr = src.mSceneMgr;
    mExtensions = src.mExtensions;
    mAnims = src.mAnims;
    mAnimQueue.clear();
    mOrientSrc = src.mOrientSrc;
    mOrientDest = src.mOrientDest;
    mRotProgress = src.mRotProgress;
    mRotFactor = src.mRotFactor;
    fRotating = src.fRotating;
  }


  bool CEntity::live() {

    return true;
  };

  void CPuppet::die() {
    this->hide();

    mLog->infoStream() << "dead";
  };

  void CEntity::setAnimFadeSpeed(float inSpeed) {
    mAnimFadeSpeed = inSpeed;
  }
  float CEntity::getAnimFadeSpeed() {
    return mAnimFadeSpeed;
  }

  void CEntity::setRotationFactor(float inFactor) {
    mRotFactor = 1.0f / inFactor;
  }

	void CEntity::attachSceneNode(Ogre::SceneNode* inNode) { mSceneNode = inNode; }
  void CEntity::attachSceneObject(Ogre::Entity* inObject) {
    mSceneObject = inObject;
    if (mSceneObject)
      mSceneObject->setUserAny(Ogre::Any(this));
  }
  Ogre::SceneNode* CEntity::getSceneNode() { return mSceneNode; }
  Ogre::Entity* CEntity::getSceneObject() { return mSceneObject; }

  MovableTextOverlay* CEntity::getText() const { return mText; }
  void CEntity::setText(MovableTextOverlay* inT) { mText = inT; }

  void CEntity::hide() {
    mSceneNode->setVisible(false);
    if (mText)
    {
      mText->hide(true);
      mText->enable(false);
      mText->update(1);
    }
  }

  void CEntity::show() {
    mSceneNode->setVisible(true);
    if (mText)
    {
      mText->hide(false);
      mText->enable(true);
      mText->update(1);
    }
  }

  void CEntity::setup(Ogre::SceneManager* inSceneMgr) {
    mSceneMgr = inSceneMgr;

    setupBody();
    setupAnimations();
  }

  Ogre::Entity* CEntity::attachExtension(std::string inMesh, std::string inBone) {
    Ogre::Entity* tmp =
      mSceneMgr->createEntity(stringify(getUID()) + "extension" + stringify(mExtensions.size()), inMesh);

    mSceneObject->attachObjectToBone(inBone, tmp);
    mExtensions.push_back(tmp);

    return tmp;
  }

  void CEntity::setupBody()
	{
	}

	void CEntity::setupAnimations()
	{

    using namespace Ogre;

		// this is very important due to the nature of the exported animations
		mSceneObject->getSkeleton()->setBlendMode(ANIMBLEND_CUMULATIVE);

    for (anim_map_t::iterator itr = mAnims.begin();
      itr != mAnims.end();
      ++itr)
    {
      for (anims_t::iterator anim = itr->second.begin();
        anim != itr->second.end();
        ++anim)
      {
        (*anim)->FadingIn = false;
        (*anim)->FadingOut = false;
      }
    }

    //mCurrentAnimID = ANIM_NONE;

    return;
	}


	void CEntity::fadeAnimations(Real deltaTime)
	{

    for (anim_map_t::iterator itr = mAnims.begin();
      itr != mAnims.end();
      ++itr)
    {
      for (anims_t::iterator anim = itr->second.begin();
        anim != itr->second.end();
        ++anim)
      {
        if ((*anim)->FadingIn)
        {
          // slowly fade this animation in until it has full weight
          Real newWeight = (*anim)->State->getWeight() + deltaTime * mAnimFadeSpeed;
          (*anim)->State->setWeight(Math::Clamp<Real>(newWeight, 0, 1));
          if (newWeight >= 1)
            (*anim)->FadingIn = false;
        }
        else if ((*anim)->FadingOut)
        {
          // slowly fade this animation out until it has no weight, and then disable it
          Real newWeight = (*anim)->State->getWeight() - deltaTime * mAnimFadeSpeed;
          (*anim)->State->setWeight(Math::Clamp<Real>(newWeight, 0, 1));
          if (newWeight <= 0)
          {
            (*anim)->State->setEnabled(false);
            (*anim)->FadingOut = false;
          }
        }
      }
		}
	}

  void CEntity::updateAnimations(unsigned long dt) {
    //~ return;

		Real baseAnimSpeed = 1;
		Real topAnimSpeed = 1;
    Real deltaTime = dt * 0.001f;

		mTimer += deltaTime;

		// increment the current animation times
		if (mCurrentAnim) {
      mCurrentAnim->State->addTime(deltaTime * baseAnimSpeed);
      if (mCurrentAnim->State->hasEnded()) {

        if (mCurrentAnim->isMini())
          mAnimQueue.pop_front();

        _applyNextAnimation();
      }
    }
    //animateIdle();

		// apply smooth transitioning between our animations
		fadeAnimations(deltaTime);
  }

	void CEntity::updateBody(unsigned long dt)
	{
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
        mSceneNode->setOrientation(delta);
      }
    }  // if mRotating
	}

  void  CEntity::registerAnimationState(AnimID inId, std::string inState, bool loop) {
    //~ assert(!mAnims[inId]);
    assert(inId != ANIM_NONE);
    //assert(mAnims.find(inId) != mAnims.end());
    if (mAnims.find(inId) == mAnims.end())
      mAnims.insert( std::make_pair(inId, anims_t()) );

    Animation* _anim = new Animation();
    _anim->ID = inId;
    _anim->FadingIn = false;
    _anim->FadingOut = false;
    _anim->State = mSceneObject->getAnimationState(inState);
    _anim->State->setLoop(loop);

    mAnims[inId].push_back(_anim);
    _anim = 0;
  }

  float CEntity::animateLive() {
    return this->_animate(ANIM_LIVE, true);
  }
  float CEntity::animateDie() {
    return this->_animate(ANIM_DIE, true);
  }
  float CEntity::animateIdle() {
    return this->_animate(ANIM_IDLE);
  }
  float CEntity::animateWalk() {
    return this->_animate(ANIM_WALK);
  }
  float CEntity::animateRun() {
    return this->_animate(ANIM_RUN);
  }
  float CEntity::animateAttack() {
    return this->_animate(ANIM_ATTACK);
  }
  float CEntity::animateHit() {
    return this->_animate(ANIM_HIT, true);
  }
  float CEntity::animateRest() {
    return this->_animate(ANIM_REST);
  }
  float CEntity::animateGetUp() {
    return this->_animate(ANIM_GETUP);
  }
  float CEntity::_animate(AnimID id, bool override) {
    if (mAnims.find(id) == mAnims.end() || mAnims[id].empty()) {
      std::cerr << "ERROR! Asked to play a non-existing animation: " << id << ", gracefully rejecting\n";
      return 0;
    }

    Animation* _anim = mAnims[id].at(rand() % mAnims[id].size());

    // first animation must be a looping one
    if (!mCurrentAnim)
      if (!_anim->isMini()) {
        //mLoopAnimID = id;
        mLoopAnim = _anim;
        _applyNextAnimation();
      } else
        throw std::runtime_error("must have a base loop animation first!");

    // replacing the loop anim
    else if (!_anim->isMini()) {
      assert(mLoopAnim);
      //mLoopAnimID = id;
      mLoopAnim = _anim;
      // if there are no mini-anims running, apply the new loop anim
      if (mAnimQueue.empty())
        _applyNextAnimation();
    }

    // it's a mini-anim
    else if (_anim->isMini()) {
      if (override)
        mAnimQueue.push_front(_anim);
      else
        mAnimQueue.push_back(_anim);

      // if there are no mini-anims running, apply this one immediately
      if (mAnimQueue.size() == 1 || override)
        _applyNextAnimation();
    } else
      throw std::runtime_error("can't be here!");

    return _anim->State->getLength();
  }

  void CEntity::_applyNextAnimation() {
    Animation* _nextAnim = 0;

    // if there are pending mini-anims, play them
    if (!mAnimQueue.empty()) {
      _nextAnim = mAnimQueue.front();
      //std::cout << "Playing a mini-animation " << _nextAnim->ID << " (" << mAnimQueue.size() << " in queue)\n";
    } else { // otherwise we play the loop animation
      _nextAnim = mLoopAnim;
      //std::cout << "Playing loop animation " << mLoopAnim->ID << "\n";
    }

    assert(_nextAnim);

		if (mCurrentAnim)
		{
			// if we have an old animation, fade it out
      mCurrentAnim->FadingIn = false;
      mCurrentAnim->FadingOut = true;
		}

		//mCurrentAnimID = _nextAnimID;
    mCurrentAnim = _nextAnim;

    // we have a new animation, reset, enable, and fade it in
    _nextAnim->State->setEnabled(true);
    _nextAnim->State->setWeight(0);
    _nextAnim->State->setTimePosition(0);
    _nextAnim->FadingOut = false;
    _nextAnim->FadingIn = true;

  }

  void CEntity::trackEnemyPuppet() {
    return;

    CPuppet* mEnemy = 0;
    Combat::puppets_t lPuppets = Combat::getSingleton().getPuppets();
    for (Combat::puppets_t::const_iterator itr = lPuppets.begin();
      itr != lPuppets.end();
      ++itr)
    {
      if ((*itr)->getUID() != getOwner()->getUID()) {
        mEnemy = *itr;
        break;
      }
    }

    assert(mEnemy);

    mSceneNode->setAutoTracking(true, mEnemy->getSceneNode());
  }

  void CEntity::trackEnemyUnit(CUnit* inUnit) {
    return;
    //mSceneNode->setAutoTracking(true, inUnit->getSceneNode());
  }

  /*
  void CEntity::setOrientation(Ogre::Quaternion inQuat) {
    mOrientation = inQuat;
    resetOrientation();
  }

  void CEntity::resetOrientation() {
    mSceneNode->setOrientation(mOrientation);
  }
  */

  void CEntity::rotateToEnemy() {
    CPuppet* mEnemy = 0;
    Combat::puppets_t lPuppets = Combat::getSingleton().getPuppets();
    for (Combat::puppets_t::const_iterator itr = lPuppets.begin();
      itr != lPuppets.end();
      ++itr)
    {
      if ((*itr)->getUID() != getOwner()->getUID()) {
        mEnemy = *itr;
        break;
      }
    }

    assert(mEnemy);
    rotateTo(mEnemy->getSceneNode()->getPosition());
  }

  void CEntity::rotateTo(const Ogre::Vector3& inDest) {
    mOrientSrc = mSceneNode->getOrientation();
    Vector3 src = mSceneNode->getOrientation( ) * Vector3::UNIT_Z;
    // We want dest orientation, not a relative rotation (quat)
    mOrientDest = (src.getRotationTo(inDest - mSceneNode->getPosition())) * mOrientSrc;
    mRotProgress = 0;
    fRotating = true;
  }

  Puppet* const CEntity::toPuppet() const
  {
    return dynamic_cast<CPuppet*>((CEntity*)this);
  }
  Unit* const CEntity::toUnit() const
  {
    return dynamic_cast<CUnit*>((CEntity*)this);
  }

  Entity* CEntity::getOwner() const
  {
    return dynamic_cast<CEntity*>(this->mOwner);
  }
} // end of namespace
