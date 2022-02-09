#include <stdio.h>
#include <math.h>

int main(){
	float x1, x2, y1, y2, aux1, aux2, distancia;
	printf("Insira as coordenadas X e Y do primeiro ponto.\n");
	printf("x1 = ");
	scanf("%f", &x1);
	printf("y1 = ");
	scanf("%f", &y1);
	printf("Insira as coordenadas X e Y do segundo ponto.\n");
	printf("x2 = ");
	scanf("%f", &x2);
	printf("y2 = ");
	scanf("%f", &y2);
	aux1 = pow((x2 - x1), 2); 
	aux2 = pow((y2 - y1), 2);
	distancia = sqrt(aux1 + aux2);
	printf("A distancia entre os pontos eh: %.4f\n", distancia);

	return 0;
}
