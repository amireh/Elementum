#include "AutoRepeatKey.h"

namespace Pixy
{

  AutoRepeatKey::AutoRepeatKey(float a_fRepeatDelay, float a_fInitialDelay):
      m_nKey(OIS::KC_UNASSIGNED),
      m_fRepeatDelay(a_fRepeatDelay),
      m_fInitialDelay(a_fInitialDelay)
  {
  }

  AutoRepeatKey::~AutoRepeatKey()
  {
  }

  void AutoRepeatKey::begin(const OIS::KeyEvent &evt) {
      m_nKey = evt.key;
      m_nChar = evt.text;

      m_fElapsed = 0;
      m_fDelay = m_fInitialDelay;
  }

  void AutoRepeatKey::end(const OIS::KeyEvent &evt) {
      if (m_nKey != evt.key) return;

      m_nKey = OIS::KC_UNASSIGNED;
  }

  void AutoRepeatKey::update(float a_fElapsed) {
      if (m_nKey == OIS::KC_UNASSIGNED) return;

      m_fElapsed += a_fElapsed;
      if (m_fElapsed < m_fDelay) return;

      m_fElapsed -= m_fDelay;
      m_fDelay = m_fRepeatDelay;

      do {
          repeatKey(m_nKey, m_nChar);

          m_fElapsed -= m_fRepeatDelay;
      } while (m_fElapsed >= m_fRepeatDelay);

      m_fElapsed = 0;
  }

  MyInput::MyInput(float a_fRepeatDelay, float a_fInitialDelay)
  : AutoRepeatKey(a_fRepeatDelay, a_fInitialDelay)
  {
  }

  MyInput::~MyInput()
  {
  }


  void MyInput::injectOISKey(bool bButtonDown, OIS::KeyEvent inKey)
  {
    if (bButtonDown)
    {
      CEGUI::System::getSingleton().injectKeyDown(inKey.key);
      CEGUI::System::getSingleton().injectChar(inKey.text);
      begin(inKey);
    }
    else
    {
      CEGUI::System::getSingleton().injectKeyUp(inKey.key);
      end(inKey);
    }
  }

  void MyInput::repeatKey(OIS::KeyCode a_nKey, unsigned int a_nChar)
  {
    // Now remember the key is still down, so we need to simulate the key being released, and then repressed immediatly
    CEGUI::System::getSingleton().injectKeyUp(a_nKey);   // Key UP
    CEGUI::System::getSingleton().injectKeyDown(a_nKey); // Key Down
    CEGUI::System::getSingleton().injectChar(a_nChar);       // What that key means
  }

}
