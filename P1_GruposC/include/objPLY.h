#ifndef _OBJPLY_H
#define _OBJPLY_H

#include "obj3D.h"
#include "file_ply_stl.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <string>
#include <iostream>

class ObjPLY : public Obj3D {

protected:
   vector<float> v;
   vector<int> t;

public:
   ObjPLY();
   void leerPLY(string nombre);
   void createGeometry();
   string leerObjeto();
};

#endif
