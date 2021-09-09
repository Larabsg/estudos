#include <stdlib.h>
#include "pilha.h"

typedef struct lista {
	float info;
	struct lista* prox;
} Lista;
typedef struct pilha {
	Lista* prim;
} Pilha;

Pilha* pilha_cria(void) {
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

int pilha_vazia(Pilha* p) {
	return (p->prim == NULL);
}

void pilha_push(Pilha* p, float valor) {
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	
	novo->info = valor;
	novo->prox = p->prim;
	p->prim = novo;
}

float pilha_pop(Pilha* p) {
	Lista* temp;
	float v;
	
	if(pilha_vazia(p)) {
		printf("Pilha vazia!\n");
		exit(1);
	}
	else {
		temp = p->prim;
		v = temp->info;
		p->prim = temp->prox;
		free(temp);
		
		return v;
	}
}

void pilha_imprime(Pilha* p) {
	
	Lista* per= p->prim;
	
	while(per!= NULL) {
		printf("Info: %.2f\n", per->info);
		per = per->prox;
	}
}

void pilha_libera(Pilha* p) {
	Lista* per = p->prim;
	while(per!= NULL) {
		Lista* temp = per->prox;
		free(per);
		per = temp;
	}
	
	free(p);
}
