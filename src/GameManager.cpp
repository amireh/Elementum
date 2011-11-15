/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#include "GameManager.h"
#include "PixyUtility.h"
#include "GameState.h"
#include "EventManager.h"
#include "Intro.h"
//#include "Lobby.h"
#include "Combat.h"
#include "log4cpp/PixyLogLayout.h"
#include <boost/filesystem.hpp>

#include "UIEngine.h"
#include "GfxEngine.h"
#include "FxEngine.h"
#include "ScriptEngine.h"
#include "NetworkManager.h"
#include "InputManager.h"
#include "EntityManager.h"
#include "ogre/OgreSdkTrays.h"
#include "binreloc/binreloc.h"
//#include "SfxEngine.h"
//#include "PhyxEngine.h"
using namespace Ogre;

namespace Pixy
{
	GameManager* GameManager::mGameManager;

	GameManager::GameManager() :
  mIOService(),
  mWork(mIOService),
  mWorker(0),
	mRoot(0),
  mEntityMgr(0),
	mInputMgr(0),
  mLog(0),
	fShutdown(false),
  fSetup(false) {
	}

	GameManager::~GameManager() {
	}

  std::string const& GameManager::getRootPath() const {
    return mRootPath;
  };
  std::string const& GameManager::getResPath() const {
    return mResPath;
  };
  std::string const& GameManager::getBinPath() const {
    return mBinPath;
  };
  std::string const& GameManager::getCfgPath() const {
    return mCfgPath;
  }
  std::string const& GameManager::getLogPath() const {
    return mLogPath;
  }

  boost::asio::io_service& GameManager::getIOService() {
    return mIOService;
  }

  void GameManager::loadRenderSystems()
  {
    //Root* ogreRoot = Root::getSingletonPtr();
    bool rendererInstalled = false;
    std::string lPluginsPath;
#if PIXY_PLATFORM == PIXY_PLATFORM_APPLE
      lPluginsPath = macBundlePath() + "/Contents/Plugins/";
#elif PIXY_PLATFORM == PIXY_PLATFORM_WIN32
      lPluginsPath = mBinPath + "//";
#else
      lPluginsPath = "./";
#endif
#if PIXY_PLATFORM == PIXY_PLATFORM_WIN32
/*    HRESULT hr;
    DWORD dwDirectXVersion = 0;
    TCHAR strDirectXVersion[10];

    hr = GetDXVersion( &dwDirectXVersion, strDirectXVersion, 10 );
    if( SUCCEEDED(hr) ) {
      ostringstream dxinfoStream;
      dxinfoStream << "DirectX version: " << strDirectXVersion;
      //LogManager::getSingleton().logMessage(dxinfoStream.str());
      mLog->infoStream() << dxinfoStream.str();
*/
      //if(dwDirectXVersion >= 0x00090000) {
        try {
          mRoot->loadPlugin(mBinPath + "RenderSystem_Direct3D9");
          mRoot->setRenderSystem(mRoot->getRenderSystemByName("Direct3D9 Rendering Subsystem"));
          rendererInstalled = true;
        } catch (Ogre::Exception& e) {
          mLog->errorStream() << "Unable to create D3D9 RenderSystem: " << e.getFullDescription();
        } catch(std::exception& e) {
          mLog->errorStream() << "Unable to create D3D9 RenderSystem: " << e.what();
        }
      //}
//    }
#endif
    try {
      mRoot->loadPlugin(lPluginsPath + "RenderSystem_GL");
      if (!rendererInstalled) {
        mRoot->setRenderSystem(mRoot->getRenderSystemByName("OpenGL Rendering Subsystem"));
        rendererInstalled = true;
      }
    }
    catch(Ogre::Exception& e) {
      mLog->errorStream() << "Unable to create OpenGL RenderSystem: " << e.getFullDescription();
    }

    try {
      mRoot->loadPlugin("./Plugin_CgProgramManager");
    }
    catch(Ogre::Exception& e) {
      mLog->errorStream() << "Unable to create CG Program manager RenderSystem: " << e.getFullDescription();
    }
  }

