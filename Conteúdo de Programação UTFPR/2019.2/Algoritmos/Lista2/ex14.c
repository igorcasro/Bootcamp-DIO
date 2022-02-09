#include <stdio.h>
#include <stdlib.h>

void perimetro(float *pb, float *ph, float *pp){
	
	*pp = (2 * *pb) + (2 * *ph);
	*pb = 2 * *pb;
	*ph = 2 * *ph;
}

void main(){
	float b, h, p;
	float *pb, *ph, *pp;
	pb = &b;
	ph = &h;
	pp = &p;

	printf("Insira a base: ");
	scanf("%f", pb);
	printf("Insira a altura: ");
	scanf("%f", ph);
	perimetro(pb, ph, pp);
	printf("O perimetro eh: %f\n", *pp);
	printf("A nova base tem valor: %f\n", *pb);
	printf("A nova altura tem valor: %f\n", *ph);
}