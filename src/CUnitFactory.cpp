// EntityFactory.cpp

#include "CUnitFactory.h"
#include "PixyUtility.h"

namespace Pixy
{
	CUnitFactory* CUnitFactory::mUnitFactory = NULL;

	CUnitFactory::CUnitFactory()
	{
		mLog = new log4cpp::FixedContextCategory(CLIENT_LOG_CATEGORY, "CUnitFactory");

		mEntities.clear();
	    mLog->infoStream() << "runningzz";
	};

	CUnitFactory::~CUnitFactory()
	{
		mLog->infoStream() << "cleaning up Unit pools";
	    for (int i=0; i<4;i++)
	    {
        while (!mPool[i].empty())
        {
          mPool[i].pop_back();
        }
	    }

		mLog->infoStream() << "destroying Unit objects";

		entities_t::iterator lUnit = mEntities.begin();
		for (lUnit; lUnit != mEntities.end(); ++lUnit) {
			delete (*lUnit);
		}

		if (mLog)
		  delete mLog;
    mUnitFactory = NULL;
	};

	CUnitFactory* CUnitFactory::getSingletonPtr()
	{
		if (mUnitFactory == NULL)
			mUnitFactory = new CUnitFactory();

		return mUnitFactory;
	};


	CUnit*
	CUnitFactory::createEntity(const int inObjectId,
	                            const std::string& inName,
	                            const std::string& inOwner,
	                            const RACE inRace)
	{
    CUnit* lUnit = new CUnit();
		lUnit->setName(inName);
		lUnit->setRace(inRace);
    lUnit->setObjectId(inObjectId);
    lUnit->setOwner(inOwner);

    mLog->infoStream() << "Creating a Unit called " << lUnit->getName() << " of race " << lUnit->getRace();
		// track our Unit
		mEntities.push_back(lUnit);

		return lUnit;
	};


	void CUnitFactory::destroyEntity(CUnit* inEntity)
	{
		// remove it from our container
		mEntities.remove(inEntity);

    delete inEntity;
    inEntity = 0;
	};




} // end of namespace Pixy
