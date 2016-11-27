#ifndef _MOVIL_H
#define _MOVIL_H

#include "figura.h"
#include "base.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <string>
#include <math.h>
#include "cilindro.h"

class Movil {
   private:
      Figura figuraDelfin;
      Figura figuraBarco;
      Figura figuraAvion;
      Figura figuraHelicoptero;
      Base base;
      Cilindro cuerda;
      double rotarTodo = 5;
      double balanceo = 0;
      bool tope = false;
   public:
      Movil();
      void draw(GLenum face, GLenum mode, bool ajedrez);
      void setRotarTodo();
      void setRotarFigura();
      void setMoverFigura();
      void setBalanceo();
};

#endif
