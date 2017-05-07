#ifndef _SCENA_H
#define _SCENA_H

#include <vector>
#include "cFigura.h"
#include "cProstokat.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

class cScena:public CFizyka{
protected:
	int aktywny;
	vector<cFigura*> figury;
	
	int punkty;
public:
	cScena();
	void rysuj();
	void inicjuj();
	void aktualizuj();
	void init();
	void mysz_aktywnie(int x1, int y1);
	void klawiatura(unsigned char key, int mouse_x, int mouse_y);
	void obracaj_czolgi();
	void strzelaj();
	void przesun_weza();
	void zmien_kierunek();
};
extern cScena scena;

#endif