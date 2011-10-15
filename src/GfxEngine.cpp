/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#include "GfxEngine.h"
#include "GameManager.h"
#include "EventManager.h"
#include "CPuppet.h"
#include "CUnit.h"
#include "Renderable.h"
#include "Combat.h"
#include "UIEngine.h"
#include "NetworkManager.h"
#include "InputManager.h"
#include "FxEngine.h"
#include "ScriptEngine.h"
#include "OgreMax/OgreMaxScene.hpp"
#include "PixyUtility.h"
#include "ogre/MousePicker.h"
#include "ogre/OgreRTT.h"

#if PIXY_PLATFORM == PIXY_PLATFORM_APPLE
#include <CEGUI/CEGUI.h>
#include <CEGUI/CEGUISystem.h>
#include <CEGUI/CEGUISchemeManager.h>
#include <CEGUI/CEGUIInputEvent.h>
#else
#include <CEGUI/CEGUI.h>
#include <CEGUI/CEGUISystem.h>
#include <CEGUI/CEGUISchemeManager.h>
#include <CEGUI/CEGUIInputEvent.h>
#endif

#include <Ogre.h>
//#include <OGRE/Terrain/OgreTerrain.h>
//#include <OGRE/Terrain/OgreTerrainGroup.h>
//#include <OGRE/Plugins/OctreeSceneManager/OgreOctreeSceneManager.h>
//#include <OGRE/Plugins/Hydrax/Hydrax.h>
//#include <OGRE/Plugins/Caelum/Caelum.h>
//#include "Plugins/Hydrax/Hydrax.h"
//#include "Plugins/Hydrax/Noise/FFT/FFT.h"
//#include "Plugins/Hydrax/Noise/Perlin/Perlin.h"
//#include "Plugins/Hydrax/Noise/Real/Real.h"
//#include "Plugins/Hydrax/Modules/ProjectedGrid/ProjectedGrid.h"
//#include "Plugins/Hydrax/Modules/RadialGrid/RadialGrid.h"
//#include "Plugins/Hydrax/Modules/SimpleGrid/SimpleGrid.h"
//#include "Plugins/Caelum/CaelumSystem.h"

//#include "dotscene/DotSceneLoader.h"
//#include "ogre/HelperLogics.h"
#include "ogre/SdkCameraMan.h"
//#include "ogre/HDRCompositor.h"
#include "ogre/MovableTextOverlay.h"
#include "ogre/RectLayoutManager.h"
#include "ogre/OgreSdkTrays.h"


namespace Pixy {

	GfxEngine* GfxEngine::_myGfxEngine = NULL;

	GfxEngine* GfxEngine::getSingletonPtr() {
		if( !_myGfxEngine ) {
		    _myGfxEngine = new GfxEngine();
		}

		return _myGfxEngine;
	}

	GfxEngine::GfxEngine() {
		mLog = new log4cpp::FixedContextCategory(PIXY_LOG_CATEGORY, "GfxEngine");
		mLog->infoStream() << "firing up";
    mLog->infoStream() << "My Listener UID: " << mUID;

		fSetup = false;
		//mPlayers.clear();
		mCameraMan = 0;
    attrs = 0;
		//mSceneLoader = 0;
    mPlayer = 0;
    mEnemy = 0;
    inBlockPhase = false;
    mSelected = 0;
    mPicker = 0;
    mGenericPicker = 0;
    mPolyPicker = 0;
    mTrayMgr = 0;
    mCameraYawPitchDist = Ogre::Vector3::ZERO;
	}

	GfxEngine::~GfxEngine() {
		if (mLog)
      mLog->infoStream() << "shutting down";

		if (fSetup) {

      delete mGenericPicker;
      delete mPolyPicker;
      mGenericPicker = 0;
      mPolyPicker = 0;
      mPicker = 0;

      delete mCameraMan;
      mCameraMan = 0;

			mRoot = 0;
			mSceneMgr = 0;
			mCamera = mCamera2 = mCamera3 = mCamera4 = 0;
			mViewport = 0;
			mRenderWindow = 0;


      delete mTrayMgr;

      if (attrs)
        delete attrs;
      attrs = 0;

			delete mLog;
			mLog = 0;

			//if (mSceneLoader)
				//delete mSceneLoader;

			fSetup = false;
		}
	}

	bool GfxEngine::setup() {
		if (fSetup)
			return true;

		mLog->infoStream() << "Setting up";

		mRoot         = Ogre::Root::getSingletonPtr();
		//mOverlayMgr   = OverlayManager::getSingletonPtr();
		//if (mRoot->hasSceneManager(Ogre::ST_GENERIC))
		//	mSceneMgr     = mRoot->getSceneManager( ST_GENERIC, "CombatScene" );
		//else
		mSceneMgr = mRoot->createSceneManager("OctreeSceneManager", "CombatScene");

		mCamera       = mSceneMgr->createCamera("Combat_Camera");

		mRenderWindow = mRoot->getAutoCreatedWindow();

	  mViewport = mRenderWindow->addViewport(mCamera);

		mEvtMgr = EventManager::getSingletonPtr();

		bind(EventUID::EntitySelected, boost::bind(&GfxEngine::onEntitySelected, this, _1));
    bind(EventUID::StartBlockPhase, boost::bind(&GfxEngine::onStartBlockPhase, this, _1));
    bind(EventUID::Charge, boost::bind(&GfxEngine::onCharge, this, _1));
    bind(EventUID::CancelCharge, boost::bind(&GfxEngine::onCancelCharge, this, _1));
    bind(EventUID::Block, boost::bind(&GfxEngine::onBlock, this, _1));
    bind(EventUID::CancelBlock, boost::bind(&GfxEngine::onCancelBlock, this, _1));
    bind(EventUID::EndBlockPhase, boost::bind(&GfxEngine::onEndBlockPhase, this, _1));
    bind(EventUID::MatchFinished, boost::bind(&GfxEngine::onMatchFinished, this, _1));

    Ogre::MovableObject::setDefaultQueryFlags(TERRAIN_MASK);
    Ogre::MovableObject::setDefaultVisibilityFlags(TERRAIN_MASK);

    //mSceneLoader = new DotSceneLoader();


		/*mPuppetPos[ME] = Vector3(0, 0, -50);
    mPuppetPos[ENEMY] =
      Vector3(mPuppetPos[ME].x,
							mPuppetPos[ME].y,
							mPuppetPos[ME].z + 100);
    */

    mCameraMan = new OgreBites::SdkCameraMan(mCamera);
    mCameraMan->setStyle(OgreBites::CS_ORBIT);

	  //Ogre::CompositorManager& compMgr = Ogre::CompositorManager::getSingleton();
		//compMgr.registerCompositorLogic("HDR", new HDRLogic);



	  //setupSky();
	  //setupWater();
    //setupTerrain();
    //setupLights();

    mTrayMgr = new SdkTrayManager("Elementum", mRenderWindow, InputManager::getSingletonPtr()->getMouse(), 0);
    mTrayMgr->hideCursor();

    mGenericPicker = new GenericMousePicker(mSceneMgr);
    mPolyPicker = new PolyMousePicker(mSceneMgr);

    mPicker = (MousePicker*)mPolyPicker;

		mUpdate = &GfxEngine::updateIntro;

		mSelected = 0;
		fSetup = true;
		return fSetup;
	}

  void GfxEngine::setupMovableTextOverlays() {
    if (attrs)
    {
      delete attrs;
      attrs = 0;
    }

    attrs =
      new MovableTextOverlayAttributes(
        "MTOAttributes",
        mCamera,
        mMTOFontName,mMTOFontSize,mMTOFontColor,mMTOMaterialName);
  }

