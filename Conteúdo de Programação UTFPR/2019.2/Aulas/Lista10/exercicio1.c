#include <stdio.h>

void main(){
	int matriz[5][5], secundaria[5], soma, k = 0;

	printf("Escreva uma matriz de ordem 5.\n");
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			scanf("%d", &matriz[i][j]);
		}
	}

	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			soma = i + j;
			if(soma == 4){
				secundaria[k] = matriz[i][j];
				++k;
			}
		}
	}

	printf("Diagonal secundaria = ");
	for(int k = 0; k < 5; ++k){
		printf("%d ", secundaria[k]);
	}
	printf("\n");





}