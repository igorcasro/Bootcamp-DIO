#include <stdio.h>

void ordene(int **pa, int **pb, int **pc){
	int maior;

	if(**pa < **pb){
		maior = **pb;
		**pb = **pa;
		**pa = maior;
		if(**pa < **pc){
			maior = **pc;
			**pc = **pa;
			**pa = maior;
		}
		if(**pb < **pc){
			maior = **pc;
			**pc = **pb;
			**pb = maior;
		}
	} else 
		if(**pb < **pc){
			maior = **pc;
			**pc = **pb;
			**pb = maior;
			if(**pa < **pb){
				maior = **pb;
				**pb = **pa;
				**pa = maior;
			}
	}


}

int main() {

	int a = 0 ;
	int b = 0 ;
	int c = 0 ;
	int *pa = &a ;
	int *pb = &b ;
	int *pc = &c ;
	scanf("%i%i%i",pa,pb, pc);
	ordene(&pa,&pb, &pc);
	printf("PA = %i, ",*pa);
	printf("PB = %i, ",*pb);
	printf("PC = %i\n",*pc);

}