/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_NetworkManager_H
#define H_NetworkManager_H

#include <iostream>

#include "Pixy.h"
#include "Connection.hpp"
#include <boost/thread.hpp>

namespace Pixy {

	struct Event;

	/*! \class NetworkManager
	 *	\brief
	 *	Handles connections and sockets and streaming of game data over the network.
	 *	This class also intercepts all events meant to be sent to the server and
	 *	does the actual sending
	 */
	class NetworkManager {

	public:
		static NetworkManager* getSingletonPtr();
    static NetworkManager& getSingleton();
		virtual ~NetworkManager();

		/*! \brief
		 *	initiates connection to the master server, result of the attempt
		 *	is handled by connAccepted() and connFailed()
		 */
		bool connect();

		/*! \brief
		 *	dispatches a "Logout" event to all the local modules so they can
		 *	wrap up their work, then severes the connection with the MS
		 */
		bool disconnect();

    void send(const Event&);

    bool isConnected() const;

	protected:
    void doConnect();

		/*! \brief
		 *	uses dispatchEvent() method to broadcast an incoming event
		 */
		void onInbound(const Event&);

    void onSyncGameData(const Event&);

		log4cpp::Category	*mLog;

		bool fOnline;

	private:
		static NetworkManager* mInstance;
		NetworkManager();

    Connection_ptr conn_;
    std::string mHost;

    boost::asio::io_service& io_service_;
    boost::asio::io_service::work work_;
    boost::asio::deadline_timer timer_;
    boost::thread* poller_;

	};
}

#endif
