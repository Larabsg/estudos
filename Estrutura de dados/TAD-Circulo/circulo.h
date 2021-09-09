#include "tad_ponto.h"

/* Tipo exportado */
typedef struct circulo Circulo;

/* Funções exportadas */

/* Função cria
** Aloca e retorna um círculo com centro (x,y) e raio r
*/
Circulo* circ_cria (float x, float y, float r);

/* Função libera 
** Libera a memória de um circulo previamente criado
*/
void circ_libera (Circulo* c);

/* Função área
** Retorna o valor da área do circulo
*/
float circ_area (Circulo* c);

/* Função interior
** Verifica se um dado ponto p está dentro do círculo
*/
int circ_interior (Circulo* c, Ponto* p);

#ifndef circulo_c
	#define circulo_c
	#include "_circulo.c"
#endif



