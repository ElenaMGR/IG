#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>
#include "objRevolucion.h"

ObjRevolucion::ObjRevolucion(){
}

ObjRevolucion::ObjRevolucion(vector<float> vec){
   v=vec;
}

void ObjRevolucion::createGeometry(int repeticiones, bool tapa, bool base, bool escalado){
   vector<GLfloat> vertices;
   vector<GLuint> triangulos;
   double angulo = (2.0 * M_PI) / repeticiones;
   vector<float> vaux = v;
   float puntobase;
   float puntotapa;

   //Base
   //Si hay base la borro y la guardo en variable
   if( (v[0] == 0) && v[2] == 0){
      puntobase = v[1];
      vaux.erase(vaux.begin(), vaux.begin()+3);
   }

   //Tapa
   //Si hay tapa la borro y la guardo en variable
   if( (v[v.size()-3] == 0) && v[v.size()-1] == 0){
      puntotapa = v[v.size()-2];
      vaux.erase(vaux.end()-3, vaux.end());
   }


   //Vertices

   //Rotación en el eje y
   for (int i=0; i<vaux.size();i+=3){
      // Si no esta en el eje genero las repeticiones
      if( (vaux[i] != 0) || vaux[i+2] != 0){
         for (int j=0; j< repeticiones; j++){
            vertices.push_back( cos ( j * angulo) * vaux[i] +  sin (j * angulo) * vaux[i+2] );
            vertices.push_back( vaux[i+1] );
            vertices.push_back( -sin (j * angulo) * vaux[i] + cos (j * angulo) * vaux[i+2] );
         }
      }else{
         vertices.push_back( vaux[i] );
         vertices.push_back( vaux[i+1] );
         vertices.push_back( vaux[i+2] );
      }
   }

   //Triangulos
   int numVer = vaux.size()/3;
   for (int i=0; i < numVer -1; i++){
      for (int j=0; j < repeticiones; j++){
         triangulos.push_back(i*repeticiones + j);
         int p1 = i*repeticiones + ((j+1)%(repeticiones));
         triangulos.push_back(p1);
         triangulos.push_back(p1+repeticiones);

         triangulos.push_back(i*repeticiones + j);
         triangulos.push_back(p1+repeticiones);
         triangulos.push_back((i*repeticiones + j + repeticiones) );
      }
   }


   //Tapa
   //Si no hay tapa la creo
   if (tapa){
      if( (v[v.size()-3] != 0) || v[v.size()-1] != 0){
         vertices.push_back( 0.0 );
         vertices.push_back( v[v.size()-2] );
         vertices.push_back( 0.0 );
      }else{
         vertices.push_back( 0.0 );
         vertices.push_back( puntotapa );
         vertices.push_back( 0.0 );
      }

      int ultimo = vertices.size()/3 - 1;
      for (int i=1; i<=repeticiones; i++){
         if (i==repeticiones){
            triangulos.push_back(ultimo - 1);
         }else{
            triangulos.push_back(ultimo - i - 1);
         }
         triangulos.push_back(ultimo - i);
         triangulos.push_back(ultimo);
      }
   }

   //Base
   //Si no hay base la creo
   if (base){
      if( (v[0] != 0) || v[2] != 0){
         vertices.push_back( 0.0 );
         vertices.push_back( v[1] );
         vertices.push_back( 0.0 );
      }else{
         vertices.push_back( 0.0 );
         vertices.push_back( puntobase );
         vertices.push_back( 0.0 );
      }

      int ultimo = vertices.size()/3 - 1;
      for (int i=0; i<repeticiones; i++){
         triangulos.push_back((i+1) % repeticiones);
         triangulos.push_back(i);
         triangulos.push_back(ultimo);
      }
   }

   Obj3D::setMalla(vertices,triangulos);
   if (escalado)
      centrarEscalar();
}


