#include <stdio.h>

void conversao(float valorDolar, float valorReal){
	float valorFinal;
	valorFinal = valorDolar * valorReal;

	printf("O valor %.2f convertido para dolar eh: %.2f\n", valorReal, valorFinal);
}

int main(){
	float  valorDolar, valorReal;

	do{
		printf("Insira o valor do dolar: ");
		scanf("%f", &valorDolar);
		printf("Insira o valor de reais para conversao: ");
		scanf("%f", &valorReal);
	} while (valorDolar < 0 || valorReal < 0);

	conversao(valorDolar, valorReal);


	return 0;
}
