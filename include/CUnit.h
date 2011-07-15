#ifndef H_CUnit_H
#define H_CUnit_H

#include "Unit.h"
#include "CSpell.h"
#include <Ogre.h>
#include <list>
#include <vector>
#include <boost/function.hpp>
#include <boost/asio.hpp>

using std::list;
using std::vector;


using Ogre::Real;
using Ogre::Vector3;
namespace Pixy
{
  class GfxEngine;
  class Renderable;
  class CPuppet;
	class CUnit : public Unit
	{
	public:
    typedef std::list<CSpell*> spells_t;

    CUnit();
    CUnit(const CUnit& src);
    CUnit& operator=(const CUnit& rhs);
    virtual ~CUnit();

    virtual Renderable* getRenderable();

    virtual bool live();
    virtual void die();

    void move(UNIT_POS inDestination, boost::function<void(CUnit*)> callback=0);
    void moveAndAttack(CPuppet* inTarget);
    void moveAndAttack(std::list<CUnit*> inBlockers);

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

    /// @note entities are responsible for destroying the spell objects they own
		spells_t const& getSpells();
		virtual int nrSpells();
		virtual CSpell* getSpell(int inUID);
    /// @warn ownership of the Spell pointer is transferred to the entity
    /// which means you can't invalidate throughout the lifetime of this entity
		virtual void attachSpell(CSpell* inSpell);
		virtual void detachSpell(int inUID);

    virtual bool attack(Pixy::CPuppet* inTarget, boost::function<void()> callback);
    virtual bool attack(Pixy::CUnit* inTarget, boost::function<void()> callback, bool block=false);

    //~ virtual bool attack(Pixy::CPuppet* inTarget);
    //~ virtual bool attack(Pixy::CUnit* inTarget, bool block=false);

    void updateTextOverlay();

    virtual void reset();

    void onVictory();

    virtual void rest();
    virtual void getUp();

    virtual void updateFromEvent(const Event& evt);

	protected:
    friend class GfxEngine;

    Renderable* mRenderable;
    virtual void copyFrom(const CUnit& src);

    bool setMoving(bool inMoving) {
      fIsMoving = inMoving;
    }

    bool doMove(unsigned long);

    // recursively goes through all the blockers and attacks them
    void doAttack(std::list<CUnit*>& inBlockers);



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

    //~ bool fDoneBlocking;

    typedef std::list<CUnit*> blockers_t;
    blockers_t mBlockers;

    boost::function<void(CUnit*)> mCallback;

    boost::asio::deadline_timer* mTimer;

    spells_t mSpells;
	};
} // end of namespace
#endif
