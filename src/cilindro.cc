#ifdef _WIN32
#include <windows.h>
#endif

#include "cilindro.h"

Cilindro::Cilindro(){
   vec.push_back(0.5);
   vec.push_back(-0.5);
   vec.push_back(0);
   vec.push_back(0.5);
   vec.push_back(0.5);
   vec.push_back(0);
   v = vec;

   createGeometry(20,true,true,false) ;
}
