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

namespace Ogre {
  class SceneNode;
  class MovableObject;
}

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

	public:
		/*! Default ctor.
		 *!  Initializes all attributes with default settings.
		 */
		Renderable(Entity* inOwner);
		Renderable& operator=(const Renderable& rhs) = delete;
		Renderable(const Renderable& src) = delete;
		virtual ~Renderable();

		virtual void attachSceneNode(Ogre::SceneNode* inNode);
		virtual Ogre::SceneNode* getSceneNode();

		virtual void attachSceneObject(Ogre::MovableObject* inObject);
		virtual Ogre::MovableObject* getSceneObject();

    virtual Entity* getEntity();

    MovableTextOverlay* getText() const;
    void setText(MovableTextOverlay* inT);

		protected:
      friend class CPuppet;
      friend class CUnit;

      void setOwner(Pixy::Entity* inOwner) {
        mOwner = inOwner;
      }

		Ogre::SceneNode         *mSceneNode;
		Ogre::MovableObject     *mSceneObject;
    MovableTextOverlay       *mText;
    Pixy::Entity* mOwner;

		//! helper method for copy/assignment methods
		//! copies all data from src and sets it into this entity
		//~ virtual void copyFrom(const Renderable& src);

	}; // end of Entity class
} // end of Pixy namespace
#endif
