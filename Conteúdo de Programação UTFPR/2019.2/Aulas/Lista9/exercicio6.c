#include <stdio.h>

void main(){
	int n;

	printf("Insira a quantidade de alunos: ");
	scanf("%d", &n);

	int alunos[n];

	for(int i = 0; i < n; ++i){
		alunos[i] = 0;
		printf("Aluno %d = %d\n", i + 1, alunos[i]);
	}
}
