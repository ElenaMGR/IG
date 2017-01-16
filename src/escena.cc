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
    modo = GL_LINE;
    ajedrez = false;
    tapa=true;
    base=true;
    practica = 5;
    mostrarMenu();
}

void Escena::inicializar(int UI_window_width,int UI_window_height) {

	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer
   glEnable (GL_CULL_FACE);

   Width=UI_window_width/10;
	Height=UI_window_height/10;

   if (practica==4){
      luz.enableLuz(true);
      luz.Inicializarluz();
   }

   if (practica==5){
      objPly.leerPLY("eg07"); objPly.createGeometry(true) ;
      objPly2=objPly;
      peon.leerPLY("peon");
      peon.createGeometry(20,true,true,false);
      peon2=peon;

      //Camaras
      GLfloat lente[6] = {-Width,Width,-Height,Height,Front_plane,Back_plane};

      // frente
      camara1.setPositionEye(0,0,200);
      camara1.setPositionAt(0,0,0);
      camara1.setPositionUp(0,1,0);
      // alzado
      camara2.setPositionEye(0,200,0);
      camara2.setPositionAt(0,0,0);
      camara2.setPositionUp(0,0,-1);
      // Perfil
      camara3.setPositionEye(200,0,0);
      camara3.setPositionAt(0,0,0);
      camara3.setPositionUp(0,1,0);

      camara1.setLente(lente);
      camara2.setLente(lente);
      camara3.setLente(lente);

      camara1.setPerspectiva(true); // perspectiva
      camara2.setPerspectiva(true); // perspectiva
      camara3.setPerspectiva(false); // Ortogonal
      camaras[0] = camara1;
      camaras[1] = camara2;
      camaras[2] = camara3;
      camaraActiva = 0; //por defecto se activa la camara1
      cout << "Iniciada camara"<< endl;
   }

	this->change_projection();
	glViewport(0,0,UI_window_width,UI_window_height);

}


//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects() {
   if (practica==3){
      movil.draw(GL_FRONT_AND_BACK, modo, ajedrez);
   }else if (practica==4){
      escenaPractica4.draw(GL_FRONT_AND_BACK, modo, ajedrez);
   }else if (practica==5){
      modo=GL_FILL;
      //escenaPractica4.draw(GL_FRONT_AND_BACK, modo, ajedrez);
      lata.draw(GL_FRONT_AND_BACK, modo, ajedrez);
      glPushMatrix();
         glTranslatef(-130,20,0);
         objPly.draw(GL_FRONT_AND_BACK, modo, ajedrez);
      glPopMatrix();
      glPushMatrix();
      glScalef(2,2,2);
         glPushMatrix();
            glScalef(10,10,10);
            glTranslatef(3.5,1.4,-3);
            peon.draw(GL_FRONT_AND_BACK,modo,ajedrez);
            glTranslatef(0,0,3);
            peon.draw(GL_FRONT_AND_BACK,modo,ajedrez);
            glTranslatef(0,0,3);
            peon.draw(GL_FRONT_AND_BACK,modo,ajedrez);
         glPopMatrix();
      glPopMatrix();
   }else {
      obj3D.draw(GL_FRONT_AND_BACK, modo, ajedrez);
   }

}



void Escena::dibujar() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
	draw_axis();
	draw_objects();
}



