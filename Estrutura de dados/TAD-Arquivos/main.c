#include <stdio.h>

int main() {
	
	FILE* fp = fopen("Dados.txt", "wt");
	/*int c;
	while((c=fgetc(fp)) != EOF)
		printf("%c", c);
	fclose(fp);*/
	
//	fprintf(fp, "Ola, mundo\tteste\n%d", 123);
	
	fclose(fp);
	return 0;
}
