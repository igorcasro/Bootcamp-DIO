#include <stdio.h>
#include <stdlib.h>

void desaloca(int **v){
	free(*v);
	*v = NULL;
}

void imprime(int *v, int n){

	printf("\n");
	for(int i = 0; i < n; i++){
		printf("[%d] = %d\n", i + 1, *(v + i));
	}

}


void main(){
	int *p, n = 7;

	p = (int *)malloc(n*sizeof(int));

	printf("%x eh o endereco do ponteiro\n", p);

	printf("Adicionando 1 ao endereco %x temos: %d\n", p, *(p)+1);

	desaloca(&p);
	imprime(p, n);
}