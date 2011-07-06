#include "CUnit.h"
#include "Renderable.h"

namespace Pixy
{

  CUnit::CUnit() {
    mRenderable = new Renderable(this);
  };


  CUnit::CUnit(const CUnit& src)
  {
      copyFrom(src);
  };

  CUnit& CUnit::operator=(const CUnit& rhs)
  {
      // check for self-assignment
      if (this == &rhs)
          return (*this);

      copyFrom(rhs);
      return (*this);
  };

  CUnit::~CUnit() {

    if (mRenderable)
      delete mRenderable;

    mRenderable = 0;
  };

  void CUnit::copyFrom(const CUnit& src) {
    Unit::copyFrom(src);

    this->mRenderable = new Renderable(*src.mRenderable);
    this->mRenderable->setOwner(this);
  }

  bool CUnit::live() {
    mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, "CUnit " + mName);
    mLog->infoStream() << "created";

    return true;
  };

  void CUnit::die() {

    mLog->infoStream() << "dead";
  };



  Renderable* CUnit::getRenderable() {
    return mRenderable;

  }


} // end of namespace