  bool GfxEngine::setupIntro()
  {
    if (!fSetup)
      setup();

    mRenderables.clear();
    mUpdatees.clear();
    mRTTs.clear();
    mPlayer = 0;
    mEnemy = 0;

    mUpdate = &GfxEngine::updateIntro;

    return true;
  }
	bool GfxEngine::setupCombat() {
    if (!fSetup)
      setup();

		mLog->infoStream() << "preparing combat scene";

    mRenderables.clear();
    mUpdatees.clear();
    mRTTs.clear();
    mPlayer = 0;
    mEnemy = 0;

    mPlayer = Combat::getSingleton().getPuppet();
    for (Combat::puppets_t::const_iterator puppet = Combat::getSingleton().getPuppets().begin();
         puppet != Combat::getSingleton().getPuppets().end();
         ++puppet)
      if ((*puppet)->getUID() != mPlayer->getUID()) {
        mEnemy = *puppet;
        break;
      }

    assert(mPlayer && mEnemy);

		//mPlayers.push_back(Combat::getSingleton().getPuppets().front()->getName());
		//mPlayers.push_back(Combat::getSingleton().getPuppets().back()->getName());

    setupNodes();
    setupWaypoints();

		//~ std::ostringstream lNodeName;
		//~ lNodeName << getNodeIdPrefix(mPlayer) << "_node_puppet";
    //~ assert(mSceneMgr->getSceneNode(lNodeName.str()));
    //~ setYawPitchDist(mCameraYawPitchDist);
    //~ mCameraMan->setStyle(OgreBites::CS_ORBIT);
    //~ trackNode(mSceneMgr->getSceneNode(lNodeName.str()));
    mCamera = mSceneMgr->getCamera("Combat_Camera");

    //mCamera->yaw(Ogre::Degree(-180));

		//Combat::getSingleton().updateGfx();
		mUpdate = &GfxEngine::updateCombat;

		return true;
	}

  void GfxEngine::trackNode(Ogre::SceneNode* inNode)
  {
    mCameraMan->setTarget(inNode);
  }

  void GfxEngine::setYawPitchDist(Ogre::Vector3 inVec)
  {
    mCameraYawPitchDist = inVec;
    mCameraMan->setYawPitchDist(Ogre::Degree(mCameraYawPitchDist.x), Ogre::Degree(mCameraYawPitchDist.y), mCameraYawPitchDist.z);
  }


	void GfxEngine::setCamera(const Ogre::String& inCameraName) {
		mCamera = mSceneMgr->createCamera(inCameraName);
	}

	SdkCameraMan* GfxEngine::getCameraMan() {
		return mCameraMan;
	}
	Ogre::Camera* GfxEngine::getCamera() {
		return mCamera;
	}

	Ogre::Root* GfxEngine::getRoot() {
		return mRoot;
	}

	Ogre::SceneManager* GfxEngine::getSceneMgr() {
		return mSceneMgr;
	}

  Ogre::RenderWindow* GfxEngine::getWindow() {
    return mRenderWindow;
  }

	Ogre::Viewport* GfxEngine::getViewport() {
		return mViewport;
	}

  Renderable* GfxEngine::getSelected() {
    return mSelected;
  }

	void GfxEngine::updateNothing(unsigned long lTimeElapsed) {

	};

	void GfxEngine::updateIntro(unsigned long lTimeElapsed) {
		//~ mCameraMan->update(lTimeElapsed);
		// update our good tray manager
    evt.timeSinceLastFrame = evt.timeSinceLastEvent = lTimeElapsed;
    mTrayMgr->frameRenderingQueued(evt);

		using namespace Ogre;

    // clean up updatees marked for removal
    updatees_t::iterator itr = mUpdatees.begin();
    for (itr = mUpdatees.begin(); itr != mUpdatees.end(); ++itr)
      if (itr->second)
        itr->first->update(lTimeElapsed);


    std::list<Renderable*>::const_iterator r;
    for (r = mRenderables.begin(); r != mRenderables.end(); ++r) {
      (*r)->updateAnimations(lTimeElapsed);
      (*r)->updateBody(lTimeElapsed);
    }

	};
	void GfxEngine::updateCombat(unsigned long lTimeElapsed) {
		mCameraMan->update(lTimeElapsed);
		// update our good tray manager
    evt.timeSinceLastFrame = evt.timeSinceLastEvent = lTimeElapsed;
    mTrayMgr->frameRenderingQueued(evt);

		using namespace Ogre;

    // clean up updatees marked for removal
    updatees_t::iterator itr = mUpdatees.begin();
    /*while (!cleaned) {
      if ((itr->second) == false) {
        mUpdatees.erase(itr);
        itr = mUpdatees.begin();
      }

      if (itr == mUpdatees.end())
        cleaned = true;

      ++itr;
    }*/

    for (itr = mUpdatees.begin(); itr != mUpdatees.end(); ++itr)
      if (itr->second)
        itr->first->update(lTimeElapsed);

    RectLayoutManager m(0,0,
      mCamera->getViewport()->getActualWidth(),
      mCamera->getViewport()->getActualHeight());
    m.setDepth(0);

    int visible=0;
    MovableTextOverlay *p=0;
    std::list<Renderable*>::const_iterator r;
    for (r = mRenderables.begin(); r != mRenderables.end(); ++r) {
      (*r)->updateAnimations(lTimeElapsed);
      (*r)->updateBody(lTimeElapsed);

      p = (*r)->getText();

      if (p->isHidden())
        continue;

      p->update(lTimeElapsed);

      if (p->isOnScreen()) {
      visible++;

      RectLayoutManager::Rect r(	p->getPixelsLeft(),
                p->getPixelsTop()+10,
                p->getPixelsRight(),
                p->getPixelsBottom()+10);

      RectLayoutManager::RectList::iterator it = m.addData(r);
      if (it != m.getListEnd())
      {
      //~ p->setPixelsTop((*it).getTop());
      p->enable(true);
      }
      else
      p->enable(false);
      }
      else
      p->enable(false);
    }


		//mCaelumSystem->updateSubcomponents(lTimeElapsed);
		/*mCaelumSystem->notifyCameraChanged(mCamera);
		*/

	};

	void GfxEngine::update(unsigned long lTimeElapsed) {
		processEvents();

		(this->*mUpdate)(lTimeElapsed);
	}

	bool GfxEngine::cleanup() {
	  mLog->infoStream() << "Cleaning up";

		return true;
	}


  void GfxEngine::setupSceneManager()
  {
  };

  void GfxEngine::loadDotScene(std::string inScene, std::string inName) {
    //assert(mSceneLoader);

    //mSceneLoader->parseDotScene(inScene, inName, mSceneMgr);
  }

  void GfxEngine::enableCompositorEffect(std::string inEffect) {
	  Ogre::CompositorManager::getSingleton().addCompositor(mViewport, inEffect);
	  Ogre::CompositorManager::getSingleton().setCompositorEnabled(mViewport, inEffect, true);
  }

  void GfxEngine::setupViewports()
  {
  };

  void GfxEngine::setupLights()
  {
  };

