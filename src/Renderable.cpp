// Renderable.cpp
#include "Renderable.h"
#include "PixyUtility.h"
#include "Entity.h"
#include <Ogre.h>
#include <cstring>
#include "ogre/MovableTextOverlay.h"
#include "GfxEngine.h"
#include "Combat.h"
#include "CPuppet.h"
#include "CUnit.h"

namespace Pixy
{

	Renderable::Renderable(Pixy::Entity* inOwner)
	{
    mOwner = inOwner;
    mSceneNode = 0;
    mSceneObject = 0;
    mText = 0;
    mSceneMgr = 0;
    nrHandlers = 0;
    mBaseAnimID = ANIM_NONE;
    mLoopAnim = ANIM_NONE;
    mScale = Ogre::Vector3(1,1,1);
    fRotating = false;
    //~ mRotDirection = Ogre::Vector3::ZERO;
	};

  Renderable::~Renderable() {
    mSceneNode->setVisible(true);
    GfxEngine::getSingletonPtr()->detachFromScene(this);

    mOwner = 0;

		mSceneNode = 0;
    mSceneObject = 0;
    delete mText;
    mText = 0;
    nrHandlers = 0;
	};

  void Renderable::setScale(Ogre::Vector3 inScale) {
    mScale = inScale;
  }

  void Renderable::setScale(float inScale) {
    mScale = Ogre::Vector3(inScale, inScale, inScale);
  }

  Ogre::Vector3 const& Renderable::getScale() const {
    return mScale;
  }

  /*Renderable::Renderable(const Renderable& src)
  {

    copyFrom(src);
  };

  Renderable& Renderable::operator=(const Renderable& rhs)
  {
    // check for self-assignment
    if (this == &rhs)
    {
        return (*this);
    }

    copyFrom(rhs);

    return (*this);
  };

  void Renderable::copyFrom(const Renderable& src)
  {
    mSceneNode = src.mSceneNode;
    mSceneObject = src.mSceneObject;
    mOwner = src.mOwner;
    mText = src.mText;
  };*/

	void Renderable::attachSceneNode(Ogre::SceneNode* inNode) { mSceneNode = inNode; }
  void Renderable::attachSceneObject(Ogre::Entity* inObject) { mSceneObject = inObject; }
  Ogre::SceneNode* Renderable::getSceneNode() { return mSceneNode; }
  Ogre::Entity* Renderable::getSceneObject() { return mSceneObject; }

  Entity* Renderable::getEntity() { return mOwner; }

  MovableTextOverlay* Renderable::getText() const { return mText; }
  void Renderable::setText(MovableTextOverlay* inT) { mText = inT; }

  void Renderable::hide() {
    mSceneNode->setVisible(false);
    mText->hide(true);
    mText->enable(false);
    mText->update(1);
  }

  void Renderable::show() {
    mSceneNode->setVisible(true);
    mText->hide(false);
    mText->enable(true);
    mText->update(1);
  }

  void Renderable::setup(Ogre::SceneManager* inSceneMgr) {
    mSceneMgr = inSceneMgr;

    setupBody();
    setupAnimations();
  }

  void Renderable::attachExtension(std::string inMesh, std::string inBone) {
    Ogre::Entity* tmp =
      mSceneMgr->createEntity(stringify(mOwner->getUID()) + "extension" + stringify(mExtensions.size()), inMesh);

    mSceneObject->attachObjectToBone(inBone, tmp);
    mExtensions.push_back(tmp);
  }

