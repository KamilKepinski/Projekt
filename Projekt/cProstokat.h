#ifndef _CPROSTOKAT _H
#define _CPROSTOKAT _H
using namespace std;
#include "Scena.h"
#include "cFizyka.h"
#include "cFigura.h"

class cProstokat : public cFigura {
protected:
	float h, w;
public:
	cProstokat();
	~cProstokat();
	cProstokat(float _h, float _w);
	void rysuj();
};



class cPrzeszkody :public cProstokat
{
protected:
	int punkty;

public:
	cPrzeszkody();
	~cPrzeszkody();
	cPrzeszkody(double dr, double dg, double db, double dh, double dw);


};
#endif