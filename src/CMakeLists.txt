# add sources
SET(EClient_SRCS
  ${EClient_SRCS}

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
  
  ${CMAKE_CURRENT_SOURCE_DIR}/packages/lua_EClient.cpp

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
  SET( PROJECT_FRAMEWORKS "-framework IOKit -framework Cocoa -F/usr/local/lib/CEGUI -framework CEGUIBase -framework CEGUILuaScriptModule -framework CEGUIOgreRenderer -lOIS")
  
  LINK_LIBRARIES(${PROJECT_FRAMEWORKS})
  #LINK_DIRECTORIES(/usr/local/lib/OGRE /usr/local/lib/CEGUI)
  #LINK_LIBRARIES(EClientLua ${PROJECT_FRAMEWORKS} tolua++ ${LUA_LIBRARIES})
else()
  LIST(APPEND PROJECT_LIBS 
    ${OGRE_LIBRARIES}
    
    CEGUI
    CEGUIOgreRenderer
    CEGUILuaScriptModule
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
#LINK_LIBRARIES( ${PROJECT_NAME} ${PROJECT_LIBS} EClient_Modules)

# generate lua bindings
ADD_CUSTOM_COMMAND(
  OUTPUT packages/lua_EClient.cpp
  #TARGET ${PROJECT_NAME} PRE_BUILD
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/packages/parser.sh ${CMAKE_CURRENT_SOURCE_DIR}/packages
  "Generating lua bindings"
)
#LIST(APPEND EClient_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/packages/lua_EClient.cpp)

#message("Libs: " ${PROJECT_LIBS})
# the executable
SET(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../bin")
IF (APPLE)
  ADD_EXECUTABLE(${PROJECT_NAME} MACOSX_BUNDLE ${EClient_SRCS} )
ELSE()
  ADD_EXECUTABLE(${PROJECT_NAME} ${EClient_SRCS} )
ENDIF()

SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_SOURCE_DIR}/packages/lua_EClient.cpp PROPERTIES GENERATED 1)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${PROJECT_LIBS} EClient_Modules)

ADD_CUSTOM_TARGET(EClientLua DEPENDS packages/lua_EClient.cpp)
IF(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/packages/lua_EClient.cpp")
  MESSAGE(STATUS "Lua bindings is not yet generated, forcing generation. Generate manually using make EClientLua")
  ADD_DEPENDENCIES(${PROJECT_NAME} EClientLua)
ENDIF()

