#ifndef _ESFERA_H
#define _ESFERA_H

#include "objRevolucion.h"
#include <GL/glut.h>
#include <GL/gl.h>

class Esfera : public ObjRevolucion {

private:
   vector<float> vec;

public:
   Esfera();

};
#endif
