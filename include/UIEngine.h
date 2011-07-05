/*
 *  UIEngine.h
 *  Elementum
 *
 *  Created by Ahmad Amireh on 2/11/10.
 *  Copyright 2010 JU. All rights reserved.
 *
 */

#ifndef H_UIEngine_H
#define H_UIEngine_H

#include "Engine.h"
#include "EventListener.h"
#include "InputListener.h"
#include "CPuppet.h"
#include "CSpell.h"

#include <Rocket/Core/String.h>
#include <Rocket/Core/Context.h>
#include <Rocket/Core/EventListener.h>
#include <Rocket/Core/Event.h>
#include <Ogre.h>
//#include <CEGUI/CEGUIInputEvent.h>

namespace Rocket {
namespace Core {

class Context;

}
}

class SystemInterfaceOgre3D;
class RenderInterfaceOgre3D;

namespace Pixy {

  class Event;
  class EventManager;
	/*	\class UIEngine
	 *	\brief
	 *	Loads and unloads UISheets, manages CEGUI system, and handles UI related operations
	 *
	 *	\remark
	 *	At the moment, the UIEngine acts as a manager for UISheets, however,
	 *	the sheets are ought to be handled from within the LUA subsystem.
	 */
	class UIEngine :
    public  Rocket::Core::EventListener,
    public Ogre::RenderQueueListener,
    public Engine,
    public EventListener,
    public InputListener {

	public:
		virtual ~UIEngine();
		static UIEngine* getSingletonPtr();

		virtual bool setup();
		virtual void update(unsigned long lTimeElapsed);
		virtual bool cleanup();

		void keyPressed( const OIS::KeyEvent &e );
		void keyReleased( const OIS::KeyEvent &e );

		void mouseMoved( const OIS::MouseEvent &e );
		void mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id );
		void mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id );

		/// Called from Ogre before a queue group is rendered.
		virtual void renderQueueStarted(uint8_t queueGroupId, const Ogre::String& invocation, bool& skipThisInvocation);
		/// Called from Ogre after a queue group is rendered.
    virtual void renderQueueEnded(uint8_t queueGroupId, const Ogre::String& invocation, bool& repeatThisInvocation);

    void drawSpell(CSpell*);
    void dropSpell(CSpell*);

    void ProcessEvent( Rocket::Core::Event&);

    void onTurnStarted(const Puppet* inPuppet);

    static std::string saneSpellName(const std::string&);

	protected:

		bool loadResources();

    EventManager			*mEvtMgr;




		void createScene();
		void destroyScene();

		// Configures Ogre's rendering system for rendering Rocket.
		void ConfigureRenderSystem();
		// Builds an OpenGL-style orthographic projection matrix.
		void BuildProjectionMatrix(Ogre::Matrix4& matrix);

		// Absolute path to the libRocket directory.
		Rocket::Core::String rocket_path;
		// Absolute path to the Ogre3d sample directory;
		Rocket::Core::String sample_path;

		Rocket::Core::Context* context;
    Rocket::Core::ElementDocument* mDocument;
    Rocket::Core::Element* mSpellPanel;

		SystemInterfaceOgre3D* ogre_system;
		RenderInterfaceOgre3D* ogre_renderer;

    Ogre::SceneManager* mSceneMgr;
    Ogre::Root *mRoot;

    void BuildKeyMaps();
		int GetKeyModifierState();

		typedef std::map< OIS::KeyCode, Rocket::Core::Input::KeyIdentifier > KeyIdentifierMap;
    KeyIdentifierMap key_identifiers;



	private:
		static UIEngine* _myUIEngine;
		UIEngine();
		UIEngine(const UIEngine& src);
		UIEngine& operator=(const UIEngine& rhs);
	};
}
#endif