int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {


   cout << "Tecla " << Tecla1<< std::endl;
   switch (toupper(Tecla1)) {
      case 'Q': return 1; break;

      //Elegir práctica a mostrar:
      case '1': practica=1; cout<<"Elegida pŕactica 1"<<endl; mostrarMenu(); inicializarPractica(); break;
      case '2': practica=2; cout<<"Elegida pŕactica 2"<<endl; mostrarMenu(); inicializarPractica(); break;
      case '3': practica=3; cout<<"Elegida pŕactica 3"<<endl; mostrarMenu(); inicializarPractica(); break;
      case '4': practica=4; cout<<"Elegida pŕactica 4"<<endl; mostrarMenu(); inicializarPractica(); break;
      case '5': practica=5; cout<<"Elegida pŕactica 5"<<endl; mostrarMenu(); inicializarPractica(); break;

      //Opciones comunes a todas las prácaracteristicas:
      case 'L': modo = GL_LINE; ajedrez = false; break;
      case 'F': modo = GL_FILL; ajedrez = false; break;
      case 'P': modo = GL_POINT; ajedrez = false; break;
      //case 'A': ajedrez = true; modo = GL_FILL; break;
   }

   //Opciones de la práctica 1:
   if (practica==1){
      switch (toupper(Tecla1)) {
         case 'T': obj3D = tetraedro; break;
         case 'C': obj3D = cubo; break;
         case 'O': obj3D = octaedro; break;
      }
   }

   //Opeciones de la práctia 2:
   else if (practica==2){
      switch (toupper(Tecla1)) {
         //Ply
         case 'Y': objPly.leerPLY(objPly.leerObjeto()); objPly.createGeometry(true) ;obj3D = objPly; break;
         //objeto revolución
         case 'R': objRevolucion.leerPLY(objRevolucion.leerObjeto()) ;
                     rev = objRevolucion.leerObjetoRev();
                     objRevolucion.createGeometry(rev,tapa,base,true) ;
                     obj3D = objRevolucion; break;
         //cambiar revoluciones del objeto revolución
         case 'X': rev = objRevolucion.leerObjetoRev();
                     objRevolucion.createGeometry(rev,tapa,base,true) ;
                     obj3D = objRevolucion; break;
         //mostrar/ocultar base
         case 'B': base = !base; objRevolucion.createGeometry(rev,tapa,base,true) ;
                     obj3D = objRevolucion; break;
         //mostrar/ocultar tapa
         case 'V': tapa = !tapa; objRevolucion.createGeometry(rev,tapa,base,true) ;
                     obj3D = objRevolucion; break;
      }
   }

   else if (practica==3){
      switch (toupper(Tecla1)) {
         case 'W': movil.setRotarTodo(); break;
         case 'E': movil.setRotarFigura(); break;
         case 'R': movil.setMoverFigura(); break;
         case 'T': movil.setBalanceo(); break;
         case 'Y': animacion=!animacion; break;
         case 'U': movil.setEscalarAvion(); break;
      }

      switch (Tecla1) {
          case 'M': cambiarVelocidadRMovil(5); break;
          case 'm': cambiarVelocidadRMovil(-5); break;
          case 'N': cambiarVelocidadRFigura(5); break;
          case 'n': cambiarVelocidadRFigura(-5); break;
          case 'B': cambiarVelocidadMFigura(5); break;
          case 'b': cambiarVelocidadMFigura(-5); break;
          case 'V': cambiarVelocidadBalanceo(5); break;
          case 'v': cambiarVelocidadBalanceo(-5); break;
      }
   }

   else if (practica==5){
      switch (toupper(Tecla1)) {
         case 'W':
            /*if (camaraActiva==0) camaras[camaraActiva].moverEye(0,0,-1);
            else if (camaraActiva==1) camaras[camaraActiva].moverEye(0,-1,0);
            else if (camaraActiva==2) camaras[camaraActiva].moverEye(-1,0,0);*/
            camaras[camaraActiva].avanzar(2);
         break;
         case 'A':
            /*if (camaraActiva==0) camaras[camaraActiva].moverEye(-1,0,0);
            else if (camaraActiva==1) camaras[camaraActiva].moverEye(-1,0,0);
            else if (camaraActiva==2) camaras[camaraActiva].moverEye(0,0,1);*/
            camaras[camaraActiva].movLateral(5);
         break;
         case 'S':
            /*if (camaraActiva==0) camaras[camaraActiva].moverEye(0,0,1);
            else if (camaraActiva==1) camaras[camaraActiva].moverEye(0,1,0);
            else if (camaraActiva==2) camaras[camaraActiva].moverEye(1,0,0);*/
            camaras[camaraActiva].avanzar(-2);
         break;
         case 'D':
            /*if (camaraActiva==0) camaras[camaraActiva].moverEye(1,0,0);
            else if (camaraActiva==1) camaras[camaraActiva].moverEye(1,0,0);
            else if (camaraActiva==2) camaras[camaraActiva].moverEye(0,0,-1);*/
            camaras[camaraActiva].movLateral(-5);;
         break;
         case 'R':
            if (camaraActiva==0){
               camaras[camaraActiva].setPositionEye(0,0,200);
               camaras[camaraActiva].setPositionAt(0,0,0);
               camaras[camaraActiva].setPositionUp(0,1,0);
            }
            else if (camaraActiva==1){
               camaras[camaraActiva].setPositionEye(0,200,0);
               camaras[camaraActiva].setPositionAt(0,0,0);
               camaras[camaraActiva].setPositionUp(0,0,-1);
            }
            else if (camaraActiva==2){
               camaras[camaraActiva].setPositionEye(200,0,0);
               camaras[camaraActiva].setPositionAt(0,0,0);
               camaras[camaraActiva].setPositionUp(0,1,0);
            }
         break;
      }
   }

  return 0;
}

