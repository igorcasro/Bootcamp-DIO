#include <stdio.h>
#include <stdlib.h>

void maior_valor(int *ptrval1, int *ptrval2, int *ptrmaior){
	if(*ptrval1 > *ptrval2){
		*ptrmaior = *ptrval1;
	} else {
		*ptrmaior = *ptrval2;
	}
}

void main(){
	int val1, val2, maior;
	int *ptrval1, *ptrval2, *ptrmaior;
	ptrval1 = &val1;
	ptrval2 = &val2;
	ptrmaior = &maior;

	printf("Insira o primeiro valor: ");
	scanf("%d", ptrval1);
	printf("Insira o segundo valor: ");
	scanf("%d", ptrval2);

	maior_valor(ptrval1, ptrval2, ptrmaior);

	printf("%d %d %d\n", *ptrmaior, *ptrval1, *ptrval2);

}