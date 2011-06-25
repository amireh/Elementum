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
#include "Event.h"
#include "EventListener.h"
#include "PacketProcessor.h"

//#include "RakNetworkFactory.h"
#include "RakPeerInterface.h"
#include "MessageIdentifiers.h"
#include "NetworkIDManager.h"
#include "GetTime.h"
#include "BitStream.h"
#include "RakString.h"
#include "RakNetTypes.h"

#undef __BITSTREAM_NATIVE_END

using RakNet::BitStream;
using RakNet::RakPeerInterface;
using RakNet::SocketDescriptor;
using RakNet::NetworkIDManager;
using RakNet::RakNetGUID;
using RakNet::SystemAddress;
namespace Pixy {

	class PacketProcessor;
	class Event;

	/*! \class NetworkManager
	 *	\brief
	 *	Handles connections and sockets and streaming of game data over the network.
	 *	This class also intercepts all events meant to be sent to the server and
	 *	does the actual sending
	 */
	class NetworkManager : public EventListener {

	public:
		static NetworkManager* getSingletonPtr();
		virtual ~NetworkManager();
		/*! \brief
		 *	initiates connection to the master server, result of the attempt
		 *	is handled by connAccepted() and connFailed()
		 */
		bool connect();

		/*! \brief
		 *	polls for packets and handles them upon arrival
		 */
		void update();

		/*! \brief
		 *	dispatches a "Logout" event to all the local modules so they can
		 *	wrap up their work, then severes the connection with the MS
		 */
		bool disconnect();

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

		RakPeerInterface	*mPeer;
		SocketDescriptor	*mSock;
		Packet				*mPacket;
		NetworkIDManager	mNetIDMgr;
		EventManager		*mEvtMgr;
		PacketProcessor		*mPktProcessor;
		log4cpp::Category	*mLog;
		RakNetGUID			mGUID;
		RakNetGUID			mServerGUID;
		SystemAddress		mServerAddr;
		BitStream			mStream;
		bool fOnline, fGameDataReceived;

		map<MessageID, void (NetworkManager::*)(Packet*)> mPktHandlers;

	private:
		/*! \brief
		 *	methods that will handle outgoing events, and the Logout event
		 */
		void bindEventHandlers();

		/*! \brief
		 *	populates the mPktHandlers map with the methods that will handle each
		 *	type of packet received
		 */
		void bindPacketHandlers();

		/*! \brief
		 *	uses dispatchEvent() method to broadcast an incoming event
		 */
		void eventReceived(Packet* inPkt);

    void gameDataReceived(Packet* inPkt);
    void puppetDataReceived(Packet* inPkt);
    void passDrawSpells(Packet* inPkt);

		/*! \brief
		 *	stores information about the server, and broadcasts the event "Connected"
		 *	to local modules
		 */
		void connAccepted(Packet* inPkt);

		/*! \brief
		 *	does nothing really, just logs a warning
		 */
		void connFailed(Packet* inPkt);

		static NetworkManager* mInstance;
		NetworkManager();

	};
}

#endif
