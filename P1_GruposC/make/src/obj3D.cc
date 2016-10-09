#ifdef _WIN32
#include <windows.h>
#endif

#include "obj3D.h"
#include <iostream>

void Obj3D::draw (GLenum face, GLenum mode){
      glColor3f(0.0f, 0.0f, 0.0f);
      glEnableClientState(GL_VERTEX_ARRAY);
      glVertexPointer (3, GL_FLOAT, 0, &(getMalla().vertices[0]));
      glPolygonMode(face, mode);
      glDrawElements (GL_TRIANGLES, 3*getMalla().num_tri,GL_UNSIGNED_INT, &(getMalla().triangulos[0]));
}

Malla Obj3D::getMalla(){
   return mesh;
}

void Obj3D::setMalla(vector<GLfloat> v, vector<GLuint> t){
   mesh.vertices = v;
   mesh.triangulos = t;
   calculaNumVer();
   calculaNumTri();
}

void Obj3D::calculaNumVer(){
   mesh.num_ver = (getMalla().vertices.size()) / 3;
}
void Obj3D::calculaNumTri(){
   mesh.num_tri = (getMalla().triangulos.size()) / 3;
}
