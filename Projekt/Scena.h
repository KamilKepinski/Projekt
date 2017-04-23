#ifndef _SCENA_H
#define _SCENA_H

#include <vector>
#include "cFigura.h"
#include "cProstokat.h"
#include "cOkrag.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

class cScena{
protected:
	int aktywny;
	vector<cFigura*> figury;
public:
	cScena();
	void rysuj();
	void inicjuj();
	void aktualizuj();
	void init();
	void loop();
	void key(unsigned char key, int x_d, int y_d);
};
extern cScena scena;

#endif