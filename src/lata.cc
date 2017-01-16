#ifdef _WIN32
#include <windows.h>
#endif

#include "lata.h"

Lata::Lata(){
   cuerpo_lata.leerPLY("lata-pcue");
   cuerpo_lata.createGeometry(20,false,false,false);

   tapa_lata.leerPLY("lata-psup");
   tapa_lata.createGeometry(20,true,true,false);

   base_lata.leerPLY("lata-pinf");
   base_lata.createGeometry(20,true,true,false);
}

void Lata::draw(GLenum face, GLenum mode, bool ajedrez){
   glPushMatrix();
   glScalef(2,2,2);
      glPushMatrix();
         glScalef(50,50,50);
         cuerpo_lata.draw(face,mode,ajedrez);
         //Tapa y base
         tapa_lata.draw(face,mode,ajedrez);
         base_lata.draw(face,mode,ajedrez);
      glPopMatrix();
   glPopMatrix();
}


void Lata::asignarColor(GLfloat R ,GLfloat G ,GLfloat B){
   cuerpo_lata.asignarColor(R,G,B);
   tapa_lata.asignarColor(R,G,B);
   base_lata.asignarColor(R,G,B);
}
