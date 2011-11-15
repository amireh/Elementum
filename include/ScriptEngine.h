/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_ScriptEngine_H
#define H_ScriptEngine_H

#include "Engine.h"
#include "EventListener.h"
#include "InputListener.h"
#include <boost/asio.hpp>

namespace CEGUI {
  class LuaScriptModule;
}
// LUA
extern "C" {
	#include "lua.h"
	#include "lualib.h"
	//#include "lauxlib.h"
}
//#include "luabind/luabind.hpp"
namespace Pixy {

  class Puppet;
	/*! \class ScriptEngine
	 *	\brief
	 *	Manages the Lua module, loads Script resources, listens to and passes off
	 *	Events fro and to Lua.
	 */
	class ScriptEngine : public Engine, public EventListener, public InputListener {

	public:
		virtual ~ScriptEngine();
		static ScriptEngine* getSingletonPtr();
		static ScriptEngine& getSingleton();

		virtual bool setup();
		virtual bool setup(int inState);
		virtual void update(unsigned long lTimeElapsed);
		virtual bool cleanup();

		void runScript(const char* inScript);
		lua_State* getLuaState();
		static void luaLog(std::string inMsg);
		log4cpp::Category* getLuaLog();

		bool passToLua(const Event& inEvt);
    bool passToLua(const char* inFunc, int argc, ...);

    std::string getScriptPathPrefix() const;
    std::string getModulePathPrefix() const;

    void callMeAfter(int inSeconds, std::string func);

		void keyPressed( const OIS::KeyEvent &e );
		void keyReleased( const OIS::KeyEvent &e );

		bool mouseMoved( const OIS::MouseEvent &e );
		bool mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id );
		bool mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id );

    int _passGameData();

    /*!
     * @brief
     * Called by Intro::onSyncPuppets() to pass off the puppet data to Lua.
     *
     * This happens when the player logs in and receives the list of their
     * puppets.
     */
    int _passPuppetListing();

    /*!
     * @brief
     * Called by Intro::onSyncPuppetData() to pass off the selected puppet to Lua.
     *
     * This happens when the player joins the lobby with a selected puppet.
     */
    int _passPuppet();

	protected:

    bool onMatchFinished(const Event& inEvt);
    bool onGameDataSynced(const Event&);

    void luaCallback(std::string inFunc);

    //bool evtAssignPuppets(Event* inEvt);
    //bool evtJoinQueue(Event* inEvt);

		lua_State* mLUA;
		CEGUI::LuaScriptModule* mCEGUILua;
		log4cpp::Category *mLuaLog;
		void loadResources();

		bool setupIntro();
		bool setupCombat();

		void updateNothing(unsigned long lTimeElapsed);
		void updateIntro(unsigned long lTimeElapsed);
		void updateCombat(unsigned long lTimeElapsed);

    boost::asio::deadline_timer* mTimer;

    //void assignSelfPuppet(Puppet* inPuppet);
	private:
		static ScriptEngine* _myScriptEngine;
		ScriptEngine();
		ScriptEngine(const ScriptEngine& src);
		ScriptEngine& operator=(const ScriptEngine& rhs);

		void (ScriptEngine::*mUpdater)(unsigned long);
	};
}
#endif
