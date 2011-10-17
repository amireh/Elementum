/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_CPuppet_H
#define H_CPuppet_H

#include "Puppet.h"
//#include "Renderable.h"
#include "CUnit.h"
//#include "CDeck.h"
#include "CSpell.h"
#include <list>
#include <vector>
#include "Logger.h"

using std::list;
using std::vector;
namespace Pixy
{
  //~ class CUnit;
  class CDeck;
  //~ class Renderable;
  /*! \class CPuppet CPuppet.h "src/CPuppet.h"
   *  \brief Represents Combat CPuppet GameObject
   */
	class CPuppet : public Puppet, public CEntity, public Logger
	{
	public:
		//~ typedef std::list<CSpell*> hand_t;
    //~ typedef std::list<CSpell*> spells_t;
		//~ typedef std::list<CUnit*> units_t;
    //~ typedef std::list<CDeck const*> decks_t;

    CPuppet();
    virtual ~CPuppet();

    //~ virtual Renderable* getRenderable();

    virtual bool live();
    virtual void die();

    //virtual CDeck* getDeck();

		//~ virtual void attachUnit(CUnit* inUnit);
		//~ virtual void detachUnit(int inUID, bool remove=true);
		virtual CUnit* getUnit(int inUID);
		//~ units_t const& getUnits() const;

    virtual void deserialize(const Event& evt);

    void updateTextOverlay();

    void onVictory();

    virtual void setHP(int inHP);

	protected:
    //~ Renderable* mRenderable;
    //~ CDeck *mDeck;
    //~ decks_t   mDecks;
		//~ hand_t			mHand;
    //~ spells_t    mBuffs;
		//~ units_t     mUnits;

    CPuppet* mEnemy;
	};
} // end of namespace
#endif
