/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_Animable_H
#define H_Animable_H

#include "Pixy.h"
#include <Ogre.h>

namespace Pixy
{
  class Renderable;
	class Animable
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

		Animable();
		Animable& operator=(const Animable& rhs);
		Animable(const Animable& src);
		virtual ~Animable();


    void registerAnimationState(AnimID inId, std::string inState, bool doLoop = true);

    void stepAnime(unsigned long deltaTime);

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

    static void setAnimFadeSpeed(float inSpeed);
    static float getAnimFadeSpeed();

		protected:

    /**
     * @brief
     * Registers the given SceneNode and Ogre Entity to be used for animating and
     * prepares the animable object.
     *
     * @warning
     * This function MUST be called before any usage of the Animable instance.
     **/
    void setup(Renderable*);

    private:

    static float mAnimeFadeSpeed;
    Ogre::Real mAnimeTimer;
    Renderable *mRenderable;

    /**
     * @struct Animation clips interface
     *
     *
     **/
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
    anim_map_t mAnims;

    std::list<Animation*> mAnimQueue;

    void _applyNextAnimation();

    void setupBody();
    void setupAnimations();
    void fadeAnimations(Ogre::Real deltaTime);

	}; // end of Animable class
} // end of Pixy namespace
#endif
