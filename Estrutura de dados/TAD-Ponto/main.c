#include <stdio.h>
#include "tad_ponto.h"

int main() {
	
	float x, y;
	
	printf("Digite o ponto P1(x, y): ");
	scanf("%f %f", &x, &y);
	
	Ponto* p = cria_ponto(x, y);
	
	printf("Digite o ponto P2(x, y): ");
	scanf("%f %f", &x, &y);
	
	Ponto* q = cria_ponto(x, y);
	
	float d = distanciaPontos(p, q);
	
	printf("Distancia dos pontos eh: %.1f", d);
	
	return 0;
}
