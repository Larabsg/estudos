/*TAD - Fila*/

typedef struct fila Fila;
typedef struct lista Lista;

Fila* fila_cria(void);

int fila_vazia(Fila* f);

void fila_insere(Fila* f, float valor);

void fila_imprime(Fila* f);

float fila_retira(Fila* f);

void fila_libera(Fila* f);

#ifndef fila_c
	#define fila_c
	#include "fila.c"
#endif
