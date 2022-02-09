#include <stdio.h>
#include <string.h>

void main(){
	printf("***CONTADOR DE 1's***\n\n");

	char frase[100];
	int contador = 0;

	printf("Insira o texto para realizar a contagem de 1's: ");
	fgets(frase, 100, stdin);

	for(int i = 0; i < strlen(frase); i++){
		if(frase[i] == '1'){
			++contador;
		}
	}

	printf("A quantidade de 1's no texto inserido eh de: %d.\n", contador);
}