/* Estruturas disponíveis*/

struct lista{
	int info;
	struct lista* prox;
};


/* Função cria
** Retorna NULL para inicializar o ponteiro para uma lista vazia.
*/

Lista* lst_cria(){
	
}

/* Função lista vazia
** Returna 1 em caso lista vazia, retorna 0 caso contenha algum elemento.
*/

int lst_vazia(Lista* L){
	
}

/* Função imprime
** Imprime na tela todos os elementos da lista.
*/

void lst_imprime(Lista* L){
	
}

/* Função insere
**  Insere um novo elemento, retornando o endereço da nova cabeça da lista.
*/

Lista* lst_insere(Lista* L, int valor){
	
}

/* Função busca
** Retorna o endereço de um elemento encontrado na lista. 
** Retorna NULL caso não encontre.
*/

Lista* lst_busca(Lista* L, int valor){
	
}

/* Função retira
** Retira um elemento e retorna o endereço da cabeça da lista sem o elemento.
*/

Lista* lst_retira(Lista* L, int valor){
	
}

/* Função libera
** Libera a memória utilizada pela lista.
*/

void lst_libera(Lista* L){
	
}

/* Função Insere Ordenado
** Insere um novo elemento na lista mantendo-a ordenada.
*/

void lst_insere_ordenado(Lista* L, int valor){
	
}

/* Função Listas Iguais
** Verifica se duas listas são iguais.
*/

void lst_igual(Lista* L1, Lista*L2){
	
}

/* Função Imprime Recursivo
** Imprime os valores da lista utilizando um método recursivo.
*/

void lst_imprime_rec(Lista* L){
	
}

/* Função Retira Recursivo
** Retira um elemento da lista utilizando um método recursivo.
*/

void lst_retira_rec(Lista* L, int valor){
	
}

/* Função Libera Recursivo
** Libera a memória de uma lista utilizando um método recursivo.
*/

void lst_libera_rec(Lista* L, int valor){
	
}

/* Função Listas Iguais recursivo
** Verifica se duas listas são iguais utilizando um método recursivo.
*/

void lst_igual_rec(Lista* L1, Lista* L2){
	
}
