#include <stdio.h>
#include <stdlib.h>

void main(){
	int val1;
	float val2;	
	int *ptrval1;
	float *ptrval2;
	ptrval1 = &val1;
	ptrval2 = &val2;

	printf("Insira um valor inteiro: ");
	scanf("%d", ptrval1);
	printf("Insira um valor flutuante: ");
	scanf("%f", ptrval2);

	*ptrval1 = *ptrval1 + 7;
	*ptrval2 = *ptrval2 + 47.1;

	printf("O valor inteiro adicionado de 7 eh: %d\n", *ptrval1);
	printf("O valor flutuante adicionado de 47.1 eh: %.2f\n", *ptrval2);
}