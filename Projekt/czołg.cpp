#include "czo³g.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

cCzolg::cCzolg()
{
	h = 0.1; w = 0.2;
}
/**************************/
cCzolg::cCzolg(float _h, float _w)
{
	w = _w; h = _h;
	setGeometria(x, y, -w / 2, -h / 2, w / 2, h / 2);
}


/**************************/
void cCzolg::rysuj() {
	glPushMatrix();
	glColor3f(R, G, B);
	glTranslatef(x, y, 0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(alpha, 0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	{
		//czolg
		glVertex2d(-w / 2, h / 2);
		glVertex2d(w / 2, h / 2);
		glVertex2d(w / 2, -h / 2);
		glVertex2d(-w / 2, -h / 2);
	

		//lufa
		glVertex2d(w , h / 5);
		glVertex2d(w , -h / 5);
		
		glVertex2d(w / 2, -h / 5);

	}
	glEnd();
	glPopMatrix();
}
void cCzolg::Odbicie(float alfa_n)
{
	odpornosc--;
	if (odpornosc <= 0)
		widoczny = false;
	CFizyka::Odbicie(alfa_n);
}