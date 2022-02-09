#include <stdio.h>
#include <string.h>

void main(){
	printf("***CONTA E TROCA VOGAIS***\n\n");

	char palavra[100];

	printf("Insira uma palavra: ");
	fgets(palavra, 100, stdin);

	int cont = 0;
	int aux = 0;

	while(aux < strlen(palavra)){
		if(palavra[aux] == 'a' || palavra[aux] == 'A'){
			++cont;
		}
		if(palavra[aux] == 'e' || palavra[aux] == 'E'){
			++cont;
		}
		if(palavra[aux] == 'i' || palavra[aux] == 'I'){
			++cont;
		}
		if(palavra[aux] == 'o' || palavra[aux] == 'O'){
			++cont;
		}
		if(palavra[aux] == 'u' || palavra[aux] == 'U'){
			++cont;
		}
		++aux;
	}

	printf("A palavra inserida possui %d vogais.\n", cont);

	char troca;

	printf("Insira uma vogal para trocar pelas vogais existentes na palavra inserida: ");	
	scanf("%c", &troca);

	for(int i = 0; i < strlen(palavra); i++){
		if(palavra[i] == 'a' || palavra[i] == 'A'){
			palavra[i] = troca;
		}
		if(palavra[i] == 'e' || palavra[i] == 'E'){
			palavra[i] = troca;
		}
		if(palavra[i] == 'i' || palavra[i] == 'I'){
			palavra[i] = troca;
		}
		if(palavra[i] == 'o' || palavra[i] == 'O'){
			palavra[i] = troca;
		}
		if(palavra[i] == 'u' || palavra[i] == 'U'){
			palavra[i] = troca;
		}
	}

	printf("A palavra inserida com as vogais substituidas pela vogal selecionada eh: %s", palavra);

}