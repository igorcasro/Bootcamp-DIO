#include <stdio.h>

int main(){
	float numerador, denominador, soma;
	int contador;
	contador = 10;
	denominador = 500;
	soma = 0;
	while(contador > 0){
		if(contador % 2 == 0){
			numerador = 2;
		} else {
			numerador = -5;
		}
		soma = soma + (numerador / denominador);
		denominador = denominador - 50;
		--contador;
	}
	printf("O valor dos dez primeiros termos da serie eh: %.4f\n", soma);

	return 0;
}
