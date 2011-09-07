# add sources
SET(Elementum_SRCS
  ${Elementum_SRCS}

  ../include/AudioEngine.h
  ../include/CDeck.h
  ../include/CEntity.h
  ../include/Combat.h
  ../include/Connection.hpp
  ../include/CPuppet.h
  ../include/CResourceManager.h
  ../include/CSpell.h
  ../include/CUnit.h
  ../include/Engine.h
  ../include/FxEngine.h
  ../include/GameManager.h
  ../include/GameState.h
  ../include/GfxEngine.h
  ../include/InputListener.h
  ../include/InputManager.h
  ../include/Intro.h
  ../include/Lobby.h
  ../include/NetworkManager.h
  ../include/PhyxEngine.h
  ../include/Renderable.h
  ../include/ScriptEngine.h
  ../include/UIEngine.h

  Connection.cpp

  Renderable.cpp
  CPuppet.cpp
  #CPuppetFactory.cpp
  CSpell.cpp
  CDeck.cpp
  CResourceManager.cpp
  CUnit.cpp
  #CUnitFactory.cpp
  Combat.cpp
  FxEngine.cpp
  GameManager.cpp
  GameState.cpp
  GfxEngine.cpp
  InputManager.cpp
  Intro.cpp
  #Lobby.cpp
  NetworkManager.cpp
  ScriptEngine.cpp
  UIEngine.cpp

  main.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/packages/lua_Elementum.cpp

  #${CMAKE_CURRENT_SOURCE_DIR}/UI/Tooltip.cpp
)

SET(PROJECT_LIBS
  ${Boost_LIBRARIES}
  ${LOG4CPP_LIBRARIES}
  ${LUA_LIBRARIES}
  ${ESHARED_LIBRARIES}

  #${OIS_LIBRARIES}
  #${CEGUI_LIBRARIES}
  #${OPENAL_LIBRARIES}
  #${OGG_LIBRARIES}
  #${VORBISFILE_LIBRARIES}
  #pqxx
  tolua++
  #OgreOggSound
  Plugin_ParticleUniverse
  #~ Caelum
  #PagedGeometry
  #OgreTerrain
)

if (APPLE)

  SET( PROJECT_FRAMEWORKS "-framework IOKit -framework Cocoa -framework Carbon -F/usr/local/lib/CEGUI -framework CEGUIBase -framework CEGUILuaScriptModule -framework CEGUIOgreRenderer -lOIS")
  
  LINK_LIBRARIES(${PROJECT_FRAMEWORKS})
  #LINK_DIRECTORIES(/usr/local/lib/OGRE /usr/local/lib/CEGUI)
  #LINK_LIBRARIES(ElementumLua ${PROJECT_FRAMEWORKS} tolua++ ${LUA_LIBRARIES})
else()
  LIST(APPEND PROJECT_LIBS
    ${OGRE_LIBRARIES}
    ${CEGUI_LIBRARIES}
    #CEGUI
    CEGUIOgreRenderer
    CEGUILuaScriptModule
    ${OIS_LIBRARIES}
  )
endif()
LINK_DIRECTORIES(#${OGRE_LIBRARY_DIRS}
                 #${OIS_LIBRARY_DIRS}
                 ${CEGUI_LIBRARY_DIRS}
                 #~ ${RakNet_LIBRARY_DIRS}
                 #${OPENAL_LIBRARY_DIRS}
                 #${OGG_INCLUDE_DIRS}
                 #${VORBISFILE_INCLUDE_DIRS}
                 ${ESHARED_LIBRARY_DIR}
                 /usr/local/lib/OGRE
                 /usr/local/lib/CEGUI
                 )
#LINK_LIBRARIES( ${PROJECT_NAME} ${PROJECT_LIBS} Elementum_Modules)

# generate lua bindings
ADD_CUSTOM_COMMAND(
  OUTPUT packages/lua_Elementum.cpp
  #TARGET ${PROJECT_NAME} PRE_BUILD
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/packages/parser.sh ${CMAKE_CURRENT_SOURCE_DIR}/packages
  "Generating lua bindings"
)
#LIST(APPEND Elementum_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/packages/lua_Elementum.cpp)

