#include <stdio.h>
#include <stdlib.h>

void main(){
	int a = 32;
	float b = 10.6;
	char c = 'w';
	int *pa = &a;
	float *pb = &b;
	char *pc = &c;
	printf("A variavel a tem valor: %d\n", *pa);
	printf("A variavel b tem valor: %f\n", *pb);
	printf("A variavel c tem valor: %c\n", *pc);

	*pa = 50;
	*pb = 19.572603;
	*pc = 'x';

	printf("Apos alteracao a tem valor de: %d\n", *pa);
	printf("Apos alteracao b tem valor de: %f\n", *pb);
	printf("Apos alteracao c tem valor de: %c\n", *pc);

}