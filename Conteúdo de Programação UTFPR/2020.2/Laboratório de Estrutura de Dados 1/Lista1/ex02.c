#include <stdio.h>

void main(){
	char frase[100];
	int cont = 0;
	

	printf("Insira uma frase/palavra para ser contada a quantidade de caracteres: ");
	fgets(frase, 100, stdin);

	while(frase[cont] != '\n'){
		cont++;
	}

	printf("A frase/palavra inserida possui %d caracteres.\n", cont);


}