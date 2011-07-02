#ifndef H_InputListener_H
#define H_InputListener_H

#include <OIS.h>

namespace Pixy {
  class InputListener {
    public:

    InputListener() {};
    virtual ~InputListener() {};

		virtual void keyPressed( const OIS::KeyEvent &e )=0;
		virtual void keyReleased( const OIS::KeyEvent &e )=0;

		virtual void mouseMoved( const OIS::MouseEvent &e )=0;
		virtual void mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id )=0;
		virtual void mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id )=0;
  };
}

#endif
