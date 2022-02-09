#include <stdio.h>
#include <math.h>

int main(){
	int contador, auxiliar, auxiliar2;
	float resultado, valor;
	contador = resultado = auxiliar2 = 0;

	printf("Insira um valor para a soma no estilo 1 + 1/x² + 1/x³... : ");
	scanf("%f", &valor);

	while(contador < 20){{
			++contador;
			++auxiliar2;
			auxiliar = pow(valor, auxiliar2);
			resultado = resultado + (1 / auxiliar);
		}
	}
	printf("O valor da soma eh: %.2f\n", resultado);

	return 0;
}
