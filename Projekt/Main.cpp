#include "Scena.h"
#include "cProstokat.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

int main(int argc, char *argv[])
{

	glutInit(&argc, argv);
	scena.inicjuj();
	glutMainLoop();

	return 0;
}