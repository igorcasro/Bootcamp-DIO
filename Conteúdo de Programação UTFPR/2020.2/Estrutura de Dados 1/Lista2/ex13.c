#include <stdio.h>

void troca(int *ptr1, int *ptr2){
	int aux;

	aux = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = aux;
}

void main(){
	int val1, val2;
	int *ptr1 = &val1;
	int *ptr2 = &val2;

	printf("Insira o primeiro valor: ");
	scanf("%d", ptr1);
	printf("Insira o segundo valor: ");
	scanf("%d", ptr2);

	troca(ptr1, ptr2);

	printf("\nApos a troca temos:\nValor 1 = %d\nValor 2 = %d\n", *ptr1, *ptr2);

}