/*TAD - Pilha*/

typedef struct lista Lista;
typedef struct pilha Pilha;

Pilha* pilha_cria(void);

int pilha_vazia(Pilha* p);

void pilha_push(Pilha* p, float valor);

float pilha_pop(Pilha* p);

void pilha_imprime(Pilha* p);

void pilha_libera(Pilha* p);

#ifndef pilha_c
	#define pilha_c
	#include "pilha.c"
#endif
