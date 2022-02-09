#include <stdio.h>
#include <string.h>

void main(){
	char frase[200];
	int contador = 0;

	printf("Insira uma frase: ");
	fgets(frase, 200, stdin);

	contador = strlen(frase);

	for(int i = 0; i < contador; ++i){
		if(frase[i] != ' '){
			frase[i] = frase[i] + 3;
		}
	}

	printf("%s\n", frase);

}