/*TAD: matriz m por n*/

typedef struct matriz Matriz;

// Cria matriz de dimensão l por c
Matriz* mat_cria (int l, int c);

// Imprime na tela a matriz criada anteriormente
void mat_imprime(Matriz* mat);

// Libera a matriz
void mat_libera (Matriz* mat);

#ifndef matriz_c
	#define matriz_c
	#include "matriz.c"
#endif
