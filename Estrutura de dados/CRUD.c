#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
	int mat;
	char nome[81];
	char end[121];
	char tel[21];
} Aluno;

Aluno* criar_aluno(void);
void ler_aluno(int mat, Aluno** tab);
void atualizar_aluno(int mat, Aluno** tab);
void deletar_aluno(int mat, Aluno** tab);
void listar_aluno(Aluno** tab);
void menu(Aluno** tab);

int main() {
	
	int i;
	Aluno* tab[100];
	
	for(i = 0; i < 100; i++) {
		tab[i] = NULL;
	}
	
	menu(tab);

	return 0;
}

void menu(Aluno** tab) {
	int escolha, mat, i;
	do {
		printf("\n_____________________________\n");
		printf("\nEscolha o que deseja fazer\n");
		printf("1. Criar aluno");
		printf("\n2. Ler aluno");
		printf("\n3. Atualizar aluno");
		printf("\n4. Deletar aluno");
		printf("\n5. Listar alunos");
		printf("\n6. Sair");
		printf("\n_____________________________\n");
		
		printf("\n\nDigite a opcao: ");
		scanf("%d", &escolha);
		
		switch(escolha) {
			case 1:
				for(i=0;i<100;i++)
        			if(tab[i]==NULL){
            			tab[i]=criar_aluno();
            			break;
					}
			break;
			
			case 2:
				printf("\nDigite a matricula: ");
				scanf("%d", &mat);	
				ler_aluno(mat, tab);
				break;
			
			case 3:
				printf("\nDigite a matricula: ");
				scanf("%d", &mat);
				atualizar_aluno(mat, tab);
				break;
				
			case 4:
				printf("\nDigite a matricula: ");
				scanf("%d", &mat);
				deletar_aluno(mat, tab);
				break;
				
			case 5:
				listar_aluno(tab);
				break;
		}
	} while(escolha != 6);
}

Aluno* criar_aluno() {
	Aluno* Student = (Aluno*)malloc(sizeof(Aluno));
	
	printf("Digite o numero de matricula: ");
	scanf("%d%*c", &Student->mat);
	
	printf("\nDigite o nome: ");
	scanf("%80[^\n]%*c", Student->nome);
	
	printf("\nDigite o endereço: ");
	scanf("%120[^\n]%*c", Student->end);
	
	printf("\nDigite o numero de telefone: ");
	scanf("%20[^\n]%*c", Student->tel);
	
	printf("\nAluno criado com sucesso! :)\n");
	
	return Student;
}

void ler_aluno(int mat, Aluno** tab) {
	int i;
	for(i=0; i<100; i++) {
		if(tab[i]!=NULL)
			if(tab[i]->mat==mat) {
				printf("Aluno: %s\n", tab[i]->nome);
				printf("Matricula: %d\n", tab[i]->mat);
				printf("Endereco: %s\n", tab[i]->end);
				printf("Telefone: %s\n", tab[i]->tel);
			} else {
				printf("\nAluno nao encontrado!\n");
			}		
	}
}

void atualizar_aluno(int mat, Aluno** tab) {
	int i;
	for(i=0; i<100; i++) {
		if(tab[i]!=NULL)
			if(tab[i]->mat==mat) {
				printf("Atualize nome, endereco ou telefone: \n");
				fflush(stdin);
				printf("\nDigite o nome: ");
				scanf("%80[^\n]%*c", tab[i]->nome);
				
				printf("\nDigite o endereço: ");
				scanf("%120[^\n]%*c", tab[i]->end);
				
				printf("\nDigite o numero de telefone: ");
				scanf("%20[^\n]%*c", tab[i]->tel);
				
				printf("\nAluno atualizado com sucesso!\n");
			} else {
				printf("\nAluno nao encontrado!\n");
			}
	}

}

void listar_aluno(Aluno** tab) {
	int i;
	for(i=0; i<100; i++)
		if(tab[i]!=NULL) {
			printf("\n%s ----- %d\n", tab[i]->nome, tab[i]->mat);
		}
}

void deletar_aluno(int mat, Aluno** tab) {
	int i;
	for(i=0; i<100; i++)
		if(tab[i]!=NULL)
			if(tab[i]->mat==mat) {
				tab[i] = NULL;
				free(tab[i]);
			}

}

