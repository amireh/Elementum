#ifndef H_CPuppet_H
#define H_CPuppet_H

#include "Puppet.h"
//#include "Renderable.h"
#include "CUnit.h"
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
		typedef std::list<CSpell*> hand_t;
    typedef std::list<CSpell*> spells_t;
		typedef std::list<CUnit*> units_t;
    typedef std::list<CDeck const*> decks_t;

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
		virtual void detachSpell(int inUID, bool remove=true);

    spells_t const& getBuffs() const;
    virtual void attachBuff(CSpell*);
    virtual void detachBuff(int inUID);
    virtual bool hasBuff(int inUID);

		virtual void attachUnit(CUnit* inUnit);
		virtual void detachUnit(int inUID, bool remove=true);
		virtual CUnit* getUnit(int inUID);
		units_t const& getUnits() const;

    virtual void updateFromEvent(const Event& evt);

    void updateTextOverlay();

    void onVictory();

    virtual void setHP(int inHP);

	protected:
    Renderable* mRenderable;
    CDeck *mDeck;
    decks_t   mDecks;
		hand_t			mHand;
    spells_t    mBuffs;
		units_t     mUnits;

    CPuppet* mEnemy;
	};
} // end of namespace
#endif
