#ifdef _WIN32
#include <windows.h>
#endif

#include "obj3D.h"
#include <iostream>

void Obj3D::draw (GLenum face, GLenum mode, bool ajedrez){
   glEnableClientState(GL_VERTEX_ARRAY);
   glVertexPointer (3, GL_FLOAT, 0, &(mesh.vertices[0]));
   glPolygonMode(face, mode);
   if (!ajedrez){
      glColor3f(0.0f, 0.0f, 0.0f);
      glDrawElements (GL_TRIANGLES, 3*mesh.num_tri,GL_UNSIGNED_INT, &(mesh.triangulos[0]));
   }else{
      vector<GLuint> carasPares = getCarasPares(true);
      vector<GLuint> carasImpares = getCarasPares(false);
      glColor3f(1.0f, 0.0f, 1.0f);
      glDrawElements (GL_TRIANGLES, (3*mesh.num_tri)/2, GL_UNSIGNED_INT, &(carasPares[0]));
      glColor3f(0.0f, 0.0f, 0.0f);
      glDrawElements (GL_TRIANGLES, (3*mesh.num_tri)/2, GL_UNSIGNED_INT, &(carasImpares[0]));

      //cout << "Caras pares: "<< (3*mesh.num_tri)/2<< " - "<<carasPares.size()<<endl;
      //cout << "Caras impares: "<< (3*mesh.num_tri)/2<< " - "<<carasImpares.size()<<endl;
   }
   glDisableClientState(GL_VERTEX_ARRAY);
}

void Obj3D::setMalla(vector<GLfloat> v, vector<GLuint> t){
   mesh.vertices = v;
   mesh.triangulos = t;
   calculaNumVer();
   calculaNumTri();
}

void Obj3D::calculaNumVer(){
   mesh.num_ver = (mesh.vertices.size()) / 3;
}
void Obj3D::calculaNumTri(){
   mesh.num_tri = (mesh.triangulos.size()) / 3;
}

vector<GLuint> Obj3D::getCarasPares (bool par){
   vector<GLuint> caras;

   for( int i=(par)?0:3 ; i<mesh.triangulos.size(); i+=6){
      caras.push_back(mesh.triangulos[i]);
      caras.push_back(mesh.triangulos[i+1]);
      caras.push_back(mesh.triangulos[i+2]);
   }
   /*for (int i= 0 ; i<caras.size(); i++){
      cout<<caras[i]<< endl;
   }*/

   return caras;
}
