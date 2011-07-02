/*
 *  ScriptEngine.h
 *  Elementum
 *
 *  Created by Ahmad Amireh on 2/19/10.
 *  Copyright 2010 JU. All rights reserved.
 *
 */


#ifndef H_ScriptEngine_H
#define H_ScriptEngine_H

#include "Engine.h"
#include "EventListener.h"

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

  class CPuppet;
	/*! \class ScriptEngine
	 *	\brief
	 *	Manages the Lua module, loads Script resources, listens to and passes off
	 *	Events fro and to Lua.
	 */
	class ScriptEngine : public Engine, public EventListener {

	public:
		virtual ~ScriptEngine();
		static ScriptEngine* getSingletonPtr();
		static ScriptEngine& getSingleton();

		virtual bool setup();
		virtual void update(unsigned long lTimeElapsed);
		virtual bool cleanup();

		void runScript(const char* inScript);
		lua_State* getLuaState();
		static void luaLog(std::string inMsg);
		log4cpp::Category* getLuaLog();

		bool passToLua(const Event& inEvt);
    bool passToLua(const char* inFunc, int argc, ...);

	protected:

    //bool evtAssignPuppets(Event* inEvt);
    //bool evtJoinQueue(Event* inEvt);

		lua_State* mLUA;
		CEGUI::LuaScriptModule* mCEGUILua;
		log4cpp::Category *mLuaLog;
		void loadResources();

		bool setupIntro();
		bool setupCombat();

		void updateIntro(unsigned long lTimeElapsed);
		void updateCombat(unsigned long lTimeElapsed);

    //void assignSelfPuppet(CPuppet* inPuppet);
	private:
		static ScriptEngine* _myScriptEngine;
		ScriptEngine();
		ScriptEngine(const ScriptEngine& src);
		ScriptEngine& operator=(const ScriptEngine& rhs);

		void (ScriptEngine::*mUpdater)(unsigned long);
	};
}
#endif
