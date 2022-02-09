#include <stdio.h>
#include <stdlib.h>

double *max(double *a, int size){
	double *x = NULL, m;
	m = *(a + 0);

	if(a == NULL){
		return NULL;
	}

	for(int i = 1; i < size; i++){
		if(*(a + i) > m){
			x = (a + i);
			m = *(a + i);
		}
	}
	return x;
}

void main(){
	int size;
	double *maior;

	printf("Insira o tamanho do seu vetor: ");
	scanf("%d", &size);

	double vet[size];

	for (int i = 0; i < size; i++){
 		printf("endereco de vd[%d] = %X\n", i, &vet[i]);
	}

	for(int i = 0; i < 5; i++){
		printf("[%d] = ", i);
		scanf("%f", (vet + i));
		printf("[%d] = %f\n", i, *(vet + i));
	}


	maior = max(vet, size);
	printf("O maior eh: %f\n", *maior);
	printf("O endereco do maior eh: %X\n", maior);
}