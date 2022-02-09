#include <stdio.h>

void Armazenar(int F[], int n);

void main(){
	int F[20], n = 20;

	Armazenar(F, 20);
}

void Armazenar(int F[], int n){
	int i;

	for(i = 0; i < n; i++){
		printf("[%d]= ", i);
		scanf("%d", &F[i]);
	}
	printf("\nMultiplicando os vetores por suas posicoes, temos: \n\n");
	for(i = 0; i < n; i++){
		F[i] = F[i] * i;
		printf("[%d] = %d\n", i, F[i]);
	}
	
}
