#include <stdio.h>
#include <stdlib.h>

char *strcopy(char *str){
	char *copia = NULL;

	copia = str;

	return copia;
}

void main(){
	char *str = (char *)malloc(100 * sizeof(char));
	char *copia = NULL;

	printf("Insira uma string: ");
	fgets(str, 100, stdin);

	copia = strcopy(str);

	printf("%s", copia);

	free(str);
	str = NULL;
}