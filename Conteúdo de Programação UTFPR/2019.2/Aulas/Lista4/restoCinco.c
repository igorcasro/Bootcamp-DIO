#include <stdio.h>

int main(){
	int numero, aux;
	numero = 1000;

	printf("Os numeros entre 1000 e 1999 dividos por 11 com resto 5 sao: \n");
	while(numero <= 1999) {
		if( (numero % 11 == 5) ){
			printf("%d ", numero);
		}
		++numero;
	}
	printf("\n");

	return 0;
}
