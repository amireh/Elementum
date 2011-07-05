#include "CSpell.h"
//#if PIXY_PLATFORM == PIXY_PLATFORM_APPLE
//#include "CEGUIBase/CEGUIBase.h"
//#else
//#include "CEGUI/CEGUIBase.h"
//#endif
//#include "Combat.h"
//#include "Entity.h"
//#include "Puppet.h"
//#include "Unit.h"

namespace Pixy
{
    CSpell::CSpell()
    {
      mButton = NULL;
      std::cout << "CSpell is being created\n";
    }

    CSpell::~CSpell()
    {
      std::cout << "CSpell is being destroyed\n";
      mButton = 0;
    };

    CSpell::CSpell(const CSpell& src)
    {
        copyFromSrc(src);
    }
    CSpell& CSpell::operator=(const CSpell& rhs)
    {
        if (this == &rhs)
            return (*this);

        copyFromSrc(rhs);

        return (*this);
    }

    void CSpell::copyFromSrc(const CSpell& src)
    {
      Spell::copyFromSrc(src);

      //~ mImageName = src.mImageName;
      //~ mImageSet = src.mImageSet;
      mButton = src.mButton;

    }
    CSpell::CSpell(const Spell& src) {
      Spell::copyFromSrc(src);

      //~ mImageName = "";
      //~ mImageSet = "";
      mButton = 0;

      std::cout << "CSpell cloned from Spell, my name is " << mName << "\n";
    }

    //~ void CSpell::setImageSet(std::string inName) {
        //~ mImageSet = inName;
    //~ }
    //~ void CSpell::setImageName(std::string inName) {
        //~ mImageName = inName;
    //~ }
    void CSpell::setButton(Rocket::Core::Element* inButton) {
        mButton = inButton;
    }


    //~ std::string CSpell::getImageSet() { return mImageSet; }
    //~ std::string CSpell::getImageName() { return mImageName; }
    Rocket::Core::Element* CSpell::getButton() { return mButton; }
}
