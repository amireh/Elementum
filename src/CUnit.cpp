#include "CUnit.h"
#include "Renderable.h"

namespace Pixy
{

  CUnit::CUnit() {
    mRenderable = new Renderable(this);
  };

  bool CUnit::live() {
    mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, "CUnit " + mName);
    mLog->infoStream() << "created";

    return true;
  };

  void CUnit::die() {

    mLog->infoStream() << "dead";
  };

  CUnit::~CUnit() {

    if (mRenderable)
      delete mRenderable;

    mRenderable = 0;
  };

  Renderable& CUnit::getRenderable() {
    return *mRenderable;

  }


} // end of namespace
