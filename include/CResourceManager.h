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
	class CResourceManager : public ResourceManager {
    public:
      typedef std::list<CSpell*> spells_t;
      typedef std::list<CUnit*> units_t;

      CResourceManager();
      virtual ~CResourceManager();

      list<CPuppet*> puppetsFromStream(istringstream &stream);
      list<CPuppet*>& getPuppets();

    protected:

      void parsePuppetsSection(istringstream &stream, int section, int nrEntries);
      void parsePuppetsStats(vector<string>& entries);
      void parsePuppetsDecks(vector<string>& entries);

      void assignTalents(Puppet& inPuppet, string inTalents);
      void assignDeck(Puppet& inPuppet, string inName, string inSpells, int inUseCount);

      CPuppet* getPuppet(string inName, list<CPuppet*>& inPuppets);

      spells_t mSpells[4];
      units_t mUnits[4];

      list<CPuppet*> mPuppets;
  };
}

#endif
