INCLUDE_DIRECTORIES(include include/dotscene include/ogre include/tinyxml include/tinyxmlresource include/OgreMax)
# add sources
SET(EClient_Modules_SRCS

  #src/dotscene/DotSceneLoader.cpp

  src/tinyxmlresource/TinyXMLResource.cpp
  src/tinyxmlresource/TinyXMLResourceManager.cpp

  src/ogre/HDRCompositor.cpp
  src/ogre/HelperLogics.cpp
  src/ogre/MovableTextOverlay.cpp

  src/OgreMax/OgreMaxModel.cpp
  src/OgreMax/OgreMaxScene.cpp
  src/OgreMax/OgreMaxUtilities.cpp
  src/OgreMax/ProgressCalculator.cpp
  src/OgreMax/Version.cpp
)

if(APPLE)
  LINK_LIBRARIES("-F/usr/local/lib/OGRE -framework Ogre -framework Cocoa -framework Carbon")
else()
  SET(PROJECT_LIBS 
    #PagedGeometry
    /usr/local/lib/OGRE/Ogre)
endif()

if(APPLE OR LINUX)
  LINK_DIRECTORIES(/usr/local/lib/OGRE /usr/local/lib)
endif()

LIST(APPEND PROJECT_LIBS ${ESHARED_LIBRARIES})
  
SET(LIBRARY_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../lib")
ADD_LIBRARY( EClient_Modules SHARED ${EClient_Modules_SRCS} )
TARGET_LINK_LIBRARIES( EClient_Modules ${PROJECT_LIBS} )
