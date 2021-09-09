#include <stdio.h>
#include <locale.h>
#include "pilhagen.h"

void* registra_aluno();
void imprime(void* val);

int main() {
	
	setlocale(LC_ALL, "");
	
	PilhaGen* P = pilhaGen_cria();
	int op;
	
	do {
		printf("\n1. Push\n");
		printf("2. Pop\n");
		printf("3. Imprimir\n");
		printf("4. Verifica pilha vazia\n");
		printf("5. Sair\n");
		
		scanf("%d", &op);
		
		switch(op) {
			case 1:
				pilhaGen_push(P, registra_aluno);
				printf("\nAdicionado!\n");
				break;
			case 2:
				pilhaGen_pop(P);
				printf("\nRetirado!\n");
				break;
			case 3:
				pilhaGen_imprime(P, imprime);
				break;
			case 4:
				if(!(pilhaGen_vazia(P)))
					printf("\nPilha não está vazia!\n");
				else 
					printf("\nPilha vazia!\n");
				break;
		}
		
	} while(op != 5);
	
	return 0;
}

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
	printf("\nMatrícula: %d\n", alu->mat);
	printf("Nome: %s\n", alu->nome);
	printf("Email: %s\n", alu->email);
}
