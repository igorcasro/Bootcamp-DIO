#include <stdio.h>

void main(){
	char palavra[100];
	int contador = 0;
	int i =0;

	printf("Insira uma string: ");
	scanf("%s", palavra);

	while(palavra[i] != '\0'){
		++contador;
		++i;
	}

	i = 0;
	while(i < contador){
		while(palavra[i] == 'a' || palavra[i] == 'A' || palavra[i] == 'e' || palavra[i] == 'E' || palavra[i] == 'i' || palavra[i] == 'I' || palavra[i] == 'o' || palavra[i] == 'O' || palavra[i] == 'u' || palavra[i] == 'U'){
			++i;
		}
		printf("%c", palavra[i]);
		++i;
	}

	printf("\n");

}