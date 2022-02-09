#include <stdio.h>

int main(){
	int num1, soma, divisor, contador;
	printf("***NUMERO PERFEITO***\n\n");
	printf("Insira um numero inteiro para fazer a verificação de 1 até ele: ");
	scanf("%d", &num1);
	
	for(contador = 1; contador <= num1; ++contador){
		soma = 0;
		for(divisor = 1; divisor <= (contador/2); ++divisor){
			if(contador % divisor == 0){		
				soma = soma + divisor;			
			}
		}
		if(soma == contador){
			printf("%d eh um numero perfeito.\n", contador);
		}	
	}

	return 0;
}
