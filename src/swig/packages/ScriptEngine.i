/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

%module Pixy
%{
  #include "ScriptEngine.h"
%}

namespace Pixy {

  %nodefaultctor ScriptEngine;

  %rename(Log) ScriptEngine::luaLog;
	class ScriptEngine {

	public:
		virtual ~ScriptEngine();
		static ScriptEngine* getSingletonPtr();
		static ScriptEngine& getSingleton();

    std::string getScriptPathPrefix() const;
    std::string getModulePathPrefix() const;

    void callMeAfter(int inSeconds, std::string func);
    static void luaLog(std::string inMsg);

    int _passGameData();
    int _passPuppetListing();
    int _passPuppet();

    void _reportAccepted();
	};
}

%luacode {
  Pixy.Log = Pixy.ScriptEngine_Log
}
