#include <stdio.h>

float retornaMaior(float *ptrA, float *ptrB){

	if(*ptrA >= *ptrB){
		return *ptrA;
	} else
		return *ptrB;

}

void main(){
	float A, B;
	float *ptrA = &A;
	float *ptrB = &B;
	float maior;

	printf("ENTRADA: ");
	scanf("%f %f", ptrA, ptrB);

	maior = retornaMaior(ptrA, ptrB);

	printf("SAIDA: %.2f %.2f %.2f\n", maior, *ptrA, *ptrB);
}