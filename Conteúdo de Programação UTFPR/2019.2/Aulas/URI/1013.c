#include <stdio.h>

int main(){
	int val1, val2, val3;
	
	do {
		printf("Insira tres valores inteiros para verificacao do maior.\n");
		printf("Valor 1 = ");
		scanf("%d", &val1);
		printf("Valor 2 = ");
		scanf("%d", &val2);
		printf("Valor 3 = ");
		scanf("%d", &val3);
		if(val1 == val2 || val1 == val3){
			printf("Valores iguais!\n");
		}else if(val1 > val2 && val1 > val3 ){
			printf("O valor %d eh o maior.\n", val1);	
		} else if(val2 > val3) {
			printf("O valor %d eh o maior.\n", val2);
		} else
			printf("O valor %d eh o maior.\n", val3);
	} while(val1 == val2 || val1 == val3 || val2 == val3);

	return 0;
}
