#include <stdio.h>
#include <stdlib.h>

double* max(double* a, int size){
	double maior, *ptrMaior = NULL;
	
	if(a == NULL){
		return NULL;
	} else {
		maior = *(a + 0);
		for(int i = 1; i < size; i++){
			if(*(a + i) > maior){
				maior = *(a + i);
				ptrMaior = (a + i); 
			}
		}
		return ptrMaior;
	}
}

void main(){
	double *maior = NULL;
	int size;
	double *ptrArray; 

	printf("Insira o tamanho do seu vetor: ");
	scanf("%d", &size);

	ptrArray = (double *)malloc(size*(sizeof(double)));
	
	for(int i = 0; i < size; i++){
		printf("[%d] = ", i + 1);
		scanf("%lf", (ptrArray + i));
	}

	maior = max(ptrArray, size);
	if(maior == NULL){
		printf("Array vazio.\n");
	} else 
		printf("O maior valor do array eh: %.2f e seu endereco eh: %x\n", *maior, maior);
}