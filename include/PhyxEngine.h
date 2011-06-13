/*
 *  PhyxEngine.h
 *  Elementum
 *
 *  Created by Ahmad Amireh on 2/15/10.
 *  Copyright 2010 JU. All rights reserved.
 *
 */


#ifndef H_PhyxEngine_H
#define H_PhyxEngine_H

#include "Pixy.h"
#include "Engine.h"
#include "EventListener.h"

namespace Pixy
{
	
	/*! \class PhyxEngine
	 *	\brief
	 *	Binds physics functionality in game Entity objects, handles collision 
	 *	events, manages all Physics-related resources, and acts as a wrapper
	 *	over nVidia's PhyX system.
	 */
    class PhyxEngine : public Engine, public EventListener
	{
    };
};



#endif