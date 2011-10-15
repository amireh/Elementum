/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#include "OgreRTT.h"
#include "GfxEngine.h"

namespace Pixy
{
  int OgreRTT::gUID = 0;

  OgreRTT::OgreRTT()
  : mWindow(0),
    mCamera(0),
    mMiniScreen(0)
  {
  }

  OgreRTT::~OgreRTT()
  {
    GfxEngine::getSingletonPtr()->detachRTT(this);
    this->disable();
    delete mMiniScreen;
    mSceneMgr->destroySceneNode(mSceneNode);
    Ogre::MaterialManager::getSingleton().remove(mMatPtr->getName());
    //~ Ogre::TextureManager::getSingleton().remove(mTexture->getName());

    //~ delete mMatTechnique;
    //~ mSceneNode = 0;

    //~ delete mRenderTexture;
  }

  void OgreRTT::setup(Ogre::SceneManager *inSceneMgr, Ogre::RenderWindow *inWindow, Ogre::Camera *inCamera)
  {
    mSceneMgr = inSceneMgr;
    mWindow = inWindow;
    mCamera = inCamera;

    using namespace Ogre;
    TexturePtr mTexture =
      TextureManager::getSingleton().createManual(
        "RttTex_" + gUID,
        ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        TEX_TYPE_2D,
        mWindow->getWidth(),
        mWindow->getHeight(),
        0,
        Ogre::PF_R8G8B8, Ogre::TU_RENDERTARGET);


    mRenderTexture = mTexture->getBuffer()->getRenderTarget();

    mViewport = mRenderTexture->addViewport(mCamera);
    mViewport->setVisibilityMask(GfxEngine::ENTITY_MASK);
    mViewport->setClearEveryFrame(true);
    mViewport->setBackgroundColour(Ogre::ColourValue::Black);
    mViewport->setOverlaysEnabled(false);

    // Create the rectangle
    mMiniScreen = new Ogre::Rectangle2D(true);
    mMiniScreen->setCorners(0.5f, -0.5f, 1.0f, -1.0f);
    mMiniScreen->setBoundingBox(Ogre::AxisAlignedBox(-100000.0f * Ogre::Vector3::UNIT_SCALE, 100000.0f * Ogre::Vector3::UNIT_SCALE));

    mSceneNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("MiniScreenNode_" + gUID);
    mSceneNode->attachObject(mMiniScreen);

    // Create the material
    mMatPtr = Ogre::MaterialManager::getSingleton().create("RttMat_" + gUID, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    mMatTechnique = mMatPtr->createTechnique();
    mMatTechnique->createPass();
    mMatPtr->getTechnique(0)->getPass(0)->setLightingEnabled(false);
    mMatPtr->getTechnique(0)->getPass(0)->createTextureUnitState("RttTex_" + gUID);

    mMiniScreen->setMaterial("RttMat_" + gUID);

    ++gUID;

    GfxEngine::getSingletonPtr()->attachRTT(this);
  }

  void OgreRTT::setCorners(Ogre::Real left, Ogre::Real right, Ogre::Real top, Ogre::Real bot)
  {
    assert(mMiniScreen);
    mMiniScreen->setCorners(left, right, top, bot);
  }

  void OgreRTT::enable()
  {
    mRenderTexture->addListener(GfxEngine::getSingletonPtr());
    fEnabled = true;
  }

  void OgreRTT::disable()
  {
    mRenderTexture->removeListener(GfxEngine::getSingletonPtr());
    fEnabled = false;
  }

  bool OgreRTT::isEnabled() const {
    return fEnabled;
  }

  void OgreRTT::hide()
  {
    mMiniScreen->setVisible(false);
  }

  void OgreRTT::show()
  {
    mMiniScreen->setVisible(true);
  }

}
