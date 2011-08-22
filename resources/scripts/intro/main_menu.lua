-- UISheet : MainMenu

-- package.path = package.path .. ";/Users/kandie/Workspace/Projects/Elementum/Client/Resources/UI/lua_scripts/?.lua;"
package.path = "./?.lua;../resources/scripts/?.lua;"

require("pixy")

Pixy.registerGlobals()

require("intro/login")

MainMenu = {}

MainMenu.attach = function()
	Layout = Pixy.UI.attach("intro/main_menu.layout")
end

MainMenu.detach = function()
	--CEWindowMgr:destroyWindow(Layout)
end

MainMenu.Play = function(e)
  --CESystem:executeScriptFile("Login.lua")
	MainMenu.detach()
	Login.attach()
end

MainMenu.Quit = function(e)
	MainMenu.detach()
  Intro:requestShutdown()
end

MainMenu.attach()
