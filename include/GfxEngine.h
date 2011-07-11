/*
 *  GfxEngine.h
 *  Elementum
 *
 *  Created by Ahmad Amireh on 2/11/10.
 *  Copyright 2010 JU. All rights reserved.
 *
 */

#ifndef H_GfxEngine_H
#define H_GfxEngine_H

#include "Engine.h"
#include "EventListener.h"
#include "InputListener.h"

#include <Ogre.h>


// forward declarations
/*namespace Ogre {
  class Root;
  class Camera;
  class SceneManager;
  class Viewport;
  class RenderWindow;
  class OverlayManager;
  class Overlay;
  class Vector3;
  class Real;
  class SceneNode;
  class String;
}*/
namespace Hydrax {
  class Hydrax;
}
namespace Caelum {
  class CaelumSystem;
}
namespace OgreBites {
  class SdkCameraMan;
}

class HDRCompositor;
class DotSceneLoader;
class MovableTextOverlay;
class MovableTextOverlayAttributes;

using Ogre::Vector3;
using Ogre::Real;
using Ogre::SceneNode;
using Ogre::String;
using OgreBites::SdkCameraMan;
using Hydrax::Hydrax;
namespace Pixy {

  class CUnit;
  class CPuppet;
  class Renderable;
  class EventManager;
	/*! \class GfxEngine
	 *	\brief
	 *	Handles all graphics related features of the game, acts as the immediate
	 *	wrapper over OGRE3D. The game scene is entirely managed by and through
	 *	this Engine.
	 */
	class GfxEngine : public Engine, public EventListener, public InputListener {

	public:
		virtual ~GfxEngine();
		static GfxEngine* getSingletonPtr();


		virtual bool setup();
		virtual void update(unsigned long lTimeElapsed);
		virtual bool cleanup();

		void setCamera(const Ogre::String& inCameraName);

		//! Attaches a Pixy::Entity to an SceneNode and renders it
		/*!
		 * Called upon by CombatManager::createUnit();
		 * Determines the appropriate empty SceneNode in which to render
		 * the given inEntity. Moreover, "attaches" Pixy::Entity
		 * to the given Ogre::Entity for later retrieval, thus,
		 * linking the GameObject with SceneObject.
		 */
		bool attachToScene(Renderable* inEntity);

		//! Detaches a Pixy::Entity from an SceneNode and removes it from Scene
		/*!
		 * Called upon by CombatManager::destroyUnit();
		 * Detaches the Ogre::Entity from SceneNode;
		 * stops rendering it. Also detaches Pixy::Entity
		 * from the Ogre::Entity.
		 */
		void detachFromScene(Renderable* inEntity);

		//! Moves a SceneNode to a destination using a Waypoint
		/*!
		 * Moves a matching SceneNode to inDestination.
		 * @return true the node is still moving
		 * @return false the node is done moving
		 */
		//bool moveUnit(Unit* inUnit, int inDestination);

		SdkCameraMan* getCameraMan();
		Ogre::Camera* getCamera();
		Ogre::Root* getRoot();
		Ogre::SceneManager* getSceneMgr();
    Ogre::RenderWindow *getWindow();
		Ogre::Viewport* getViewport();

		//! Sets up OGRE SceneManager
		void setupSceneManager();

		//! Sets up OGRE Viewport to which our Camera will be attached
		void setupViewports();

		//! Sets up OGRE Camera, attaches it to Viewport, and fixes it position
		void setupCamera();

		//! Sets up OGRE Terrain, using terrain.cfg file for config
		void setupTerrain();

		//! Sets up OGRE Lights, attaches 2 spotlights, each for a Puppet respectively
		void setupLights();

		void setupWater();

		void setupSky();

		/*!
		 * \brief Sets up OGRE SceneNodes in which all of our GameObjects
		 * (Pixy::Entity, Unit, and Puppet) will be rendered.
		 *
		 * \note The position of these nodes are fixed throughout the Combat.
		 * \remarks
		 *  Each Puppet can own no more than 10 Units, thus we have
		 *  22 SceneNodes in total for Puppetes and Units in-game.
		 *  However, there are 3 more SceneNodes to account for,
		 *  which describe the position in which Units will be
		 *  taking action;
		 *  \li a) Shared_offence : is used by all Units in-game when
		 *      they are attacking a Unit that is blocking them.
		 *  \li b) Host_defence : is used by Host's Units when they
		 *      are blocking an Attacking unit.
		 *  \li c) Client_defence : like b), but for Client's Units
		 *      respectively.
		 */
		void setupNodes();

