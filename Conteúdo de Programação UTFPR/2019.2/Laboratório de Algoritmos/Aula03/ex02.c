#include <stdio.h>
#include <stdlib.h>

void main(){
	int val1, val2;
	int *ptrval1, *ptrval2;
	ptrval1 = &val1;
	ptrval2 = &val2;

	printf("Insira o primeiro valor inteiro: ");
	scanf("%d", ptrval1);
	printf("Insira o segundo valor inteiro: ");
	scanf("%d", ptrval2);

	if(*ptrval1 > *ptrval2){
		printf("Valor1: %X\n", ptrval1);
		printf("Valor2: %X\n", ptrval2);
	} else {
		printf("Valor1: %X\n", ptrval2);
		printf("Valor2: %X\n", ptrval1);
	}
}