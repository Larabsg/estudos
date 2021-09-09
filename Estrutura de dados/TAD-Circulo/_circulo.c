#include <stdlib.h>
#include "circulo.h"

#define PI 3.14159

struct circulo {
	Ponto* p;
	float r;
};

Circulo* circ_cria (float x, float y, float r) {
	Circulo* c = (Circulo*)malloc(sizeof(Circulo));
	c->p = cria_ponto(x,y);
	c->r = r;
	return c;
}

void circ_libera (Circulo* c) {
	libera(c->p);
	free(c);
}

float circ_area (Circulo* c) {
	return PI*c->r*c->r;
}

int circ_interior (Circulo* c, Ponto* p) {
	float d = distanciaPontos(c->p, p);
	return (d<c->r);
}
