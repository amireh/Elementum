/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_EntityManager_H
#define H_EntityManager_H

#include "Pixy.h"
#include "BaseEntityManager.h"
#include "ResourceParser.h"
#include "Entity.h"
#include "Deck.h"
#include "Puppet.h"
#include "Unit.h"
#include "Spell.h"
#include "Talent.h"

namespace Pixy
{
	class EntityManager : public BaseEntityManager {
    public:

    EntityManager();
    virtual ~EntityManager();

    typedef Spell spell_t;
    typedef Unit unit_t;
    typedef Puppet puppet_t;
    typedef Deck deck_t;
    typedef Talent talent_t;

    typedef std::list<spell_t*> spells_t;
    typedef std::list<unit_t*> units_t;
    typedef std::list<talent_t*> talents_t;
    typedef std::list<puppet_t*> puppets_t;
    typedef std::list<deck_t*> decks_t;

    virtual void clear();

    /**
     * @brief
     * Returns a _copy_ of the requested spell identified by inName.
     *
     * An exception of type "UnidentifiedResource" will be thrown if the requested
     * spell is not found.
     **/
    virtual spell_t* const getSpell(std::string const& inName);
    virtual spell_t* const getSpell(std::string const& inName, char inRace);

    /**
     * @brief
     * Returns a _copy_ of the requested unit identified by inName.
     *
     * An exception of type "UnidentifiedResource" will be thrown if the requested
     * unit is not found.
     **/
    virtual unit_t* const getUnit(std::string const& inName);
    virtual unit_t* const getUnit(std::string const& inName, char inRace);

    virtual puppet_t* getPuppet(std::string const& inName);
    virtual puppet_t* getPuppetInList(std::string const& inName, puppets_t const& inList);

    /**
     * @brief
     * Retrieves the _model_ Talent identified by inName.
     *
     * Since Talents are globally unique and do not have to be cloned,
     * the pointer returned here is a "weak" const one.
     **/
    virtual talent_t const* const getTalent(std::string const& inName);
    virtual talent_t const* const getTalent(std::string const& inName, char inRace);

    /**
     * @brief
     * Returns ALL the registered spell models for the given race.
     *
     * This is used internally by Lua to populate its own database.
     **/
    virtual spells_t const& _getSpells(char inRace);
    virtual units_t const& _getUnits(char inRace);
    virtual talents_t const& _getTalents(char inRace);
    virtual puppets_t& _getPuppets();

    protected:
    friend class ResourceParser;

    virtual Spell* createSpell(char inRace);
    virtual Unit* createUnit(char inRace);
    virtual Puppet* createPuppet(int inUID, std::string inName, char inRace);
    virtual Deck* createDeck(BasePuppet const* inPuppet);
    virtual Talent* createTalent(char inRace);

    virtual const spell_t* const getModelSpell(std::string const& inName);
    virtual const unit_t* const getModelUnit(std::string const& inName);

    log4cpp::Category	*mLog;
    spells_t mSpells[4];
    units_t mUnits[4];
    talents_t mTalents[4];
    puppets_t mPuppets;
    decks_t mDecks;
  };
}
#endif
