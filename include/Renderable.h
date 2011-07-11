/* -----------------------------------------------
 *  Filename: Entity.h
 *  Date Created: ??/2009
 *
 *  Original Author:
 *      Ahmad Amireh ( ahmad.amireh@gmail.com )
 *
 *  Last Update:
 *      Date:   20/4/2009
 *      By:     Ahmad Amireh
 * ----------------------------------------------- */

#ifndef H_Renderable_H
#define H_Renderable_H

#include "Pixy.h"
#include <Ogre.h>

#define NUM_ANIMS 13           // number of animations the character has
#define CHAR_HEIGHT 5          // height of character's center of mass above ground
#define ANIM_FADE_SPEED 7.5f   // animation crossfade speed in % of full weight per second

/*namespace Ogre {
  class SceneNode;
  class MovableObject;
  class Entity;
  class RibbonTrail;
  class AnimationState;
}*/

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
	class Renderable
	{

    private:

    public:
		Renderable(Entity* inOwner);
		Renderable& operator=(const Renderable& rhs) = delete;
		Renderable(const Renderable& src) = delete;
		virtual ~Renderable();

		virtual void attachSceneNode(Ogre::SceneNode* inNode);
		virtual Ogre::SceneNode* getSceneNode();

		virtual void attachSceneObject(Ogre::Entity* inObject);
		virtual Ogre::Entity* getSceneObject();

    void setup(Ogre::SceneManager*);
    void updateAnimations(unsigned long deltaTime);

    virtual Entity* getEntity();

    MovableTextOverlay* getText() const;
    void setText(MovableTextOverlay* inT);

    void hide();
    void show();

		protected:

    friend class CPuppet;
    friend class CUnit;

    // all the animations our character has, and a null ID
    // some of these affect separate body parts and will be blended together
    enum AnimID
    {
      ANIM_IDLE_BASE,
      ANIM_IDLE_TOP,
      ANIM_RUN_BASE,
      ANIM_RUN_TOP,
      ANIM_HANDS_CLOSED,
      ANIM_HANDS_RELAXED,
      ANIM_DRAW_SWORDS,
      ANIM_SLICE_VERTICAL,
      ANIM_SLICE_HORIZONTAL,
      ANIM_DANCE,
      ANIM_JUMP_START,
      ANIM_JUMP_LOOP,
      ANIM_JUMP_END,
      ANIM_NONE
    };

    void setOwner(Pixy::Entity* inOwner) {
      mOwner = inOwner;
    }

    void setBaseAnimation(AnimID id, bool reset = false);
    void setTopAnimation(AnimID id, bool reset = false);

    AnimID mBaseAnimID;                   // current base (full- or lower-body) animation
    AnimID mTopAnimID;                    // current top (upper-body) animation
    Ogre::Real mTimer;
    Ogre::AnimationState* mAnims[NUM_ANIMS];    // master animation list

    private:

    void setupBody();
    void setupAnimations();

    void fadeAnimations(Ogre::Real deltaTime);

		Ogre::SceneNode     *mSceneNode;
		Ogre::Entity *mSceneObject;
    MovableTextOverlay  *mText;
    Pixy::Entity        *mOwner;
    Ogre::SceneManager  *mSceneMgr;

    Ogre::Real mPivotPitch;
    //Ogre::Entity* mBodyEnt;
    Ogre::Entity* mSword1;
    Ogre::Entity* mSword2;
    Ogre::RibbonTrail* mSwordTrail;
    bool mFadingIn[NUM_ANIMS];            // which animations are fading in
    bool mFadingOut[NUM_ANIMS];           // which animations are fading out
    bool mSwordsDrawn;
    Ogre::Real mVerticalVelocity;     // for jumping


		//! helper method for copy/assignment methods
		//! copies all data from src and sets it into this entity
		//~ virtual void copyFrom(const Renderable& src);

	}; // end of Entity class
} // end of Pixy namespace
#endif
