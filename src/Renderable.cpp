// Renderable.cpp
#include "Renderable.h"
#include "PixyUtility.h"
#include "Entity.h"
#include <Ogre.h>
#include <cstring>

namespace Pixy
{

	Renderable::Renderable(Pixy::Entity* inOwner)
	{
    mOwner = inOwner;
	};

  Renderable::~Renderable() {
    mOwner = 0;

		mSceneNode = 0;
    mSceneObject = 0;
	};

  Renderable::Renderable(const Renderable& src)
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
  };

	void Renderable::attachSceneNode(Ogre::SceneNode* inNode) { mSceneNode = inNode; }
  void Renderable::attachSceneObject(Ogre::MovableObject* inObject) { mSceneObject = inObject; }
  Ogre::SceneNode* Renderable::getSceneNode() { return mSceneNode; }
  Ogre::MovableObject* Renderable::getSceneObject() { return mSceneObject; }

  Entity* Renderable::getEntity() { return mOwner; }
} // end of namespace
