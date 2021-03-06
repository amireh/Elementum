/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_OgreRTT_H
#define H_OgreRTT_H

#include "Ogre.h"

namespace Pixy
{
  class OgreRTT// : public Ogre::RenderTargetListener
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

    protected:

    //virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
    //~ virtual void preRenderTargetUpdate(const Ogre::RenderTargetEvent& evt);
    //~ virtual void postRenderTargetUpdate(const Ogre::RenderTargetEvent& evt);

    Ogre::Camera* mCamera;
    Ogre::RenderWindow* mWindow;

    Ogre::MaterialPtr mMatPtr;
    Ogre::Technique *mMatTechnique;

    Ogre::Viewport *mViewport;
    Ogre::TexturePtr mTexture;
    Ogre::RenderTexture *mRenderTexture;
    Ogre::Rectangle2D *mMiniScreen;
    Ogre::SceneNode* mSceneNode;

    Ogre::SceneManager* mSceneMgr;

    bool fEnabled;

    static int gUID;
  };
}

#endif
