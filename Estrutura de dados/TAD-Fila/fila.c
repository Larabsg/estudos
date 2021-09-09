#include <stdlib.h>
#include "fila.h"

typedef struct lista {
	float info;
	struct lista* prox;
} Lista;

typedef struct fila {
	Lista* inicio;
	Lista* fim;
} Fila;


Fila* fila_cria() {
	Fila* f = (Lista*)malloc(sizeof(Fila));
	
	f->inicio=f->fim=NULL;
	
	return f;
}

int fila_vazia(Fila* f) {
	return(f->inicio==NULL);
}

void fila_insere(Fila* f, float valor) {
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = valor;
	novo->prox=NULL;
	if(f->fim!=NULL) {
		f->fim->prox=novo;		
	}
	else {
		f->inicio=novo;
	}
	f->fim=novo;
}

void fila_imprime(Fila* f) {
	Lista* t = f->inicio;
	while(t!=NULL) {
		printf("Info: %.2f\n", t->info);
		t = t->prox;
	}
}

float fila_retira(Fila* f) {
	Lista* temp = f->inicio;
	float v;
	
	if(fila_vazia(f)) 
		printf("Fila vazia!");
	else {
		v = temp->info;
		f->inicio = temp->prox;
		free(temp);
	}
	if(fila_vazia(f)) {
		f->fim = NULL;
	}	
	return v;
}

void fila_libera(Fila* f) {
	Lista* p = f->inicio;
	
	while(p!=NULL) {
		Lista* temp = p->prox;
		free(p);
		p = temp;
		
	}
	
	free(f);
}
