#ifdef _WIN32
#include <windows.h>
#endif

#include "camara.h"


Camara::Camara(){}

Camara::Camara(bool perspectiva, GLdouble eye[3], GLdouble at[3], GLdouble up[3], GLdouble lente[6]){
   this->perspectiva=perspectiva;
   this->eye[0]=eye[0];
   this->eye[1]=eye[1];
   this->eye[2]=eye[2];
   this->at[0]=at[0];
   this->at[1]=at[1];
   this->at[2]=at[2];
   this->up[0]=up[0];
   this->up[1]=up[1];
   this->up[2]=up[2];
   left=lente[0];
   right=lente[1];
   botton=lente[2];
   top=lente[3];
   near=lente[4];
   far=lente[5];
}

void Camara::setLente(GLdouble lente[6]){
   left=lente[0];
   right=lente[1];
   botton=lente[2];
   top=lente[3];
   near=lente[4];
   far=lente[5];
}

void Camara::setLente(GLdouble left, GLdouble right, GLdouble botton, GLdouble top, GLdouble near, GLdouble far){
   this->left=left;
   this->right=right;
   this->botton=botton;
   this->top=top;
   this->near=near;
   this->far=far;
}

void Camara::setPosition(GLdouble eye[3], GLdouble at[3], GLdouble up[3]){
   this->eye[0]=eye[0];
   this->eye[1]=eye[1];
   this->eye[2]=eye[2];
   this->at[0]=at[0];
   this->at[1]=at[1];
   this->at[2]=at[2];
   this->up[0]=up[0];
   this->up[1]=up[1];
   this->up[2]=up[2];
}

void Camara::setPositionEye(GLdouble eyex, GLdouble eyey, GLdouble eyez){
   eye[0]=eyex;
   eye[1]=eyey;
   eye[2]=eyez;
}

void Camara::setPositionEye(GLdouble eyex, GLdouble eyey){
   eye[0]=eyex;
   eye[1]=eyey;
}

void Camara::setPositionAt(GLdouble atx, GLdouble aty, GLdouble atz){
   at[0]=atx;
   at[1]=aty;
   at[2]=atz;
}

void Camara::setPositionAt(GLdouble atx, GLdouble aty){
   at[0]=atx;
   at[1]=aty;
}

void Camara::setPositionUp(GLdouble upx, GLdouble upy, GLdouble upz){
   up[0]=upx;
   up[1]=upy;
   up[2]=upz;
}

void Camara::setProyeccion(){
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   if(perspectiva)
      glFrustum(left, right, botton, top, near, far);
   else
      glOrtho(left, right, botton, top, near, far);
}

void Camara::setLookAt(){
   gluLookAt(eye[0],eye[1],eye[2],at[0],at[1],at[2],up[0],up[1],up[2]);
}

void Camara::setPerspectiva(bool perspectiva){
   this->perspectiva=perspectiva;
}

void Camara::moverEye(GLdouble eyex, GLdouble eyey, GLdouble eyez){
   eye[0]+=eyex;
   eye[1]+=eyey;
   eye[2]+=eyez;
}


void Camara::zoom(int numero){

}
