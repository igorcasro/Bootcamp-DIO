#include <stdio.h>
#include <stdlib.h>

void main(){
	int a = 2;
	int *pa = &a;
	free(pa);
	printf("%d\n", *pa);



}