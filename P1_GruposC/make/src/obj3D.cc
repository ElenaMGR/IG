#ifdef _WIN32
#include <windows.h>
#endif

#include "obj3D.h"

void Obj3D::draw (){
      glEnableClientState(GL_VERTEX_ARRAY);
      glVertexPointer (3, GL_FLOAT, 0, &(getMalla().vertices[0]));
      glDrawElements (GL_TRIANGLES, getMalla().triangulos.size(),GL_UNSIGNED_INT, &(getMalla().triangulos[0]));
}

Malla Obj3D::getMalla(){
   return mesh;
}

void Obj3D::setMalla(vector<GLfloat> v, vector<GLuint> t){
   mesh.vertices = v;
   mesh.triangulos = t;
}
