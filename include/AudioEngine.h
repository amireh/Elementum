/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */


#ifndef H_AudioEngine_H
#define H_AudioEngine_H

#include "Pixy.h"
#include "Engine.h"
#include "EventListener.h"

namespace Pixy
{

  class Engine;
  class EventListener;
	/*! \class AudioEngine
	 *	\brief
	 *	Provides audio support, loads sound resources, and handles all sound
	 *	related events.
	 */
  class AudioEngine : public Engine, public EventListener
	{
	};
};



#endif
