#include <stdio.h>

double *max(double *a, int size){
	double *maior = a;

	for(int i = 1; i < (double)size; i++){
		if(*maior < *(a + i)){
			maior = (a + i);
		}
	}

	return maior;
}

void main(){
	int size;

	printf("Insira o tamanho do seu vetor: ");
	scanf("%d", &size);

	double vetor[size], maior[1];

	for(int i = 0; i < size; i++){
		printf("[%d] = ", i);
		scanf("%lf", (vetor + i));
	}

	for(int i = 0; i < size; i++){
		printf("[%d] = %lf\n", i, *(vetor + i));
	}

	maior[0] = *max(vetor, size);

	printf("%d\n", maior);

}