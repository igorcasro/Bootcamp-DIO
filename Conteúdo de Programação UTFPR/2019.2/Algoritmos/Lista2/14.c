#include <stdio.h>

float perimetro(float *b, float *h){
	float P;

	P = 2 * (*b) + 2 * (*h);
	*b = 2 * (*b);
	*h = 2 * (*h);

	return P;
}

void main(){
	float b, h, *ptrb = &b, *ptrh = &h, p;
	printf("***CALCULO DE PERIMETRO***\n\n\n");
	printf("Insira a base do retangulo: ");
	scanf("%f", ptrb);
	printf("Insira a altura do retangulo: ");
	scanf("%f", ptrh);
	p = perimetro(ptrb, ptrh);

	printf("Perimetro = %.2f\nNova base = %.2f\nNova altura = %.2f\n", p, *ptrb, *ptrh);
}