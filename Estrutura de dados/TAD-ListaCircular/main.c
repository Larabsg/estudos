#include <stdio.h>
#include "lista_dupla.h"

int main() {
	
	int resp, valor, ver, resp2;
	
	ListaDupla* l1;
	l1 = lstdupla_cria();
	
	ListaDupla* l2;
	l2 = lstdupla_cria();
	
	
	do {
		printf("\n------------Escolha o que deseja fazer-----------\n");
		printf("|\t1. Inserir novo valor na lista\t\t|\n");
		printf("|\t2. Imprimir a lista\t\t\t|\n");
		printf("|\t3. Verifica se lista estah vazia\t|\n");
		printf("|\t4. Retira elemento da lista\t\t|\n");
		printf("|\t5. Nada\t\t\t\t\t|\n");
		printf("-------------------------------------------------\n\n");
		scanf("%d%*c", &resp);
		
		switch(resp) {
			case 1:
				printf("Em qual lista deseja inserir? 1 ou 2?");
				scanf("%d", &resp2);
				
				if(resp2 == 1) {
					printf("Digite o valor a ser inserido na lista: ");
					scanf("%d", &valor);
					l1 = lstdupla_insere(l1, valor);
				} else if (resp2 == 2) {
					printf("Digite o valor a ser inserido na lista: ");
					scanf("%d", &valor);
					l2 = lstdupla_insere(l2, valor);
				} else
					printf("Numero de lista invalido!");
				
				
				break;
				
			case 2:
				printf("Lista 1: \n\n");
				lstdupla_imprime(l1);
				
				printf("\n\nLista 2: \n\n");
				lstdupla_imprime(l2);
				
				break;
				
			case 3:
				if(lstdupla_vazia(l1))
					printf("A lista 1 estah vazia\n");
				else
					printf("A lista 1 nao estah vazia\n");
					
				if(lstdupla_vazia(l2))
					printf("A lista 2 estah vazia\n");
				else
					printf("A lista 2 nao estah vazia\n");
				break;
				
			case 4:
				printf("De qual lista deseja retirar? 1 ou 2?");
				scanf("%d", &resp2);
				
				if(resp2 == 1) {
					printf("Digite o valor que deseja retirar da lista: ");
					scanf("%d", &valor);
				
					l1 = lstdupla_retira(l1, valor);
				}
				 else if (resp2 == 2) {
				 	printf("Digite o valor que deseja retirar da lista: ");
					scanf("%d", &valor);
				
					l2 = lstdupla_retira(l2, valor);
				 }
				
				break;
				
			default:
				break;
		}
	} while(resp != 5);
	
	lstdupla_libera(l1);
	lstdupla_libera(l2);
	
	return 0;
}
