#ifndef H_CPuppet_H
#define H_CPuppet_H

#include "Puppet.h"
#include "Renderable.h"
#include "CDeck.h"
#include <list>
#include <vector>

using std::list;
using std::vector;
namespace Pixy
{
  /*! \class CPuppet CPuppet.h "src/CPuppet.h"
   *  \brief Represents Combat CPuppet GameObject
   */
  //class Deck;
  //class CDeck : public Deck;
	class CPuppet : public Puppet
	{
	public:
    CPuppet();
    virtual ~CPuppet();

    virtual Renderable& getRenderable();

    virtual bool live();
    virtual void die();

    virtual CDeck* getDeck();

	protected:
    Renderable* mRenderable;
    CDeck *mDeck;
	};
} // end of namespace
#endif
