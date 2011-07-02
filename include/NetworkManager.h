/*
 *  NetworkManager.h
 *  Elementum
 *
 *  Created by Ahmad Amireh on 2/15/10.
 *  Copyright 2010 JU. All rights reserved.
 *
 */

#ifndef H_NetworkManager_H
#define H_NetworkManager_H

#include <iostream>

#include "PixyLog.h"
#include "Connection.hpp"
#include <boost/thread.hpp>

namespace Pixy {

	class Event;

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
		 *	polls for Events and handles them upon arrival
		 */
		void update();

		/*! \brief
		 *	dispatches a "Logout" event to all the local modules so they can
		 *	wrap up their work, then severes the connection with the MS
		 */
		bool disconnect();

    void send(const Event&);

	protected:
		/*! \brief
		 *	broadcasts an INCOMING (EVT_RESP) event to all the modules interested
		 */
		bool dispatchEvent(Event* inEvt);

		/*! \brief
		 *	intercepts OUTGOING (EVT_REQ) events and sends them off to the server
		 */
		bool dispatchToServer(Event* inEvt);

		/*! \brief
		 *	even though the NetworkManager itself is the one who broadcasts the
		 *	Logout event upon loss of connection; it's also interested in it
		 *	to clean up
		 */
		bool evtLogout(Event* inEvt);
		// connect
		bool evtLogin(Event* inEvt);

		log4cpp::Category	*mLog;

		bool fOnline, fGameDataReceived;

		//~ map<MessageID, void (NetworkManager::*)(Event*)> mPktHandlers;

	private:

		/*! \brief
		 *	populates the mPktHandlers map with the methods that will handle each
		 *	type of Event received
		 */
		void bindEventHandlers();

		/*! \brief
		 *	uses dispatchEvent() method to broadcast an incoming event
		 */
		void eventReceived(const Event& inEvt);

    void gameDataReceived(const Event& inEvt);
    void puppetDataReceived(const Event& inEvt);
    void passDrawSpells(const Event& inEvt);

		static NetworkManager* mInstance;
		NetworkManager();

    Connection_ptr conn_;

    boost::asio::io_service io_service_;
    boost::asio::io_service::work work_;
    boost::asio::deadline_timer timer_;
    boost::thread* poller_;

	};
}

#endif
