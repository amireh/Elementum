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
  #include "ogre/OgreRTT.h"
%}

%import(module="Ogre") "Ogre.i"

namespace Pixy {
  class OgreRTT
  {
    public:
    OgreRTT();
    virtual ~OgreRTT();

    void setup(Ogre::SceneManager *mSceneMgr, Ogre::RenderWindow *inWindow, Ogre::Camera *inCamera);
    void setCorners(Ogre::Real left, Ogre::Real right, Ogre::Real top, Ogre::Real bot);

    void enable();
    void disable();

    bool isEnabled() const;

    void hide();
    void show();
  };
}
