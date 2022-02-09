#include <stdio.h>

int main(){
	float den, soma;
	int num, contador;
	contador = 0;
	soma = den = 0;
	num = 1000;
	while(contador < 50){
		++den;
		if(num % 2 == 0){
			soma = soma + (num / den);
		} else {
			soma = soma - (num / den);
		}
		num = num - 3;
		
		++contador;
	}
	printf("A soma dos 50 primeiros termos eh = %.4f\n", soma);

	return 0;
}