void Escena::inicializarPractica(){
   if (practica==1){
      obj3D=cubo;
   }

   else if (practica==2){
      objPly.leerPLY("beethoven");
      objPly.createGeometry(true);
      obj3D = objPly;
      rev=20;
      objRevolucion.leerPLY("peon");
      objRevolucion.createGeometry(rev,tapa,base,true);
   }else if (practica==5){
      objPly.leerPLY("eg07"); objPly.createGeometry(true) ;
      peon.leerPLY("peon");
      peon.createGeometry(20,true,true,false);
   }

}

void Escena::mostrarMenu(){
   cout<< "Opciones: " <<endl;
	cout<< "1: Práctica 1" <<endl;
	cout<< "2: Práctica 2" <<endl;
	cout<< "3: Práctica 3" <<endl;
	cout<< "4: Práctica 4" <<endl;
   cout<< "5: Práctica 5" <<endl;
	cout<< "q: salir" <<endl;


   if (practica==1){
      cout<<endl<< "Opciones de la práctica 1: " <<endl;
   	cout<< "p: dibujar puntos" <<endl;
   	cout<< "l: dibujar lineas" <<endl;
   	cout<< "f: dibujar sólido" <<endl;
   	cout<< "a: dibujar ajedrez" <<endl;
      cout<< "t: dibujar tetraedro" <<endl;
      cout<< "c: dibujar cubo" <<endl;
      cout<< "o: dibujar octaedro" <<endl;
   }

   else if (practica==2){
      cout<<endl<< "Opciones de la práctica 2: " <<endl;
   	cout<< "p: dibujar puntos" <<endl;
   	cout<< "l: dibujar lineas" <<endl;
   	cout<< "f: dibujar sólido" <<endl;
   	cout<< "a: dibujar ajedrez" <<endl;
      cout<< "y: dibujar objeto PLY" <<endl;
      cout<< "r: dibujar objeto Revolución" <<endl;
      cout<< "x: cambiar revoluciones del objeto por revolución" <<endl;
      cout<< "b: mostrar/ocultar la base del objeto" <<endl;
      cout<< "v: mostrar/ocultar la tapa del objeto" <<endl;
   }

   else if (practica==3){
      cout<<endl<< "Opciones de la práctica 3: " <<endl;
   	cout<< "p: dibujar puntos" <<endl;
   	cout<< "l: dibujar lineas" <<endl;
   	cout<< "f: dibujar sólido" <<endl;
   	cout<< "a: dibujar ajedrez" <<endl;
   	cout<< "w: Rotar todo" <<endl;
   	cout<< "e: Rotar figura" <<endl;
   	cout<< "r: Mover figura" <<endl;
   	cout<< "t: Balanceo" <<endl;
   	cout<< "y: Animar" <<endl;
      cout<< "u: prueba3 - escalar el avión"<<endl;
   	cout<< "V/v: Aumentar/disminuir balanceo" <<endl;
   	cout<< "B/b: Aumentar/disminuir movimiento de la figura" <<endl;
   	cout<< "N/n: Aumentar/disminuir rotación de la figura" <<endl;
   	cout<< "M/m: Aumentar/disminuir rotación" <<endl;
   }

   else if (practica==5){
      cout<<endl<< "Opciones de la práctica 5: " <<endl;
   	cout<< "F1: activar camara1 con vista frente" <<endl;
   	cout<< "F2: activar camara2 con vista alzado" <<endl;
   	cout<< "F3: activar camara3 con vista perfil ortogonal" <<endl;
      cout<< "W: avanzar" <<endl;
   	cout<< "S: retroceder" <<endl;
   	cout<< "A: desplazamiento a la izquierda" <<endl;
      cout<< "D: desplazamiento a la derecha:" <<endl;
      cout<< "R: reiniciar posición" <<endl;
   }
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
   if (practica==5){
      switch (Tecla1) {
         case GLUT_KEY_F1: camaraActiva=0;break;
         case GLUT_KEY_F2: camaraActiva=1;break;
         case GLUT_KEY_F3: camaraActiva=2;break;
      }
   }

	std::cout << Observer_distance << std::endl;
}


