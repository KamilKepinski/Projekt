#include "scena.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

cScena scena;
/***********************************************/
void przerysuj()
{
	scena.rysuj();
}
/***********************************************/
void cScena::key(unsigned char key, int x_d, int y_d)
{
	switch (key)
	{
	case 'd':
		figury[0]->przesun(1, 0);
		glutPostRedisplay();
		break;
	case 'a':
		figury[0]->przesun(-1, 0);
		glutPostRedisplay();
	}
}
void key(unsigned char z, int x, int y){
	scena.key(z, x, y);
}
/*******************/
cScena::cScena(){
	aktywny = -1;
}
/*******************/
void cScena::rysuj(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	pilki[0]->rysuj();
	for (auto f = figury.begin(); f != figury.end(); f++)
	{
		(*f)->rysuj();
	}
	for (auto itr = sciany.begin(); itr != sciany.end(); itr++)
	{
		(*itr)->rysuj();
	}
	glPopMatrix();
	glutSwapBuffers();
}
/*************************************/
void cScena::aktualizuj()

{
	for (int i = 0; i < figury.size(); i++)
	{
		if (pilki[0]->Kolizja(*figury[i]));
	}
	for (int i = 0; i < sciany.size(); i++)
	{
		if (pilki[0]->Kolizja(*sciany[i]))
		{

		}
	}
	pilki[0]->Aktualizuj(GetTickCount());
	pilki[0]->Reset();
}

/*************************************/
void cScena::init()
{
	cOkrag *pilka = new cOkrag(0.5);
	pilka->setPredkosc(0.01, 70);
	pilka->ustaw_kolor(1, 0.3, 0);
	pilka->idz_do(0, -10);
	pilki.push_back(pilka);
	cProstokat *paletka = new cProstokat(1, 8);
	paletka->setPredkosc(0, 0);
	paletka->ustaw_kolor(0, 0.3, 1);
	paletka->idz_do(0, -24);
	figury.push_back(paletka);
	//(-37.5, 0, 5, 75, 0.5, 0.5, 0.5));
	cProstokat *sciana1 = new cProstokat(50, 2);
	sciana1->setPredkosc(0, 0);
	sciana1->idz_do(-28, 0);
	figury.push_back(sciana1);
	cProstokat *sciana2 = new cProstokat(50, 2);
	sciana2->setPredkosc(0, 0);
	sciana2->idz_do(28, 0);
	figury.push_back(sciana2);
	cProstokat *sufit = new cProstokat(2, 58);
	sufit->setPredkosc(0, 0);
	sufit->idz_do(0, 25);
	figury.push_back(sufit);
	int pozycja = -22;
	double kolor, kolor2, kolor3;
	for (int i = 0; i < 10; i++)
	{
		kolor = ((double)rand() / (RAND_MAX));
		kolor2 = ((double)rand() / (RAND_MAX));
		kolor3 = ((double)rand() / (RAND_MAX));
		cPrzeszkody *klocek1 = new cPrzeszkody(kolor, kolor2, kolor3, 5,11);
		klocek1->setPredkosc(0, 0);
		klocek1->idz_do(pozycja, 7);
		sciany.push_back(klocek1);
		pozycja += 5;

	}
	pozycja = -22;

	for (int i = 0; i < 10; i++)

	{
		kolor = ((double)rand() / (RAND_MAX));
		kolor2 = ((double)rand() / (RAND_MAX));
		kolor3 = ((double)rand() / (RAND_MAX));
		cPrzeszkody *klocek2 = new cPrzeszkody(kolor, kolor2, kolor3, 5,11);
		klocek2->setPredkosc(0, 0);
		klocek2->idz_do(pozycja, 12);
		sciany.push_back(klocek2);
		pozycja += 5;


	}
	}
void idle()
{
	scena.aktualizuj();
	glutPostRedisplay();
	Sleep(1);
}

/****************************************/
void cScena::inicjuj(){
	glutInitWindowPosition(200, 0);
	glutInitWindowSize(1000, 700);
	init();
	glutIdleFunc(idle);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);//| GLUT_DEPTH | GLUT_MULTISAMPLE
	glutCreateWindow("Prostokaty");
	glClearColor(1, 1, 1, 1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glutDisplayFunc(::przerysuj);
	glutKeyboardFunc(::key);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-30, 30, -30, 30, -30, 30);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*********************************************/