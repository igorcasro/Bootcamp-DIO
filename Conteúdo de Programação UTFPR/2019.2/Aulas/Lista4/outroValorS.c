#include <stdio.h>
#include <math.h>

int main(){
	float segundo, valorS, potencia;
	int primeiro;
	primeiro = segundo = 0;  
	valorS = 0;
	potencia = 1;
		
	while(primeiro < 11 && segundo < 101){
		if(primeiro % 2 == 0){
			valorS = valorS + (-primeiro / potencia);
		} else
			valorS = valorS + (primeiro / potencia);
			++primeiro;
			++segundo;
			potencia = pow(segundo, 2);
	}
	printf("O valor de S eh: %.2f\n", valorS);

	return 0;
}
