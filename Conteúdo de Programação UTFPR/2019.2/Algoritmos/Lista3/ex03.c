#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int matricula;
	char nome[100];
	float notas[3];
}curso;

typedef struct{
	char maior[100];
}maior_aluno;

void preencher(curso alunos[5]){
	for(int i = 0; i < 2; i++){		
		printf("ALUNO %d\n", i + 1);
		printf("Insira a matricula do aluno: ");
		scanf("%d", &alunos[i].matricula);
		printf("Insira o nome do aluno: ");
		setbuf(stdin, NULL);
		fgets(alunos[i].nome, 100, stdin);
		printf("Insira as notas do aluno.\n");
		for(int j = 0; j < 3; j++){
			printf("Nota %d: ", j + 1);
			scanf("%f", &alunos[i].notas[j]);
		}
	}
}

void maior_primeira(curso alunos[5]){
	float maior = 0;
	char *maior_nota = (char *)calloc(100, sizeof(int));
	
	for(int i = 0; i < 2; i++){
		if(maior < alunos[i].notas[0]){
			maior = alunos[i].notas[0];
			strcpy(maior_nota, alunos[i].nome);
		}
	}
	printf("A pessoa com a maior nota na primeira prova eh: %s", maior_nota);

	free(maior_nota);
	maior_nota = NULL;	
}

void maior_media(curso alunos[5]){
	float maior1, maior2;
	maior1 = (alunos[0].notas[0] + alunos[0].notas[1] + alunos[0].notas[2]) / 3;

	for(int i = 1; i < 2; i++){
		maior2 = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2]) / 3;
		if(maior2 > maior1){
			maior1 = maior2;
		}
	}

	printf("A maior media eh: %.2f\n", maior1);

}

void menor_media(curso alunos[5]){
	float menor1, menor2;
	menor1 = (alunos[0].notas[0] + alunos[0].notas[1] + alunos[0].notas[2]) / 3;

	for(int i = 1; i < 2; i++){
		menor2 = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2]) / 3;
		if(menor2 < menor1){
			menor1 = menor2;
		}
	}

	printf("A menor media eh: %.2f\n", menor1);

}

void aprovado(curso alunos[5]){
	for(int i = 0; i < 2; i++){
		if(((alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2]) / 3) >= 6.0){
			printf("O aluno %s foi aprovado!\n", alunos[i].nome);
		} else {
			printf("O aluno %s foi reprovado!\n", alunos[i].nome);
		}
	}
}

void main(){
	curso alunos[5];
	maior_aluno maior_nota; 

	preencher(alunos);
	maior_primeira(alunos);
	maior_media(alunos);
	menor_media(alunos);
	aprovado(alunos);
}