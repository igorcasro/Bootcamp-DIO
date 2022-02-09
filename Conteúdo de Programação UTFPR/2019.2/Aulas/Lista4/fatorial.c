#include <stdio.h>

int main(){
	int numero, cont;
	
	printf("Insira um valor para que seja calculado o fatorial: ");
	scanf("%d", &numero);
	cont = numero - 1;
	if(numero > 0){
	while(cont > 0){
		numero = numero * cont;
		--cont;
	}
	printf("O fatorial eh: %d \n", numero);
	} else 
		printf("Valor invalido!\n");
	
	return 0;
}
