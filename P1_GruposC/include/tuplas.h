#ifndef _TUPLAS_H
#define _TUPLAS_H

#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>


/** TUPLA DE REALES
*   Tupla de Coordenadas(x,y,z) de reales.
*/
struct Tupla3r{
private:
  GLfloat coords[3];  // X=0  Y=1   Z=2

public:
  inline Tupla3r(){}

  inline Tupla3r( const float x, const float y, const float z){
     coords[0] = x ;
     coords[1] = y ;
     coords[2] = z ;
  }

  inline GLfloat& operator[](int eje){
      return coords[eje];
  }

  friend Tupla3r operator - (const Tupla3r & t1, const Tupla3r & t2){
    Tupla3r result;
    result[0] = t1.coords[0] - t2.coords[0];
    result[1] = t1.coords[1] - t2.coords[1];
    result[2] = t1.coords[2] - t2.coords[2];
    return result;
  }

  friend Tupla3r operator + (const Tupla3r & t1, const Tupla3r & t2){
    Tupla3r result;
    result[0] = t1.coords[0] + t2.coords[0];
    result[1] = t1.coords[1] + t2.coords[1];
    result[2] = t1.coords[2] + t2.coords[2];
    return result;
  }

  friend Tupla3r operator * (const Tupla3r & t1, const float & t2){
    Tupla3r result;
    result[0] = t1.coords[0] * t2;
    result[1] = t1.coords[1] * t2;
    result[2] = t1.coords[2] * t2;
    return result;
  }

  friend inline void operator -= ( Tupla3r & t1, const Tupla3r & t2 ){
    t1 = t1 - t2;
  }

  friend inline void operator += ( Tupla3r & t1, const Tupla3r & t2 ){
    t1 = t1 + t2;
  }

  friend inline void operator *= ( Tupla3r & t1, const float & t2 ){
    t1 = t1 * t2;
  }

  /** Función para normalizar una tupla
  *
  */
  friend Tupla3r normalized(Tupla3r & t1){
    Tupla3r resul;
    GLfloat aux;
    aux = sqrt(t1[0]*t1[0] + t1[1]*t1[1] + t1[2]*t1[2]);

    resul[0] = t1[0] / aux;
    resul[1] = t1[1] / aux;
    resul[2] = t1[2] / aux;

    return resul;
  }


};

/** TUPLA DE NATURALES
*   Indica los vertices que forma un triangulo con de naturales.
*/
struct Tupla3n{
private:
  GLuint coords[3];

public:
  inline GLuint& operator[](int eje){
      return coords[eje];
  }
};

/** TUPLA DE NATURALES
*   Indica los vertices que forma un triangulo con de naturales.
*/
struct Tupla4r{

  GLfloat coords[4];

  inline Tupla4r(){}

  inline Tupla4r( const float x, const float y, const float z, const float w ){
     coords[0] = x ;
     coords[1] = y ;
     coords[2] = z ;
     coords[3] = w ;
  }

  inline GLfloat& operator[](int eje){
      return coords[eje];
  }
};


#endif
