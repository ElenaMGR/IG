#ifndef _CAMARA_H
#define _CAMARA_H

#include <GL/glut.h>
#include <GL/gl.h>
#include "tuplas.h"

class Camara{
   private:
      Tupla3r eye; // posicion del ojo
      Tupla3r at; // punto hacia el que se mira
      Tupla3r up; // sentido
      Tupla3r dir; // direccion
      Tupla3r derecha; 
      GLfloat left, right, botton, top, near, far; //lente
      bool perspectiva;
      bool modoLibre;

   public:
      Camara();
      Camara(bool perspectiva, bool modoLibre, Tupla3r eye, Tupla3r at, Tupla3r up, GLfloat lente[6]);
      void setLente(GLfloat lente[6]);
      void setLente(GLfloat left, GLfloat right, GLfloat botton, GLfloat top, GLfloat near, GLfloat far);
      void setPosition(Tupla3r eye, Tupla3r at, Tupla3r up);
      void setPositionEye(GLfloat eyex, GLfloat eyey, GLfloat eyez);
      void setPositionEye(GLfloat eyex, GLfloat eyey);
      void setPositionAt(GLfloat atx, GLfloat aty, GLfloat atz);
      void setPositionAt(GLfloat atx, GLfloat aty);
      Tupla3r getPositionAt ();
      void setPositionUp(GLfloat upx, GLfloat upy, GLfloat upz);
      void setProyeccion();
      void setLookAt();
      void setPerspectiva(bool perspectiva);
      void zoom(int numero);
      void moverEye(GLfloat eyex, GLfloat eyey, GLfloat eyez);

      void avanzar(int x);
      void movLateral(int x);
      void movVertical(int x);
      void giroHoriz(int x);
      void giroVert(int x);
};

#endif
