#include <stdio.h>

void imprimePosicao(float *ptr){
	for(int i = 0; i < 10; i++){
		printf("%x\n", (ptr + i));
	}
}


void main(){
	float array[10];
	float *ptr = array;

	imprimePosicao(ptr);
}