#include <stdio.h>

void imprimePosicao(float *ptrArray){
	for(int i = 0; i < 10; i++){
		printf("Endereço de [%d] = %x\n", i, (sptrArray + i));
	}
}

void main(){
	float array[10];
	float *ptrArray = array;

	imprimePosicao(ptrArray);

}