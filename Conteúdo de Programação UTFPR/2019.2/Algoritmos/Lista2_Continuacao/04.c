#include <stdio.h>
#include <stdlib.h>

void quadradoA(int *a){
	*a = (*a) * (*a);
}

void fatorialB(int *b){
	if(*b >= 1){
		for(int i = *b; i > 1; i--){
			*b = *b * (i - 1);
		}
	}
}

void main(){
	int *a, *b, auxA, auxB;
	a = (int *)malloc(sizeof(int));
	b = (int *)malloc(sizeof(int));

	printf("Insira o valor de a: ");
	scanf("%d", a);
	printf("Insira o valor de b: ");
	scanf("%d", b);

	auxA = *a;
	auxB = *b;

	quadradoA(a);
	printf("\nO quadrado de %d eh %d.\n", auxA, *a);
	free(a);
	a = NULL;

	fatorialB(b);
	printf("O fatorial de %d eh %d.\n", auxB, *b);
	free(b);
	b = NULL;
}