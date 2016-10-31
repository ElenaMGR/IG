#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "escena.h"


Escena::Escena(){
    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
    ejes.changeAxisSize(5000);
    objPly.leerPLY("beethoven");
    objPly.createGeometry();
    obj3D = objPly;
    modo = GL_LINE;
    ajedrez = false;
    tapa=true;
    base=true;
    rev=20;
    objRevolucion.leerPLY("peon");
    objRevolucion.createGeometry(rev,tapa,base);
}

void Escena::inicializar(int UI_window_width,int UI_window_height) {

	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer
   glEnable (GL_CULL_FACE);

	this->change_projection();
	Width=UI_window_width/10;
	Height=UI_window_height/10;
	glViewport(0,0,UI_window_width,UI_window_height);

}


//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects() {
   obj3D.draw(GL_FRONT_AND_BACK, modo, ajedrez);
}



void Escena::dibujar() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
	draw_axis();
	draw_objects();
}



int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {

   std::cout << "Tecla " << Tecla1<< std::endl;
   switch (toupper(Tecla1)) {
    case 'Q': return 1; break;
    case 'L': modo = GL_LINE; ajedrez = false; break;
    case 'F': modo = GL_FILL; ajedrez = false; break;
    case 'P': modo = GL_POINT; ajedrez = false; break;
    case 'T': obj3D = tetraedro; break;
    case 'C': obj3D = cubo; break;
    case 'O': obj3D = octaedro; break;
    case 'A': ajedrez = true; modo = GL_FILL; break;
    case 'Y': objPly.leerPLY(objPly.leerObjeto()); objPly.createGeometry() ;obj3D = objPly; break;
    case 'R': objRevolucion.leerPLY(objRevolucion.leerObjeto()) ;
               rev = objRevolucion.leerObjetoRev();
               objRevolucion.createGeometry(rev,tapa,base) ;
               obj3D = objRevolucion;
               break;
    case 'X': rev = objRevolucion.leerObjetoRev();
               objRevolucion.createGeometry(rev,tapa,base) ;
               obj3D = objRevolucion;
               break;
    case 'B': base = !base; objRevolucion.createGeometry(rev,tapa,base) ;
               obj3D = objRevolucion;
               break;
    case 'V': tapa = !tapa; objRevolucion.createGeometry(rev,tapa,base) ;
               obj3D = objRevolucion;
               break;
  }
  return 0;
}


void Escena::teclaEspecial(int Tecla1,int x,int y) {
switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}

	std::cout << Observer_distance << std::endl;
}


//**************************************************************************
// Funcion para definir la transformaci�n de proyeccion
//***************************************************************************

void Escena::change_projection()  {
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
}


void Escena::redimensionar(int newWidth,int newHeight) {
change_projection();
Width=newWidth/10;
Height=newHeight/10;
glViewport(0,0,newWidth,newHeight);
}


//**************************************************************************
// Funcion para definir la transformaci�n de vista (posicionar la camara)
//***************************************************************************



void Escena::change_observer() {

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}


//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void Escena::draw_axis()
{
ejes.draw();
}
