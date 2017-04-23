#include "cOkrag.h"

cOkrag::cOkrag(){
	r = 0.1;
}
/************************/
cOkrag::cOkrag(float _r)
{
	r = _r;
	setGeometria(x, y, x - r, y - r, x + r, y + r);
}
/************************/
void cOkrag::rysuj(){
	glPushMatrix();
	glColor3f(R, G, B);
	glTranslatef(x, y, 0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(alpha, 0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i += 1) {
		float i_rad = i*PI / (float)180;
		float pos_x = x + r * cos(i_rad);
		float pos_y = y + r * sin(i_rad);
		glVertex2f(pos_x, pos_y);
	}
	glEnd();
	glPopMatrix();
}
/**********************************************/