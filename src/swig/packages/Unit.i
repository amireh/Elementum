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
  #include "Unit.h"
%}

%import(module="Pixy") "BaseUnit.i"

namespace Pixy
{
  class Puppet;
  class Unit : public Entity, public BaseUnit, public Mobile
  {
    public:

    Unit();
    Unit(const Unit& src);
    Unit& operator=(const Unit& rhs);
    virtual ~Unit();

    virtual bool live();
    virtual void die();

    virtual bool attack(Puppet* inTarget);
    virtual bool attack(Unit* inTarget, bool doBlock = false);

    virtual Puppet* getOwner() const;


    int getAttackOrder() const;
    void setAttackOrder(int);

    Unit* getBlockTarget() const;
    void setBlockTarget(Unit* const);
    Entity* getAttackTarget() const;
    void setAttackTarget(Entity* const);

    virtual void setAP(int inU);
    virtual void setHP(int inU);

    virtual void updateTextOverlay();
    virtual void reset();
    virtual void rest();
    virtual void getUp();

    bool isDying() const;
  }; // end of class Unit
} // end of Pixy namespace
