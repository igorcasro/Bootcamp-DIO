#include <stdio.h>

void calcula_media(float *matriz, float *vetor){
	int m = 2, n = 2;

	printf("Insira as notas dos alunos:\n");

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			printf("[%d] = ", i + 1);
			scanf("%f", matriz[i][j]);
			*(vetor + i) = *(vetor + i) + matriz[i][j];
		}
		*(vetor + i) = (*(vetor + i))/ n;
	}


	for(int i = 0; i < m; i++){
		printf("[%d] = %.2f\n", i + 1, *(vetor + i));
	}
}

void main(){
	int m = 2, n = 2;


	float matriz[m][n];
	float vetor[m];

	calcula_media(matriz, vetor);

}