#include <stdio.h>

void idade(void) {
	int i;
	printf("Em que ano voce nasceu? ");
	scanf("%d", &i);
	printf("Voce fez ou fara %d anos esse ano", 2021-i);
}

int main() {
	
	void(*age)(void) = &idade;
	
	age();
	
	return 0;
}
