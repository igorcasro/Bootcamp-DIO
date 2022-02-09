#include <stdio.h>
#include <stdlib.h>

void mm(int *p, int n, int *min, int *max){

	for(int i = 1; i < n; i++){
		if(*min > *(p + i)){
			*min = *(p + i);
		}
		if(*max < *(p + i)){
			*max = *(p + i);
		}
	}

}

void main(){
	int *min = (int *)malloc(sizeof(int));
	int *max = (int *)malloc(sizeof(int));

	int n;

	printf("Insira o tamanho do vetor: ");
	scanf("%d", &n);

	int *v= (int *)malloc(n*sizeof(int));

	int *p = v;

	for(int i = 0; i < n; i++){
		printf("[%d] = ", i);
		scanf("%d", (p + i));
	}

	*min = *v;
	*max = *v;

	mm(v, n, min, max);

	printf("Min = %d\n", *min);
	printf("Max = %d\n", *max);

}