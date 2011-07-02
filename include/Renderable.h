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
namespace Pixy
{
  class Entity;
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
		Renderable& operator=(const Renderable& rhs);
		Renderable(const Renderable& src);
		virtual ~Renderable();

		virtual void attachSceneNode(Ogre::SceneNode* inNode);
		virtual Ogre::SceneNode* getSceneNode();

		virtual void attachSceneObject(Ogre::MovableObject* inObject);
		virtual Ogre::MovableObject* getSceneObject();

    virtual Entity* getEntity();

		protected:

		Ogre::SceneNode         *mSceneNode;
		Ogre::MovableObject     *mSceneObject;
    Pixy::Entity* mOwner;

		//! helper method for copy/assignment methods
		//! copies all data from src and sets it into this entity
		virtual void copyFrom(const Renderable& src);

	}; // end of Entity class
} // end of Pixy namespace
#endif
