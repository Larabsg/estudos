#include <stdio.h>
#include "fila.h"

int main() {
	
	float valor;
	int resp;
	
	Fila* f = (Fila*)malloc(sizeof(Fila));
	f = fila_cria();
	
	do {
		
		printf("\n _______________________________\n");
		printf("|\t1. Insere na fila\t|\n");
		printf("|\t2. Imprime fila\t\t|\n");
		printf("|\t3. Retira da fila\t|\n");
		printf("|\t4. Nada\t\t\t|\n");
		printf("|_______________________________|\n");
		
		scanf("%d", &resp);
		
		switch(resp) {
			case 1:
				printf("Qual valor deseja inserir? ");
				scanf("%f", &valor);
				fila_insere(f, valor);
				break;
			case 2:
				fila_imprime(f);
				break;
			case 3:
				fila_retira(f);
				break;
			default:
				break;
		}
		
	} while (resp!=4);
	
	fila_libera(f);
	return 0;
}
