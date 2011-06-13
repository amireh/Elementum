#ifndef H_CUnit_H
#define H_CUnit_H

#include "Unit.h"
#include "Renderable.h"
#include <list>
#include <vector>

using std::list;
using std::vector;
namespace Pixy
{

	class CUnit : public Unit
	{
	public:
    CUnit();
    virtual ~CUnit();

    virtual Renderable& getRenderable();

    virtual bool live();
    virtual void die();

	protected:
    Renderable* mRenderable;

	};
} // end of namespace
#endif
