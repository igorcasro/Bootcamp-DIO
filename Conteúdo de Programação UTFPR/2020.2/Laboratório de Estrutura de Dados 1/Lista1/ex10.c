#include <stdio.h>
#include <string.h>

void main(){
	printf("***REVERSOR DE PALAVRAS***\n\n");

	char palavra[100];

	printf("Insira uma palavra: ");
	fgets(palavra, 100, stdin);
	setbuf(stdin, NULL);

	int i = strlen(palavra) - 1;

	printf("\nEssa palavra de tras para frente fica: ");

	for(i; i >= 0; i--){
		printf("%c", palavra[i]);
	}

	printf("\n");

}