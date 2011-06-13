/*
 *  NetworkManager.cpp
 *  Elementum
 *
 *  Created by Ahmad Amireh on 2/15/10.
 *  Copyright 2010 JU. All rights reserved.
 *
 */

#include "NetworkManager.h"

using RakNet::BitStream;
using RakNet::RakPeerInterface;
using RakNet::SocketDescriptor;
using RakNet::NetworkIDManager;
using RakNet::RakNetGUID;
using RakNet::SystemAddress;
namespace Pixy {
	
	NetworkManager* NetworkManager::mInstance = NULL;
	
	NetworkManager::NetworkManager() {
		mLog = new log4cpp::FixedContextCategory(CLIENT_LOG_CATEGORY, "NetMgr");
		
		mPktProcessor = new PacketProcessor(mLog);
		
		fOnline = false;
		
		mEvtMgr = EventManager::getSingletonPtr();
		// we'll be handling the EVT_REQ events (outgoing to server)
		mEvtMgr->subscribeNetworkDispatcher(this);
		
		// fire up our RakPeerInterface and its socket
		mPeer = RakNet::RakPeerInterface::GetInstance();
		//mPeer->SetNetworkIDManager(&mNetIDMgr);
		mSock = new SocketDescriptor();
		//mPeer->Startup(1, 10, mSock, 1);
		mPeer->Startup(1, mSock, 1);
		
		bindEventHandlers();
		bindPacketHandlers();
		
		mLog->infoStream() << "up and running";
	}
	
	NetworkManager::~NetworkManager() {
	  if (fOnline)
	    disconnect();
	    
		
		
		if (mPktProcessor)
			delete mPktProcessor;
		
		RakNet::RakPeerInterface::DestroyInstance(mPeer);
		
		mPktProcessor = 0;
		
		mLog->infoStream() << "shutting down";
		if (mLog)
			delete mLog;
		mLog = 0;
		fOnline = false;
	}
	
	NetworkManager* NetworkManager::getSingletonPtr() {
		if (!mInstance)
			mInstance = new NetworkManager();
		
		return mInstance;
	}
	
	void NetworkManager::bindEventHandlers() {
		bindToAll<NetworkManager>(this, &NetworkManager::dispatchToServer);
		bindToName("Logout", this, &NetworkManager::evtLogout);
		bindToName("Login", this, &NetworkManager::evtLogin);
	}
	
	void NetworkManager::bindPacketHandlers() {
		mPktHandlers.insert(make_pair((MessageID)ID_EVENT, &NetworkManager::eventReceived));
		mPktHandlers.insert(make_pair((MessageID)ID_ENTITY_EVENT, &NetworkManager::eventReceived));
		mPktHandlers.insert(make_pair(ID_CONNECTION_REQUEST_ACCEPTED, &NetworkManager::connAccepted));
		mPktHandlers.insert(make_pair(ID_CONNECTION_ATTEMPT_FAILED, &NetworkManager::connFailed));
	}
	
	bool NetworkManager::connect() {
	  if (fOnline)
	    return true;
	    
    mLog->infoStream() << "Connecting to server";
    
		mPeer->Connect(SERVER_ADDRESS, SERVER_PORT,0,0);
		
		return true;
	}
	
	bool NetworkManager::disconnect() {
    if (!fOnline)
      return true;
      
    mLog->infoStream() << "Disconnecting from server";
    
		RakNet::RakPeerInterface::DestroyInstance(mPeer);
		mPeer = 0;
		fOnline = false;
		return true;
	}
	
	bool NetworkManager::evtLogin(Event* inEvt) {
	  /*if (!fOnline)
	    connect();*/
		
		return true;
	}
	bool NetworkManager::evtLogout(Event* inEvt) {
	  /*if (fOnline)
	    disconnect();*/
	    
		return true;
	}

	bool NetworkManager::dispatchToServer(Event* inEvt) {
		
		if (!fOnline)
			return true;
		
		if (inEvt->getType() == EVT_RESP || inEvt->isLocal())
			return true;
		
		mStream.Reset();
		mPktProcessor->dumpEvent(inEvt, mStream);

		//mLog->infoStream() << "sending pkt to server data with length " << mStream.GetNumberOfBytesUsed();
		mPeer->Send(&mStream, HIGH_PRIORITY, RELIABLE, 0, mServerAddr, false);
		
		mStream.Reset();
		mStream.AssertStreamEmpty();

		return true;
	}
	
	void NetworkManager::eventReceived(Packet* inPkt) {
		Event* lEvt = mPktProcessor->parseEvent(mPacket);
		mEvtMgr->hook(lEvt);
		lEvt = 0;
	}
	
	void NetworkManager::connAccepted(Packet* inPkt) {
		mServerAddr = mPacket->systemAddress;
		mServerGUID = mPacket->guid;
		mGUID = mPeer->GetGuidFromSystemAddress(RakNet::UNASSIGNED_SYSTEM_ADDRESS);
		mLog->infoStream() << "Connected to Server! my guid is " << mGUID.ToString();
		{
			// notify components that we're connected
			Event* lEvt = mEvtMgr->createEvt("Connected");
			lEvt->setType(EVT_RESP);
			mEvtMgr->hook(lEvt);
			lEvt = NULL;
		}	
		fOnline = true;
	}
	
	void NetworkManager::connFailed(Packet* inPkt) {
		mLog->infoStream() << "Connection Failed!";
		fOnline = false;
	}
	
	void NetworkManager::update() {

		if (!mPeer)
			return;
		
		mPacket = mPeer->Receive();

		while (mPacket) {
			
			// the hideous unreadability of the following line is due to
			// aggressive optimization. what it basically does is it retrieves
			// our packet handler from the map, then dereferences it and
			// passes it our packet
			if (mPktHandlers.find(mPktProcessor->getPacketIdentifier(mPacket)) != mPktHandlers.end())
				(this->*(mPktHandlers.find(mPktProcessor->getPacketIdentifier(mPacket))->second))(mPacket);
			
			mPeer->DeallocatePacket(mPacket);
			mPacket = 0;
		}
		
		//if (!fOnline)
		//	return;
		
		processEvents();
	}
	
}