  void GfxEngine::createSphere(const std::string& strName, const float r, const int nRings, const int nSegments)
 {
   using namespace Ogre;
     MeshPtr pSphere = MeshManager::getSingleton().createManual(strName, ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
     SubMesh *pSphereVertex = pSphere->createSubMesh();

     pSphere->sharedVertexData = new VertexData();
     VertexData* vertexData = pSphere->sharedVertexData;

     // define the vertex format
     VertexDeclaration* vertexDecl = vertexData->vertexDeclaration;
     size_t currOffset = 0;
     // positions
     vertexDecl->addElement(0, currOffset, VET_FLOAT3, VES_POSITION);
     currOffset += VertexElement::getTypeSize(VET_FLOAT3);
     // normals
     vertexDecl->addElement(0, currOffset, VET_FLOAT3, VES_NORMAL);
     currOffset += VertexElement::getTypeSize(VET_FLOAT3);
     // two dimensional texture coordinates
     vertexDecl->addElement(0, currOffset, VET_FLOAT2, VES_TEXTURE_COORDINATES, 0);
     currOffset += VertexElement::getTypeSize(VET_FLOAT2);

     // allocate the vertex buffer
     vertexData->vertexCount = (nRings + 1) * (nSegments+1);
     HardwareVertexBufferSharedPtr vBuf = HardwareBufferManager::getSingleton().createVertexBuffer(vertexDecl->getVertexSize(0), vertexData->vertexCount, HardwareBuffer::HBU_STATIC_WRITE_ONLY, false);
     VertexBufferBinding* binding = vertexData->vertexBufferBinding;
     binding->setBinding(0, vBuf);
     float* pVertex = static_cast<float*>(vBuf->lock(HardwareBuffer::HBL_DISCARD));

     // allocate index buffer
     pSphereVertex->indexData->indexCount = 6 * nRings * (nSegments + 1);
     pSphereVertex->indexData->indexBuffer = HardwareBufferManager::getSingleton().createIndexBuffer(HardwareIndexBuffer::IT_16BIT, pSphereVertex->indexData->indexCount, HardwareBuffer::HBU_STATIC_WRITE_ONLY, false);
     HardwareIndexBufferSharedPtr iBuf = pSphereVertex->indexData->indexBuffer;
     unsigned short* pIndices = static_cast<unsigned short*>(iBuf->lock(HardwareBuffer::HBL_DISCARD));

     float fDeltaRingAngle = (Math::PI / nRings);
     float fDeltaSegAngle = (2 * Math::PI / nSegments);
     unsigned short wVerticeIndex = 0 ;

     // Generate the group of rings for the sphere
     for( int ring = 0; ring <= nRings; ring++ ) {
         float r0 = r * sinf (ring * fDeltaRingAngle);
         float y0 = r * cosf (ring * fDeltaRingAngle);

         // Generate the group of segments for the current ring
         for(int seg = 0; seg <= nSegments; seg++) {
             float x0 = r0 * sinf(seg * fDeltaSegAngle);
             float z0 = r0 * cosf(seg * fDeltaSegAngle);

             // Add one vertex to the strip which makes up the sphere
             *pVertex++ = x0;
             *pVertex++ = y0;
             *pVertex++ = z0;

             Vector3 vNormal = Vector3(x0, y0, z0).normalisedCopy();
             *pVertex++ = vNormal.x;
             *pVertex++ = vNormal.y;
             *pVertex++ = vNormal.z;

             *pVertex++ = (float) seg / (float) nSegments;
             *pVertex++ = (float) ring / (float) nRings;

             if (ring != nRings) {
                                // each vertex (except the last) has six indices pointing to it
                 *pIndices++ = wVerticeIndex + nSegments + 1;
                 *pIndices++ = wVerticeIndex;
                 *pIndices++ = wVerticeIndex + nSegments;
                 *pIndices++ = wVerticeIndex + nSegments + 1;
                 *pIndices++ = wVerticeIndex + 1;
                 *pIndices++ = wVerticeIndex;
                 wVerticeIndex ++;
             }
         }; // end for seg
     } // end for ring

     // Unlock
     vBuf->unlock();
     iBuf->unlock();
     // Generate face list
     pSphereVertex->useSharedVertices = true;

     // the original code was missing this line:
     pSphere->_setBounds( AxisAlignedBox( Vector3(-r, -r, -r), Vector3(r, r, r) ), false );
     pSphere->_setBoundingSphereRadius(r);
         // this line makes clear the mesh is loaded (avoids memory leaks)
         pSphere->load();
  }
  void GfxEngine::setupSky() {

    // skyz0rs
    //mLog->noticeStream() << "Setting up sky";
    //mSceneMgr->setSkyDome(true, "Elementum/Sky", 1, 1,5000,true);
    //mSceneMgr->setSkyBox(true, "Elementum/Sky", 5000, true);

    //~ createSphere("mySphereMesh", 1000, 64, 64);
    //~ Ogre::Entity* sphereEntity = mSceneMgr->createEntity("mySphereEntity", "mySphereMesh");
    //~ Ogre::SceneNode* sphereNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    //~ sphereEntity->setMaterialName("Elementum/Sky");
    //~ sphereNode->attachObject(sphereEntity);

    //~ sphereNode->roll(Ogre::Degree(180));
#if 0 // __DISABLED__ not using Caelum

    Ogre::ResourceGroupManager::getSingleton().initialiseResourceGroup("Caelum");

    // Pick components to create in the demo.
    // You can comment any of those and it should still work
    // Trying to disable one of these can be useful in finding problems.
    Caelum::CaelumSystem::CaelumComponent componentMask;
    componentMask = static_cast<Caelum::CaelumSystem::CaelumComponent> (
            //Caelum::CaelumSystem::CAELUM_COMPONENT_SUN |
            Caelum::CaelumSystem::CAELUM_COMPONENT_MOON |
            Caelum::CaelumSystem::CAELUM_COMPONENT_SKY_DOME |
            //Caelum::CaelumSystem::CAELUM_COMPONENT_IMAGE_STARFIELD |
            Caelum::CaelumSystem::CAELUM_COMPONENT_POINT_STARFIELD |
            Caelum::CaelumSystem::CAELUM_COMPONENT_CLOUDS |
            0);
    //componentMask = CaelumSystem::CAELUM_COMPONENTS_DEFAULT;

    // Initialise CaelumSystem.
    mCaelumSystem = new Caelum::CaelumSystem (mRoot, mSceneMgr, componentMask);
    mCaelumSystem->setSceneFogDensityMultiplier(0.001f); // or some other small value.
    //mCaelumSystem->setManageSceneFog(true);
    // Set time acceleration.
    mCaelumSystem->getUniversalClock()->setTimeScale (512);

    // Register caelum as a listener.
    mRenderWindow->addListener(mCaelumSystem);
    mRoot->addFrameListener(mCaelumSystem);

    /*mCaelumSystem =
    new CaelumSystem(mRoot, mSceneMgr, CaelumSystem::CAELUM_COMPONENTS_ALL);

    mCaelumSystem->setManageAmbientLight(false);*/

    //CaelumPlugin::getSingleton().loadCaelumSystemFromScript(mCaelumSystem, "Eclipse");

    //mCaelumSystem->attachViewport(mViewport);
#endif

  };

  /*void GfxEngine::setupWater() {
// Hydrax initialization code ---------------------------------------------
		// ------------------------------------------------------------------------

        // Create Hydrax object
		mHydrax = new Hydrax::Hydrax(mSceneMgr, mCamera, mViewport);

		// Create our projected grid module
		Hydrax::Module::ProjectedGrid *mModule
			= new Hydrax::Module::ProjectedGrid(// Hydrax parent pointer
			                                    mHydrax,
												// Noise module
			                                    new Hydrax::Noise::Real(),
												// Base plane
			                                    Ogre::Plane(Ogre::Vector3(0,1,0), Ogre::Vector3(0,0,0)),
												// Normal mode
												Hydrax::MaterialManager::NM_VERTEX,
												// Projected grid options
										        Hydrax::Module::ProjectedGrid::Options());

        // Add some waves
        static_cast<Hydrax::Noise::Real*>(mModule->getNoise())->addWave(
                                                Ogre::Vector2(1.f,0.f),
                                                0.3f,
                                                10.f);
        static_cast<Hydrax::Noise::Real*>(mModule->getNoise())->addWave(
                                                Ogre::Vector2(0.85f,0.15f),
                                                0.15f,
                                                8.f);
        static_cast<Hydrax::Noise::Real*>(mModule->getNoise())->addWave(
                                                Ogre::Vector2(0.95f,0.1f),
                                                0.1f,
                                                7.f);

		// Set our module
		mHydrax->setModule(static_cast<Hydrax::Module::Module*>(mModule));

		// Load all parameters from config file
		// Remarks: The config file must be in Hydrax resource group.
		// All parameters can be set/updated directly by code(Like previous versions),
		// but due to the high number of customizable parameters, since 0.4 version, Hydrax allows save/load config files.
		mHydrax->loadCfg("HydraxDemo.hdx");

    // Create water
    mHydrax->create();
  };*/

  void GfxEngine::setupCamera()
  {
	};



  void GfxEngine::setupTerrain()
  {
  };

  void GfxEngine::setupNodes()
  {
		mLog->debugStream() << "setting up nodes";
        /*
		 * Set up 22 nodes, 2 for Puppetes, and 20 for Units
		 * Each Puppet can own no more than 10 Units, and
		 * Entity positions are fixed throughout the game.
		 * Thus, the positions in which these Nodes are
		 * rendered are not to be changed.
		 * Worthy to note is that we will calculate each Node's
		 * position, and direction, using the respective owner
		 * Puppet's position.
		 */

		using Ogre::String;
    //Vector3 mPuppetScale, mUnitScale; // mPuppetPos[2], mDirection[2],

    // Define the scale to which the Models will be resized to
    //float scaleMod = 5.0f;
    //mPuppetScale = Vector3(scaleMod, scaleMod, scaleMod);
    //mUnitScale = Vector3(1.0f, 1.0f, 1.0f);

    // Set up the direction to make each faction face the other
    mDirection[ME] = mPuppetPos[ENEMY];
    mDirection[ENEMY] = mPuppetPos[ME];
    /*Vector3 mDirectionShared =
      Vector3(mPuppetPos[ME].x,
              mPuppetPos[ME].y,
              (mPuppetPos[ME].z + mPuppetPos[ENEMY].z) / 2);*/

    // create Puppet nodes
    String ownerName, nodeName;
    Vector3 tmpPos, tmpDir;
    for (int i=0; i<2; i++)
    {
      if (i == ME)
      {
        ownerName = getNodeIdPrefix(mPlayer);
        tmpPos = mPuppetPos[ME];
        tmpDir = mDirection[ME];
      } else {
        ownerName = getNodeIdPrefix(mEnemy);
        tmpPos = mPuppetPos[ENEMY];
        tmpDir = mDirection[ENEMY];
      }
      tmpPos.y *= mPuppetScale.y;
      nodeName = ownerName + "_node_puppet";
      Ogre::SceneNode* tmpNode = createNode(nodeName, tmpPos, mPuppetScale, tmpDir);
      mLog->debugStream() << "Node: " << nodeName << " at: (" << tmpPos.x << ", " << tmpPos.y << ", " << tmpPos.z << ")";
      if (i == ENEMY) {
        tmpNode->yaw(Ogre::Degree(180));
      }
    };

    // create Unit nodes
    Ogre::Real unitMargin, packMargin, posFrontier, posRear;
    for (int owner=0; owner<2; owner++)
    {
      if (owner == ME)
      {
        // start by creating client's nodes
        ownerName = getNodeIdPrefix(mPlayer);
        // define the starting position of the first node
        tmpPos = mPuppetPos[ME];
        tmpDir = mDirection[ME];
      } else {
        ownerName = getNodeIdPrefix(mEnemy);
        // define the starting position of the opponent first node
        tmpPos = mPuppetPos[ENEMY];
        tmpDir = mDirection[ENEMY];
      }

      //~ tmpPos.x += 10; // margin from the puppet
      //~ tmpPos.x += mPuppetMargin.x;
      tmpPos.x += mPackSpacing / 2;
      //~ tmpPos.z += (owner == ME) ? -50 : 50;
      tmpPos.z += (owner == ME) ? -mPuppetMargin.z : mPuppetMargin.z;

      //~ unitMargin = 10; // separate units by unitMargin space units on X axis
      unitMargin = mUnitMargin.x; // separate units by unitMargin space units on X axis
      //~ packMargin = 75; // separate "packs" of units by packMargin space units on X axis
      packMargin = mPackSpacing; // separate "packs" of units by packMargin space units on X axis
      posFrontier = tmpPos.z;
      //~ posRear = posFrontier+15; // more on this below
      posRear = posFrontier+mUnitMargin.z; // more on this below

      for (int i=0; i<10; i++)
      {

        /* define Unit position now;
         * Units will be grouped in packs of 5, resulting in
         * 2 "packs" of units for each Puppet, one to the left, other to the
         * right of Her. Units should be standing behind the Puppet,

         * However, each pack of units will be split in 2 rows, Frontier and Rear;
         * this way, we have a nicely aligned pack of 3 units in front,
         * and 2 in the back, split up from the other group.
         */

				// separate our "packs"
				if (i == 5)
				{
					tmpPos.x = mPuppetPos[ME].x - (mPackSpacing / 2);
					tmpPos.z = posFrontier;
					unitMargin *= -1; // negated so that nodes grow in the opposite direction
				}

				// split our pack into 2 rows
				tmpPos.z = (tmpPos.z == posFrontier) ? posRear : posFrontier;
				tmpPos.x += unitMargin;
				nodeName = ownerName + "_node_" + Ogre::StringConverter::toString(i);
				SceneNode* tmpNode = createNode(nodeName, tmpPos, mUnitScale, tmpDir);
        if (owner == ENEMY) {
          tmpNode->yaw(Ogre::Degree(180));
        }
				mLog->debugStream() << "Node: " << nodeName << " at: (" << tmpPos.x << ", " << tmpPos.y << ", " << tmpPos.z << ")";
      }; // end of for(i)
    }; // end of for(owner)

    // DEBUG ONLY
    // this is used because the models we use right now are bugged
    //mSceneMgr->getSceneNode("host_node_puppet")->setScale(Vector3(5,5,5));
    //mSceneMgr->getSceneNode("client_node_puppet")->setScale(Vector3(60,60,60));

    /* Create "combat" nodes now
     * These are shared throughout the game by all the Units
     * as the names describe, each node is attached to a certain - fixed -
     * position in which a certain action is taken
     */
    Vector3 offensePos, defensePos[2];
    offensePos =
    Vector3(mPuppetPos[ME].x,
            mPuppetPos[ME].y,
            (mPuppetPos[ME].z+mPuppetPos[ENEMY].z)/2);

    //~ defensePos[ME] =
    //~ Vector3(mPuppetPos[ME].x,
            //~ mPuppetPos[ME].y,
            //~ mPuppetPos[ME].z+5);

    //~ defensePos[ENEMY] =
    //~ Vector3(mPuppetPos[ENEMY].x,
            //~ mPuppetPos[ENEMY].y,
            //~ mPuppetPos[ENEMY].z-5);

    defensePos[ME] =
    Vector3(offensePos.x,
            offensePos.y,
            offensePos.z-5);

    defensePos[ENEMY] =
    Vector3(offensePos.x,
            offensePos.y,
            offensePos.z+5);

    Ogre::String tmpName[3] = {
	    "shared_node_offense",
	    getNodeIdPrefix(mPlayer) + "_node_defense",
	    getNodeIdPrefix(mEnemy) + "_node_defense"
		};

    createNode(tmpName[0],   offensePos,        mUnitScale, mDirection[ME]);
    createNode(tmpName[1],   defensePos[ME],    mUnitScale, mDirection[ENEMY]);
    createNode(tmpName[2],   defensePos[ENEMY], mUnitScale, mDirection[ME]);

  };

/* MOVING FUNCTIONS */
  void GfxEngine::createWaypoint(
    int inOwner,
    int inNode,
    std::string inOwnerName,
    std::string inOpponentName)
  {
    // Create the walking list
    // every unit "node" has 5 spots to move to
    // 1) Passive position (default, starts at it)
    // 2) Charging position (moved to when unit is told to attack/defend)
    // 3) Defensive position (1 shared node for all units under hero's control for defense)
    // 4) Offensive position (shared throughout the combat objects, there can be only 1 attacker at a time)
    // 5) Attack position (which is the defensive spot for the opponent hero in relation to the unit)
    //std::cout<<"Im setting up waypoints for"<<nodeOwner<<"@"<<nodeID<<"\n";

    std::vector<Ogre::Vector3>* mWalklist = &mWaypoints[inOwner][inNode];

    Vector3 passivePos, chargingPos, defensePos, offensePos, attackPos;
    Ogre::Real margin = 100;
    Ogre::String nodeName, heroNodeName;

    if (inOwner == ME)
    {
     //ownerName = Combat::getSingletonPtr()->getPuppetName();
     //opponentName = "enemy";
     margin *= -1;
     //~ mWalklist = &hWalklist[inIdNode];
    } else {
     //ownerName = "enemy";
     //opponentName = "player";
     //~ mWalklist = &cWalklist[inIdNode];
    }

    nodeName = inOwnerName + "_node_" + Ogre::StringConverter::toString(inNode);
    heroNodeName = inOwnerName + "_node_puppet";

    // Passive position
    passivePos = mSceneMgr->getSceneNode(nodeName)->getPosition();
    //passivePos.y /= (mPuppetScale.y);

    // Charging position
    chargingPos = passivePos;
    chargingPos.z = mSceneMgr->getSceneNode(inOwnerName + "_node_puppet")->getPosition().z;

    // Defence position
    defensePos = mSceneMgr->getSceneNode(inOwnerName + "_node_defense")->getPosition();
    defensePos.y = passivePos.y;

    // Offence position
    offensePos = mSceneMgr->getSceneNode("shared_node_offense")->getPosition();
    offensePos.y = passivePos.y;

    // Attack position
    attackPos = mSceneMgr->getSceneNode(inOpponentName + "_node_puppet")->getPosition();
    attackPos.z += (inOwner == ME) ? -5 : 5;
    attackPos.y = passivePos.y;

    //std::cout
    //  << "Waypoint for node: " << inOwner << "#" << inNode << ":\n"
    //  << "\tIdle: " << passivePos.x << "," << passivePos.y << "," << passivePos.z << "\n"
    //  << "\tCharging: " << chargingPos.x << "," << chargingPos.y << "," << chargingPos.z << "\n"
    //  << "\tBlock: " << defensePos.x << "," << defensePos.y << "," << defensePos.z << "\n"
    //  << "\tOffense: " << offensePos.x << "," << offensePos.y << "," << offensePos.z << "\n"
    //  << "\tAttack: " << attackPos.x << "," << attackPos.y << "," << attackPos.z << "\n";

    (*mWalklist).push_back(passivePos);
    (*mWalklist).push_back(chargingPos);
    (*mWalklist).push_back(defensePos);
    (*mWalklist).push_back(offensePos);
    (*mWalklist).push_back(attackPos);
  };

  Ogre::SceneNode* GfxEngine::createNode(String& inName, Vector3& inPosition, Vector3& inScale, Vector3& inDirection, Ogre::SceneNode* inParent)
  {
      Ogre::SceneNode* mNode;
      if (!inParent)
          inParent = mSceneMgr->getRootSceneNode();

      if (mSceneMgr->hasSceneNode(inName))
        mSceneMgr->destroySceneNode(inName);

      mNode = inParent->createChildSceneNode(inName, inPosition);
      mNode->setScale(inScale);
      //mNode->lookAt(inDirection, Ogre::Node::TS_WORLD);
      //~ mNode->showBoundingBox(true);

      //mNode = NULL;
      return mNode;
  };

  Ogre::SceneNode* GfxEngine::renderEntity(Renderable* inRenderable)
  {
    Entity* inEntity = inRenderable->getEntity();
    mLog->debugStream() << "rendering entity " << inEntity->getName();

    bool isPuppet = inEntity->getRank() == PUPPET;
    Ogre::SceneNode* mNode = 0;
    Ogre::Entity* mEntity = 0;
    int idNode = -1;

    String entityName = "", nodeName = "", ownerName = "";
    ownerName = getNodeIdPrefix(static_cast<CPuppet*>(inEntity->getOwner()->getOwner()));
    if (isPuppet)
    {
      entityName = ownerName + "_entity_puppet";
      nodeName = ownerName + "_node_puppet";

      mNode = mSceneMgr->getSceneNode(nodeName);
    } else
    {
      // handle units
      entityName = ownerName + "_entity_" + stringify(inEntity->getUID());
      // now we need to locate the nearest empty SceneNode
      Ogre::SceneNode* _node1 = 0;
      Ogre::SceneNode* _node2 = 0;
      for (int i=0; i<5; i++)
      {
        _node1 = mSceneMgr->getSceneNode( ownerName + "_node_" + stringify(i) );
        _node2 = mSceneMgr->getSceneNode( ownerName + "_node_" + stringify(i+5) );

        if (_node1->numAttachedObjects() == 0) {
          mNode = _node1;
          idNode = i;
        } else if(_node2->numAttachedObjects() == 0) {
          mNode = _node2;
          idNode = i+5;
        }

        if (mNode)
          break;
      }
    }

    if (!mNode)
    {
      mLog->errorStream() << "Could not attach Entity! No empty SceneNodes available";
      assert(false);
    }

    mEntity = mSceneMgr->createEntity(entityName, inEntity->getMesh());
    mEntity->setMaterialName(inEntity->getMaterial());
    mEntity->setQueryFlags(GfxEngine::ENTITY_MASK);
    mEntity->setVisibilityFlags(GfxEngine::ENTITY_MASK);
    mEntity->setRenderQueueGroup(Ogre::RENDER_QUEUE_8);
    mEntity->setUserAny(Ogre::Any(inRenderable));

    mNode->attachObject(mEntity);
    mNode->setScale(inRenderable->getScale());

    MovableTextOverlay *p =
      new MovableTextOverlay(mEntity->getName() + "_text"," Robot ", mEntity, attrs);
    p->enable(false); // make it invisible for now
    p->setUpdateFrequency(0.01f);// set update frequency to 0.01 seconds
    inRenderable->setText(p);
    p = 0;

    inRenderable->attachSceneNode(mNode);
    inRenderable->attachSceneObject(mEntity);

    inRenderable->setup(mSceneMgr);


    /* ugly 3-legged monkey hack: because I don't know what's happening,
     * some units scenenodes are getting translated to undefined positions
     * after units die and are re-attached, so here we force the node back
     * to its original position
     */
    if (!isPuppet){
      assert(idNode >= 0);
      std::vector<Ogre::Vector3>* lWaypoints = &mWaypoints[inEntity->getOwner()->getUID() == mPlayer->getUID() ? 0 : 1][idNode];

      static_cast<CUnit*>(inEntity)->setWaypoints(lWaypoints);
      mNode->setPosition((*lWaypoints)[POS_READY]);

      // update the MTO
      static_cast<CUnit*>(inEntity)->updateTextOverlay();
    } else
    {
      // update the MTO
      static_cast<CPuppet*>(inEntity)->updateTextOverlay();
    }

    mRenderables.push_back(inRenderable);

    return mNode;
  };


  bool GfxEngine::attachToScene(Renderable* inEntity)
  {
      //bool isPuppet = (inEntity->getRank() == 0) ? true : false;

      assert(inEntity->getEntity());

      if (GameManager::getSingleton().getCurrentState()->getId() != STATE_COMBAT)
      {
        mRenderables.push_back(inEntity);
        //~ MovableTextOverlay *p =
          //~ new MovableTextOverlay(inEntity->getEntity()->getName() + "_text"," Robot ", inEntity->getSceneObject(), attrs);
        //~ p->enable(false); // make it invisible for now
        //~ p->hide(true);
        //~ p->setUpdateFrequency(0.01);// set update frequency to 0.01 seconds
        //~ inEntity->setText(p);
        //~ p = 0;
      } else
        // render the object
        renderEntity(inEntity);
  /*
      // create and attach interface stats overlay
      if (!isPuppet)
          inEntity->attachSceneOverlay( mInterface->createUnitOverlay(inEntity) );
      else
          inEntity->attachSceneOverlay( mInterface->createPuppetOverlay(inEntity) );
  */
  return true;
  };



  void GfxEngine::detachFromScene(Renderable* inRenderable)
  {
    dehighlight();

    Entity* inEntity = inRenderable->getEntity();

    /*Ogre::String ownerName = stringify(inEntity->getUID());// == ID_HOST) ? "host" : "client";
    Ogre::String nodeName = ownerName + "_node_";
    Ogre::String entityName = ownerName + "_entity_" + Ogre::StringConverter::toString(inEntity->getUID());*/
    Ogre::SceneNode* mTmpNode = NULL;

    mTmpNode = inRenderable->getSceneNode();

    // move the node back to its original spot
    //~ if (inRenderable->getEntity()->getRank() != PUPPET
      //~ && GameManager::getSingleton().getCurrentState()->getId() == STATE_COMBAT)
      //~ mTmpNode->translate(static_cast<CUnit*>(inRenderable->getEntity())->mWaypoints->front());

    mLog->debugStream() << "I'm detaching Entity '" << inEntity->getName() << "' from SceneNode : " + mTmpNode->getName();
    mTmpNode->showBoundingBox(false);
    //~ mTmpNode->detachObject(inRenderable->getSceneObject());
    mTmpNode->detachAllObjects();

    // destroy entity
    mSceneMgr->destroyEntity((Ogre::Entity*)inRenderable->getSceneObject());

    mRenderables.remove(inRenderable);

    inRenderable->attachSceneNode(NULL);
    inRenderable->attachSceneObject(NULL);

    if (inRenderable->getEntity()->getRank() != PUPPET)
      mUpdatees.erase(static_cast<CUnit*>(inRenderable->getEntity()));
      inEntity = 0;
  }

  void GfxEngine::changeOwnership(Pixy::CUnit* inUnit) {

    Renderable* inRenderable = inUnit->getRenderable();

    std::string ownerName = getNodeIdPrefix(inUnit);
    std::string entityName = ownerName + "_entity_" + stringify<int>(inUnit->getUID());
    // now we need to locate the nearest empty SceneNode
    // to render our Entity in
    int idNode=0;
    bool found = false;
    std::string nodeName = "";
    Ogre::SceneNode* mNode = 0;
    for (int i=0; i<10; i++)
    {
      nodeName = ownerName + "_node_" + Ogre::StringConverter::toString(i);
      mNode = mSceneMgr->getSceneNode(nodeName);
      if (mNode->numAttachedObjects() == 0) {
        idNode = i;
        if (i < 5 &&
          mSceneMgr->getSceneNode(ownerName + "_node_" + Ogre::StringConverter::toString(i+5))->numAttachedObjects() == 0
        ) {
          idNode += 5;
          mNode = mSceneMgr->getSceneNode(ownerName + "_node_" + Ogre::StringConverter::toString(i+5));
        }
        found = true;
        break;
      }
    };

    if (found)
    {
      // This is being called directly by the spell handler, because for some
      // reason, pixy.lua:arbitraryFunc() can't find onEntityDeselected
      //
      // hack date: 09/05/2011
      //ScriptEngine::getSingletonPtr()->passToLua("onEntityDeselected", 0);

      // move the new node to the unit's current position
      Ogre::SceneNode* oldNode = inRenderable->getSceneNode();
      Ogre::Vector3 oldPos(oldNode->getPosition());
      mNode->setPosition(oldPos);

      // detach the unit from its current node and transfer to the new node
      inRenderable->getSceneNode()->detachObject(inRenderable->getSceneObject());
      mNode->attachObject(inRenderable->getSceneObject());
      mNode->setScale(inRenderable->getScale());
      inRenderable->attachSceneNode(mNode);
      oldNode->setPosition((*inUnit->mWaypoints)[POS_READY]);

      // move to the new ready position
      inUnit->setWaypoints(&mWaypoints[inUnit->getOwner()->getUID() == mPlayer->getUID() ? 0 : 1][idNode]);
      inUnit->move(POS_READY);

      //~ FxEngine::getSingleton().dehighlight();

    } else {
      throw std::runtime_error("gfxengine: could not change Unit's ownership! No empty SceneNodes available");
    }
  }

  void GfxEngine::setupWaypoints()
  {
    for (int i=0; i<10; i++)
    {
      createWaypoint(ME, i, getNodeIdPrefix(mPlayer), getNodeIdPrefix(mEnemy));
      createWaypoint(ENEMY, i, getNodeIdPrefix(mEnemy), getNodeIdPrefix(mPlayer));
    };
  };

	bool GfxEngine::mouseMoved( const OIS::MouseEvent &e )
	{
    // TODO: refactor this into two methods depending on states
    if (GameManager::getSingleton().getCurrentState()->getId() != STATE_COMBAT)
      return true;

		if (mCameraMan)
			mCameraMan->injectMouseMove(e);

    return true;
	}

	bool GfxEngine::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id )
	{
    // check if the mouse is over any UI element that wants to capture the input
    CEGUI::Window *window = CEGUI::System::getSingletonPtr()->getWindowContainingMouse();
    if (window)
    {
      typedef std::list<std::string> list_t;
      for (list_t::const_iterator itr = mUIInputCapturingElements.begin();
        itr != mUIInputCapturingElements.end();
        ++itr)
      {
        if (window->getName().find((*itr)) != CEGUI::String::npos) return false;
      }
    }

		if (mCameraMan)
			mCameraMan->injectMouseDown(e, id);

    CEGUI::Point mousePos = CEGUI::MouseCursor::getSingleton().getPosition();

    if (id != OIS::MB_Left)
      return false;

    Ogre::MovableObject *resultObj = 0;
    bool result = mPicker->cast( e, mousePos, mCamera, &resultObj, ENTITY_MASK);

    if (!result)
    {

      dehighlight();
      return true;
    }

    assert(resultObj);
    highlight(Ogre::any_cast<Pixy::Renderable*>(resultObj->getUserAny()));

    return true;

	}

