#include "NetworkManager.h"

#include "GameManager.h"
#include "Archiver.h"
#include "CResourceManager.h"
#include <boost/filesystem.hpp>

namespace Pixy {

	NetworkManager* NetworkManager::mInstance = NULL;

	NetworkManager::NetworkManager()
  : io_service_(GameManager::getSingleton().getIOService()),
    work_(io_service_),
    timer_(io_service_),
    fOnline(false),
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


		if (mLog) {
      mLog->infoStream() << "shutting down";
			delete mLog;
    }

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

	bool NetworkManager::connect() {
    if (fOnline)
	    return true;

    boost::thread(boost::bind(&NetworkManager::doConnect, this));

		return true;
	}

  void NetworkManager::doConnect()
  {
    mLog->infoStream() << "Connecting to server";

   // Build hosts list
    using boost::filesystem::exists;
    using boost::filesystem::path;

    path lPath = path(GameManager::getSingleton().getCfgPath()) / std::string("hosts.txt");

    std::vector<std::string> mHosts;
    if (exists(lPath)) {
      std::ifstream lMirrorsFile(lPath.c_str());
      if (lMirrorsFile.is_open() && lMirrorsFile.good()) {
        std::string lMirror;
        while (lMirrorsFile.good()) {
          getline(lMirrorsFile, lMirror);
          // TODO: some sanity checks on the mirror url
          if (!lMirror.empty())
            mHosts.push_back(lMirror);
        }
        mLog->infoStream() << "registered " << mHosts.size() << " patch mirrors";
        lMirrorsFile.close();
      }
    }

    // add hardcoded/fallback hosts
		mHosts.push_back("phantom.shroom-studios.com");

    conn_.reset(new Connection(io_service_));

    bool _connected = false;
    std::string _port = SERVER_PORT;
    for (std::vector<std::string>::const_iterator lHost = mHosts.begin();
      lHost != mHosts.end();
      ++lHost)
    {
      mLog->infoStream() << "attempting to connect to host " << *lHost << ":" << _port;
      if (conn_->connect(*lHost, _port) ) {
        _connected = true;
        break;
      }
    }

    if (!_connected)
    {
      mLog->errorStream() << "couldnt start the conn .. ";
      Event e(EventUID::Connected, EventFeedback::Error);
      EventManager::getSingleton().hook(e);
      return;
    }

    try {
      conn_->start();
    } catch (std::exception& e) {
      mLog->errorStream() << "a connection error occured: " << e.what();
      Event evt(EventUID::Connected, EventFeedback::Error);
      EventManager::getSingleton().hook(evt);
      return;
    }

    conn_->get_dispatcher().bind(EventUID::Unassigned, this, &NetworkManager::onInbound);
    conn_->get_dispatcher().bind(EventUID::SyncGameData, this, &NetworkManager::onSyncGameData);

		{
			// notify components that we're connected
      Event evt(EventUID::Connected, EventFeedback::Ok);
      EventManager::getSingleton().hook(evt);

      // sync the game data
      send(Event(EventUID::SyncGameData));
		}

		fOnline = true;

    mLog->infoStream() << "connected";
  }

	bool NetworkManager::disconnect() {
    if (!fOnline)
      return true;

    Event evt(EventUID::Logout);
    send(evt);
    EventManager::getSingleton().hook(evt);

    mLog->infoStream() << "Disconnecting from server";

    conn_->stop();
    conn_.reset();

		fOnline = false;
		return true;
	}

  void NetworkManager::send(const Event& inEvt) {
    assert(isConnected());

    mLog->debugStream() << "sending an event " << (int)inEvt.UID;
    //inEvt.dump();
    Event clone(inEvt);
    conn_->send(clone);
  }

	void NetworkManager::onInbound(const Event& inEvt) {
    EventManager::getSingleton().hook(inEvt);
	}


  bool NetworkManager::isConnected() const
  {
    return fOnline;
  }

  void NetworkManager::onSyncGameData(const Event& evt)
  {
    using std::string;
    using std::vector;

    mLog->infoStream() << "received game data, populating Resource Manager...";

    std::string senc = evt.getProperty("Data");

    vector<unsigned char> encoded(senc.begin(), senc.end());
    vector<unsigned char> raw;

    if (Archiver::decodeLzma(raw, encoded, evt.Rawsize) != 1) {
      std::cerr << "decoding failed!! \n";
    }

    string raw2str(raw.begin(), raw.end());

    std::istringstream datastream(raw2str);

    GameManager::getSingleton().getResMgr().clearDatabase();
    GameManager::getSingleton().getResMgr().populate(datastream);

    Event notice(EventUID::GameDataSynced);
    EventManager::getSingleton().hook(notice);
  }

}
