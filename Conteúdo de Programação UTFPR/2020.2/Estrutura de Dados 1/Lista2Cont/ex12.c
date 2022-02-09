#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void preencheVetor(int *vetor, int tam);
void desaloca(int **vetor);
int *uniaoVetores(int *vetor1, int *vetor2, int tam1, int tam2);

void main(){
	int nA, nB;

	printf("Insira o tamanho do vetor A: ");
	scanf("%d", &nA);
	printf("Insira o tamanho do vetor B: ");
	scanf("%d", &nB);

	int *vetA = (int *)malloc(nA * sizeof(int));
	int *vetB = (int *)malloc(nB * sizeof(int));

	printf("Preenchendo o vetor A\n");
	preencheVetor(vetA, nA);
	printf("Preenchendo o vetor B\n");
	preencheVetor(vetB, nB);

	int nC = nA + nB;
	int *vetC = (int *)malloc(nC * sizeof(int));

	vetC = uniaoVetores(vetA, vetB, nA, nB);

	for(int i = 0; i < nC; i++){
		printf("C[%d] = %d\n", i, *(vetC + i));
	}

	desaloca(&vetA);
	desaloca(&vetB);
	desaloca(&vetC);
}

void preencheVetor(int *vetor, int tam){
	for(int i = 0; i < tam; i++){
		printf("[%d] = ", i);
		scanf("%d", (vetor + i));
	}
}

int *uniaoVetores(int *vetor1, int *vetor2, int tam1, int tam2){
	int *vetorSoma = (int *)malloc((tam1 + tam2) * sizeof(int));

	int j = 0;

	for(int i = 0; i < tam1; i++){
		*(vetorSoma + i) = *(vetor1 + i);
	}
	for(int i = 0; i < tam2; i++){
		*(vetorSoma + tam1 + i) = *(vetor2 + i);
	}

	return vetorSoma;
}

void desaloca(int **vetor){
	free(*vetor);
	*vetor = NULL;
}
