/*
 *  UIEngine.cpp
 *  Elementum
 *
 *  Created by Ahmad Amireh on 2/11/10.
 *  Copyright 2010 JU. All rights reserved.
 *
 */

#include "UIEngine.h"
#include "EventManager.h"
// CEGUI
#if PIXY_PLATFORM == PIXY_PLATFORM_APPLE
#include <CEGUIBase/CEGUI.h>
#include <CEGUIBase/CEGUISystem.h>
#include <CEGUIBase/CEGUISchemeManager.h>
//#include "CEGUIBase/ScriptingModules/LuaScriptModule/CEGUILua.h"
#include "CEGUIBase/RendererModules/Ogre/CEGUIOgreRenderer.h"
#else
#include <CEGUI/CEGUI.h>
#include <CEGUI/CEGUISystem.h>
#include <CEGUI/CEGUISchemeManager.h>
//#include "CEGUI/ScriptingModules/LuaScriptModule/CEGUILua.h"
#include "CEGUI/RendererModules/Ogre/CEGUIOgreRenderer.h"
#endif
#include <Ogre.h>
//#include "Combat.h"

namespace Pixy {
	UIEngine* UIEngine::_myUIEngine = NULL;

	UIEngine* UIEngine::getSingletonPtr() {
		if( !_myUIEngine ) {
		    _myUIEngine = new UIEngine();
		}

		return _myUIEngine;
	}

