#ifndef _OBJ3D_H
#define _OBJ3D_H

#include <vector>

struct Malla {
   int num_ver;
   int num_tri;
   vector<float> vertices;
   vector<float> triangulos;
};

class Obj3D {

private:
   Malla mesh;

public:
   void draw (Malla *mesh);
};


#endif
