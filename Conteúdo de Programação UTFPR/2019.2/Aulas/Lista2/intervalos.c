#include <stdio.h>

int main() {

	float A, B, C, D, n;
	printf("Insira um intervalo [A, B], onde A < B\n");
	printf("Valor A: ");
	scanf("%f", &A);
	printf("Valor B: ");
	scanf("%f", &B);
	printf("Insira um intervalo [C, D], onde C < D e C > A\n");
	printf("Valor C: ");
	scanf("%f", &C);
	printf("Valor D: ");
	scanf("%f", &D);
	printf("Insira um valor para verificacao de existencia nos intervalos: ");
	scanf("%f", &n);
	if(A < B && C < D && A < C){
		if(n >= A && n <= B){
			printf("O numero %.2f pertence ao intervalo [A, B] = [%.2f, %.2f].\n", n, A, B);
		}
		if(n >= C && n <= D){
			printf("O numero %.2f pertence ao intervalo [C, D] = [%.2f, %.2f].\n", n, C, D);
		} else
				printf("O numero %f nao pertence a nenhum dos intervalos!\n", n);
	} else
		printf("Intervalos incorretos!\n");

	return 0;
}