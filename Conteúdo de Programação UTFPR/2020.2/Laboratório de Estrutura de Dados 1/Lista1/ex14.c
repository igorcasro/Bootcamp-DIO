#include <stdio.h>
#include <string.h>

void main(){
	printf("***ORDEM ALFABETICA***\n\n");

	char palavra1[15], palavra2[15];

	printf("Insira a primeira palavra: ");
	scanf("%s", &palavra1);
	printf("Insira a segunda palavra: ");
	scanf("%s", &palavra2);

	printf("%s %d\n", palavra1, strlen(palavra1));
	printf("%s %d\n", palavra2, strlen(palavra2));

	int valor = 0;

	int comp = palavra1 - palavra2;
	printf("Resultado = %d\n", comp);

	if(strlen(palavra1) == strlen(palavra2)){
		for(int i = 0; i < strlen(palavra1); i++){
			valor = palavra1[i] - palavra2[i];
			if(valor != 0){
				if(valor < 0){
					printf("%s vem antes de %s na ordem alfabetica.\n", palavra1, palavra2);
				} else {
					printf("%s vem antes de %s na ordem alfabetica.\n", palavra2, palavra1);
				}
				break;
			}
		}
	}

}