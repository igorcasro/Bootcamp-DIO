#include <stdio.h>
#include <stdlib.h>

void main(){
	int a = 32;
	float b =  10.6;
	char c = 'w';
	int *pa = &a;
	float *pb = &b;
	char *pc = &c;
	printf("Tamanho de a(bytes): %d\n", sizeof(int));
	printf("Conteudo de a: %d\n", *pa);
	printf("Endereco de a: %x\n", pa);
	printf("Tamanho de b(bytes): %d\n", sizeof(float));
	printf("Conteudo de b: %f\n", *pb);
	printf("Endereco de b: %x\n", pb);
	printf("Tamanho de c(bytes): %d\n", sizeof(char));
	printf("Conteudo de c: %c\n", *pc);
	printf("Endereco de c: %x\n", pc);
}