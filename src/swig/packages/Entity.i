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
  #include "Entity.h"
%}

%import(module="Pixy") "BaseEntity.i"
%import(module="Pixy") "Caster.i"
%import(module="Pixy") "Animable.i"
%import(module="Pixy") "Renderable.i"

namespace Pixy
{
  //%nodefaultctor Entity;

  class Unit;
  class Entity : public BaseEntity, public Caster, public Animable, public Renderable
  {
    public:

    Entity();
    Entity(const Entity& src);
    Entity& operator=(const Entity& rhs);
    virtual ~Entity();

    virtual void setup(Ogre::SceneManager*);

    virtual bool live();
		virtual void die();

		virtual void attachSpell(Pixy::BaseSpell* inSpell);
		virtual void attachBuff(Pixy::BaseSpell* inSpell);

    MovableTextOverlay* getText() const;
    void setText(MovableTextOverlay* inT);
    virtual void updateTextOverlay()=0;

    void hide();
    void show();

    //void trackEnemyPuppet();
    void trackEnemyUnit(Unit* inUnit);
    virtual void setHP(int);

  }; // end of class Entity
} // end of Pixy namespace
