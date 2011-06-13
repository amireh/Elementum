#include "CSpell.h"
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

      mTooltip = src.mTooltip;
      mImageName = src.mImageName;
      mImageSet = src.mImageSet;
      mButton = src.mButton;

    }
    CSpell::CSpell(const Spell& src) {
      Spell::copyFromSrc(src);

      mTooltip = "Unset";
      mImageName = "";
      mImageSet = "";
      mButton = 0;
    }


    void CSpell::setTooltip(std::string inTooltip) {
      mTooltip = inTooltip;
    };
    void CSpell::setImageSet(std::string inName) {
        mImageSet = inName;
    }
    void CSpell::setImageName(std::string inName) {
        mImageName = inName;
    }
    void CSpell::setButton(CEGUI::Window* inButton) {
        mButton = inButton;
    }


    std::string CSpell::getTooltip() { return mTooltip; };
    std::string CSpell::getImageSet() { return mImageSet; }
    std::string CSpell::getImageName() { return mImageName; }
    CEGUI::Window* CSpell::getButton() { return mButton; }
}
