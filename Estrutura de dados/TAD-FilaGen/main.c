#include <stdio.h>
#include <locale.h>
#include "filagen.h"

typedef struct aluno Aluno;
void* registra_aluno();
void imprime(void* val);


int main() {
	
	setlocale(LC_ALL, "");
	
	FilaGen* F = criar_fila();
	int op;
	
	do {
		printf("\n1. Verifica se está vazia\n");
		printf("2. Inserir\n");
		printf("3. Imprimir\n");
		printf("4. Retirar\n");
		printf("5. Sair\n");
		
		scanf("%d", &op);
		
		switch(op) {
			case 1:
				if(fila_vazia(F)) {
					printf("\n====================\n");
					printf(" Fila vazia!\n");
					printf("====================\n");
				}
					
				else {
					printf("\n====================\n");
					printf(" Fila não vazia!\n");
					printf("====================\n");
				}
					
				break;
			case 2:
				fila_insere(F, registra_aluno);
				printf("\n====================\n");
				printf(" Adicionado!\n");
				printf("====================\n");
				break;
			case 3:
				fila_imprime(F, imprime);
				break;
			case 4:
				fila_retira(F);
				printf("\n====================\n");
				printf(" Retirado!\n");
				printf("====================\n");
				break;
		}
		
	} while(op != 5);
	
	fila_libera(F);
	
	return 0;
}

typedef struct aluno {
	int mat;
	char nome[101];
	char email[51];
} Aluno;

void* registra_aluno() {
	Aluno* alu = (Aluno*)malloc(sizeof(Aluno));
	printf("Digite a matrícula do aluno: ");
	scanf("%d%*c", &alu->mat);
	printf("Digite o nome do aluno: ");
	scanf("%101[^\n]", &alu->nome);
	fflush(stdin);
	printf("Digite o email do aluno: ");
	scanf("%51[^\n]", &alu->email);
	
	return (void*)alu;
}

void imprime(void* val) {
	Aluno* alu = (Aluno*)val;
	printf("\n============================\n");
	printf(" Matrícula: %d\n", alu->mat);
	printf(" Nome: %s\n", alu->nome);
	printf(" Email: %s\n", alu->email);
	printf("============================\n");
}
