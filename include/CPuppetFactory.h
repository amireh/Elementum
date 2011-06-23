/* -----------------------------------------------
 *  Filename: PuppetFactory.h
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

#ifndef P_CPuppetFactory_H
#define P_CPuppetFactory_H

#include "PuppetFactory.h"
#include "CPuppet.h"

namespace Pixy
{

    /*! \class Pixy::PuppetFactory
     *  \brief Factory class used for creating and destroying Pixy::Puppet objects.
     */
	class CPuppetFactory : public PuppetFactory
	{
		public:
			virtual ~CPuppetFactory();


			//! Retrieves the singleton instance of this class.
			/*!
			 * \return Pointer to the instance of this Factory.
             */
			static CPuppetFactory* getSingletonPtr();

			/*! \brief
			 * Interface method for creating Entity objects.
			 *
			 * @param   inIdEntity    unique id of the Entity object to create
			 * @param   inIdOwner     id of Entity owner to attach to
			 * @return  pointer to the newly created Pixy::Puppet* object
			 */
			virtual CPuppet*
		  createEntity(const int inObjectId,
		               const std::string& inName,
		               const std::string& inOwner,
		               const RACE inRace);

			//! Interface method for destroying Puppet objects.
			/*!
			 * @param inEntity pointer to the Puppet object to destroy
			 */
			virtual void destroyEntity(CPuppet* inEntity);

      protected:
			CPuppetFactory();
			CPuppetFactory(const CPuppetFactory&){};
      CPuppetFactory& operator=(const CPuppetFactory&){return *this;};
			static CPuppetFactory* mPuppetFactory;
		private:

	}; // end of EntityFactory class

} // end of Pixy namespace

#endif // P_PuppetFactory_H

#endif
