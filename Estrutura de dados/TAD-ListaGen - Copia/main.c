#include <stdio.h>
#include <locale.h>
#include "listagen.h"

void imprime_aluno(void* vals);
int compara_aluno(void* alu, void* mat);

int main() {
	
	setlocale(LC_ALL, "");
	
	ListaGen* LG = lgen_cria();
	
	int op, mat;
	char nome[101];
	char email[51];
	
	do {
		
		printf("\n _______________________________\n");
		printf("|\t1. Inserir aluno\t|\n");
		printf("|\t2. Imprimir lista\t|\n");
		printf("|\t3. Verifica lista vazia\t|\n");
		printf("|\t4. Buscar na lista\t|\n");
		printf("|\t5. Excluir da lista\t|\n");
		printf("|\t6. Sair\t\t\t|\n");
		printf("|_______________________________|\n");
		
		scanf("%d", &op);
		
		switch(op) {
			case 1:
				
				printf("Digite a matrícula: ");
				scanf("%d%*c", &mat);
				printf("Digite o nome do aluno: ");
				scanf("%101[^\n]%*c", &nome);
				printf("Digite o email do aluno: ");
				
				scanf("%51[^\n]", &email);
				
				Aluno* stu = registra_aluno(mat, nome, email);
				LG = lgen_insere(LG, stu);
				printf("\nAluno inserido!");
				
				break;
			case 2:
				
				lgen_imprime(LG, imprime_aluno);
				break;
			case 3:
				
				if(lgen_vazia(LG))
					printf("\nLista vazia!\n");
				else
					printf("\nLista não está vazia!\n");
				break;
			case 4:
				printf("Digite o número de matrícula que deseja buscar: ");
				scanf("%d", &mat);
				Aluno* busca = (Aluno*)lgen_busca(LG, compara_aluno, mat);
				if(busca == NULL)
					printf("\nAluno não encontrado!");
				else {
					printf("\nAluno encontrado!\n");
					imprime_aluno(busca);
				}
				break;
			case 5:
				printf("Digite a matrícula que deseja excluir: ");
				scanf("%d", &mat);
				LG = lgen_exclui(LG, compara_aluno, mat);
				printf("\nAluno excluído!");
				break;
			default:
				break;
		}
		
	} while(op != 6);
	
	return 0;
}

void imprime_aluno(void* vals) {
	Aluno* alun = (Aluno*)vals;
	printf("\n_____________________________\n");
	printf("Matrícula: %d\n", alun->mat);
	printf("Nome: %s\n", alun->nome);
	printf("Email: %s\n", alun->email);
	printf("______________________________\n");
}

int compara_aluno(void* alu, void* mat) {
	Aluno* aluno = (Aluno*)alu;
	int matricula = (int*)mat;
	return aluno->mat == matricula;
}
