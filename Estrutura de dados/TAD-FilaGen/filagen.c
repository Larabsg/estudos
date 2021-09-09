#include <stdlib.h>
#include "filagen.h"

typedef struct listagen {
	void* info;
	struct listagen* prox;
} ListaGen;

typedef struct filagen {
	ListaGen* inicio;
	ListaGen* fim;
} FilaGen;

FilaGen* criar_fila() {
	FilaGen* new_fila = (FilaGen*)malloc(sizeof(FilaGen));
	new_fila->fim = new_fila->inicio = NULL;
	
	return new_fila;
}

int fila_vazia(FilaGen* fila) {
	return fila->inicio == NULL;
}

void fila_insere(FilaGen* fila, void*(*registra)(void)) {
	ListaGen* novo = (ListaGen*)malloc(sizeof(ListaGen));
	
	novo->info = registra();
	novo->prox = NULL;
	
	if(fila->fim != NULL) {
		fila->fim->prox = novo;
	}
	else {
		fila->inicio = novo;
	}
	
	fila->fim = novo;		
}
void fila_imprime(FilaGen* fila, void(*imprime)(void*)) {
	ListaGen* temp;
	for(temp = fila->inicio; temp != NULL; temp = temp->prox) {
		imprime(temp->info);
	}
}
FilaGen* fila_retira(FilaGen* fila) {
	ListaGen* temp;
	void* v;
	
	if(fila_vazia(fila)) {
		return NULL;
	}
	
	temp = fila->inicio;
	v = temp->info;
	fila->inicio = temp->prox;
	
	if(fila_vazia(fila)) {
		fila->fim = NULL;
	}
	
	free(temp);
	return v;
}

void fila_libera(FilaGen* fila) {
	ListaGen* temp = fila->inicio;
	
	while(temp!=NULL) {
		ListaGen* p = temp->prox;
		free(temp->info);
		free(temp);
		temp = p;
	}
	
	free(fila);
}
