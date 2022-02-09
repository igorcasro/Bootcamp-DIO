#include <stdio.h>

void main(){
	char palavra[100];
	int contador = 0;
	int i = 0;

	printf("Insira uma palavra: ");
	scanf("%s", palavra);

	while(palavra[i] != '\0'){
		++contador;
		++i;
	}

	while(contador >= 0){
		printf("%c", palavra[contador]);
		--contador;
	}

	printf("\n");

}