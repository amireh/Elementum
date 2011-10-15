/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_LuaExporter_H
#define H_LuaExporter_H

#include "BaseLuaExporter.h"
#include "ScriptEngine.h"

typedef std::vector<Pixy::CUnit*> CUnitVec;
typedef std::vector<Pixy::CSpell*> CSpellVec;
typedef std::vector<Pixy::CPuppet*> CPuppetVec;
typedef std::list<Pixy::CUnit*> CUnitList;
typedef std::list<Pixy::CSpell*> CSpellList;
typedef std::list<Pixy::CPuppet*> CPuppetList;

namespace Pixy {

  using std::list;

  template <typename T>
  class LuaExporter : public BaseLuaExporter<T>
  {
    TOLUA_TEMPLATE_BIND(T)

    public:
      LuaExporter() { }
      virtual ~LuaExporter() {}


      inline virtual void
      __export(T const& container, const char* data_type, const char* out_table)
      {
        BaseLuaExporter<T>::__export(ScriptEngine::getSingleton().getLuaState(), container, data_type, out_table);
      }
  };
}

#endif
