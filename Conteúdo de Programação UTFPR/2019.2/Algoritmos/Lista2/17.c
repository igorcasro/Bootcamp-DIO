#include <stdio.h>

void calcula_media(float *matriz, float *vetor){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
			*(vetor + i) += *(matriz[i] + j);
		}
		*(vetor + i) = *(vetor + i) / (4.0);
		printf("Media do aluno %d = %f\n", i, *(vetor + i));
	}
}

void main(){
	int alunos = 3;
	int notas = 4;
	float notasAlunos[alunos][notas], *ptrNotasAlunos = notasAlunos;
	float media[alunos], *ptrMedia = media;

	for(int i = 0; i < alunos; i++){
		printf("Aluno %d\n", i + 1);
		for(int j = 0; j < notas; j++){
			do{
				printf("Nota %d: ", j + 1);
				scanf("%f", (notasAlunos[i] + j));
			} while(*(notasAlunos[i] + j) < 0 || *(notasAlunos[i] + j) > 10);
		}
	}

	calcula_media(ptrNotasAlunos, ptrMedia);
}