#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b){

	*a = *a * *a;

	int tamB = *b;

	for(int i = 2; i < tamB; i++){
		*b = (*b) * i;
	}

}

void main(){

	int valA, valB;
	int *a = (int *)malloc(sizeof(int));
	int *b = (int *)malloc(sizeof(int));

	printf("Insira o valor de a: ");
	scanf("%d", a);
	printf("Insira o valor de b: ");
	scanf("%d", b);

	valA = *a;
	valB = *b;

	troca(a, b);

	printf("O valor de %d ao quadrado eh %d\n", valA, *a);
	printf("O valor de %d fatorial eh %d\n", valB, *b);

	free(a);
	a = NULL;
	free(b);
	b = NULL;

}