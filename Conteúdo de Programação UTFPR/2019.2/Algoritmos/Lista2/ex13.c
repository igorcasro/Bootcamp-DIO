#include <stdio.h>
#include <stdlib.h>

void troca(int *ptrval1, int *ptrval2){
	int aux;
	aux = *ptrval1;
	*ptrval1 = *ptrval2;
	*ptrval2 = aux;
}

void main(){
	int val1, val2;
	int *ptrval1, *ptrval2;
	ptrval1 = &val1;
	ptrval2 = &val2;
	printf("Insira o primeiro valor: ");
	scanf("%d", ptrval1);
	printf("Insira o segundo valor: ");
	scanf("%d", ptrval2);
	troca(&val1, &val2);
	printf("Trocando os valores temos\nValor 1 = %d\nValor 2 = %d\n", *ptrval1, *ptrval2);
}