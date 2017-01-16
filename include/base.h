#ifndef _BASE_H
#define _BASE_H

#include "cilindro.h"
#include "esfera.h"
#include <GL/glut.h>
#include <GL/gl.h>

class Base {

private:
   Cilindro cilindro;
   void dibujarCilindro(GLenum face, GLenum mode, bool ajedrez);
   void dibujarCilindros(GLenum face, GLenum mode, bool ajedrez);
   void dibujarEsfera(GLenum face, GLenum mode, bool ajedrez);
   void dibujarTorus();

   Esfera esfera;

public:
   Base();
   void draw(GLenum face, GLenum mode, bool ajedrez);

};


#endif
