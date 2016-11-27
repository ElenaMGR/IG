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
   glPushMatrix();
      glTranslatef(0,moverFigura,0);
      glRotatef(-90,1,0,0);
      glRotatef(rotarFigura,0,0,1);
      switch (caso) {
         case 0: dibujarDelfin(face, mode, ajedrez); break;
         case 1: dibujarBarco(face, mode, ajedrez); break;
         case 2: dibujarAvion(face, mode, ajedrez); break;
         case 3: dibujarHelicoptero(face, mode, ajedrez); break;
      }
   glPopMatrix();

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
   glPushMatrix();
      glScalef(0.3,0.3,0.3);
      figurita.draw(face, mode, ajedrez);
   glPopMatrix();
}

void Figura::dibujarBarco(GLenum face, GLenum mode, bool ajedrez){
   glPushMatrix();
      glScalef(0.15,0.15,0.15);
      figurita.draw(face, mode, ajedrez);
   glPopMatrix();
}

void Figura::dibujarAvion(GLenum face, GLenum mode, bool ajedrez){
   glPushMatrix();
      glScalef(0.3,0.3,0.3);
      figurita.draw(face, mode, ajedrez);
   glPopMatrix();
}

void Figura::dibujarHelicoptero(GLenum face, GLenum mode, bool ajedrez){
   glPushMatrix();
      glScalef(0.3,0.3,0.3);
      figurita.draw(face, mode, ajedrez);
   glPopMatrix();
}

void Figura::setRotarFigura(double rotarFigura){
   this->rotarFigura += rotarFigura;
   this->rotarFigura = fmod(this->rotarFigura,360);
}

void Figura::setMoverFigura (double moverFigura){
   this->moverFigura += (tope) ? moverFigura : -moverFigura;

   if (this->moverFigura < -35)
      tope = true;
   if (this->moverFigura > -15)
      tope = false;
}
