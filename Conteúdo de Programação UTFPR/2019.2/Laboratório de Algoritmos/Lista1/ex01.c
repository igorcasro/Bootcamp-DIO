#include <stdio.h>

void main(){
	char frase[100];

	int contador = 0;
	int i = 0;

	printf("Insira uma string: ");
	scanf("%s", frase);

	while(frase[i] != '\0'){
		++contador;
		++i;
	}

	printf("O tamanho da sua string eh: %d\n", contador);

}