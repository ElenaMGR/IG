#ifndef _OBJ3D_H
#define _OBJ3D_H

#include <vector>
#include <GL/glut.h>
#include <GL/gl.h>
#include "math.h"
#include "tuplas.h"
using namespace std;

struct Malla {
   vector<GLfloat> vertices;
   vector<GLuint> triangulos;
   vector<GLuint> carasPares;
   vector<GLuint> carasImpares;
   vector<GLfloat> color;
   vector<GLfloat> colorLineas;
   vector<GLfloat> colorPares;
   vector<GLfloat> normalesCaras;
   vector<GLfloat> normalesVertices;
   vector<pair<GLfloat, GLfloat>> mapaTexturas;
};

class Obj3D {
private:
   Malla mesh;
   float cx,cy,cz;
public:
   /**
   * Método que dibuja el objeto3D
   */
   void draw (GLenum face, GLenum mode, bool ajedrez);
   void asignarColor(float r, float g, float b);
   void generarNormalesCaras();
   void generarNormalesVertices();
   void generarCoordenadasTexturaRev(int repeticiones, int vertices);
   Tupla3r getCentro();

protected:
   void setMalla(vector<GLfloat> v, vector<GLuint> t);
   vector<GLuint> getCarasPares (bool par);
   void moverObjeto ();
   void asignarColorCarasPares(float r, float g, float b);
   void centrarEscalar();
   void normalizar(float & x, float & y, float & z);

};


#endif
