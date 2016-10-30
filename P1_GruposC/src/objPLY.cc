#ifdef _WIN32
#include <windows.h>
#endif

#include "objPLY.h"


ObjPLY::ObjPLY(){
}

void ObjPLY::leerPLY(string nombre){
   _file_ply filePly;
   string nomply = "./PLY/"+nombre+".ply";
   filePly.open(nomply.c_str());
   filePly.read(v,t);
}

void ObjPLY::createGeometry(){
   vector<GLfloat> vertices;
   for (int i=0; i<v.size();i++){
      vertices.push_back(v[i]);
   }

   vector<GLuint> triangulos;
   for (int i=0; i<t.size();i++){
      triangulos.push_back(t[i]);
   }

   Obj3D::setMalla(vertices,triangulos);
   centrarEscalar();
}
