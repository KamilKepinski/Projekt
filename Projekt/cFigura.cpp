#include "cFigura.h"
#include "cProstokat.h"
#include "Scena.h"

cFigura::cFigura(){
	x = 0;
	y = 0;
	R = 0; G = 0; B = 0;
	alpha = 0;
}

void cFigura::przesun(float dx, float dy){
	x += dx;
	y += dy;
}
/***************************/
void cFigura::idz_do(float q, float r){
	x = q;
	y = r;
}
/******************************/
void cFigura::obroc(float dalpha){
	alpha += dalpha;
}
/*********************************/
void cFigura::ustaw_kolor(float r, float g, float b){
	R = r;
	G = g;
	B = b;
}
/*********************************/