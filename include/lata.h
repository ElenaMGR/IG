#ifndef _LATA_H
#define _LATA_H

#include "objRevolucion.h"
#include <GL/glut.h>
#include <GL/gl.h>

class Lata {

private:
   ObjRevolucion cuerpo_lata, base_lata, tapa_lata;

public:
   Lata();
   void draw(GLenum face, GLenum mode, bool ajedrez);
   void asignarColor(GLfloat R ,GLfloat G ,GLfloat B);

};
#endif
