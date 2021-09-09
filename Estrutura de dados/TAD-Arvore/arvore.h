/*TAD - Arvore*/

typedef struct arv Arv;

Arv* arv_criavazia(void);
Arv* arv_cria(char c, Arv* esq, Arv* dir);
Arv* arv_libera(Arv* a);
int arv_vazia(Arv* a);
int arv_pertence(Arv* a, char c);
void arv_imprime(Arv* a);

#ifndef arvore_c
	#define arvore_c
	#include "arvore.c"
#endif
