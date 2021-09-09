#include <stdio.h>
#include "lista.h"

int main() {
	
	int resp, valor, ver;
	
	Lista* l1;
	l1 = lst_cria();
	
	Lista* l2;
	
	
	do {
		printf("\n------------Escolha o que deseja fazer-----------\n");
		printf("|\t1. Inserir novo valor na lista\t\t|\n");
		printf("|\t2. Imprimir a lista\t\t\t|\n");
		printf("|\t3. Verifica se lista estah vazia\t|\n");
		printf("|\t4. Busca elemento na lista\t\t|\n");
		printf("|\t5. Retira elemento da lista\t\t|\n");
		printf("|\t6. Nada\t\t\t\t\t|\n");
		printf("-------------------------------------------------\n\n");
		scanf("%d%*c", &resp);
		
		switch(resp) {
			case 1:
				printf("Digite o valor a ser inserido na lista: ");
				scanf("%d", &valor);
				l = lst_insere(l, valor);
				break;
				
			case 2:
				lst_imprime(l);
				break;
				
			case 3:
				if(lst_vazia(l))
					printf("A lista estah vazia\n");
				else
					printf("A lista nao estah vazia\n");
				break;
			case 4:
				printf("\nDigite o valor que deseja buscar: ");
				scanf("%d", &valor);
				
				if(lst_busca(l, valor))
					printf("\nValor encontrado na lista");
				else
					printf("\nValor nao encontrado na lista");
				break;
			case 5:
				printf("Digite o valor que deseja retirar da lista: ");
				scanf("%d", &valor);
				
				l = lst_retira(l, valor);
				
				break;
				
			default:
				break;
		}
	} while(resp != 6);
	
	lst_libera(l);
	
	return 0;
}
