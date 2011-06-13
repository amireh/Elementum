#ifndef H_CSpell_H
#define H_CSpell_H

#include "Pixy.h"
#include "Spell.h"

#if PIXY_PLATFORM == PIXY_PLATFORM_APPLE
#include "CEGUIBase/CEGUIBase.h"
#else
#include "CEGUI/CEGUIBase.h"
#endif
#include <string>

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
    void setTooltip(std::string inTooltip);
    void setButton(CEGUI::Window* inButton);

    string  getImageSet();
    string  getImageName();
    CEGUI::Window*  getButton();
    string getTooltip();

    protected:
    void copyFromSrc(const CSpell& src);

    // interface info
    // __NOTE__ : refactor into a UI renderable object
    std::string          mImageSet;
    std::string          mImageName;
    CEGUI::Window*  mButton;
    std::string          mTooltip; // tooltip desc
  };
}

#endif // H_Spell_H
