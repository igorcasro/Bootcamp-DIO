#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[100];
	short int idade;
} pessoa;

int buscaLinear(const char nome[64], pessoa vet[], int tam){
	int aux;
	
	for(int i = 0; i < tam; i++){
		aux = strcmp(nome, vet[i].nome);
		if(aux == 0){
			return i;
		} else {
			return -1;
		}
	}

}

void main(){
	int result, tamanho;

	printf("Insira quantos alunos terao na sala: ");
	scanf("%d", &tamanho);

	pessoa Alunos_Sala[tamanho];

	for(int i = 0; i < tamanho; i++){
		setbuf(stdin, NULL);
		printf("Insira o nome do aluno %d: ", i + 1);
		fgets(Alunos_Sala[i].nome, 100, stdin);
		printf("Insira a idade do aluno %d: ", i + 1);
		scanf("%d", &Alunos_Sala[i].idade);
	}	

	setbuf(stdin, NULL);
	char nome[64];
	printf("Insira o nome da pessoa a ser procurada: ");
	fgets(nome, 64, stdin);

	result = buscaLinear(nome, Alunos_Sala, tamanho);
	if(result == -1){
		printf("%s nao se encontra na turma.\n", nome);
	} else {
		printf("%ssera encontrado(a) na posicao %d da turma.\n", nome, result);
	}

}