#include <stdio.h>

int main(){
	float distancia, litros, consumo;
	do {
	printf("Insira a distancia total percorrida: ");
	scanf("%f", &distancia);
	printf("Insira a quantidade de combustivel gasto: ");
	scanf("%f", &litros);
	consumo = distancia / litros;
	printf("O consumo medio desse automovel eh de: %.3f km/l\n", consumo);
	} while(distancia < 0 || litros < 0);

	return 0;
}
