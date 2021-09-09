#include <stdio.h>
#include "arvorebin.h"

int main() {
	
	int resp, valor;
	
	Arv* Ab = arvbin_criavazia();
	Arv* Ab_temp = arvbin_criavazia();
	
	
	do {
		
		printf("\n________________________________\n");
		printf("1. Inserir elemento na arvore\n");
		printf("2. Ver se pertence a arvore\n");
		printf("3. Imprimir arvore\n");
		printf("4. Verificar altura da arvore\n");
		printf("5. Buscar na arvore\n");
		printf("6. Retirar da arvore\n");
		printf("7. Gravar arvore\n");
		printf("8. Carregar arvore\n");
		printf("9. Nada\n");
		printf("________________________________\n");
		
		scanf("%d", &resp);
		
		switch(resp) {
			case 1:
				printf("\nQual valor deseja inserir? ");
				scanf("%d", &valor);
				Ab = arvbin_insere_ord(Ab, valor);
				break;
				
			case 2:
				printf("Qual valor deseja procurar? ");
				scanf("%d", &valor);
				if(arvbin_pertence(Ab, valor))
					printf("\nO elemento pertence a arvore!");
				else
					printf("\nO elemento nao pertence a arvore!");
				break;
				
			case 3:
				arvbin_imprime_simetrico(Ab);
				
				break;
				
			case 4:
				printf("\nA altura da arvore eh: %d", arvbin_altura(Ab));
				break;
				
			case 5:
				printf("\nQual valor deseja buscar? ");
				scanf("%d", &valor);
				Ab_temp = arvbin_busca(Ab, valor);
				if(Ab_temp)
					printf("\nNumero %d achado na arvore!", valor);
				else
					printf("\nValor %d nao achado na arvore!", valor);
				break;
				
			case 6:
				printf("\nQual valor deseja retirar? ");
				scanf("%d", &valor);
				Ab = arvbin_retira(Ab, valor);
				break;
			
			case 7: ;
				FILE* fp = fopen("Dados.txt", "wt");
				arvbin_grava(Ab, fp);
				fclose(fp);
				break;
			
			case 8: ;
				FILE* fp2 = fopen("Dados.txt", "rt");
				Ab = arvbin_carrega(fp2);
				fclose(fp2);
				break;
				
			default:
				break;
		}
		
	} while(resp != 9);
	
	arvbin_libera(Ab);
	
	return 0;
}
