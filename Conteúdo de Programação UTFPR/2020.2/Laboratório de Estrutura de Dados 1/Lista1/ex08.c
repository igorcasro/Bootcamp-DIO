#include <stdio.h>
#include <string.h>

void main(){
	printf("***TROCA DE 0 POR 1***\n\n");

	char texto[100];

	printf("Insira o texto para a troca de valores: ");
	fgets(texto, 100, stdin);

	for(int i = 0; i < strlen(texto); i++){
		if(texto[i] == '0'){
			texto[i] = '1';
		}
	}

	printf("O texto com as trocas realizadas fica: %s\n", texto);

}