#include <stdio.h>

void main(){
	char nome[20];
	int contador = 0;

	printf("Insira seu nome: ");
	fgets(nome, 20, stdin);

	while(nome[contador] != '\0'){
		++contador;
	}

	printf("Seu nome possui %d letras.\n", (contador - 1));

}