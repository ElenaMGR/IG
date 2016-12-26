#ifndef _ESCENAP4_H
#define _ESCENAP4_H

#include <GL/glut.h>
#include <GL/gl.h>
#include <string>
#include <math.h>
#include "objRevolucion.h"
#include "material.h"

class EscenaP4{

private:
  // Formas básicas
  ObjRevolucion peon, cuerpo_lata, base_lata, tapa_lata;
  Material material_madera,material_blanco,material_negro, material_cuerpo, material_metalico;

public:
  EscenaP4();

  void draw(GLenum face,int mode_view,GLfloat n);

  void activarMaterial();


};

#endif
