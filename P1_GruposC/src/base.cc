#ifdef _WIN32
#include <windows.h>
#endif

#include "base.h"

Base::Base(){

}

void Base::draw(GLenum face, GLenum mode, bool ajedrez){
   dibujarTorus();
   dibujarCilindros(face,mode,ajedrez);
   dibujarEsfera(face,mode,ajedrez);
}

void Base::dibujarCilindro(GLenum face, GLenum mode, bool ajedrez){
   glPushMatrix();

      glRotatef(90,1,0,0);
      glTranslatef(0,25,0);
      glScalef(1.5,40,1.5);
      cilindro.draw(face, mode, ajedrez);

   glPopMatrix();
}

void Base::dibujarCilindros(GLenum face, GLenum mode, bool ajedrez){
   glPushMatrix();
      glRotatef(90,0,1,0);
      dibujarCilindro(face, mode, ajedrez);
   glPopMatrix();

   glPushMatrix();
      glRotatef(180,0,1,0);
      dibujarCilindro(face, mode, ajedrez);
   glPopMatrix();

   glPushMatrix();
      glRotatef(-90,0,1,0);
      dibujarCilindro(face, mode, ajedrez);
   glPopMatrix();

   glPushMatrix();
      dibujarCilindro(face, mode, ajedrez);
   glPopMatrix();
}

void Base::dibujarEsfera(GLenum face, GLenum mode, bool ajedrez){
   glScalef(10,10,10);
   esfera.draw(face, mode, ajedrez);
}

void Base::dibujarTorus (){
   glPushMatrix();

      glRotatef(90,1,0,0);
      glColor3d(0,0,0);
      glutSolidTorus(1,46,40,40);

   glPopMatrix();
}
