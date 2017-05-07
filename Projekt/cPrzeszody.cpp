#include "cProstokat.h"




cPrzeszkody::cPrzeszkody()
{
	w = 10;
	h = 3;
	setGeometria(x, y, -w, -h, w, h);
}

cPrzeszkody::~cPrzeszkody()
{

}

cPrzeszkody::cPrzeszkody(double dr, double dg, double db, double dh, double dw)
{
	R = dr;
	G = dg;
	B = db;
	w = dw;
	h = dh;
	setGeometria(x, y, -w, -h, w, h);

}
