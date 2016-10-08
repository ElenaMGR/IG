#ifndef _TETRAEDRO_H
#define _TETRAEDROD_H

#include "obj3D.h"
#include <GL/glut.h>
#include <GL/gl.h>
using namespace std;

class Tetraedro : public Obj3D {

private:


public:
   Tetraedro();
   void createGeometry();
   void draw(GLenum face, GLenum mode);

};
#endif
