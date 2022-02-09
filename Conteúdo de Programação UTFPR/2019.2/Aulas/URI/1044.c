#include <stdio.h>

int main(){
	int val1, val2;
	printf("***VERIFICACAO MULTIPLOS***\n\n");
	printf("Insira o primeiro valor inteiro: ");
	scanf("%d", &val1);
	printf("Insira o segundo valor inteiro: ");
	scanf("%d", &val2);
	if(val2 % val1 == 0){
		printf("Sao Multiplos.\n");
	} else
		printf("Nao sao Multiplos.\n");

	return 0;
}
