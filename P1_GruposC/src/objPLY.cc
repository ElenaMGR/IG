#ifdef _WIN32
#include <windows.h>
#endif

#include "objPLY.h"


ObjPLY::ObjPLY(){
   leerPLY();
}

void ObjPLY::leerPLY(){
   _file_ply filePly;
   filePly.open("./PLY/beethoven.ply");
   vector<float> v;
   vector<int> t;
   filePly.read(v,t);

   vector<GLfloat> vertices;
   for (int i=0; i<v.size();i++){
      vertices.push_back(v[i]);
   }
   
   vector<GLuint> triangulos;
   for (int i=0; i<t.size();i++){
      triangulos.push_back(t[i]);
   }

   Obj3D::setMalla(vertices,triangulos);
}
