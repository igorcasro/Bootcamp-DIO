#include <stdio.h>

void main(){
	char nome[100];

	printf("Insira seu nome: ");
	scanf("%s", nome);

	if(nome[0] == 'a' || nome[0] == 'A'){
		printf("Bom dia, %s.\n", nome);
	}

}