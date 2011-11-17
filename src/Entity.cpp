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
  : mText(0)
  {
  }

  Entity::~Entity()
  {

    if (mText)
      delete mText;

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

    mText = src.mText;
  }

  std::ostream& Entity::toStream(std::ostream& inStream) const
  {
    inStream
      //~ << this->getName() << "[" << this->getUID() << "," << this->getOwner()->getUID() << "]";
      << "\"" << mName << "[" << mUID << "," << mOwner->getUID() << "]" << "\"";

    return inStream;
  }

  void Entity::setup(Ogre::SceneManager* inSceneMgr)
  {
    mSceneMgr = inSceneMgr;
    assert(mSceneNode && mSceneObject);
    Animable::setup(this);
    show();
  }

  bool Entity::live()
  {
    fIsDead = false;

    //GfxEngine::getSingletonPtr()->attachToScene(this);
  }

  void Entity::die()
  {
    if (mSceneNode && mSceneObject)
    {
      hide();
      GfxEngine::getSingletonPtr()->detachFromScene(this);
    }

    fIsDead = true;
  }

	void Entity::attachSpell(BaseSpell* inSpell)
	{
		Caster::attachSpell(inSpell);
    mSpells.back()->setCaster(this);
	}

	void Entity::attachBuff(BaseSpell* inSpell)
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
    if (!mSceneNode || !mText)
      return;

    mSceneNode->setVisible(false);
    if (mText)
    {
      mText->hide(true);
      mText->enable(false);
      mText->update(1);
    }
  }

  void Entity::show() {
    if (!mSceneNode || !mText)
      return;

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

  void Entity::setHP(int inHP)
  {
    BaseEntity::setHP(inHP);
    updateTextOverlay();

  }
} // end of Pixy namespace
