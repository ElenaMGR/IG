#ifdef _WIN32
#include <windows.h>
#endif

#include "movil.h"

Movil::Movil(){
   figuraDelfin.cargarPLY("dolphins",0.02,0.04,0.8);
   figuraBarco.cargarPLY("galleon",0.38,0.25,0.07);
   figuraAvion.cargarPLY("x29",0.39,0.53,0.40);
   figuraHelicoptero.cargarPLY("hind",1,0.28,0.28);
}


void Movil::draw(GLenum face, GLenum mode, bool ajedrez){
   glPushMatrix();

      glScalef(1.3,1.3,1.3);
      glTranslatef(0,50,0);
      glRotatef(balanceo,0,0,1);

      glPushMatrix();
         glTranslatef(0,-20,0);
         glScalef(1,40,1);
         cuerda.draw(GL_FRONT_AND_BACK, mode, ajedrez);
      glPopMatrix();

      glTranslatef(0,-40,0);

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

void Movil::setMoverFigura(){
   figuraDelfin.setMoverFigura(1);
   figuraBarco.setMoverFigura(2);
   figuraAvion.setMoverFigura(3);
   figuraHelicoptero.setMoverFigura(4);
}

void Movil::setBalanceo(){
   balanceo += (tope) ? 3 : -3;

   if (balanceo < -40)
      tope = true;
   if (balanceo > 40)
      tope = false;

}
