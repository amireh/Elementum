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
  #include "Puppet.h"
  #include "BasePuppet.h"
  #include "Entity.h"
%}

%import(module="Pixy") "BasePuppet.i"

namespace Pixy
{

	class Puppet : public Entity, public BasePuppet
	{
  public:
    typedef Unit unit_t;
    typedef Deck deck_t;
    typedef std::list<deck_t*> decks_t;
    typedef std::list<unit_t*> units_t;

		Puppet();
		virtual ~Puppet();

    virtual bool live();

    virtual void attachDeck(BaseDeck* inDeck);
    virtual void detachDeck(std::string const& inName);
		virtual void _setDeck(BaseDeck* inDeck);
		virtual deck_t* getDeck();
    virtual decks_t const& getDecks() const;
    virtual bool hasDeck(std::string const& inName) const;
    virtual int nrDecks() const;

		virtual void attachUnit(unit_t* inUnit);
		virtual void detachUnit(int inUID, bool inRemove = true);
		virtual unit_t* getUnit(int inUID);
		virtual units_t& getUnits();
    virtual bool hasUnitWithName(std::string const&) const;

    virtual void updateTextOverlay();
	};

} // end of namespace