  void GameManager::_setup() {
    resolvePaths();

    // init logger
    initLogger();

    mWorker = new boost::thread(boost::bind(&boost::asio::io_service::run, &mIOService));

    // set up Ogre paths
    using boost::filesystem::path;
    std::string lPathOgreRes, lPathOgrePlugins, lPathOgreCfg, lPathOgreLog;
    std::string lSuffix = "";
#if PIXY_PLATFORM == PIXY_PLATFORM_WIN32
    lSuffix = "win32";
#elif PIXY_PLATFORM == PIXY_PLATFORM_APPLE
    lSuffix = "osx";
#else
    lSuffix = "linux";
#endif
    lPathOgreRes = path(path(mCfgPath) / std::string("resources_" + lSuffix+ ".cfg")).make_preferred().string();
    lPathOgrePlugins = path(path(mCfgPath) / std::string("plugins_" + lSuffix + ".cfg")).make_preferred().string();
    lPathOgreCfg = path(path(mCfgPath) / "ogre.cfg").make_preferred().string();
    lPathOgreLog = path(path(mLogPath) / "Ogre.log").make_preferred().string();

    mRoot = OGRE_NEW Root(lPathOgrePlugins, lPathOgreCfg, lPathOgreLog);
    if (!mRoot) {
    	throw Ogre::Exception( Ogre::Exception::ERR_INTERNAL_ERROR,
    						  "Error - Couldn't initalize OGRE!",
    						  "Vertigo - Error");
    }
    //loadRenderSystems();

    // Setup and configure game
    if( !this->configureGame() ) {
        // If game can't be configured, throw exception and quit application
        throw Ogre::Exception( Ogre::Exception::ERR_INTERNAL_ERROR,
    						  "Error - Couldn't Configure Renderwindow",
    						  "Vertigo - Error" );
        return;
    }

    // Setup input & register as listener
    mInputMgr = InputManager::getSingletonPtr();
    mRenderWindow = mRoot->getAutoCreatedWindow();
    mInputMgr->initialise( mRenderWindow );
    WindowEventUtilities::addWindowEventListener( mRenderWindow, this );

    // load initial resources
    this->setupResources(lPathOgreRes);

    mInputMgr->addKeyListener( this, "GameManager" );
    mInputMgr->addMouseListener( this, "GameManager" );

    mEntityMgr = new EntityManager();

    NetworkManager::getSingletonPtr();
    EventManager::getSingletonPtr();
    GfxEngine::getSingletonPtr()->setup();
    UIEngine::getSingletonPtr()->setup();
    FxEngine::getSingletonPtr()->setup();
    ScriptEngine::getSingletonPtr()->setup();

    ScriptEngine::getSingletonPtr()->runScript("pixy.lua");
    ScriptEngine::getSingletonPtr()->passToLua("Pixy.onEnter", 0);

    // Change to first state
    this->changeState( Combat::getSingletonPtr() );
    //~ this->changeState( Intro::getSingletonPtr() );

    // lTimeLastFrame remembers the last time that it was checked
    // we use it to calculate the time since last frame

    lTimeLastFrame = 0;
    lTimeCurrentFrame = 0;
    lTimeSinceLastFrame = 0;

    mRoot->getTimer()->reset();

    fSetup = true;
  }

	void GameManager::startGame(/*int argc, char** argv*/) {

    this->_setup();

		// main game loop
		while( !fShutdown ) {
      _update();
		}

    this->_cleanup();
	}

  void GameManager::_cleanup()
  {
    // Clean up all the states
		while( !mStates.empty() ) {
		    mStates.back()->exit();
		    mStates.pop_back();
		}

    if (fSetup)
    {
      if (mLog)
        mLog->infoStream() << "cleaning up the scripts";

      // make the scripts clean up
      ScriptEngine::getSingletonPtr()->passToLua("Pixy.onExit", 0);

      if (mLog)
        mLog->infoStream() << "tearing down all engines";

      delete GfxEngine::getSingletonPtr();
      delete FxEngine::getSingletonPtr();
      //delete SfxEngine::getSingletonPtr();
      //delete PhyxEngine::getSingletonPtr();
      delete UIEngine::getSingletonPtr();
      delete ScriptEngine::getSingletonPtr();
      delete EventManager::getSingletonPtr();
      delete NetworkManager::getSingletonPtr();
    }

    if (mEntityMgr)
      delete mEntityMgr;
    mEntityMgr = 0;

		if( mInputMgr )
      delete mInputMgr;
    mInputMgr = 0;

		if( mRoot )
      delete mRoot;
    mRoot = 0;

		if (mLog) {
      mLog->infoStream() << "++++++ Elementum cleaned up successfully ++++++";
		  delete mLog;

      log4cpp::Category::shutdown();
    }
    mLog = 0;

    if (mWorker)
    {
      mIOService.stop();
      mWorker->join();
      delete mWorker;
    }
    mWorker = 0;
  }

