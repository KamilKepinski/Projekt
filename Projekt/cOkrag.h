#ifndef _COKRAG _H
#define _COKRAG _H
#include "cFigura.h"

class cOkrag : public cFigura{
protected:
	float r;
public:
	cOkrag();
	cOkrag(float _r);
	void rysuj();
};
#endif