	UIEngine::UIEngine()  {
		mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, "UIEngine");
		mLog->infoStream() << "firing up";
		fSetup = false;
	}

	UIEngine::~UIEngine() {
		mLog->infoStream() << "shutting down";

		if (fSetup) {
			mLog->debugStream() << "destroying all windows";
			CEGUI::WindowManager::getSingleton().destroyAllWindows();

			mLog->debugStream() << "destroying system";
			mOgreRenderer->destroySystem();

			mOgreRenderer = NULL; mUISystem = NULL;
			delete mLog; mLog = 0;
			fSetup = false;
		}
	}

	bool UIEngine::cleanup() {
		return true;
	}

	CEGUI::MouseButton UIEngine::convertButton(OIS::MouseButtonID buttonID)
	{
		switch (buttonID)
		{
			case OIS::MB_Left:
				return CEGUI::LeftButton;

			case OIS::MB_Right:
				return CEGUI::RightButton;

			case OIS::MB_Middle:
				return CEGUI::MiddleButton;

			default:
				return CEGUI::LeftButton;
		}
	}

	const char* UIEngine::getDataPathPrefix() const
	{
		static char dataPathPrefix[PATH_MAX];

		return dataPathPrefix;
	}

	bool UIEngine::setup() {
		if (fSetup)
			return true;

		mLog->infoStream() << "Setting up";

		mEvtMgr = EventManager::getSingletonPtr();

		mLog->infoStream() << "initting CEGUI system & CEGUIOgreRenderer.";

		if (CEGUI::System::getSingletonPtr())
			throw CEGUI::InvalidRequestException("OgreRenderer::bootstrapSystem: "
										  "CEGUI::System object is already initialised.");


		CEGUI::DefaultLogger* lUILog = new CEGUI::DefaultLogger();
		std::ostringstream lUILogPath;
		lUILogPath << PROJECT_LOG_DIR << "/CEGUI.log";
		lUILog->setLogFilename(lUILogPath.str(), true);

		mOgreRenderer = &CEGUI::OgreRenderer::bootstrapSystem();
		mUISystem = &CEGUI::System::getSingleton();

		// load resources
		loadResources();

		// load GUI scheme

		CEGUI::SchemeManager::getSingleton().create( "TaharezLook.scheme" );
		CEGUI::SchemeManager::getSingleton().create( "VanillaSkin.scheme" );
		CEGUI::SchemeManager::getSingleton().create( "WindowsLook.scheme" );


		// load font and setup default if not loaded via scheme
		//CEGUI::FontManager::getSingleton().create("DejaVuSans-10.font");

		// set up defaults
		CEGUI::System::getSingleton().setDefaultMouseCursor("TaharezLook", "MouseArrow");
		//CEGUI::System::getSingleton().setDefaultFont("DejaVuSans-10");

    // Create default ToolTip item
    CEGUI::System::getSingleton().setDefaultTooltip( (CEGUI::utf8*)"TaharezLook/Tooltip" );
    CEGUI::Tooltip* ttip = CEGUI::System::getSingleton().getDefaultTooltip();
    ttip->setMaxSize(CEGUI::UVector2(CEGUI::UDim(0, 600), CEGUI::UDim(0, 400)));

		mLog->infoStream() << "Set up!";

		//Combat::getSingletonPtr()->updateMe(getSingletonPtr());

		fSetup = true;
		return true;
	}


	bool UIEngine::loadResources() {

		mLog->infoStream() << "Loading resources...";
		using namespace Ogre;
		ResourceGroupManager& rgm = ResourceGroupManager::getSingleton();

		// add resource groups that we use
		rgm.createResourceGroup("imagesets");
		rgm.createResourceGroup("fonts");
		rgm.createResourceGroup("layouts");
		rgm.createResourceGroup("schemes");
		rgm.createResourceGroup("looknfeels");
		rgm.createResourceGroup("schemas");

		// add CEGUI sample framework datafile dirs as resource locations
		ResourceGroupManager::getSingleton().addResourceLocation("./", "FileSystem");

		char* dataPathPrefix = (char*)malloc(sizeof(char) * (strlen(PROJECT_ROOT) + 1 + strlen(PROJECT_RESOURCES) + 1 + strlen("ui") + 1));
		sprintf(dataPathPrefix, "%s%s/ui", PROJECT_ROOT, PROJECT_RESOURCES);
		char resourcePath[PATH_MAX];

		// for each resource type, set a resource group directory
		sprintf(resourcePath, "%s/%s", dataPathPrefix, "schemes/");
		ResourceGroupManager::getSingleton().addResourceLocation(resourcePath, "FileSystem", "schemes");
		sprintf(resourcePath, "%s/%s", dataPathPrefix, "imagesets/");
		ResourceGroupManager::getSingleton().addResourceLocation(resourcePath, "FileSystem", "imagesets");
		sprintf(resourcePath, "%s/%s", dataPathPrefix, "fonts/");
		ResourceGroupManager::getSingleton().addResourceLocation(resourcePath, "FileSystem", "fonts");
		sprintf(resourcePath, "%s/%s", dataPathPrefix, "layouts/");
		ResourceGroupManager::getSingleton().addResourceLocation(resourcePath, "FileSystem", "layouts");
		sprintf(resourcePath, "%s/%s", dataPathPrefix, "looknfeel/");
		ResourceGroupManager::getSingleton().addResourceLocation(resourcePath, "FileSystem", "looknfeels");
		sprintf(resourcePath, "%s/%s", dataPathPrefix, "xml_schemas/");
		ResourceGroupManager::getSingleton().addResourceLocation(resourcePath, "FileSystem", "schemas");

		free(dataPathPrefix);

		// set the default resource groups to be used
		CEGUI::Imageset::setDefaultResourceGroup("imagesets");
		CEGUI::Font::setDefaultResourceGroup("fonts");
		CEGUI::Scheme::setDefaultResourceGroup("schemes");
		CEGUI::WidgetLookManager::setDefaultResourceGroup("looknfeels");
		CEGUI::WindowManager::setDefaultResourceGroup("layouts");

		// setup default group for validation schemas
		CEGUI::XMLParser* parser = CEGUI::System::getSingleton().getXMLParser();
		if (parser->isPropertyPresent("SchemaDefaultResourceGroup"))
			parser->setProperty("SchemaDefaultResourceGroup", "schemas");

		//ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
		ResourceGroupManager::getSingleton().initialiseResourceGroup("schemes");
		ResourceGroupManager::getSingleton().initialiseResourceGroup("imagesets");
		ResourceGroupManager::getSingleton().initialiseResourceGroup("fonts");
		ResourceGroupManager::getSingleton().initialiseResourceGroup("layouts");
		ResourceGroupManager::getSingleton().initialiseResourceGroup("looknfeels");
		ResourceGroupManager::getSingleton().initialiseResourceGroup("schemas");

		// load LUA script
		return true;
	}


	void UIEngine::update( unsigned long lTimeElapsed ) {
		mUISystem->injectTimePulse(lTimeElapsed * 0.001f);
		processEvents();
	}

	void UIEngine::mouseMoved( const OIS::MouseEvent &e )
	{
		mUISystem->injectMouseMove(e.state.X.rel, e.state.Y.rel);
	}

	void UIEngine::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
		mUISystem->injectMouseButtonDown(convertButton(id));
	}

	void UIEngine::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
		mUISystem->injectMouseButtonUp(convertButton(id));
	}

	void UIEngine::keyReleased( const OIS::KeyEvent &e ) {

	}
	void UIEngine::keyPressed( const OIS::KeyEvent &e ) {

	}

  void UIEngine::setMargin(CEGUI::Window* win, CEGUI::UBox& margin) {
    using CEGUI::UDim;
    //win->setMargin(CEGUI::UBox(UDim(0,0),UDim(0,0),UDim(0,0),UDim(0,5)));
    win->setMargin(margin);
  }

  void UIEngine::refreshSize() {
    using namespace CEGUI;
    Window* sp = CEGUI::WindowManager::getSingletonPtr()->getWindow("Elementum/Scenes/Combat/SpellPanel/Player");
    UVector2 sz(sp->getSize());
    sp->setSize(UVector2(UDim(0,0),UDim(0,0)));
    sp->setSize(sz);
  }

}
