/*
* Copyright (C) Shroom Studios, Inc - All Rights Reserved
*
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*
* Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
*/

#include "Spell.h"
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
  Spell::Spell()
  : mButton(0),
    mTooltip("")
  {
    //std::cout << "Spell is being created\n";
  }

  Spell::~Spell()
  {
    //std::cout << "Spell is being destroyed\n";
    mButton = 0;
  };

  Spell::Spell(const Spell& src)
  {
    copyFrom(src);
  }
  Spell& Spell::operator=(const Spell& rhs)
  {
    if (this == &rhs)
      return (*this);

    copyFrom(rhs);

    return (*this);
  }

  void Spell::copyFrom(const Spell& src)
  {
    BaseSpell::copyFrom(src);

    mImageName = src.mImageName;
    mImageSet = src.mImageSet;
    mTooltip = src.mTooltip;
    mButton = src.mButton;

  }


  void Spell::setImageSet(std::string inName) {
    mImageSet = inName;
  }
  void Spell::setImageName(std::string inName) {
    mImageName = inName;
  }
  void Spell::setButton(CEGUI::Window* inButton) {
    mButton = inButton;
  }

  void Spell::updateTooltip()
  {
    this->generateTooltip();
  }

  std::string Spell::getTooltip() const {
    if (mTooltip.empty()) {
      ((Spell*)this)->updateTooltip();
    }

    return mTooltip;
  }

  void Spell::generateTooltip() {
    std::ostringstream s;
    s << "[padding='l:5 t:0 r:5 b:0']" << mName << "\n \n" << mDescription;
    s << "\n \nCost: " << mCostWP << "wp/" << mCostHP << "hp/" << mCostChannels << "c";

    mTooltip = s.str();
  }

  std::string Spell::getImageSet() { return mImageSet; }
  std::string Spell::getImageName() { return mImageName; }
  CEGUI::Window* Spell::getButton() { return mButton; }
}
