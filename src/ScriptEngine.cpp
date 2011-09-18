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
#include "PixyUtility.h"
#include "tolua++.h"
#include "GameManager.h"
//#include "CPuppet.h"
#include "CEGUI/ScriptingModules/LuaScriptModule/CEGUILua.h"
#include <CEGUI/CEGUISystem.h>
#include <CEGUI/CEGUIExceptions.h>
//#include "EntityEvent.h"
//#include "Combat.h"
#include "CSpell.h"
#include "CResourceManager.h"
#include "Intro.h"
#include "Deck.h"
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
    mUpdater = &ScriptEngine::updateNothing;
    mLUA = 0;
    mCEGUILua = 0;
    mTimer = 0;
		fSetup = false;
	}

	ScriptEngine::~ScriptEngine() {
		cleanup();

		mLog->infoStream() << "shutting down.";
		//if (fSetup) {
			//mLUA = NULL; mCEGUILua = NULL;
			//fSetup = false;
			delete mLog;
			delete mLuaLog;
			mLog = mLuaLog = 0;

      //delete mTimer;
		//}
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

    mUpdater = &ScriptEngine::updateNothing;

    mTimer = new boost::asio::deadline_timer(GameManager::getSingleton().getIOService());

		//Combat::getSingletonPtr()->updateMe(getSingletonPtr());
		fSetup = true;
		return true;
	}

  bool ScriptEngine::setup(GAME_STATE inState)
  {
    if (!fSetup)
      setup();

    bool lSuccess = true;
    if (inState == STATE_COMBAT)
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
    //~ CEGUI::LuaScriptModule::destroy(*mCEGUILua);

		mCEGUILua = 0;
		mLUA = 0;

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

	void ScriptEngine::updateNothing(unsigned long lTimeElapsed) {
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


	void ScriptEngine::loadResources() {
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

  bool ScriptEngine::onGameDataSynced(const Event& inEvt)
  {
    // populate Lua with the game resources

    // spells

    return true;
  }

  int ScriptEngine::_passGameData()
  {
    lua_newtable(mLUA); // spells master table
    std::list<CSpell*> mSpells[4];

    std::list<CSpell*>::iterator spell;
    int i=0;
    for (i=0; i < 4; ++i)
    {
      mSpells[i] = GameManager::getSingleton().getResMgr()._getSpells((Pixy::RACE)i);
      int count = 1; // start from 1 for Lua compatibility

      lua_newtable(mLUA); // race spells table
      for (spell = mSpells[i].begin(); spell != mSpells[i].end(); ++spell)
      {
        lua_pushinteger(mLUA, count);
        tolua_pushusertype(mLUA, (void*)(*spell), "Pixy::CSpell");
        lua_settable(mLUA, -3);

        ++count;
      }

      lua_pushinteger(mLUA, i);
      lua_insert(mLUA, -2); // swap race spells table with the index
      lua_settable(mLUA, -3); // assign the new spells table
    }

    lua_setglobal(mLUA, "Spells"); /* set bottom table as global variable t */

    return 0;
  }

  int ScriptEngine::_passPuppetListing()
  {
    lua_newtable(mLUA); // spells master table
    Intro::puppets_t mPuppets = Intro::getSingleton().getPuppets();

    Intro::puppets_t::iterator puppet;
    int count = 1;
    for (puppet = mPuppets.begin(); puppet != mPuppets.end(); ++puppet)
    {
      lua_pushinteger(mLUA, count);
      tolua_pushusertype(mLUA, (void*)(*puppet), "Pixy::CPuppet");
      lua_settable(mLUA, -3);

      ++count;
    }

    lua_setglobal(mLUA, "Puppets");

    Event e(EventUID::PuppetListSynced);
    EventManager::getSingleton().hook(e);

    return true;
  }

  int ScriptEngine::_passPuppet()
  {
    CPuppet* mPuppet = Intro::getSingleton().getPuppet();

    tolua_pushusertype(mLUA, (void*)mPuppet, "Pixy::CPuppet");
    lua_setglobal(mLUA, "Puppet");

    Event e(EventUID::PuppetSynced);
    EventManager::getSingleton().hook(e);

    // export decks
    {

      lua_newtable(mLUA); // decks table
      const Puppet::decks_t& mDecks = mPuppet->getDecks();

      mLog->debugStream() << "exporting decks # " << mDecks.size();

      Puppet::decks_t::const_iterator deck;
      int count = 1;
      for (deck = mDecks.begin(); deck != mDecks.end(); ++deck)
      {
        mLog->debugStream() << "exporting deck " << (*deck)->getName();
        lua_pushinteger(mLUA, count);
        tolua_pushusertype(mLUA, (void*)(*deck), "Pixy::Deck");
        lua_settable(mLUA, -3);

        ++count;
      }

      lua_setglobal(mLUA, "PuppetDecks");
    }

    {
      Event e(EventUID::PuppetDecksSynced);
      EventManager::getSingleton().hook(e);
    }

    return true;
  }

  bool ScriptEngine::onMatchFinished(const Event& inEvt) {
    lua_getfield(mLUA, LUA_GLOBALSINDEX, "arbitraryFunc");
    lua_pushfstring(mLUA, "onMatchFinished");
    lua_pushinteger(mLUA, convertTo<int>(inEvt.getProperty("W")));
    lua_call(mLUA, 2, 0);

    return true;
  }


	bool ScriptEngine::mouseMoved( const OIS::MouseEvent &e )
	{
		//return passToLua("onMouseMoved", 1, "OIS::MouseEvent", &e);
	}

	bool ScriptEngine::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
		return passToLua("onMousePressed", 2, "OIS::MouseEvent", &e, "OIS::MouseButtonID", &id);
	}

	bool ScriptEngine::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
		return passToLua("onMouseReleased", 2, "OIS::MouseEvent", &e, "OIS::MouseButtonID", &id);
    //CEGUI::Window *window = CEGUI::System::getSingletonPtr()->getWindowContainingMouse();
    //return (window && window->isVisible() && window->getAlpha() > 0.0f && (window->getType() != "DefaultWindow"));
  }

	void ScriptEngine::keyReleased( const OIS::KeyEvent &e ) {
    passToLua("onKeyReleased", 1, "OIS::KeyEvent", &e);
	}
	void ScriptEngine::keyPressed( const OIS::KeyEvent &e ) {
		passToLua("onKeyPressed", 1, "OIS::KeyEvent", &e);
	}

  std::string ScriptEngine::getScriptPathPrefix() const {
#if PIXY_PLATFORM == PIXY_PLATFORM_APPLE
    return macBundlePath() + "/Contents/Resources/scripts";
#elif PIXY_PLATFORM == PIXY_PLATFORM_WIN32
    return "../resources/scripts";
#else // UNIX
    return "../resources/scripts";
#endif
  }

  std::string ScriptEngine::getModulePathPrefix() const {
#if PIXY_PLATFORM == PIXY_PLATFORM_APPLE
    return macBundlePath() + "/Contents/Plugins";
#elif PIXY_PLATFORM == PIXY_PLATFORM_WIN32
    return "./";
#else // UNIX
    return "../lib";
#endif
  }

}