	Ogre::RenderWindow* GameManager::getRenderWindow() const {
    return mRenderWindow;
	}

  void GameManager::_update() {
	  // calculate time since last frame and remember current time for next frame
    lTimeCurrentFrame = mRoot->getTimer()->getMilliseconds();
    lTimeSinceLastFrame = lTimeCurrentFrame - lTimeLastFrame;
    lTimeLastFrame = lTimeCurrentFrame;

    // update input manager
    mInputMgr->capture();

    // cpdate current state
    mStates.back()->update( lTimeSinceLastFrame );

		WindowEventUtilities::messagePump();

		// render next frame
	  mRoot->renderOneFrame();
  }

	bool GameManager::configureGame() {

		// Load config settings from ogre.cfg
		if( !mRoot->restoreConfig() ) {
		    // If there is no config file, show the configuration dialog
		    if( !mRoot->showConfigDialog() ) {
		        return false;
		    }
		}

		// Initialise and create a default rendering window
		mRenderWindow = mRoot->initialise( true, "Elementum" );

		// Initialise resources
		//ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

		// Create needed scenemanagers
		Ogre::SceneManager *mSceneMgr = mRoot->createSceneManager( "DefaultSceneManager", "LoadingScene" );
		Ogre::Camera *mCamera = mSceneMgr->createCamera("LoadingCamera");
		mRenderWindow->addViewport(mCamera, -1);

		return true;
	}

	void GameManager::setupResources(std::string inPath) {

		// Load resource paths from config file
		ConfigFile cf;
		cf.load( inPath );

		// Go through all settings in the file
		ConfigFile::SectionIterator itSection = cf.getSectionIterator();

		String sSection, sType, sArch;
		while( itSection.hasMoreElements() ) {
		    sSection = itSection.peekNextKey();

		    ConfigFile::SettingsMultiMap *mapSettings = itSection.getNext();
		    ConfigFile::SettingsMultiMap::iterator itSetting = mapSettings->begin();
		    while( itSetting != mapSettings->end() ) {
		        sType = itSetting->first;
		        sArch = itSetting->second;
#if PIXY_PLATFORM == PIXY_PLATFORM_APPLE
				ResourceGroupManager::getSingleton().addResourceLocation( String(macBundlePath() + "/" + sArch), sType, sSection);
#else
				ResourceGroupManager::getSingleton().addResourceLocation( sArch, sType, sSection);
#endif

		        ++itSetting;
		    }
		}
		// Initialise resources
		ResourceGroupManager::getSingleton().initialiseResourceGroup("Bootstrap");
		OgreBites::SdkTrayManager *mTrayMgr =
		  new OgreBites::SdkTrayManager("Elementum/Loader", mRenderWindow, InputManager::getSingletonPtr()->getMouse(), 0);
		//mTrayMgr->showAll();
		mTrayMgr->showLoadingBar(1,1, 1);
		//ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
		ResourceGroupManager::getSingleton().initialiseResourceGroup("General");
		ResourceGroupManager::getSingleton().initialiseResourceGroup("scripts");
		ResourceGroupManager::getSingleton().initialiseResourceGroup("Models");
		//~ ResourceGroupManager::getSingleton().loadResourceGroup("Models");
		this->loadConfig();
		mTrayMgr->hideLoadingBar();
		delete mTrayMgr;

		//mRenderWindow->removeViewport(-1);
		//mRoot->getSceneManager("LoadingScene")->destroyCamera("LoadingCamera");
		//mRoot->destroySceneManager(mRoot->getSceneManager("LoadingScene"));

	}

	void GameManager::changeState( GameState *inState ) {

		// Cleanup the current state
		if( !mStates.empty() ) {

        //~ Event evt(EventUID::ChangingState);
        //~ EventManager::getSingleton().hook(evt);
        //~ for (int i=0; i < 5; ++i)
          //~ mStates.back()->update(1);

		    mStates.back()->exit();
		    mStates.pop_back();
		}

		// Store and init the new state
		mCurrentState = inState;
		mStates.push_back( inState );
		mStates.back()->enter();

		// reset our frame timer to eliminate any frame bursts
		//mRoot->getTimer()->reset();
		//lTimeLastFrame = 0;
	}

	void GameManager::pushState( GameState *inState ) {

		// Pause current state
		if( !mStates.empty() ) {
		    mStates.back()->pause();
		}

		mCurrentState = inState;

		// Store and init the new state
		mStates.push_back( inState );
		mStates.back()->enter();

		// reset our frame timer to eliminate any frame bursts
		//mRoot->getTimer()->reset();
		//lTimeLastFrame = 0;
	}

