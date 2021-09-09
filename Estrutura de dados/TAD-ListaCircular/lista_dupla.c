#include <stdlib.h>
#include "lista_dupla.h"

/* Funções Lista Circular - Aula 23*/

typedef struct listaDupla {
	int info;
	struct listaDupla* prox;
	struct listaDupla* ant;
} ListaDupla;

ListaDupla* lstdupla_cria() {
	return NULL;
}
int lstdupla_vazia(ListaDupla* L) {
	return (L==NULL);
}
void lstdupla_imprime(ListaDupla* L) {
	ListaDupla* p = L;
	if(!lstdupla_vazia(L)) {
		do {
			printf("|\tInfo = %d\t|\n", p->info);
			p = p->prox;
		} while (p!=L);
	}
}
void lstdupla_libera(ListaDupla* L) {
	ListaDupla* p = L;
	if(!lstdupla_vazia(L)) {
		while(p!=NULL) {
			ListaDupla* t = p->prox;
			free(p);
			p = t;
		}
	}
}
ListaDupla* lstdupla_insere(ListaDupla* L, int valor) {
	ListaDupla* p = L;
	ListaDupla* novo = (ListaDupla*)malloc(sizeof(ListaDupla));
	novo->info = valor;
	
	if(!lstdupla_vazia(L)) {
		novo->prox = p;
		novo->ant = p->ant;
		p->ant = novo;
		novo->ant->prox = novo;
		
	} else {
		novo->ant = novo;
		novo->prox = novo;
	}
	
	return novo;
}
ListaDupla* lstdupla_retira(ListaDupla* L, int valor) {
	ListaDupla* p = L;
	if(!lstdupla_vazia(L)) {
		do {
			if(p->info == valor) {
				p->ant->prox = p->prox;
				p->prox->ant = p->ant;
				
				if(p == L) 
					L = p->prox;
				free(p);
				break;
			}
			else {
				p = p->prox;
			}
		} while(p!=L);
	}
	
	return L;
}