  void Renderable::setupBody()
	{
    //mSword1 = mSceneMgr->createEntity(stringify(mOwner->getUID()) + "knight_sword", "DarkKnightSword.mesh");
    //mSceneObject->attachObjectToBone("Bone01", mSword1);
    //mSword1->setUserAny(Ogre::Any(this));
    return;
    using namespace Ogre;
		// create main model
		//mBodyNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(Vector3::UNIT_Y * CHAR_HEIGHT);
		//mSceneObject = mSceneMgr->createEntity("SinbadBody", "Sinbad.mesh");
		//mBodyNode->attachObject(mSceneObject);

		// create swords and attach to sheath
		//LogManager::getSingleton().logMessage("Creating swords");
		/*mSword1 = mSceneMgr->createEntity(stringify(mOwner->getUID()) + "_SinbadSword1", "Sword.mesh");
		mSword2 = mSceneMgr->createEntity(stringify(mOwner->getUID()) + "_SinbadSword2", "Sword.mesh");
		mSceneObject->attachObjectToBone("Sheath.L", mSword1);
		mSceneObject->attachObjectToBone("Sheath.R", mSword2);

    mSword1->setUserAny(Ogre::Any(this));
    mSword2->setUserAny(Ogre::Any(this));

		//LogManager::getSingleton().logMessage("Creating the chains");
		// create a couple of ribbon trails for the swords, just for fun
		NameValuePairList params;
		params["numberOfChains"] = "2";
		params["maxElements"] = "80";
		mSwordTrail = (RibbonTrail*)mSceneMgr->createMovableObject("RibbonTrail", &params);
		mSwordTrail->setMaterialName("Examples/LightRibbonTrail");
		mSwordTrail->setTrailLength(20);
		mSwordTrail->setVisible(false);
    static_cast<Ogre::MovableObject*>(mSwordTrail)->setUserAny(Ogre::Any(this));
		mSceneMgr->getRootSceneNode()->attachObject(mSwordTrail);


		for (int i = 0; i < 2; i++)
		{
			mSwordTrail->setInitialColour(i, 1, 0.8, 0);
			mSwordTrail->setColourChange(i, 0.75, 1.25, 1.25, 1.25);
			mSwordTrail->setWidthChange(i, 1);
			mSwordTrail->setInitialWidth(i, 0.5);
		}

		mVerticalVelocity = 0;*/
	}

	void Renderable::setupAnimations()
	{

    using namespace Ogre;

		// this is very important due to the nature of the exported animations
		mSceneObject->getSkeleton()->setBlendMode(ANIMBLEND_CUMULATIVE);

		for (int i = 0; i < NUM_ANIMS; i++)
		{
			mFadingIn[i] = false;
			mFadingOut[i] = false;
		}

    mBaseAnimID = ANIM_NONE;

		/*String animNames[] =
		{"IdleBase", "IdleTop", "RunBase", "RunTop", "HandsClosed", "HandsRelaxed", "DrawSwords",
		"SliceVertical", "SliceHorizontal", "Dance", "JumpStart", "JumpLoop", "JumpEnd"};*/
    /*std::vector<Ogre::String> animNames;
    animNames.push_back("Idle_1");
    animNames.push_back("Idle_2");
    animNames.push_back("Run");
    animNames.push_back("Hit_1");
    animNames.push_back("Death_1");
    animNames.push_back("Attack_1");

		// populate our animation list
		//for (int i = 0; i < NUM_ANIMS; i++)
		for (int i = 0; i < animNames.size(); i++)
		{
			mAnims[i] = mSceneObject->getAnimationState(animNames[i]);
			mAnims[i]->setLoop(true);
			mFadingIn[i] = false;
			mFadingOut[i] = false;
		}

		// start off in the idle state (top and bottom together)
		setBaseAnimation(ANIM_IDLE1);*/
		//setTopAnimation(ANIM_IDLE_TOP);

		// relax the hands since we're not holding anything
		//~ mAnims[ANIM_HANDS_RELAXED]->setEnabled(true);

		//~ mSwordsDrawn = false;
    return;
	}



	void Renderable::setBaseAnimation(AnimID id, bool reset)
	{
    //~ return;
		if (mBaseAnimID >= 0 && mBaseAnimID < NUM_ANIMS)
		{
			// if we have an old animation, fade it out
			mFadingIn[mBaseAnimID] = false;
			mFadingOut[mBaseAnimID] = true;
		}

		mBaseAnimID = id;

		if (id != ANIM_NONE)
		{
			// if we have a new animation, enable it and fade it in
			mAnims[id]->setEnabled(true);
			mAnims[id]->setWeight(0);
			mFadingOut[id] = false;
			mFadingIn[id] = true;
			if (reset) mAnims[id]->setTimePosition(0);
		}
	}

