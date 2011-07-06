#ifndef H_CUnit_H
#define H_CUnit_H

#include "Unit.h"
#include <list>
#include <vector>

using std::list;
using std::vector;
namespace Pixy
{

  class Renderable;
	class CUnit : public Unit
	{
	public:
    CUnit();
    CUnit(const CUnit& src);
    CUnit& operator=(const CUnit& rhs);
    virtual ~CUnit();

    virtual Renderable* getRenderable();

    virtual bool live();
    virtual void die();

	protected:
    Renderable* mRenderable;
    virtual void copyFrom(const CUnit& src);

	};
} // end of namespace
#endif
