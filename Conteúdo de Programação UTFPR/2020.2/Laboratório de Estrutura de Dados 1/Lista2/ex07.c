#include <stdio.h>

void soma(float *ptrA, float *ptrB){
	*ptrA = *ptrA + *ptrB;
}

void main(){
	float A, B;
	float *ptrA = &A;
	float *ptrB = &B;

	printf("ENTRADA: ");
	scanf("%f %f", ptrA, ptrB);

	soma(ptrA, ptrB);

	printf("SAIDA: %.2f %.2f\n", A, B);
}