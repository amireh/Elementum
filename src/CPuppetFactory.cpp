// EntityFactory.cpp

#include "CPuppetFactory.h"
#include "PixyUtility.h"

namespace Pixy
{
	CPuppetFactory* CPuppetFactory::mPuppetFactory = NULL;

	CPuppetFactory::CPuppetFactory()
	{
		mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, "CPuppetFactory");

		mEntities.clear();
	    mLog->infoStream() << "runningzz";
	};

	CPuppetFactory::~CPuppetFactory()
	{
		mLog->infoStream() << "cleaning up Puppet pools";
	    for (int i=0; i<4;i++)
	    {
        while (!mPool[i].empty())
        {
          mPool[i].pop_back();
        }
	    }

		mLog->infoStream() << "destroying Puppet objects";

		entities_t::iterator lPuppet = mEntities.begin();
		for (lPuppet; lPuppet != mEntities.end(); ++lPuppet) {
			delete (*lPuppet);
		}

		if (mLog)
		  delete mLog;
    mPuppetFactory = NULL;
	};

	CPuppetFactory* CPuppetFactory::getSingletonPtr()
	{
		if (mPuppetFactory == NULL)
			mPuppetFactory = new CPuppetFactory();

		return mPuppetFactory;
	};


	CPuppet*
	CPuppetFactory::createEntity(const int inObjectId,
	                            const std::string& inName,
	                            const std::string& inOwner,
	                            const RACE inRace)
	{
    CPuppet* lPuppet = new CPuppet();
		lPuppet->setName(inName);
		lPuppet->setRace(inRace);
    lPuppet->setObjectId(inObjectId);
    lPuppet->setOwner(inOwner);

    mLog->infoStream() << "Creating a puppet called " << lPuppet->getName() << " of race " << lPuppet->getRace();
		// track our puppet
		mEntities.push_back(lPuppet);

		return lPuppet;
	};


	void CPuppetFactory::destroyEntity(CPuppet* inEntity)
	{
		// remove it from our container
		mEntities.remove(inEntity);

    delete inEntity;
    inEntity = 0;
	};




} // end of namespace Pixy
