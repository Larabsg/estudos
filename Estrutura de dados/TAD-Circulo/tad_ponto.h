// Estruturas utilizadas

typedef struct ponto Ponto;

// Fun��o cria pontos: Aloca e retorna o ponto
Ponto* cria_ponto(float x, float y);

// Faz o free da vari�vel
void libera();

/* 
** Calcula a distancia eucliadina entre dois pontos
** e a retorna 
*/
float distanciaPontos(Ponto* p1, Ponto* p2);

#ifndef tad_ponto_c
	#define tad_ponto_c
	#include "tad_ponto.c"
#endif
