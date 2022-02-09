#include <stdio.h>

void troca(int *ptr1, int *ptr2){
	int aux;
	aux = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = aux;
}

void main() {
	int val1, val2;
	int *ptr1 = &val1, *ptr2 = &val2;

	printf("Insira o valor A: ");
	scanf("%d", ptr1);
	printf("Insira o valor B: ");
	scanf("%d", ptr2);

	troca(ptr1, ptr2);

	printf("Apos troca temos que A vale %d e B vale %d.\n", *ptr1, *ptr2);

}