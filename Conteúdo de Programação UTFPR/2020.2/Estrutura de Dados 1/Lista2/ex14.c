#include <stdio.h>

float perimetro(float *ptrb, float *ptrh){
	float P = 2 * (*ptrb) + 2 * (*ptrh);

	*ptrb = *ptrb * 2;
	*ptrh = *ptrh * 2;

	return P;
}

void main(){
	float b, *ptrb = &b, h, *ptrh = &h, P;

	printf("Insira a base do retangulo: ");
	scanf("%f", ptrb);
	printf("Insira a altura do retangulo: ");
	scanf("%f", ptrh);

	P = perimetro(ptrb, ptrh);

	printf("\n\nPerimetro = %.2f\nNova base = %.2f\nNova altura = %.2f\n", P, *ptrb, *ptrh);

}