#ifdef _WIN32
#include <windows.h>
#endif

#include "obj3D.h"

void Obj3D::draw (GLenum face, GLenum mode, bool ajedrez){
   glEnableClientState(GL_COLOR_ARRAY);
   glEnableClientState(GL_VERTEX_ARRAY);
   glColorPointer(3, GL_FLOAT, 0, &(color[0]));
   glVertexPointer (3, GL_FLOAT, 0, &(mesh.vertices[0]));
   glPolygonMode(face, mode);
   if (!ajedrez){
      //glColor3f(0.0f, 0.0f, 0.0f);
      glDrawElements (GL_TRIANGLES, mesh.triangulos.size(),GL_UNSIGNED_INT, &(mesh.triangulos[0]));
   }else{
      //glColor3f(0.0f, 0.0f, 0.0f);
      glDrawElements (GL_TRIANGLES, mesh.carasImpares.size(), GL_UNSIGNED_INT, &(mesh.carasImpares[0]));
      //glColor3f(1.0f, 0.0f, 1.0f);
      glColorPointer(3, GL_FLOAT, 0, &(colorPares[0]));
      glDrawElements (GL_TRIANGLES, mesh.carasPares.size(), GL_UNSIGNED_INT, &(mesh.carasPares[0]));
   }
}

void Obj3D::setMalla(vector<GLfloat> v, vector<GLuint> t){
   mesh.vertices = v;
   mesh.triangulos = t;
   mesh.carasPares = getCarasPares(true);
   mesh.carasImpares = getCarasPares(false);
   asignarColor(0.0,0.0,0.0);
   asignarColorCarasPares(1.0, 0.0, 1.0);
   centrarEscalar();
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


void Obj3D::asignarColor(float r, float g, float b){
   color.clear();
   for (int i=0; i<mesh.vertices.size(); i+=3){
      color.push_back(r);
      color.push_back(g);
      color.push_back(b);
   }
}

void Obj3D::asignarColorCarasPares(float r, float g, float b){
   colorPares.clear();
   for (int i=0; i<mesh.carasPares.size(); i+=3){
      colorPares.push_back(r);
      colorPares.push_back(g);
      colorPares.push_back(b);
   }
}

void Obj3D::centrarEscalar(){
   float cx,cy,cz;
   //Asingo por defecto el valor del primer vertice
   float minx = mesh.vertices[0] ,maxx = mesh.vertices[0];
   float miny = mesh.vertices[1], maxy = mesh.vertices[1];
   float minz = mesh.vertices[2], maxz = mesh.vertices[2];
   //Calculo el cubo envolvente
   for (int i=0; i<mesh.vertices.size(); i+=3){
      if (mesh.vertices[i] < minx)
         minx=mesh.vertices[i];
      if (mesh.vertices[i] > maxx)
         maxx=mesh.vertices[i];
      if (mesh.vertices[i+1] < miny)
         miny=mesh.vertices[i+1];
      if (mesh.vertices[i+1] > maxy)
         maxy=mesh.vertices[i+1];
      if (mesh.vertices[i+2] < minz)
         minz=mesh.vertices[i+2];
      if (mesh.vertices[i+2] > maxz)
         maxz=mesh.vertices[i+2];
   }
   //Calculo el centro del cubo
   cx=(minx+maxx)/2;
   cy=(miny+maxy)/2;
   cz=(minz+maxz)/2;


   for (int i=0; i<mesh.vertices.size(); i+=3){
      mesh.vertices[i]=mesh.vertices[i]-cx;
      mesh.vertices[i+1]=mesh.vertices[i+1]-cy;
      mesh.vertices[i+2]=mesh.vertices[i+2]-cz;
   }

   //Calculamos el escalado
   for (int i=0; i<mesh.vertices.size(); i++){
      mesh.vertices[i]=mesh.vertices[i]*(90/(maxx-minx));
   }

}
