#ifndef H_CPuppet_H
#define H_CPuppet_H

#include "Puppet.h"
#include "Renderable.h"
#include "CDeck.h"
#include "CUnit.h"
#include "CSpell.h"
#include <list>
#include <vector>

using std::list;
using std::vector;
namespace Pixy
{
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

    virtual Renderable& getRenderable();

    virtual bool live();
    virtual void die();

    //virtual CDeck* getDeck();
    virtual CSpell* getSpell(int inUID);

	protected:
    Renderable* mRenderable;
    CDeck *mDeck;
    decks_t   mDecks;
		hand_t			mHand;
		units_t     mUnits;
	};
} // end of namespace
#endif
