#include <stdio.h>
#include <stdlib.h>

void calcula_media(float *notas, float *media){
	*media = *media + *notas + (*notas + 1) + (*notas + 2) + (*notas + 3);
	printf("%f\n", *media);
}

void main(){
	float notas[3][4];
	float media[3];

	for(int i = 0; i < 3; i++){
		printf("Insira as notas do aluno %d \n", i + 1);
			for(int j = 0; j < 4; j++){
				printf("[%d] = ", j + 1);
				scanf("%f", &notas[i][j]);
			}
	}

	calcula_media(*notas, media);
	printf("Media do aluno 1 = %f\n", media);

}