	bool GfxEngine::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id )
	{
		if (mCameraMan)
			mCameraMan->injectMouseUp(e, id);

    return true;
	}

	void GfxEngine::keyReleased( const OIS::KeyEvent &e ) {
	  if (mCameraMan)
			mCameraMan->injectKeyUp(e);

    if (Combat::getSingleton().getPuppet() == 0)
      return;

    //SceneNode* tmp = Combat::getSingleton().getPuppet()->getRenderable()->getSceneNode();

    switch (e.key) {
      case OIS::KC_F:
        if (mSelected)
          mSelected->getSceneNode()->yaw(Ogre::Degree(15));
      break;
      case OIS::KC_G:
        if (mSelected)
          mSelected->rotateToEnemy();
        //tmp->roll(Ogre::Degree(5));
      break;
      case OIS::KC_H:
        //tmp->pitch(Ogre::Degree(5));
      break;
      case OIS::KC_E:
        if (mSelected && mSelected->getEntity()->getRank() != PUPPET)
          static_cast<CUnit*>(mSelected->getEntity())->move(POS_READY);
        break;
      case OIS::KC_R:
        if (mSelected && mSelected->getEntity()->getRank() != PUPPET)
          static_cast<CUnit*>(mSelected->getEntity())->move(POS_CHARGING);
        break;
      case OIS::KC_T:
        if (mSelected && mSelected->getEntity()->getRank() != PUPPET)
          static_cast<CUnit*>(mSelected->getEntity())->move(POS_DEFENCE);
        break;
      case OIS::KC_Y:
        if (mSelected && mSelected->getEntity()->getRank() != PUPPET)
          static_cast<CUnit*>(mSelected->getEntity())->move(POS_OFFENCE);
        break;
      case OIS::KC_U:
        if (mSelected && mSelected->getEntity()->getRank() != PUPPET)
          static_cast<CUnit*>(mSelected->getEntity())->move(POS_ATTACK);
        break;
      case OIS::KC_M:
        switchMousePickingMode();
        break;
      /*case OIS::KC_I:
        if (mRenderables.front()->getText()->isHidden())
          mRenderables.front()->show();
        else
          mRenderables.front()->hide();
        break;*/
      case OIS::KC_K:
        if (mTrayMgr->areFrameStatsVisible())
          mTrayMgr->hideFrameStats();
        else
          mTrayMgr->showFrameStats(OgreBites::TL_TOPRIGHT);
        break;
      case OIS::KC_L:
        //~ ScriptEngine::getSingletonPtr()->passToLua("onKeyReleased", 0);
        break;
      case OIS::KC_V:
        if (mSelected) {
          Ogre::Vector2 coords = getScreenCoords(mSelected->getSceneObject());
          mLog->infoStream() << "Model is at " << coords.x << "," << coords.y;
        }
        break;
    }
	}
	void GfxEngine::keyPressed( const OIS::KeyEvent &e ) {
	  if (mCameraMan)
			mCameraMan->injectKeyDown(e);
	}

	void GfxEngine::highlight(Renderable* inEntity) {
	  //~ dehighlight();

    if (inEntity->getEntity()->isDead() && GameManager::getSingleton().getCurrentState()->getId() == STATE_COMBAT) {
      std::cout << "will not select a dead entity!\n";
      return;
    }

    std::cout << "broadcasting entity selected!\n";
    Event e(EventUID::EntitySelected);
    e.Any = (void*)inEntity;
    mEvtMgr->hook(e);

	  //mSelected = inEntity;
	  //~ mSelected->getSceneNode()->showBoundingBox(true);
	};

	void GfxEngine::dehighlight() {
	  if (!mSelected)
	    return;

    //FxEngine::getSingleton().dehighlight();
    Event e(EventUID::EntityDeselected);
    e.Any = (void*)mSelected;
    mEvtMgr->hook(e);

    //ScriptEngine::getSingletonPtr()->passToLua("onEntityDeselected", 0);

	  //~ mSelected->getSceneNode()->showBoundingBox(false);
	  mSelected = 0;
	};

  bool GfxEngine::onEntitySelected(const Event& inEvt) {
    return inBlockPhase ? onEntitySelectedBlock(inEvt) : onEntitySelectedAttack(inEvt);
  }
  bool GfxEngine::onEntitySelectedAttack(const Event& inEvt) {
    Pixy::Renderable* lRend = static_cast<Pixy::Renderable*>(inEvt.Any);
    Pixy::Entity* lEntity = lRend->getEntity();

    //~ std::cout << "selected a unit with UID: " << lEntity->getUID() << "\n";
     // double click on an entity
    if (mSelected && mSelected->getEntity()->getUID() == lEntity->getUID()) {
      //~ std::cout << "got a double click\n";
      if (lEntity->getRank() != PUPPET) {
        CUnit *lUnit = static_cast<CUnit*>(lEntity);

        // make sure the unit is owned by the player not the opponent
        if (lUnit->getOwner() != mPlayer || lUnit->isResting()) {
          return true;
        }

        // if the unit is moving to anywhere, don't do anything
        if (lUnit->isMoving())
          return true;

        // if the unit has 0 AP, don't do anything
        if (lUnit->getBaseAP() == 0) {
          Event resp(EventUID::InvalidAction);
          resp.setProperty("Action", "Charge");
          resp.setProperty("Reason", "AttackerHasNoAP");
          mEvtMgr->hook(resp);
          return true;
        }

        // if the unit is passive, make it charge
        if (lUnit->getPosition() == POS_READY) {
          Event req(EventUID::Charge);
          req.setProperty("UID", lEntity->getUID());
          NetworkManager::getSingleton().send(req);

          // restless units can't not charge!
        } else if (lUnit->getPosition() == POS_CHARGING) {
          if (lUnit->isRestless()) {
            Event resp(EventUID::InvalidAction);
            resp.setProperty("Action", "Charge");
            resp.setProperty("Reason", "AttackerRestless");
            mEvtMgr->hook(resp);
          } else {
            Event req(EventUID::CancelCharge);
            req.setProperty("UID", lEntity->getUID());
            NetworkManager::getSingleton().send(req);
          }

        }

        lUnit = 0;
        dehighlight();
      }

      return true;
    }

    mSelected = lRend;

    //highlight(lRend);

    return true;
  }
  bool GfxEngine::onEntitySelectedBlock(const Event& inEvt) {
    Pixy::Renderable* lRend = static_cast<Pixy::Renderable*>(inEvt.Any);
    Pixy::Entity* lEntity = lRend->getEntity();

    // if it's a puppet, just de-select
    if (lEntity->getRank() == PUPPET) {
      mSelected = lRend;
      Event resp(EventUID::InvalidAction);
      resp.setProperty("Action", "Block");
      resp.setProperty("Reason", "InvalidTarget");
      mEvtMgr->hook(resp);
      //~ highlight(lRend);
      return true;
    }

    CUnit* lUnit = static_cast<CUnit*>(lEntity);

    // if an own unit is double-clicked and is blocking, cancel the block
    if (mSelected && mSelected == lRend) {
      if (lUnit->getOwner() == mPlayer && lUnit->getPosition() == POS_CHARGING) {
        Event req(EventUID::CancelBlock);
        req.setProperty("UID", lUnit->getUID());
        NetworkManager::getSingleton().send(req);
      }
      return true;
    }

    // only when an own unit is chosen and then a charging unit is chosen
    // will we trigger the block event
    if (mSelected &&
        mSelected->getEntity()->getRank() != PUPPET &&
        mSelected->getEntity()->getOwner() == mPlayer &&
        lUnit->getOwner() != mPlayer &&
        lUnit->getPosition() == POS_CHARGING
        //~ && !static_cast<CUnit*>(mSelected->getEntity())->isResting()
        )
    {
      // reject if the blocker is resting
      CUnit *unit = static_cast<CUnit*>(mSelected->getEntity());
      if (unit->isResting()) {
        Event resp(EventUID::InvalidAction);
        resp.setProperty("Action", "Block");
        resp.setProperty("Reason", "BlockerResting");
        mEvtMgr->hook(resp);
        return true;
      }

      // reject if the attacker is unblockable
      if (lUnit->isUnblockable()) {
        Event resp(EventUID::InvalidAction);
        resp.setProperty("Action", "Block");
        resp.setProperty("Reason", "AttackerUnblockable");
        mEvtMgr->hook(resp);
        return true;
      }

      Event req(EventUID::Block);
      req.setProperty("B", mSelected->getEntity()->getUID());
      req.setProperty("A", lUnit->getUID());
      NetworkManager::getSingleton().send(req);
    } else
      mSelected = lRend;

    return true;
  }

  bool GfxEngine::onStartBlockPhase(const Event& inEvt) {
    if (Combat::getSingleton().getActivePuppet() != mPlayer) {
      inBlockPhase = true;
      mLog->debugStream() << "entered blocking phase";
    }

    return true;
  }

  bool GfxEngine::onCharge(const Event& inEvt) {
    mLog->infoStream() << "charging with a unit";

    CUnit* lUnit = Combat::getSingleton().getUnit(convertTo<int>(inEvt.getProperty("UID")));

    lUnit->move(POS_CHARGING);

    return true;
  }

  bool GfxEngine::onCancelCharge(const Event& inEvt) {
    mLog->infoStream() << "no longer charging with a unit";

    CUnit* lUnit = Combat::getSingleton().getUnit(convertTo<int>(inEvt.getProperty("UID")));

    lUnit->move(POS_READY);

    return true;
  }

  bool GfxEngine::onBlock(const Event& inEvt) {
    mLog->infoStream() << "blocking with a unit";

    CUnit* lUnit = Combat::getSingleton().getUnit(convertTo<int>(inEvt.getProperty("B")));

    lUnit->move(POS_CHARGING);

    return true;
  }

  bool GfxEngine::onCancelBlock(const Event& inEvt) {
    mLog->infoStream() << "no longer blocking with a unit";

    CUnit* lUnit = Combat::getSingleton().getUnit(convertTo<int>(inEvt.getProperty("B")));
    lUnit->move(POS_READY);

    return true;
  }

  bool GfxEngine::onEndBlockPhase(const Event& inEvt) {
    if (Combat::getSingleton().getActivePuppet() != mPlayer) {
      inBlockPhase = false;
      mLog->debugStream() << "no longer in blocking phase";
    }

    return true;
  }

  bool GfxEngine::onMatchFinished(const Event& inEvt) {
    int wuid = convertTo<int>(inEvt.getProperty("W"));
    CPuppet* lWinner = 0;
    if (wuid == mPlayer->getUID())
      lWinner = mPlayer;
    else
      lWinner = mEnemy;

    mLog->infoStream() << "game is over! the winner is " << lWinner->getName();
    for (CPuppet::units_t::const_iterator unit = lWinner->getUnits().begin();
         unit != lWinner->getUnits().end();
         ++unit) {
      (*unit)->onVictory();
    }
    lWinner->onVictory();

    return true;
  }

  void GfxEngine::updateMe(CUnit* inUnit) {
    if (mUpdatees.find(inUnit) != mUpdatees.end()) {
      mUpdatees.find(inUnit)->second = true;
      return;
    }

    mUpdatees.insert(std::make_pair(inUnit, true));
  }

  void GfxEngine::stopUpdatingMe(CUnit* inUnit) {
    if (mUpdatees.find(inUnit) != mUpdatees.end())
      mUpdatees.find(inUnit)->second = false;
  }

  OgreMax::OgreMaxScene* GfxEngine::loadScene(std::string inSceneName) {
    using namespace OgreMax;
    OgreMaxScene* scene = new OgreMaxScene();
    scene->Load(inSceneName, mRenderWindow, OgreMaxScene::NO_OPTIONS, mSceneMgr, mSceneMgr->getRootSceneNode());

    return scene;
  }

  void GfxEngine::unloadScene(OgreMax::OgreMaxScene* inScene) {
    inScene->Destroy();
    delete inScene;
  }

  Ogre::Vector2 GfxEngine::getScreenCoords(Ogre::MovableObject* inObject) {
    using namespace Ogre;
    // get the projection of the object's AABB into screen space
    /*const Ogre::AxisAlignedBox& bbox = inObject->getWorldBoundingBox(true);
    Ogre::Matrix4 mat = mCamera->getViewMatrix();

    const Ogre::Vector3* corners = bbox.getAllCorners();

    float min_x = 1.0f, max_x = 0.0f, min_y = 1.0f, max_y = 0.0f;

    // expand the screen-space bounding-box so that it completely encloses
    // the object's AABB
    for (int i=0; i<8; i++) {
      Ogre::Vector3 corner = corners[i];

      // multiply the AABB corner vertex by the view matrix to
      // get a camera-space vertex
      corner = mat * corner;

      // make 2D relative/normalized coords from the view-space vertex
      // by dividing out the Z (depth) factor -- this is an approximation
      float x = corner.x / corner.z + 0.5;
      float y = corner.y / corner.z + 0.5;

      if (x < min_x)
          min_x = x;

      if (x > max_x)
          max_x = x;

      if (y < min_y)
          min_y = y;

      if (y > max_y)
          max_y = y;
    }

    return Ogre::Vector2(1-max_x, min_y);*/
    /*const Ogre::AxisAlignedBox &AABB = inObject->getWorldBoundingBox(true);// the AABB of the target
    Ogre::Vector3 opos = AABB.getCorner(Ogre::AxisAlignedBox::FAR_LEFT_TOP);
    Vector3 pos = mCamera->getProjectionMatrix() * (mCamera->getViewMatrix() * opos);
    return Vector2(
      1.0f - ((-pos.x+1)/2),
      //~ ((pos.x *0.5f) + 0.5f),
      //~ 1.0f - ((pos.y+1)/2));
      1.0f - ((pos.y * 0.5f) + 0.5f));*/


    /*Vector3 pos = inObject->getParentSceneNode()->_getDerivedPosition();

    Vector3 hcsPosition = mCamera->getProjectionMatrix() * (mCamera->getViewMatrix() * pos);
    //Vector3 eyeSpacePos = mCamera->getViewMatrix(true) * pos;
    Real x = 0;
    Real y = 0;

    x = ((hcsPosition.x * 0.5f) + 0.5f);// 0 <= x <= 1 // left := 0,right := 1
    y = 1.0f - ((hcsPosition.y * 0.5f) + 0.5f);// 0 <= y <= 1 // bottom := 0,top := 1

    return Vector2(x,y);*/


    Real MinX = 0;
    Real MinY = 0;
    Real MaxX = 0;
    Real MaxY = 0;

    Ogre::Real X[4];// the 2D dots of the AABB in screencoordinates
    Ogre::Real Y[4];

    if (!inObject->isInScene())
       return Vector2(0,0);

    const Ogre::AxisAlignedBox &AABB = inObject->getWorldBoundingBox(true);// the AABB of the target
    const Ogre::Vector3 CornersOfTopAABB[4] = {
      AABB.getCorner(AxisAlignedBox::FAR_LEFT_TOP),
      AABB.getCorner(AxisAlignedBox::FAR_RIGHT_TOP),
      AABB.getCorner(AxisAlignedBox::NEAR_LEFT_TOP),
      AABB.getCorner(AxisAlignedBox::NEAR_RIGHT_TOP)};

    Ogre::Vector3 CameraPlainNormal = mCamera->getDerivedOrientation().zAxis();//The normal vector of the plaine.this points directly infront of the cam

    Ogre::Plane CameraPlain = Plane(CameraPlainNormal,mCamera->getDerivedPosition());//the plaine that devides the space bevor and behin the cam

    for (int i = 0; i < 4; i++)
    {
      X[i] = 0;
      Y[i] = 0;


      Vector3 hcsPosition = mCamera->getProjectionMatrix() * (mCamera->getViewMatrix() * CornersOfTopAABB[i]);

      X[i] = 1.0f - ((hcsPosition.x * 0.5f) + 0.5f);// 0 <= x <= 1 // left := 0,right := 1
      Y[i] = ((hcsPosition.y * 0.5f) + 0.5f);// 0 <= y <= 1 // bottom := 0,top := 1
      //_getScreenCoordinates(CornersOfTopAABB[i],X[i],Y[i]);// transfor into 2d dots

      if (CameraPlain.getSide(CornersOfTopAABB[i]) == Plane::NEGATIVE_SIDE)
      {

       if (i == 0)// accept the first set of values, no matter how bad it might be.
       {
        MinX = X[i];
        MinY = Y[i];
        MaxX = X[i];
        MaxY = Y[i];
       }
       else// now compare if you get "better" values
       {
        if (MinX > X[i])// get the x minimum
        {
           MinX = X[i];
        }
        if (MinY > Y[i])// get the y minimum
        {
           MinY = Y[i];
        }
        if (MaxX < X[i])// get the x maximum
        {
           MaxX = X[i];
        }
        if (MaxY < Y[i])// get the y maximum
        {
           MaxY = Y[i];
        }
       }
      }
      else
      {
      MinX = 0;
      MinY = 0;
      MaxX = 0;
      MaxY = 0;
      break;
      }
    }
    Real relWidth = inObject->getWorldBoundingBox().getSize().x * 2 / Ogre::OverlayManager::getSingleton().getViewportWidth();
    return Vector2(1-(MinX + MaxX + 0.05f + relWidth )/2, 1-MaxY+0.05f);

  }

  std::string GfxEngine::getNodeIdPrefix(CPuppet* inEntity) {
    return std::string(inEntity->getName() + "_" + stringify(inEntity->getUID()));
  }
  std::string GfxEngine::getNodeIdPrefix(CUnit* inUnit) {
    return getNodeIdPrefix(static_cast<CPuppet*>(inUnit->getOwner()));
  }

  void GfxEngine::switchMousePickingMode()
  {
    mPicker = (mPicker == (MousePicker*)mPolyPicker) ? (MousePicker*)mGenericPicker : (MousePicker*)mPolyPicker;
  }

  int GfxEngine::getMousePickingMode() const
  {
    return (mPicker == (MousePicker*)mPolyPicker) ? POLY : GENERIC;
  };

  void GfxEngine::_setUserAny(Ogre::MovableObject* inObj, void* any)
  {
    inObj->setUserAny(Ogre::Any(any));
  }

  void GfxEngine::attachRTT(OgreRTT* inRTT)
  {
    mRTTs.push_back(inRTT);
  }
  void GfxEngine::detachRTT(OgreRTT* inRTT)
  {
    mRTTs.remove(inRTT);
  }


  void GfxEngine::preRenderTargetUpdate(const Ogre::RenderTargetEvent& evt)
  {
    mSceneMgr->getSceneNode("EntitySelectionNode")->setVisible(false);
    //~ mSceneMgr->getSceneNode("Scene")->setVisible(false);
    for (std::list<OgreRTT*>::iterator rtt = mRTTs.begin(); rtt != mRTTs.end(); ++rtt)
      (*rtt)->hide();
    //~ mMiniScreen->setVisible(false);
  }

  void GfxEngine::postRenderTargetUpdate(const Ogre::RenderTargetEvent& evt)
  {
    mSceneMgr->getSceneNode("EntitySelectionNode")->setVisible(true);
    //~ mSceneMgr->getSceneNode("Scene")->setVisible(true);
    for (std::list<OgreRTT*>::iterator rtt = mRTTs.begin(); rtt != mRTTs.end(); ++rtt)
      (*rtt)->show();
    //~ mMiniScreen->setVisible(true);
  }

  void GfxEngine::disableMouseCaptureOverUIElement(std::string const& inElementName)
  {
    // make sure the element isn't already tracked
    std::list<std::string>::const_iterator itr;
    for (itr = mUIInputCapturingElements.begin();
      itr != mUIInputCapturingElements.end();
      ++itr)
      if ((*itr) == inElementName) return;

    mUIInputCapturingElements.push_back(inElementName);
  }
  void GfxEngine::enableMouseCaptureOverUIElement(std::string const& inElementName)
  {
    mUIInputCapturingElements.remove(inElementName);
  }
}
