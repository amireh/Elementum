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
  #include "GfxEngine.h"
%}

namespace OgreMax {
  class OgreMaxScene;
}
namespace OgreBites {
  class SdkCameraMan;
  class SdkTrayManager;
}

class HDRCompositor;

class MovableTextOverlay;
class MovableTextOverlayAttributes;

using Ogre::Vector3;
using Ogre::Real;
using Ogre::SceneNode;
using Ogre::String;
using OgreBites::SdkCameraMan;
using OgreBites::SdkTrayManager;
namespace Pixy {

  %nodefaultctor GfxEngine;

  class Mobile;
  class Animable;
  class Entity;
  class Unit;
  class Puppet;
  class EventManager;
  class MousePicker;
  class GenericMousePicker;
  class PolyMousePicker;
  class OgreRTT;
	class GfxEngine {

	public:

    enum QueryFlags {
      TERRAIN_MASK = 1<<0,
      ENTITY_MASK = 1<<1
    };

    enum MousePickingMode {
      GENERIC,
      POLY
    };

		static GfxEngine* getSingletonPtr();

    Ogre::ColourValue mMTOFontColor;
    Ogre::String mMTOFontName;
    int mMTOFontSize;
    Ogre::String mMTOMaterialName;
		//! used for setting Puppetes' starting positions in Scene
		Vector3 mPuppetPos[2];
		Vector3 mPuppetScale, mUnitScale;

    Vector3 mUnitMargin;
    Vector3 mPuppetMargin;
    int mPackSpacing;

    Vector3 mCameraYawPitchDist;

    void disableMouseCaptureOverUIElement(std::string const& inElementName);
    void enableMouseCaptureOverUIElement(std::string const& inElementName);

		void setCamera(const Ogre::String& inCameraName);

    void createSphere(const std::string& strName, const float r, const int nRings = 16, const int nSegments = 16);

    void switchMousePickingMode();
    int getMousePickingMode() const;

		bool attachToScene(Entity* inEntity);
		void detachFromScene(Entity* inEntity);

    void setupMovableTextOverlays();

		SdkCameraMan* getCameraMan();
		Ogre::Camera* getCamera();
		Ogre::Root* getRoot();
		Ogre::SceneManager* getSceneMgr();
    Ogre::RenderWindow *getWindow();
		Ogre::Viewport* getViewport();

		Entity* getSelected();

    void updateMe(Mobile*);
    void stopUpdatingMe(Mobile*);

    void changeOwnership(Pixy::Unit*);

    OgreMax::OgreMaxScene* loadScene(std::string inOgreMaxScene);
    void unloadScene(OgreMax::OgreMaxScene* inScene);

    void enableCompositorEffect(std::string inEffect);

    void loadDotScene(std::string inScene, std::string inName);

    Ogre::Vector2 getScreenCoords(Ogre::MovableObject* inObject);

    void setYawPitchDist(Ogre::Vector3 inVec);
    void trackNode(Ogre::SceneNode* inNode);

    void _setUserAny(Ogre::MovableObject*, void*);

    void attachRTT(OgreRTT*);
    void detachRTT(OgreRTT*);

	};
}
