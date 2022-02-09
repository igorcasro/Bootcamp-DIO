#include <stdio.h>
#include <stdlib.h>

int *concatenado(int *vet1, int *vet2, int n1, int n3,int *vetRes){
	int j = 0;
	vetRes = vet1;
	for(int i = n1; i < n3; i++){
		*(vetRes + i) = *(vet2 + j);
		++j;
	}

	return vetRes;
}

void main(){
	int n1, n2, n3;
	int *resultado = NULL;
	printf("Insira o tamanho do vetor 1: ");
	scanf("%d", &n1);
	printf("Insira o tamanho do vetor 2: ");
	scanf("%d", &n2);
	int *vet1 = (int *)malloc(n1 *(sizeof(int)));
	int *vet2 = (int *)malloc(n2 *(sizeof(int)));
	
	for(int i = 0; i < n1; i++){
		printf("vet1[%d] = ", i);
		scanf("%d", (vet1 + i));
	}
	for(int i = 0; i < n2; i++){
		printf("vet2[%d] = ", i);
		scanf("%d", (vet2 + i));
	}

	n3 = n1 + n2;
	int *vetRes = (int *)malloc(n3 *(sizeof(int)));

	
	resultado = concatenado(vet1, vet2, n1, n3, vetRes);

	printf("O vetor concatenado fica: ");
	for(int i = 0; i < (n1 + n2); i++){
		printf("%d ", *(resultado + i));
	}
	printf("\n");

	free(vet1);
	vet1 = NULL;

	free(vet2);
	vet2 = NULL;

//	free(resultado);
//	resultado = NULL;
}