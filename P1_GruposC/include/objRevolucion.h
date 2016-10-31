#ifndef _OBJREV_H
#define _OBJREV_H

#include "objPLY.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

class ObjRevolucion : public ObjPLY {

private:

public:
   ObjRevolucion();
   ObjRevolucion(vector<float> vec);
   void createGeometry(int repeticiones, bool tapa, bool base);
   int leerObjetoRev();
};

#endif
