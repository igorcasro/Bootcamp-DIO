#include <stdio.h>

int main() {
	int saida = 0;
	float salarioAnt, salarioNov;
	
	printf("Insira o salario para calcular o reajuste: ");
	scanf("%f", &salarioAnt);
	salarioNov = 1.1 * salarioAnt;
	printf("O salario reajustado eh %.2f\n", salarioNov);
	do{
		printf("Para sair do programa digite 1: ");
		scanf("%d", &saida);
	} while(saida != 1);

	return 0;
}
