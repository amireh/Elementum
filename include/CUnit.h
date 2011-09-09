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

    bool fRequiresYawFix;

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

    CPuppet* getEnemy() const {
      assert(mEnemy);
      return mEnemy;
    };

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


    virtual void setIsTrampling(bool inF);
    virtual void setIsUnblockable(bool inF);
    virtual void setIsRestless(bool inF);
    virtual void setHasFirstStrike(bool inF);
    virtual void setHasLifetap(bool inF);

    virtual void setHP(int inU);
    virtual void setBaseHP(int inU);
    virtual void setBaseAP(int inU);

    /// @note entities are responsible for destroying the spell objects they own
		spells_t const& getSpells();
		virtual int nrSpells();
		virtual CSpell* getSpell(int inUID);
    /// @warn ownership of the Spell pointer is transferred to the entity
    /// which means you can't invalidate throughout the lifetime of this entity
		virtual void attachSpell(CSpell* inSpell);
		virtual void detachSpell(int inUID, bool remove=true);

    spells_t const& getBuffs() const;
    virtual void attachBuff(CSpell*);
    virtual void detachBuff(int inUID);
    virtual bool hasBuff(int inUID);

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

    bool isDying() const;

    void setWalkSpeed(const float inSpeed);
    float getWalkSpeed() const;

    static void setDefaultWalkSpeed(const float inSpeed);
    static float getDefaultWalkSpeed();

	protected:
    friend class GfxEngine;

    Renderable* mRenderable;
    virtual void copyFrom(const CUnit& src);

    bool setMoving(bool inMoving) {
      fIsMoving = inMoving;
    }

    bool doMove(unsigned long);

    void dieAfterAnimating();

    void attackAfterMoving(CPuppet* inTarget);
    void attackAfterMoving(CUnit* inBlocker);
    void cleanupAfterAttacking(CPuppet* inTarget);
    void cleanupAfterMovingBack(CPuppet* inTarget);

    // recursively goes through all the blockers and attacks them
    void doAttack();

    void attackAfterAnimation(boost::function<void()> callback, CPuppet*);
    void attackAfterAnimation(boost::function<void()> callback, CUnit*, bool doBlock);
    void updateOverlayAfterAttack(boost::function<void()> callback);

    void moveBackAfterBlocking(CUnit* blocker);

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

    static float mDefaultWalkSpeed;

    //~ bool fDoneBlocking;

    typedef std::list<CUnit*> blockers_t;
    blockers_t mBlockers;

    boost::function<void(CUnit*)> mCallback;

    boost::asio::deadline_timer* mTimer;

    spells_t mSpells;
    spells_t mBuffs;
    bool fDying;

    CPuppet* mEnemy;

    Ogre::RaySceneQuery *mRaySceneQuery;
    Ogre::SceneManager      *mSceneMgr;
	};
} // end of namespace
#endif
