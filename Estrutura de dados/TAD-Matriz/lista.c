#include <stdlib.h>
#include "lista.h"

typedef struct lista {
	int info;
	struct lista* prox;
} Lista;

Lista* lst_cria (void) {
	return NULL;
}

void lst_libera (Lista* l);

Lista* lst_insere (Lista* l, int valor) {
	Lista* nHead = (Lista*)malloc(sizeof(Lista));
	nHead->info = valor;
	nHead->prox = l;
	
	return nHead;
}

int lst_vazia (Lista* l) {
	return (l == NULL);
}

void lst_imprime (Lista* l) {
	Lista* i;
	for(i=l;i!=NULL;i=i->prox) {
		printf("Info[i] = %d\n", i->info);
	}
}
