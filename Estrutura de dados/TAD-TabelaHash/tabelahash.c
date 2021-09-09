#include <stdlib.h>
#include <string.h>
#include "tabelahash.h"

static int hash(int mat) {
	return mat%50;
}

typedef struct aluno {
	int mat;
	char nome[101];
	char email[51];
	char turma[21];
} Aluno;

Aluno* hsh_busca(Aluno** tab, int mat) {
	int h = hash(mat);
	while(tab[h] != NULL) {
		if(tab[h]->mat == mat)
			return tab[h];	
		h = (h+1) % 50;
	}
	
	return NULL;
}

Aluno* hsh_insere(Aluno** tab, int mat, char* nome, char* turma, char* email) {
	int h = hash(mat);
	while(tab[h] != NULL) {
		if(tab[h]->mat == mat)
			break;
		h = (h+1) % 50;
	}
	
	if(tab[h]==NULL) {
		tab[h] = (Aluno*)malloc(sizeof(Aluno));
		tab[h]->mat = mat;
	}
	
	strcpy(tab[h]->nome, nome);
	strcpy(tab[h]->email, email);
	strcpy(tab[h]->turma, turma);
	
	return tab[h];
}

void hsh_grava(FILE* fp, Aluno** tab) {
	int i;
	char aux = '0';
	for(i=0; i<50;i++) {
		if(tab[i] != NULL) {
			if(aux!='1') {
				fprintf(fp, "\n");
				aux='1';
			}
			fprintf(fp, "%d\n", tab[i]->mat);
			fprintf(fp, "%s\n", tab[i]->nome);
			fprintf(fp, "%s\n", tab[i]->turma);
			fprintf(fp, "%s\n", tab[i]->email);
			free(tab[i]);
		}
	}
	
	free(tab);
}

Aluno** hsh_carrega(FILE * fp) {
	Aluno** tab = (Aluno*)malloc(50*sizeof(Aluno*));
	Aluno* aux;
	char linha[151];
	int i;
	for(i = 0; fgets(linha, 151, fp) != NULL; i++) 
		switch(i%4) {
			case 0:
				aux = (Aluno*)malloc(sizeof(Aluno));
				sscanf(linha, "%d", &aux->mat);
				break;
			case 1:
				sscanf(linha, "%s", aux->nome);
				break;
			case 2:
				sscanf(linha, "%s", aux->turma);
				break;
			case 3:
				sscanf(linha, "%s", aux->email);
				tab[hash(aux->mat)] = aux;
				free(aux);
				break;
		}
}

