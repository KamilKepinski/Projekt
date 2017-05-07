#include "scena.h"
#include "cKlocek.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <time.h>
#include <cstdlib>

cScena scena;
int current = -1;
float alfa=0;
/***************/

void przerysuj()
{
	scena.rysuj();
}
cScena::cScena(){
	aktywny = -1;
}
void klawisz(unsigned char znak, int x, int y)
{
	scena.klawiatura(znak, x, y);
}
/*******************/

void cScena::mysz_aktywnie(int x1, int y1)
{
	
}

void mysz_aktywna( int x, int y)
{
	scena.mysz_aktywnie(x, y);
}

void idle()
{
	
	scena.aktualizuj();
	glutPostRedisplay();
	Sleep(1);
}

void cScena::klawiatura(unsigned char key, int mouse_x, int mouse_y)
{
	switch (key)
	{
	case'w':
	{
		
		if (alfa == 270)
			break;
		alfa = 90;
		figury[0]->setPredkosc(0.0001, alfa);
		figury[2]->ustaw_pozycje(figury[0]->x, figury[0]->y-.1);
		figury[2]->setPredkosc(0.0001, alfa);
		break;
	}
	case'd':
	{
		if (alfa == 180)
			break;
		alfa = 0;
		figury[0]->setPredkosc(0.0001, alfa);
		figury[2]->ustaw_pozycje(figury[0]->x-.1, figury[0]->y);
		figury[2]->setPredkosc(0.0001, alfa);
		break;
	}

	case'a':
	{
		if (alfa == 0)
			break;
		alfa = 180;
		figury[0]->setPredkosc(0.0001, alfa);
		figury[2]->ustaw_pozycje(figury[0]->x  +.1, figury[0]->y);
		figury[2]->setPredkosc(0.0001, alfa);
		break;
	}

	case's':
	{
		if (alfa == 90)
			break;
		alfa = 270;
		figury[0]->setPredkosc(0.0001, alfa);
		figury[2]->ustaw_pozycje(figury[0]->x, figury[0]->y+.1);
		figury[2]->setPredkosc(0.0001, alfa);
		
		break;
	}
	


	default:
		break;
	}



}
void cScena::aktualizuj()
{
	int czas = GetTickCount(); //zwraca czas w [ms]
	for (int i = 0; i< figury.size() - 1; i++)
		figury[i]->Aktualizuj(czas); //obliczanie nowych polozen
									 //wykrywanie kolizji
	for (int i = 0; i< figury.size() - 1; i++)
		for (int j = i + 1; j<figury.size() - 1; j++)
			if (figury[i]->Kolizja(*figury[j])) //znajduje kolizje
			{
				


				
			}

		
}
/*******************/
void cScena::rysuj(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	for (auto f = figury.begin(); f != figury.end(); f++)
	{
		(*f)->rysuj();
	}
	glPopMatrix();
	glutSwapBuffers();
}
/***************************************/
void cScena::init()
{
	cProstokat *glowa = new cProstokat(.1, .1);
	glowa->setPredkosc(0.0001, 0);
	glowa->ustaw_kolor(1, 0, 0);
	figury.push_back(glowa);
	
	cProstokat *waz1 = new cProstokat(0.000001, .2);
	waz1->setPredkosc(0.001, 0);
	figury.push_back(waz1);

	cProstokat *waz2 = new cProstokat(.1, .1);
	waz2->setPredkosc(0.0001, 0);
	waz2->przesun(-0.1, 0);
	figury.push_back(waz2);

	cProstokat *waz3 = new cProstokat(.0000000000000001, .1);
	figury.push_back(waz3);



	
	cProstokat *czesc = new cProstokat(.1, .1);
	czesc->ustaw_kolor(.5, 1, .3);
	czesc->ustaw_pozycje(.04,.4);
	figury.push_back(czesc);

//
//	cProstokat *waz3 = new cProstokat(.0000000000000001, .1);
	//figury.push_back(waz3);


	

}
/****************************************/
void cScena::inicjuj()
{
	glutInitWindowPosition(150, 50);
	glutInitWindowSize(900, 600);
	glutIdleFunc(idle);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);// | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutCreateWindow("Prostokaty");
	glClearColor(1, 1, 1, 1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glutKeyboardFunc(::klawisz);
	glutDisplayFunc(::przerysuj);
//	glutMouseFunc(::mysz);
	glutPassiveMotionFunc(::mysz_aktywna);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -.1, .1);
	init();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*********************************************/