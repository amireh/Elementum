#ifndef H_CPuppet_H
#define H_CPuppet_H

#include "CUnit.h"
#include "Puppet.h"
//#include "Renderable.h"
//#include "CDeck.h"
#include "CSpell.h"
#include <list>
#include <vector>

using std::list;
using std::vector;
namespace Pixy
{
  //~ class CUnit;
  class CDeck;
  class Renderable;
  /*! \class CPuppet CPuppet.h "src/CPuppet.h"
   *  \brief Represents Combat CPuppet GameObject
   */
	class CPuppet : public Puppet
	{
	public:
		typedef list<CSpell*> hand_t;
		typedef list<CUnit*> units_t;
    typedef list<CDeck const*> decks_t;

    CPuppet();
    virtual ~CPuppet();

    virtual Renderable* getRenderable();

    virtual bool live();
    virtual void die();

    //virtual CDeck* getDeck();
		hand_t const& getHand();
		virtual int nrSpellsInHand();
    //~ virtual spells_t const& getSpells();
    virtual CSpell* getSpell(int inUID);
		virtual void attachSpell(CSpell* inSpell);
		virtual void detachSpell(int inUID);

		virtual void attachUnit(CUnit* inUnit);
		virtual void detachUnit(int inUID);
		virtual CUnit* getUnit(int inUID);
		//virtual units_t& getUnits();

	protected:
    Renderable* mRenderable;
    CDeck *mDeck;
    decks_t   mDecks;
		hand_t			mHand;
		units_t     mUnits;
	};
} // end of namespace
#endif