#message("Libs: " ${PROJECT_LIBS})

# the executable
SET(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../bin")
IF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  SET(CMAKE_INSTALL_PREFIX ${EXECUTABLE_OUTPUT_PATH} CACHE PATH "Elementum install prefix" FORCE)
ENDIF()

IF (APPLE)
  SET(ICNS_FILE ${CMAKE_CURRENT_SOURCE_DIR}/../resources/elementum.icns)
  SET(PLIST_FILE ${CMAKE_CURRENT_SOURCE_DIR}/../resources/ElementumInfo.plist.in)
  LIST(APPEND Elementum_SRCS ${ICNS_FILE})
  
ENDIF()

ADD_EXECUTABLE(Elementum MACOSX_BUNDLE WIN32 ${Elementum_SRCS})

SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_SOURCE_DIR}/packages/lua_Elementum.cpp PROPERTIES GENERATED 1)
TARGET_LINK_LIBRARIES(Elementum ${PROJECT_LIBS} Elementum_Modules)

ADD_CUSTOM_TARGET(ElementumLua DEPENDS packages/lua_Elementum.cpp)
IF(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/packages/lua_Elementum.cpp")
  MESSAGE(STATUS "Lua bindings is not yet generated, forcing generation. Generate manually using make ElementumLua")
  ADD_DEPENDENCIES(Elementum ElementumLua)
ENDIF()

# handle resources for Mac bundle
IF(APPLE)

  # ---
  # Generate Info.plist (see resources/cocoa/KarazehInfo.plist.in)
  # ---
  SET_TARGET_PROPERTIES(Elementum PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${PLIST_FILE})

  # ---
  # copy the icon
  # ---
  SET_SOURCE_FILES_PROPERTIES(
    ${ICNS_FILE}
		PROPERTIES
   	MACOSX_PACKAGE_LOCATION Resources)

  # ---
  # copy the frameworks & plugins
  # ---
  SET(OSX_DEPS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/osx)
  SET(OSX_FWK_PATH ${OSX_DEPS_PATH}/Frameworks)
  SET(OSX_PLUGINS_PATH ${OSX_DEPS_PATH}/Plugins)

ENDIF(APPLE)

#--------------------------------------------------------------------------------
# Install the QtTest application, on Apple, the bundle is at the root of the
# install tree, and on other platforms it'll go into the bin directory.
SET(plugin_dest_dir bin)

SET(APPS "\${CMAKE_INSTALL_PREFIX}/bin/Elementum")
IF(APPLE)
  SET(plugin_dest_dir Elementum.app/Contents)
  SET(res_dest_dir Elementum.app/Contents/Resources)
  SET(fwk_dest_dir Elementum.app/Contents)
  
  #SET(APPS "\${CMAKE_INSTALL_PREFIX}/bin/Elementum.app")
ENDIF(APPLE)
IF(WIN32)
  #SET(APPS "\${CMAKE_INSTALL_PREFIX}/bin/Elementum.exe")
ENDIF(WIN32)

# --------------------------------------------------------------------------------
# Copy dependencies for OS X (Frameworks, dylibs & bundles) into the bundle
INSTALL(DIRECTORY "${OSX_PLUGINS_PATH}" DESTINATION ${plugin_dest_dir} COMPONENT Runtime)
INSTALL(DIRECTORY "${OSX_FWK_PATH}" DESTINATION ${fwk_dest_dir} COMPONENT Runtime)
# Elementum shared libraries
INSTALL(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/lib" DESTINATION ${plugin_dest_dir} COMPONENT Runtime)
# Elementum modules library
INSTALL(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../lib" DESTINATION ${plugin_dest_dir} COMPONENT Runtime)

# install!
INSTALL(TARGETS Elementum 
  BUNDLE DESTINATION . COMPONENT Runtime
  RUNTIME DESTINATION bin COMPONENT Runtime
)
  
# To Create a package, one can run "cpack -G DragNDrop CPackConfig.cmake" on Mac OS X
# where CPackConfig.cmake is created by including CPack
# And then there's ways to customize this as well
set(CPACK_BINARY_DRAGNDROP ON)
include(CPack)