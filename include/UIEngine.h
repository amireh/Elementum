/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_UIEngine_H
#define H_UIEngine_H

#include "Engine.h"
#include "EventListener.h"
#include "InputListener.h"

#include <CEGUI/CEGUIBase.h>
#include <CEGUI/CEGUIInputEvent.h>
#include <CEGUI/RendererModules/Ogre/CEGUIOgreRenderer.h>

namespace Pixy {

  struct Event;
  class EventManager;
  class Spell;
  class MyInput;
	/*	\class UIEngine
	 *	\brief
	 *	Loads and unloads UISheets, manages CEGUI system, and handles UI related operations
	 *
	 *	\remark
	 *	At the moment, the UIEngine acts as a manager for UISheets, however,
	 *	the sheets are ought to be handled from within the LUA subsystem.
	 */
	class UIEngine : public Engine, public EventListener, public InputListener {

	public:
		virtual ~UIEngine();
		static UIEngine* getSingletonPtr();

		virtual bool setup();
		virtual void update(unsigned long lTimeElapsed);
		virtual bool cleanup();

		void keyPressed( const OIS::KeyEvent &e );
		void keyReleased( const OIS::KeyEvent &e );

		bool mouseMoved( const OIS::MouseEvent &e );
		bool mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id );
		bool mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id );

		CEGUI::MouseButton convertButton(OIS::MouseButtonID buttonID);

    void setMargin(CEGUI::Window*, CEGUI::UBox&);

    void refreshSize();

    void connectAnimation(CEGUI::Window*, std::string inAnim);
    void refreshTooltipSize(CEGUI::Window* inWindow, Spell* inSpell);

	protected:
		const char* getDataPathPrefix() const;

		bool loadResources();

		CEGUI::OgreRenderer		*mOgreRenderer;
		CEGUI::System			*mUISystem;
		EventManager			*mEvtMgr;
    MyInput *mMyInput;

	private:
		static UIEngine* _myUIEngine;
		UIEngine();
		UIEngine(const UIEngine& src);
		UIEngine& operator=(const UIEngine& rhs);
	};
}
#endif
