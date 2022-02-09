#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct polar{
	float a;
	float b;
} pontoPolar;

void preenche(pontoPolar *ponto1);
void converte(pontoPolar *ponto1, pontoPolar *ponto2);
void imprime(pontoPolar *ponto);


void main(){
	pontoPolar ponto1, ponto2;

	preenche(&ponto1);
	printf("Ponto1\n");
	imprime(&ponto1);
	converte(&ponto1, &ponto2);
	printf("Ponto2\n");
	imprime(&ponto2);
}

void converte(pontoPolar *ponto1, pontoPolar *ponto2){
	ponto2->a = (ponto1->a) * (cos(ponto1->b));
	ponto2->b = (ponto1->a) * (sin(ponto1->b));
}

void preenche(pontoPolar *ponto1){
	printf("Insira o raio: ");
	scanf("%f", &(ponto1->a));
	printf("Insira o argumento em radianos: ");
	scanf("%f", &(ponto1->b));
}

void imprime(pontoPolar *ponto){
	printf("Valor 1: %.2f\nValor 2: %.2f\n", ponto->a, ponto->b);
}