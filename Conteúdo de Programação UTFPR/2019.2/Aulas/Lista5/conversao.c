#include <stdio.h>

int main(){
	float contador, celsius, divisao;

	printf("***CONVERSAO DE FAHRENHEIT PARA CENTIGRADOS***\n\n");
	
	contador = 50;
	divisao = 5 / 9;
	do{
		celsius =(contador - 32);
		celsius = 5 * celsius;
		celsius = celsius / 9;
		printf("%.0f F = %.2f C\n", contador, celsius);
		++contador;
	} while (contador <= 150);
	printf("\n");

	return 0;
}
