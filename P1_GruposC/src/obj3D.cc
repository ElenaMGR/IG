#ifdef _WIN32
#include <windows.h>
#endif

#include "obj3D.h"

void Obj3D::draw (GLenum face, GLenum mode, bool ajedrez){
   glEnableClientState(GL_COLOR_ARRAY);
   glEnableClientState(GL_VERTEX_ARRAY);
   glColorPointer(3, GL_FLOAT, 0, &(mesh.color[0]));
   glVertexPointer (3, GL_FLOAT, 0, &(mesh.vertices[0]));
   glPolygonMode(face, mode);
   if (!ajedrez){
      glDrawElements (GL_TRIANGLES, mesh.triangulos.size(),GL_UNSIGNED_INT, &(mesh.triangulos[0]));
      /*if (mode == GL_FILL ){
         glPolygonMode(face, GL_LINE);
         glColorPointer(3, GL_FLOAT, 0, &(mesh.colorLineas[0]));
         glDrawElements (GL_TRIANGLES, mesh.triangulos.size(),GL_UNSIGNED_INT, &(mesh.triangulos[0]));
      }*/

   }else{
      glDrawElements (GL_TRIANGLES, mesh.carasImpares.size(), GL_UNSIGNED_INT, &(mesh.carasImpares[0]));
      glColorPointer(3, GL_FLOAT, 0, &(mesh.colorPares[0]));
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
   generarNormalesCaras();
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
   mesh.color.clear();
   for (int i=0; i<mesh.vertices.size(); i+=3){
      mesh.color.push_back(r);
      mesh.color.push_back(g);
      mesh.color.push_back(b);
   }
   mesh.colorLineas.clear();
   for (int i=0; i<mesh.vertices.size(); i+=3){
      mesh.colorLineas.push_back(0);
      mesh.colorLineas.push_back(1);
      mesh.colorLineas.push_back(0);
   }
}

void Obj3D::asignarColorCarasPares(float r, float g, float b){
   mesh.colorPares.clear();
   for (int i=0; i<mesh.carasPares.size(); i+=3){
      mesh.colorPares.push_back(r);
      mesh.colorPares.push_back(g);
      mesh.colorPares.push_back(b);
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

   // Centro en el origen
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

void Obj3D::generarNormalesCaras(){
   mesh.normalesCaras.clear();
   // Variables donde guardar los vectores dirección a y b
   float ax,ay,az,bx,by,bz;
   //Variables de la normal
   float nx,ny,nz;
   //Calculo los vectores a y b
   for (int i=0; i<mesh.triangulos.size(); i+=3){
      ax=mesh.vertices[mesh.triangulos[i]] - mesh.vertices[(mesh.triangulos[i+1])*3];
      ay=mesh.vertices[mesh.triangulos[i]+1] - mesh.vertices[(mesh.triangulos[i+1])*3+1];
      az=mesh.vertices[mesh.triangulos[i]+2] - mesh.vertices[(mesh.triangulos[i+1])*3+2];

      bx=mesh.vertices[mesh.triangulos[i+2]] - mesh.vertices[(mesh.triangulos[i+1])*3];
      by=mesh.vertices[mesh.triangulos[i+2]+1] - mesh.vertices[(mesh.triangulos[i+1])*3+1];
      bz=mesh.vertices[mesh.triangulos[i+2]+2] - mesh.vertices[(mesh.triangulos[i+1])*3+2];

      //Normalizo antes de hacer el producto a x b para evitar posibles errores
      normalizar(ax,ay,az);
      normalizar(bx,by,bz);

      //Cáculo la normal de a y b
      nx = ay*bz - az*by;
      ny = az*bx - ax*bz;
      nz = ax*by - ay*bz;

      //Normalizamos las normales
      normalizar(nx,ny,nz);

      //Guardo las normales de cara
      mesh.normalesCaras.push_back(nx);
      mesh.normalesCaras.push_back(ny);
      mesh.normalesCaras.push_back(nz);
   }

}

void Obj3D::normalizar(float & x, float & y, float & z){
   float aux = sqrt(x*x+y*y+z*z);

   x = x / aux;
   y = y / aux;
   z = z / aux;
}

void Obj3D::generarNormalesVertices(){

}
