#include "NetworkManager.h"

#include "GameManager.h"
#include "Combat.h"


namespace Pixy {

	NetworkManager* NetworkManager::mInstance = NULL;

	NetworkManager::NetworkManager()
  : io_service_(),
    work_(io_service_),
    timer_(io_service_),
    fOnline(false),
    fGameDataReceived(false),
    mLog(new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, "NetMgr"))
  {
    poller_ = new boost::thread(boost::bind(&boost::asio::io_service::run, &io_service_));

		mLog->infoStream() << "up and running";
	}

	NetworkManager::~NetworkManager() {

	  if (fOnline)
	    disconnect();

    io_service_.stop();
    poller_->join();
    delete poller_;
    poller_ = 0;


		mLog->infoStream() << "shutting down";

		if (mLog)
			delete mLog;
		mLog = 0;
		fOnline = false;
	}

  NetworkManager& NetworkManager::getSingleton() {
		if (!mInstance)
			mInstance = new NetworkManager();

		return *mInstance;
	}

	NetworkManager* NetworkManager::getSingletonPtr() {
		return &getSingleton();
	}


	void NetworkManager::bindEventHandlers() {
		//~ bindToAll<NetworkManager>(this, &NetworkManager::dispatchToServer);
		//~ bindToName("Logout", this, &NetworkManager::evtLogout);
		//~ bindToName("Login", this, &NetworkManager::evtLogin);
    //bindToName("Connected", this, &NetworkManager::evtLogout);

		//~ mPktHandlers.insert(make_pair((MessageID)ID_EVENT, &NetworkManager::eventReceived));
		//~ mPktHandlers.insert(make_pair((MessageID)ID_ENTITY_EVENT, &NetworkManager::eventReceived));
    //~ mPktHandlers.insert(make_pair((MessageID)ID_LOGIN_EVENT, &NetworkManager::eventReceived));
    //~ mPktHandlers.insert(make_pair((MessageID)ID_FETCH_GAME_DATA, &NetworkManager::gameDataReceived));
    //~ mPktHandlers.insert(make_pair((MessageID)ID_FETCH_PUPPETS, &NetworkManager::puppetDataReceived));
    //~ mPktHandlers.insert(make_pair((MessageID)ID_DRAW_SPELLS, &NetworkManager::passDrawSpells));
		//~ mPktHandlers.insert(make_pair(ID_CONNECTION_REQUEST_ACCEPTED, &NetworkManager::connAccepted));
		//~ mPktHandlers.insert(make_pair(ID_CONNECTION_ATTEMPT_FAILED, &NetworkManager::connFailed));
	}

	bool NetworkManager::connect() {
    if (fOnline)
	    return true;

    mLog->infoStream() << "Connecting to server";

    conn_.reset(new Connection(io_service_, "phantom.shroom-studios.com"/*SERVER_ADDRESS*/, SERVER_PORT));
    if (!conn_->connect() ) {
      mLog->errorStream() << "couldnt start the conn .. ";
      return false;
    }
    try {
      conn_->start();
    } catch (std::exception& e) {
      mLog->errorStream() << "a connection error occured: " << e.what();
      return false;
    }

    conn_->get_dispatcher().bind(EventUID::Unassigned, this, &NetworkManager::eventReceived);

		{
			// notify components that we're connected
      Event evt(EventUID::Connected);
      EventManager::getSingleton().hook(evt);
		}
		fOnline = true;

    mLog->infoStream() << "connected";

		return true;
	}

	bool NetworkManager::disconnect() {
    if (!fOnline)
      return true;

    mLog->infoStream() << "Disconnecting from server";

    conn_->stop();
    conn_.reset();

		fOnline = false;
		return true;
	}

  void NetworkManager::send(const Event& inEvt) {
    mLog->debugStream() << "sending an event " << (int)inEvt.UID;
    inEvt.dump();
    conn_->send(inEvt);
  }

	void NetworkManager::eventReceived(const Event& inEvt) {
    EventManager::getSingleton().hook(inEvt);
		//~ Event* lEvt = mPktProcessor->parseEvent(mEvent);
		//~ mEvtMgr->hook(lEvt);
		//~ lEvt = 0;
	}

	bool NetworkManager::evtLogin(Event* inEvt) {
    //~ if (inEvt->getType() == EVT_RESP && inEvt->getFeedback() == EVT_OK && !fGameDataReceived)
    //~ {
      //~ // download latest game data
      //~ mStream.Reset();
      //~ mStream.AssertStreamEmpty();
      //~ mStream.Write<MessageID>(ID_FETCH_GAME_DATA);
      //~ mPeer->Send(&mStream, HIGH_PRIORITY, RELIABLE, 0, mServerAddr, false);
//~
      //~ fGameDataReceived = true;
    //~ }

		return true;
	}
	bool NetworkManager::evtLogout(Event* inEvt) {
	  /*if (fOnline)
	    disconnect();*/

    mLog->debugStream() << "handling local evt connected";

		return true;
	}

	bool NetworkManager::dispatchToServer(Event* inEvt) {

		//~ if (!fOnline)
			//~ return true;
//~
		//~ if (inEvt->getType() == EVT_RESP || inEvt->isLocal())
			//~ return true;
//~
		//~ mStream.Reset();
		//~ mPktProcessor->dumpEvent(inEvt, mStream);
//~
		//~ //mLog->infoStream() << "sending pkt to server data with length " << mStream.GetNumberOfBytesUsed();
		//~ mPeer->Send(&mStream, HIGH_PRIORITY, RELIABLE, 0, mServerAddr, false);
//~
		//~ mStream.Reset();
		//~ mStream.AssertStreamEmpty();

		return true;
	}




	void NetworkManager::update() {
/*
		if (!mPeer)
			return;

		mEvent = mPeer->Receive();

		while (mEvent) {
      mLog->debugStream() << "received a Event with id " << (int)mPktProcessor->getEventIdentifier(mEvent);
			// the hideous unreadability of the following line is due to
			// aggressive optimization. what it basically does is it retrieves
			// our Event handler from the map, then dereferences it and
			// passes it our Event
			if (mPktHandlers.find(mPktProcessor->getEventIdentifier(mEvent)) != mPktHandlers.end())
				(this->*(mPktHandlers.find(mPktProcessor->getEventIdentifier(mEvent))->second))(mEvent);

			mPeer->DeallocateEvent(mEvent);
			mEvent = 0;
		}

		//if (!fOnline)
		//	return;

		processEvents();*/
	}

