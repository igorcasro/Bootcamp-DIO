#include <stdio.h>
#include <math.h>

int main(){
	int valor, contador, auxiliar;
	float soma, elevado;
		
	printf("Insira um valor inteiro para que seja feito o cálculo: ");
	scanf("%d", &valor);

	contador = 25;
	soma = 0;
	auxiliar = 1;
	while(contador > 0){
		elevado = pow(valor, contador);
		if(contador % 2 == 0){
			soma = soma - (elevado / auxiliar);
		} else {
			soma = soma + (elevado / auxiliar);
		}	

		++auxiliar;
		--contador;
	}
	printf("O somatorio eh: %.5f\n", soma);


	return 0;
}
