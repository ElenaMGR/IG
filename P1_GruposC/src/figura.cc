#ifdef _WIN32
#include <windows.h>
#endif

#include "figura.h"

Figura::Figura(){
}

void Figura::cargarPLY(string nombrePLY){
   figurita.leerPLY(nombrePLY);
   figurita.createGeometry(true);
}

void Figura::draw(GLenum face, GLenum mode, bool ajedrez, int caso){
   switch (caso) {
      case 0: dibujarDelfin(face, mode, ajedrez); break;
      case 1: dibujarAvion(face, mode, ajedrez); break;
      case 2: dibujarBarco(face, mode, ajedrez); break;
      case 3: dibujarHelicoptero(face, mode, ajedrez); break;
   }

   dibujarCilindro(face, mode, ajedrez);
}

void Figura::dibujarCilindro(GLenum face, GLenum mode, bool ajedrez){
   glPushMatrix();

      glTranslatef(0,-25,0);
      glScalef(1.5,50,1.5);
      cilindro.draw(face, mode, ajedrez);

   glPopMatrix();
}

void Figura::dibujarDelfin(GLenum face, GLenum mode, bool ajedrez){
   cargarPLY("dolphins");
   glPushMatrix();
      glTranslatef(0,-20,0);
      glRotatef(-90,1,0,0);
      glScalef(0.3,0.3,0.3);
      figurita.draw(face, mode, ajedrez);
   glPopMatrix();
}

void Figura::dibujarBarco(GLenum face, GLenum mode, bool ajedrez){
   cargarPLY("galleon");
   glPushMatrix();
      glTranslatef(0,-20,0);
      glRotatef(-90,1,0,0);
      glScalef(0.15,0.15,0.15);
      figurita.draw(face, mode, ajedrez);
   glPopMatrix();
}

void Figura::dibujarAvion(GLenum face, GLenum mode, bool ajedrez){
   cargarPLY("x29");
   glPushMatrix();
      glTranslatef(0,-20,0);
      glRotatef(-90,1,0,0);
      glScalef(0.3,0.3,0.3);
      figurita.draw(face, mode, ajedrez);
   glPopMatrix();
}

void Figura::dibujarHelicoptero(GLenum face, GLenum mode, bool ajedrez){
   cargarPLY("hind");
   glPushMatrix();
      glTranslatef(0,-20,0);
      glRotatef(-90,1,0,0);
      glScalef(0.3,0.3,0.3);
      figurita.draw(face, mode, ajedrez);
   glPopMatrix();
}
