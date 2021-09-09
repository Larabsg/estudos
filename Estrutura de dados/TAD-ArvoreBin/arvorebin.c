#include <stdlib.h>
#include "arvorebin.h"

typedef struct arv {
	int info;
	struct arv* sae;
	struct arv* sad;
} Arv;

Arv* arvbin_criavazia(void) {
	return NULL;
}

int arvbin_vazia(Arv* a) {
	return (a == NULL);
}

Arv* arvbin_insere_ord(Arv* a, int valor) {
	if(arvbin_vazia(a)) {
		a = (Arv*)malloc(sizeof(Arv));
		a->info = valor;
		a->sad = NULL;
		a->sae = NULL;
	} else {
		if(valor < a->info) {
			a->sae = arvbin_insere_ord(a->sae, valor);
		}	
		else {
			a->sad = arvbin_insere_ord(a->sad, valor);
		}		
	}	
	return a;
}

Arv* arvbin_libera(Arv* a) {
	if(!arvbin_vazia(a)) {
		arvbin_libera(a->sae);
		arvbin_libera(a->sad);
		free(a);
	}
	
	return NULL;
}

int arvbin_pertence(Arv* a, int valor) {
	if(arvbin_vazia(a))
		return 0;
	else {
		return (arvbin_pertence(a->sae, valor) || arvbin_pertence(a->sad, valor) || a->info == valor);
	}
}

void arvbin_imprime_simetrico(Arv* a) {
	if(!arvbin_vazia(a)) {
		arvbin_imprime_simetrico(a->sae);
		printf("|%d|\n", a->info);
		arvbin_imprime_simetrico(a->sad);
	}
}

static int comp(int a, int b) {
	return (a>b)?a:b;
}

int arvbin_altura(Arv* a) {
	if(arvbin_vazia(a))
		return -1;
	else 
		return 1 + comp(arvbin_altura(a->sae), arvbin_altura(a->sad));
}

Arv* arvbin_busca(Arv* a, int valor) {
	if(!arvbin_vazia(a)) {
		if(a->info > valor) {
			return arvbin_busca(a->sae, valor);
		} else if (a->info < valor) {
			return arvbin_busca(a->sad, valor);
		}
		
		return a;
	} else {
		return NULL;
	}
}

Arv* arvbin_retira(Arv* a, int valor) {
	if(a == NULL) 
		return NULL;
	else if(a->info > valor)
		a->sae = arvbin_retira(a->sae, valor);
	else if(a->info < valor)
		a->sad = arvbin_retira(a->sad, valor);
	else {
		if(a->sae == NULL && a->sad == NULL) {
			free(a);
			a = NULL;
		}
		else {
			if(a->sae == NULL) {
				Arv* temp = a;
				a = a->sad;
				free(temp);
			}
			else {
				if(a->sad == NULL) {
					Arv* temp = a;
					a = a->sad;
					free(temp);
				}
				else {
					Arv* temp = a->sae;
					while(temp->sad != NULL) {
						temp = temp->sad;
					}
					a->info = temp->info;
					temp->info = valor;
					a->sae = arvbin_retira(a->sae, valor);
				}
			}
		}
	return a;
	}
}

void arvbin_grava(Arv* a, FILE* fp) {
	if(!arvbin_vazia(a)) {
		arvbin_grava(a->sae, fp);
		fprintf(fp, "%d\n", a->info);
		arvbin_grava(a->sad, fp);		
	}
}

Arv* arvbin_carrega(FILE* fp) {
	
	Arv* traz_arv = arvbin_criavazia();
	int valor, n;
	char linha[121];
	while(fgets(linha, 121, fp) != NULL) {
		int n = sscanf(linha, "%d", &valor);
		traz_arv = arvbin_insere_ord(traz_arv, valor);
	}
	
	return traz_arv;
}
