#include "PixyPlatform.h"

#if PIXY_PLATFORM == PIXY_PLATFORM_APPLE
# include "AppDelegate.h"
#endif

#include "GameManager.h"
#include "Intro.h"

using namespace Pixy;
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT ) {
#else
	int main( int argc, char **argv ) {
#endif
// Apple
#if (OGRE_PLATFORM == OGRE_PLATFORM_APPLE) && __LP64__
  	NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];

    mAppDelegate = [[AppDelegate alloc] init];
    [[NSApplication sharedApplication] setDelegate:mAppDelegate];
  	int retVal = NSApplicationMain(argc, (const char **) argv);

  	[pool release];

  	return retVal;
#else

// Win32 && Linux
		GameManager *gameManager = GameManager::getSingletonPtr();
		try {
			// Initialise the game and switch to the first state
			gameManager->startGame(/*argc, argv*/);

		}
		catch ( Ogre::Exception& ex ) {
# if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
			MessageBox( NULL, ex.getFullDescription().c_str(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL );
# else
			std::cerr << "An exception has occured: " << ex.getFullDescription();
# endif
		} catch (std::exception& e) {
			Ogre::String errMsg = e.what();
			log4cpp::Category::getInstance(PIXY_LOG_CATEGORY).errorStream() << errMsg;
		}

		delete gameManager;
		return 0;
#endif
	}

