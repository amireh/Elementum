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
  #include "Caster.h"
  #include "BaseCaster.h"
  #include "Spell.h"
  #include <list>
%}

%import(module="Pixy") "BaseCaster.i"

namespace Pixy
{

	class Caster : public BaseCaster
	{
	public:
    typedef Spell spell_t;
    typedef std::list<spell_t*> spells_t;

		//~ Caster(BaseEntity*);
		Caster();
		Caster& operator=(const Caster& rhs);
		Caster(const Caster& src);
		virtual ~Caster();


		virtual void attachSpell(Pixy::BaseSpell* inSpell);
		virtual void attachBuff(Pixy::BaseSpell* inSpell);

		virtual void detachSpell(int inUID, bool remove=true);
		virtual void detachBuff(int inUID, bool remove=true);

    virtual spell_t* getSpell(int inUID);
    virtual spell_t* getBuff(int inUID);

		spells_t const& getSpells();
		spells_t const& getBuffs();

		virtual int nrSpells();
		virtual int nrBuffs();

    virtual bool hasBuff(int inUID);
    virtual bool hasBuffWithName(std::string const&);

	}; // end of Caster class
} // end of Pixy namespace
