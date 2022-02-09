#include <stdio.h>
#include <string.h>

void main(){
	printf("***VERIFICA PALINDROMO***\n\n");

	char frase[100];

	printf("Insira uma frase para se realizar a verificacao: ");
	fgets(frase, 100, stdin);
	printf("1 - %s", frase);

	int tam = strlen(frase);

	char fraseInvertida[tam];
	int aux = 0;
	printf("2 - %s", frase);

	for(int i = tam - 1; i > 0; i--){
		fraseInvertida[aux] = frase[i - 1];
		++aux;		
	}
	fraseInvertida[tam - 1] = frase[tam - 1];
	printf("3 - %s", frase);

	if(fraseInvertida + 16 == frase){
		printf("INGUAIS!\n");
	} else {
		printf("NAO INGUAIS\n");
	}

	printf("%s", fraseInvertida);
	printf("4 - %s", frase);
}