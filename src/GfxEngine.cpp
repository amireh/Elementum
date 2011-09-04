/*
 *  GfxEngine.cpp
 *  Elementum
 *
 *  Created by Ahmad Amireh on 2/11/10.
 *  Copyright 2010 JU. All rights reserved.
 *
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
#include "ogre/HelperLogics.h"
#include "ogre/SdkCameraMan.h"
#include "ogre/HDRCompositor.h"
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
		//mSceneLoader = 0;
    mPlayer = 0;
    mEnemy = 0;
    inBlockPhase = false;
    mSelected = 0;
	}

	GfxEngine::~GfxEngine() {
		mLog->infoStream() << "shutting down";
		if (fSetup) {
			mRoot = 0;
			mSceneMgr = 0;
			mCamera = mCamera2 = mCamera3 = mCamera4 = 0;
			mViewport = 0;
			mRenderWindow = 0;

      delete mTrayMgr;

      delete attrs;

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

    //mSceneLoader = new DotSceneLoader();


		/*mPuppetPos[ME] = Vector3(0, 0, -50);
    mPuppetPos[ENEMY] =
      Vector3(mPuppetPos[ME].x,
							mPuppetPos[ME].y,
							mPuppetPos[ME].z + 100);
    */

    mCameraMan = new OgreBites::SdkCameraMan(mCamera);
	  mCameraMan->setStyle(OgreBites::CS_ORBIT);

	  Ogre::CompositorManager& compMgr = Ogre::CompositorManager::getSingleton();
		//~ compMgr.registerCompositorLogic("HDR", new HDRLogic);

	  //setupSky();
	  //setupWater();
    //setupTerrain();
    //setupLights();

    mTrayMgr = new SdkTrayManager("Elementum", mRenderWindow, InputManager::getSingletonPtr()->getMouse(), 0);
    mTrayMgr->hideCursor();

		mUpdate = &GfxEngine::updateNothing;
		mSelected = 0;
		fSetup = true;
		return fSetup;
	}

  void GfxEngine::setupMovableTextOverlays() {
    attrs =
      new MovableTextOverlayAttributes(
        "MTOAttributes",
        mCamera,
        mMTOFontName,mMTOFontSize,mMTOFontColor,mMTOMaterialName);
  }

	bool GfxEngine::setupCombat() {

		mLog->infoStream() << "preparing combat scene";

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


		std::ostringstream lNodeName;
		lNodeName << mPlayer->getName() << "_node_puppet";
		mCameraMan->setTarget(mSceneMgr->getSceneNode(lNodeName.str()));
    mCameraMan->setYawPitchDist(Ogre::Degree(mCameraYawPitchDist.x), Ogre::Degree(mCameraYawPitchDist.y), mCameraYawPitchDist.z);
    //mCamera->yaw(Ogre::Degree(-180));

		//Combat::getSingleton().updateGfx();
		mUpdate = &GfxEngine::updateCombat;

		return true;
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


		/*
		bool mFly = false;
		if (!mFly)
		{
		 */
			// clamp to terrain
			/*Vector3 camPos = mCamera->getPosition();
			Ray ray;
			ray.setOrigin(Vector3(camPos.x, 10000, camPos.z));
			ray.setDirection(Vector3::NEGATIVE_UNIT_Y);*/

			/*TerrainGroup::RayResult rayResult = mSceneLoader->getTerrainGroup()->rayIntersects(ray);
			Real distanceAboveTerrain = 50;
			Real fallSpeed = 300;
			Real newy = camPos.y;
			if (rayResult.hit)
			{
				if (camPos.y > rayResult.position.y + distanceAboveTerrain)
				{
					mFallVelocity += lTimeElapsed * 20;
					mFallVelocity = std::min(mFallVelocity, fallSpeed);
					newy = camPos.y - mFallVelocity * lTimeElapsed;

				}
				newy = std::max(rayResult.position.y + distanceAboveTerrain, newy);
				mCamera->setPosition(camPos.x, newy, camPos.z);

			}*/
		//}
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
        ownerName = mPlayer->getName();
        tmpPos = mPuppetPos[ME];
        tmpDir = mDirection[ME];
      } else {
        ownerName = mEnemy->getName();
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
        ownerName = mPlayer->getName();
        // define the starting position of the first node
        tmpPos = mPuppetPos[ME];
        tmpDir = mDirection[ME];
      } else {
        ownerName = mEnemy->getName();
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
	    mPlayer->getName() + "_node_defense",
	    mEnemy->getName() + "_node_defense"
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

    std::cout
      << "Waypoint for node: " << inOwner << "#" << inNode << ":\n"
      << "\tIdle: " << passivePos.x << "," << passivePos.y << "," << passivePos.z << "\n"
      << "\tCharging: " << chargingPos.x << "," << chargingPos.y << "," << chargingPos.z << "\n"
      << "\tBlock: " << defensePos.x << "," << defensePos.y << "," << defensePos.z << "\n"
      << "\tOffense: " << offensePos.x << "," << offensePos.y << "," << offensePos.z << "\n"
      << "\tAttack: " << attackPos.x << "," << attackPos.y << "," << attackPos.z << "\n";

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
    bool found = false;
    SceneNode* mNode;
    Ogre::Entity* mEntity;

    String entityName = "", nodeName = "", ownerName = "";

    //ownerName = (inEntity->getOwner() == ME) ? "host" : "client";
    //ownerName = stringify(inEntity->getUID());
    ownerName = inEntity->getOwner()->getName();
    if (isPuppet)
    {
      entityName = ownerName + "_entity_puppet";
      nodeName = ownerName + "_node_puppet";
      /* TO_DO: add functionality to retrieve entitie's mesh pathes from factory */

      mLog->debugStream() << "puppet node name " << nodeName;
      mNode = mSceneMgr->getSceneNode(nodeName);

      mEntity = mSceneMgr->createEntity(entityName, inEntity->getMesh());
      mEntity->setMaterialName(inEntity->getMaterial());

      mLog->debugStream() << "attaching user data to ogre entity";
      mEntity->setUserAny(Ogre::Any(inRenderable));

      mLog->infoStream() << "Attaching puppet entity " << mEntity->getName() << " to node " << mNode->getName();
      mNode->attachObject(mEntity);
      mNode->setScale(inRenderable->getScale());

      MovableTextOverlay *p =
        new MovableTextOverlay(mEntity->getName() + "_text"," Robot ", mEntity, attrs);
      p->enable(false); // make it invisible for now
      p->setUpdateFrequency(0.01);// set update frequency to 0.01 seconds
      inRenderable->setText(p);
      p = 0;

      inRenderable->attachSceneNode(mNode);
      inRenderable->attachSceneObject(mEntity);

      inRenderable->setup(mSceneMgr);

      static_cast<CPuppet*>(inEntity)->updateTextOverlay();

      mRenderables.push_back(inRenderable);

      return mSceneMgr->getSceneNode(nodeName);
    };

    // handle units
    entityName = ownerName + "_entity_" + stringify<int>(inEntity->getUID());
    // now we need to locate the nearest empty SceneNode
    // to render our Entity in
    int idNode;
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

    // now we've got our Node, create the Entity & attach
    if (found)
    {
      /* TO_DO */
      std::string _meshPath = "";
      mEntity = mSceneMgr->createEntity(entityName, inEntity->getMesh());
      mEntity->setMaterialName(inEntity->getMaterial());
      mEntity->setUserAny(Ogre::Any(inRenderable));
      mNode->attachObject(mEntity);
      mNode->setScale(inRenderable->getScale());

      MovableTextOverlay *p =
        new MovableTextOverlay(mEntity->getName() + "_text"," Robot ", mEntity, attrs);
      p->enable(false); // make it invisible for now
      p->setUpdateFrequency(0.01);// set update frequency to 0.01 seconds
      inRenderable->setText(p);
      p = 0;

      inRenderable->attachSceneNode(mNode);
      inRenderable->attachSceneObject(mEntity);

      inRenderable->setup(mSceneMgr);

      static_cast<CUnit*>(inEntity)->
        setWaypoints(&mWaypoints[inEntity->getOwner() == mPlayer ? 0 : 1][idNode]);

      static_cast<CUnit*>(inEntity)->updateTextOverlay();

      mRenderables.push_back(inRenderable);

      /* ugly 3-legged monkey hack: because I don't know what's happening,
       * some units scenenodes are getting translated to undefined positions
       * after units die and are re-attached, so here we force the node back
       * to its original position
       */
      mNode->setPosition(mWaypoints[inEntity->getOwner() == mPlayer ? 0 : 1][idNode][POS_READY]);

      return mNode;
      //mSceneMgr->getSceneNode(nodeName)->setUserAny(
    } else {
      mLog->errorStream() << "Could not attach Entity! No empty SceneNodes available";
      return NULL;
    }
    //LOG_F(__FUNCTION__);
  };


  bool GfxEngine::attachToScene(Renderable* inEntity)
  {
      //bool isPuppet = (inEntity->getRank() == 0) ? true : false;

      assert(inEntity->getEntity());
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
    FxEngine::getSingleton().dehighlight();

    Entity* inEntity = inRenderable->getEntity();

    Ogre::String ownerName = stringify(inEntity->getUID());// == ID_HOST) ? "host" : "client";
    Ogre::String nodeName = ownerName + "_node_";
    Ogre::String entityName = ownerName + "_entity_" + Ogre::StringConverter::toString(inEntity->getUID());
    Ogre::SceneNode* mTmpNode = NULL;

    mTmpNode = inRenderable->getSceneNode();

    // move the node back to its original spot
    if (inRenderable->getEntity()->getRank() != PUPPET)
      mTmpNode->translate(static_cast<CUnit*>(inRenderable->getEntity())->mWaypoints->front());

    mLog->debugStream() << "I'm detaching Entity '" << inEntity->getName() << "' from SceneNode : " + mTmpNode->getName();
    mTmpNode->showBoundingBox(false);
    mTmpNode->detachObject(inRenderable->getSceneObject());

    // destroy entity
    mSceneMgr->destroyEntity((Ogre::Entity*)inRenderable->getSceneObject());

    mRenderables.remove(inRenderable);

    if (inRenderable->getEntity()->getRank() != PUPPET)
      mUpdatees.erase(static_cast<CUnit*>(inRenderable->getEntity()));
      inEntity = 0;
  }

  void GfxEngine::changeOwnership(Pixy::CUnit* inUnit) {

    Renderable* inRenderable = inUnit->getRenderable();

    std::string ownerName = inUnit->getOwner()->getName();
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
      inUnit->setWaypoints(&mWaypoints[inUnit->getOwner() == mPlayer ? 0 : 1][idNode]);
      inUnit->move(POS_READY);

      FxEngine::getSingleton().dehighlight();

    } else {
      mLog->errorStream() << "Could not change Unit's ownership! No empty SceneNodes available";
    }
  }

  void GfxEngine::setupWaypoints()
  {
    for (int i=0; i<10; i++)
    {
      createWaypoint(ME, i, mPlayer->getName(), mEnemy->getName());
      createWaypoint(ENEMY, i, mEnemy->getName(), mPlayer->getName());
    };
  };

	bool GfxEngine::mouseMoved( const OIS::MouseEvent &e )
	{
		if (mCameraMan)
			mCameraMan->injectMouseMove(e);

    return true;
	}

	bool GfxEngine::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id )
	{
    // check if the mouse is over the UI hand (spell buttons)
    CEGUI::Window *window = CEGUI::System::getSingletonPtr()->getWindowContainingMouse();
    if (window && window->getName().find("SpellPanel") != CEGUI::String::npos)
      return false;

		if (mCameraMan)
			mCameraMan->injectMouseDown(e, id);

    CEGUI::Point mousePos = CEGUI::MouseCursor::getSingleton().getPosition();

    if (id != OIS::MB_Left)
      return false;

    // Setup the ray scene query, use CEGUI's mouse position
    Ogre::Ray mouseRay =
      mCamera->getCameraToViewportRay(
        mousePos.d_x/float(e.state.width),
        mousePos.d_y/float(e.state.height)
      );

    Ogre::RaySceneQuery *mRaySceneQuery = mSceneMgr->createRayQuery(Ogre::Ray());
    mRaySceneQuery->setRay(mouseRay);
    mRaySceneQuery->setSortByDistance(true);
    // Execute query
    Ogre::RaySceneQueryResult &result = mRaySceneQuery->execute();
    Ogre::RaySceneQueryResult::iterator itr;


    //dehighlight(); // remove any unit selection
    bool found = false;
    for (itr = result.begin(); itr != result.end(); itr++)
    {
      if (itr->movable)
        mLog->infoStream() << "Ray target name: " << itr->movable->getName();
      if (itr->movable &&
          (itr->movable->getName().find(mPlayer->getName()) != std::string::npos ||
          itr->movable->getName().find(mEnemy->getName()) != std::string::npos
          //(itr->movable->getName().find("Fx") == std::string::npos &&
          // itr->movable->getName().find("Blood") == std::string::npos)
          )
         /*(itr->movable->getName().substr(0,6) != "Caelum") &&
         itr->movable->getName() != "" &&
         //~ itr->movable->getName() != "mySphereEntity" &&
         itr->movable->getName() != "Floor" &&
         itr->movable->getName() != "Ceiling" &&
         itr->movable->getName() != "LeftWall" &&
         itr->movable->getName() != "RightWall" &&
         itr->movable->getName() != "FrontWall" &&
         itr->movable->getName() != "BackWall"*/) {

        Event e(EventUID::EntitySelected);
        e.Any = ((void*)Ogre::any_cast<Pixy::Renderable*>(itr->movable->getUserAny()));
        mEvtMgr->hook(e);

        found = true;

        break;

      }
    }
    if (!found) {
      // ignore any terrain selection
      dehighlight();
      FxEngine::getSingleton().dehighlight();
      ScriptEngine::getSingletonPtr()->passToLua("onEntityDeselected", 0);
    }

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
      /*case OIS::KC_H:
        tmp->pitch(Ogre::Degree(5));
      break;
      case OIS::KC_E:
        static_cast<CUnit*>(mSelected->getEntity())->move(POS_READY);
        break;
      case OIS::KC_R:
        static_cast<CUnit*>(mSelected->getEntity())->move(POS_CHARGING);
        break;
      case OIS::KC_T:
        static_cast<CUnit*>(mSelected->getEntity())->move(POS_DEFENCE);
        break;
      case OIS::KC_Y:
        static_cast<CUnit*>(mSelected->getEntity())->move(POS_OFFENCE);
        break;
      case OIS::KC_U:
        static_cast<CUnit*>(mSelected->getEntity())->move(POS_ATTACK);
        break;
      case OIS::KC_I:
        if (mRenderables.front()->getText()->isHidden())
          mRenderables.front()->show();
        else
          mRenderables.front()->hide();
        break;*/
      case OIS::KC_K:
        if (mTrayMgr->areFrameStatsVisible())
          mTrayMgr->hideFrameStats();
        else
          mTrayMgr->showFrameStats(OgreBites::TL_BOTTOMRIGHT);
        break;
        break;
    }
	}
	void GfxEngine::keyPressed( const OIS::KeyEvent &e ) {
	  if (mCameraMan)
			mCameraMan->injectKeyDown(e);
	}

	void GfxEngine::highlight(Renderable* inEntity) {
	  dehighlight();
	  mSelected = inEntity;
	  //~ mSelected->getSceneNode()->showBoundingBox(true);
	};

	void GfxEngine::dehighlight() {
	  if (!mSelected)
	    return;

	  //~ mSelected->getSceneNode()->showBoundingBox(false);
	  mSelected = 0;
	};

  bool GfxEngine::onEntitySelected(const Event& inEvt) {
    return inBlockPhase ? onEntitySelectedBlock(inEvt) : onEntitySelectedAttack(inEvt);
  }
  bool GfxEngine::onEntitySelectedAttack(const Event& inEvt) {
    Pixy::Renderable* lRend = static_cast<Pixy::Renderable*>(inEvt.Any);
    Pixy::Entity* lEntity = lRend->getEntity();

    std::cout << "selected a unit with UID: " << lEntity->getUID() << "\n";
     // double click on an entity
    if (mSelected && mSelected->getEntity()->getUID() == lEntity->getUID()) {
      std::cout << "got a double click\n";
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
        if (lUnit->getBaseAP() == 0)
          return true;

        // if the unit is passive, make it charge
        if (lUnit->getPosition() == POS_READY) {
          Event req(EventUID::Charge);
          req.setProperty("UID", lEntity->getUID());
          NetworkManager::getSingleton().send(req);


        } else if (lUnit->getPosition() == POS_CHARGING) {
          Event req(EventUID::CancelCharge);
          req.setProperty("UID", lEntity->getUID());
          NetworkManager::getSingleton().send(req);

        }

        lUnit = 0;
        dehighlight();
      }

      return true;
    }

    highlight(lRend);

    return true;
  }
  bool GfxEngine::onEntitySelectedBlock(const Event& inEvt) {
    Pixy::Renderable* lRend = static_cast<Pixy::Renderable*>(inEvt.Any);
    Pixy::Entity* lEntity = lRend->getEntity();

    // if it's a puppet, just de-select
    if (lEntity->getRank() == PUPPET) {
      highlight(lRend);
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
        lUnit->getPosition() == POS_CHARGING &&
        !static_cast<CUnit*>(mSelected->getEntity())->isResting())
    {
      Event req(EventUID::Block);
      req.setProperty("B", mSelected->getEntity()->getUID());
      req.setProperty("A", lUnit->getUID());
      NetworkManager::getSingleton().send(req);
    } else
      highlight(lRend);

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
    mUpdatees.find(inUnit)->second = false;
  }

  OgreMax::OgreMaxScene* GfxEngine::loadScene(std::string inSceneName) {
    using namespace OgreMax;
    OgreMaxScene* scene = new OgreMaxScene();
    scene->Load(inSceneName, mRenderWindow);

    return scene;
  }

  void GfxEngine::unloadScene(OgreMax::OgreMaxScene* inScene) {
    inScene->Destroy();
  }
}
