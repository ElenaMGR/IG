#ifndef _FIGURA_H
#define _FIGURA_H

#include "cilindro.h"
#include "objPLY.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <string>
#include <math.h>

class Figura {
   private:
      Cilindro cilindro;
      ObjPLY figurita;
      void dibujarCilindro(GLenum face, GLenum mode, bool ajedrez);
      void dibujarDelfin(GLenum face, GLenum mode, bool ajedrez);
      void dibujarAvion(GLenum face, GLenum mode, bool ajedrez);
      void dibujarBarco(GLenum face, GLenum mode, bool ajedrez);
      void dibujarHelicoptero(GLenum face, GLenum mode, bool ajedrez);
      double rotarFigura = 5;
   public:
      Figura();
      void cargarPLY(string nombrePLY);
      void draw(GLenum face, GLenum mode, bool ajedrez, int caso);
      void setRotarFigura(double rotarFigura);
};

#endif
