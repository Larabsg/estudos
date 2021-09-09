// Estruturas utilizadas

typedef struct ponto Ponto;

// Função cria pontos: Aloca e retorna o ponto
Ponto* cria_ponto(float x, float y);

// Faz o free da variável
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
