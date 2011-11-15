/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_Spell_H
#define H_Spell_H

#include "Pixy.h"
#include "BaseSpell.h"

#include <string>

namespace CEGUI {
  class Window;
}

using std::string;
namespace Pixy
{
  /*! \class Spell
  *  \brief
  *  Defines Spell GameObjects that are used by Puppet objects.
  */
  class Renderable;
  class Spell : public BaseSpell
  {
    public:
    Spell();
    Spell(const Spell& src);
    Spell& operator=(const Spell& rhs);

    virtual ~Spell();

    void setImageSet(std::string inName);
    void setImageName(std::string inName);
    //void setButton(Rocket::Core::Element*inButton);
    void setButton(CEGUI::Window*);

    string  getImageSet();
    string  getImageName();
    //Rocket::Core::Element*  getButton();
    CEGUI::Window* getButton();

    std::string getTooltip() const;
    void updateTooltip();

    protected:
    void copyFrom(const Spell& src);
    void generateTooltip();

    // interface info
    std::string   mImageSet;
    std::string   mImageName;
    std::string   mTooltip;
    CEGUI::Window *mButton;
  };
}

#endif // H_Spell_H
