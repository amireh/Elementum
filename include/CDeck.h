#ifndef H_CDeck_H
#define H_CDeck_H

#include "Pixy.h"
#include "Deck.h"
//#include "CSpell.h"
//#include "CPuppet.h"

using std::vector;
namespace Pixy
{
  class CSpell;
  class CPuppet;
  //class CombatManager;

  /*! \class Deck
   *  \brief
   *  Contains the Spells from which a Puppet draws into its hand
   */
  class CDeck : public Deck {
	public:
		CDeck(CPuppet* inPuppet);
		virtual ~CDeck();

		/*! \brief
		 *	creates the pool of spells from which the Puppet will be drawing
		 *  using the Puppet's race, alignment, and talent build;
		 *  this method will prepare a list of spells the Puppet
		 *  is eligible to cast
		 */
		virtual void generate();

		/*! \brief
		 *	draws a spell randomly from this Puppet's deck
		 *  using a random number generator, this method
		 *  will retrieve a spell from the pool and
		 *  insert it into the Puppet's hand
		 */
		//CSpell* drawSpell();

		CSpell* getSpell(std::string inName);
	protected:
		//vector<CSpell*>  mSpells;
		static int      idCounter;
		int             nrRandom;
		CPuppet*           mPuppet;

	};
}

#endif // H_Deck_H
