#include "textura.h"

Textura::Textura( int id,const char * nombreFichero, bool gen_aut_coordenadas,Tupla3r ct,
   Tupla3r cs,Tupla3r punto_origen){

  Tupla3r u_t,u_s;

  glGenTextures( id, &idTex );
  //pimg = new Imagen(nombreFichero);
  bitmap_image img(nombreFichero); // Carga la imagen
  img.bgr_to_rgb(); // Pasa a formato RGB, ya que usa BGR por defecto

  tamx = img.width();
  tamy = img.height();
  texels = img.data(); // Devuelve puntero al array de datos.

  auto_coords=gen_aut_coordenadas;

  u_t=normalized(ct); // Crear metodo para normalizar
  u_s=normalized(cs);

  for(int i=0;i<3;i++){ // REVISAR ASIGNACION
     coor_t[i]=u_t[i];
     coor_s[i]=u_s[i];
  }

  coor_t[3] =- punto_origen[0]*u_t[0]+punto_origen[1]*u_t[1]+punto_origen[2]*u_t[2];
  coor_s[3] =- punto_origen[0]*u_s[0]+punto_origen[1]*u_s[1]+punto_origen[2]*u_s[2]; //producto escalar

  activar();
  gluBuild2DMipmaps( GL_TEXTURE_2D,GL_RGB,tamx,tamy,GL_RGB,GL_UNSIGNED_BYTE,texels);

}



Textura::Textura( int id,const char * nombreFichero, bool gen_aut_coordenadas,Tupla3r ct, Tupla3r cs){
  Tupla3r u_t,u_s;


   glGenTextures( id, &idTex );
   bitmap_image img(nombreFichero); // Carga la imagen
   img.bgr_to_rgb(); // Pasa a formato RGB, ya que usa BGR por defecto

   tamx = img.width();
   tamy = img.height();
   texels = img.data(); // Devuelve puntero al array de datos.

   auto_coords=gen_aut_coordenadas;

   u_t=normalized(ct);  // Crear metodo para normalizar
   u_s=normalized(cs);

   for(int i=0;i<3;i++){
      coor_t[i]=u_t[i];
      coor_s[i]=u_s[i];
   }

   coor_t[3]=0;
   coor_s[3]=0;

   activar();
   std::cout << "TEX7 "<< tamx << "-"<<tamy<<std::endl;

   //gluBuild2DMipmaps( GL_TEXTURE_2D,GL_RGB,tamx,tamy,GL_RGB,GL_UNSIGNED_BYTE,texels);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,tamx, tamy, 0, GL_RGB, GL_UNSIGNED_BYTE, texels);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);


   std::cout << "TEX 8"<<std::endl;
}

void Textura::activar(){

    glBindTexture( GL_TEXTURE_2D, idTex );

    if(auto_coords){
       glEnable( GL_TEXTURE_GEN_S );
       glEnable( GL_TEXTURE_GEN_T );
       glTexGenfv( GL_S, GL_OBJECT_PLANE, coor_s ) ;
       glTexGenfv( GL_T, GL_OBJECT_PLANE, coor_t ) ;
    }
    else{
       glDisable( GL_TEXTURE_GEN_S );
       glDisable( GL_TEXTURE_GEN_T );
    }
}