//**************************************************************************
// Funcion para definir la transformaci�n de proyeccion
//***************************************************************************

void Escena::change_projection()  {
   if (practica==5){
      camaras[camaraActiva].setProyeccion();
   }else{
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
   }
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
   if (practica==5){
      camaras[camaraActiva].setLookAt();
   }else{
      glTranslatef(0,0,-Observer_distance);
      glRotatef(Observer_angle_x,1,0,0);
      glRotatef(Observer_angle_y,0,1,0);
   }
}


//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void Escena::draw_axis()
{
ejes.draw();
}


//**************************************************************************
// Funcion para animar el objeto jerárquico
//***************************************************************************

void Escena::animar(){
   if (animacion){
      if (anima1>velocidadRMovil){
         movil.setRotarTodo();
         anima1=0;
      }
      anima1++;
      if (anima2>velocidadRFigura){
         movil.setRotarFigura();
         anima2=0;
      }
      anima2++;
      if (anima3>velocidadMFigura){
         movil.setMoverFigura();
         anima3=0;
      }
      anima3++;
      if (anima4>velocidadBalanceo){
         movil.setBalanceo();
         anima4=0;
      }
      anima4++;
   }
}

//**************************************************************************
// Funcion que controla los eventos producidos por el movimiento raton
//***************************************************************************

void Escena::ratonMovido(int x,int y){
   if(estadoRaton == MOVIENDO_CAMARA_FIRSTPERSON){
      camaras[camaraActiva].giroHoriz(xant-x);
      camaras[camaraActiva].giroVert(yant-y);
   }else if(estadoRaton == MODO_EXAMINAR){


   }
   xant = x;
   yant = y;

}

//**************************************************************************
// Funcion que controla los eventos producidos por el raton
//***************************************************************************

