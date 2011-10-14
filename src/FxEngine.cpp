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
#include "GameManager.h"
#include "Renderable.h"
#include "Entity.h"
#include "CPuppet.h"
#include "CUnit.h"
#include "GameState.h"
#include "PixyUtility.h"

namespace Pixy {
	FxEngine* FxEngine::__instance = NULL;
  int FxEngine::gUID = 0;

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
    mLog->infoStream() << "My Listener UID: " << mUID;

    mDeathlist.clear();
    mEffects.clear();
		fSetup = false;
	}

	FxEngine::~FxEngine() {
		if (mLog)
    {
      mLog->infoStream() << "shutting down";
      delete mLog;
      mLog = 0;
    }

		if (fSetup) {
      mFxMgr->destroyAllParticleSystems(mSceneMgr);
      mFxMgr = 0;

			fSetup = false;
		}
	}

	bool FxEngine::cleanup() {
		return true;
	}


	bool FxEngine::setup() {
    mPortableEffects.clear();
    mDeathlist.clear();

		if (fSetup)
			return true;

		mLog->infoStream() << "Setting up";

    //bind(EventUID::EntitySelected, boost::bind(&FxEngine::onEntitySelected, this, _1));
    bind(EventUID::UnitAttacked, boost::bind(&FxEngine::onEntityAttacked, this, _1));
    //~ if (GameManager::getSingleton().getCurrentState()->getId() == STATE_COMBAT)
    //~ {
      //~ bind(EventUID::EntityDying, boost::bind(&FxEngine::onEntityDying, this, _1));
    //~ } else
      //~ unbind(EventUID::EntityDying);

    mSceneMgr = GfxEngine::getSingletonPtr()->getSceneMgr();
    mFxMgr = ParticleUniverse::ParticleSystemManager::getSingletonPtr();

		fSetup = true;
		return true;
	}


	void FxEngine::update( unsigned long lTimeElapsed ) {
		processEvents();
    deathlist_t::iterator node;
    for (node = mDeathlist.begin();
         node != mDeathlist.end();
         ++node) {
      (*node)->detachAllObjects();
      mPortableEffects.remove(*node);
      mSceneMgr->destroySceneNode(*node);
    }
    mDeathlist.clear();
	}

  ParticleUniverse::ParticleSystem* FxEngine::loadEffect(std::string inName) {
    // make sure it's not already registered
    if (mEffects.find(inName) != mEffects.end())
      return mEffects.find(inName)->second;

    ParticleUniverse::ParticleSystem* effect = 0;
    effect =
      mFxMgr->createParticleSystem( inName + "_", inName, mSceneMgr);
    //effect->setRenderQueueGroup(Ogre::RENDER_QUEUE_OVERLAY);
    effect->prepare();

    mEffects.insert(std::make_pair(inName, effect));

    return effect;
  }

  /*void FxEngine::registerHighlightEffect(std::string inName) {
    assert(mEffects.find(inName) != mEffects.end());

    mHighlightEffect = mEffects.find(inName)->second;
  }*/

  ParticleUniverse::ParticleSystem* FxEngine::playEffect(ParticleUniverse::ParticleSystem* inEffect, Renderable* inEntity) {

    if (inEffect->isAttached()) {
      //inEffect->stop();
      inEffect->getParentSceneNode()->detachObject(inEffect);
    }

    //~ inEffect->setUserAny(Ogre::Any(inEntity));
    //~ inEffect->setScale(inEntity->getSceneNode()->getScale());
    inEntity->getSceneNode()->attachObject(inEffect);
    inEffect->start();

    return inEffect;
	};

  ParticleUniverse::ParticleSystem* FxEngine::playEffect(std::string inEffect, Renderable* inEntity, bool newInstance) {
    if (newInstance)
    {
      ParticleUniverse::ParticleSystem* effect
        = mFxMgr->createParticleSystem( inEffect + "_" + stringify(++gUID), inEffect, mSceneMgr);
      return playEffect(effect, inEntity);
    }
    assert(mEffects.find(inEffect) != mEffects.end());

    return playEffect(mEffects.find(inEffect)->second, inEntity);
  }

  ParticleUniverse::ParticleSystem* FxEngine::playEffect(std::string inEffect, Ogre::Vector3 pos, bool newInstance) {
    Ogre::SceneNode* mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    mNode->setPosition(pos);

    ParticleUniverse::ParticleSystem* mEffect = 0;
    if (newInstance)
    {
      mEffect = mFxMgr->createParticleSystem( inEffect + "_" + stringify(++gUID), inEffect, mSceneMgr);
    } else {
      assert(mEffects.find(inEffect) != mEffects.end());
      mEffect = mEffects.find(inEffect)->second;

      if (mEffect->isAttached())
        mEffect->getParentSceneNode()->detachObject(mEffect);
    }

    mNode->attachObject(mEffect);
    mEffect->addParticleSystemListener(this);
    mEffect->start();

    mLog->infoStream() << "created a portable effect node";

    mPortableEffects.push_back(mNode);

    return mEffect;
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

    //mLog->infoStream() << "on entity selected";

    // double click on an entity
    if (mSelected && mSelected->getEntity()->getUID() == lEntity->getUID()) {
      dehighlight();
      return true;
    }

    highlight(lRend);

    return true;
  }

  bool FxEngine::onEntityAttacked(const Event& inEvt) {
    assert(inEvt.Any);

    Renderable* lEntity = static_cast<Renderable*>(inEvt.Any);

    assert(lEntity);

    // if it's a puppet and it died, play the blood spray effect
    if (lEntity->getEntity()->getRank() == PUPPET && lEntity->getEntity()->isDead())
    {
      ParticleUniverse::ParticleSystem* lEffect =
        mEffects.find("Elementum/Fx/BloodSplat")->second;
      //if (!lEffect->isAttached()) {
        playEffect(lEffect, lEntity);
        return true;
      //}
    }

    //mLog->infoStream() << "on entity attacked";

    // try any of the following effects, whichever is not being played
    bool played = false;
    if (mEffects.find("Elementum/Fx/BloodStrike2") != mEffects.end()) {
      ParticleUniverse::ParticleSystem* lEffect =
        mEffects.find("Elementum/Fx/BloodStrike2")->second;
      if (lEffect->getState() != ParticleUniverse::ParticleSystem::PSS_STARTED) {
        playEffect(lEffect, lEntity);
        played = true;
      }
    }

    if (played)
      return true;

    if (mEffects.find("Elementum/Fx/BloodStrike3") != mEffects.end()) {
      ParticleUniverse::ParticleSystem* lEffect =
        mEffects.find("Elementum/Fx/BloodStrike3")->second;
      if (lEffect->getState() != ParticleUniverse::ParticleSystem::PSS_STARTED) {
        playEffect(lEffect, lEntity);
        played = true;
      }
    }

    /*if (played)
      return true;

    if (mEffects.find("Elementum/Fx/BloodSpray") != mEffects.end()) {
      ParticleUniverse::ParticleSystem* lEffect =
        mEffects.find("Elementum/Fx/BloodSpray")->second;
      if (lEffect->getState() != ParticleUniverse::ParticleSystem::PSS_STARTED) {
        playEffect(lEffect, lEntity);
        played = true;
      }
    }*/

    return true;
  }


  void FxEngine::handleParticleSystemEvent(
    ParticleUniverse::ParticleSystem* inSystem,
    ParticleUniverse::ParticleUniverseEvent& inEvt)
  {
    using namespace ParticleUniverse;

    //~ mLog->debugStream() << "got a PU event: " << (int)inEvt.eventType;
    switch(inEvt.eventType)
    {
      case PU_EVT_SYSTEM_STOPPED:
        // if the system is attached to a portable effect node, we need to destroy it
        portable_effects_t::iterator node;
        for (node = mPortableEffects.begin();
             node != mPortableEffects.end();
             ++node) {
          try {
            if ((*node)->getAttachedObject(inSystem->getName())) {
              //node->detachObject(inSystem);
              inSystem->removeParticleSystemListener(this);
              mDeathlist.push_back(*node);
              //mPortableEffects.remove(*node);

              mLog->infoStream() << "destroyed a portable effect node";
              break;
            }
          } catch (Ogre::Exception& e) {
          }
        }
      break;
    }
  }

  //~ void FxEngine::onEntityDying(Renderable* inUnit) {
  bool FxEngine::onEntityDying(const Event& evt) {
    Renderable *inUnit = static_cast<Renderable*>(evt.Any);
    assert(mEffects.find("Elementum/Fx/Desummon") != mEffects.end());

    playEffect("Elementum/Fx/Desummon", inUnit->getSceneNode()->getPosition());

    return true;
  }

  void FxEngine::unloadAllEffects() {
    //~ dehighlight();
    mEffects.clear();
    mDeathlist.clear();
    mFxMgr->destroyAllParticleSystems(mSceneMgr);
    mHighlightEffect = 0;
  }

}
