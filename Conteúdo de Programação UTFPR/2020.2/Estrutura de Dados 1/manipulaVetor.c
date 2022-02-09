#include <stdio.h>
#include <stdlib.h>

int *aloca(int n);
void inicializa(int *v, int n);
void imprime(int *v, int n);
void desalocapp(int **v);

void main(){
	int n, *p;

	printf("Insira o tamanho do seu vetor: ");
	scanf("%d", &n);

	p = aloca(n);
	inicializa(p, n);
	imprime(p, n);
	desalocapp(&p);
	imprime(p, n);

}

int *aloca(int n){
	int *v;
	v = (int *)malloc(n * (sizeof(int)));

	return v;
}

void inicializa(int *v, int n){
	
	for(int i = 0; i < n; i++){
		printf("[%d] = ", i + 1);
		scanf("%d", v + i);
	}

}

void imprime(int *v, int n){

	printf("\n");
	for(int i = 0; i < n; i++){
		printf("[%d] = %d\n", i + 1, *(v + i));
	}

}

void desalocapp(int **v){

	free(*v);
	*v = NULL;

}