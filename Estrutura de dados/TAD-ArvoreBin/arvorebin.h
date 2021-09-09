/*TAD - Arvore Binaria*/

typedef struct arv Arv;

Arv* arvbin_criavazia(void);
int arvbin_vazia(Arv* a);
Arv* arvbin_insere_ord(Arv* a, int valor);
Arv* arvbin_libera(Arv* a);
int arvbin_pertence(Arv* a, int valor);
void arvbin_imprime_simetrico(Arv* a);
int arvbin_altura(Arv* a);
Arv* arvbin_busca(Arv* a, int valor);
Arv* arvbin_retira(Arv* a, int valor);
static int comp(int a, int b);

/*Aula 29 - Arquivos*/

void arvbin_grava(Arv* a, FILE* fp);
Arv* arvbin_carrega(FILE* fp);

#ifndef arvorebin_c
	#define arvorebin_c
	#include "arvorebin.c"
#endif
