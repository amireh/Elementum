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
#include <Ogre.h>
#include <Rocket/Core.h>
#include <Rocket/Controls.h>
#include <Rocket/Debugger.h>
#include "UI/SystemInterfaceOgre3D.h"
#include "UI/RenderInterfaceOgre3D.h"
#include "GfxEngine.h"
#include <algorithm>
#include <string>
#include <locale>
#include "Combat.h"

namespace Pixy {
	UIEngine* UIEngine::_myUIEngine = NULL;

	UIEngine* UIEngine::getSingletonPtr() {
		if( !_myUIEngine ) {
		    _myUIEngine = new UIEngine();
		}

		return _myUIEngine;
	}

	UIEngine::UIEngine()
  : mDocument(0),
    context(0),
    mSpellPanel(0) {
		mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, "UIEngine");
		mLog->infoStream() << "firing up";

    context = NULL;
    ogre_system = NULL;
    ogre_renderer = NULL;

    sample_path = "/home/kandie/Workspace/Projects/Elementum/Client/resources/ui/";

    BuildKeyMaps();

		fSetup = false;
	}

	UIEngine::~UIEngine() {
    destroyScene();
		mLog->infoStream() << "shutting down";

		if (fSetup) {
			mLog->debugStream() << "destroying all windows";

			delete mLog; mLog = 0;
			fSetup = false;
		}
	}

	bool UIEngine::cleanup() {
		return true;
	}

	bool UIEngine::setup() {
		if (fSetup)
			return true;

		mLog->infoStream() << "Setting up";

		mEvtMgr = EventManager::getSingletonPtr();

    createScene();

    mLog->infoStream() << "Set up!";

		//Combat::getSingletonPtr()->updateMe(getSingletonPtr());

		fSetup = true;
		return true;
	}


  void UIEngine::createScene()
  {
    //Ogre::ResourceGroupManager::getSingleton().createResourceGroup("Rocket");
    //Ogre::ResourceGroupManager::getSingleton().addResourceLocation(rocket_path.Replace("\\", "/").CString(), "FileSystem", "Rocket");

    // Rocket initialisation.
    Ogre::RenderWindow* mWindow = GfxEngine::getSingletonPtr()->getWindow();
    ogre_renderer = new RenderInterfaceOgre3D(mWindow->getWidth(), mWindow->getHeight());
    Rocket::Core::SetRenderInterface(ogre_renderer);

    ogre_system = new SystemInterfaceOgre3D();
    Rocket::Core::SetSystemInterface(ogre_system);

    Rocket::Core::Initialise();
    Rocket::Controls::Initialise();

    // Load the fonts from the path to the sample directory.
    Rocket::Core::FontDatabase::LoadFontFace("/home/kandie/Workspace/Projects/Elementum/Client/resources/ui/assets/Delicious-Roman.otf");
    Rocket::Core::FontDatabase::LoadFontFace("/home/kandie/Workspace/Projects/Elementum/Client/resources/ui/assets/Delicious-Bold.otf");
    Rocket::Core::FontDatabase::LoadFontFace("/home/kandie/Workspace/Projects/Elementum/Client/resources/ui/assets/Delicious-Italic.otf");
    Rocket::Core::FontDatabase::LoadFontFace("/home/kandie/Workspace/Projects/Elementum/Client/resources/ui/assets/Delicious-BoldItalic.otf");

    context = Rocket::Core::CreateContext("main", Rocket::Core::Vector2i(mWindow->getWidth(), mWindow->getHeight()));
    Rocket::Debugger::Initialise(context);
    //Rocket::Debugger::SetVisible(true);

    // Load the mouse cursor and release the caller's reference.
    Rocket::Core::ElementDocument* cursor = context->LoadMouseCursor("/home/kandie/Workspace/Projects/Elementum/Client/resources/ui/assets/cursor.rml");
    if (cursor)
      cursor->RemoveReference();

    mDocument = context->LoadDocument("/home/kandie/Workspace/Projects/Elementum/Client/resources/ui/assets/demo.rml");
    if (mDocument)
    {
      mDocument->Show();
      //document->RemoveReference();
    } else {
      mLog->errorStream() << "couldn't create Rocket element document!";
    }

    mSpellPanel = mDocument->GetElementById("hand");
    assert(mSpellPanel);
    mSpellPanel->AddReference();

    Rocket::Core::ElementScroll* scroll = mSpellPanel->GetElementScroll();
    scroll->EnableScrollbar(Rocket::Core::ElementScroll::Orientation::HORIZONTAL, 400);
    scroll->DisableScrollbar(Rocket::Core::ElementScroll::Orientation::VERTICAL);
    scroll->FormatScrollbars();
    // Add the application as a listener to Ogre's render queue so we can render during the overlay.
    GfxEngine::getSingletonPtr()->getSceneMgr()->addRenderQueueListener(this);
  }

  void UIEngine::destroyScene()
  {
    for (auto button_pair : mSpellButtons)
      button_pair.first->RemoveReference();

    mSpellButtons.clear();

    // Shutdown Rocket.
    mDocument->RemoveReference();
    mSpellPanel->RemoveReference();
    context->RemoveReference();
    Rocket::Core::Shutdown();

    delete ogre_system;
    ogre_system = NULL;

    delete ogre_renderer;
    ogre_renderer = NULL;
  }

	bool UIEngine::loadResources() {

		mLog->infoStream() << "Loading resources...";

		return true;
	}


	void UIEngine::update( unsigned long lTimeElapsed ) {
		processEvents();
	}

  // Called from Ogre before a queue group is rendered.
  void UIEngine::renderQueueStarted(uint8_t queueGroupId, const Ogre::String& invocation, bool& ROCKET_UNUSED(skipThisInvocation))
  {
    if (queueGroupId == Ogre::RENDER_QUEUE_OVERLAY && Ogre::Root::getSingleton().getRenderSystem()->_getViewport()->getOverlaysEnabled())
    {
      context->Update();

      ConfigureRenderSystem();
      context->Render();
    }
  }

  // Called from Ogre after a queue group is rendered.
  void UIEngine::renderQueueEnded(uint8_t ROCKET_UNUSED(queueGroupId), const Ogre::String& ROCKET_UNUSED(invocation), bool& ROCKET_UNUSED(repeatThisInvocation))
  {
  }

  // Configures Ogre's rendering system for rendering Rocket.
  void UIEngine::ConfigureRenderSystem()
  {
    Ogre::RenderSystem* render_system = Ogre::Root::getSingleton().getRenderSystem();

    // Set up the projection and view matrices.
    Ogre::Matrix4 projection_matrix;
    BuildProjectionMatrix(projection_matrix);
    render_system->_setProjectionMatrix(projection_matrix);
    render_system->_setViewMatrix(Ogre::Matrix4::IDENTITY);

    // Disable lighting, as all of Rocket's geometry is unlit.
    render_system->setLightingEnabled(false);
    // Disable depth-buffering; all of the geometry is already depth-sorted.
    render_system->_setDepthBufferParams(false, false);
    // Rocket generates anti-clockwise geometry, so enable clockwise-culling.
    render_system->_setCullingMode(Ogre::CULL_CLOCKWISE);
    // Disable fogging.
    render_system->_setFog(Ogre::FOG_NONE);
    // Enable writing to all four channels.
    render_system->_setColourBufferWriteEnabled(true, true, true, true);
    // Unbind any vertex or fragment programs bound previously by the application.
    render_system->unbindGpuProgram(Ogre::GPT_FRAGMENT_PROGRAM);
    render_system->unbindGpuProgram(Ogre::GPT_VERTEX_PROGRAM);

    // Set texture settings to clamp along both axes.
    Ogre::TextureUnitState::UVWAddressingMode addressing_mode;
    addressing_mode.u = Ogre::TextureUnitState::TAM_CLAMP;
    addressing_mode.v = Ogre::TextureUnitState::TAM_CLAMP;
    addressing_mode.w = Ogre::TextureUnitState::TAM_CLAMP;
    render_system->_setTextureAddressingMode(0, addressing_mode);

    // Set the texture coordinates for unit 0 to be read from unit 0.
    render_system->_setTextureCoordSet(0, 0);
    // Disable texture coordinate calculation.
    render_system->_setTextureCoordCalculation(0, Ogre::TEXCALC_NONE);
    // Enable linear filtering; images should be rendering 1 texel == 1 pixel, so point filtering could be used
    // except in the case of scaling tiled decorators.
    render_system->_setTextureUnitFiltering(0, Ogre::FO_LINEAR, Ogre::FO_LINEAR, Ogre::FO_POINT);
    // Disable texture coordinate transforms.
    render_system->_setTextureMatrix(0, Ogre::Matrix4::IDENTITY);
    // Reject pixels with an alpha of 0.
    render_system->_setAlphaRejectSettings(Ogre::CMPF_GREATER, 0, false);
    // Disable all texture units but the first.
    render_system->_disableTextureUnitsFrom(1);

    // Enable simple alpha blending.
    render_system->_setSceneBlending(Ogre::SBF_SOURCE_ALPHA, Ogre::SBF_ONE_MINUS_SOURCE_ALPHA);

    // Disable depth bias.
    render_system->_setDepthBias(0, 0);
  }

  // Builds an OpenGL-style orthographic projection matrix.
  void UIEngine::BuildProjectionMatrix(Ogre::Matrix4& projection_matrix)
  {
    Ogre::RenderWindow* mWindow = GfxEngine::getSingletonPtr()->getWindow();

    float z_near = -1;
    float z_far = 1;

    projection_matrix = Ogre::Matrix4::ZERO;

    // Set up matrices.
    projection_matrix[0][0] = 2.0f / mWindow->getWidth();
    projection_matrix[0][3]= -1.0000000f;
    projection_matrix[1][1]= -2.0f / mWindow->getHeight();
    projection_matrix[1][3]= 1.0000000f;
    projection_matrix[2][2]= -2.0f / (z_far - z_near);
    projection_matrix[3][3]= 1.0000000f;
  }



  void UIEngine::mouseMoved(const OIS::MouseEvent& e)
  {
    int key_modifier_state = GetKeyModifierState();

    context->ProcessMouseMove(e.state.X.abs, e.state.Y.abs, key_modifier_state);
    if (e.state.Z.rel != 0)
      context->ProcessMouseWheel(e.state.Z.rel / -120, key_modifier_state);

    return;
  }

  void UIEngine::mousePressed(const OIS::MouseEvent& ROCKET_UNUSED(e), OIS::MouseButtonID id)
  {
    context->ProcessMouseButtonDown((int) id, GetKeyModifierState());
    return;
  }

  void UIEngine::mouseReleased(const OIS::MouseEvent& ROCKET_UNUSED(e), OIS::MouseButtonID id)
  {
    context->ProcessMouseButtonUp((int) id, GetKeyModifierState());
    return;
  }

  void UIEngine::keyPressed(const OIS::KeyEvent& e)
  {
    Rocket::Core::Input::KeyIdentifier key_identifier = key_identifiers[e.key];

    // Toggle the debugger on a shift-~ press.
    if (key_identifier == Rocket::Core::Input::KI_OEM_3 &&
      (GetKeyModifierState() & Rocket::Core::Input::KM_SHIFT))
    {
      Rocket::Debugger::SetVisible(!Rocket::Debugger::IsVisible());
      return;
    }

    bool consumed = false;
    if (key_identifier != Rocket::Core::Input::KI_UNKNOWN)
      consumed = context->ProcessKeyDown(key_identifier, GetKeyModifierState());

    std::cout << "UIengine: event consumed? " << (consumed ? "yes" : "no") << "\n";

    // Send through the ASCII value as text input if it is printable.
    if (e.text >= 32)
      context->ProcessTextInput((Rocket::Core::word) e.text);
    else if (key_identifier == Rocket::Core::Input::KI_RETURN)
      context->ProcessTextInput((Rocket::Core::word) '\n');

    return;
  }

  void UIEngine::keyReleased(const OIS::KeyEvent& e)
  {
    Rocket::Core::Input::KeyIdentifier key_identifier = key_identifiers[e.key];

    if (key_identifier != Rocket::Core::Input::KI_UNKNOWN)
      context->ProcessKeyUp(key_identifier, GetKeyModifierState());
    if (e.key == OIS::KC_P)
      if (Rocket::Debugger::IsVisible())
        Rocket::Debugger::SetVisible(false);
      else
        Rocket::Debugger::SetVisible(true);

    return;
  }

  void UIEngine::BuildKeyMaps()
  {
    key_identifiers[OIS::KC_UNASSIGNED] = Rocket::Core::Input::KI_UNKNOWN;
    key_identifiers[OIS::KC_ESCAPE] = Rocket::Core::Input::KI_ESCAPE;
    key_identifiers[OIS::KC_1] = Rocket::Core::Input::KI_1;
    key_identifiers[OIS::KC_2] = Rocket::Core::Input::KI_2;
    key_identifiers[OIS::KC_3] = Rocket::Core::Input::KI_3;
    key_identifiers[OIS::KC_4] = Rocket::Core::Input::KI_4;
    key_identifiers[OIS::KC_5] = Rocket::Core::Input::KI_5;
    key_identifiers[OIS::KC_6] = Rocket::Core::Input::KI_6;
    key_identifiers[OIS::KC_7] = Rocket::Core::Input::KI_7;
    key_identifiers[OIS::KC_8] = Rocket::Core::Input::KI_8;
    key_identifiers[OIS::KC_9] = Rocket::Core::Input::KI_9;
    key_identifiers[OIS::KC_0] = Rocket::Core::Input::KI_0;
    key_identifiers[OIS::KC_MINUS] = Rocket::Core::Input::KI_OEM_MINUS;
    key_identifiers[OIS::KC_EQUALS] = Rocket::Core::Input::KI_OEM_PLUS;
    key_identifiers[OIS::KC_BACK] = Rocket::Core::Input::KI_BACK;
    key_identifiers[OIS::KC_TAB] = Rocket::Core::Input::KI_TAB;
    key_identifiers[OIS::KC_Q] = Rocket::Core::Input::KI_Q;
    key_identifiers[OIS::KC_W] = Rocket::Core::Input::KI_W;
    key_identifiers[OIS::KC_E] = Rocket::Core::Input::KI_E;
    key_identifiers[OIS::KC_R] = Rocket::Core::Input::KI_R;
    key_identifiers[OIS::KC_T] = Rocket::Core::Input::KI_T;
    key_identifiers[OIS::KC_Y] = Rocket::Core::Input::KI_Y;
    key_identifiers[OIS::KC_U] = Rocket::Core::Input::KI_U;
    key_identifiers[OIS::KC_I] = Rocket::Core::Input::KI_I;
    key_identifiers[OIS::KC_O] = Rocket::Core::Input::KI_O;
    key_identifiers[OIS::KC_P] = Rocket::Core::Input::KI_P;
    key_identifiers[OIS::KC_LBRACKET] = Rocket::Core::Input::KI_OEM_4;
    key_identifiers[OIS::KC_RBRACKET] = Rocket::Core::Input::KI_OEM_6;
    key_identifiers[OIS::KC_RETURN] = Rocket::Core::Input::KI_RETURN;
    key_identifiers[OIS::KC_LCONTROL] = Rocket::Core::Input::KI_LCONTROL;
    key_identifiers[OIS::KC_A] = Rocket::Core::Input::KI_A;
    key_identifiers[OIS::KC_S] = Rocket::Core::Input::KI_S;
    key_identifiers[OIS::KC_D] = Rocket::Core::Input::KI_D;
    key_identifiers[OIS::KC_F] = Rocket::Core::Input::KI_F;
    key_identifiers[OIS::KC_G] = Rocket::Core::Input::KI_G;
    key_identifiers[OIS::KC_H] = Rocket::Core::Input::KI_H;
    key_identifiers[OIS::KC_J] = Rocket::Core::Input::KI_J;
    key_identifiers[OIS::KC_K] = Rocket::Core::Input::KI_K;
    key_identifiers[OIS::KC_L] = Rocket::Core::Input::KI_L;
    key_identifiers[OIS::KC_SEMICOLON] = Rocket::Core::Input::KI_OEM_1;
    key_identifiers[OIS::KC_APOSTROPHE] = Rocket::Core::Input::KI_OEM_7;
    key_identifiers[OIS::KC_GRAVE] = Rocket::Core::Input::KI_OEM_3;
    key_identifiers[OIS::KC_LSHIFT] = Rocket::Core::Input::KI_LSHIFT;
    key_identifiers[OIS::KC_BACKSLASH] = Rocket::Core::Input::KI_OEM_5;
    key_identifiers[OIS::KC_Z] = Rocket::Core::Input::KI_Z;
    key_identifiers[OIS::KC_X] = Rocket::Core::Input::KI_X;
    key_identifiers[OIS::KC_C] = Rocket::Core::Input::KI_C;
    key_identifiers[OIS::KC_V] = Rocket::Core::Input::KI_V;
    key_identifiers[OIS::KC_B] = Rocket::Core::Input::KI_B;
    key_identifiers[OIS::KC_N] = Rocket::Core::Input::KI_N;
    key_identifiers[OIS::KC_M] = Rocket::Core::Input::KI_M;
    key_identifiers[OIS::KC_COMMA] = Rocket::Core::Input::KI_OEM_COMMA;
    key_identifiers[OIS::KC_PERIOD] = Rocket::Core::Input::KI_OEM_PERIOD;
    key_identifiers[OIS::KC_SLASH] = Rocket::Core::Input::KI_OEM_2;
    key_identifiers[OIS::KC_RSHIFT] = Rocket::Core::Input::KI_RSHIFT;
    key_identifiers[OIS::KC_MULTIPLY] = Rocket::Core::Input::KI_MULTIPLY;
    key_identifiers[OIS::KC_LMENU] = Rocket::Core::Input::KI_LMENU;
    key_identifiers[OIS::KC_SPACE] = Rocket::Core::Input::KI_SPACE;
    key_identifiers[OIS::KC_CAPITAL] = Rocket::Core::Input::KI_CAPITAL;
    key_identifiers[OIS::KC_F1] = Rocket::Core::Input::KI_F1;
    key_identifiers[OIS::KC_F2] = Rocket::Core::Input::KI_F2;
    key_identifiers[OIS::KC_F3] = Rocket::Core::Input::KI_F3;
    key_identifiers[OIS::KC_F4] = Rocket::Core::Input::KI_F4;
    key_identifiers[OIS::KC_F5] = Rocket::Core::Input::KI_F5;
    key_identifiers[OIS::KC_F6] = Rocket::Core::Input::KI_F6;
    key_identifiers[OIS::KC_F7] = Rocket::Core::Input::KI_F7;
    key_identifiers[OIS::KC_F8] = Rocket::Core::Input::KI_F8;
    key_identifiers[OIS::KC_F9] = Rocket::Core::Input::KI_F9;
    key_identifiers[OIS::KC_F10] = Rocket::Core::Input::KI_F10;
    key_identifiers[OIS::KC_NUMLOCK] = Rocket::Core::Input::KI_NUMLOCK;
    key_identifiers[OIS::KC_SCROLL] = Rocket::Core::Input::KI_SCROLL;
    key_identifiers[OIS::KC_NUMPAD7] = Rocket::Core::Input::KI_7;
    key_identifiers[OIS::KC_NUMPAD8] = Rocket::Core::Input::KI_8;
    key_identifiers[OIS::KC_NUMPAD9] = Rocket::Core::Input::KI_9;
    key_identifiers[OIS::KC_SUBTRACT] = Rocket::Core::Input::KI_SUBTRACT;
    key_identifiers[OIS::KC_NUMPAD4] = Rocket::Core::Input::KI_4;
    key_identifiers[OIS::KC_NUMPAD5] = Rocket::Core::Input::KI_5;
    key_identifiers[OIS::KC_NUMPAD6] = Rocket::Core::Input::KI_6;
    key_identifiers[OIS::KC_ADD] = Rocket::Core::Input::KI_ADD;
    key_identifiers[OIS::KC_NUMPAD1] = Rocket::Core::Input::KI_1;
    key_identifiers[OIS::KC_NUMPAD2] = Rocket::Core::Input::KI_2;
    key_identifiers[OIS::KC_NUMPAD3] = Rocket::Core::Input::KI_3;
    key_identifiers[OIS::KC_NUMPAD0] = Rocket::Core::Input::KI_0;
    key_identifiers[OIS::KC_DECIMAL] = Rocket::Core::Input::KI_DECIMAL;
    key_identifiers[OIS::KC_OEM_102] = Rocket::Core::Input::KI_OEM_102;
    key_identifiers[OIS::KC_F11] = Rocket::Core::Input::KI_F11;
    key_identifiers[OIS::KC_F12] = Rocket::Core::Input::KI_F12;
    key_identifiers[OIS::KC_F13] = Rocket::Core::Input::KI_F13;
    key_identifiers[OIS::KC_F14] = Rocket::Core::Input::KI_F14;
    key_identifiers[OIS::KC_F15] = Rocket::Core::Input::KI_F15;
    key_identifiers[OIS::KC_KANA] = Rocket::Core::Input::KI_KANA;
    key_identifiers[OIS::KC_ABNT_C1] = Rocket::Core::Input::KI_UNKNOWN;
    key_identifiers[OIS::KC_CONVERT] = Rocket::Core::Input::KI_CONVERT;
    key_identifiers[OIS::KC_NOCONVERT] = Rocket::Core::Input::KI_NONCONVERT;
    key_identifiers[OIS::KC_YEN] = Rocket::Core::Input::KI_UNKNOWN;
    key_identifiers[OIS::KC_ABNT_C2] = Rocket::Core::Input::KI_UNKNOWN;
    key_identifiers[OIS::KC_NUMPADEQUALS] = Rocket::Core::Input::KI_OEM_NEC_EQUAL;
    key_identifiers[OIS::KC_PREVTRACK] = Rocket::Core::Input::KI_MEDIA_PREV_TRACK;
    key_identifiers[OIS::KC_AT] = Rocket::Core::Input::KI_UNKNOWN;
    key_identifiers[OIS::KC_COLON] = Rocket::Core::Input::KI_OEM_1;
    key_identifiers[OIS::KC_UNDERLINE] = Rocket::Core::Input::KI_OEM_MINUS;
    key_identifiers[OIS::KC_KANJI] = Rocket::Core::Input::KI_KANJI;
    key_identifiers[OIS::KC_STOP] = Rocket::Core::Input::KI_UNKNOWN;
    key_identifiers[OIS::KC_AX] = Rocket::Core::Input::KI_OEM_AX;
    key_identifiers[OIS::KC_UNLABELED] = Rocket::Core::Input::KI_UNKNOWN;
    key_identifiers[OIS::KC_NEXTTRACK] = Rocket::Core::Input::KI_MEDIA_NEXT_TRACK;
    key_identifiers[OIS::KC_NUMPADENTER] = Rocket::Core::Input::KI_NUMPADENTER;
    key_identifiers[OIS::KC_RCONTROL] = Rocket::Core::Input::KI_RCONTROL;
    key_identifiers[OIS::KC_MUTE] = Rocket::Core::Input::KI_VOLUME_MUTE;
    key_identifiers[OIS::KC_CALCULATOR] = Rocket::Core::Input::KI_UNKNOWN;
    key_identifiers[OIS::KC_PLAYPAUSE] = Rocket::Core::Input::KI_MEDIA_PLAY_PAUSE;
    key_identifiers[OIS::KC_MEDIASTOP] = Rocket::Core::Input::KI_MEDIA_STOP;
    key_identifiers[OIS::KC_VOLUMEDOWN] = Rocket::Core::Input::KI_VOLUME_DOWN;
    key_identifiers[OIS::KC_VOLUMEUP] = Rocket::Core::Input::KI_VOLUME_UP;
    key_identifiers[OIS::KC_WEBHOME] = Rocket::Core::Input::KI_BROWSER_HOME;
    key_identifiers[OIS::KC_NUMPADCOMMA] = Rocket::Core::Input::KI_SEPARATOR;
    key_identifiers[OIS::KC_DIVIDE] = Rocket::Core::Input::KI_DIVIDE;
    key_identifiers[OIS::KC_SYSRQ] = Rocket::Core::Input::KI_SNAPSHOT;
    key_identifiers[OIS::KC_RMENU] = Rocket::Core::Input::KI_RMENU;
    key_identifiers[OIS::KC_PAUSE] = Rocket::Core::Input::KI_PAUSE;
    key_identifiers[OIS::KC_HOME] = Rocket::Core::Input::KI_HOME;
    key_identifiers[OIS::KC_UP] = Rocket::Core::Input::KI_UP;
    key_identifiers[OIS::KC_PGUP] = Rocket::Core::Input::KI_PRIOR;
    key_identifiers[OIS::KC_LEFT] = Rocket::Core::Input::KI_LEFT;
    key_identifiers[OIS::KC_RIGHT] = Rocket::Core::Input::KI_RIGHT;
    key_identifiers[OIS::KC_END] = Rocket::Core::Input::KI_END;
    key_identifiers[OIS::KC_DOWN] = Rocket::Core::Input::KI_DOWN;
    key_identifiers[OIS::KC_PGDOWN] = Rocket::Core::Input::KI_NEXT;
    key_identifiers[OIS::KC_INSERT] = Rocket::Core::Input::KI_INSERT;
    key_identifiers[OIS::KC_DELETE] = Rocket::Core::Input::KI_DELETE;
    key_identifiers[OIS::KC_LWIN] = Rocket::Core::Input::KI_LWIN;
    key_identifiers[OIS::KC_RWIN] = Rocket::Core::Input::KI_RWIN;
    key_identifiers[OIS::KC_APPS] = Rocket::Core::Input::KI_APPS;
    key_identifiers[OIS::KC_POWER] = Rocket::Core::Input::KI_POWER;
    key_identifiers[OIS::KC_SLEEP] = Rocket::Core::Input::KI_SLEEP;
    key_identifiers[OIS::KC_WAKE] = Rocket::Core::Input::KI_WAKE;
    key_identifiers[OIS::KC_WEBSEARCH] = Rocket::Core::Input::KI_BROWSER_SEARCH;
    key_identifiers[OIS::KC_WEBFAVORITES] = Rocket::Core::Input::KI_BROWSER_FAVORITES;
    key_identifiers[OIS::KC_WEBREFRESH] = Rocket::Core::Input::KI_BROWSER_REFRESH;
    key_identifiers[OIS::KC_WEBSTOP] = Rocket::Core::Input::KI_BROWSER_STOP;
    key_identifiers[OIS::KC_WEBFORWARD] = Rocket::Core::Input::KI_BROWSER_FORWARD;
    key_identifiers[OIS::KC_WEBBACK] = Rocket::Core::Input::KI_BROWSER_BACK;
    key_identifiers[OIS::KC_MYCOMPUTER] = Rocket::Core::Input::KI_UNKNOWN;
    key_identifiers[OIS::KC_MAIL] = Rocket::Core::Input::KI_LAUNCH_MAIL;
    key_identifiers[OIS::KC_MEDIASELECT] = Rocket::Core::Input::KI_LAUNCH_MEDIA_SELECT;
  }

  int UIEngine::GetKeyModifierState()
  {
    int modifier_state = 0;

    /*if (mKeyboard->isModifierDown(OIS::Keyboard::Ctrl))
      modifier_state |= Rocket::Core::Input::KM_CTRL;
    if (mKeyboard->isModifierDown(OIS::Keyboard::Shift))
      modifier_state |= Rocket::Core::Input::KM_SHIFT;
    if (mKeyboard->isModifierDown(OIS::Keyboard::Alt))
      modifier_state |= Rocket::Core::Input::KM_ALT;

  #if OGRE_PLATFORM == OGRE_PLATFORM_WIN32

    if (GetKeyState(VK_CAPITAL) > 0)
      modifier_state |= Rocket::Core::Input::KM_CAPSLOCK;
    if (GetKeyState(VK_NUMLOCK) > 0)
      modifier_state |= Rocket::Core::Input::KM_NUMLOCK;
    if (GetKeyState(VK_SCROLL) > 0)
      modifier_state |= Rocket::Core::Input::KM_SCROLLLOCK;

  #elif OGRE_PLATFORM == OGRE_PLATFORM_APPLE

    UInt32 key_modifiers = GetCurrentEventKeyModifiers();
    if (key_modifiers & (1 << alphaLockBit))
      modifier_state |= Rocket::Core::Input::KM_CAPSLOCK;

  #elif OGRE_PLATFORM == OGRE_PLATFORM_LINUX

    XKeyboardState keyboard_state;
    XGetKeyboardControl(DISPLAY!, &keyboard_state);

    if (keyboard_state.led_mask & (1 << 0))
      modifier_state |= Rocket::Core::Input::KM_CAPSLOCK;
    if (keyboard_state.led_mask & (1 << 1))
      modifier_state |= Rocket::Core::Input::KM_NUMLOCK;
    if (keyboard_state.led_mask & (1 << 2))
      modifier_state |= Rocket::Core::Input::KM_SCROLLLOCK;

  #endif*/

    return modifier_state;
  }


  void UIEngine::onTurnStarted(const Puppet* inPuppet) {
    mDocument->GetElementById("active_puppet")->SetInnerRML(inPuppet->getName().c_str());
  }

  std::string UIEngine::saneSpellName(const std::string& inName) {
    std::string str(inName);

    std::locale loc;
    const int length = str.length();
    for(int i=0; i < length; ++i)
    {
      if (!isalpha(str[i], loc))
        str[i] = '_';
      else
        str[i] = std::tolower(str[i]);
    }

    return str;
  }

  void UIEngine::drawSpell(CSpell* inSpell) {
    mLog->infoStream() << "drawing a spell button : " << inSpell->getName();
    Rocket::Core::XMLAttributes attributes;
    attributes.Set("class", Rocket::Core::String(saneSpellName(inSpell->getName()).c_str()));
    Rocket::Core::Element* el =
      Rocket::Core::Factory::InstanceElement(0,"button","button", attributes);
    assert(el);
    mSpellPanel->AppendChild(el);
    assert(el->IsVisible());
    //el->SetClass("summon_fetish_zij", true);

    Rocket::Core::ElementScroll* scroll = mSpellPanel->GetElementScroll();
    scroll->EnableScrollbar(Rocket::Core::ElementScroll::Orientation::HORIZONTAL, 400);
    scroll->DisableScrollbar(Rocket::Core::ElementScroll::Orientation::VERTICAL);
    scroll->FormatScrollbars();
    scroll = 0;

    el->AddEventListener("mouseover", this);
    el->AddEventListener("mouseout", this);
    el->AddEventListener("click", this);

    mSpellButtons.insert( std::make_pair(el, inSpell) );

    inSpell->setButton(el);
    //el->SetAttribute<CSpell*>("spell", inSpell);
    //el->RemoveReference();
  }

  void UIEngine::dropSpell(CSpell* inSpell) {
    for (auto button_pair : mSpellButtons)
      if (button_pair.second == inSpell) {
        button_pair.first->RemoveReference();
        mSpellButtons.erase(button_pair.first);
        break;
      }
    mSpellPanel->RemoveChild(inSpell->getButton());
  }

  void UIEngine::ProcessEvent( Rocket::Core::Event& e) {
    CSpell* lSpell = mSpellButtons.find(e.GetTargetElement())->second;
    assert(lSpell);
    if (e == "mouseover") {
      std::cout << "got a hover event over " << lSpell->getName() << "!\n";
      mDocument->GetElementById("tooltip")->SetInnerRML(lSpell->getTooltip().c_str());
      mDocument->GetElementById("tooltip_container")->SetProperty("visibility", "visible");
      //~ std::cout << lSpell->getTooltip() << "\n";
    }
    else if (e == "mouseout") {
      std::cout << "got a mouse leave event!\n";
      mDocument->GetElementById("tooltip_container")->SetProperty("visibility", "hidden");
    }
    else if (e == "click") {
      std::cout << "spell got clicked\n";
      Combat::getSingleton().castSpell(lSpell);
    }

    lSpell = 0;
  }


}
