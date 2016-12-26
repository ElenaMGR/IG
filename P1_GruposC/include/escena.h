#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "tetraedro.h"
#include "cubo.h"
#include "octaedro.h"
#include "objPLY.h"
#include "objRevolucion.h"
#include "cilindro.h"
#include "movil.h"
#include "luz.h"
#include "escenaP4.h"
#include <iostream>

using namespace std;

class Escena {
private:
// tama�o de los ejes
#define AXIS_SIZE 5000
Ejes ejes;

// Objetos
Tetraedro tetraedro;
Cubo cubo;
Octaedro octaedro;
Obj3D obj3D;
ObjPLY objPly;
ObjRevolucion objRevolucion;
Cilindro cilindro;
Movil movil;
Luz luz;
EscenaP4 escenaPractica4;

//Variables de control
GLenum modo;
bool ajedrez;
bool tapa, base;
int rev;
double angulo;
bool animacion = false;

int velocidadRFigura = 100;
int velocidadMFigura = 100;
int velocidadBalanceo = 100;
int velocidadRMovil = 100;

int anima1=0;
int anima2=0;
int anima3=0;
int anima4=0;

int practica=4;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Width,Height,Front_plane,Back_plane;

private:
	void clear_window();
	void draw_axis();
	void draw_objects();

//Transformaci�n de c�mara
	void change_projection();
	void change_observer();

//Velocidades
	void cambiarVelocidadTotal(int vel);
	void cambiarVelocidadRFigura(int vel);
	void cambiarVelocidadMFigura(int vel);
	void cambiarVelocidadBalanceo(int vel);
	void cambiarVelocidadRMovil(int vel);

//mostrar las opciones del menú dependiendo de la práctica
	void mostrarMenu();
	void inicializarPractica();

public:
     Escena();
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight) ;

	// Dibujar
	void dibujar() ;

	// Interacci�n con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);
	void animar();


};
#endif
