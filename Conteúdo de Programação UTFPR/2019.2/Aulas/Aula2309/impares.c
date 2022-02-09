#include <stdio.h>

int main() {
	int numero;

	numero = 0;
	printf("Os numeros impares entre 0 e 100 sao:\n");
	while(numero <= 100){
		if(numero % 2 != 0){
			printf("%d ", numero);
		}
		++numero;
	}
	printf("\n");

	return 0;
}
