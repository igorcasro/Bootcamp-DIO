#include <stdio.h>

int main(){
	float primeiro, segundo, valorS;
	primeiro = 1;
	segundo = 1;
	valorS = 0;

	while(primeiro < 100 && segundo < 51){
		valorS = valorS + (primeiro / segundo);
		primeiro = primeiro + 2;
		++segundo;
	}
	printf("O valor de S eh: %.2f\n", valorS);

	return 0;
}
