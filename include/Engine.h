/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_Engine_H
#define H_Engine_H

#include "Pixy.h"

namespace Pixy
{

	/*! \brief
	 *	Skeleton Engine that defines the base behaviour of all game Engines.
	 */
  class Engine
  {
    public:
    inline virtual ~Engine() { mLog = NULL; fSetup = false; };

    virtual bool setup()=0;
    virtual void update(unsigned long lTimeElapsed)=0;
    virtual bool cleanup()=0;

  protected:
    inline Engine() { mLog = NULL; fSetup = false; }
    log4cpp::Category* mLog;
    bool fSetup;

  private:
    Engine(const Engine& src);
    Engine& operator=(const Engine& rhs);

  };
};



#endif
