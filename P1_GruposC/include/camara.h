#ifndef _CAMARA_H
#define _CAMARA_H

#include <GL/glut.h>
#include <GL/gl.h>

class Camara{
   private:
      GLdouble eye[3]; // posicion del ojo
      GLdouble at[3]; // punto hacia el que se mira
      GLdouble up[3]; // sentido
      GLdouble left, right, botton, top, near, far; //lente
      bool perspectiva;

   public:
      Camara();
      Camara(bool perspectiva, GLdouble eye[3], GLdouble at[3], GLdouble up[3], GLdouble lente[6]);
      void setLente(GLdouble lente[6]);
      void setLente(GLdouble left, GLdouble right, GLdouble botton, GLdouble top, GLdouble near, GLdouble far);
      void setPosition(GLdouble eye[3], GLdouble at[3], GLdouble up[3]);
      void setPositionEye(GLdouble eyex, GLdouble eyey, GLdouble eyez);
      void setPositionEye(GLdouble eyex, GLdouble eyey);
      void setPositionAt(GLdouble atx, GLdouble aty, GLdouble atz);
      void setPositionAt(GLdouble atx, GLdouble aty);
      void setPositionUp(GLdouble upx, GLdouble upy, GLdouble upz);
      void setProyeccion();
      void setLookAt();
      void setPerspectiva(bool perspectiva);
      void zoom(int numero);
      void moverEye(GLdouble eyex, GLdouble eyey, GLdouble eyez);
};

#endif
