#include <stdio.h>

void main() {

	int a = 32 ;
	float b = 10.6 ;
	char c = 'w' ;
	int *pa = &a ;
	float *pb = &b ;
	char *pc = &c ;

	printf("Variavel A\nTamanho = %d\nConteudo = %d\nEndereco de memoria = %x\n\n", sizeof(*pa), *pa, pa);
	printf("Variavel B\nTamanho = %d\nConteudo = %.1f\nEndereco de memoria = %x\n\n", sizeof(*pb), *pb, pb);
	printf("Variavel C\nTamanho = %d\nConteudo = %c\nEndereco de memoria = %x\n\n", sizeof(*pc), *pc, pc);

	*pa = 16;
	*pb = 19.5;
	*pc = 't';

	printf("Variavel A\nTamanho = %d\nConteudo = %d\nEndereco de memoria = %x\n\n", sizeof(*pa), *pa, pa);
	printf("Variavel B\nTamanho = %d\nConteudo = %.1f\nEndereco de memoria = %x\n\n", sizeof(*pb), *pb, pb);
	printf("Variavel C\nTamanho = %d\nConteudo = %c\nEndereco de memoria = %x\n\n", sizeof(*pc), *pc, pc);

}