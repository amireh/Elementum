CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

IF(DEFINED CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel.")
ELSE()
  SET(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel.")
ENDIF()

INCLUDE (CheckIncludeFileCXX)
INCLUDE (CMakeDependentOption)

PROJECT(Elementum)

SET( CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  ${CMAKE_CURRENT_SOURCE_DIR}/CMake
  ${CMAKE_CURRENT_SOURCE_DIR}/CMake/Packages )

IF(APPLE)
  SET(ENV{CMAKE_OSX_ARCHITECTURES} "i386")
  SET(Boost_USE_STATIC_LIBS ON)
ENDIF()

IF(UNIX)
  ADD_DEFINITIONS("-std=c++0x")
ENDIF()

IF(WIN32)
  ADD_DEFINITIONS("-D_CRT_SECURE_NO_WARNINGS")
	set(Boost_USE_SHARED_LIBS ON)
ENDIF()

FIND_PACKAGE(PkgConfig)

set(Boost_USE_MULTITHREAD ON)
FIND_PACKAGE(Boost 1.46 COMPONENTS filesystem thread system date_time REQUIRED)
FIND_PACKAGE(log4cpp REQUIRED)
FIND_PACKAGE(Lua51 REQUIRED)
FIND_PACKAGE(EShared REQUIRED)
FIND_PACKAGE(OGRE REQUIRED)
FIND_PACKAGE(OIS REQUIRED)
FIND_PACKAGE(CEGUI REQUIRED)
FIND_PACKAGE(toluapp REQUIRED)
FIND_PACKAGE(ParticleUniverse REQUIRED)
#FIND_PACKAGE(OpenAL REQUIRED)
#FIND_PACKAGE(OGG REQUIRED)
#FIND_PACKAGE(VorbisFile REQUIRED)

# project version
SET( ${PROJECT_NAME}_MAJOR_VERSION 0 )
SET( ${PROJECT_NAME}_MINOR_VERSION 1 )
SET( ${PROJECT_NAME}_BUILD_LEVEL 1 )

#ADD_DEFINITIONS("-std=c++0x")
#SET(CMAKE_VERBOSE_MAKEFILE 1)

INCLUDE_DIRECTORIES(
  include
  modules/include
  modules/include/pixy
  ${Boost_INCLUDE_DIRS}
  ${LOG4CPP_INCLUDE_DIR}
  ${LUA_INCLUDE_DIR}
  ${TOLUAPP_INCLUDE_DIR}
  ${ESHARED_INCLUDE_DIRS}
  ${OGRE_INCLUDE_DIRS}
  ${OIS_INCLUDE_DIRS}
  ${CEGUI_INCLUDE_DIR}
  ${ParticleUniverse_INCLUDE_DIRS}
  /usr/local/include
  /usr/local/include/OGRE/Plugins/ParticleUniverse)

IF(WIN32)
  LINK_DIRECTORIES(${CEGUI_LIBRARY_DIRS} ${Boost_LIBRARY_DIRS})
  LINK_LIBRARIES(
    ${OGRE_LIBRARIES}
    ${LOG4CPP_LIBRARIES}
    ${LUA_LIBRARIES}
    ${TOLUAPP_LIBRARIES}
    ${CEGUI_LIBRARIES}
    ${CEGUI_LIBRARY}
    ${CEGUIOgre_LIBRARY}
    CEGUILuaScriptModule
    ${OIS_LIBRARIES})

ENDIF()

ADD_SUBDIRECTORY(modules)
ADD_SUBDIRECTORY(src)
