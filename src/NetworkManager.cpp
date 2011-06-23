/*
 *  NetworkManager.cpp
 *  Elementum
 *
 *  Created by Ahmad Amireh on 2/15/10.
 *  Copyright 2010 JU. All rights reserved.
 *
 */

#include "NetworkManager.h"
#include "Archiver.h"
#include "GameManager.h"
#include "Combat.h"

using RakNet::BitStream;
using RakNet::RakPeerInterface;
using RakNet::SocketDescriptor;
using RakNet::NetworkIDManager;
using RakNet::RakNetGUID;
using RakNet::SystemAddress;
namespace Pixy {

	NetworkManager* NetworkManager::mInstance = NULL;

	NetworkManager::NetworkManager() {
		mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, "NetMgr");

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
    mPktHandlers.insert(make_pair((MessageID)ID_LOGIN_EVENT, &NetworkManager::eventReceived));
    mPktHandlers.insert(make_pair((MessageID)ID_FETCH_GAME_DATA, &NetworkManager::gameDataReceived));
    mPktHandlers.insert(make_pair((MessageID)ID_FETCH_PUPPETS, &NetworkManager::puppetDataReceived));
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

    mPeer->CloseConnection(mServerAddr, true);
    sleep(1);
		RakNet::RakPeerInterface::DestroyInstance(mPeer);
		mPeer = 0;
		fOnline = false;
		return true;
	}

	bool NetworkManager::evtLogin(Event* inEvt) {
    // download latest game data
    mStream.Reset();
    mStream.AssertStreamEmpty();
    mStream.Write<MessageID>(ID_FETCH_GAME_DATA);
    mPeer->Send(&mStream, HIGH_PRIORITY, RELIABLE, 0, mServerAddr, false);

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

	void NetworkManager::gameDataReceived(Packet* inPkt) {
    using std::string;
    using std::vector;

    BitStream lStream(inPkt->data, inPkt->length, false);
		unsigned char lPktId = mPktProcessor->getPacketIdentifier(inPkt);

    lStream.IgnoreBytes(1);

    int sumlen = 32;
    int buflen = inPkt->length - 33 - sizeof(int);
    int rawlen = 0;

    char* sum = (char*)malloc(sizeof(char) * sumlen);
    lStream.Read(sum, sumlen);
    sum[sumlen] = '\0';

    lStream.Read<int>(rawlen);

    char* buf = (char*)malloc(sizeof(char) * (buflen + 1));
    lStream.Read(buf, buflen);
    buf[buflen] = '\0';

    string buf2str(buf, buflen);
    //std::cout << "compressed data is: " << buf2str << "\n";

    vector<unsigned char> encoded(buf2str.begin(), buf2str.end());
    vector<unsigned char> raw;

    if (Archiver::decodeLzma(raw, encoded, rawlen) != 1) {
      std::cerr << "decoding failed!! \n";
    }

    string raw2str(raw.begin(), raw.end());

    std::cout << "packet size: "<< inPkt->length << ", compressed stream size: " << buflen << ", raw stream size: " << raw.size() << "\n";
    std::cout << "Uncompressed puppet data: " << raw2str << "\n";

    std::istringstream datastream(raw2str);
    GameManager::getSingleton().getResMgr().populate(datastream);
    datastream.clear();

    free(buf);
    encoded.clear();
    raw.clear();
    free(sum);
	}

	void NetworkManager::puppetDataReceived(Packet* inPkt) {
    using std::string;
    using std::vector;

    BitStream lStream(inPkt->data, inPkt->length, false);
		unsigned char lPktId = mPktProcessor->getPacketIdentifier(inPkt);

    lStream.IgnoreBytes(1);

    int sumlen = 32;
    int buflen = inPkt->length - 33 - sizeof(int);
    int rawlen = 0;

    char* sum = (char*)malloc(sizeof(char) * sumlen);
    lStream.Read(sum, sumlen);
    sum[sumlen] = '\0';

    lStream.Read<int>(rawlen);

    char* buf = (char*)malloc(sizeof(char) * (buflen + 1));
    lStream.Read(buf, buflen);
    buf[buflen] = '\0';

    string buf2str(buf, buflen);
    //std::cout << "compressed data is: " << buf2str << "\n";

    vector<unsigned char> encoded(buf2str.begin(), buf2str.end());
    vector<unsigned char> raw;

    if (Archiver::decodeLzma(raw, encoded, rawlen) != 1) {
      std::cerr << "decoding failed!! \n";
    }

    string raw2str(raw.begin(), raw.end());

    std::cout << "packet size: "<< inPkt->length << ", compressed stream size: " << buflen << ", raw stream size: " << raw.size() << "\n";
    std::cout << "Uncompressed puppet data: " << raw2str << "\n";

    std::istringstream datastream(raw2str);
    GameManager::getSingleton().getResMgr().puppetsFromStream(datastream);
    datastream.clear();

    list<CPuppet*> lPuppets = GameManager::getSingleton().getResMgr().getPuppets();
    list<CPuppet*>::iterator lPuppet;
    for (lPuppet = lPuppets.begin(); lPuppet != lPuppets.end(); ++lPuppet)
      Combat::getSingletonPtr()->registerPuppet(*lPuppet);

		{
			// notify components that we received puppet data
			Event* lEvt = mEvtMgr->createEvt("AssignPuppets");
			lEvt->setType(EVT_RESP);
			mEvtMgr->hook(lEvt);
			lEvt = NULL;
		}

    free(buf);
    encoded.clear();
    raw.clear();
    free(sum);
	}
}
