/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_CSpell_H
#define H_CSpell_H

#include "Pixy.h"
#include "Spell.h"

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
  class CSpell : public Spell
  {
    public:


    CSpell();
    CSpell(const CSpell& src);
    CSpell& operator=(const CSpell& rhs);
    CSpell(const Spell& src);

    virtual ~CSpell();

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

    virtual void setCaster(owner_t* inCaster);
    virtual void setTarget(owner_t* inTarget);
    virtual owner_t* getCaster() const;
    virtual owner_t* getTarget() const;

    protected:
    void copyFromSrc(const CSpell& src);
    void generateTooltip();

    // interface info
    std::string   mImageSet;
    std::string   mImageName;
    std::string mTooltip;
    CEGUI::Window *mButton;

    //CEntity* mCaster;
    //CEntity* mTarget;
  };
}

#endif // H_Spell_H
