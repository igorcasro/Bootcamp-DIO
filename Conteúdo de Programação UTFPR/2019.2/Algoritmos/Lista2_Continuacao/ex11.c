#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void caracteres_iguais(char *str1, char *str2, int *tam1, int *tam2, int *cont){
	*cont = 0;
	if(*tam1 >= *tam2){
		for(int i = 0; i < *tam1; i++){
			for(int j = 0; j < *tam2; j++){
				if(*(str1 + i) == *(str2 + j)){
					++(*cont);
				}
			}
		}
	} else {
		for(int i = 0; i < *tam2; i++){
			for(int j = 0; j < *tam1; j++){
				if(*(str2 + i) == *(str1 + j)){
					++(*cont);
				}
			}
		}
	}
}

void main(){
	char *string1 = (char *)calloc(100, sizeof(char));
	char *string2 = (char *)calloc(100, sizeof(char));
	int *tam_string1 = (int *)calloc(1, sizeof(int));
	int *tam_string2 = (int *)calloc(1, sizeof(int));
	int *contador = (int *)calloc(1, sizeof(int));

	printf("Insira a primeira string: ");
	fgets(string1, 100, stdin);
	printf("Insira a segunda string: ");
	fgets(string2, 100, stdin);

	*tam_string1 = strlen(string1);
	*tam_string2 = strlen(string2);
	--(*tam_string1);
	--(*tam_string2);

	caracteres_iguais(string1, string2, tam_string1, tam_string2, contador);
	printf("O numero de caracteres iguais eh de: %d\n", *contador);
}	