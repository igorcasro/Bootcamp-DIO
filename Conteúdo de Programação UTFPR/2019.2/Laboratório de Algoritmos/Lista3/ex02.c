#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	char nome[64];
	int idade;
} pessoa;

int iguaisRef(pessoa *a, pessoa *b){
	int resultado;

	resultado = strcmp(a->nome, b->nome);

	if(resultado == 0 && a->idade == b ->idade){
		return 1;
	} else {
		return 0;
	}
}

void main(){
	pessoa *p1, *p2;
	p1 = (pessoa *)malloc(sizeof(pessoa));
	p2 = (pessoa *)malloc(sizeof(pessoa));
	int result;

	printf("Insira o nome da primeira pessoa: ");
	scanf("%s", &p1->nome);
	printf("Insira a idade da primeira pessoa: ");
	scanf("%d", &p1->idade);
	
	printf("Insira o nome da segunda pessoa: ");
	scanf("%s", &p2->nome);
	printf("Insira a idade da segunda pessoa: ");
	scanf("%d", &p2->idade);

	result = iguaisRef(p1, p2);
	if(result == 1){
		printf("Sao a mesma pessoa.\n");
	} else {
		printf("Nao sao a mesma pessoa.\n");
	}

	free(p1);
	p1 = NULL;
	free(p2);
	p2 = NULL;
}
