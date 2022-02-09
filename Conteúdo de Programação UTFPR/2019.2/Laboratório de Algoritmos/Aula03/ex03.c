#include <stdio.h>
#include <stdlib.h>

void main(){
	int val1, val2, soma;
	int *ptrval1, *ptrval2, *ptrsoma;
	ptrval1 = &val1;
	ptrval2 = &val2;
	ptrsoma = &soma;

	printf("Insira o primeiro valor: ");
	scanf("%d", ptrval1);
	printf("Insira o segundo valor: ");
	scanf("%d", ptrval2);

	*ptrsoma = *ptrval1 + *ptrval2;

	printf("Valor 1 + Valor 2 = %d\n", *ptrsoma);
	printf("Endereco da soma = %X\n", ptrsoma);
}