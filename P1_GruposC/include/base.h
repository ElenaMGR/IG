#ifndef _BASE_H
#define _BASE_H

#include "cilindro.h"
#include "esfera.h"
#include <GL/glut.h>
#include <GL/gl.h>

class Base {

private:
   Cilindro cilindro;
   void DibujarCilindro(GLenum face, GLenum mode, bool ajedrez);
   void DibujarCilindros(GLenum face, GLenum mode, bool ajedrez);
   void DibujarEsfera(GLenum face, GLenum mode, bool ajedrez);

   Esfera esfera;

public:
   Base();
   void draw(GLenum face, GLenum mode, bool ajedrez);

};


#endif
