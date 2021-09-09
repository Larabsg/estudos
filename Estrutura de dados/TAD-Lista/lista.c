#include <stdlib.h>
#include "lista.h"

typedef struct lista {
	int info;
	struct lista* prox;
} Lista;

Lista* lst_cria (void) {
	return NULL;
}

void lst_libera (Lista* l) {
	Lista* p = l;
	
	while(p != NULL) {
		Lista* t = p->prox;
		free(p);
		p = t;
	}
}

Lista* lst_insere (Lista* l, int valor) {
	Lista* nHead = (Lista*)malloc(sizeof(Lista));
	nHead->info = valor;
	nHead->prox = l;
	
	return nHead;
}

Lista* lst_busca(Lista* l, int valor) {
	Lista* p;
	
	for(p=l; p!= NULL; p= p->prox) {
		if(p->info = valor) {
			return p;
		}
	}
	
	return NULL;
}

Lista* lst_retira(Lista* l, int valor) {
	Lista* pt = l;       
	Lista* ant = NULL; 
	
	while(pt->info != valor && pt!= NULL) { 
		ant = pt;
		pt = pt->prox;
	}
	
	if(pt == NULL)     
		return l;
		
	if(ant == NULL)
		l = pt->prox;
	else
		ant->prox = pt->prox;
	
	free(pt);
	
	return l;
}

int lst_vazia (Lista* l) {
	return (l == NULL);
}

void lst_imprime (Lista* l) {
	Lista* i;
	printf("\n---------Lista-----------\n");
	for(i=l;i!=NULL;i=i->prox) {
		printf("|\tInfo = %d\t|\n", i->info);
	}
	printf("-------------------------\n");
}

Lista* lst_insere_ordenado(Lista* l, int valor) {
	
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	Lista* ant = NULL; //anterior
	Lista* p = l; //percorre
	novo->info = valor;
	
	while(p != NULL && p->info < valor) {
		ant = p;
		p = p->prox;
	}
	
	if (ant == NULL) {
		novo->prox = l;
		l = novo;
	}
	else {
		novo->prox = ant->prox;
		ant->prox = novo;
	}
	
	return l;
}

Lista* lst_igual(Lista* l1, Lista* l2) {
	
	Lista* p1;
	Lista* p2;
	
	for(p1 = l1, p2 = l2; p1 != NULL && p2 != NULL; p1 = p1->prox, p2 = p2->prox) {
		if (p1 != p2) {
			return 0;
		} else
			return 1;
	}
}
