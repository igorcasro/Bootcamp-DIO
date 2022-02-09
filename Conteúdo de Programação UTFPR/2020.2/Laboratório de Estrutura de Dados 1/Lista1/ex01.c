#include <stdio.h>

void main(){
	char frase[100];

	printf("Insira uma frase, por favor: ");
	fgets(frase, 100, stdin);


	printf("A frase inserida foi: %s\n", frase);

}