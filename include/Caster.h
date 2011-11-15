/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_Caster_H
#define H_Caster_H

#include "Pixy.h"
#include "BaseCaster.h"
#include "Spell.h"
#include <list>

namespace Pixy
{

	/*!
   * @class Caster Caster.h "src/Caster.h"
   *
	 * @brief
   * Caster entities can hold BaseSpell objects and cast them.
	 */
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

    /*!
     * @brief
     * Adds the given BaseSpell object to this Caster's container, and assigns this
     * Caster instance as the BaseSpell's Caster.
     *
     * @warning
     * Ownership of the BaseSpell pointer is transferred to the Caster,
     * which means you can't invalidate throughout the lifetime of this Caster.
     *
     * Furthermore, Casters will _destroy_ all BaseSpell objects they hold upon
     * their destruction.
     */
		virtual void attachSpell(BaseSpell* inSpell);
		virtual void attachBuff(BaseSpell* inSpell);

    /*!
     * @brief
     * Removes BaseSpell with the given UID from the container. The BaseSpell object
     * will be destroyed if remove is true.
     *
     * @note
     * This method can raise an exception of type invalid_uid if the spell can not be found.
     */
		virtual void detachSpell(int inUID, bool remove=true);
		virtual void detachBuff(int inUID, bool remove=true);

    /*!
     * @brief
     * Returns the BaseSpell with the given UID.
     *
     * @note
     * This method can raise an exception of type invalid_uid if the spell can not be found.
     */
    virtual spell_t* getSpell(int inUID);
    virtual spell_t* getBuff(int inUID);

    //! @brief Returns the current BaseSpell objects the Caster has
		spells_t const& getSpells();
		spells_t const& getBuffs();

    //! @brief Convenience method for returning the number of Spells this Caster has
		virtual int nrSpells();
		virtual int nrBuffs();

    virtual bool hasBuff(int inUID);
    virtual bool hasBuffWithName(std::string const&);

		protected:

    spells_t mSpells;
    spells_t mBuffs;

		//! helper method for copy/assignment methods
		//! copies all data from src and sets it into this Caster
		virtual void copyFrom(const Caster& src);

	}; // end of Caster class
} // end of Pixy namespace
#endif
