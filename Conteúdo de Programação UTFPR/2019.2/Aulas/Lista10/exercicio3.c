#include <stdio.h>

void main(){
	int matriz[7][5], maior = 0, pMaior;

	printf("Preencha a matriz B(7x5)\n");

	for(int i = 0; i < 7; ++i){
		for(int j = 0; j < 5; ++j){
			printf("[%d][%d] = ", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	printf("Matriz B\n");
	for(int i = 0; i < 7; ++i){
		for(int j = 0; j < 5; ++j){
			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}



}
