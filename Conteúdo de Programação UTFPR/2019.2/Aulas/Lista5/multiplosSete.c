#include <stdio.h>

int main(){
	int numero;
	numero = 100;

	while(numero <= 200) {
		if(numero % 7 == 0){
			printf("Valor multiplo: %d\n", numero);
		}
		++numero;
	}
 
	return 0;
}
