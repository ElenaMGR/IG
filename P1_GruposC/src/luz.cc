#ifdef _WIN32
#include <windows.h>
#endif

#include "luz.h"

void Luz::Inicializarluz(){

   // Propiedades a las luces
	//GLfloat lmodel_ambient[] = {0.2,0.2,0.2,1.0};
	GLfloat lmodel_light[3][4] = {{0.2,0.2,0.2,1.0},{1.0,1.0,1.0,1.0},{1.0,1.0,1.0,1.0}};
	// light0.setLightColor(lmodel_light);
	GLfloat posf[4] = {0,100,100,1.0};
   //	 light0.setPosition(posf);
	setLuz(GL_LIGHT0,lmodel_light,true,posf);

	GLfloat lmodel_light1[3][4] = {{1.0,0.0,0.0,1.0},{1.0,0.0,0.0,1.0},{1.0,0.0,0.0,1.0}};
	GLfloat posf1[4] = {100,100,0,1.0};
	GLfloat posf2[4] = {-100,100,0,0.0};
	//setLuz(GL_LIGHT1,lmodel_light1,true,posf1);
	//setLuz(GL_LIGHT2,lmodel_light1,true,posf2);

}

void Luz::enableLuz(bool state){
   if (state)
      glEnable(GL_LIGHTING);
   else
      glDisable(GL_LIGHTING);


}

void Luz::encenderLuz(int light_i){
   glEnable(GL_LIGHT0 + light_i);
}

void Luz::apagarLuz(int light_i){
   glDisable(GL_LIGHT0 + light_i);
}

void Luz::setLuz(GLenum light_i, float colors[3][4], bool positional, GLfloat posf[4]){

	glEnable(light_i);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

    glLoadIdentity();
		glLightfv(light_i, GL_AMBIENT, colors[0]);
		glLightfv(light_i, GL_DIFFUSE, colors[1]);
		glLightfv(light_i, GL_SPECULAR, colors[2]);
		glLightfv(light_i, GL_POSITION, posf);

	glPopMatrix();

}
