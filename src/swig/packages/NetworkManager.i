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
  #include "NetworkManager.h"
%}

namespace Pixy {

  %nodefaultctor NetworkManager;

	struct Event;
	class NetworkManager {

	public:
		static NetworkManager* getSingletonPtr();
    static NetworkManager& getSingleton();

		bool connect();
		bool disconnect();

    void send(const Event&);

    bool isConnected() const;


	};
}
