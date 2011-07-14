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
    : mButton(0),
      mTooltip("")
    {
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

      mImageName = src.mImageName;
      mImageSet = src.mImageSet;
      mButton = src.mButton;

    }
    CSpell::CSpell(const Spell& src) {
      Spell::copyFromSrc(src);

      mImageName = "";
      mImageSet = "";
      mButton = 0;

      std::cout << "CSpell cloned from Spell, my name is " << mName << "\n";
    }

    void CSpell::setImageSet(std::string inName) {
        mImageSet = inName;
    }
    void CSpell::setImageName(std::string inName) {
        mImageName = inName;
    }
    void CSpell::setButton(CEGUI::Window* inButton) {
        mButton = inButton;
    }

    std::string CSpell::getTooltip() const {
      if (mTooltip.empty()) {
        ((CSpell*)this)->generateTooltip();
      }

      return mTooltip;
    }

    void CSpell::generateTooltip() {
      std::ostringstream s;
      s << "[padding='l:5 t:100 r:5 b:20']" << mName << "\n[padding='l:5 t:0 r:5 b:0']" << mDescription;
      s << "\n[padding='l:5 t:20 r:5 b:0']Cost: " << mCostWP << "wp[padding='l:5 t:0 r:5 b:0']";

      mTooltip = s.str();
    }


    std::string CSpell::getImageSet() { return mImageSet; }
    std::string CSpell::getImageName() { return mImageName; }
    CEGUI::Window* CSpell::getButton() { return mButton; }
}
