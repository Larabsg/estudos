/* Funções Lista Circular Duplamente Encadeadas - Aula 23 */
typedef struct listaDupla ListaDupla;

ListaDupla* lstdupla_cria();
int lstdupla_vazia(ListaDupla* L);
void lstdupla_imprime(ListaDupla* L);
void lstdupla_libera(ListaDupla* L);
ListaDupla* lstdupla_insere(ListaDupla* L, int valor);
ListaDupla* lstdupla_retira(ListaDupla* L, int valor);

#ifndef lista_dupla_c
	#define lista_dupla_c
	#include "lista_dupla.c"
#endif
