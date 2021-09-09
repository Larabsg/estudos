typedef struct listagen ListaGen;

typedef struct aluno Aluno;

ListaGen* lgen_cria();
int lgen_vazia(ListaGen* L);
void lgen_imprime(ListaGen* L, void(*f_imp)(void*));

#ifndef listagen_c
	#define listagen_c
	#include "listagen.c"
#endif
