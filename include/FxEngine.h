#ifndef H_FxEngine_H
#define H_FxEngine_H

#include "Engine.h"
#include "EventListener.h"

namespace ParticleUniverse {
  class ParticleSystemManager;
  class ParticleSystem;
}
namespace Ogre {
  class Vector3;
  class SceneManager;
}

namespace Pixy {

  class Event;
  class Renderable;
  class GfxEngine;
	class FxEngine : public Engine, public EventListener {

	public:
		virtual ~FxEngine();
		static FxEngine& getSingleton();
    static FxEngine* getSingletonPtr();

		virtual bool setup();
		virtual void update(unsigned long lTimeElapsed);
		virtual bool cleanup();

    void loadEffect(std::string inName);
    void playEffect(std::string inEffect, Renderable* inEntity);
    void playEffect(ParticleUniverse::ParticleSystem*, Renderable* inEntity);
    void playEffect(std::string inEffect, const Ogre::Vector3& pos);

    void registerHighlightEffect(std::string inName);

	protected:
    friend class GfxEngine;

    bool onEntitySelected(const Event& inEvt);
    bool onEntityAttacked(const Event& inEvt);

    void highlight(Renderable*);
    void dehighlight();

	private:

    Ogre::SceneManager *mSceneMgr;
    ParticleUniverse::ParticleSystemManager* mFxMgr;
    ParticleUniverse::ParticleSystem* mHighlightEffect;

    typedef std::map< std::string, ParticleUniverse::ParticleSystem* > effects_t;
    effects_t mEffects;

    Renderable* mSelected;

		static FxEngine* __instance;
		FxEngine();
		FxEngine(const FxEngine& src) = delete;
		FxEngine& operator=(const FxEngine& rhs) = delete;
	};
}
#endif
