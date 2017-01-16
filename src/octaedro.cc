#ifdef _WIN32
#include <windows.h>
#endif

#include "octaedro.h"

Octaedro::Octaedro(){
   // geometria del octaedro
   vector<GLfloat> vertices;

   // vertice 0
   vertices.push_back(50);
   vertices.push_back(0);
   vertices.push_back(0);
   // vertice 1
   vertices.push_back(-50);
   vertices.push_back(0);
   vertices.push_back(0);
   // vertice 2
   vertices.push_back(0);
   vertices.push_back(50);
   vertices.push_back(0);
   // vertice 3
   vertices.push_back(0);
   vertices.push_back(-50);
   vertices.push_back(0);
   // vertice 4
   vertices.push_back(0);
   vertices.push_back(0);
   vertices.push_back(50);
   // vertice 5
   vertices.push_back(0);
   vertices.push_back(0);
   vertices.push_back(-50);

   vector<GLuint> triangulos;
   //Caras arriba
   // cara 1 fondo
   triangulos.push_back(2);
   triangulos.push_back(5);
   triangulos.push_back(1);
   // cara 2 izquierda
   triangulos.push_back(2);
   triangulos.push_back(1);
   triangulos.push_back(4);
   // cara 3 centro
   triangulos.push_back(2);
   triangulos.push_back(4);
   triangulos.push_back(0);
   // cara 4 derecha
   triangulos.push_back(2);
   triangulos.push_back(0);
   triangulos.push_back(5);

   //Caras abajo
   // cara 1 izquierda
   triangulos.push_back(4);
   triangulos.push_back(1);
   triangulos.push_back(3);
   // cara 2 centro
   triangulos.push_back(4);
   triangulos.push_back(3);
   triangulos.push_back(0);
   // cara 3 derecha
   triangulos.push_back(0);
   triangulos.push_back(3);
   triangulos.push_back(5);
   // cara 4 fondo
   triangulos.push_back(1);
   triangulos.push_back(5);
   triangulos.push_back(3);

   Obj3D::setMalla(vertices,triangulos);
}
