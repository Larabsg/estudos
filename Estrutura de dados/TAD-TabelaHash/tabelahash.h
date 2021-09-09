// Tabela Hash

static int hash(int mat);
typedef struct aluno Aluno;
Aluno* hsh_busca(Aluno** tab, int mat);
Aluno* hsh_insere(Aluno** tab, int mat, char* nome, char* turma, char* email);
void hsh_grava(FILE* fp, Aluno** tab);
Aluno** hsh_carrega(FILE * fp);


#ifndef tabelahash_c
	#define tabelahash_c
	#include "tabelahash.c"
#endif
