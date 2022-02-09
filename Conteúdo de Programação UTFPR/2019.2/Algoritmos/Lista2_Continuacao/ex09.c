#include <stdio.h>
#include <stdlib.h>

char *strcopy(char *str){
	char *copy = NULL;

	copy = str;

	return copy;
}

void main(){
	char *string;
	char *copia = NULL;

	printf("Insira uma string: ");
	fgets(string, 100, stdin);

	copia = strcopy(string);

	printf("%s", copia);
}