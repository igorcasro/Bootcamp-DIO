#include <stdio.h>

void troca(int *val1, int *val2){
	int aux;
	aux = *val1;
	*val1 = *val2;
	*val2 = aux;
}


void main(){
	int a, b;
	int *ptra = &a, *ptrb = &b;

	printf("Insira o primeiro valor: ");
	scanf("%d", ptra);

	printf("Insira o segundo valor: ");
	scanf("%d", ptrb);

	printf("A = %d\nB = %d\n", *ptra, *ptrb);

	troca(ptra, ptrb);

	printf("Apos a troca temos:\nA = %d\nB = %d\n", *ptra, *ptrb);
}