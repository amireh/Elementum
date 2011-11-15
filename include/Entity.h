/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_ElementumEntity_H
#define H_ElementumEntity_H

#include "BaseEntity.h"
#include "Caster.h"
#include "Animable.h"
#include "Renderable.h"
#include "ogre/MovableTextOverlay.h"

namespace Pixy
{
  class Unit;
  class Entity : public BaseEntity, public Caster, public Animable, public Renderable
  {
    public:

    Entity();
    Entity(const Entity& src);
    Entity& operator=(const Entity& rhs);
    virtual ~Entity();

    void setup(Ogre::SceneManager*);

    virtual bool live();
		virtual void die();

    /**
     * Overridden from Pixy::Caster
     **/
		virtual void attachSpell(spell_t* inSpell);
		virtual void attachBuff(spell_t* inSpell);

		virtual Caster* toCaster() const;

    /**
     * Overridden from Pixy::BaseEntity
     **/
    virtual void deserialize(const Event& evt);

    MovableTextOverlay* getText() const;
    void setText(MovableTextOverlay* inT);
    virtual void updateTextOverlay()=0;

    void hide();
    void show();

    void trackEnemyPuppet();
    void trackEnemyUnit(Unit* inUnit);

    void stepBody(unsigned long dt);

    protected:

    void copyFrom(const Entity& src);
    virtual std::ostream& toStream(std::ostream& inStream);

    private:

		//~ Ogre::SceneNode     *mSceneNode;
    Ogre::Vector3       mScale;
		//~ Ogre::Entity        *mSceneObject;
    MovableTextOverlay  *mText;
    //~ Ogre::SceneManager  *mSceneMgr;
    typedef std::vector<Ogre::Entity*> extensions_t;
    extensions_t mExtensions;

  }; // end of class Entity
} // end of Pixy namespace

#endif // P_Entity_H
