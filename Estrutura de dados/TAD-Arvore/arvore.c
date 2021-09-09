// arvore.c

#include <stdlib.h>
#include "arvore.h"

typedef struct arv {
	char info;
	struct arv* sae;
	struct arv* sad;
} Arv;

Arv* arv_criavazia(void) {
	return NULL;
}

Arv* arv_cria(char c, Arv* esq, Arv* dir) {
	Arv* no = (Arv*)malloc(sizeof(Arv));
	
	no->info = c;
	no->sae = esq;
	no->sad = dir;
	
	return no;
}

int arv_vazia(Arv* a) {
	return a==NULL;
}

Arv* arv_libera(Arv* a) {
	if(!arv_vazia(a)) {
		arv_libera(a->sae);
		arv_libera(a->sad);
		
		free(a);
	}
	
	return NULL;
}

int arv_pertence(Arv* a, char c) {
	if(arv_vazia(a))
		return 0;
	else {
		return (arv_pertence(a->sae, c) || arv_pertence(a->sad, c) || a->info == c);
	}
}

void arv_imprime(Arv* a) {
	if(!arv_vazia(a)){
		printf("%c\n", a->info);
		arv_imprime(a->sae);
		arv_imprime(a->sad);
	}
}

