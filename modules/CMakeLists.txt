INCLUDE_DIRECTORIES(include include/dotscene include/ogre include/tinyxmlresource)
# add sources
SET(EClient_Modules_SRCS

  src/dotscene/DotSceneLoader.cpp

  src/tinyxmlresource/TinyXMLResource.cpp
  src/tinyxmlresource/TinyXMLResourceManager.cpp

  src/ogre/HDRCompositor.cpp
  src/ogre/HelperLogics.cpp
  src/ogre/MovableTextOverlay.cpp
)


SET(PROJECT_LIBS PagedGeometry)

LINK_DIRECTORIES(${OGRE_LIBRARY_DIRS} /usr/local/lib/OGRE)

SET(LIBRARY_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../lib")
ADD_LIBRARY( EClient_Modules SHARED ${EClient_Modules_SRCS} )
TARGET_LINK_LIBRARIES( EClient_Modules ${PROJECT_LIBS} )
