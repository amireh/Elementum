/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * ************
 * MousePicker - an interface for querying objects in an Ogre3D scene
 *
 * Written by:
 *  code for the PolyMousePicker was written by <gerds>
 *
 * Original link:
 *  http://www.ogre3d.org/tikiwiki/Raycasting+to+the+polygon+level&structure=Cookbook
 *
 * Modified by: Ahmad Amireh <ahmad@shroom-studios.com>
 */

#ifndef H_MousePicker_H
#define H_MousePicker_H

#include "Ogre.h"
#include "CEGUI/CEGUI.h"
#include "OIS.h"

namespace Pixy {

  class MousePicker {
    public:

    MousePicker(Ogre::SceneManager*);
    virtual ~MousePicker();

    virtual bool
    cast(const Ogre::Vector3 &inOrigin,
         const Ogre::Vector3 &inDirection,
         Ogre::MovableObject **out,
         Ogre::uint32 mask = Ogre::SceneManager::ENTITY_TYPE_MASK)=0;

    virtual bool
    cast (const OIS::MouseEvent &e,
          const CEGUI::Point& mousePos,
          const Ogre::Camera *inCamera,
          Ogre::MovableObject **out,
          Ogre::uint32 mask = Ogre::SceneManager::ENTITY_TYPE_MASK)=0;

    protected:

    Ogre::SceneManager *mSceneMgr;
    Ogre::RaySceneQuery *mRayQuery;
  };

  class GenericMousePicker : MousePicker {
    public:

    GenericMousePicker(Ogre::SceneManager*);
    virtual ~GenericMousePicker();

    virtual bool
    cast(const Ogre::Vector3 &inOrigin,
         const Ogre::Vector3 &inDirection,
         Ogre::MovableObject **out,
         Ogre::uint32 mask = Ogre::SceneManager::ENTITY_TYPE_MASK);

    virtual bool
    cast (const OIS::MouseEvent &e,
          const CEGUI::Point& mousePos,
          const Ogre::Camera *inCamera,
          Ogre::MovableObject **out,
          Ogre::uint32 mask = Ogre::SceneManager::ENTITY_TYPE_MASK);
  };

  class PolyMousePicker : MousePicker {
    public:

    //typedef bool (*filter_t)(Ogre::MovableObject*);

    PolyMousePicker(Ogre::SceneManager*);
    virtual ~PolyMousePicker();

    virtual bool
    cast(const Ogre::Vector3 &inOrigin,
         const Ogre::Vector3 &inDirection,
         Ogre::MovableObject **out,
         Ogre::uint32 mask = Ogre::SceneManager::ENTITY_TYPE_MASK);

    virtual bool
    cast (const OIS::MouseEvent &e,
          const CEGUI::Point& mousePos,
          const Ogre::Camera *inCamera,
          Ogre::MovableObject **out,
          Ogre::uint32 mask = Ogre::SceneManager::ENTITY_TYPE_MASK);

    void setStep(Ogre::Real);
    Ogre::Real getStep() const;

    private:

    bool
    RaycastFromPoint(
      const Ogre::Vector3 &point,
      const Ogre::Vector3 &normal,
      Ogre::Vector3 &result,
      Ogre::MovableObject** out,
      Ogre::uint32 mask = Ogre::SceneManager::ENTITY_TYPE_MASK);

    void
    GetMeshInformation(
      Ogre::Entity *entity,
      size_t &vertex_count,
      Ogre::Vector3* &vertices,
      size_t &index_count,
      Ogre::uint32* &indices,
      const Ogre::Vector3 &position,
      const Ogre::Quaternion &orient,
      const Ogre::Vector3 &scale);

    Ogre::Vector2 mCorners[9];
    Ogre::Real    mStep;

    void generateCorners();
    //void assignFilter(filter_t inFilter);

    //private:
    //Ogre::RaySceneQuery *m_pray_scene_query;
    //Ogre::SceneManager  *m_pscene_manager;

    //filter_t filter;
  };


}

#endif
