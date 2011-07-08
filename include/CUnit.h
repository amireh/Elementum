#ifndef H_CUnit_H
#define H_CUnit_H

#include "Unit.h"
#include <Ogre.h>
#include <list>
#include <vector>

using std::list;
using std::vector;


using Ogre::Real;
using Ogre::Vector3;
namespace Pixy
{

  class Renderable;
	class CUnit : public Unit
	{
	public:
    CUnit();
    CUnit(const CUnit& src);
    CUnit& operator=(const CUnit& rhs);
    virtual ~CUnit();

    virtual Renderable* getRenderable();

    virtual bool live();
    virtual void die();

    void move(UNIT_POS inDestination);
    void update(unsigned long);

    bool isMoving() const {
      return fIsMoving;
    }

    UNIT_POS getPosition() const {
      return mPosition;
    }
    void setPosition(UNIT_POS inPos) {
      mPosition = inPos;
    }

    void setWaypoints(std::vector<Vector3>* inWp) {
      mWaypoints = inWp;
    }

	protected:
    Renderable* mRenderable;
    virtual void copyFrom(const CUnit& src);

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

    bool fIsMoving;
    UNIT_POS  mPosition, mPDestination;
    std::vector<Vector3>* mWaypoints;

    //! used by moveUnit() and nextLocation() for tracking the Node's destination
    Vector3 mDestination;
    //! used by moveUnit() and nextLocation() for tracking and updating Node's direction while moving
    Vector3 mMoveDirection;
    //! used by nextLocation() for calculating how much distance left to travel
    Real mMoveDistance;
    //! fixed speed to be used later by mMoveSpeed
    Real mWalkSpeed;
    //! regulates the movement speed by (mWalkSpeed * mTimeElapsed) keeping it consistent
    Real mMoveSpeed;
	};
} // end of namespace
#endif
