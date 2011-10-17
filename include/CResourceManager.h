/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_CResourceManager_H
#define H_CResourceManager_H

#include "Pixy.h"
#include "ResourceManager.h"
#include "CPuppet.h"
#include "CSpell.h"
#include "CUnit.h"
#include "CDeck.h"

using std::string;
using std::vector;
using std::list;
using std::istringstream;
namespace Pixy
{
  //class CSpell;
  //class CUnit;
  //class CDeck;
	class CResourceManager : public ResourceManager {
    public:
    typedef CSpell spell_t;
    typedef CUnit unit_t;
    typedef CPuppet puppet_t;

    typedef std::list<puppet_t*> puppets_t;

    CResourceManager();
    virtual ~CResourceManager();

    virtual spell_t* const getSpell(std::string const& inName, char inRace);
    virtual unit_t* const getUnit(std::string const& inName, char inRace);

    protected:

  };
}

#endif
