#include <stdio.h>
#include <stdlib.h>

void main(){

	double *ptrArray = (double *)malloc(sizeof(double) * 5);

	for(int i = 0; i < 5; i++){
		printf("endereco de [%d] = %x\n", i, (ptrArray + i));
		printf("[%d] = ", i);
		scanf("%lf", (ptrArray + i));
	}

	for(int i = 0; i < 5; i++){
		printf("[%d] = %F\n", i, *(ptrArray + i));
	}
} 