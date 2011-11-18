/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#include "ScriptEngine.h"
#include "GameState.h"
#include "EventManager.h"
#include "PixyUtility.h"
#include "tolua++.h"
#include "GameManager.h"
//#include "Puppet.h"
#include "CEGUI/ScriptingModules/LuaScriptModule/CEGUILua.h"
#include <CEGUI/CEGUISystem.h>
#include <CEGUI/CEGUIExceptions.h>
//#include "EntityEvent.h"
//#include "Combat.h"
#include "Spell.h"
//#include "CResourceManager.h"
#include "Intro.h"
#include "Deck.h"
#include <stdarg.h>
#include <boost/bind.hpp>
#include "EntityManager.h"
#include "UIEngine.h"

//~ TOLUA_API int  tolua_Elementum_open (lua_State* tolua_S);
//~ TOLUA_API int  tolua_EShared_open (lua_State* tolua_S);
//~ TOLUA_API int  tolua_Event_open (lua_State* tolua_S);
extern "C" {
  int luaopen_Pixy(lua_State* L);
  int luaopen_Pixy_EventFeedback(lua_State* L);
  int luaopen_Pixy_EventUID(lua_State* L);
  int luaopen_Pixy_Race(lua_State* L);
  int luaopen_Ogre(lua_State* L);
  int luaopen_OIS(lua_State* L);
  int luaopen_ParticleUniverse(lua_State* L);

  #include "swigluaruntime.h"

  struct swig_module_info;
  struct swig_type_info;
  swig_module_info *SWIG_Lua_GetModule(lua_State* L);
  void SWIG_Lua_NewPointerObj(lua_State* L,void* ptr,swig_type_info *type, int own);
  swig_type_info *SWIG_TypeQueryModule(swig_module_info *start,swig_module_info *end,const char *name);
}
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
    mUpdater = &ScriptEngine::updateNothing;
    mLuaState = 0;
    mCEGUILua = 0;
    mTimer = 0;
    fReportIsShown = false;
    fCorruptState = false;
		fSetup = false;

    mCEGUILua = &CEGUI::LuaScriptModule::create();
	}

	ScriptEngine::~ScriptEngine() {
		cleanup();

		if (mLog)
    {
      mLog->infoStream() << "shutting down.";
		//if (fSetup) {
			//mLuaState = NULL; mCEGUILua = NULL;
			//fSetup = false;
			delete mLog;
			delete mLuaLog;
			mLog = mLuaLog = 0;

      //delete mTimer;
		//}
    }
	}

	bool ScriptEngine::setup() {
		if (fSetup)
			return true;

		mLog->infoStream() << "Setting up";

		CEGUI::System::getSingleton().setScriptingModule(mCEGUILua);

		mLuaState = mCEGUILua->getLuaState();
    //~ tolua_EShared_open(mLuaState);
    //~ tolua_Elementum_open(mLuaState);
    //~ tolua_Event_open(mLuaState);
    luaopen_Pixy(mLuaState);
    luaopen_Pixy_EventUID(mLuaState);
    luaopen_Pixy_EventFeedback(mLuaState);
    luaopen_Pixy_Race(mLuaState);
    luaopen_Ogre(mLuaState);
    luaopen_OIS(mLuaState);
    luaopen_ParticleUniverse(mLuaState);

    //~ bind(EventUID::MatchFinished, boost::bind(&ScriptEngine::onMatchFinished, this, _1));
    bind(EventUID::Unassigned, boost::bind(&ScriptEngine::passToLua, this, _1));

    mUpdater = &ScriptEngine::updateNothing;

    mTimer = new boost::asio::deadline_timer(GameManager::getSingleton().getIOService());

		//Combat::getSingletonPtr()->updateMe(getSingletonPtr());
    fReportIsShown = false;
		fSetup = true;
		return true;
	}

  bool ScriptEngine::setup(int inState)
  {
    if (!fSetup)
      setup();

    bool lSuccess = true;
    if (inState == GameState::State::Combat)
    {
      lSuccess = setupCombat();
      mUpdater = &ScriptEngine::updateCombat;
    } else
    {
      lSuccess = setupIntro();
      mUpdater = &ScriptEngine::updateIntro;
    }

    return lSuccess;
  }

	bool ScriptEngine::cleanup() {
    if (!fSetup)
      return true;

    unbind(EventUID::MatchFinished);
    unbind(EventUID::Unassigned);

		//~ CEGUI::System::getSingleton().setScriptingModule(0);
    CEGUI::LuaScriptModule::destroy(*mCEGUILua);

		mCEGUILua = 0;
		mLuaState = 0;

    delete mTimer;
    mTimer = 0;

    mUpdater = &ScriptEngine::updateNothing;

    fSetup = false;

		return true;
	}

  void ScriptEngine::callMeAfter(int inSeconds, std::string inFunc)
  {
    mTimer->expires_from_now(boost::posix_time::milliseconds(inSeconds * 1000));
    mTimer->async_wait(boost::bind(&ScriptEngine::luaCallback, this, inFunc));
  }

  void ScriptEngine::luaCallback(std::string inFunc)
  {
    passToLua(inFunc.c_str(), 0);
  }

	bool ScriptEngine::setupIntro() {

		mLog->infoStream() << "setting up Intro & Lobby";
		//loadResources();

		// init lua state
		//mLuaState = lua_open();

		//luaL_openlibs(mLuaState);

		//luabind::open(mLuaState);

		// -------------------
		// BINDERS
		// -------------------
		// UI binder


		//bind<ScriptEngine, UIEvent>(EVT_UI_LOGIN, this, &ScriptEngine::passToLua);
		/*
		 char _filePath[PATH_MAX];
		 sprintf(_filePath,  "%s/%s/MainMenu.lua", PROJECT_ROOT, PROJECT_SCRIPTS );
		 luaL_dofile(mLuaState, _filePath);
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

	void ScriptEngine::updateNothing(unsigned long lTimeElapsed) {
  }

	void ScriptEngine::updateIntro(unsigned long lTimeElapsed) {

		lua_getfield(mLuaState, LUA_GLOBALSINDEX, "update");
    lua_pushinteger(mLuaState,lTimeElapsed);
		if(lua_isfunction(mLuaState, 1))
		{
      int ec = lua_pcall(mLuaState, 1, 0, 0);
      if (ec != 0)
      {
        // there was a lua error, dump the state and shut down the instance
        reportError();
        return;
      }

		} else
			mLog->errorStream() << "could not find Lua updater!";
	}

	void ScriptEngine::updateCombat(unsigned long lTimeElapsed) {
		lua_getfield(mLuaState, LUA_GLOBALSINDEX, "update");
    lua_pushinteger(mLuaState,lTimeElapsed);
		if(lua_isfunction(mLuaState, 1))
		{
      int ec = lua_pcall(mLuaState, 1, 0, 0);
      if (ec != 0)
      {
        // there was a lua error, dump the state and shut down the instance
        reportError();
        return;
      }

		} else
			mLog->errorStream() << "could not find Lua updater!";
	}


	void ScriptEngine::loadResources() {
	}

	lua_State* ScriptEngine::getLuaState() {
		return mLuaState;
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

  void ScriptEngine::pushUserData(void* inData, std::string inType)
  {
    SWIG_Lua_NewPointerObj(
      mLuaState,
      inData,
      SWIG_TypeQueryModule(
        SWIG_Lua_GetModule(mLuaState),
        SWIG_Lua_GetModule(mLuaState),
        (inType + " *").c_str()),0);
  }

	bool ScriptEngine::passToLua(const Event& inEvt) {

		lua_getfield(mLuaState, LUA_GLOBALSINDEX, "processEvt");
		if(!lua_isfunction(mLuaState, 1))
		{
			mLog->errorStream() << "could not find Lua event processor!";
      reportError();
      return false;
			//lua_pop(mLuaState,1);
			//return true;
		}

		//~ tolua_pushusertype(mLuaState,(void*)&inEvt,"Pixy::Event");
		//~ lua_pushlightuserdata(mLuaState,(void*)&inEvt);
    pushUserData((void*)&inEvt, "Pixy::Event");

    int ec = lua_pcall(mLuaState, 1, 1, 0);
    if (ec != 0)
    {
      reportError();
      return false;
    }

		bool result = lua_toboolean(mLuaState, lua_gettop(mLuaState));
		lua_remove(mLuaState, lua_gettop(mLuaState));

		return result;
	}

  bool ScriptEngine::passToLua(const char* inFunc, int argc, ...) {
    if (fCorruptState)
    {
      mLog->warnStream() << "Lua state is corrupt, bailing out on method call " << inFunc;
      return false;
    }

    va_list argp;
    va_start(argp, argc);

		lua_getfield(mLuaState, LUA_GLOBALSINDEX, "arbitrary");
		if(!lua_isfunction(mLuaState, 1))
		{
			mLog->errorStream() << "could not find Lua arbitrary functor " << inFunc << "!";
      reportError();
      return false;
			//lua_pop(mLuaState,1);
			//return true;
		}

    lua_pushfstring(mLuaState, inFunc);
    for (int i=0; i < argc; ++i) {
      const char* argtype = (const char*)va_arg(argp, const char*);
      void* argv = (void*)va_arg(argp, void*);
      //tolua_pushusertype(mLuaState,argv,argtype);
      pushUserData(argv, argtype);
    }

    int ec = lua_pcall(mLuaState, argc+1, 1, 0);
    if (ec != 0)
    {
      // there was a lua error, dump the state and shut down the instance
      reportError();
      return false;
    }

		bool result = lua_toboolean(mLuaState, lua_gettop(mLuaState));
		lua_remove(mLuaState, lua_gettop(mLuaState));

    va_end(argp);
    //~ return result;
    return true;
  }

  void ScriptEngine::reportError()
  {
    // pop the error msg from the stack
    std::string lError = lua_tostring(mLuaState, lua_gettop(mLuaState));

    fCorruptState = true;

    // unbind any lua callers
    unbind(EventUID::Unassigned);
    mUpdater = &ScriptEngine::updateNothing;

    UIEngine::getSingletonPtr()->reportLuaError(lError);
    assert(false);
    return;

    // don't flood error reports, show only one at a time
    if (fReportIsShown)
      return;

    // now we attempt to report the error, in the case where we can't get to the
    // reporter function or call it successfully, the client has encountered
    // a fatal error and can not be recovered, thus we throw lua_runtime_error()

		lua_getfield(mLuaState, LUA_GLOBALSINDEX, "arbitrary");
		if(!lua_isfunction(mLuaState, 1))
		{
			mLog->errorStream() << "Fatal - could not call Lua error reporter, shutdown is inevitable";
      throw lua_runtime_error(lError);
		}

		lua_pushfstring(mLuaState,"UI.reportLuaError");
		lua_pushfstring(mLuaState,lError.c_str());

    int ec = lua_pcall(mLuaState, 1, 0, 0);
    if (ec != 0)
    {
			mLog->errorStream() << "Fatal - failed to report Lua error, shutdown is inevitable";
      throw lua_runtime_error(lError);
    }

    fReportIsShown = true;

    // throw lua_runtime_error(lua_tostring(mLuaState, lua_gettop(mLuaState)));
    // assert(false);
  }

  void ScriptEngine::_reportAccepted()
  {
    fReportIsShown = false;
  }

  bool ScriptEngine::onGameDataSynced(const Event& inEvt)
  {
    // populate Lua with the game resources

    // spells

    return true;
  }

  int ScriptEngine::_passGameData()
  {
    lua_newtable(mLuaState); // spells master table
    std::list<Spell*> mSpells[4];

    std::list<Spell*>::iterator spell;
    int i=0;
    for (i=0; i < 4; ++i)
    {
      mSpells[i] = GameManager::getSingleton().getEntityMgr()._getSpells(i);
      int count = 1; // start from 1 for Lua compatibility

      lua_newtable(mLuaState); // race spells table
      for (spell = mSpells[i].begin(); spell != mSpells[i].end(); ++spell)
      {
        lua_pushinteger(mLuaState, count);
        pushUserData(*spell, "Pixy::Spell");
        //~ tolua_pushusertype(mLuaState, (void*)(*spell), "Pixy::Spell");
        lua_settable(mLuaState, -3);

        ++count;
      }

      lua_pushinteger(mLuaState, i);
      lua_insert(mLuaState, -2); // swap race spells table with the index
      lua_settable(mLuaState, -3); // assign the new spells table
    }

    lua_setglobal(mLuaState, "__SpellsTemp"); /* set bottom table as global variable t */

    return 0;
  }

  int ScriptEngine::_passPuppetListing()
  {
    mLog->debugStream() << "Exporting puppet listing to Lua";

    lua_newtable(mLuaState); // spells master table
    Intro::puppets_t mPuppets = Intro::getSingleton().getPuppets();

    Intro::puppets_t::iterator puppet;
    int count = 1;
    for (puppet = mPuppets.begin(); puppet != mPuppets.end(); ++puppet)
    {
      lua_pushinteger(mLuaState, count);
      //~ tolua_pushusertype(mLuaState, (void*)(*puppet), "Pixy::Puppet");
      pushUserData(*puppet, "Pixy::Puppet");
      lua_settable(mLuaState, -3);

      ++count;
    }

    lua_setglobal(mLuaState, "__PuppetsTemp");

    Event e(EventUID::PuppetListSynced);
    EventManager::getSingleton().hook(e);

    return true;
  }

  int ScriptEngine::_passPuppet()
  {
    Puppet* mPuppet = Intro::getSingleton().getPuppet();

    //~ tolua_pushusertype(mLuaState, (void*)mPuppet, "Pixy::Puppet");
    pushUserData(mPuppet, "Pixy::Puppet");
    lua_setglobal(mLuaState, "__PuppetTemp");

    Event e(EventUID::PuppetSynced);
    EventManager::getSingleton().hook(e);

    // export decks
    {

      lua_newtable(mLuaState); // decks table
      const Puppet::decks_t& mDecks = mPuppet->getDecks();

      mLog->debugStream() << "exporting decks # " << mDecks.size();

      Puppet::decks_t::const_iterator deck;
      int count = 1;
      for (deck = mDecks.begin(); deck != mDecks.end(); ++deck)
      {
        mLog->debugStream() << "exporting deck " << (*deck)->getName();
        lua_pushinteger(mLuaState, count);
        //~ tolua_pushusertype(mLuaState, (void*)(*deck), "Pixy::Deck");
        pushUserData(*deck, "Pixy::Deck");
        lua_settable(mLuaState, -3);

        ++count;
      }

      lua_setglobal(mLuaState, "__PuppetDecksTemp");
    }

    {
      Event e(EventUID::PuppetDecksSynced);
      EventManager::getSingleton().hook(e);
    }

    return true;
  }

	bool ScriptEngine::mouseMoved( const OIS::MouseEvent &e )
	{
		//return passToLua("onMouseMoved", 1, "OIS::MouseEvent", &e);
		return true;
	}

	bool ScriptEngine::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
		return passToLua("Input.onMousePressed", 2, "OIS::MouseEvent", &e, "OIS::MouseButtonID", &id);
	}

	bool ScriptEngine::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
		return passToLua("Input.onMouseReleased", 2, "OIS::MouseEvent", &e, "OIS::MouseButtonID", &id);
    //CEGUI::Window *window = CEGUI::System::getSingletonPtr()->getWindowContainingMouse();
    //return (window && window->isVisible() && window->getAlpha() > 0.0f && (window->getType() != "DefaultWindow"));
  }

	void ScriptEngine::keyReleased( const OIS::KeyEvent &e ) {
    passToLua("Input.onKeyReleased", 1, "OIS::KeyEvent", &e);
	}
	void ScriptEngine::keyPressed( const OIS::KeyEvent &e ) {
		passToLua("Input.onKeyPressed", 1, "OIS::KeyEvent", &e);
	}

  std::string ScriptEngine::getScriptPathPrefix() const {
#if PIXY_PLATFORM == PIXY_PLATFORM_APPLE
    return Utility::macBundlePath() + "/Contents/Resources/scripts";
#elif PIXY_PLATFORM == PIXY_PLATFORM_WIN32
    return "../resources/scripts";
#else // UNIX
    return "../resources/scripts";
#endif
  }

  std::string ScriptEngine::getModulePathPrefix() const {
#if PIXY_PLATFORM == PIXY_PLATFORM_APPLE
    return Utility::macBundlePath() + "/Contents/Plugins";
#elif PIXY_PLATFORM == PIXY_PLATFORM_WIN32
    return GameManager::getSingleton().getBinPath();
#else // UNIX
    return "../lib";
#endif
  }

}
