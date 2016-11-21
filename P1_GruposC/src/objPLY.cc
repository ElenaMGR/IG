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

void ObjPLY::createGeometry(bool escalado){
   vector<GLfloat> vertices;
   for (int i=0; i<v.size();i++){
      vertices.push_back(v[i]);
   }

   vector<GLuint> triangulos;
   for (int i=0; i<t.size();i++){
      triangulos.push_back(t[i]);
   }

   Obj3D::setMalla(vertices,triangulos);
   if (escalado)
      centrarEscalar();
}

string ObjPLY::leerObjeto(){
   string input;
   cout<<"Introduce nombre de objeto PLY: "<<endl;
   getline(std::cin, input);
   return input;
}
