#include <stdio.h>

int main(){
	int multiplo, contador, soma;
	
	soma = 0;

	for(contador = 100; contador < 200; ++contador){
		if(contador % 7 == 0){
			printf("%d\n", contador);
			soma = soma + contador;
		}
	}
	printf("A soma deles eh: %d\n", soma);

	return 0;
}
