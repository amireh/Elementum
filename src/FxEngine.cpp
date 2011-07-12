/*
 *  FxEngine.cpp
 *  Elementum
 *
 *  Created by Ahmad Amireh on 2/11/10.
 *  Copyright 2010 JU. All rights reserved.
 *
 */

#include "FxEngine.h"
#include "ParticleUniverseSystemManager.h"
#include "GfxEngine.h"
#include "Renderable.h"
#include "Entity.h"

namespace Pixy {
	FxEngine* FxEngine::__instance = NULL;

	FxEngine* FxEngine::getSingletonPtr() {
		if( !__instance ) {
		    __instance = new FxEngine();
		}

		return __instance;
	}

  FxEngine& FxEngine::getSingleton() {
    return *FxEngine::getSingletonPtr();
  }

	FxEngine::FxEngine()
  : mHighlightEffect(0),
    mSelected(0)
  {
		mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, "FxEngine");
		mLog->infoStream() << "firing up";
		fSetup = false;
	}

	FxEngine::~FxEngine() {
		mLog->infoStream() << "shutting down";

		if (fSetup) {
      mFxMgr->destroyAllParticleSystems(mSceneMgr);
      mFxMgr = 0;

			delete mLog; mLog = 0;
			fSetup = false;
		}
	}

	bool FxEngine::cleanup() {
		return true;
	}


	bool FxEngine::setup() {
		if (fSetup)
			return true;

		mLog->infoStream() << "Setting up";

    bind(EventUID::EntitySelected, boost::bind(&FxEngine::onEntitySelected, this, _1));

    mSceneMgr = GfxEngine::getSingletonPtr()->getSceneMgr();
    mFxMgr = ParticleUniverse::ParticleSystemManager::getSingletonPtr();

		fSetup = true;
		return true;
	}


	void FxEngine::update( unsigned long lTimeElapsed ) {
		processEvents();
	}

  void FxEngine::loadEffect(std::string inName) {
    // make sure it's not already registered
    if (mEffects.find(inName) != mEffects.end())
      return;

    ParticleUniverse::ParticleSystem* effect = 0;
    effect =
      mFxMgr->createParticleSystem( inName + "_", inName, mSceneMgr);
    effect->prepare();
    mEffects.insert(std::make_pair(inName, effect));

    effect = 0;
  }

  void FxEngine::registerHighlightEffect(std::string inName) {
    assert(mEffects.find(inName) != mEffects.end());

    mHighlightEffect = mEffects.find(inName)->second;
  }

  void FxEngine::playEffect(ParticleUniverse::ParticleSystem* inEffect, Renderable* inEntity) {
    if (inEffect->isAttached())
      inEffect->getParentSceneNode()->detachObject(inEffect);

    inEffect->setUserAny(Ogre::Any(inEntity));
    inEntity->getSceneNode()->attachObject(inEffect);
    inEffect->start();
	};

  void FxEngine::playEffect(std::string inEffect, Renderable* inEntity) {
    assert(mEffects.find(inEffect) != mEffects.end());

    playEffect(mEffects.find(inEffect)->second, inEntity);
  }

  void FxEngine::highlight(Renderable* inEntity) {
    assert(mHighlightEffect);

    mLog->infoStream() << "highlighting mob";
    dehighlight();

    mSelected = inEntity;
    playEffect(mHighlightEffect, mSelected);
  }
  void FxEngine::dehighlight() {
    assert(mHighlightEffect);

    if (mHighlightEffect->isAttached())
      mHighlightEffect->getParentSceneNode()->detachObject(mHighlightEffect);

    mHighlightEffect->stop();

    mSelected = 0;
  }

  bool FxEngine::onEntitySelected(const Event& inEvt) {
    Pixy::Renderable* lRend = static_cast<Pixy::Renderable*>(inEvt.Any);
    Pixy::Entity* lEntity = lRend->getEntity();

    mLog->infoStream() << "on entity selected";

    // double click on an entity
    if (mSelected && mSelected->getEntity()->getUID() == lEntity->getUID()) {
      dehighlight();
      return true;
    }

    highlight(lRend);

    return true;
  }
}