void Escena::clickRaton(int boton,int estado,int x,int y){
   if(boton == GLUT_RIGHT_BUTTON){
      cout << "Click derecho ";
      if(estado == GLUT_DOWN){  // Se pulsa el botón, por lo que se entra en el estado "moviendo camara"
         cout <<"pulsado"<< endl;
         xant = x;
         yant = y;
         if(estadoRaton == -1)
            estadoRaton = 0;
      }else{ // Se levanta el botón, por lo que se sale del estado "moviendo camara"
         cout <<"soltado"<< endl;
         if(estadoRaton == 0)
            estadoRaton = -1;
      }
   }else if(boton == GLUT_LEFT_BUTTON){
      cout << "Click izquierdo ";
      if(estado == GLUT_DOWN){  // Se pulsa el botón
         if(estadoRaton != 1){
            dibujaSeleccion();
            objetoSeleccionado=pick(x,y);
         }
         cout <<"pulsado"<< endl;
      }else if(objetoSeleccionado){
         xant = x;
         yant = y;
         estadoRaton = (estadoRaton==1)?-1:1;  // Si estaba activado lo desactivo y si no estaba activado lo activo
      }
   }
}


void Escena::dibujaSeleccion(){
   glDisable(GL_DITHER); // deshabilitar degradado
   glDisable(GL_LIGHTING);
   glDisable(GL_TEXTURE);

   glPushMatrix();
   //glColor3f(1,0,0);
   lata2.asignarColor(1,0,0);
   lata2.draw(GL_FRONT, GL_FILL, false);
   glPushMatrix();
      glTranslatef(-130,20,0);
      //glColor3f(0,1,0);
      objPly2.asignarColor(0,1,0);
      objPly2.draw(GL_FRONT, GL_FILL, false);
   glPopMatrix();
   glPushMatrix();
   glScalef(2,2,2);
      glPushMatrix();
         glScalef(10,10,10);
         glTranslatef(3.5,1.4,-3);
         //glColor3f(0,0,1);
         peon2.asignarColor(0,0,1);
         peon2.draw(GL_FRONT,GL_FILL,false);
         glTranslatef(0,0,3);
         //glColor3f(1,1,0);
         peon2.asignarColor(1,1,0);
         peon2.draw(GL_FRONT,GL_FILL,false);
         glTranslatef(0,0,3);
         //glColor3f(0,1,1);
         peon2.asignarColor(0,1,1);
         peon2.draw(GL_FRONT,GL_FILL,false);
      glPopMatrix();
   glPopMatrix();

   glPopMatrix();
   glEnable(GL_DITHER);
   //glEnable(GL_LIGHTING);
   //glEnable(GL_TEXTURE);
}

bool Escena::pick(int x,int y){
   bool objeto= false;
   GLint viewport[4];
   GLfloat pixel[3];
   Tupla3r centro;
   glGetIntegerv(GL_VIEWPORT,viewport);
   glReadPixels(x,viewport[3]-y,1,1,GL_RGB,GL_FLOAT,(void *) pixel);
   cout<<pixel[0]<<" "<<pixel[1]<<" "<<pixel[2]<<endl;
   if(pixel[0]==1 && pixel[1]==0 && pixel[2]==0){  // lata
      //centro = lata.getCentro();
      cout<<"Seleccionada lata"<<endl;
      objeto=true;
   } else if (pixel[0]==0 && pixel[1]==1 && pixel[2]==0){ //objPly
      cout<<"Seleccionado objeto ply"<<endl;
      objeto=true;
   } else if (pixel[0]==0 && pixel[1]==0 && pixel[2]==1){ //peon
      cout<<"Seleccionado peon derecha"<<endl;
      objeto=true;
   }else if (pixel[0]==1 && pixel[1]==1 && pixel[2]==0){ //peon
      cout<<"Seleccionado peon centro"<<endl;
      objeto=true;
   }else if (pixel[0]==0 && pixel[1]==1 && pixel[2]==1){ //peon
      cout<<"Seleccionado peon izquierda"<<endl;
      objeto=true;
   }
   return objeto;
}


void Escena::cambiarVelocidadRFigura(int vel){
   velocidadRFigura += vel;
}

void Escena::cambiarVelocidadMFigura(int vel){
   velocidadMFigura += vel;
}

void Escena::cambiarVelocidadBalanceo(int vel){
   velocidadBalanceo += vel;
}

void Escena::cambiarVelocidadRMovil(int vel){
   velocidadRMovil += vel;
}
