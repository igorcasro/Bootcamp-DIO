#include <stdio.h>
#include <stdlib.h>

void soma(float *ptrA, float *ptrB){
	*ptrA = *ptrA + *ptrB;
}

void main(){
	float A, B;
	float *ptrA, *ptrB;
	ptrA = &A;
	ptrB = &B;
	
	printf("Insira o valor de A: ");
	scanf("%f", ptrA);
	printf("Insira o valor de B: ");
	scanf("%f", ptrB);

	soma(ptrA, ptrB);

	printf("%.2f %.2f\n", *ptrA, *ptrB);

}