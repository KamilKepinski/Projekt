#ifndef _COKRAG_H
#define _COKRAG_H

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