	void Renderable::setTopAnimation(AnimID id, bool reset)
	{
    return;
		if (mTopAnimID >= 0 && mTopAnimID < NUM_ANIMS)
		{
			// if we have an old animation, fade it out
			mFadingIn[mTopAnimID] = false;
			mFadingOut[mTopAnimID] = true;
		}

		mTopAnimID = id;

		if (id != ANIM_NONE)
		{
			// if we have a new animation, enable it and fade it in
			mAnims[id]->setEnabled(true);
			mAnims[id]->setWeight(0);
			mFadingOut[id] = false;
			mFadingIn[id] = true;
			if (reset) mAnims[id]->setTimePosition(0);
		}
	}


	void Renderable::fadeAnimations(Real deltaTime)
	{
    //~ return;
		for (int i = 0; i < NUM_ANIMS; i++)
		{
			if (mFadingIn[i])
			{
				// slowly fade this animation in until it has full weight
				Real newWeight = mAnims[i]->getWeight() + deltaTime * ANIM_FADE_SPEED;
				mAnims[i]->setWeight(Math::Clamp<Real>(newWeight, 0, 1));
				if (newWeight >= 1) mFadingIn[i] = false;
			}
			else if (mFadingOut[i])
			{
				// slowly fade this animation out until it has no weight, and then disable it
				Real newWeight = mAnims[i]->getWeight() - deltaTime * ANIM_FADE_SPEED;
				mAnims[i]->setWeight(Math::Clamp<Real>(newWeight, 0, 1));
				if (newWeight <= 0)
				{
					mAnims[i]->setEnabled(false);
					mFadingOut[i] = false;
				}
			}
		}
	}

  void Renderable::updateAnimations(unsigned long dt) {
    //~ return;

		Real baseAnimSpeed = 1;
		Real topAnimSpeed = 1;
    Real deltaTime = dt * 0.001f;

		mTimer += deltaTime;

		// increment the current animation times
		if (mBaseAnimID != ANIM_NONE) {
      mAnims[mBaseAnimID]->addTime(deltaTime * baseAnimSpeed);
      if (mAnims[mBaseAnimID]->hasEnded()) {

        if (!mAnims[mBaseAnimID]->getLoop())
          mAnimQueue.pop_front();

        _applyNextAnimation();
      }
    }
      //animateIdle();
		//if (mTopAnimID != ANIM_NONE) mAnims[mTopAnimID]->addTime(deltaTime * topAnimSpeed);

		// apply smooth transitioning between our animations
		fadeAnimations(deltaTime);
  }

	void Renderable::updateBody(unsigned long dt)
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

  void  Renderable::registerAnimationState(AnimID inId, std::string inState, bool loop) {
    //~ assert(!mAnims[inId]);

    mAnims[inId] = mSceneObject->getAnimationState(inState);
    mAnims[inId]->setLoop(loop);
    mFadingIn[inId] = false;
    mFadingOut[inId] = false;
  }

  void  Renderable::setRunSpeed(float inSpeed) {
    mRunSpeed = inSpeed;
  }
  float Renderable::animateLive() {
    return this->_animate(rand() % 2 == 0 ? ANIM_LIVE1 : ANIM_LIVE2);
  }
  float Renderable::animateDie() {
    return this->_animate(rand() % 2 == 0 ? ANIM_DEATH1 : ANIM_DEATH2);
  }
  float Renderable::animateIdle() {
    return this->_animate(rand() % 2 == 0 ? ANIM_IDLE1 : ANIM_IDLE2);
  }
  float Renderable::animateWalk() {
    return this->_animate(ANIM_WALK);
  }
  float Renderable::animateRun() {
    return this->_animate(ANIM_RUN);
  }
  float Renderable::animateAttack() {
    return this->_animate(rand() % 2 == 0 ? ANIM_ATTACK1 : ANIM_ATTACK2);
  }
  float Renderable::animateHit() {
    return this->_animate(rand() % 2 == 0 ? ANIM_HIT1 : ANIM_HIT2);
  }
  float Renderable::animateRest() {
    return this->_animate(ANIM_REST);
  }
  float Renderable::animateGetUp() {
    return this->_animate(ANIM_GETUP);
  }
  float Renderable::_animate(AnimID id) {
    assert(mAnims[id]);

    // first animation must be a looping one
    if (mBaseAnimID == ANIM_NONE)
      if (mAnims[id]->getLoop()) {
        mLoopAnim = id;
        _applyNextAnimation();
      } else
        throw std::runtime_error("must have a base loop animation first!");

    // replacing the loop anim
    else if (mAnims[id]->getLoop()) {
      assert(mLoopAnim != ANIM_NONE);
      mLoopAnim = id;
      // if there are no mini-anims running, apply the new loop anim
      if (mAnimQueue.empty())
        _applyNextAnimation();
    }

    // it's a mini-anim
    else if (!mAnims[id]->getLoop()) {
      mAnimQueue.push_back(id);
      std::cout << "Queuing a mini-anim, queue has: " << mAnimQueue.size() << "\n";
      // if there are no mini-anims running, apply this one immediately
      if (mAnimQueue.size() == 1)
        _applyNextAnimation();
    } else
      throw std::runtime_error("can't be here!");

    return mAnims[id]->getLength();
  }

