#ifdef _WIN32
#include <windows.h>
#endif

#include "base.h"

Base::Base(){

}

void Base::draw(GLenum face, GLenum mode, bool ajedrez){
   DibujarCilindros(face,mode,ajedrez);
   DibujarEsfera(face,mode,ajedrez);
}

void Base::DibujarCilindro(GLenum face, GLenum mode, bool ajedrez){
   glPushMatrix();

   glTranslatef(0,18,-13);
   glRotatef(30,1,0,0);
   glScalef(1.5,40,1.5);
   cilindro.draw(face, mode, ajedrez);

   glPopMatrix();
}

void Base::DibujarCilindros(GLenum face, GLenum mode, bool ajedrez){
   glPushMatrix();
   glRotatef(90,0,1,0);
   DibujarCilindro(face, mode, ajedrez);
   glPopMatrix();

   glPushMatrix();
   glRotatef(180,0,1,0);
   DibujarCilindro(face, mode, ajedrez);
   glPopMatrix();

   glPushMatrix();
   glRotatef(-90,0,1,0);
   DibujarCilindro(face, mode, ajedrez);
   glPopMatrix();

   glPushMatrix();
   DibujarCilindro(face, mode, ajedrez);
   glPopMatrix();
}

void Base::DibujarEsfera(GLenum face, GLenum mode, bool ajedrez){
   glTranslatef(0,36,0);
   glScalef(7,7,7);
   esfera.draw(face, mode, ajedrez);
}
