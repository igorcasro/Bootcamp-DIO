#include <stdio.h>

int main () {
	int val1, val2, val3, aux1, aux2, aux3;
	printf("***SORT SIMPLES***\n\n");
	do{
		printf("Insira o primeiro valor: ");
		scanf("%d", &val1);
		aux1 = val1;
		printf("Insira o segundo valor distinto do primeiro: ");
		scanf("%d", &val2);
		aux2 = val2;
		printf("Insira o terceiro valor distinto de ambos: ");
		scanf("%d", &val3);
		aux3 = val3;
	} while(val1 == val2 || val1 == val3 || val2 == val3);
		if(val1 > val2 && val1 > val3){
			printf("%d\n", val1);
			if(val2 > val3){
				printf("%d\n%d\n", val2, val3);
			} else
				printf("%d\n%d\n", val3, val2);
		} else if(val2 > val1 && val2 > val3){
			printf("%d\n", val2);
			if(val1 > val3){	
				printf("%d\n%d\n", val1, val3);
			} else
				printf("%d\n%d\n", val3, val1);
		} else if(val3 > val1 && val3 > val2) {
			printf("%d\n", val3);
			if(val1> val2){
				printf("%d\n%d\n", val1, val2);
			} else
				printf("%d\n%d\n", val2, val1);
		}
	
	printf("\n%d\n%d\n%d\n", aux1, aux2, aux3);

	return 0;
}
