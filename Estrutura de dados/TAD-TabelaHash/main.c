#include <stdio.h>
#include "tabelahash.h"

int main() {
	
	int i, resp;
	Aluno* tab[50];
	
	
	
	for(i=0; i< 50; i++) {
		tab[i] = NULL;
	}
	
	hsh_insere(tab, 1, "Lara", "A", "larabsg18");
	
	
	
	do {
		printf("1. Buscar\n");
		printf("2. Gravar\n");
		printf("3. Carregar\n");
		printf("4. Sair\n");
		
		scanf("%d", &resp);
		
		switch(resp) {
			case 1:
				
				printf("Qual matricula deseja procurar? ");
				scanf("%d", &resp);
				Aluno* t = hsh_busca(tab, resp);
	
				if(t != NULL) {
					printf("Achei!\n");
				} else {
					printf("Nao achei!\n");
				}
				break;
			case 2: ;
				FILE* fp = fopen("Dados_Hash.txt", "wt");
				hsh_grava(fp, tab);
				fclose(fp);
				break;
			case 3: ;
				FILE* fp2 = fopen("Dados_Hash.txt", "rt");
				hsh_carrega(fp2);
				fclose(fp2);
				break;
			default:
				break;
		}
		
	} while(resp != 4);
	
	return 0;
}
