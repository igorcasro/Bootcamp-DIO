#include <stdio.h>

int main() {
	float salFixo, vendas, salFinal;
	int nome;

	printf("Insira o numero de identificacao do vendedor: ");
	scanf("%d", &nome);
	printf("Informe o salario fixo: ");
	scanf("%f", &salFixo);
	printf("Informe o total de vendas do mes em dinheiro: ");
	scanf("%f", &vendas);
	salFinal = (salFixo + (0.15 * vendas));
	printf("O salario final eh: %.2f reais.\n", salFinal);

	return 0;
}
