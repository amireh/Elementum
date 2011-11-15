/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

// Renderable.cpp
#include "Renderable.h"
#include "PixyUtility.h"
#include "GfxEngine.h"

namespace Pixy
{

  int Renderable::gUID = 0;

	Renderable::Renderable()
  : mSceneNode(0),
    mSceneObject(0),
    mSceneMgr(GfxEngine::getSingletonPtr()->getSceneMgr())
	{
	}

  Renderable::~Renderable() {

    for (extensions_t::iterator ext = mExtensions.begin(); ext != mExtensions.end(); ++ext)
    {
      mSceneMgr->destroyEntity((*ext)->getName());
    }
    mExtensions.clear();

		mSceneNode = 0;
    mSceneObject = 0;
    mSceneMgr = 0;
	}

	void Renderable::attachSceneNode(Ogre::SceneNode* inNode)
  {
    mSceneNode = inNode;
  }

  void Renderable::attachSceneObject(Ogre::Entity* inObject)
  {
    mSceneObject = inObject;
    if (mSceneObject)
      mSceneObject->setUserAny(Ogre::Any(this));
  }

  Ogre::Entity* Renderable::attachExtension(std::string const& inMesh, std::string const& inBone)
  {
    Ogre::Entity* tmp =
      mSceneMgr->createEntity(stringify(++gUID) + "extension" + stringify(mExtensions.size()), inMesh);

    mSceneObject->attachObjectToBone(inBone, tmp);
    mExtensions.push_back(tmp);

    return tmp;
  }

  Ogre::SceneNode* Renderable::getSceneNode() const
  {
    return mSceneNode;
  }

  Ogre::Entity* Renderable::getSceneObject() const
  {
    return mSceneObject;
  }

} // end of namespace
