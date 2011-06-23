/* -----------------------------------------------
 *  Filename: UnitFactory.h
 *  Date Created: ??/2009
 *
 *  Original Author:
 *      Ahmad Amireh ( ahmad.amireh@gmail.com )
 *
 *  Last Update:
 *      Date:   20/4/2009
 *      By:     Ahmad Amireh
 * ----------------------------------------------- */

#if 0

#ifndef P_CUnitFactory_H
#define P_CUnitFactory_H

#include "UnitFactory.h"
#include "CUnit.h"

namespace Pixy
{

    /*! \class Pixy::UnitFactory
     *  \brief Factory class used for creating and destroying Pixy::Unit objects.
     */
	class CUnitFactory : public UnitFactory
	{
		public:
			virtual ~CUnitFactory();


			//! Retrieves the singleton instance of this class.
			/*!
			 * \return Pointer to the instance of this Factory.
             */
			static CUnitFactory* getSingletonPtr();

			/*! \brief
			 * Interface method for creating Entity objects.
			 *
			 * @param   inIdEntity    unique id of the Entity object to create
			 * @param   inIdOwner     id of Entity owner to attach to
			 * @return  pointer to the newly created Pixy::Unit* object
			 */
			virtual CUnit*
		  createEntity(const int inObjectId,
		               const std::string& inName,
		               const std::string& inOwner,
		               const RACE inRace);

			//! Interface method for destroying Unit objects.
			/*!
			 * @param inEntity pointer to the Unit object to destroy
			 */
			virtual void destroyEntity(CUnit* inEntity);

      protected:
			CUnitFactory();
			CUnitFactory(const CUnitFactory&){};
      CUnitFactory& operator=(const CUnitFactory&){return *this;};
			static CUnitFactory* mUnitFactory;
		private:

	}; // end of EntityFactory class

} // end of Pixy namespace

#endif // P_UnitFactory_H

#endif
