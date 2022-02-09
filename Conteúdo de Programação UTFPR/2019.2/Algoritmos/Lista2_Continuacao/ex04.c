#include <stdio.h>
#include <stdlib.h>

void a_quadrado(int *a){
	*a = (*a) * (*a);
}

void b_fatorial(int *b){
	for(int i = *b; i > 1; i--){
		*b = *b * (i - 1);
	}
}


void main(){ 
	int *a, *b;
	a =(int *)malloc(sizeof(int));
	b =(int *)malloc(sizeof(int));

	printf("Insira o valor de a: ");
	scanf("%d", a);
	printf("Insira o valor de b: ");
	scanf("%d", b);

	a_quadrado(a);
	printf("O quadrado do valor a eh: %d\n", *a);
	free(a);
	a = NULL;

	b_fatorial(b);
	printf("O fatorial de b eh: %d\n", *b);
	free(b);
	b = NULL;
}