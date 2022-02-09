#include <stdio.h>

void main(){
	int matriz[7][5], soma[7], k = 0;

	printf("Escreva uma matriz A(7x5).\n");
	for(int i = 0; i < 7; ++i){
		for(int j = 0; j < 5; ++j){
			scanf("%d", &matriz[i][j]);
		}
	}

	for(int i = 0; i < 7; ++i){
		soma[k] = 0;
		for(int j = 0; j < 5; ++j){
			soma[k] =  soma[k] + matriz[i][j];
		}
		++k;
	}
	
	for(int l = 0; l < 7; ++l){
		printf("Soma linha %d = %d\n", l + 1, soma[l]);
	}

	
}