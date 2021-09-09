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
	
	Lista* novoNum = (Lista*)malloc(sizeof(Lista));
	novoNum->info = valor;
	
	Lista* ant = NULL; //anterior
	Lista* p = l; //percorre
	
	while(p != NULL && p->info < valor) {
		ant = p;
		p = p->prox;
	}
	
	if (ant == NULL) {
		novoNum->prox = l;
		l = novoNum;
	}
	else {
		novoNum->prox = ant->prox;
		ant->prox = novoNum;
	}
	
	return l;
}

Lista* lst_igual(Lista* l1, Lista* l2) {
	
	Lista* pot1;
	Lista* pot2;
	
	for(pot1 = l1, pot2 = l2; pot1 != NULL && pot2 != NULL; pot1 = pot1->prox, pot2 = pot2->prox) {
		if (pot1->info != pot2->info) {
			return 0;
		}	
	}
	
	return pot1 == pot2;
}

/* Funções recursivas - Aula 22 */

void lst_imprime_rec(Lista* l) {
	if(!lst_vazia(l)) {
		printf("\n|\tInfo = %d\t|\n", l->info);
		lst_imprime_rec(l->prox);
	}
}

Lista* lst_retira_rec(Lista* l, int valor) {
	if(!lst_vazia(l)) {
		if(l->info == valor) {
			Lista* t = l;
			l = l->prox;
			free(t);
		}
		
		else {
			l->prox = lst_retira_rec(l->prox, valor);
		}
	}
	
	return l;
}
void lst_libera_rec(Lista* l) {
	if(!lst_vazia(l)) {
		lst_libera_rec(l->prox);
		free(l);
	}
}
int lst_igual_rec(Lista* l1, Lista* l2) {
	if(l1 == NULL && l2 == NULL)
		return 1;
	else if(l1 == NULL || l2 == NULL) 
		return 0;
	else
		return (l1->info == l2->info && lst_igual_rec(l1->prox, l2->prox));
}

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

