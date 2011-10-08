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
  class Renderable;
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

    void setCaster(Renderable* inCaster) {
      mCaster = inCaster;
    }
    void setTarget(Renderable* inTarget) {
      mTarget = inTarget;
    };
    Renderable* getCaster() const {
      return mCaster;
    };
    Renderable* getTarget() const {
      return mTarget;
    };

    protected:
    void copyFromSrc(const CSpell& src);
    void generateTooltip();

    // interface info
    std::string   mImageSet;
    std::string   mImageName;
    std::string mTooltip;
    CEGUI::Window *mButton;

    Renderable* mCaster;
    Renderable* mTarget;
  };
}

#endif // H_Spell_H
