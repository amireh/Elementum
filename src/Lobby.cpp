#include "Lobby.h"
#include "Intro.h"

using namespace Ogre;
namespace Pixy
	{

	
	Lobby* Lobby::mLobby;

	GAME_STATE Lobby::getId() const { return STATE_LOBBY; }
		
	void Lobby::enter( void ) {
		mGfxEngine = GfxEngine::getSingletonPtr();
		mUIEngine = UIEngine::getSingletonPtr();
		mUISystem = &CEGUI::System::getSingleton();
	}

	void Lobby::exit( void ) {
		mUIEngine->cleanup();
		mGfxEngine->cleanup();
	}

	void Lobby::keyPressed( const OIS::KeyEvent &e )
	{
		
		 mUISystem->injectKeyDown(e.key);
		 mUISystem->injectChar(e.text);
		 
	}
	
	void Lobby::keyReleased( const OIS::KeyEvent &e ) {
		
		 mUISystem->injectKeyUp(e.key);
		 
		if( e.key == OIS::KC_ESCAPE ) {
			this->requestShutdown();
		}
		
	}
	
	void Lobby::mouseMoved( const OIS::MouseEvent &e )
	{
		mUISystem->injectMouseMove(e.state.X.rel, e.state.Y.rel);
	}
	
	void Lobby::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
		mUISystem->injectMouseButtonDown(convertButton(id));
		
	}
	
	void Lobby::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
		mUISystem->injectMouseButtonUp(convertButton(id));
	}
		
	void Lobby::pause( void ) {
		//mIntroOverlay->hide();
	}

	void Lobby::resume( void ) {
		//mIntroOverlay->hide();
	}

	void Lobby::update( unsigned long lTimeElapsed ) {
				
	}
		
	Lobby* Lobby::getSingletonPtr( void ) {
		if( !mLobby ) {
		    mLobby = new Lobby();
		}

		return mLobby;
	}

		
} // end of namespace
