/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#include "Entity.h"
#include <Ogre.h>
#include "Spell.h"
#include "PixyUtility.h"
#include "GfxEngine.h"
#include "Combat.h"
#include "Puppet.h"
#include "Unit.h"

namespace Pixy
{

  Entity::Entity()
  {
    mSceneNode = 0;
    mSceneObject = 0;
    mText = 0;
    mSceneMgr = 0;
    //mScale = Ogre::Vector3(1,1,1);
  }

  Entity::~Entity()
  {

    for (extensions_t::iterator ext = mExtensions.begin(); ext != mExtensions.end(); ++ext)
    {
      mSceneMgr->destroyEntity((*ext)->getName());
    }
    mExtensions.clear();

    if (mText)
      delete mText;

    if (mSceneNode) {
      mSceneNode->setVisible(true);
      GfxEngine::getSingletonPtr()->detachFromScene(this);
    }

		mSceneNode = 0;
    mSceneObject = 0;

    mText = 0;
  }


  Entity::Entity(const Entity& src)// : Caster(this)
  {
    copyFrom(src);
  }

  Entity& Entity::operator=(const Entity& rhs)
  {
    // check for self-assignment
    if (this == &rhs)
      return (*this);

    copyFrom(rhs);

    return (*this);
  }

  void Entity::copyFrom(const Entity& src)
  {
    BaseEntity::copyFrom(src);
    Caster::copyFrom(src);
  }

  std::ostream& Entity::toStream(std::ostream& inStream)
  {
    inStream
      //~ << this->getName() << "[" << this->getUID() << "," << this->getOwner()->getUID() << "]";
      << mName << "[" << mUID << "," << mOwner->getUID() << "]";

    return inStream;
  }

  bool Entity::live()
  {
    BaseEntity::live();

    fIsDead = false;

    mSceneMgr = GfxEngine::getSingletonPtr()->getSceneMgr();
    GfxEngine::getSingletonPtr()->attachToScene(this);
    Animable::setup(this);

    show();
  }

  void Entity::die()
  {
    BaseEntity::die();

    hide();
    GfxEngine::getSingletonPtr()->detachFromScene(this);

    fIsDead = true;
  }

	void Entity::attachSpell(spell_t* inSpell)
	{
		Caster::attachSpell(inSpell);
    mSpells.back()->setCaster(this);
	}

	void Entity::attachBuff(spell_t* inSpell)
	{
    Caster::attachBuff(inSpell);
    mBuffs.back()->setTarget(this);
	}

  Caster* Entity::toCaster() const {
    return static_cast<Caster*>((Entity*)this);
  }

  void Entity::deserialize(const Event& evt)
  {
    BaseEntity::deserialize(evt);

    updateTextOverlay();
  }


  MovableTextOverlay* Entity::getText() const { return mText; }
  void Entity::setText(MovableTextOverlay* inT) { mText = inT; }

  void Entity::hide() {
    mSceneNode->setVisible(false);
    if (mText)
    {
      mText->hide(true);
      mText->enable(false);
      mText->update(1);
    }
  }

  void Entity::show() {
    mSceneNode->setVisible(true);
    if (mText)
    {
      mText->hide(false);
      mText->enable(true);
      mText->update(1);
    }
  }


  void Entity::trackEnemyUnit(Unit* inUnit) {
    return;
    mSceneNode->setAutoTracking(true, inUnit->getSceneNode());
  }

  /*
  void Entity::setOrientation(Ogre::Quaternion inQuat) {
    mOrientation = inQuat;
    resetOrientation();
  }

  void Entity::resetOrientation() {
    mSceneNode->setOrientation(mOrientation);
  }
  */

} // end of Pixy namespace
