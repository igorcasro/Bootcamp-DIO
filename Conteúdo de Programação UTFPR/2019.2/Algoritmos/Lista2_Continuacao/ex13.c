#include <stdio.h>
#include <stdlib.h>

void Leitura(int *vet, int n){
	for(int i = 0; i < n; i++){
		printf("[%d] = ", i);
		scanf("%d", (vet + i));		
	}

}

void Separa(int *vet, int n, int *vet_I, int *vet_P){
	int j = 0, k = 0;

	for(int i = 0; i < n; i++){
		if(*(vet + i) % 2 == 0){
			*(vet_P + j) = *(vet + i);
			++j;
		} else {
			*(vet_I + k) = *(vet + i);
			++k;
		}
	}
}

void Imprime(int *vet, int n){
	printf("O seu vetor eh:\n");
	for(int i = 0; i < n; i++){
		printf("[%d] = %d\n", i, *(vet+i));
	}
}

void main(){
	int n;
	printf("Insira o tamanho do seu vetor: ");
	scanf("%d", &n);

	int *vetor = (int *)malloc(n *(sizeof(int)));
	int *vetor_I =(int *)malloc(n *(sizeof(int)));
	int *vetor_P =(int *)malloc(n *(sizeof(int)));

	Leitura(vetor, n);
	Separa(vetor, n, vetor_I, vetor_P);

	free(vetor_I);
	vetor_I = NULL;

	free(vetor_P);
	vetor_P = NULL;

	Imprime(vetor, n);
}
