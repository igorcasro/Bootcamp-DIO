#include <stdio.h>
#include <string.h>

void main(){
	printf("***IMPRIME FRASE INVERTIDA E SUBSTITUI A POR \"*\" ***\n\n");

	char frase1[30], frase2[30];

	printf("Insira a primeira frase: ");
	fgets(frase1, 30, stdin);
	printf("Insira a segunda frase: ");
	fgets(frase2, 30, stdin);

	printf("Invertendo e fazendo a troca da primeira frase temos: ");
	for(int i = (strlen(frase1) - 2); i >= 0; i--){		
		if(frase1[i] == 'a' || frase1[i] == 'A'){
			printf("*");
		} else {
			printf("%c", frase1[i]);
		}
	}

	printf("\nInvertendo e fazendo a troca da segunda frase temos: ");
	for(int i = (strlen(frase2) - 2); i >= 0; i--){
		if(frase2[i] == 'a' || frase2[i] == 'A'){
			printf("*");
		} else {
			printf("%c", frase2[i]);
		}
	}

	printf("\n");
}