		//! Creates movement Waypoints for all SceneNodes in scene
		/*!
		 * Each SceneNode is attached to 5 "Waypoints" which
		 * describe it's position in a given state;
		 * Since Units have the ability to move to 5 different
		 * spots, this method defines the positions of these
		 * spots. Spots are:
		 * \li POS_PASSIVE
		 * \li POS_CHARGING
		 * \li POS_OFFENCE
		 * \li POS_ATTACK
		 * \li POS_BLOCK
		 */
		void setupWaypoints();

		bool setupCombat();

		void keyPressed( const OIS::KeyEvent &e );
		void keyReleased( const OIS::KeyEvent &e );

		void mouseMoved( const OIS::MouseEvent &e );
		void mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id );
		void mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id );

		Renderable* getSelected();

    void updateMe(CUnit*);
    void stopUpdatingMe(CUnit*);

	protected:
	  void (GfxEngine::*mUpdate)(unsigned long);

	  void updateNothing(unsigned long lTimeElapsed);
	  void updateCombat(unsigned long lTimeElapsed);

		Ogre::Root           *mRoot;
		Ogre::Camera         *mCamera, *mCamera2, *mCamera3, *mCamera4;
		Ogre::SceneManager   *mSceneMgr;
		Ogre::Viewport       *mViewport;
		Ogre::RenderWindow	 *mRenderWindow;
		Ogre::OverlayManager *mOverlayMgr;
		Ogre::Overlay        *mOverlay;
		EventManager		 *mEvtMgr;
		SdkCameraMan		 *mCameraMan;
		DotSceneLoader		 *mSceneLoader;
		Hydrax::Hydrax *mHydrax;
		Caelum::CaelumSystem *mCaelumSystem;
		HDRCompositor *mHDRComp;

    CPuppet *mPlayer, *mEnemy;

		Renderable* mSelected; // selected entity

		//! used for setting Puppetes' starting positions in Scene
		Vector3 mPuppetPos[2];
		//! used for setting Objects' direction in Scene
		Vector3 mDirection[2];
    Vector3 mPuppetScale, mUnitScale;

    typedef std::map<CUnit*, bool> updatees_t;
    updatees_t mUpdatees;

		/*!
		 * \brief Creates an Ogre::Entity and renders it in an
		 * appropriate SceneNode. Must not be called directly;
		 * only reachable via attachToScene()
		 */
		SceneNode* renderEntity(Renderable* inEntity);

		/*!
		 * \brief Creates a SceneNode with the given attributes
		 *
		 * \note used by setupNodes()
		 * @return the created SceneNode
		 */
		SceneNode* createNode(String& inName, Vector3& inPosition, Vector3& inScale, Vector3& inDirection, SceneNode* inParent=NULL);

    /*!
     * \brief Creates a list of 5 Waypoints for a matching SceneNode
     *
     * The waypoints are determined in relation to
     * the owner's Hero position, this way, if a Hero's
     * position changes, all the waypoints for Units are
     * changed accordingly.
     * \note used by setupWaypoints()
     */
    void createWaypoint(int inOwner, int inNode, std::string, std::string);

    std::vector<Ogre::Vector3> mWaypoints[2][10];

    std::list<Renderable*> mRenderables;

    MovableTextOverlayAttributes* attrs;

	  bool onEntitySelected(const Event&);
    bool onEntitySelectedAttack(const Event&);
    bool onEntitySelectedBlock(const Event&);

    bool onCharge(const Event&);
    bool onCancelCharge(const Event&);
    bool onBlock(const Event&);
    bool onCancelBlock(const Event&);
    bool onStartBlockPhase(const Event&);
    bool onEndBlockPhase(const Event&);

	  void highlight(Renderable* inEntity);
	  void dehighlight();

    bool inBlockPhase;

	private:
		static GfxEngine* _myGfxEngine;
		GfxEngine();
		GfxEngine(const GfxEngine& src);
		GfxEngine& operator=(const GfxEngine& rhs);
	};
}
#endif
