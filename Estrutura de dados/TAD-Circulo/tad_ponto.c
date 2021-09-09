#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct ponto {
	float x, y;
} Ponto;

Ponto* cria_ponto(float x, float y) {
	Ponto* p = (Ponto*)malloc(sizeof(Ponto));
	
	p->x = x;
	p->y = y;
	
	return p;
}

void libera(Ponto* x) {
	free(x);
}

//void ponto_acessa(Ponto* p, float* x, float* y) {
//	*x = p->x;
//	*y = p->y;
//}

float distanciaPontos(Ponto* p1, Ponto* p2) {
	return sqrt(pow((p2->x - p1->x), 2) + pow((p2->y - p1->y), 2));
}
