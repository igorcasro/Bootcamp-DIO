#include <stdio.h>

int main() {

	int num1, num2, num3, num4;
	printf("Informe o primeiro numero inteiro: ");
	scanf("%d", &num1);
	printf("Informe o segundo numero inteiro: ");
	scanf("%d", &num2);
	printf("Informe o terceiro numero inteiro: ");
	scanf("%d", &num3);
	printf("Informe o quarto numero inteiro: ");
	scanf("%d", &num4);
	if((num1 % 2 == 0) && (num1 % 3 == 0)) {
		printf("O numero %d eh divisivel por 2 e por 3. \n", num1);
	}
	if((num2 % 2 == 0) && (num2 % 3 == 0)) {
		printf("O numero %d eh divisivel por 2 e por 3. \n", num2);
	}
	if((num3 % 2 == 0) && (num3 % 3 == 0)) {
		printf("O numero %d eh divisivel por 2 e por 3. \n", num3);
	}
	if((num4 % 2 == 0) && (num4 % 3 == 0)) {
		printf("O numero %d eh divisivel por 2 e por 3. \n", num4);
	}



	return 0;
}