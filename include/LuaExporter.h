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
#include "Spell.h"
#include "Puppet.h"
#include "Unit.h"

typedef std::vector<Pixy::Unit*> UnitVec;
typedef std::vector<Pixy::Spell*> SpellVec;
typedef std::vector<Pixy::Puppet*> PuppetVec;
typedef std::vector<Pixy::Deck*> DeckVec;
typedef std::list<Pixy::Unit*> UnitList;
typedef std::list<Pixy::Spell*> SpellList;
typedef std::list<Pixy::Puppet*> PuppetList;
typedef std::list<Pixy::Deck*> DeckList;

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
