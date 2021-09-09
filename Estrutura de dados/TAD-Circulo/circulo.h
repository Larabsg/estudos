#include "tad_ponto.h"

/* Tipo exportado */
typedef struct circulo Circulo;

/* Fun��es exportadas */

/* Fun��o cria
** Aloca e retorna um c�rculo com centro (x,y) e raio r
*/
Circulo* circ_cria (float x, float y, float r);

/* Fun��o libera 
** Libera a mem�ria de um circulo previamente criado
*/
void circ_libera (Circulo* c);

/* Fun��o �rea
** Retorna o valor da �rea do circulo
*/
float circ_area (Circulo* c);

/* Fun��o interior
** Verifica se um dado ponto p est� dentro do c�rculo
*/
int circ_interior (Circulo* c, Ponto* p);

#ifndef circulo_c
	#define circulo_c
	#include "_circulo.c"
#endif



