#include <stdio.h>
#include <stdlib.h>

typedef struct cadastro {
	char nome[20];
	int idade;
} aluno;

void main(){
	FILE *arq;

	int contador = 0, na;

	arq = fopen("tad1.txt", "w");

	if(arq == NULL){
		printf("Erro na abertura do arquivo!\n");
	}

	printf("Insira quantas pessoas vai cadastrar: ");
	scanf("%d", &na);
	aluno *inserido = (aluno *)malloc(sizeof(aluno) * na);

	while(contador < na){
		printf("Insira o nome %d: ", contador + 1);
		scanf("%s", &(inserido + contador)->nome);
		printf("Agora insira sua idade: ");
		scanf("%d", &(inserido + contador)->idade);
		fprintf(arq, "%s %d\n", (inserido + contador)->nome, (inserido + contador)->idade);
		++contador;
	}
	fclose(arq);
	free(inserido);
	inserido = NULL;

}