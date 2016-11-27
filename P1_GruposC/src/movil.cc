#ifdef _WIN32
#include <windows.h>
#endif

#include "movil.h"

Movil::Movil(){
   figuraDelfin.cargarPLY("dolphins");
   figuraBarco.cargarPLY("galleon");
   figuraAvion.cargarPLY("x29");
   figuraHelicoptero.cargarPLY("hind");
}


void Movil::draw(GLenum face, GLenum mode, bool ajedrez){
   glPushMatrix();

      glRotatef(rotarTodo,0,1,0);

      glPushMatrix();
         base.draw(GL_FRONT_AND_BACK, mode, ajedrez);
      glPopMatrix();

      glPushMatrix();
         glTranslatef(45.5,0,0);
         figuraDelfin.draw(GL_FRONT_AND_BACK, mode, ajedrez,0);
      glPopMatrix();

      glPushMatrix();
         glTranslatef(-45.5,0,0);
         figuraBarco.draw(GL_FRONT_AND_BACK, mode, ajedrez,1);
      glPopMatrix();

      glPushMatrix();
         glTranslatef(0,0,45.5);
         figuraAvion.draw(GL_FRONT_AND_BACK, mode, ajedrez,2);
      glPopMatrix();

      glPushMatrix();
         glTranslatef(0,0,-45.5);
         figuraHelicoptero.draw(GL_FRONT_AND_BACK, mode, ajedrez,3);
      glPopMatrix();

      glPushMatrix();
         glTranslatef(0,-50,0);
         base.draw(GL_FRONT_AND_BACK, mode, ajedrez);
      glPopMatrix();

   glPopMatrix();
}

void Movil::setRotarTodo(){
   rotarTodo += 5;
   rotarTodo = fmod (rotarTodo,360);
}

void Movil::setRotarFigura(){
   figuraDelfin.setRotarFigura(3);
   figuraBarco.setRotarFigura(6);
   figuraAvion.setRotarFigura(9);
   figuraHelicoptero.setRotarFigura(12);
}
