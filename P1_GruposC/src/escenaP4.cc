#include "escenaP4.h"

EscenaP4::EscenaP4(){
   //Peon
   peon.leerPLY("peon");
   peon.createGeometry(20,true,true,false);
   material_madera = Material(1,"./texturas/text-madera.bmp",true,Tupla3r(1,0,0),Tupla3r(0,1,0),
               Tupla4r(0.5,0.4,0.5,1.0),Tupla4r(0.5,0.2,0.0,1),Tupla4r(0.5,0.2,0.0,1),50);
   material_blanco= Material(2,Tupla4r(0.1,0.1,0.1,1)   ,Tupla4r(1.0,1.0,1.0,1.0),Tupla4r(0.0,0.0,0.0,1),128.0);
   material_negro = Material(3,Tupla4r(0.01,0.01,0.01,1),Tupla4r(0.1,0.1,0.1,1)  ,Tupla4r(0.9,0.9,0.9,1),10.0);
   cuerpo_lata.leerPLY("lata-pcue");
   cuerpo_lata.createGeometry(20,false,false,false);
   //Lata
   tapa_lata.leerPLY("lata-psup");
   tapa_lata.createGeometry(20,true,true,false);

   base_lata.leerPLY("lata-pinf");
   base_lata.createGeometry(20,true,true,false);
   material_cuerpo =  Material(9,"./texturas/text-lata-1.bmp",true,Tupla3r(1,0,0),Tupla3r(0,1,0),
                     Tupla4r(0.2,0.2,0.2,1.0),Tupla4r(0.5,0.5,0.5,1),Tupla4r(0.5,0.5,0.5,1),80);
   material_metalico =Material(5,Tupla4r(0.2,0.2,0.2,1.0),Tupla4r(0.5,0.5,0.5,1),Tupla4r(0.5,0.5,0.5,1),80);
}


void EscenaP4::draw(GLenum face,int mode_view,GLfloat n){
   glPushMatrix();
   glScalef(2,2,2);

      glPushMatrix();
         glScalef(10,10,10);
         glTranslatef(3.5,1.4,-3);
         // Peon madera
         material_madera.activarMaterial();
         peon.draw(face,mode_view,n);

         // peon blanco
         glTranslatef(0,0,3);
         material_blanco.activarMaterial();
         peon.draw(face,mode_view,n);

         // peon negro
         glTranslatef(0,0,3);
         material_negro.activarMaterial();
         peon.draw(face,mode_view,n);

      glPopMatrix();

      glPushMatrix();
         glScalef(50,50,50);
         material_cuerpo.activarMaterial();
         cuerpo_lata.draw(face,mode_view,n);

         //Tapa y base
         material_metalico.activarMaterial();
         tapa_lata.draw(face,mode_view,n);
         base_lata.draw(face,mode_view,n);
      glPopMatrix();

   glPopMatrix();
}