	void GameManager::popState() {
		// Cleanup the current state
		if( !mStates.empty() ) {
		    mStates.back()->exit();
		    mStates.pop_back();
		}

		// Resume previous state
		if( !mStates.empty() ) {
		    mCurrentState = mStates.back();
		    mStates.back()->resume();
		}

		// reset our frame timer to eliminate any frame bursts
		//mRoot->getTimer()->reset();
		//lTimeLastFrame = 0;
	}

	void GameManager::requestShutdown() {
		fShutdown = true;
	}

	bool GameManager::keyPressed( const OIS::KeyEvent &e ) {
		// Call keyPressed of current state
		mStates.back()->keyPressed( e );

		return true;
	}

	bool GameManager::keyReleased( const OIS::KeyEvent &e ) {
		// Call keyReleased of current state
		mStates.back()->keyReleased( e );

		return true;
	}

	bool GameManager::mouseMoved( const OIS::MouseEvent &e ) {
		// Call mouseMoved of current state
		mStates.back()->mouseMoved( e );

		return true;
	}

	bool GameManager::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
		// Call mousePressed of current state
		mStates.back()->mousePressed( e, id );

		return true;
	}

	bool GameManager::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
		// Call mouseReleased of current state
		mStates.back()->mouseReleased( e, id );

		return true;
	}

	GameManager* GameManager::getSingletonPtr() {
		if( !mGameManager ) {
		    mGameManager = new GameManager();
		}

		return mGameManager;
	}

	GameManager& GameManager::getSingleton() {
		return *getSingletonPtr();
	}

	GameState* GameManager::getCurrentState() {
		return mCurrentState;
	}

  void GameManager::resolvePaths() {
    using boost::filesystem::path;
    using boost::filesystem::is_directory;
    using boost::filesystem::create_directories;
    using boost::filesystem::create_directory;
    using boost::filesystem::exists;

    bool dontOverride = false;

    std::cout << "Resolving paths...\n";

    // locate the binary and build its path
#if PIXY_PLATFORM == PIXY_PLATFORM_LINUX
    std::cout << "Platform: Linux\n";
    // use binreloc and boost::filesystem to build up our paths
    int brres = br_init(0);
    if (brres == 0) {
      std::cerr << "binreloc could not be initialised\n";
    }
    char *p = br_find_exe_dir(".");
    mBinPath = std::string(p);
    free(p);
    mBinPath = path(mBinPath).make_preferred().string();
#elif PIXY_PLATFORM == PIXY_PLATFORM_APPLE
    // use NSBundlePath() to build up our paths
    mBinPath = Utility::macBundlePath() + "/Contents/MacOS";
    mRootPath = Utility::macBundlePath() = "/Contents";
    mResPath = Utility::macBundlePath() + "/Contents/Resources";
    mCfgPath = Utility::macBundlePath() + "/Contents/Resources/config";
    mLogPath = Utility::macBundlePath() + "/Contents/Logs";

    dontOverride = true;
#else
    // use GetModuleFileName() and boost::filesystem to build up our paths on Windows
    TCHAR szPath[MAX_PATH];

    if( !GetModuleFileName( NULL, szPath, MAX_PATH ) )
    {
        printf("Cannot install service (%d)\n", GetLastError());
        throw std::runtime_error("could not get runpath!");
    }

    mBinPath = std::string(szPath);
    mBinPath = path(mBinPath).remove_filename().make_preferred().string();
#endif

    // root is PIXY_DISTANCE_FROM_ROOT directories up from the binary's
    path lRoot = path(mBinPath);
    for (int i=0; i < /*PIXY_DISTANCE_FROM_ROOT*/ 1; ++i) {
      lRoot = lRoot.remove_leaf();
    }


    mRootPath = lRoot.make_preferred().string();
    if (!dontOverride) {
      mResPath = (path(mRootPath) / PROJECT_RESOURCES).make_preferred().string();
      mCfgPath = (path(mResPath) / "config").make_preferred().string();
      mLogPath = (path(mRootPath) / path(PROJECT_LOG_DIR)).make_preferred().string();
    }

    if (!is_directory(path(mLogPath)))
    {
      try {
        if (!create_directories(path(mLogPath)))
        {
          throw std::runtime_error("Couldn't create log directory!");
        }
      } catch(...) {
        throw std::runtime_error("Couldn't create log directory!");
      }
    }

    std::cout << "Root path: " <<  mRootPath << "\n";
    std::cout << "Binary path: " <<  mBinPath << "\n";
    std::cout << "Config path: " <<  mCfgPath << "\n";
    std::cout << "Resources path: " <<  mResPath << "\n";
    std::cout << "Log path: " <<  mLogPath << "\n";

  };

	void GameManager::initLogger() {
    using boost::filesystem::path;

		std::string lLogPath = (path(mLogPath) / "Elementum.log").make_preferred().string();
		std::cout << "| Initting log4cpp logger @ " << lLogPath << "!\n";

		log4cpp::Appender* lApp = new
		log4cpp::FileAppender("FileAppender",
							  lLogPath, false);

        log4cpp::Layout* lLayout = new Pixy::PixyLogLayout();
		/* used for header logging */
		PixyLogLayout* lHeaderLayout = new PixyLogLayout();
		lHeaderLayout->setVanilla(true);

		lApp->setLayout(lHeaderLayout);

		std::string lCatName = PIXY_LOG_CATEGORY;
		log4cpp::Category* lCat = &log4cpp::Category::getInstance(lCatName);

        lCat->setAdditivity(false);
		lCat->setAppender(lApp);
		lCat->setPriority(log4cpp::Priority::DEBUG);

		lCat->infoStream() << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
		lCat->infoStream() << "\n+                        Elementum v" << ELEMENTUM_VERSION << " - Client Log                          +";
		lCat->infoStream() << "\n+                      (http://www.elementum-game.com)                        +";
		lCat->infoStream() << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";

		lApp->setLayout(lLayout);

		lApp = 0;
		lCat = 0;
		lLayout = 0;
		lHeaderLayout = 0;

		mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, "GameManager");
	}

	bool GameManager::shuttingDown() { return fShutdown; };

	tPixySettings& GameManager::getSettings() {
	  return mSettings;
	};

	void GameManager::loadConfig() {
	  mLog->infoStream() << "loading Vertigo config";

	  Ogre::ResourceGroupManager& mRGM = Ogre::ResourceGroupManager::getSingleton();

	  if (mRGM.resourceExists("General", "vertigo.cfg")) {
	    mLog->infoStream() << "found existing configuration, parsing...";

	    Ogre::ConfigFile *mCfg = new Ogre::ConfigFile();
	    mCfg->loadFromResourceSystem("vertigo.cfg", "General");
	    mSettings.insert(std::make_pair<std::string,std::string>(
	      "Visual Detail",
	      mCfg->getSetting("Visual Detail", Ogre::StringUtil::BLANK, "Medium")
	    ));

	    mSettings.insert(std::make_pair<std::string,std::string>(
	      "Music Enabled",
	      mCfg->getSetting("Music Enabled", Ogre::StringUtil::BLANK, "Yes")
	    ));

	    mSettings.insert(std::make_pair<std::string,std::string>(
	      "Sound Enabled",
	      mCfg->getSetting("Sound Enabled", Ogre::StringUtil::BLANK, "Yes")
	    ));

	    delete mCfg;

	  } else {
	    // default values
	    mSettings.insert(std::make_pair<std::string,std::string>("Visual Detail", "Medium"));
	    mSettings.insert(std::make_pair<std::string,std::string>("Sound Enabled", "Yes"));
	    mSettings.insert(std::make_pair<std::string,std::string>("Music Enabled", "Yes"));
	  }

    this->saveConfig();
	};

	void GameManager::saveConfig() {
    using boost::filesystem::path;
	  mLog->infoStream() << "saving Vertigo config";

	  std::string tConfigFilePath = (path(mCfgPath) / "vertigo.cfg").make_preferred().string();
	  std::ofstream of(tConfigFilePath.c_str());
	  if (!of) {
	    mLog->errorStream() << "could not write settings to " << tConfigFilePath << "!! aborting";
	    return;
	  }

	  of << "Visual Detail=" << mSettings["Visual Detail"] << std::endl;
	  of << "Music Enabled=" << mSettings["Music Enabled"] << std::endl;
	  of << "Sound Enabled=" << mSettings["Sound Enabled"] << std::endl;
	  of.close();

	};

	void GameManager::applyNewSettings(tPixySettings& inSettings) {
	  mSettings = inSettings;
	  this->saveConfig();
	  EventManager* mEvtMgr = EventManager::getSingletonPtr();
	  //~ mEvtMgr->hook(mEvtMgr->createEvt("SettingsChanged")); __DISABLED__
	};

  EntityManager& GameManager::getEntityMgr() {
    return *mEntityMgr;
  }
} // end of namespace Pixy
