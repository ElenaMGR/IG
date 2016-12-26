#ifndef _MATERIAL_H
#define _MATERIAL_H

#include "textura.h"
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

class Material{
private:
  Tupla4r ambiental,difusa,especular;
  float brillo;
  Textura *textura = NULL;


public:
  Material();
  // Constructores de materiales solidos
  Material(int id,Tupla4r ambiental, Tupla4r difusa, Tupla4r especular, float brillo);
  Material(Tupla4r color);
  // Constructores de material con textura
  Material(int id,const char * nombreFichero, bool gen_aut_coordenadas,Tupla3r ct, Tupla3r cs);
  Material(int id,const char * nombreFichero, bool gen_aut_coordenadas,Tupla3r ct, Tupla3r cs,Tupla4r ambiental, Tupla4r difusa, Tupla4r especular, float brillo);

  // Propiedades del material
  void setColores(Tupla4r ambiental, Tupla4r difusa, Tupla4r especular, float brillo);
  void setTextura(int id,const char * nombreFichero, bool gen_aut_coordenadas,Tupla3r ct, Tupla3r cs);

  void activarMaterial();

};
#endif
