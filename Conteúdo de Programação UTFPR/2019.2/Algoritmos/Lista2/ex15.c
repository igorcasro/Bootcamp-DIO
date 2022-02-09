#include <stdio.h>
#include <stdlib.h>

void imprimeEndereco(float *array){
	printf("%x\n", array);
}

void main(){
	float array[10];
	for(int i = 0; i < 10; i++){
		imprimeEndereco(array + i);
	}
}