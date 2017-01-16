#ifndef _TEXTURA_H
#define _TEXTURA_H
#include <GL/glut.h>
#include <GL/gl.h>
#include "bitmap_image.h"
#include "tuplas.h"

class Textura{

private:
	unsigned int idTex;
	bool auto_coords;
	bitmap_image img;
	unsigned int tamx;
	unsigned int tamy;
	unsigned char * texels;
	float  coor_t[4],coor_s[4];

public:

	Textura(int id,const char * nombreFichero, bool gen_aut_coordenadas,Tupla3r ct, Tupla3r cs,Tupla3r punto_origen);
   Textura(int id,const char * nombreFichero, bool gen_aut_coordenadas,Tupla3r ct, Tupla3r cs);
	void activar();
};
#endif
