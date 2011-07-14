// Renderable.cpp
#include "Renderable.h"
#include "PixyUtility.h"
#include "Entity.h"
#include <Ogre.h>
#include <cstring>
#include "ogre/MovableTextOverlay.h"
#include "GfxEngine.h"
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

  void Renderable::setupBody()
	{
    using namespace Ogre;
		// create main model
		//mBodyNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(Vector3::UNIT_Y * CHAR_HEIGHT);
		//mSceneObject = mSceneMgr->createEntity("SinbadBody", "Sinbad.mesh");
		//mBodyNode->attachObject(mSceneObject);

		// create swords and attach to sheath
		//LogManager::getSingleton().logMessage("Creating swords");
		mSword1 = mSceneMgr->createEntity(stringify(mOwner->getUID()) + "_SinbadSword1", "Sword.mesh");
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

		mVerticalVelocity = 0;
	}

	void Renderable::setupAnimations()
	{
    using namespace Ogre;

		// this is very important due to the nature of the exported animations
		mSceneObject->getSkeleton()->setBlendMode(ANIMBLEND_CUMULATIVE);

		String animNames[] =
		{"IdleBase", "IdleTop", "RunBase", "RunTop", "HandsClosed", "HandsRelaxed", "DrawSwords",
		"SliceVertical", "SliceHorizontal", "Dance", "JumpStart", "JumpLoop", "JumpEnd"};

		// populate our animation list
		for (int i = 0; i < NUM_ANIMS; i++)
		{
			mAnims[i] = mSceneObject->getAnimationState(animNames[i]);
			mAnims[i]->setLoop(true);
			mFadingIn[i] = false;
			mFadingOut[i] = false;
		}

		// start off in the idle state (top and bottom together)
		setBaseAnimation(ANIM_IDLE_BASE);
		setTopAnimation(ANIM_IDLE_TOP);

		// relax the hands since we're not holding anything
		mAnims[ANIM_HANDS_RELAXED]->setEnabled(true);

		mSwordsDrawn = false;
	}



	void Renderable::setBaseAnimation(AnimID id, bool reset)
	{
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
		Real baseAnimSpeed = 1;
		Real topAnimSpeed = 1;
    Real deltaTime = dt * 0.001f;

		mTimer += deltaTime;

		if (mTopAnimID == ANIM_DRAW_SWORDS)
		{
			// flip the draw swords animation if we need to put it back
			topAnimSpeed = mSwordsDrawn ? -1 : 1;

			// half-way through the animation is when the hand grasps the handles...
			if (mTimer >= mAnims[mTopAnimID]->getLength() / 2 &&
				mTimer - deltaTime < mAnims[mTopAnimID]->getLength() / 2)
			{
				// so transfer the swords from the sheaths to the hands
				mSceneObject->detachAllObjectsFromBone();
				mSceneObject->attachObjectToBone(mSwordsDrawn ? "Sheath.L" : "Handle.L", mSword1);
				mSceneObject->attachObjectToBone(mSwordsDrawn ? "Sheath.R" : "Handle.R", mSword2);
				// change the hand state to grab or let go
				mAnims[ANIM_HANDS_CLOSED]->setEnabled(!mSwordsDrawn);
				mAnims[ANIM_HANDS_RELAXED]->setEnabled(mSwordsDrawn);

				// toggle sword trails
				if (mSwordsDrawn)
				{
					mSwordTrail->setVisible(false);
					mSwordTrail->removeNode(mSword1->getParentNode());
					mSwordTrail->removeNode(mSword2->getParentNode());
				}
				else
				{
					mSwordTrail->setVisible(true);
					mSwordTrail->addNode(mSword1->getParentNode());
					mSwordTrail->addNode(mSword2->getParentNode());
				}
			}

			if (mTimer >= mAnims[mTopAnimID]->getLength())
			{
				// animation is finished, so return to what we were doing before
				if (mBaseAnimID == ANIM_IDLE_BASE) setTopAnimation(ANIM_IDLE_TOP);
				else
				{
					setTopAnimation(ANIM_RUN_TOP);
					mAnims[ANIM_RUN_TOP]->setTimePosition(mAnims[ANIM_RUN_BASE]->getTimePosition());
				}
				mSwordsDrawn = !mSwordsDrawn;
			}
		}
		else if (mTopAnimID == ANIM_SLICE_VERTICAL || mTopAnimID == ANIM_SLICE_HORIZONTAL)
		{
			if (mTimer >= mAnims[mTopAnimID]->getLength())
			{
				// animation is finished, so return to what we were doing before
				if (mBaseAnimID == ANIM_IDLE_BASE) setTopAnimation(ANIM_IDLE_TOP);
				else
				{
					setTopAnimation(ANIM_RUN_TOP);
					mAnims[ANIM_RUN_TOP]->setTimePosition(mAnims[ANIM_RUN_BASE]->getTimePosition());
				}
			}

			// don't sway hips from side to side when slicing. that's just embarrassing.
			if (mBaseAnimID == ANIM_IDLE_BASE) baseAnimSpeed = 0;
		}

    		else if (mBaseAnimID == ANIM_JUMP_START)
		{
			if (mTimer >= mAnims[mBaseAnimID]->getLength())
			{
				// takeoff animation finished, so time to leave the ground!
				setBaseAnimation(ANIM_JUMP_LOOP, true);
				// apply a jump acceleration to the character
				mVerticalVelocity = JUMP_ACCEL;
			}
		}
		else if (mBaseAnimID == ANIM_JUMP_END)
		{
			if (mTimer >= mAnims[mBaseAnimID]->getLength())
			{
				// safely landed, so go back to running or idling
        setBaseAnimation(ANIM_IDLE_BASE);
				setTopAnimation(ANIM_IDLE_TOP);

			}
		}

		// increment the current base and top animation times
		if (mBaseAnimID != ANIM_NONE) mAnims[mBaseAnimID]->addTime(deltaTime * baseAnimSpeed);
		if (mTopAnimID != ANIM_NONE) mAnims[mTopAnimID]->addTime(deltaTime * topAnimSpeed);

		// apply smooth transitioning between our animations
		fadeAnimations(deltaTime);
  }

	void Renderable::updateBody(unsigned long dt)
	{
		mGoalDirection = Ogre::Vector3::ZERO;   // we will calculate this
    Ogre::Real deltaTime = dt * 0.001f;
		if (mBaseAnimID == ANIM_JUMP_LOOP)
		{
			// if we're jumping, add a vertical offset too, and apply gravity
			mSceneNode->translate(0, mVerticalVelocity * deltaTime, 0, Ogre::Node::TS_LOCAL);
			mVerticalVelocity -= GRAVITY * deltaTime;

			Ogre::Vector3 pos = mSceneNode->getPosition();
			if (pos.y <= CHAR_HEIGHT)
			{
				// if we've hit the ground, change to landing state
				pos.y = CHAR_HEIGHT;
				mSceneNode->setPosition(pos);
				setBaseAnimation(ANIM_JUMP_END, true);
				mTimer = 0;
			}
		}
	}

} // end of namespace
