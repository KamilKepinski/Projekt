#include "cProstokat.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

cProstokat::cProstokat(){
	w = 10;
	h = 3;
	setGeometria(x, y, -w, -h, w, h);
}
/**************************/
cProstokat::cProstokat(float _h, float _w)
{
	w = _w; h = _h;
	setGeometria(x, y, -w, -h, w, h);
}
/**************************/
void cProstokat::rysuj(){
	glPushMatrix();
	glColor3f(R, G, B);
	glTranslatef(x, y, 0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(alpha, 0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	{
		glVertex3d(-w / 2, h / 2, 0);
		glVertex3d(w / 2, h / 2, 0);
		glVertex3d(w / 2, -h / 2, 0);
		glVertex3d(-w / 2, -h / 2, 0);
	}
	glEnd();
	glPopMatrix();
}
/****************************/
cProstokat::~cProstokat(){
	
}