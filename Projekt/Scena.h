#ifndef _SCENA _H
#define _SCENA _H
#include <vector>
#include "cFigura.h"

#include "cProstokat.h"
#include "cOkrag.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <list>
class cScena{
protected:
	int aktywny;
	vector<cFigura*> figury;
	vector<cFigura*> sciany;
	vector<cFigura*> pilki;
public:
	cScena();
	void rysuj();
	void inicjuj();
	void aktualizuj();
	void init();
	void key(unsigned char key, int x_d, int y_d);
};
extern cScena scena;

#endif