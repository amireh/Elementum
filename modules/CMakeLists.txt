SET(Elementum_Modules_INCLUDE_DIRS
  include
  include/cegui
  include/dotscene
  include/ogre
  include/tinyxml
  include/tinyxmlresource
  include/OgreMax

  include/pixy)

INCLUDE_DIRECTORIES(${Elementum_Modules_INCLUDE_DIRS})

# add sources
SET(Elementum_Modules_SRCS

  #src/dotscene/DotSceneLoader.cpp
  src/cegui/FormattedListboxTextItem.cpp

  src/tinyxmlresource/TinyXMLResource.cpp
  src/tinyxmlresource/TinyXMLResourceManager.cpp

  src/ogre/HDRCompositor.cpp
  src/ogre/HelperLogics.cpp
  src/ogre/MovableTextOverlay.cpp
  src/ogre/RectLayoutManager.cpp

  src/OgreMax/OgreMaxModel.cpp
  src/OgreMax/OgreMaxScene.cpp
  src/OgreMax/OgreMaxUtilities.cpp
  src/OgreMax/ProgressCalculator.cpp
  src/OgreMax/Version.cpp

  src/pixy/required.cpp
)

if(APPLE)
  LINK_LIBRARIES("-F/usr/local/lib/OGRE -framework Ogre -framework Cocoa")
else()
  #SET(PROJECT_LIBS PagedGeometry)
endif()

if(APPLE OR LINUX)
  LINK_DIRECTORIES(/usr/local/lib/OGRE /usr/local/lib)
endif()

IF(WIN32)
  SET(LIB_TYPE STATIC)
ELSE()
  SET(LIB_TYPE SHARED)
ENDIF()

LIST(APPEND PROJECT_LIBS ${ESHARED_LIBRARIES})

SET(LIBRARY_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../lib")
ADD_LIBRARY( Elementum_Modules ${LIB_TYPE} ${Elementum_Modules_SRCS} )
TARGET_LINK_LIBRARIES( Elementum_Modules ${PROJECT_LIBS} )

IF(APPLE)
  set_target_properties(Elementum_Modules
     PROPERTIES BUILD_WITH_INSTALL_RPATH 1
     INSTALL_NAME_DIR "@executable_path/../Plugins")
ENDIF()
