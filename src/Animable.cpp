#include "Animable.h"
#include "Renderable.h"

namespace Pixy {
  float Animable::mAnimeFadeSpeed = 7.5f;

  Animable::Animable()
  : mRenderable(0),
    mCurrentAnim(0),
    mLoopAnim(0)
  {
  }

  Animable::~Animable()
  {
    for (anim_map_t::iterator itr = mAnims.begin();
      itr != mAnims.end();
      ++itr)
    {
      for (anims_t::iterator anim = itr->second.begin();
        anim != itr->second.end();
        ++anim)
        delete *anim;

      itr->second.clear();
    }
    mAnims.clear();
    mAnimQueue.clear();

    mRenderable = 0;
    mCurrentAnim = 0;
    mLoopAnim = 0;
  }

  Animable::Animable(const Animable& src)
  {
    mLoopAnim = 0;
    mCurrentAnim = 0;
    mRenderable = src.mRenderable;
  }

  Animable& Animable::operator=(const Animable& rhs)
  {
    if (&rhs == this)
      return *this;

    mLoopAnim = 0;
    mCurrentAnim = 0;
    mRenderable = rhs.mRenderable;
    return *this;
  }

  void Animable::setup(Renderable* inRnd)
  {
    mRenderable = inRnd;

    setupAnimations();
  }

	void Animable::setupAnimations()
	{

    using namespace Ogre;

		// this is very important due to the nature of the exported animations
		mRenderable->getSceneObject()->getSkeleton()->setBlendMode(ANIMBLEND_CUMULATIVE);

    for (anim_map_t::iterator itr = mAnims.begin();
      itr != mAnims.end();
      ++itr)
    {
      for (anims_t::iterator anim = itr->second.begin();
        anim != itr->second.end();
        ++anim)
      {
        (*anim)->FadingIn = false;
        (*anim)->FadingOut = false;
      }
    }

    //mCurrentAnimID = ANIM_NONE;

    return;
	}

  void Animable::setAnimFadeSpeed(float inSpeed) {
    mAnimeFadeSpeed = inSpeed;
  }
  float Animable::getAnimFadeSpeed() {
    return mAnimeFadeSpeed;
  }

	void Animable::fadeAnimations(Ogre::Real deltaTime)
	{
    using namespace Ogre;

    for (anim_map_t::iterator itr = mAnims.begin();
      itr != mAnims.end();
      ++itr)
    {
      for (anims_t::iterator anim = itr->second.begin();
        anim != itr->second.end();
        ++anim)
      {
        if ((*anim)->FadingIn)
        {
          // slowly fade this animation in until it has full weight
          Ogre::Real newWeight = (*anim)->State->getWeight() + deltaTime * mAnimeFadeSpeed;
          (*anim)->State->setWeight(Math::Clamp<Real>(newWeight, 0, 1));
          if (newWeight >= 1)
            (*anim)->FadingIn = false;
        }
        else if ((*anim)->FadingOut)
        {
          // slowly fade this animation out until it has no weight, and then disable it
          Real newWeight = (*anim)->State->getWeight() - deltaTime * mAnimeFadeSpeed;
          (*anim)->State->setWeight(Math::Clamp<Real>(newWeight, 0, 1));
          if (newWeight <= 0)
          {
            (*anim)->State->setEnabled(false);
            (*anim)->FadingOut = false;
          }
        }
      }
		}
	}

  void Animable::step(unsigned long dt) {
    //~ return;

		Ogre::Real baseAnimSpeed = 1;
		Ogre::Real topAnimSpeed = 1;
    Ogre::Real deltaTime = dt * 0.001f;

		mAnimeTimer += deltaTime;

		// increment the current animation times
		if (mCurrentAnim) {
      mCurrentAnim->State->addTime(deltaTime * baseAnimSpeed);
      if (mCurrentAnim->State->hasEnded()) {

        if (mCurrentAnim->isMini())
          mAnimQueue.pop_front();

        _applyNextAnimation();
      }
    }
    //animateIdle();

		// apply smooth transitioning between our animations
		fadeAnimations(deltaTime);
  }


