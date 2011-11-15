/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_Mobile_H
#define H_Mobile_H

#include "Pixy.h"
#include <Ogre.h>
#include <boost/function.hpp>
#include <boost/asio.hpp>

using Ogre::Real;
using Ogre::Vector3;
namespace Pixy
{
  //~ class Unit;
  class Renderable;
	class Mobile
	{
    public:

		Mobile();
		Mobile& operator=(const Mobile& rhs);
		Mobile(const Mobile& src);
		virtual ~Mobile();

    void move(int inWaypoint);

    void step(unsigned long dt);
    bool isMoving() const;

    void setWaypoints(std::vector<Vector3>* inWp);

    void setWalkSpeed(const float inSpeed);
    float getWalkSpeed() const;

    static void setDefaultWalkSpeed(const float inSpeed);
    static float getDefaultWalkSpeed();

    void rotateToEnemy();
    void rotateTo(const Ogre::Vector3& inDest);

    static void setRotationFactor(float inFactor);


		protected:

    /**
     * @brief
     * Registers the given SceneNode and Ogre Entity to be used for animating and
     * prepares the Mobile object.
     *
     * @warning
     * This function MUST be called before any usage of the Mobile instance.
     **/
    void setup(Renderable*);

    /**
     * @brief
     * Hooks a callback method that will be invoked when this entity is done moving
     **/
    void hookOnDoneMoving(boost::function<void(Mobile*)>);

    void copyFrom(const Mobile& src);

    private:

    bool fIsMoving;
    //! used  for tracking the Node's destination
    Vector3 mDestination;
    int mDestinationWP;
    //! used  for tracking and updating Node's direction while moving
    Vector3 mMoveDirection;
    //! used  for calculating the distance left to travel
    Real mMoveDistance;
    //! fixed speed to be used later by mMoveSpeed
    Real mWalkSpeed;
    //! regulates the movement speed by (mWalkSpeed * mTimeElapsed) keeping it consistent
    Real mMoveSpeed;
    std::vector<Vector3>* mWaypoints;
    static float mDefaultWalkSpeed;

    boost::function<void(Mobile*)> mCallback;

    bool setMoving(bool inMoving) {
      fIsMoving = inMoving;
    }

    bool doMove(unsigned long);

    /*!
     * \brief Informs whether the SceneNode has
     * reached its destination and updates the distance left, and the direction
     * the Node should be facing.
     * \note used by moveUnit()
     * @return true the Unit still has not reached its destination
     * @return false the Unit should not move further
     */
    bool nextLocation(int inDestination);

    Renderable *mRenderable;

    //Ogre::SceneNode *mSceneNode;
    //Ogre::Entity *mSceneObject;
    Ogre::RaySceneQuery *mRaySceneQuery;
    Ogre::SceneManager *mSceneMgr;

    // for rotation
    Ogre::Quaternion mOrientSrc;               // Initial orientation
    Ogre::Quaternion mOrientDest;              // Destination orientation
    Ogre::Real mRotProgress;                   // How far we've interpolated
    static Ogre::Real mRotFactor;                     // Interpolation step
    bool fRotating;

	}; // end of Mobile class
} // end of Pixy namespace
#endif
