#include <stdio.h>
#include <stdlib.h>

void mm(int *v,int *min,int *Max, int n){
	for(int i = 0; i < (n  - 1); i++){
		if(*(v + i + 1) < *(v + i)){
			*min = (v + i + 1);
		} else {
			*min = v;
		}
		if(*(v + i + 1) > *(v + i)){
			*Max = (v + i + 1);
		} else {
			*Max = v;
		}
	}
}

void main(){
	int n;
	int *min = (int *)malloc(sizeof(int));
	int *Max = (int *)malloc(sizeof(int));
	printf("Insira o tamanho do vetor: ");
	scanf("%d", &n);

	int *v = (int *)malloc(n * (sizeof(int)));
	for(int i = 0; i < n; i++){
		printf("[%d] = ", i);
		scanf("%d", (v + i));
	}
	for(int i = 0; i < n; i++){
		printf("&[%d] = %X\n", i, (v + i));
	}

	*min = *v;
	*Max = *(v + n);

	mm(v, min, Max, n);

	printf("&min = %X\n", *min);
	printf("&Max = %X\n", *Max);

}