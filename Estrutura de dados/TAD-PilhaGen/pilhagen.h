typedef struct listagen ListaGen;
typedef struct pilhagen PilhaGen;
typedef struct aluno Aluno;
PilhaGen* pilhaGen_cria(void);
int pilhaGen_vazia(PilhaGen* pilha);
void pilhaGen_push(PilhaGen* pilha, void*(*registra)(void));
void* pilhaGen_pop(PilhaGen* pilha);
void pilhaGen_imprime(PilhaGen* pilha, void(*imp)(void* val));

#ifndef pilhagen_c
	#define pilhagen_c
	#include "pilhagen.c"
#endif
