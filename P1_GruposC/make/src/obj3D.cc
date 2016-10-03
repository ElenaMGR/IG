#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include "obj3D.h"


void Obj3D::draw (Malla *mesh){
      glEnableClienteState (GL_VERTEX_ARRAY);
      glVertexPointer (3, GL_FLOAT, 0, mesh->vertices);
      glDrawElements (GL_TRIANGLES, 3*mesh->num_tri,GL_UNSIGNED_INT, mesh->triangulos);
}
