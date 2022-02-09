#include <stdio.h>
#include <math.h>

void distancia(float x1, float x2, float y1, float y2){
	float primeiroQuad, segundoQuad, soma, distancia;

	primeiroQuad = pow((x2 - x1), 2);
	segundoQuad = pow((y2 - y1), 2);
	soma = primeiroQuad + segundoQuad;
	distancia = sqrt(soma);
	printf("Distancia = %f\n", distancia);
}

int main(){
	float x1, x2, y1, y2;
	
	printf("Insira as coordenadas X e Y do primeiro ponto.\n");
	printf("X1 = ");
	scanf("%f", &x1);
	printf("Y1 = ");
	scanf("%f", &y1);
	printf("Insira as coordenadas X e Y do segundo ponto.\n");
	printf("X2 = ");
	scanf("%f", &x2);
	printf("Y2 = ");
	scanf("%f", &y2);

	distancia(x1, x2, y1, y2);

	return 0;
}
