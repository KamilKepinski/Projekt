#include "scena.h"
#include "cKlocek.h"
#include "czo³g.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

cScena scena;
int current = -1;
float kat_max=2;
float kat_min =180;
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

void cScena::obracaj_czolgi()
{

	figury[4]->obroc(0.1);
	figury[5]->obroc(-0.13);
	figury[6]->obroc(0.18);
}

void cScena::strzelaj()
{
	if(figury[4]->sprawdz_kat()==0)
	{ 
		cProstokat *pocisk1 = new cProstokat(0.03, .03);
	pocisk1->ustaw_pozycje(figury[4]->x, figury[4]->y);
		pocisk1->setPredkosc(0.002, figury[4]->sprawdz_kat());
		figury.push_back(pocisk1);

		cProstokat *pocisk2 = new cProstokat(0.03, .03);
		pocisk2->ustaw_pozycje(figury[4]->x, figury[4]->y);
		pocisk2->setPredkosc(0.002, figury[4]->sprawdz_kat());
		figury.push_back(pocisk2);
	}
}


void mysz_aktywna( int x, int y)
{
	scena.mysz_aktywnie(x, y);
}

void idle()
{
	scena.strzelaj();
	scena.obracaj_czolgi();
	scena.aktualizuj();
	glutPostRedisplay();
	Sleep(1);
}

void cScena::klawiatura(unsigned char key, int mouse_x, int mouse_y)
{
	switch (key)
	{

	case'd':
	{
		figury[7]->przesun(0.01,0);
		break;
	}

	case'a':
	{
		figury[7]->przesun(-0.01, 0);
		break;
	}
	case'w':
	{
		figury[7]->przesun(0, 0.01);
		break;
	}
	
	case's':
	{
		figury[7]->przesun(0, -0.01);
		break;
	}
	case'e':
	{
		figury[7]->obroc(-2);
		break;
	}

	case'q':
	{
		figury[7]->obroc(2);
		break;
	}
	case'f':
	{


		cProstokat *pocisk = new cProstokat(0.03, .03);
		pocisk->ustaw_pozycje(figury[7]->x, figury[7]->y);
		pocisk->setPredkosc(0.002, figury[7]->sprawdz_kat());
		figury.push_back(figury[7]->strzal());


		
	}


	default:
		break;
	}



}
void cScena::aktualizuj()
{
	int czas = GetTickCount(); //zwraca czas w [ms]
	for (int i = 0; i<figury.size() ; i++)
		figury[i]->Aktualizuj(czas); //obliczanie nowych polozen
									 //wykrywanie kolizji
	for (int i = 0; i< figury.size() - 1; i++)
		for (int j = i + 1; j<figury.size() ; j++)
			if (figury[i]->Kolizja(*figury[j])) //znajduje kolizje
			{
				cProstokat* pocisk = dynamic_cast<cProstokat*>(figury[j]);
				if (pocisk != NULL)
				{
					//usun pocisk
					delete pocisk;

					cCzolg* czolg = dynamic_cast<cCzolg*>(figury[i]);
					if (czolg != NULL)
					{
						int health = czolg->trafiony();
						if (health == 0)
						{
							//usun
							//usun element z wektora
							delete czolg;
							

						}
					}
				

				}
				//figury[j]->odbicie();





				
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
	cProstokat *granica = new cProstokat(1.5, .1);
	granica->przesun(-1, 0);
	figury.push_back(granica);


	cProstokat *granica1 = new cProstokat(.1, 2);
	granica1->przesun(0, .8);
	figury.push_back(granica1);


	

	cProstokat *granica2 = new cProstokat(.1, 2);
	granica2->przesun(0, -.8);
	figury.push_back(granica2);

	cProstokat *granica3 = new cProstokat(1.5, .1);
	granica3->przesun(1, 0);
	figury.push_back(granica3);

	cCzolg *czolg_CPU = new cCzolg(.15, .15);
	czolg_CPU->ustaw_kolor(.3, .7, .3);
	czolg_CPU->ustaw_pozycje(-.8, .6);
	figury.push_back(czolg_CPU);


	cCzolg *czolg_CPU_1 = new cCzolg(.15, .15);
	czolg_CPU_1->ustaw_kolor(.3, .7, .3);
	czolg_CPU_1->ustaw_pozycje(-.8, -.6);
	
	figury.push_back(czolg_CPU_1);
	

	cCzolg *czolg_CPU_2 = new cCzolg(.15, .15);
	czolg_CPU_2->ustaw_kolor(.3, .7, .3);
	czolg_CPU_2->ustaw_pozycje(.8, .6);
	czolg_CPU_2->obroc(180);
	figury.push_back(czolg_CPU_2);

	cCzolg *czolg_SI = new cCzolg(.15, .15);
	czolg_SI->ustaw_kolor(.9, .6, .1);
	czolg_SI->ustaw_pozycje(.8, -.6);
	czolg_SI->obroc(180);
	figury.push_back(czolg_SI);





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