#include <stdio.h>
#include "pilha.h"

int main() {
	
	int resp;
	float valor;
	
	Pilha* Pi = pilha_cria();
	
	do {
		printf("\n------------Escolha o que deseja fazer-----------\n");
		printf("|\t1. Push na pilha\t\t\t|\n");
		printf("|\t2. Pop na pilha\t\t\t\t|\n");
		printf("|\t3. Imprimir pilha\t\t\t|\n");
		printf("|\t4. Nada\t\t\t\t\t|\n");
		printf("-------------------------------------------------\n\n");
		scanf("%d%*c", &resp);
		
		switch(resp) {
			case 1:
				printf("Qual valor deseja adicionar a pilha? ");
				scanf("%f", &valor);
				pilha_push(Pi, valor);
				break;
			case 2:
				valor = pilha_pop(Pi);
				printf("O valor retirado foi: %.2f", valor);
				break;
			case 3:
				pilha_imprime(Pi);
				break;
			default:
				break;
		}
		
	} while(resp!=4);
	
	
	pilha_libera(Pi);
	return 0;
}
