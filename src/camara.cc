#ifdef _WIN32
#include <windows.h>
#endif

#include "camara.h"


Camara::Camara(){
   modoLibre=true;
}

Camara::Camara(bool perspectiva, bool modoLibre, Tupla3r eye, Tupla3r at, Tupla3r up, GLfloat lente[6]){
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
   this->modoLibre=modoLibre;
   dir[0]=at[0]-eye[0];
   dir[1]=at[1]-eye[1];
   dir[2]=at[2]-eye[2];
   dir=normalized(dir);
   derecha[0] = up[1]*dir[2] - (up[2]*dir[1]);
  derecha[1] = up[2]*dir[0] - (up[0]*dir[2]);
  derecha[2] = up[0]*dir[1] - (up[1]*dir[0]);
  derecha = normalized(derecha);
}

void Camara::setLente(GLfloat lente[6]){
   left=lente[0];
   right=lente[1];
   botton=lente[2];
   top=lente[3];
   near=lente[4];
   far=lente[5];
}

void Camara::setLente(GLfloat left, GLfloat right, GLfloat botton, GLfloat top, GLfloat near, GLfloat far){
   this->left=left;
   this->right=right;
   this->botton=botton;
   this->top=top;
   this->near=near;
   this->far=far;
}

void Camara::setPosition(Tupla3r eye, Tupla3r at, Tupla3r up){
   this->eye[0]=eye[0];
   this->eye[1]=eye[1];
   this->eye[2]=eye[2];
   this->at[0]=at[0];
   this->at[1]=at[1];
   this->at[2]=at[2];
   this->up[0]=up[0];
   this->up[1]=up[1];
   this->up[2]=up[2];

   dir[0]=at[0]-eye[0];
   dir[1]=at[1]-eye[1];
   dir[2]=at[2]-eye[2];
   dir=normalized(dir);
   derecha[0] = up[1]*dir[2] - (up[2]*dir[1]);
  derecha[1] = up[2]*dir[0] - (up[0]*dir[2]);
  derecha[2] = up[0]*dir[1] - (up[1]*dir[0]);
  derecha = normalized(derecha);
}

void Camara::setPositionEye(GLfloat eyex, GLfloat eyey, GLfloat eyez){
   eye[0]=eyex;
   eye[1]=eyey;
   eye[2]=eyez;

   dir[0]=at[0]-eye[0];
   dir[1]=at[1]-eye[1];
   dir[2]=at[2]-eye[2];
   dir=normalized(dir);
   derecha[0] = up[1]*dir[2] - (up[2]*dir[1]);
  derecha[1] = up[2]*dir[0] - (up[0]*dir[2]);
  derecha[2] = up[0]*dir[1] - (up[1]*dir[0]);
  derecha = normalized(derecha);
}

void Camara::setPositionEye(GLfloat eyex, GLfloat eyey){
   eye[0]=eyex;
   eye[1]=eyey;

   dir[0]=at[0]-eye[0];
   dir[1]=at[1]-eye[1];
   dir[2]=at[2]-eye[2];
   dir=normalized(dir);
   derecha[0] = up[1]*dir[2] - (up[2]*dir[1]);
  derecha[1] = up[2]*dir[0] - (up[0]*dir[2]);
  derecha[2] = up[0]*dir[1] - (up[1]*dir[0]);
  derecha = normalized(derecha);
}

void Camara::setPositionAt(GLfloat atx, GLfloat aty, GLfloat atz){
   at[0]=atx;
   at[1]=aty;
   at[2]=atz;

   dir[0]=at[0]-eye[0];
   dir[1]=at[1]-eye[1];
   dir[2]=at[2]-eye[2];
   dir=normalized(dir);
   derecha[0] = up[1]*dir[2] - (up[2]*dir[1]);
  derecha[1] = up[2]*dir[0] - (up[0]*dir[2]);
  derecha[2] = up[0]*dir[1] - (up[1]*dir[0]);
  derecha = normalized(derecha);
}

void Camara::setPositionAt(GLfloat atx, GLfloat aty){
   at[0]=atx;
   at[1]=aty;

   dir[0]=at[0]-eye[0];
   dir[1]=at[1]-eye[1];
   dir[2]=at[2]-eye[2];
   dir=normalized(dir);
   derecha[0] = up[1]*dir[2] - (up[2]*dir[1]);
  derecha[1] = up[2]*dir[0] - (up[0]*dir[2]);
  derecha[2] = up[0]*dir[1] - (up[1]*dir[0]);
  derecha = normalized(derecha);
}
Tupla3r Camara::getPositionAt (){
   return Tupla3r(at[0],at[1],at[2]);
}

void Camara::setPositionUp(GLfloat upx, GLfloat upy, GLfloat upz){
   up[0]=upx;
   up[1]=upy;
   up[2]=upz;

   dir[0]=at[0]-eye[0];
   dir[1]=at[1]-eye[1];
   dir[2]=at[2]-eye[2];
   dir=normalized(dir);
   derecha[0] = up[1]*dir[2] - (up[2]*dir[1]);
  derecha[1] = up[2]*dir[0] - (up[0]*dir[2]);
  derecha[2] = up[0]*dir[1] - (up[1]*dir[0]);
  derecha = normalized(derecha);
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
   //gluLookAt(eye[0],eye[1],eye[2],at[0],at[1],at[2],up[0],up[1],up[2]);
   if (modoLibre)
      gluLookAt(eye[0],eye[1],eye[2],eye[0]+dir[0],eye[1]+dir[1],eye[2]+dir[2],up[0],up[1],up[2]);
}

void Camara::setPerspectiva(bool perspectiva){
   this->perspectiva=perspectiva;
}

void Camara::moverEye(GLfloat eyex, GLfloat eyey, GLfloat eyez){
   eye[0]+=eyex;
   eye[1]+=eyey;
   eye[2]+=eyez;
}


void Camara::zoom(int numero){

}

void Camara::avanzar(int x){
   eye += dir * x;
}

void Camara::movLateral(int x){
   eye += derecha * x;

}

void Camara::movVertical(int x){

}

void Camara::giroHoriz(int x){
   double alpha = (0.0174533)*x;
   dir[0]= (cos(alpha) * dir[0]) + (sin(alpha)*dir[2]);
   dir[1]= dir[1];
   dir[2]= (-sin(alpha) * dir[0])+ (cos(alpha)*dir[2]);
   dir = normalized(dir);

   derecha[0] = up[1]*dir[2] - (up[2]*dir[1]);
   derecha[1] = up[2]*dir[0] - (up[0]*dir[2]);
   derecha[2] = up[0]*dir[1] - (up[1]*dir[0]);
   derecha = normalized(derecha);
}

void Camara::giroVert(int x){
   double alpha = (0.0174533)*x;
   dir[0]= dir[0];
   dir[1]= (cos(alpha) * dir[1]) - (sin(alpha)*dir[2]);
   dir[2]= (sin(alpha) * dir[1])+ (cos(alpha)*dir[2]);
   dir = normalized(dir);

   derecha[0] = up[1]*dir[2] - (up[2]*dir[1]);
   derecha[1] = up[2]*dir[0] - (up[0]*dir[2]);
   derecha[2] = up[0]*dir[1] - (up[1]*dir[0]);
   derecha = normalized(derecha);
}
