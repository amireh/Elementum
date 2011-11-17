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
  #include "FxEngine.h"
%}

namespace Ogre {
  class Vector3;
  class SceneManager;
  class SceneNode;
}

namespace Pixy {

  %nodefaultctor FxEngine;

  class Entity;
	class FxEngine {

	public:

		static FxEngine& getSingleton();
    static FxEngine* getSingletonPtr();

    ParticleUniverse::ParticleSystem* loadEffect(std::string inName);
    ParticleUniverse::ParticleSystem* playEffect(std::string inEffect, Entity* inEntity, bool newInstance = false);
    ParticleUniverse::ParticleSystem* playEffect(ParticleUniverse::ParticleSystem*, Entity* inEntity);
    ParticleUniverse::ParticleSystem* playEffect(std::string inEffect, const Ogre::Vector3 pos, bool newInstance = false);

    void unloadAllEffects();
	};
}
