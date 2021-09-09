#include <stdio.h>
#include "lista.h"

int main() {
	
	int resp, valor, ver, resp2;
	
	Lista* l1;
	l1 = lst_cria();
	
	Lista* l2;
	l2 = lst_cria();
	
	
	do {
		printf("\n------------Escolha o que deseja fazer-----------\n");
		printf("|\t1. Inserir novo valor na lista\t\t|\n");
		printf("|\t2. Imprimir a lista\t\t\t|\n");
		printf("|\t3. Verifica se lista estah vazia\t|\n");
		printf("|\t4. Busca elemento na lista\t\t|\n");
		printf("|\t5. Retira elemento da lista\t\t|\n");
		printf("|\t6. Compara listas\t\t\t|\n");
		printf("|\t7. Nada\t\t\t\t\t|\n");
		printf("-------------------------------------------------\n\n");
		scanf("%d%*c", &resp);
		
		switch(resp) {
			case 1:
				printf("Em qual lista deseja inserir? 1 ou 2?");
				scanf("%d", &resp2);
				
				if(resp2 == 1) {
					printf("Digite o valor a ser inserido na lista: ");
					scanf("%d", &valor);
					l1 = lst_insere_ordenado(l1, valor);
				} else if (resp2 == 2) {
					printf("Digite o valor a ser inserido na lista: ");
					scanf("%d", &valor);
					l2 = lst_insere_ordenado(l2, valor);
				} else
					printf("Numero de lista invalido!");
				
				
				break;
				
			case 2:
				printf("Lista 1: ");
				lst_imprime_rec(l1);
				
				printf("Lista 2: ");
				lst_imprime_rec(l2);
				
				break;
				
			case 3:
				if(lst_vazia(l1))
					printf("A lista 1 estah vazia\n");
				else
					printf("A lista 1 nao estah vazia\n");
					
				if(lst_vazia(l2))
					printf("A lista 2 estah vazia\n");
				else
					printf("A lista 2 nao estah vazia\n");
				break;
				
			case 4:
				printf("Em qual lista deseja buscar? 1 ou 2?");
				scanf("%d", &resp2);
				
				if(resp2 == 1) {
					printf("\nDigite o valor que deseja buscar: ");
					scanf("%d", &valor);
				
					if(lst_busca(l1, valor))
						printf("\nValor encontrado na lista");
					else
						printf("\nValor nao encontrado na lista");
				}
				
				 else if(resp2 == 2) {
				 	printf("\nDigite o valor que deseja buscar: ");
					scanf("%d", &valor);
				
					if(lst_busca(l2, valor))
						printf("\nValor encontrado na lista");
					else
						printf("\nValor nao encontrado na lista");
				 }
				
				break;
			case 5:
				printf("De qual lista deseja retirar? 1 ou 2?");
				scanf("%d", &resp2);
				
				if(resp2 == 1) {
					printf("Digite o valor que deseja retirar da lista: ");
					scanf("%d", &valor);
				
					l1 = lst_retira_rec(l1, valor);
				}
				 else if (resp2 == 2) {
				 	printf("Digite o valor que deseja retirar da lista: ");
					scanf("%d", &valor);
				
					l2 = lst_retira_rec(l2, valor);
				 }
				
				break;
				
			case 6:
				if(lst_igual_rec(l1, l2))
					printf("Listas iguais!");
				else
					printf("Listas diferentes!");
				
			default:
				break;
		}
	} while(resp != 7);
	
	lst_libera_rec(l1);
	lst_libera_rec(l2);
	
	return 0;
}
