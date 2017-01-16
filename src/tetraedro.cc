#ifdef _WIN32
#include <windows.h>
#endif

#include "tetraedro.h"

Tetraedro::Tetraedro(){
   // geometria del tetraedro
   vector<GLfloat> vertices;

   // vertice 0
   vertices.push_back(40);
   vertices.push_back(40);
   vertices.push_back(40);
   // vertice 1
   vertices.push_back(40);
   vertices.push_back(-40);
   vertices.push_back(-40);
   // vertice 2
   vertices.push_back(-40);
   vertices.push_back(40);
   vertices.push_back(-40);
   // vertice 3
   vertices.push_back(-40);
   vertices.push_back(-40);
   vertices.push_back(40);

   vector<GLuint> triangulos;
   // cara 1 fondo
   triangulos.push_back(3);
   triangulos.push_back(2);
   triangulos.push_back(1);
   // cara 2 izquierda
   triangulos.push_back(0);
   triangulos.push_back(2);
   triangulos.push_back(3);
   // cara 3 derecha
   triangulos.push_back(2);
   triangulos.push_back(0);
   triangulos.push_back(1);
   // cara 4 base
   triangulos.push_back(0);
   triangulos.push_back(3);
   triangulos.push_back(1);

   Obj3D::setMalla(vertices,triangulos);
}
