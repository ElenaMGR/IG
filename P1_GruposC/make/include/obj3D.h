#ifndef _OBJ3D_H
#define _OBJ3D_H

#include <vector>
#include <GL/glut.h>
#include <GL/gl.h>
using namespace std;

struct Malla {
   int num_ver;
   int num_tri;
   vector<GLfloat> vertices;
   vector<GLuint> triangulos;
};

class Obj3D {

private:
   Malla mesh;
   void calculaNumVer();
   void calculaNumTri();

public:
   /**
   * Método que dibuja el objeto3D
   */
   void draw (GLenum face, GLenum mode, bool ajedrez);

protected:

   void setMalla(vector<GLfloat> v, vector<GLuint> t);
   vector<GLuint> getCarasPares (bool par);

};


#endif
