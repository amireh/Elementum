/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

%module Pixy
%{
  #include "Animable.h"
  #include <Ogre.h>
%}

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

    float animateLive();
    float animateDie();
    float animateIdle();
    float animateWalk();
    float animateRun();
    float animateAttack();
    float animateHit();
    float animateRest();
    float animateGetUp();

    static void setAnimFadeSpeed(float inSpeed);
    static float getAnimFadeSpeed();

	}; // end of Animable class
} // end of Pixy namespace
