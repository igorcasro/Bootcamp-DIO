#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contaIguais(char *string1, int n1, char *string2, int n2);

void main(){

	char *string1 = (char *)malloc(15 * sizeof(char));
	char *string2 = (char *)malloc(15 * sizeof(char));

	printf("Insira a primeira palavra: ");
	scanf("%s", string1);
	printf("Insira a segunda palavra: ");
	scanf("%s", string2);

	int n1 = strlen(string1);
	int n2 = strlen(string2);

	int iguais;

	iguais = contaIguais(string1, n1, string2, n2);

	printf("A quantidade de letras iguais eh: %d\n", iguais);

}

int contaIguais(char *string1, int n1, char *string2, int n2){
	int numIguais = 0;

		for(int i = 0; i < n1; i++){
			for(int j = 1; j < n1; j++){
				if(*(string1 + i) == *(string1 + j) && i != j){
					*(string1 + j) = '\0';
				}
			}
		}

		for(int i = 0; i < n1; i++){
			for(int j = 0; j < n2; j++){
				if(*(string1 + i) == *(string2 + j)){
					++numIguais;
				}
			}
		}

	return numIguais;
}