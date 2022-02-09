#include <stdio.h>

void main(){
	char palavra1[100];
	char palavra2[100];

	printf("Insira a primeira palavra: ");
	scanf("%s", palavra1);
	printf("Insira a segunda palavra: ");
	scanf("%s", palavra2);

	if(palavra1[0] >= palavra2[0]){
		printf("1: %s\n2: %s\n", palavra2, palavra1);
	} else 
		printf("1: %s\n2: %s\n", palavra1, palavra2);

}