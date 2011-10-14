/*
 * This code is shamelessly stolen from CEGUI Wiki.
 * Link: http://www.cegui.org.uk/wiki/index.php/CEGUI_In_Practice_-_Auto_Repeat_Key
 *
 */

#pragma once

#ifndef H_AutoRepeatKey_H
#define H_AutoRepeatKey_H

#include <OIS.h>
#if PIXY_PLATFORM == PIXY_PLATFORM_APPLE
# include <CoreFoundation/CoreFoundation.h>
#endif

#include <CEGUI/CEGUI.h>

namespace Pixy
{

  class AutoRepeatKey
  {
    private:

    OIS::KeyCode m_nKey;
    unsigned int m_nChar;

    float m_fElapsed;
    float m_fDelay;

    float m_fRepeatDelay;
    float m_fInitialDelay;

    protected:

    virtual void repeatKey(OIS::KeyCode a_nKey, unsigned int a_nChar) = 0;

    public:

    AutoRepeatKey(float a_fRepeatDelay = 0.035f, float a_fInitialDelay = 0.300f);
    virtual ~AutoRepeatKey();

    virtual void begin(const OIS::KeyEvent &evt);
    virtual void end(const OIS::KeyEvent &evt);
    virtual void update(float a_fElapsed); // Elapsed time in seconds
  };

  class MyInput : public AutoRepeatKey
  {
    public:

    MyInput(float a_fRepeatDelay = 0.035f, float a_fInitialDelay = 0.300f);
    virtual ~MyInput();

    void injectOISKey(bool bButtonDown, OIS::KeyEvent inKey);

    protected:

    void repeatKey(OIS::KeyCode a_nKey, unsigned int a_nChar);
  };
}

#endif