  void Renderable::_applyNextAnimation() {
    AnimID nextAnimID = ANIM_NONE;

    // if there are pending mini-anims, play them
    if (!mAnimQueue.empty()) {
      nextAnimID = mAnimQueue.front();
      std::cout << "Playing a mini-animation " << nextAnimID << " (" << mAnimQueue.size() << " in queue)\n";
    } else { // otherwise we play the loop animation
      nextAnimID = mLoopAnim;
      std::cout << "Playing loop animation " << mLoopAnim << "\n";
    }

    assert(nextAnimID != ANIM_NONE);

		if (mBaseAnimID >= 0 && mBaseAnimID < NUM_ANIMS)
		{
			// if we have an old animation, fade it out
			mFadingIn[mBaseAnimID] = false;
			mFadingOut[mBaseAnimID] = true;
		}

		mBaseAnimID = nextAnimID;

		/*if (nextAnimID != ANIM_NONE)
		{*/
			// we have a new animation, enable it and fade it in
			mAnims[nextAnimID]->setEnabled(true);
			mAnims[nextAnimID]->setWeight(0);
			mFadingOut[nextAnimID] = false;
			mFadingIn[nextAnimID] = true;
      // reset it
			mAnims[nextAnimID]->setTimePosition(0);
		//}

  }

  void Renderable::trackEnemyPuppet() {
    CPuppet* mEnemy = 0;
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

    mSceneNode->setAutoTracking(true, mEnemy->getRenderable()->getSceneNode());
  }

  void Renderable::trackEnemyUnit(CUnit* inUnit) {
    mSceneNode->setAutoTracking(true, inUnit->getRenderable()->getSceneNode());
  }

  void Renderable::setOrientation(Ogre::Quaternion inQuat) {
    mOrientation = inQuat;
    resetOrientation();
  }

  void Renderable::resetOrientation() {
    mSceneNode->setOrientation(mOrientation);
  }

  void Renderable::rotateToEnemy() {
    CPuppet* mEnemy = 0;
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

    mRotFactor = 1.0f / 30;
    mOrientSrc = mSceneNode->getOrientation();
    //~ mOrientDest = mEnemy->getRenderable()->getSceneNode()->getOrientation() * mOrientSrc;           // We want dest orientation, not a relative rotation (quat)
    Vector3 src = mSceneNode->getOrientation( ) * Vector3::UNIT_Z;
    mOrientDest = (src.getRotationTo(mEnemy->getRenderable()->getSceneNode()->getPosition() - mSceneNode->getPosition())) * mOrientSrc;           // We want dest orientation, not a relative rotation (quat)
    mRotProgress = 0;

    /*Vector3 src = mSceneNode->getOrientation() * Vector3::NEGATIVE_UNIT_Z;
    Ogre::Radian angle = src.angleBetween(mEnemy->getRenderable()->getSceneNode()->getPosition());
    mRotDirection = mEnemy->getRenderable()->getSceneNode()->getPosition() - mSceneNode->getPosition();
    mRotQuat = src.getRotationTo(mRotDirection);
    mSceneNode->rotate(mRotQuat );*/

    //~ std::cout << "Angle between the two vecs =  " << src.angleBetween(mEnemy->getRenderable()->getSceneNode()->getPosition()) << "\n";
    //~ std::cout << "Rotation quaternion: "
      //~ << mRotQuat.w << ","
      //~ << mRotQuat.x << ","
      //~ << mRotQuat.y << ","
      //~ << mRotQuat.z << "\n";

    fRotating = true;
  }
} // end of namespace
