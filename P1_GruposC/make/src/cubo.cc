#ifdef _WIN32
#include <windows.h>
#endif

#include "cubo.h"

Cubo::Cubo(){
   // geometria del tetraedro
   vector<GLfloat> vertices;
   // vertice 0 - abajo fondo izquierdo
   vertices.push_back(-30);
   vertices.push_back(-30);
   vertices.push_back(-30);
   // vertice 1 abajo fondo derecho
   vertices.push_back(30);
   vertices.push_back(-30);
   vertices.push_back(-30);
   // vertice 2 abajo izquierdo
   vertices.push_back(-30);
   vertices.push_back(-30);
   vertices.push_back(30);
   // vertice 3 abajo derecho
   vertices.push_back(30);
   vertices.push_back(-30);
   vertices.push_back(30);
   // vertice 4 arriba fondo izquierdo
   vertices.push_back(-30);
   vertices.push_back(30);
   vertices.push_back(-30);
   // vertice 5 arriba fondo derecho
   vertices.push_back(30);
   vertices.push_back(30);
   vertices.push_back(-30);
   // vertice 6 arriba izquierdo
   vertices.push_back(-30);
   vertices.push_back(30);
   vertices.push_back(30);
   // vertice 7 arriba derecho
   vertices.push_back(30);
   vertices.push_back(30);
   vertices.push_back(30);

   vector<GLuint> triangulos;
   // cara 1 delante
   triangulos.push_back(6);
   triangulos.push_back(2);
   triangulos.push_back(3);

   triangulos.push_back(6);
   triangulos.push_back(3);
   triangulos.push_back(7);
   // cara 2 izquierda
   triangulos.push_back(2);
   triangulos.push_back(4);
   triangulos.push_back(0);

   triangulos.push_back(2);
   triangulos.push_back(6);
   triangulos.push_back(4);
   // cara 3 derecha
   triangulos.push_back(7);
   triangulos.push_back(3);
   triangulos.push_back(1);

   triangulos.push_back(7);
   triangulos.push_back(1);
   triangulos.push_back(5);
   // cara 4 detras
   triangulos.push_back(0);
   triangulos.push_back(5);
   triangulos.push_back(1);

   triangulos.push_back(4);
   triangulos.push_back(5);
   triangulos.push_back(0);
   // cara 5 abajo
   triangulos.push_back(2);
   triangulos.push_back(0);
   triangulos.push_back(1);

   triangulos.push_back(2);
   triangulos.push_back(1);
   triangulos.push_back(3);
   // cara 6 arriba
   triangulos.push_back(4);
   triangulos.push_back(6);
   triangulos.push_back(7);

   triangulos.push_back(4);
   triangulos.push_back(7);
   triangulos.push_back(5);

   Obj3D::setMalla(vertices,triangulos);
   //moverObjeto();
}
