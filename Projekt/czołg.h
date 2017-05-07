#ifndef _CZOLG_H
#define _CZOLG_H

#include "scena.h"
#include "fizyka.h"
#include "cFigura.h"

class cCzolg : public cFigura {
protected:
	float h, w;
	int odpornosc=5;
public:
	virtual void Odbicie(float alfa_n);
	cCzolg();
	cCzolg(float _h, float _w);
	void rysuj();

};

#endif
