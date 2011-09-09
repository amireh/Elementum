#include "MousePicker.h"

using Ogre::Vector3;
namespace Pixy {

  MousePicker::MousePicker(Ogre::SceneManager* inMgr)
  : mSceneMgr(inMgr),
    mRayQuery(0)
  {
  }

  MousePicker::~MousePicker()
  {
    mSceneMgr = 0;
    if (mRayQuery)
      delete mRayQuery;
  }

  // -------------------------------------------------------------
  // GenericMousePicker
  // -------------------------------------------------------------
  GenericMousePicker::GenericMousePicker(Ogre::SceneManager* inSceneMgr)
  : MousePicker(inSceneMgr)
  {
    // create the ray scene query object
    //~ mRayQuery = mSceneMgr->createRayQuery(Ogre::Ray(), Ogre::SceneManager::WORLD_GEOMETRY_TYPE_MASK);
    mRayQuery = mSceneMgr->createRayQuery(Ogre::Ray());
    if (!mRayQuery)
    {
      throw std::runtime_error("GenericMousePicker: failed to create Ogre::RaySceneQuery instance");
    }
    mRayQuery->setSortByDistance(true);
  }

  GenericMousePicker::~GenericMousePicker()
  {
  }

  bool
  GenericMousePicker::cast(
    const OIS::MouseEvent &e,
    const CEGUI::Point& mousePos,
    const Ogre::Camera *mCamera,
    Ogre::MovableObject **out,
    Ogre::uint32 mask)
  {
    Ogre::Ray mouseRay =
      mCamera->getCameraToViewportRay(
        mousePos.d_x/float(e.state.width),
        mousePos.d_y/float(e.state.height)
      );

    return cast(mouseRay.getOrigin(), mouseRay.getDirection(), out, mask);
  }

  bool
  GenericMousePicker::cast(
    const Ogre::Vector3 &inOrigin,
    const Ogre::Vector3 &inDirection,
    Ogre::MovableObject **out,
    Ogre::uint32 mask)
  {
    Ogre::Ray mRay(inOrigin, inDirection);

    mRayQuery->setRay(mRay);
    mRayQuery->setQueryMask(mask);

    // Execute query
    Ogre::RaySceneQueryResult &result = mRayQuery->execute();
    Ogre::RaySceneQueryResult::iterator itr;

    for (itr = result.begin(); itr != result.end(); itr++)
    {
      if (itr->movable) {
        (*out) = itr->movable;
        return true;
      }
    }

    (*out) = 0;
    return false;
  }

  // -------------------------------------------------------------
  // PolyMousePicker
  // -------------------------------------------------------------
  PolyMousePicker::PolyMousePicker(Ogre::SceneManager* inSceneMgr)
  : MousePicker(inSceneMgr)
  {
    // create the ray scene query object
    //~ mRayQuery = mSceneMgr->createRayQuery(Ogre::Ray(), Ogre::SceneManager::WORLD_GEOMETRY_TYPE_MASK);
    mRayQuery = mSceneMgr->createRayQuery(Ogre::Ray());
    if (!mRayQuery)
    {
      throw std::runtime_error("GenericMousePicker: failed to create Ogre::RaySceneQuery instance");
    }
    mRayQuery->setSortByDistance(true);

    mStep = 20;
    generateCorners();
  }

  PolyMousePicker::~PolyMousePicker()
  {
  }

  void PolyMousePicker::setStep(Ogre::Real inStep)
  {
    mStep = inStep;
    generateCorners();
  }

  Ogre::Real PolyMousePicker::getStep() const
  {
    return mStep;
  }

  void PolyMousePicker::generateCorners()
  {
    using Ogre::Vector2;

    mCorners[0] = Vector2(-mStep, -mStep);
    mCorners[1] = Vector2(0, -mStep);
    mCorners[2] = Vector2(mStep, -mStep);
    mCorners[3] = Vector2(-mStep, 0);
    mCorners[4] = Vector2(0, 0);
    mCorners[5] = Vector2(mStep, 0);
    mCorners[6] = Vector2(-mStep, mStep);
    mCorners[7] = Vector2(0, mStep);
    mCorners[8] = Vector2(mStep, mStep);
  }

