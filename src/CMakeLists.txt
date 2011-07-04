# add sources
SET(EClient_SRCS
  ${EClient_SRCS}

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
  GameManager.cpp
  GameState.cpp
  GfxEngine.cpp
  InputManager.cpp
  #Intro.cpp
  #Lobby.cpp
  NetworkManager.cpp
  ScriptEngine.cpp
  UIEngine.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/UI/RenderInterfaceOgre3D.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/UI/SystemInterfaceOgre3D.cpp

  main.cpp

  #${CMAKE_CURRENT_SOURCE_DIR}/packages/lua_EClient.cpp
)

SET(PROJECT_LIBS
  #~ ${RakNet_LIBRARIES}
  ${Boost_LIBRARIES}
  ${LOG4CPP_LIBRARIES}
  ${LUA_LIBRARIES}
  ${ESHARED_LIBRARIES}
  ${OGRE_LIBRARIES}
  ${OIS_LIBRARIES}
  #${CEGUI_LIBRARIES}
  ${OPENAL_LIBRARIES}
  ${OGG_LIBRARIES}
  ${VORBISFILE_LIBRARIES}
  pqxx
  tolua++
  #CEGUIOgreRenderer
  #CEGUILuaScriptModule
  OgreOggSound
  ParticleUniverse
  Caelum
  #PagedGeometry
  OgreTerrain
  RocketCore
  RocketControls
  RocketDebugger
)

LINK_DIRECTORIES(${OGRE_LIBRARY_DIRS}
                 ${OIS_LIBRARY_DIRS}
                 #${CEGUI_LIBRARY_DIRS}
                 #~ ${RakNet_LIBRARY_DIRS}
                 ${OPENAL_LIBRARY_DIRS}
                 ${OGG_INCLUDE_DIRS}
                 ${VORBISFILE_INCLUDE_DIRS}
                 ${ESHARED_LIBRARY_DIR}
                 /usr/local/lib/OGRE)
#LINK_LIBRARIES( ${PROJECT_NAME} ${PROJECT_LIBS})

# generate lua bindings
ADD_CUSTOM_COMMAND(
  OUTPUT packages/lua_EClient.cpp
  #TARGET ${PROJECT_NAME} PRE_BUILD
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/packages/parser.sh ${CMAKE_CURRENT_SOURCE_DIR}/packages
  "Generating lua bindings"
  #DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/bar.c
)
#LIST(APPEND EClient_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/packages/lua_EClient.cpp)

# the executable
SET(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../bin")
ADD_EXECUTABLE(${PROJECT_NAME} ${EClient_SRCS} ${CMAKE_CURRENT_SOURCE_DIR}/packages/lua_EClient.cpp)
SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_SOURCE_DIR}/packages/lua_EClient.cpp PROPERTIES GENERATED 1)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${PROJECT_LIBS} EClient_Modules)

ADD_CUSTOM_TARGET(EClientLua DEPENDS packages/lua_EClient.cpp)
IF(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/packages/lua_EClient.cpp")
  MESSAGE(STATUS "Lua bindings is not yet generated, forcing generation. Generate manually using make EClientLua")
  ADD_DEPENDENCIES(${PROJECT_NAME} EClientLua)
ENDIF()

