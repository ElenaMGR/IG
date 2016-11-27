#ifndef _MOVIL_H
#define _MOVIL_H

#include "figura.h"
#include "base.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <string>
#include <math.h>

class Movil {
   private:
      Figura figuraDelfin;
      Figura figuraBarco;
      Figura figuraAvion;
      Figura figuraHelicoptero;
      Base base;
      double rotarTodo = 5;
   public:
      Movil();
      void draw(GLenum face, GLenum mode, bool ajedrez);
      void setRotarTodo();
      void setRotarFigura();

};

#endif
