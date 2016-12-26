#include "material.h"


Material::Material(){
   ambiental=Tupla4r(0,0,1,1);
   difusa=Tupla4r(0.2,0.2,1,1);
   especular=Tupla4r(1,1,1,1);
   brillo=0;
}

Material::Material(int id,Tupla4r ambiental, Tupla4r difusa, Tupla4r especular, float brillo){
   this->ambiental=ambiental;
   this->difusa=difusa;
   this->especular=especular;
   this->brillo=brillo;
}

Material::Material(Tupla4r color){
   ambiental=color;
   difusa=color;
   especular=color;
   brillo=0;
}

Material::Material(int id,const char * nombreFichero,bool gen_aut_coordenadas,Tupla3r ct, Tupla3r cs){
   textura = new Textura(id,nombreFichero, gen_aut_coordenadas,ct,cs);

   ambiental=Tupla4r(0.2,0.2,0.2,1);
   difusa=Tupla4r(0.8,0.8,0.8,1);
   especular=Tupla4r(0.1,0.1,0.1,1);
   brillo=0;
}

Material::Material(int id,const char * nombreFichero,bool gen_aut_coordenadas,Tupla3r ct,
      Tupla3r cs,Tupla4r ambiental, Tupla4r difusa, Tupla4r especular, float brillo){

   textura = new Textura(id,nombreFichero, gen_aut_coordenadas,ct,cs);

   this->ambiental=ambiental;
   this->difusa=difusa;
   this->especular=especular;
   this->brillo=brillo;
}

void Material::setColores(Tupla4r ambiental, Tupla4r difusa, Tupla4r especular, float brillo){
   this->ambiental=ambiental;
   this->difusa=difusa;
   this->especular=especular;
   this->brillo=brillo;
}

void Material::setTextura(int id,const char * nombreFichero, bool gen_aut_coordenadas,Tupla3r ct, Tupla3r cs){
   textura=new Textura(id,nombreFichero,gen_aut_coordenadas,ct,cs);
}

void Material::activarMaterial(){
   glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, ambiental.coords ) ;
   glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, difusa.coords ) ;
   glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, especular.coords ) ;
   glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, brillo );

   glColor4fv(ambiental.coords);

   if(textura!=NULL){
      glEnable(GL_TEXTURE_2D);
      textura->activar();
   }
   else{
      glDisable(GL_TEXTURE_2D);
   }
}
