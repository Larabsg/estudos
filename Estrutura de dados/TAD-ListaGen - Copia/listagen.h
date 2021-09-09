typedef struct listagen ListaGen;

typedef struct aluno Aluno;

ListaGen* lgen_cria();
int lgen_vazia(ListaGen* L);
void lgen_imprime(ListaGen* L, void(*f_imp)(void*));
Aluno* registra_aluno(int mat, char* nome, char* email);
ListaGen* lgen_insere(ListaGen* L, void* p);
void* lgen_busca(ListaGen* L, int(*comp)(void*, void*), void* mat);
ListaGen* lgen_exclui(ListaGen* L, int(*comp)(void*, void*), void* mat);

#ifndef listagen_c
	#define listagen_c
	#include "listagen.c"
#endif