  bool
  PolyMousePicker::cast(
    const OIS::MouseEvent &e,
    const CEGUI::Point& mousePos,
    const Ogre::Camera *mCamera,
    Ogre::MovableObject **out,
    Ogre::uint32 mask)
  {

    using Ogre::Vector2;
    using Ogre::Vector3;

    std::map<Ogre::MovableObject*, int> objects;

    // cast 9 rays against every point in the box
    // and return the object that got the most hits
    for (int i=0; i < 9; ++i)
    {

      Ogre::Ray mRay =
      mCamera->getCameraToViewportRay(
        (mousePos.d_x + mCorners[i].x)/float(e.state.width),
        (mousePos.d_y + mCorners[i].y)/float(e.state.height)
      );

      //~ Ogre::Ray mRay(
        //~ Vector3(inOrigin.x + mCorners[i].x, inOrigin.y + mCorners[i].y, inOrigin.z),
        //~ inDirection);

      Ogre::Vector3 resultPoint;
      Ogre::MovableObject* resultObj = 0;
      bool result =
      RaycastFromPoint(
        mRay.getOrigin(),
        mRay.getDirection(),
        resultPoint,
        &resultObj,
        mask);

      if (result)
      {
        if (objects.find(resultObj) == objects.end())
          objects.insert(std::make_pair(resultObj, 1));
        else
          objects.find(resultObj)->second++;
      }
    }

    if (objects.empty())
      return false;

    // find the best hit
    int max = 0;
    Ogre::MovableObject* bestHit = 0;
    for (std::map<Ogre::MovableObject*, int>::const_iterator object = objects.begin();
    object != objects.end();
    ++object)
    {
      if (object->second > max)
      {
        max = object->second;
        bestHit = object->first;
      }
    }

    (*out) = bestHit;
    return true;
  }

  bool
  PolyMousePicker::cast(
    const Ogre::Vector3 &inOrigin,
    const Ogre::Vector3 &inDirection,
    Ogre::MovableObject **out,
    Ogre::uint32 mask)
  {

    return true;
  }

  // raycast from a point in to the scene.
  // returns success or failure.
  // on success the point is returned in the result.
  bool
  PolyMousePicker::RaycastFromPoint(
    const Vector3 &point,
    const Vector3 &normal,
    Vector3 &result,
    Ogre::MovableObject** out,
    Ogre::uint32 mask)
  {
    //~ assert(filter);

      // create the ray to test
      Ogre::Ray ray(Ogre::Vector3(point.x, point.y, point.z),
                    Ogre::Vector3(normal.x, normal.y, normal.z));

      // check we are initialised
      if (mRayQuery != NULL)
      {
          // create a query object
          mRayQuery->setRay(ray);
          //~ mRayQuery->setQueryTypeMask(Ogre::SceneManager::USER_TYPE_MASK_LIMIT);
          mRayQuery->setQueryMask(mask);


          // execute the query, returns a vector of hits
          if (mRayQuery->execute().size() <= 0)
          {
              // raycast did not hit an objects bounding box
              return (false);
          }
      }
      else
      {
          std::cerr << "Cannot raycast without RaySceneQuery instance\n";
          return (false);
      }

      // at this point we have raycast to a series of different objects bounding boxes.
      // we need to test these different objects to see which is the first polygon hit.
      // there are some minor optimizations (distance based) that mean we wont have to
      // check all of the objects most of the time, but the worst case scenario is that
      // we need to test every triangle of every object.
      Ogre::Real closest_distance = -1.0f;
      Ogre::Vector3 closest_result;
      Ogre::RaySceneQueryResult &query_result = mRayQuery->getLastResults();
      for (size_t qr_idx = 0; qr_idx < query_result.size(); qr_idx++)
      {
          // stop checking if we have found a raycast hit that is closer
          // than all remaining entities
          if ((closest_distance >= 0.0f) &&
              (closest_distance < query_result[qr_idx].distance))
          {
               break;
          }

          // only check this result if its a hit against an entity
          if ((query_result[qr_idx].movable != NULL)
              //~ && (*filter)(query_result[qr_idx].movable))
              //~ && (query_result[qr_idx].movable->getMovableType().compare("Entity") == 0)
              )
          {
              // get the entity to check
              Ogre::Entity *pentity = static_cast<Ogre::Entity*>(query_result[qr_idx].movable);

              // mesh data to retrieve
              size_t vertex_count;
              size_t index_count;
              Ogre::Vector3 *vertices;
              Ogre::uint32 *indices;

              // get the mesh information
              GetMeshInformation(pentity, vertex_count, vertices, index_count, indices,
                                pentity->getParentNode()->_getDerivedPosition(),
                                pentity->getParentNode()->_getDerivedOrientation(),
                                pentity->getParentNode()->_getDerivedScale());

              // test for hitting individual triangles on the mesh
              bool new_closest_found = false;
              for (int i = 0; i < static_cast<int>(index_count); i += 3)
              {
                  // check for a hit against this triangle
                  std::pair<bool, Ogre::Real> hit = Ogre::Math::intersects(ray, vertices[indices[i]],
                      vertices[indices[i+1]], vertices[indices[i+2]], true, false);

                  // if it was a hit check if its the closest
                  if (hit.first)
                  {
                      if ((closest_distance < 0.0f) ||
                          (hit.second < closest_distance))
                      {
                          // this is the closest so far, save it off
                          closest_distance = hit.second;
                          new_closest_found = true;
                      }
                  }
              }

           // free the verticies and indicies memory
              delete[] vertices;
              delete[] indices;

              // if we found a new closest raycast for this object, update the
              // closest_result before moving on to the next object.
              if (new_closest_found)
              {
                  closest_result = ray.getPoint(closest_distance);
                  (*out) = query_result[qr_idx].movable;
              }
          }
      }

      // return the result
      if (closest_distance >= 0.0f)
      {
          // raycast success
          result = closest_result;
          return (true);
      }
      else
      {
          // raycast failed
          return (false);
      }
  }

