/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

%module Pixy
%{
  #include "LuaExporter.h"
  #include "BaseLuaExporter.h"

  #include <vector>
  #include <list>
%}

//%import(module="Pixy") "BaseLuaExporter.i"

namespace Pixy {

  template <typename T>
  class LuaExporter {
    public:

    LuaExporter();
    virtual ~LuaExporter();

    %rename("export") __export;
    void __export(T const& container, const char* data_type, const char* out_table);
  };

  %template(SpellListExporter)  LuaExporter<std::list<Pixy::Spell*> >;
  %template(UnitListExporter)   LuaExporter<std::list<Pixy::Unit* > >;
  %template(PuppetListExporter) LuaExporter<std::list<Pixy::Puppet*> >;
  %template(DeckListExporter)   LuaExporter<std::list<Pixy::Deck*> >;
}
