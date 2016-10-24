#ifndef _OBJPLY_H
#define _OBJPLY_H

#include "obj3D.h"
#include "file_ply_stl.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <string>

class ObjPLY : public Obj3D {

private:

public:
   ObjPLY();
   void leerPLY(string nombre);
};

#endif
