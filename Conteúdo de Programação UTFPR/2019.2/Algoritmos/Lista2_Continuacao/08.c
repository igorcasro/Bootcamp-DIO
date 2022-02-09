#include <stdio.h>
#include <stdlib.h>

void mm(int *v, int n, int *min, int *Max){
	int auxMin = *min, auxMax = *Max;
	for(int i = 0; i < n; i++){
		if(*(v + i) < auxMin){
			auxMin = *(v + i);
			*min = (v + i);
			printf("MIN %d %x\n", auxMin, *min);
		}
		
	}
	for(int i = 0; i < n; i++){
		if(*(v + i) > auxMax){
			auxMax= *(v + i);
			*Max = (v + i);
			printf("MAX %d %x\n", auxMax, *Max);
		}
	}
}

void main(){
	int n;
	int *min = (int *)malloc(sizeof(int));
	int *Max = (int *)malloc(sizeof(int));

	printf("Insira o tamanho do seu vetor de inteiros: ");
	scanf("%d", &n);

	int *v = (int *)malloc(n * (sizeof(int)));

	for(int i = 0; i < n; i++){
		printf("[%d] = ", i);
		scanf("%d", (v + i));
		printf("%x\n", (v + i));
	}

	*min = *v;
	*Max = *v;

	mm(v, n, min, Max);

	printf("&min = %x\n", *min);
	printf("&Max = %x\n", *Max);

}	