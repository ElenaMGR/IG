#ifndef _LUZ_H
#define _LUZ_H

#include <vector>
#include <GL/glut.h>
#include <GL/gl.h>

class Luz{
   private:
   public:
      void Inicializarluz();
      /**
      *	 Habilita o desabilita la opción de iluminación de OpenGL
      */
      void enableLuz (bool estado);

      /**
      *	 Enciende o apaga la luz i-�sima
      */
      void encenderLuz(int luz_i);
      void apagarLuz(int luz_i);
      /** Colores de la fuente de luz
      *	 Asignación de los colores a la luz iésima.
      */
      void setLuz(GLenum luz_i, float colors[4][4], bool positional, GLfloat posf[4]);
};

#endif