void ObjRevolucion::createGeometry(int repeticiones, double ang, bool tapa, bool base){
   vector<GLfloat> vertices;
   vector<GLuint> triangulos;
   double angulo = ang / repeticiones;
   vector<float> vaux = v;
   float puntobase;
   float puntotapa;

   //Base
   //Si hay base la borro y la guardo en variable
   if( (v[0] == 0) && v[2] == 0){
      puntobase = v[1];
      vaux.erase(vaux.begin(), vaux.begin()+3);
   }

   //Tapa
   //Si hay tapa la borro y la guardo en variable
   if( (v[v.size()-3] == 0) && v[v.size()-1] == 0){
      puntotapa = v[v.size()-2];
      vaux.erase(vaux.end()-3, vaux.end());
   }


   //Vertices

   //Rotación en el eje y
   for (int i=0; i<vaux.size();i+=3){
      // Si no esta en el eje genero las repeticiones
      if( (vaux[i] != 0) || vaux[i+2] != 0){
         for (int j=0; j< repeticiones; j++){
            vertices.push_back( cos ( j * angulo) * vaux[i] +  sin (j * angulo) * vaux[i+2] );
            vertices.push_back( vaux[i+1] );
            vertices.push_back( -sin (j * angulo) * vaux[i] + cos (j * angulo) * vaux[i+2] );
         }
      }else{
         vertices.push_back( vaux[i] );
         vertices.push_back( vaux[i+1] );
         vertices.push_back( vaux[i+2] );
      }
   }

   //Triangulos
   int numVer = vaux.size()/3;
   for (int i=0; i < numVer -1; i++){
      for (int j=0; j < repeticiones; j++){
         triangulos.push_back(i*repeticiones + j);
         int p1 = i*repeticiones + ((j+1)/*%(repeticiones)*/);
         triangulos.push_back(p1);
         triangulos.push_back(p1+repeticiones);

         triangulos.push_back(i*repeticiones + j);
         triangulos.push_back(p1+repeticiones);
         triangulos.push_back((i*repeticiones + j + repeticiones) );
      }
   }


   //Tapa
   //Si no hay tapa la creo
   if (tapa){
      if( (v[v.size()-3] != 0) || v[v.size()-1] != 0){
         vertices.push_back( 0.0 );
         vertices.push_back( v[v.size()-2] );
         vertices.push_back( 0.0 );
      }else{
         vertices.push_back( 0.0 );
         vertices.push_back( puntotapa );
         vertices.push_back( 0.0 );
      }

      int ultimo = vertices.size()/3 - 1;
      for (int i=1; i<=repeticiones-1; i++){
         if (i==repeticiones){
            triangulos.push_back(ultimo - 1);
         }else{
            triangulos.push_back(ultimo - i - 1);
         }
         triangulos.push_back(ultimo - i);
         triangulos.push_back(ultimo);
      }
   }

   //Base
   //Si no hay base la creo
   if (base){
      if( (v[0] != 0) || v[2] != 0){
         vertices.push_back( 0.0 );
         vertices.push_back( v[1] );
         vertices.push_back( 0.0 );
      }else{
         vertices.push_back( 0.0 );
         vertices.push_back( puntobase );
         vertices.push_back( 0.0 );
      }

      int ultimo = vertices.size()/3 - 1;
      for (int i=0; i<repeticiones-1; i++){
         triangulos.push_back((i+1) /*% repeticiones*/);
         triangulos.push_back(i);
         triangulos.push_back(ultimo);
      }
   }

   Obj3D::setMalla(vertices,triangulos);
   centrarEscalar();
}


