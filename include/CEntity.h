/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_CEntity_H
#define H_CEntity_H

#include "Pixy.h"
#include "BaseEntity.h"
#include <Ogre.h>

class MovableTextOverlay;

namespace Pixy
{
  class Entity;
  class CUnit;
  class CPuppet;
	/*! \class Entity Entity.h "src/Entity.h"
	 *
	 * \brief Defines base attributes and actions for GameObjects.
	 *
	 * \note Please note that for the creation of GameObjects
	 * refer to their respective Factories, do NOT use this
	 * directly.
	 */
	class CEntity : public virtual Entity
	{

    public:

    // all the animations our character has, and a null ID
    // some of these affect separate body parts and will be blended together
    enum AnimID
    {
      ANIM_NONE=0,
      ANIM_LIVE,
      ANIM_IDLE,
      ANIM_WALK,
      ANIM_RUN,
      ANIM_ATTACK,
      ANIM_HIT,
      ANIM_REST,
      ANIM_GETUP,
      ANIM_DIE
    };

		CEntity();
		CEntity& operator=(const CEntity& rhs);
		CEntity(const CEntity& src);
		virtual ~CEntity();

    virtual bool live();
    virtual void die();

		virtual void attachSceneNode(Ogre::SceneNode* inNode);
		virtual Ogre::SceneNode* getSceneNode();

		virtual void attachSceneObject(Ogre::Entity* inObject);
		virtual Ogre::Entity* getSceneObject();

    virtual void setup(Ogre::SceneManager*);
    void updateAnimations(unsigned long deltaTime);
    void updateBody(unsigned long deltaTime);

    MovableTextOverlay* getText() const;
    void setText(MovableTextOverlay* inT);

    void hide();
    void show();

    virtual Puppet* const toPuppet() const;
    virtual Unit* const toUnit() const;

    virtual Entity* getOwner() const;

    void registerAnimationState(AnimID inId, std::string inState, bool doLoop = true);
    void setRunSpeed(float inWorldUnitsPerSecond);

    float animateLive();
    float animateDie();
    float animateIdle();
    float animateWalk();
    float animateRun();
    float animateAttack();
    float animateHit();
    float animateRest();
    float animateGetUp();

    // if override is true, then the given animation will instantly
    // play and override any currently playing one (even mini ones)
    //
    // note: only applies to Mini animations
    float _animate(AnimID inId, bool override = false);

    Ogre::Entity* attachExtension(std::string inMesh, std::string inBone);

    void trackEnemyPuppet();
    void trackEnemyUnit(CUnit* inUnit);

    void setOrientation(Ogre::Quaternion inQuat);
    void resetOrientation();

    void rotateToEnemy();
    void rotateTo(const Ogre::Vector3& inDest);

    static void setAnimFadeSpeed(float inSpeed);
    static float getAnimFadeSpeed();

    static void setRotationFactor(float inFactor);

		protected:

    //~ void setBaseAnimation(AnimID id, bool reset = false);
    //~ void setTopAnimation(AnimID id, bool reset = false);

    //~ AnimID mCurrentAnimID;
    //~ AnimID mLoopAnimID;

    Ogre::Real mTimer;
    //Ogre::AnimationState* mAnims[NUM_ANIMS];    // master animation list

    protected:
      void copyFrom(const CEntity& src);
    private:

    typedef struct {

      AnimID ID;
      Ogre::AnimationState* State;
      bool FadingIn;
      bool FadingOut;

      inline bool isMini() const {
        return (!State->getLoop());
      }

    } Animation;

    Animation *mCurrentAnim;
    Animation *mLoopAnim;

    typedef std::vector<Animation*> anims_t;
    typedef std::map<AnimID, anims_t > anim_map_t;


    void _applyNextAnimation();

    void setupBody();
    void setupAnimations();

    void fadeAnimations(Ogre::Real deltaTime);

		Ogre::SceneNode     *mSceneNode;
    Ogre::Vector3       mScale;
		Ogre::Entity        *mSceneObject;
    MovableTextOverlay  *mText;
    //~ Pixy::Entity        *mOwner;
    Ogre::SceneManager  *mSceneMgr;
    typedef std::vector<Ogre::Entity*> extensions_t;
    extensions_t mExtensions;
    static float mAnimFadeSpeed;
    anim_map_t mAnims;
    std::list<Animation*> mAnimQueue;
    // for rotation
    Ogre::Quaternion mOrientSrc;               // Initial orientation
    Ogre::Quaternion mOrientDest;              // Destination orientation
    Ogre::Real mRotProgress;                   // How far we've interpolated
    static Ogre::Real mRotFactor;                     // Interpolation step
    bool fRotating;

	}; // end of Entity class
} // end of Pixy namespace
#endif
