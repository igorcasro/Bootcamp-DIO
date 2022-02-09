#include <stdio.h>
#include <stdlib.h>

char *strcopy(char *str){
	char *copia = (char *)malloc(20 * sizeof(char));

	int i = 0;

	while(*(str + i) != '\0'){
		*(copia + i) = *(str + i);
		++i;
	}

	return copia;
}

void main(){
	char *string = (char *)malloc(20 * sizeof(char));

	printf("Insira uma palavra: ");
	scanf("%s", string);

	char *copia;

	copia = strcopy(string);

	printf("A copia da frase %s eh %s\n", string, copia);

}