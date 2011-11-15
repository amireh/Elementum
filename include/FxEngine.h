/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_FxEngine_H
#define H_FxEngine_H

#include "Engine.h"
#include "EventListener.h"
#include <Ogre.h>
#include "ParticleUniverseCommon.h"
#include "ParticleUniverseSystem.h"
#include "ParticleUniverseSystemManager.h"
#include "ParticleUniverseSystemListener.h"

/*namespace ParticleUniverse {
  class ParticleSystemManager;
  class ParticleSystem;
}*/
namespace Ogre {
  class Vector3;
  class SceneManager;
  class SceneNode;
}

namespace Pixy {

  struct Event;
  class Renderable;
  class GfxEngine;
	class FxEngine : public ParticleUniverse::ParticleSystemListener, public Engine, public EventListener {

	public:
		virtual ~FxEngine();
		static FxEngine& getSingleton();
    static FxEngine* getSingletonPtr();

		virtual bool setup();
		virtual void update(unsigned long lTimeElapsed);
		virtual bool cleanup();

    ParticleUniverse::ParticleSystem* loadEffect(std::string inName);
    ParticleUniverse::ParticleSystem* playEffect(std::string inEffect, Renderable* inEntity, bool newInstance = false);
    ParticleUniverse::ParticleSystem* playEffect(ParticleUniverse::ParticleSystem*, Renderable* inEntity);
    ParticleUniverse::ParticleSystem* playEffect(std::string inEffect, const Ogre::Vector3 pos, bool newInstance = false);

    //~ void registerHighlightEffect(std::string inName);

    virtual void
    handleParticleSystemEvent(
      ParticleUniverse::ParticleSystem*,
      ParticleUniverse::ParticleUniverseEvent&);

    //~ void onEntityDying(Renderable* inUnit);

    void unloadAllEffects();

	protected:
    friend class GfxEngine;

    bool onEntityAttacked(const Event& inEvt);

	private:

    Ogre::SceneManager *mSceneMgr;
    ParticleUniverse::ParticleSystemManager* mFxMgr;
    ParticleUniverse::ParticleSystem* mHighlightEffect;

    typedef std::map< std::string, ParticleUniverse::ParticleSystem* > effects_t;
    typedef std::list<Ogre::SceneNode*> deathlist_t;
    typedef deathlist_t portable_effects_t;

    effects_t mEffects;

    portable_effects_t mPortableEffects;
    deathlist_t mDeathlist;

		static FxEngine* __instance;
		FxEngine();
		FxEngine(const FxEngine& src);
		FxEngine& operator=(const FxEngine& rhs);

    static int gUID;
	};
}
#endif
