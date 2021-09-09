#include <stdlib.h>
#include "listagen.h"

typedef struct listagen {
	void* info;
	struct listagen* prox;
} ListaGen;

typedef struct aluno {
	int mat;
	char nome[101];
	char email[51];
} Aluno;

ListaGen* lgen_cria() {
	return NULL;
}
int lgen_vazia(ListaGen* L) {
	return (L==NULL);
}
void lgen_imprime(ListaGen* L, void(*f_imp)(void*)) {
	ListaGen* temp;
	
	for(temp = L; temp != NULL; temp = temp->prox) {
		f_imp(temp->info);
	}
}
