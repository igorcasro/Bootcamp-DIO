#include <stdio.h>

int main() {

	float salLiq, salBru, prov, desc;
	printf("Insira seu salario bruto: ");
	scanf("%f", &salBru);
	printf("Insira seus proventos: ");
	scanf("%f", &prov);
	if(salBru <= 50) {
		desc = (0.05 * salBru);
		salLiq = salBru + prov - desc;
		printf("Seu salario liquido eh: %.2f \n", salLiq);
	}
	if(salBru > 50) {
		desc = (0.1 * salBru);
		salLiq = salBru + prov - desc;
		printf("Seu salario liquido eh: %.2f \n", salLiq);
	}

	return 0;
}