#ifndef H_CSpell_H
#define H_CSpell_H

#include "Pixy.h"
#include "Spell.h"

#include <string>

namespace Rocket {
namespace Core {

class Element;

}
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

    //~ void setImageSet(std::string inName);
    //~ void setImageName(std::string inName);
    void setButton(Rocket::Core::Element*inButton);

    //string  getImageSet();
    //string  getImageName();
    Rocket::Core::Element*  getButton();

    protected:
    void copyFromSrc(const CSpell& src);

    // interface info
    //std::string   mImageSet;
    //std::string   mImageName;
    Rocket::Core::Element *mButton;
  };
}

#endif // H_Spell_H
