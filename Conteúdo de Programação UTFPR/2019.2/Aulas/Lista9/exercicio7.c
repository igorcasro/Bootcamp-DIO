#include <stdio.h>

void main(){
	int vet1[5], vet2[5], n = 5, som[5], dif[5], prod[5];
	float div[5];

	for(int i = 0; i < n; ++i){
		printf("vet1[%d] = ", i + 1);
		scanf("%d", &vet1[i]);
	}
	
	for(int i = 0; i < n; ++i){
		printf("vet2[%d] = ", i + 1);
		scanf("%d", &vet2[i]);
	}
	
	printf("\n");
	for(int i = 0; i < n; ++i){
		som[i] = vet1[i] + vet2[i];
		printf("som[%d] = %d\n", i + 1, som[i]);
	}

	printf("\n");
	for(int i = 0; i < n; ++i){
		dif[i] = vet1[i] - vet2[i];
		printf("dif[%d] = %d\n", i + 1, dif[i]);
	}
	
	printf("\n");
	for(int i = 0; i < n; ++i){
		prod[i] = vet1[i] * vet2[i];
		printf("prod[%d] = %d\n", i + 1, prod[i]);
	}

	printf("\n");
	for(int i = 0; i < n; ++i){
		if(vet2[i] != 0){
			div[i] = (float) vet1[i] /(float) vet2[i];
			printf("div[%d] = %.2f\n", i + 1, div[i]);
		} else
			printf("div[%d] = invalido\n", i + 1);
	}

}
