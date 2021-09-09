/*TAD: lista de inteiros*/

typedef struct lista Lista;

Lista* lst_cria (void);

void lst_libera (Lista* l);

Lista* lst_insere (Lista* l, int valor);

int lst_vazia (Lista* l);

void lst_imprime (Lista* l);

Lista* lst_busca(Lista* l, int valor);

Lista* lst_retira(Lista* l, int valor);

Lista* lst_insere_ordenado(Lista* l, int valor);

Lista* lst_igual(Lista* l1, Lista* l2);

/* Funções recursivas - Aula 22 */

void lst_imprime_rec(Lista* l);
Lista* lst_retira_rec(Lista* l, int valor);
void lst_libera_rec(Lista* l);
int lst_igual_rec(Lista* l1, Lista* l2);

/* Funções Lista Circular Duplamente Encadeadas - Aula 23 */
typedef struct listaDupla ListaDupla;

ListaDupla* lstdupla_cria();
int lstdupla_vazia(ListaDupla* L);
void lstdupla_imprime(ListaDupla* L);
void lstdupla_libera(ListaDupla* L);
ListaDupla* lstdupla_insere(ListaDupla* L, int valor);
ListaDupla* lstdupla_retira(ListaDupla* L, int valor);

#ifndef lista_c
	#define lista_c
	#include "lista.c"
#endif
