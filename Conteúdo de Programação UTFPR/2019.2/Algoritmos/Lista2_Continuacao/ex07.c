#include <stdio.h>
#include <stdlib.h>

int Desaloca(int **p) {
	free(*p);

	*p = NULL;
}

void main(){
	int *p = (int *)malloc(5*sizeof(int));

	for(int i = 0; i < 5; i++){
		printf("[%d] = ", i);
		scanf("%d", (p + i));
	}

	for(int i = 0; i < 5; i++){
		printf("%d\n", *(p+i));
	}
	printf("%X\n", p);
	
	Desaloca(&p);	

	for(int i = 0; i < 5; i++){
	printf("%d\n", *(p+i));
	}
	printf("%X\n", p);
}