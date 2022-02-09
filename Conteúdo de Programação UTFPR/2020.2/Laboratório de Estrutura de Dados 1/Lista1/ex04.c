#include <stdio.h>

void main(){
	char nome[20];

	printf("Insira seu nome: ");
	fgets(nome, 20, stdin);

	for(int i = 0; i < 4; i++){
		printf("%c", nome[i]);
	}

	printf("\n");

}