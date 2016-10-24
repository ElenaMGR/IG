#ifdef _WIN32
#include <windows.h>
#endif

#include "obj3D.h"

void Obj3D::draw (GLenum face, GLenum mode, bool ajedrez){
   glEnableClientState(GL_COLOR_ARRAY);
   glEnableClientState(GL_VERTEX_ARRAY);
   glVertexPointer (3, GL_FLOAT, 0, &(mesh.vertices[0]));
   glPolygonMode(face, mode);
   if (!ajedrez){
      glColor3f(0.0f, 0.0f, 0.0f);
      glDrawElements (GL_TRIANGLES, mesh.triangulos.size(),GL_UNSIGNED_INT, &(mesh.triangulos[0]));
   }else{
      glColor3f(1.0f, 0.0f, 1.0f);
      glDrawElements (GL_TRIANGLES, mesh.carasPares.size(), GL_UNSIGNED_INT, &(mesh.carasPares[0]));
      glColor3f(0.0f, 0.0f, 0.0f);
      glDrawElements (GL_TRIANGLES, mesh.carasImpares.size(), GL_UNSIGNED_INT, &(mesh.carasImpares[0]));
   }
}

void Obj3D::setMalla(vector<GLfloat> v, vector<GLuint> t){
   mesh.vertices = v;
   mesh.triangulos = t;
   mesh.carasPares = getCarasPares(true);
   mesh.carasImpares = getCarasPares(false);
}


vector<GLuint> Obj3D::getCarasPares (bool par){
   vector<GLuint> caras;

   for( int i=(par)?0:3 ; i<mesh.triangulos.size(); i+=6){
      caras.push_back(mesh.triangulos[i]);
      caras.push_back(mesh.triangulos[i+1]);
      caras.push_back(mesh.triangulos[i+2]);
   }
   return caras;
}

void Obj3D::moverObjeto (){
   for (int i=0; i<mesh.vertices.size(); i++){
      mesh.vertices[i]=mesh.vertices[i]+35;
   }
}
