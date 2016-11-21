#ifndef _CILINDRO_H
#define _CILINDRO_H

#include "objRevolucion.h"
#include <GL/glut.h>
#include <GL/gl.h>

class Cilindro : public ObjRevolucion {

private:
   vector<float> vec;

public:
   Cilindro();

};
#endif
