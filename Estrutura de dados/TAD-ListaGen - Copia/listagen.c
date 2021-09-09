#include <stdlib.h>
#include <string.h>
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

Aluno* registra_aluno(int mat, char* nome, char* email) {
	Aluno* alu = (Aluno*)malloc(sizeof(Aluno));
	
	alu->mat = mat;
	strcpy(alu->nome, nome);
	strcpy(alu->email, email);
	
	return alu;
}
ListaGen* lgen_insere(ListaGen* L, void* p) {
	ListaGen* novo = (ListaGen*)malloc(sizeof(ListaGen));
	novo->info = p;
	novo->prox = L;
	
	return novo;
}

void* lgen_busca(ListaGen* L, int(*comp)(void*, void*), void* mat) {
	ListaGen* p;
	
	for(p = L; p != NULL; p = p->prox) {
		if(comp(p->info, mat)) {
			return p->info;
		}
	}
	
	return NULL;
}

ListaGen* lgen_exclui(ListaGen* L, int(*comp)(void*, void*), void* mat) {
	ListaGen* p;
	ListaGen* ant = NULL;
	
	for(p = L; p != NULL; ant = p, p = p->prox) {
		if(comp(p->info, mat))
			break;
	}
	
	if(p == NULL)
		return L;
	if(ant == NULL)
		L = p->prox;
	else 
		ant->prox = p->prox;
	free(p->info);
	free(p);
	
	return L;
}
