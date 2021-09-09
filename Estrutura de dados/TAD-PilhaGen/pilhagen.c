#include <stdlib.h>
#include "pilhagen.h"

typedef struct listagen {
	void* info;
	struct listagen* prox;
}ListaGen;

typedef struct pilhagen {
	ListaGen* prim;
}PilhaGen;

typedef struct aluno {
	int mat;
	char nome[101];
	char email[51];
}Aluno;

PilhaGen* pilhaGen_cria(void) {
	PilhaGen* pilha = (PilhaGen*)malloc(sizeof(PilhaGen));
	pilha->prim = NULL;
	
	return pilha;
}

int pilhaGen_vazia(PilhaGen* pilha) {
	return pilha->prim == NULL;
}

void pilhaGen_push(PilhaGen* pilha, void*(*registra)(void)) {
	ListaGen* novo = (ListaGen*)malloc(sizeof(ListaGen));
	
	novo->info = (Aluno*)registra();
	novo->prox = pilha->prim;
	pilha->prim = novo;
}

void* pilhaGen_pop(PilhaGen* pilha) {
	ListaGen* temp;
	void* p;
	
	if(pilhaGen_vazia(pilha))
		return NULL;
	else {
		temp = pilha->prim;
		p = temp->info;
		pilha->prim = temp->prox;
		free(temp);
		
		return p;
	}
}

void pilhaGen_imprime(PilhaGen* pilha, void(*imp)(void*)) {
	ListaGen* temp;
	
	for(temp = pilha->prim; temp != NULL; temp = temp->prox) {
		imp(temp->info);
	}
}