  void
  PolyMousePicker::GetMeshInformation(
    Ogre::Entity *entity,
    size_t &vertex_count,
    Ogre::Vector3* &vertices,
    size_t &index_count,
    Ogre::uint32* &indices,
    const Ogre::Vector3 &position,
    const Ogre::Quaternion &orient,
    const Ogre::Vector3 &scale)
  {
    bool added_shared = false;
    size_t current_offset = 0;
    size_t shared_offset = 0;
    size_t next_offset = 0;
    size_t index_offset = 0;
    vertex_count = index_count = 0;

    Ogre::MeshPtr mesh = entity->getMesh();


    bool useSoftwareBlendingVertices = entity->hasSkeleton();

    if (useSoftwareBlendingVertices)
    {
      entity->_updateAnimation();
    }

    // Calculate how many vertices and indices we're going to need
    for (unsigned short i = 0; i < mesh->getNumSubMeshes(); ++i)
    {
      Ogre::SubMesh* submesh = mesh->getSubMesh( i );

      // We only need to add the shared vertices once
      if(submesh->useSharedVertices)
      {
        if( !added_shared )
        {
          vertex_count += mesh->sharedVertexData->vertexCount;
          added_shared = true;
        }
      }
      else
      {
        vertex_count += submesh->vertexData->vertexCount;
      }

      // Add the indices
      index_count += submesh->indexData->indexCount;
    }


    // Allocate space for the vertices and indices
    vertices = new Ogre::Vector3[vertex_count];
    indices = new Ogre::uint32[index_count];

    added_shared = false;

    // Run through the submeshes again, adding the data into the arrays
    for ( unsigned short i = 0; i < mesh->getNumSubMeshes(); ++i)
    {
      Ogre::SubMesh* submesh = mesh->getSubMesh(i);

      //----------------------------------------------------------------
      // GET VERTEXDATA
      //----------------------------------------------------------------
      Ogre::VertexData* vertex_data;

      //When there is animation:
      if(useSoftwareBlendingVertices)
        vertex_data = submesh->useSharedVertices ? entity->_getSkelAnimVertexData() : entity->getSubEntity(i)->_getSkelAnimVertexData();
      else
        vertex_data = submesh->useSharedVertices ? mesh->sharedVertexData : submesh->vertexData;


      if((!submesh->useSharedVertices)||(submesh->useSharedVertices && !added_shared))
      {
        if(submesh->useSharedVertices)
        {
          added_shared = true;
          shared_offset = current_offset;
        }

        const Ogre::VertexElement* posElem =
          vertex_data->vertexDeclaration->findElementBySemantic(Ogre::VES_POSITION);

        Ogre::HardwareVertexBufferSharedPtr vbuf =
          vertex_data->vertexBufferBinding->getBuffer(posElem->getSource());

        unsigned char* vertex =
          static_cast<unsigned char*>(vbuf->lock(Ogre::HardwareBuffer::HBL_READ_ONLY));

        // There is _no_ baseVertexPointerToElement() which takes an Ogre::Real or a double
        //  as second argument. So make it float, to avoid trouble when Ogre::Real will
        //  be comiled/typedefed as double:
        //      Ogre::Real* pReal;
        float* pReal;

        for( size_t j = 0; j < vertex_data->vertexCount; ++j, vertex += vbuf->getVertexSize())
        {
          posElem->baseVertexPointerToElement(vertex, &pReal);

          Ogre::Vector3 pt(pReal[0], pReal[1], pReal[2]);

          vertices[current_offset + j] = (orient * (pt * scale)) + position;
        }

        vbuf->unlock();
        next_offset += vertex_data->vertexCount;
      }


      Ogre::IndexData* index_data = submesh->indexData;
      size_t numTris = index_data->indexCount / 3;
      Ogre::HardwareIndexBufferSharedPtr ibuf = index_data->indexBuffer;

      bool use32bitindexes = (ibuf->getType() == Ogre::HardwareIndexBuffer::IT_32BIT);

      void* hwBuf = ibuf->lock(Ogre::HardwareBuffer::HBL_READ_ONLY);

      size_t offset = (submesh->useSharedVertices)? shared_offset : current_offset;
      size_t index_start = index_data->indexStart;
      size_t last_index = numTris*3 + index_start;

      if (use32bitindexes) {
        Ogre::uint32* hwBuf32 = static_cast<Ogre::uint32*>(hwBuf);
        for (size_t k = index_start; k < last_index; ++k)
        {
          indices[index_offset++] = hwBuf32[k] + static_cast<Ogre::uint32>( offset );
        }
      } else {
        Ogre::uint16* hwBuf16 = static_cast<Ogre::uint16*>(hwBuf);
        for (size_t k = index_start; k < last_index; ++k)
        {
          indices[ index_offset++ ] = static_cast<Ogre::uint32>( hwBuf16[k] ) +
            static_cast<Ogre::uint32>( offset );
        }
      }

      ibuf->unlock();
      current_offset = next_offset;
    }
  }

} // namespace Pixy
