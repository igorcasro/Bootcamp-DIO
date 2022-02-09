#include <stdio.h>
#include <math.h>

int main() {
	float delta, raiz1, raiz2, valA, valB, valC, quadrado, raizDelta;

	printf("***CALCULO BHASKARA***\n\n");
	printf("Insira o \'a\' da funcao: ");
	scanf("%f", &valA);
	printf("Insira o \'b\' da funcao: ");
	scanf("%f", &valB);
	printf("Insira o \'c\' da funcao: ");
	scanf("%f", &valC);
	
	quadrado = pow(valB, 2);
	delta = quadrado - (4 * valA * valC);
	if(delta < 0 || valA == 0) {
		printf("Impossivel calcular!\n");
	} else {
		raizDelta = sqrt(delta);
		raiz1 = ( -valB + raizDelta) / (2 * valA);
		raiz2 = ( +valB + raizDelta) / (2 * valA);
		printf("A primeira raiz tem valor %.5f e a segunda raiz tem valor %.5f\n", raiz1, raiz2);
	}

	return 0;
}
