#include <stdio.h>
#include <stdlib.h>



typedef struct{
	int matricula;
	char nome[15];
	float *nota;
}alunos;

void entrarDados(alunos *inserido, int n);
void mostraDados(alunos *inserido, int n);
alunos *maiorNota(alunos *inserido, int n);
void media(alunos *inserido, int n, float *mediaAlunos);

void main(){
	alunos *alunoInserido, *alunoMaior;
	int n = 3;
	
	float *mediaAlunos = (float *)malloc(n * (sizeof(float)));
	
	alunoInserido = (alunos *)malloc(n * sizeof(alunos));

	if(alunoInserido){
		entrarDados(alunoInserido, n);
		mostraDados(alunoInserido, n);
		alunoMaior = maiorNota(alunoInserido, n);
		printf("O aluno que apresentou a maior nota na primeira prova foi: %s", alunoMaior->nome);
		media(alunoInserido, n, mediaAlunos);
	}


}

void entrarDados(alunos *inserido, int n){

	for(int i = 0; i < n; i++){
		printf("ALUNO %d\n", (i + 1));
		printf("Insira a matricula do aluno %d: ", (i + 1));
		scanf("%d", &(inserido + i)->matricula);
		setbuf(stdin, NULL);
		printf("Insira o nome deste aluno: ");
		fgets((inserido + i)->nome, 15, stdin);
		(inserido + i)->nota = (float *)malloc(sizeof(float));
		for(int j = 0; j < 3; j++){
			printf("Insira a nota %d deste aluno: ", (j + 1));
			scanf("%f", &(inserido + i)->nota[j]);
		}
	}
}

void mostraDados(alunos *inserido, int n){
	for(int i = 0; i < n; i++){
		printf("MATRICULA: %d\n", (inserido + i)->matricula);
		printf("NOME: %s\n", (inserido + i)->nome);
		for(int j = 0; j < 3; j++){
			printf("NOTA %d: %.2f\n", (j + 1), (inserido + i)->nota[j]);
		}
	}
}

alunos *maiorNota(alunos *inserido, int n){
	float *maior = 0;
	int aux = 0;

	printf("MAIOR ANTES: %.2f\n", *maior);

	for(int i = 0; i < n; i++){
		if(*(inserido+i)->nota > *maior){
			*maior = *(inserido + i)->nota;
			aux = i;
		}
	}

	printf("MAIOR DEPOIS: %.2f\nAluno 0 possui como primeira nota: %.2f\n", *maior, *inserido->nota);

	return (inserido + aux);
}

void media(alunos *inserido, int n, float *mediaAlunos){

	for(int i = 0; i < n; i++){
		printf("Aluno[%d]\n", i);
		for(int j = 0; j < 3; j++){
			*(mediaAlunos + i) += (inserido + i)->nota[j];
			printf("Nota[%d] = %.2f\n", (j + 1), (inserido + i)->nota[j]);
		}
		*(mediaAlunos + i) = *(mediaAlunos + i) / 3;
	printf("Aluno[%d] tem media = %.2f\n", i, *(mediaAlunos + i));
	}

}