void ObjRevolucion::createGeometry(string eje, int repeticiones, bool tapa, bool base){
   vector<GLfloat> vertices;
   vector<GLuint> triangulos;
   double angulo = (2.0 * M_PI) / repeticiones;
   vector<float> vaux = v;
   float puntobase;
   float puntotapa;

   //Base
   //Si hay base la borro y la guardo en variable
   if (eje == "Y"){
      if( (v[0] == 0) && v[2] == 0){
         puntobase = v[1];
         vaux.erase(vaux.begin(), vaux.begin()+3);
      }
   }else if (eje=="X"){
      if( (v[1] == 0) && v[2] == 0){
         puntobase = v[0];
         vaux.erase(vaux.begin(), vaux.begin()+3);
      }
   }else{
      if( (v[0] == 0) && v[1] == 0){
         puntobase = v[2];
         vaux.erase(vaux.begin(), vaux.begin()+3);
      }
   }

   //Tapa
   //Si hay tapa la borro y la guardo en variable
   if (eje == "Y"){
      if( (v[v.size()-3] == 0) && v[v.size()-1] == 0){
         puntotapa = v[v.size()-2];
         vaux.erase(vaux.end()-3, vaux.end());
      }
   }else if (eje=="X"){
      if( (v[v.size()-2] == 0) && v[v.size()-1] == 0){
         puntotapa = v[v.size()-3];
         vaux.erase(vaux.end()-3, vaux.end());
      }
   }else{
      if( (v[v.size()-3] == 0) && v[v.size()-2] == 0){
         puntotapa = v[v.size()-1];
         vaux.erase(vaux.end()-3, vaux.end());
      }
   }


   //Vertices


   for (int i=0; i<vaux.size();i+=3){
      //Rotación en el eje y
      if (eje == "Y"){
         // Si no esta en el eje genero las repeticiones
         if( (vaux[i] != 0) || vaux[i+2] != 0){
            for (int j=0; j< repeticiones; j++){
               vertices.push_back( cos ( j * angulo) * vaux[i] +  sin (j * angulo) * vaux[i+2] );
               vertices.push_back( vaux[i+1] );
               vertices.push_back( -sin (j * angulo) * vaux[i] + cos (j * angulo) * vaux[i+2] );
            }
         }else{
            vertices.push_back( vaux[i] );
            vertices.push_back( vaux[i+1] );
            vertices.push_back( vaux[i+2] );
         }

      }else if (eje=="X"){
         // Si no esta en el eje genero las repeticiones
         if( (vaux[i+1] != 0) || vaux[i+2] != 0){
            for (int j=0; j< repeticiones; j++){
               vertices.push_back( vaux[i]  );
               vertices.push_back( cos ( j * angulo) * vaux[i+1] -  sin (j * angulo) * vaux[i+2]);
               vertices.push_back( sin (j * angulo) * vaux[i+1] + cos (j * angulo) * vaux[i+2] );
            }
         }else{
            vertices.push_back( vaux[i] );
            vertices.push_back( vaux[i+1] );
            vertices.push_back( vaux[i+2] );
         }

      }else{
         // Si no esta en el eje genero las repeticiones
         if( (vaux[i] != 0) || vaux[i+1] != 0){
            for (int j=0; j< repeticiones; j++){
               vertices.push_back( cos (j * angulo) * vaux[i] - sin (j * angulo) * vaux[i+1] );
               vertices.push_back( sin ( j * angulo) * vaux[i] + cos (j * angulo) * vaux[i+1]);
               vertices.push_back( vaux[i+2]  );
            }
         }else{
            vertices.push_back( vaux[i] );
            vertices.push_back( vaux[i+1] );
            vertices.push_back( vaux[i+2] );
         }

      }
   }

   //Triangulos
   int numVer = vaux.size()/3;
   for (int i=0; i < numVer -1; i++){
      for (int j=0; j < repeticiones; j++){
         triangulos.push_back(i*repeticiones + j);
         int p1 = i*repeticiones + ((j+1)%(repeticiones));
         triangulos.push_back(p1);
         triangulos.push_back(p1+repeticiones);

         triangulos.push_back(i*repeticiones + j);
         triangulos.push_back(p1+repeticiones);
         triangulos.push_back((i*repeticiones + j + repeticiones) );
      }
   }


   //Tapa
   //Si no hay tapa la creo
   if (tapa){
      if (eje == "Y"){
         if( (v[v.size()-3] != 0) || v[v.size()-1] != 0){
            vertices.push_back( 0.0 );
            vertices.push_back( v[v.size()-2] );
            vertices.push_back( 0.0 );
         }else{
            vertices.push_back( 0.0 );
            vertices.push_back( puntotapa );
            vertices.push_back( 0.0 );
         }
      }else if (eje == "X"){
         if( (v[v.size()-2] != 0) || v[v.size()-1] != 0){
            vertices.push_back( v[v.size()-3] );
            vertices.push_back( 0.0  );
            vertices.push_back( 0.0 );
         }else{
            vertices.push_back( puntotapa );
            vertices.push_back( 0.0 );
            vertices.push_back( 0.0 );
         }
      }else{
         if( (v[v.size()-3] != 0) || v[v.size()-2] != 0){
            vertices.push_back( 0.0 );
            vertices.push_back( 0.0 );
            vertices.push_back( v[v.size()-1] );
         }else{
            vertices.push_back( 0.0 );
            vertices.push_back( 0.0 );
            vertices.push_back( puntotapa );
         }
      }

      int ultimo = vertices.size()/3 - 1;
      for (int i=1; i<=repeticiones; i++){
         if (i==repeticiones){
            triangulos.push_back(ultimo - 1);
         }else{
            triangulos.push_back(ultimo - i - 1);
         }
         triangulos.push_back(ultimo - i);
         triangulos.push_back(ultimo);
      }
   }

   //Base
   //Si no hay base la creo
   if (base){
      if (eje == "Y"){
         if( (v[0] != 0) || v[2] != 0){
            vertices.push_back( 0.0 );
            vertices.push_back( v[1] );
            vertices.push_back( 0.0 );
         }else{
            vertices.push_back( 0.0 );
            vertices.push_back( puntobase );
            vertices.push_back( 0.0 );
         }
      }else if(eje == "X"){
         if( (v[1] != 0) || v[2] != 0){
            vertices.push_back( v[0] );
            vertices.push_back( 0.0 );
            vertices.push_back( 0.0 );
         }else{
            vertices.push_back( puntobase );
            vertices.push_back( 0.0 );
            vertices.push_back( 0.0 );
         }
      }else{
         if( (v[0] != 0) || v[1] != 0){
            vertices.push_back( 0.0 );
            vertices.push_back( 0.0 );
            vertices.push_back( v[2] );
         }else{
            vertices.push_back( 0.0 );
            vertices.push_back( 0.0 );
            vertices.push_back( puntobase );
         }

      }

      int ultimo = vertices.size()/3 - 1;
      for (int i=0; i<repeticiones; i++){
         triangulos.push_back((i+1) % repeticiones);
         triangulos.push_back(i);
         triangulos.push_back(ultimo);
      }
   }

   Obj3D::setMalla(vertices,triangulos);
   centrarEscalar();
}

int ObjRevolucion::leerObjetoRev(){
   string input;
   cout<<"Introduce el número de revoluciones: "<<endl;
   getline(std::cin, input);
   return stoi(input);
}
