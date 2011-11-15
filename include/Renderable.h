/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_Renderable_H
#define H_Renderable_H

#include "Pixy.h"
#include <Ogre.h>

namespace Pixy
{
	class Renderable
	{
    public:

		Renderable();
		Renderable& operator=(const Renderable& rhs);
		Renderable(const Renderable& src);
		virtual ~Renderable();

		void attachSceneNode(Ogre::SceneNode* inNode);
		Ogre::SceneNode* getSceneNode() const;

		void attachSceneObject(Ogre::Entity* inObject);
		Ogre::Entity* getSceneObject() const;

    Ogre::Entity* attachExtension(std::string const& inMesh, std::string const& inBone);

		protected:

		Ogre::SceneNode     *mSceneNode;
		Ogre::Entity        *mSceneObject;
    Ogre::SceneManager  *mSceneMgr;
    typedef std::vector<Ogre::Entity*> extensions_t;
    extensions_t mExtensions;

    static int gUID;

	}; // end of Renderable class
} // end of Pixy namespace
#endif
