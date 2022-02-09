#include <stdio.h>

void main(){
	char palavra[100];
	int contador = 0;
	int i = 0, j = 0;

	printf("Insira uma palavra: ");
	scanf("%s", palavra);

	while(palavra[i] != '\0'){
		++contador;
		++i;
	}

	i = 0;
	while(i < contador){
		while(palavra[i] == 'a' || palavra[i] == 'A' || palavra[i] == 'e' || palavra[i] == 'E' || palavra[i] == 'i' || palavra[i] == 'I' || palavra[i] == 'o' || palavra[i] == 'O' || palavra[i] == 'u' || palavra[i] == 'U'){
			printf("X");
			++i;
			++j;
		}
		printf("%c", palavra[i]);
		++i;
	}

	printf("\nExistem %d vogais.\n", j);

}