  void  Animable::registerAnimationState(AnimID inId, std::string inState, bool loop) {
    //~ assert(!mAnims[inId]);
    assert(inId != ANIM_NONE);
    //assert(mAnims.find(inId) != mAnims.end());
    if (mAnims.find(inId) == mAnims.end())
      mAnims.insert( std::make_pair(inId, anims_t()) );

    Animation* _anim = new Animation();
    _anim->ID = inId;
    _anim->FadingIn = false;
    _anim->FadingOut = false;
    _anim->State = mRenderable->getSceneObject()->getAnimationState(inState);
    _anim->State->setLoop(loop);

    mAnims[inId].push_back(_anim);
    _anim = 0;
  }

  float Animable::animateLive() {
    return this->_animate(ANIM_LIVE, true);
  }
  float Animable::animateDie() {
    return this->_animate(ANIM_DIE, true);
  }
  float Animable::animateIdle() {
    return this->_animate(ANIM_IDLE);
  }
  float Animable::animateWalk() {
    return this->_animate(ANIM_WALK);
  }
  float Animable::animateRun() {
    return this->_animate(ANIM_RUN);
  }
  float Animable::animateAttack() {
    return this->_animate(ANIM_ATTACK);
  }
  float Animable::animateHit() {
    return this->_animate(ANIM_HIT, true);
  }
  float Animable::animateRest() {
    return this->_animate(ANIM_REST);
  }
  float Animable::animateGetUp() {
    return this->_animate(ANIM_GETUP);
  }
  float Animable::_animate(AnimID id, bool override) {
    if (mAnims.find(id) == mAnims.end() || mAnims[id].empty()) {
      std::cerr << "ERROR! Asked to play a non-existing animation: " << id << ", gracefully rejecting\n";
      return 0;
    }

    Animation* _anim = mAnims[id].at(rand() % mAnims[id].size());

    // first animation must be a looping one
    if (!mCurrentAnim)
      if (!_anim->isMini()) {
        //mLoopAnimID = id;
        mLoopAnim = _anim;
        _applyNextAnimation();
      } else
        throw std::runtime_error("must have a base loop animation first!");

    // replacing the loop anim
    else if (!_anim->isMini()) {
      assert(mLoopAnim);
      //mLoopAnimID = id;
      mLoopAnim = _anim;
      // if there are no mini-anims running, apply the new loop anim
      if (mAnimQueue.empty())
        _applyNextAnimation();
    }

    // it's a mini-anim
    else if (_anim->isMini()) {
      if (override)
        mAnimQueue.push_front(_anim);
      else
        mAnimQueue.push_back(_anim);

      // if there are no mini-anims running, apply this one immediately
      if (mAnimQueue.size() == 1 || override)
        _applyNextAnimation();
    } else
      throw std::runtime_error("can't be here!");

    return _anim->State->getLength();
  }

  void Animable::_applyNextAnimation() {
    Animation* _nextAnim = 0;

    // if there are pending mini-anims, play them
    if (!mAnimQueue.empty()) {
      _nextAnim = mAnimQueue.front();
      //std::cout << "Playing a mini-animation " << _nextAnim->ID << " (" << mAnimQueue.size() << " in queue)\n";
    } else { // otherwise we play the loop animation
      _nextAnim = mLoopAnim;
      //std::cout << "Playing loop animation " << mLoopAnim->ID << "\n";
    }

    assert(_nextAnim);

		if (mCurrentAnim)
		{
			// if we have an old animation, fade it out
      mCurrentAnim->FadingIn = false;
      mCurrentAnim->FadingOut = true;
		}

		//mCurrentAnimID = _nextAnimID;
    mCurrentAnim = _nextAnim;

    // we have a new animation, reset, enable, and fade it in
    _nextAnim->State->setEnabled(true);
    _nextAnim->State->setWeight(0);
    _nextAnim->State->setTimePosition(0);
    _nextAnim->FadingOut = false;
    _nextAnim->FadingIn = true;

  }
}
