#include <stdio.h>
#include <string.h>

void main(){
	printf("***CODIGO DE CESAR***\n\n");
	
	char frase[100];

	printf("Insira uma frase para ser codificada: ");
	fgets(frase, 100, stdin);

	int posicao;

	printf("Insira o valor que sera usado como padrao para o codigo: ");
	scanf("%d", &posicao);

	for(int i = 0; i < strlen(frase); i++){
		if(frase[i] + posicao > 'z'){
			printf("%c", frase[i] + posicao - 26);
		} else if(frase[i] == ' ') {
			printf(" ");
		} else {
			printf("%c", frase[i] + posicao);
		}
	}

	printf("\n");

}