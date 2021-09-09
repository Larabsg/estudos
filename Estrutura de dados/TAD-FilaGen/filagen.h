typedef struct listagen ListaGen;
typedef struct filagen FilaGen;

FilaGen* criar_fila();
int fila_vazia(FilaGen* fila);
void fila_insere(FilaGen* fila, void*(*registra)(void));
void fila_imprime(FilaGen* fila, void(*imprime)(void*));
FilaGen* fila_retira(FilaGen* fila);
void fila_libera(FilaGen* fila);

#ifndef filagen_c
	#define filagen_c
	#include "filagen.c"
#endif
