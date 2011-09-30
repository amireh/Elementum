#ifndef H_CPixyLua_H
#define H_CPixyLua_H

#include "PixyLua.h"
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
  class CLuaExporter : public LuaExporter<T>
  {
    TOLUA_TEMPLATE_BIND(T)

    public:
      CLuaExporter() { }
      virtual ~CLuaExporter() {}


      inline virtual void
      __export(T const& container, const char* data_type, const char* out_table)
      {
        LuaExporter<T>::__export(ScriptEngine::getSingleton().getLuaState(), container, data_type, out_table);
      }
  };
}

#endif
