/*
 *  ScriptEngine.cpp
 *  Elementum
 *
 *  Created by Ahmad Amireh on 2/19/10.
 *  Copyright 2010 JU. All rights reserved.
 *
 */

#include "ScriptEngine.h"
#include "GameState.h"
#include "EventManager.h"
#include "tolua++.h"
#include "GameManager.h"
//#include "CPuppet.h"
#include "CEGUI/ScriptingModules/LuaScriptModule/CEGUILua.h"
#include <CEGUI/CEGUISystem.h>
#include <CEGUI/CEGUIExceptions.h>
//#include "EntityEvent.h"
//#include "Combat.h"
#include <stdarg.h>
#include <boost/bind.hpp>

TOLUA_API int  tolua_Elementum_open (lua_State* tolua_S);
TOLUA_API int  tolua_EShared_open (lua_State* tolua_S);
TOLUA_API int  tolua_Event_open (lua_State* tolua_S);
namespace Pixy {
	ScriptEngine* ScriptEngine::_myScriptEngine = NULL;

	ScriptEngine* ScriptEngine::getSingletonPtr() {
		if( !_myScriptEngine ) {
		    _myScriptEngine = new ScriptEngine();
		}

		return _myScriptEngine;
	}

	ScriptEngine& ScriptEngine::getSingleton() {
		return *(getSingletonPtr());
	}
	ScriptEngine::ScriptEngine()  {
		mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, "ScriptEngine");
		mLuaLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, "Lua");
		fSetup = false;
	}

	ScriptEngine::~ScriptEngine() {
		//cleanup();
		mLog->infoStream() << "shutting down.";
		if (fSetup) {
			mLUA = NULL; mCEGUILua = NULL;
			fSetup = false;
			delete mLog;
			delete mLuaLog;
			mLog = mLuaLog = 0;
		}
	}

	bool ScriptEngine::setup() {
		if (fSetup)
			return true;

		mLog->infoStream() << "Setting up";

		mCEGUILua = &CEGUI::LuaScriptModule::create();
		CEGUI::System::getSingleton().setScriptingModule(mCEGUILua);

		mLUA = mCEGUILua->getLuaState();
    tolua_EShared_open(mLUA);
    tolua_Elementum_open(mLUA);
    tolua_Event_open(mLUA);

    bind(EventUID::MatchFinished, boost::bind(&ScriptEngine::onMatchFinished, this, _1));
    bind(EventUID::Unassigned, boost::bind(&ScriptEngine::passToLua, this, _1));

		//~ bindToAll<ScriptEngine>(this, &ScriptEngine::passToLua); // __DISABLED__
    //bindToName("AssignPuppets", this, &ScriptEngine::evtAssignPuppets);
    //bindToName("JoinQueue", this, &ScriptEngine::evtJoinQueue);

		bool lSuccess = false;
		GAME_STATE lGameState = GameManager::getSingleton().getCurrentState()->getId();
		switch (lGameState) {
			case STATE_INTRO:
				lSuccess = setupIntro();
				mUpdater = &ScriptEngine::updateIntro;
			break;
			case STATE_COMBAT:
				lSuccess = setupCombat();
				mUpdater = &ScriptEngine::updateCombat;
			break;
			default:
				lSuccess = true;
		}

		//Combat::getSingletonPtr()->updateMe(getSingletonPtr());
		fSetup = true;
		return lSuccess;
	}

	bool ScriptEngine::setupIntro() {

		mLog->infoStream() << "setting up Intro";
		//loadResources();

		// init lua state
		//mLUA = lua_open();

		//luaL_openlibs(mLUA);

		//luabind::open(mLUA);

		// -------------------
		// BINDERS
		// -------------------
		// UI binder


		//bind<ScriptEngine, UIEvent>(EVT_UI_LOGIN, this, &ScriptEngine::passToLua);
		/*
		 char _filePath[PATH_MAX];
		 sprintf(_filePath,  "%s/%s/MainMenu.lua", PROJECT_ROOT, PROJECT_SCRIPTS );
		 luaL_dofile(mLUA, _filePath);
		 */

		//CEGUI::System::getSingleton().executeScriptFile("MainMenu.lua");

		fSetup = true;
		return true;
	}
	bool ScriptEngine::setupCombat() {
		//setupIntro();
		return true;
	}

	void ScriptEngine::update( unsigned long lTimeElapsed ) {
		processEvents();

		(this->*mUpdater)(lTimeElapsed);
	}

	void ScriptEngine::updateIntro(unsigned long lTimeElapsed) {
		// update Lua
		lua_getfield(mLUA, LUA_GLOBALSINDEX, "update");
		if(lua_isfunction(mLUA, 1))
		{
			try {
				lua_call(mLUA, 0, 0);
			} catch (...) { // do nothing
			}
		} else
			mLog->errorStream() << "could not find Lua updater!";
	}

	void ScriptEngine::updateCombat(unsigned long lTimeElapsed) {
		updateIntro(lTimeElapsed);
		lua_getfield(mLUA, LUA_GLOBALSINDEX, "updateCombat");
    lua_pushinteger(mLUA,lTimeElapsed);
		if(lua_isfunction(mLUA, 1))
		{
			try {
				lua_call(mLUA, 1, 0);
			} catch (...) { // do nothing
			}
		} else
			mLog->errorStream() << "could not find Lua updater!";
	}

	bool ScriptEngine::cleanup() {
		return true;
	}

	void ScriptEngine::loadResources() {
		/*using namespace Ogre;
		ResourceGroupManager& rgm = ResourceGroupManager::getSingleton();

		// add resource groups that we use
		rgm.createResourceGroup("scripts");

		const char* dataPathPrefix;
		dataPathPrefix = "../resources/scripts/client/";
		//char resourcePath[PATH_MAX];
		mLog->infoStream() << "Adding resource locations";

		ResourceGroupManager::getSingleton().addResourceLocation(dataPathPrefix, "FileSystem", "scripts");
		ResourceGroupManager::getSingleton().initialiseAllResourceGroups();	*/
	}

	lua_State* ScriptEngine::getLuaState() {
		return mLUA;
	}

	log4cpp::Category* ScriptEngine::getLuaLog() { return mLuaLog; }

	void ScriptEngine::luaLog(std::string inMsg) {
		ScriptEngine::getSingletonPtr()->getLuaLog()->infoStream() << inMsg;
	}

	void ScriptEngine::runScript(const char* inScript) {
		try {
			CEGUI::System::getSingleton().executeScriptFile(inScript);
		} catch (CEGUI::Exception& e) {
			mLog->errorStream() << "Could not execute script " << inScript << "; " << e.what();
		} catch (std::exception& e) {
			mLog->errorStream() << "Could not execute script `" << inScript
				<< "' out of an unexpected exception; " << e.what();
		}
	}

	bool ScriptEngine::passToLua(const Event& inEvt) {

		//~ mLog->debugStream() << "dispatching evt to lua";

		//mLog->debugStream() << "Lua stack is " << lua_gettop(mLUA) << " big";

		/*
		if (inEvt->getMsgId() == ID_ENTITY_EVENT) {
			mLog->infoStream() << "got an entity event to pass to lua!";
		}
		 */
		lua_getfield(mLUA, LUA_GLOBALSINDEX, "processEvt");
		if(!lua_isfunction(mLUA, 1))
		{
			mLog->errorStream() << "could not find Lua event processor!";
			lua_pop(mLUA,1);
			return true;
		}

		tolua_pushusertype(mLUA,(void*)&inEvt,"Pixy::Event");
		try {
			lua_call(mLUA, 1, 1);
		} catch (CEGUI::ScriptException& e) {
			mLog->errorStream() << "Lua Handler: " << e.what();
		} catch (std::exception& e) {
			mLog->errorStream() << "Lua Handler: " << e.what();
		}

		/*
		mLog->debugStream() << "Lua stack is " << lua_gettop(mLUA) << " big";
		if (lua_isboolean(mLUA, lua_gettop(mLUA)))
			mLog->infoStream() << "Lua returned a boolean";
		else
			mLog->errorStream() << "Lua did NOT return a boolean";
		*/

		bool result = lua_toboolean(mLUA, lua_gettop(mLUA));

		lua_remove(mLUA, lua_gettop(mLUA));

		/*
		mLog->debugStream() << "Lua stack is " << lua_gettop(mLUA) << " big";

		if (result)
			mLog->infoStream() << "Lua is done";
		else
			mLog->infoStream() << "Lua is not done, redispatching";
		*/

		return result;
	}

  bool ScriptEngine::passToLua(const char* inFunc, int argc, ...) {
    va_list argp;
    va_start(argp, argc);

		lua_getfield(mLUA, LUA_GLOBALSINDEX, "arbitraryFunc");
		if(!lua_isfunction(mLUA, 1))
		{
			mLog->errorStream() << "could not find Lua arbitrary functor!";
			lua_pop(mLUA,1);
			return true;
		}

    lua_pushfstring(mLUA, inFunc);
    //lua_pushinteger(mLUA, argc);
    for (int i=0; i < argc; ++i) {
      const char* argtype = (const char*)va_arg(argp, const char*);
      void* argv = (void*)va_arg(argp, void*);
      //std::cout << static_cast<Puppet*>(argv)->getName() << "\n";
      //lua_pushlightuserdata(mLUA, argv);
      tolua_pushusertype(mLUA,argv,argtype);
    }

		try {
			lua_call(mLUA, argc+1, 0);
		} catch (CEGUI::ScriptException& e) {
			mLog->errorStream() << "Lua Handler: " << e.what();
		} catch (std::exception& e) {
			mLog->errorStream() << "Lua Handler: " << e.what();
		}

    va_end(argp);
    return true;
  }

  bool ScriptEngine::onMatchFinished(const Event& inEvt) {
    lua_getfield(mLUA, LUA_GLOBALSINDEX, "arbitraryFunc");
    lua_pushfstring(mLUA, "onMatchFinished");
    lua_pushinteger(mLUA, convertTo<int>(inEvt.getProperty("W")));
    lua_call(mLUA, 2, 0);

    return true;
  }
}
