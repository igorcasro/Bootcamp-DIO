#include <stdio.h>
#include <stdlib.h>

int ordene(int **pa, int **pb, int **pc){
	int aux;
	if(**pa < **pb){
		aux = **pa;
		**pa = **pb;
		**pb = aux;
	}
	if(**pa < **pc){
		aux = **pa;
		**pa = **pc;
		**pc = aux;
	}
	if(**pb < **pc){
		aux = **pb;
		**pb = **pc;
		**pc = aux;
	}
}

int main(){
	int a = 0;
	int b = 0;
	int c = 0;
	int *pa = &a;
	int *pb = &b;
	int *pc = &c;
	scanf("%i%i%i", pa, pb, pc);
	ordene(&pa, &pb, &pc);
	printf("PA = %i\n", *pa);
	printf("PB = %i\n", *pb);
	printf("PC = %i\n", *pc);







}