#include <stdio.h>
#include "arvore.h"

int main() {
	
	int resp;
	char carac;
	
	Arv* Ab = arv_cria('a', 
				arv_cria('b', 
					arv_criavazia(),
					arv_cria('d', arv_criavazia(), arv_criavazia())
					),
				arv_cria('c',
					arv_cria('e', arv_criavazia(), arv_criavazia()),
					arv_cria('f', arv_criavazia(), arv_criavazia())
					)
					);
	
	do {
		
		printf("\n___________________________\n");
		printf("1. Imprimir arvore\n");
		printf("2. Ver se pertence a arvore\n");
		printf("3. Nada\n");
		printf("___________________________\n");
		
		scanf("%d%*c", &resp);
		
		switch(resp) {
			case 1:
				arv_imprime(Ab);
				break;
			case 2:
				printf("Qual caracter deseja procurar? ");
				scanf("%s", &carac);
				if(arv_pertence(Ab, carac))
					printf("\nO elemento pertence a arvore!");
				break;
			default:
				break;
		}
		
	} while(resp != 3);
	
	arv_libera(Ab);
	
	return 0;
}
