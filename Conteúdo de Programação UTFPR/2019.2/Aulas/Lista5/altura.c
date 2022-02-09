#include <stdio.h>

int main(){
	float hFulano, hCiclano;
	int anos;
	
	hFulano = 150;
	hCiclano = 110;
	anos = 1;

	do {
		hFulano = hFulano + 2;
		hCiclano = hCiclano + 3;
		++anos;
	}while(hCiclano < hFulano);
	
	printf("O tempo para Ciclano passar Fulano eh de: %d anos.\n", anos);

	return 0;
}
