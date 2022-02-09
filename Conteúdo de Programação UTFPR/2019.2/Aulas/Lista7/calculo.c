#include <stdio.h>
#include <math.h>

void quadrado(int numUsuario){
	int numQuadrado;
	numQuadrado = pow(numUsuario, 2);

	printf("O numero %d ao quadrado eh: %d\n", numUsuario, numQuadrado);
}

void cubica(int numUsuario){
	float raizCub;
	raizCub = pow(numUsuario, 1.0/3.0);

	printf("A raiz cubica de %d eh: %.2f\n", numUsuario, raizCub);
}

void quadrada(int numUsuario){
	float raizQuad;
	raizQuad = sqrt(numUsuario);

	printf("A raiz quadrada de %d eh: %.2f\n", numUsuario, raizQuad);
}

void cubo(int numUsuario){
	int numCubo;
	numCubo = pow(numUsuario, 3);

	printf("O numero %d ao cubo eh: %d\n", numUsuario, numCubo);
}

int main(){
	int numero;

	do{
	printf("Insira um numero positivo e diferente de zero: ");
	scanf("%d", &numero);

	} while(numero < 0);

	quadrado(numero);
	cubica(numero);	
	quadrada(numero);
	cubo(numero);

	return 0;
}	
