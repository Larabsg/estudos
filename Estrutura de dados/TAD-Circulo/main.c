#include <stdio.h>
#include "circulo.h"
#include "tad_ponto.h"

int main() {
	
	float x, y, r, d;
	int cmp;

	printf("Digite valores para P(x,y): ");
	scanf("%f %f", &x, &y);
	
	printf("\nDigite o valor do raio: ");
	scanf("%f", &r);
	
	Circulo* c = circ_cria(x, y, r);
	
	d = circ_area(c);
	
	printf("\nA area do circulo eh: %.2f", d);
	
	printf("\nDigite um valores para outro ponto P2(x, y): ");
	scanf("%f %f", &x, &y);
	
	Ponto* p = cria_ponto(x, y);
	
	cmp = circ_interior(c, p);
	
	if(cmp)
		printf("\nO ponto esta dentro do circulo!");
	else
		printf("\nO ponto esta fora do circulo!");
	
	circ_libera(c);
	libera(p);
	return 0;
}
