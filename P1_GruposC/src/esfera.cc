#ifdef _WIN32
#include <windows.h>
#endif

#include "esfera.h"

Esfera::Esfera(){
   vec.push_back(0);
   vec.push_back(-0.5);
   vec.push_back(0);

   vec.push_back(0.154509);
   vec.push_back(-0.475528);
   vec.push_back(0);

   vec.push_back(0.293893);
   vec.push_back(-0.404509);
   vec.push_back(0);

   vec.push_back(0.404509);
   vec.push_back(-0.293893);
   vec.push_back(0);

   vec.push_back(0.475528);
   vec.push_back(-0.154509);
   vec.push_back(0);

   vec.push_back(0.5);
   vec.push_back(0);
   vec.push_back(0);

   vec.push_back(0.475528);
   vec.push_back(0.154509);
   vec.push_back(0);

   vec.push_back(0.404509);
   vec.push_back(0.293893);
   vec.push_back(0);

   vec.push_back(0.293893);
   vec.push_back(0.404509);
   vec.push_back(0);

   vec.push_back(0.154509);
   vec.push_back(0.475528);
   vec.push_back(0);

   vec.push_back(0);
   vec.push_back(0.5);
   vec.push_back(0);
   v = vec;

   createGeometry(20,true,true,false) ;
}
