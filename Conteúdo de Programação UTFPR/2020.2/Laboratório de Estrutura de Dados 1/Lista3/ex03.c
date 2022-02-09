#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[64];
	int idade;
} pessoa;

int buscaLinear(const char nome[64], pessoa *vet, int tam);

void main(){
	int n; 

	printf("Insira quantas pessoas terao no seu sistema: ");
	scanf("%d", &n);

	pessoa *vetorPessoas= (pessoa *)malloc(n * sizeof(pessoa));

	if(vetorPessoas){
		for(int i = 0; i < n; i++){
			printf("PESSOA %d\n", i+1);
			setbuf(stdin, NULL);
			printf("Nome: ");
			fgets((vetorPessoas + i)->nome, 64, stdin);
		}
	}

	char *nomeProcurado = (char *)malloc(64 * sizeof(char));

	if(nomeProcurado){
		setbuf(stdin, NULL);
		printf("\nInsira o nome que deseja procurar: ");
		fgets(nomeProcurado, 64, stdin);
	}

	int retorno;
	retorno = buscaLinear(nomeProcurado, vetorPessoas, n);

	if(retorno == -1){
		printf("A pessoa desejada nao foi encontrada no sistema!\n");
	} else {
		printf("A pessoa desejada foi encontrada no sistema na posicao %d!\n", retorno);
	}
}

int buscaLinear(const char nome[64], pessoa *vet, int tam){

	for(int i = 0; i < tam; i++){
		if(strcmp(nome, (vet+i)->nome) == 0){
			return i;
		}		
	}

	return -1;
}