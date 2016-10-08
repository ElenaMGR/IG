#ifdef _WIN32
#include <windows.h>
#endif

#include "tetraedro.h"

Tetraedro::Tetraedro(){
   // geometria del tetraedro
   vector<GLfloat> vertices;
   // vertice 0
   vertices.push_back(0);
   vertices.push_back(0);
   vertices.push_back(0);
   // vertice 1
   vertices.push_back(20);
   vertices.push_back(0);
   vertices.push_back(40);
   // vertice 2
   vertices.push_back(40);
   vertices.push_back(0);
   vertices.push_back(0);
   // vertice 3
   vertices.push_back(20);
   vertices.push_back(40);
   vertices.push_back(20);

   vector<GLuint> triangulos;
   // cara 1
   triangulos.push_back(0);
   triangulos.push_back(2);
   triangulos.push_back(1);
   // cara 2
   triangulos.push_back(0);
   triangulos.push_back(3);
   triangulos.push_back(2);
   // cara 3
   triangulos.push_back(3);
   triangulos.push_back(1);
   triangulos.push_back(2);
   // cara 4
   triangulos.push_back(3);
   triangulos.push_back(0);
   triangulos.push_back(1);

   Obj3D::setMalla(vertices,triangulos);
}

void Tetraedro::draw(GLenum face, GLenum mode){
   glColor3f(1.0f, 0.0f, 0.0f);
   Obj3D::draw(face, mode);
}