#if 0 // __DISABLED__ no longer usign raknet
	void NetworkManager::gameDataReceived(Event* inPkt) {
    using std::string;
    using std::vector;

    mLog->infoStream() << "received game data, populating Resource Manager...";

    BitStream lStream(inPkt->data, inPkt->length, false);
		unsigned char lPktId = mPktProcessor->getEventIdentifier(inPkt);

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

    std::cout << "Event size: "<< inPkt->length << ", compressed stream size: " << buflen << ", raw stream size: " << raw.size() << "\n";
    //std::cout << "Uncompressed puppet data: " << raw2str << "\n";

    std::istringstream datastream(raw2str);
    GameManager::getSingleton().getResMgr().populate(datastream);
    datastream.clear();

    free(buf);
    encoded.clear();
    raw.clear();
    free(sum);


	}

	void NetworkManager::puppetDataReceived(Event* inPkt) {
    using std::string;
    using std::vector;

    BitStream lStream(inPkt->data, inPkt->length, false);
		unsigned char lPktId = mPktProcessor->getEventIdentifier(inPkt);

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

    std::cout << "Event size: "<< inPkt->length << ", compressed stream size: " << buflen << ", raw stream size: " << raw.size() << "\n";
    //std::cout << "Uncompressed puppet data: " << raw2str << "\n";

    std::istringstream datastream(raw2str);
    GameManager::getSingleton().getResMgr().puppetsFromStream(datastream);
    datastream.clear();

    list<CPuppet*> lPuppets = GameManager::getSingleton().getResMgr().getPuppets();
    list<CPuppet*>::iterator lPuppet;
    for (lPuppet = lPuppets.begin(); lPuppet != lPuppets.end(); ++lPuppet)
      Combat::getSingletonPtr()->registerPuppet(*lPuppet);

		{
			// notify components that we received puppet data
			mEvtMgr->hook(mEvtMgr->createEvt("CreatePuppets", true));
		}

    free(buf);
    encoded.clear();
    raw.clear();
    free(sum);
	}

  void NetworkManager::passDrawSpells(Event* inPkt) {
    Combat::getSingleton().pktDrawSpells(inPkt);
  }
#endif // __DISABLED__
}
