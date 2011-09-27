# Locate Elementum Shared library
# This module defines
#  ParticleUniverse_FOUND, if false, do not try to link to ParticleUniverse
#  ParticleUniverse_LIBRARIES
#  ParticleUniverse_INCLUDE_DIR, where to find Pixy.h
#

SET(ParticleUniverse_PATHS
  /usr/local
  /opt/local
  C:/Workspace/Build/ParticleUniverse
)

FIND_PATH(ParticleUniverse_INCLUDE_DIRS ParticleUniverseSystem.h
  HINTS
  PATH_SUFFIXES include include/Plugins/ParticleUniverse include/OGRE/Plugins/ParticleUniverse
  PATHS
  ${ParticleUniverse_PATHS}
)

FIND_LIBRARY(ParticleUniverse_LIBRARY
  NAMES ParticleUniverse Plugin_ParticleUniverse
  HINTS
  PATH_SUFFIXES lib lib/OGRE lib/Release
  PATHS
  ${ParticleUniverse_PATHS}
)

IF(ParticleUniverse_LIBRARY)
  SET( ParticleUniverse_LIBRARIES "${ParticleUniverse_LIBRARY}" CACHE STRING "ParticleUniverse Libraries")
  MESSAGE(STATUS "Found ParticleUniverse libraries")
  MESSAGE(STATUS "Includes: ${ParticleUniverse_INCLUDE_DIRS}")
ELSE()
  MESSAGE(STATUS "Error! Could not find ParticleUniverse libraries")
ENDIF()

#INCLUDE(${CMAKE_CURRENT_LIST_DIR}/FindPackageHandleStandardArgs.cmake)
# handle the QUIETLY and REQUIRED arguments and set LUA_FOUND to TRUE if
# all listed variables are TRUE
#FIND_PACKAGE_HANDLE_STANDARD_ARGS(ParticleUniverse  DEFAULT_MSG  ParticleUniverse_LIBRARIES ParticleUniverse_INCLUDE_DIRS)

SET(ParticleUniverse_LIBRARY_DIR ${ParticleUniverse_PATHS})
MARK_AS_ADVANCED(ParticleUniverse_FOUND ParticleUniverse_INCLUDE_DIRS ParticleUniverse_LIBRARY_DIR ParticleUniverse_LIBRARIES ParticleUniverse_LIBRARY)
